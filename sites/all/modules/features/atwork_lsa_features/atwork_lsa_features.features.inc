<?php
/**
 * @file
 * atwork_lsa_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atwork_lsa_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
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
function atwork_lsa_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
