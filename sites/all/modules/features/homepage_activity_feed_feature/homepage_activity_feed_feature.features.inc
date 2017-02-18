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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function homepage_activity_feed_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function homepage_activity_feed_feature_image_default_styles() {
  $styles = array();

  // Exported image style: ad_space_250w.
  $styles['ad_space_250w'] = array(
    'label' => 'Ad Space 250w',
    'effects' => array(
      96 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function homepage_activity_feed_feature_node_info() {
  $items = array(
    'ad_space' => array(
      'name' => t('Ad Space'),
      'base' => 'node_content',
      'description' => t('Used as a single node for the Ad-Space showing on the front page Activity Feed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This single node is for the Ad-Space showing on the front page Activity Feed. The title will not display. For the heading, use Heading 2. The body should be a regular paragraph format. A default image is used as a banner and if you replace it the replacing image needs to be a width of 248px.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
