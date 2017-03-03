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

  $export['boxes-long_service_awards_navigation'] = array(
    'cache' => -2,
    'css' => '',
    'custom' => 0,
    'delta' => 'long_service_awards_navigation',
    'js' => '',
    'module' => 'boxes',
    'node_types' => array(),
    'noscript' => '',
    'pages' => 'career/long-service-awards
career/long-service-awards/*
career/long-service-awards/form
career/long-service-awards/applications/*',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 2,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Long Service Awards',
    'visibility' => 1,
  );

  $export['boxes-lsa_admin_links'] = array(
    'cache' => -2,
    'css' => '',
    'custom' => 0,
    'delta' => 'lsa_admin_links',
    'js' => '',
    'module' => 'boxes',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => 'career/long-service-awards/applications/*',
    'roles' => array(
      'administrator' => 3,
      'lsa admin' => 11,
      'lsa contact' => 12,
    ),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 83,
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

  $export['menu-menu-lsa-admin'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'menu-lsa-admin',
    'js' => '',
    'module' => 'menu',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(
      'administrator' => 3,
      'lsa admin' => 11,
    ),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 82,
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

  $export['tb_megamenu-menu-lsa-admin'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'menu-lsa-admin',
    'js' => '',
    'module' => 'tb_megamenu',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '',
    'roles' => array(
      'lsa admin' => 11,
    ),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'navigation',
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
    'visibility' => 0,
  );

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
