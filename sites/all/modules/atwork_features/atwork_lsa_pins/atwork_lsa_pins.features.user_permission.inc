<?php

/**
 * @file
 * atwork_lsa_pins.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function atwork_lsa_pins_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create lsa_pin_application content'.
  $permissions['create lsa_pin_application content'] = array(
    'name' => 'create lsa_pin_application content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'lsa admin' => 'lsa admin',
      'lsa contact' => 'lsa contact',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any lsa_pin_application content'.
  $permissions['delete any lsa_pin_application content'] = array(
    'name' => 'delete any lsa_pin_application content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'lsa admin' => 'lsa admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own lsa_pin_application content'.
  $permissions['delete own lsa_pin_application content'] = array(
    'name' => 'delete own lsa_pin_application content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'lsa admin' => 'lsa admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any lsa_pin_application content'.
  $permissions['edit any lsa_pin_application content'] = array(
    'name' => 'edit any lsa_pin_application content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'lsa admin' => 'lsa admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own lsa_pin_application content'.
  $permissions['edit own lsa_pin_application content'] = array(
    'name' => 'edit own lsa_pin_application content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'lsa admin' => 'lsa admin',
      'lsa contact' => 'lsa contact',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions of lsa_pin_application content'.
  $permissions['view revisions of lsa_pin_application content'] = array(
    'name' => 'view revisions of lsa_pin_application content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_revisions_by_content_type',
  );

  return $permissions;
}
