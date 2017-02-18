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
      98 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}
