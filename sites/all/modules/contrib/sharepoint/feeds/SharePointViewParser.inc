<?php

/**
 * Parses a given file as a CSV file.
 */
class SharePointViewParser extends FeedsParser {
  private $list_info;
  
  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $list = $fetcher_result->getRaw();
    $endpoint = sharepoint_endpoint_load($this->config['endpoint']);
    // Fetch information about the list, so that we can filter out stuff that
    // does not belong.
    if (!isset($this->list_info)) {
      $client = sharepoint_get_client($endpoint, 'lists');
      $this->list_info = sharepoint_get_splist_info($client, $fetcher_result->list);
    }
    
    $rows = array();
    // We need to filter out the stuff that we don't want to have.
    foreach ($list as $item) {
      foreach ($this->list_info['List']['Fields']['Field'] as $field) {
        if (isset($item['!ows_' . $field['!Name']])) {
          $row[$field['!Name']] = _sharepoint_get_value($item['!ows_' . $field['!Name']]);
        }
      }
      // We still need som hidden fields, like the file path.
      // We will append everything we have to the file path
      // and make it absolute.
      if (isset($item['!ows_FileRef'])) {
        $row['filepath'] = sharepoint_get_splist_item_filepath($endpoint, $item);
        if ($this->config['download_files']) {
          $row['local_file'] = sharepoint_download_splist_item_document($endpoint, $item);
        }
      }
      // The Unique ID is a handy thing to have.
      $row['unique_id'] = _sharepoint_get_value($item['!ows_UniqueId']);
      $rows[] = $row;
    }
    return new FeedsParserResult($rows);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'list' => '',
      'view' => '',
      'download_files' => FALSE,
      'endpoint' => '',
    );
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = _sharepoint_feeds_config_form($this);
    $form['download_files'] = array(
      '#type' => 'checkbox',
      '#default_value' => $this->config['download_files'],
      '#title' => t('Download Files in this view'),
      '#description' => t('Check this box if you want to download the files in this view.
        Do this if you want to attach the files to the content you create.')
    );

    return $form;
  }
  
  /**
   * Return mapping sources.
   */
  public function getMappingSources() {
    module_load_include('inc', 'sharepoint');
    try {
      $client = sharepoint_get_client(sharepoint_endpoint_load($this->config['endpoint']), 'lists');
      $field_info = sharepoint_get_splist_info($client, $this->config['list']);
    } catch(SharePointException $e) {
      drupal_set_message('Error when trying to get view information. Make sure the view exists.', 'error');
    }
    $mappingResources = array();
    foreach ($field_info['View']['ViewFields']['FieldRef'] as $field) {
      $mappingResources[$field['!Name']] = array(
        'name' => $field['!Name'],
      );
    }
    $mappingResources['unique_id'] = array(
     'name' => t('Unique ID'),
     'description' => t('Unique ID of the document'),
    );
    $mappingResources['filepath'] = array(
      'name' => t('File Path'),
      'description' => t('The SharePoint File Path'),
    );
    $mappingResources['local_file'] = array(
      'name' => t('Local File'),
      'description' => t('The SharePoint File stored locally'),
    );
    return $mappingResources + parent::getMappingSources();
  }
}
