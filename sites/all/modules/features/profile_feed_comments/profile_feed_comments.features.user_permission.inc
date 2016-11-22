<?php
/**
 * @file
 * profile_feed_comments.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function profile_feed_comments_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer replies'.
  $permissions['administer replies'] = array(
    'name' => 'administer replies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'administer reply bundles'.
  $permissions['administer reply bundles'] = array(
    'name' => 'administer reply bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete entity_comments reply'.
  $permissions['delete entity_comments reply'] = array(
    'name' => 'delete entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete own entity_comments reply'.
  $permissions['delete own entity_comments reply'] = array(
    'name' => 'delete own entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit entity_comments reply'.
  $permissions['edit entity_comments reply'] = array(
    'name' => 'edit entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit own entity_comments reply'.
  $permissions['edit own entity_comments reply'] = array(
    'name' => 'edit own entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'post entity_comments reply'.
  $permissions['post entity_comments reply'] = array(
    'name' => 'post entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'view entity_comments reply'.
  $permissions['view entity_comments reply'] = array(
    'name' => 'view entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  return $permissions;
}
