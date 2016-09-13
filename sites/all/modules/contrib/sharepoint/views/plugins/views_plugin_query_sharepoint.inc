<?php
// $Id;

/**
 * @file
 *   Views query plugin for the Sharepoint SOAP API.
 */

/**
 * Views query plugin for the Sharepoint SOAP API.
 */
class views_plugin_query_sharepoint extends views_plugin_query {
  var $sp_list;
  var $sp_endpoint;
  var $view;
  /**
   * Constructor; Create the basic query object and fill with default values.
   */
  function init($base_table, $base_field, $options) {
    module_load_include('inc', 'sharepoint');
    $this->base_field = '';
    // Fetch some information about where we should get our data from.
    $views_data = views_fetch_data($base_table);
    $this->sp_list = $views_data['table']['base']['list'];
    $this->sp_view = $views_data['table']['base']['view'];
    $this->endpoint = $views_data['table']['base']['endpoint'];
    parent::init($base_table, $base_field, $options);
  }

  function use_pager() {
    return FALSE;
  }

  /**
   * Generate a query and a countquery from all of the information supplied
   * to the object.
   *
   * @param $get_count
   *   Provide a countquery if this is true, otherwise provide a normal query.
   */
  function query($get_count = FALSE) {  }

  /**
   * Executes the query and fills the associated view object with according
   * values.
   *
   * Values to set: $view->result, $view->total_rows, $view->execute_time,
   * $view->pager['current_page'].
   */
  function execute(&$view) {
    $start = microtime();
    module_load_include('inc', 'sharepoint');
    $endpoint = sharepoint_endpoint_load($this->endpoint);
    $client = sharepoint_get_client($endpoint, 'lists');
    $items = sharepoint_get_splist_items($client, $this->sp_list, $this->sp_view);

    foreach ($items as $key => $item) {
      $view->result[$key] = (object) $item;
      $filepath = sharepoint_get_splist_item_filepath($endpoint, $item);
      if (isset($filepath)) {
        $view->result[$key]->filepath = $filepath;
      }
    }
    // Set row counter and execute time
    $view->total_rows = isset($items->ItemCount) ? count($items->ItemCount) : 0;
    $view->execute_time = microtime() - $start;
  }

  function options_submit(&$form, &$form_state) { 
    views_invalidate_cache();  
  }
}
