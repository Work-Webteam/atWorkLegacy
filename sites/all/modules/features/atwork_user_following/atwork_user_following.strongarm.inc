<?php
/**
 * @file
 * atwork_user_following.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function atwork_user_following_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_seed_name-people_admin-page_following2';
  $strongarm->value = 1487435426;
  $export['views_seed_name-people_admin-page_following2'] = $strongarm;

  return $export;
}
