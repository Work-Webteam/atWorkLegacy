<?php
/**
 * @file
 * atwork_hashtags.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atwork_hashtags_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
