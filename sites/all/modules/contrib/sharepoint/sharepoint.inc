<?php

/**
 * @file
 * API functions for the Sharepoint module.
 */

/**
 * Get a sharepoint client pointing to a particular sharepoint web service.
 *
 * @param string $service the web service.
 *
 * @return SoapClient a SoapClient ready for use.
 */
function sharepoint_get_client($endpoint, $service = 'lists') {
  if (!sharepoint_has_library()) {
    throw new SharePointNotConfiguredException('The nusoap library was not found.');
  }
  $soapclient = new nusoap_client($endpoint['server_url'] . '/_vti_bin/' . $service . '.asmx?WSDL','false');
  $soapclient->setDebugLevel(9);
  $soapclient->setCredentials($endpoint['server_username'], $endpoint['server_password'], $endpoint['server_authtype']);
  return $soapclient;
}


/**
 * Call a particulare SOAP request in on a web service
 *
 * @param string $service the web service.
 *
 * @return Array containing the result
 */
function sharepoint_call($client, $call, $arguments=array()) {
  $result = $client->call($call, $arguments);
  if ($client->getError()){
    if (variable_get('sharepoint_debug',0)){
      drupal_set_message($client->getError(),'error');
      drupal_set_message($client->getDebug(),'error');
    }
    //TODO differentiate between a soap error and a connection error
    _sharepoint_throw_soap_error($client->getError());
  }
  return $result;

}

/**
 * Get information for a list.
 * You can optionally pass in  view and get data for just the view.
 * @param SoapClient $client the client to use for fetching the list.
 * @param string $list the list name. Only Human-readable list names works currently.
 * @param string $view the view to fetch information on.
 *
 */
function sharepoint_get_splist_info($client, $list, $view = '') {
  $result = sharepoint_call($client,"GetListAndView",(array('listName' => $list, 'viewName' => $view)));
  $list = $result['GetListAndViewResult']['ListAndView'];
  return $list;
}

function sharepoint_get_splist_items($client, $listname, $view = '', $query = NULL, $rowLimit = 10, $viewFields = NULL, $queryOptions = NULL, $webId = NULL) {
  $parameters = array(
    'listName' => $listname,
    'view' => $view,
    'query' => $query,
    'viewFields' => $viewFields,
    'rowLimit' => $rowLimit,
    'queryOptions' => $queryOptions,
    'webID' => $webId,
  );

  $result = sharepoint_call($client, "GetListItems", $parameters);
  // If we found no items, return an empty array.
  if (!isset($result['GetListItemsResult']['listitems']['data']['row'])) {
    return array();
  }
  $items = $result['GetListItemsResult']['listitems']['data']['row'];
  // If there is only one item, it will be directly under row. We need to make
  // sure we always have the same format.
  if (!isset($items[0]) || !is_array($items[0])) {
    return array($items);
  }
  return $items;
}

/**
 * Traverse field information.
 * @param SimpleXMLElement $field_info
 * @return array the field information.
 */
function _sharepoint_traverse_field_info($field_info) {
  $fields = array();
  foreach ($field_info as $data) {
    $fields[] = _sharepoint_get_attributes($data);
  }
  return $fields;
}

/**
 * Get all attributes for a field.
 * @param SimpleXMLElement $element
 */
function _sharepoint_get_attributes($element) {
  $field = array();
  foreach ($element as $key => $attribute) {
    $field[$key] = _sharepoint_get_value($attribute);
  }
  return $field;
}

/**
 * Convert a sharepoint value to the right data type,
 * e.g. string, boolean...
 * @param $sp_value some value from sharepoint.
 */
function _sharepoint_get_value($sp_value) {
  // Is this a boolean?
  $sp_value = strtolower($sp_value) == 'true' || strtolower($sp_value) == 'false' ? ($sp_value == 'TRUE') : (string)$sp_value;
  // It totally was! Let's not do anything more here then.
  if (is_bool($sp_value)) {
    return $sp_value;
  }
  // We can't deal with references to other data currently,
  // so let's just strip it out for now.
  return preg_replace('/(.*);#/', '', $sp_value, 1);
}

/**
 * Download a sharepoint file.
 * @param $list_info the information about the list.
 * @param $item the item containing the file.
 * @param $location the location to download the file to.
 */
function sharepoint_download_splist_item_document($endpoint, $item, $location = 'public://sharepoint') {
  if (isset($item['!ows_FileRef'])) {
    $filepath = sharepoint_get_splist_item_filepath($endpoint, $item);
    // Download the file.
    $options = array(
      'headers' => array(
        'Authorization' => 'Basic ' .
          base64_encode($endpoint['server_username'] . ':' . $endpoint['server_password']),
      ),
    );
    $response = drupal_http_request($filepath, $options);

    if ($response->code == 200 || $response->code == 201) {
      // Save the data.
      $local_path = $location . basename($filepath);
      file_save_data($response->data, $local_path);
      return $local_path;
    }
    else {
      throw new SharePointException(t('Could not download file from server. The file was: ') . $filepath, $response->code);
    }
  }
  return FALSE;
}

function sharepoint_get_splist_spview_collection($client, $list) {
  $result = sharepoint_call($client, 'GetViewCollection', array('listName' => $list));
  return $result['GetViewCollectionResult']['Views']['View'];
}

function sharepoint_get_spview_info($client, $list, $view) {
  $result = sharepoint_call($client, 'GetView', array('listName' => $list, 'viewName' => $view));
  return $result['GetViewResult']['View'];
}

function sharepoint_get_splist_collection($client, $show_hidden = FALSE) {
  $result = sharepoint_call($client,'GetListCollection');
  return $result['GetListCollectionResult']['Lists']['List'];
}

function sharepoint_get_spsearch_result($soapClient, $keys) {
  $results = array();
	$parameters = array(
    'queryXml' => "<QueryPacket xmlns='urn:Microsoft.Search.Query'><Query><Range><StartAt>1</StartAt><Count>50</Count></Range><Context><QueryText	type='STRING'>".$keys."</QueryText></Context></Query></QueryPacket>",
  );
  try {
		$response = sharepoint_call($soapClient, 'Query', $parameters);
		$sxml = simplexml_load_string($response['QueryResult']);

		// If the result does not return any items , don't try to process any further
		if ($sxml === FALSE || $sxml->Response->Status != 'SUCCESS') {
			return $results;
		}
		foreach ($sxml->Response->Range->Results->Document as $res) {
			$results[] = array(
		    'link' => url($res->Action->LinkUrl, array('absolute' => TRUE)),
			  //'type' => check_plain('node'),
			  'title' => $res->Title,
				//'user' => theme('admin'),
		    'date' => strtotime($res->Date),
			  //'node' => $node,
				//'extra' => $extra,
				'score' => $res->attributes()->relevance,
				'snippet' => 'description of '.$res->Title,
				//search_excerpt($keys, $node->body),
			);
		}
	}
	catch(SoapFault $fault) {
    _sharepoint_throw_connection_error($fault);
  }
	return $results;
}

/**
 * Get the absolute path to a sharepoint item file.
 * @param $item the list item
 * @return string the file path.
 */
function sharepoint_get_splist_item_filepath($endpoint, $item) {
  $path = $endpoint['server_url'] . '/';
  $parts = explode('/', _sharepoint_get_value($item['!ows_FileRef']));
  foreach ($parts as &$part) {
    $part = rawurlencode($part);
  }
  return $path . implode('/', $parts);
}
