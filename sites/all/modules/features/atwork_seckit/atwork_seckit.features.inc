<?php
/**
 * @file
 * atwork_seckit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atwork_seckit_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
