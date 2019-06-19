<?php

/**
 * @file
 * advagg_authcache.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function advagg_authcache_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
