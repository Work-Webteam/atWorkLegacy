<?php


/**
 * @file
 * Hooks provided by the atwork_auth module.
 */


/**
 * Allow modules to act upon a name (IDIR) change
 *
 * @param $user
 *   The renamed $user object.
 * 
 * @param $original_name
 *   The original (former) name (IDIR)
 * 
 */
function hook_atwork_auth_rename_user($user, $original_name) {
  $message = t('AN IDIR-GUID change was detected. User !name (!uid) was renamed to !new_name',
    array(
      '!name' =>  $original_name,
      '!uid' => $uid,
      '!new_name' => $name,
    )
  );
  
  db_insert('mymodule')
    ->fields(array(
      'log_message' => $message,
    ))
    ->execute();
}

/**
 * Alter a $user created by atwork_auth before it is saved
 *
 * @param object $user
 *   The user passed by reference
 * 
 */
function hook_atwork_auth_new_user_alter(&$user) {
  $field_language = field_language('user', $user, 'field_myfield');
  $user->field_myfield[$field_language][0]['value'] = 'myvalue';
}

/*
 * Alter a $user when they access the site
 * 
 * @param object $user
 *    The user passed by reference
 * @param bool $save
 *    Whether or not to save the $user 
 * 
 */
function hook_atwork_auth_update_fields_on_access_alter(&$user, &$save) {
  if (!isset($user->myfield)) {
    $user->myfield = 'myvalue';
    $save = TRUE;
  }
}
