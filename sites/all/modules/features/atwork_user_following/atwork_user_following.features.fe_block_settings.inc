<?php
/**
 * @file
 * atwork_user_following.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function atwork_user_following_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-people_admin-block_followers'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'people_admin-block_followers',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<?php
  if (arg(0) == \'user\' && is_numeric(arg(1)) && (arg(2) == NULL)) {
   return TRUE;
  } else {
   return FALSE;
  }
?>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'content',
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
    'visibility' => 2,
  );

  $export['views-people_admin-block_following'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'people_admin-block_following',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<?php
  if (arg(0) == \'user\' && is_numeric(arg(1)) && (arg(2) == NULL)) {
   return TRUE;
  } else {
   return FALSE;
  }
?>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'content',
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
    'visibility' => 2,
  );

  return $export;
}
