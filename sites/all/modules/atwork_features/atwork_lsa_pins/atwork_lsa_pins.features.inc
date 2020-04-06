<?php

/**
 * @file
 * atwork_lsa_pins.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atwork_lsa_pins_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function atwork_lsa_pins_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function atwork_lsa_pins_node_info() {
  $items = array(
    'lsa_pin_application' => array(
      'name' => t('Service Pin Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
