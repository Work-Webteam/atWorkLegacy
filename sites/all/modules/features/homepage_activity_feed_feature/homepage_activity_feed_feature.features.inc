<?php
/**
 * @file
 * homepage_activity_feed_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function homepage_activity_feed_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
