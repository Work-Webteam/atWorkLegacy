<?php
/**
 * @file
 * atwork_feature_events.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function atwork_feature_events_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['atwork_prem_awards-nav'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'nav',
    'js' => '',
    'module' => 'atwork_prem_awards',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => 'career/premiers-awards
career/premiers-awards/*',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 113,
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

  $export['boxes-premiers_awards_navigation'] = array(
    'cache' => -2,
    'css' => '',
    'custom' => 0,
    'delta' => 'premiers_awards_navigation',
    'js' => '',
    'module' => 'boxes',
    'node_types' => array(),
    'noscript' => '',
    'pages' => 'career/premiers-awards
career/premiers-awards/*
premiers-award-2014-application
career/premiers-awards/2016/quiz/take
career/premiers-awards/2017/webcasts/registration',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Premier\'s Awards',
    'visibility' => 1,
  );

  return $export;
}
