<?php
/**
 * @file
 * atwork_premier_awards_2018_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function atwork_premier_awards_2018_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['atwork_prem_awards-prem_registration'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'prem_registration',
    'js' => '',
    'module' => 'atwork_prem_awards',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'bottom',
        'status' => 1,
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
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
