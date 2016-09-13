<?php
// $Id;

/**
 * @file
 *   Hooks for Views API integration
 */

/**
 * Implementation of hook_views_data().
 */
function sharepoint_views_data() {
  $data = array();
  sharepoint_load_includes();
  $endpoints = sharepoint_get_endpoints();
  foreach ($endpoints as $endpoint) {
    $client = sharepoint_get_client($endpoint, 'views');
    foreach ($endpoint['lists'] as $list) {
      $views = sharepoint_get_splist_spview_collection($client, $list);
      foreach ($views as $view) {
        $table_name = $endpoint['name'] . '_' . $list . '_' . $view['!Name'];  
        $data[$table_name]['table']['group'] = t('Sharepoint');
        $data[$table_name]['table']['base'] = array(
          'title' => $list . ' ' . $view['!DisplayName'],
          'field' => '!ows_UniqueId',
          'help' => t('SharePoint Data from %view in %list', array('%view' => $view, '%list' => $list)),
          'query class' => 'views_plugin_query_sharepoint',
          'endpoint' => $endpoint['name'],
          'list' => $list,
          'view' => $view['!Name'],
        );
        $data[$table_name]['!ows_UniqueId'] = array(
          'title' => t('Unique ID'),
          'help' => t('A unique Identifier for this document'),
          'field' => array(
            'handler' => 'views_handler_field_sharepoint',
            'sharepoint' => array(
              'real field' => '',
            ),
          ),
        );
        $data[$table_name]['filepath'] = array(
          'title' => t('File Path'),
          'help' => t('The path to the document on sharepoint'),
          'field' => array(
            'handler' => 'views_handler_field_sharepoint_file',
            'sharepoint' => array(
              'real field' => '',
            ),
          ),
        );        
        $fields = sharepoint_get_spview_info($client, $list, $view['!Name']);
        foreach ($fields['ViewFields']['FieldRef'] as $field) {
          $data[$table_name]['!ows_' . $field['!Name']] = array(
            'title' => $field['!Name'],
            'help' => t('A field from the remote Sharepoint list.'),
            'field' => array(
              'handler' => 'views_handler_field_sharepoint',
              'sharepoint' => array(
                  'real field' => '',
              ),
            ),
          );
        }
      }   
  }
  }
  return $data;
}

/**
 * Implementation of hook_views_plugins().
 */
function sharepoint_views_plugins() {
  return array(
    'module' => 'sharepoint',
    'query' => array(
      'views_plugin_query_sharepoint' => array(
        'title' => t('Sharepoint Query'),
        'help' => t('Sharepoint query object.'),
        'handler' => 'views_plugin_query_sharepoint',
        'path' => drupal_get_path('module', 'sharepoint') .'/views/plugins',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function sharepoint_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'sharepoint') . '/views/handlers',
    ),
    'handlers' => array(
      'views_handler_filter_numeric_sharepoint' => array(
        'parent' => 'views_handler_filter_numeric',
      ),
      'views_handler_field_sharepoint' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_field_sharepoint_file' => array(
        'parent' => 'views_handler_field',
      ),      
      'views_handler_field_sharepoint_numeric' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'views_handler_field_sharepoint_boolean' => array(
        'parent' => 'views_handler_field_boolean',
      ),
    ),
  );
}
