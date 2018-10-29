<?php
/**
 * @file
 * atwork_seckit.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function atwork_seckit_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer seckit'.
  $permissions['administer seckit'] = array(
    'name' => 'administer seckit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'seckit',
  );

  return $permissions;
}
