<?php
/**
 * @file
 * atwork_user_following.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atwork_user_following_ctools_plugin_api($module = NULL, $api = NULL) {
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
function atwork_user_following_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function atwork_user_following_image_default_styles() {
  $styles = array();

  // Exported image style: follow_thumbs.
  $styles['follow_thumbs'] = array(
    'label' => 'Follow Thumbs',
    'effects' => array(
      96 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 64,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      97 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
