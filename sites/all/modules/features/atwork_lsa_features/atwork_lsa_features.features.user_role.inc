<?php
/**
 * @file
 * atwork_lsa_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function atwork_lsa_features_user_default_roles() {
  $roles = array();

  // Exported role: lsa admin.
  $roles['lsa admin'] = array(
    'name' => 'lsa admin',
    'weight' => 9,
  );

  // Exported role: lsa contact.
  $roles['lsa contact'] = array(
    'name' => 'lsa contact',
    'weight' => 10,
  );

  return $roles;
}
