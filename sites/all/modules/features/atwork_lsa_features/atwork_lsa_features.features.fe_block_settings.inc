<?php
/**
 * @file
 * atwork_lsa_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function atwork_lsa_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-lsa_admin-block_lsa_rsvp'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'lsa_admin-block_lsa_rsvp',
    'js' => '',
    'module' => 'views',
    'node_types' => array(
      0 => 'lsa_application',
    ),
    'noscript' => '',
    'pages' => '*/edit
node/add/*',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 8,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
