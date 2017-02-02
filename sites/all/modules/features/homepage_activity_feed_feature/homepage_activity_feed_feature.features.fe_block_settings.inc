<?php
/**
 * @file
 * homepage_activity_feed_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function homepage_activity_feed_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['atwork_activity-homepage'] = array(
    'cache' => 1,
    'css' => '',
    'custom' => 0,
    'delta' => 'homepage',
    'js' => '',
    'module' => 'atwork_activity',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>
node/20049',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'social_side',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 24,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
