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

  $export['views-home_page_blocks_zen-ad_space'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-ad_space',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 67,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block_1'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_1',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 28,
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

  $export['views-home_page_blocks_zen-block_2'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_2',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 27,
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

  $export['views-home_page_blocks_zen-block_3'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_3',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 29,
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

  $export['views-home_page_blocks_zen-block_4'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_4',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 30,
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

  $export['views-home_page_blocks_zen-block_5'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_5',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 17,
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
