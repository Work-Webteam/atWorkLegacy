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
  $strongarm->name = 'pathauto_taxonomy_term_profile_interests_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_profile_interests_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_profile_skills_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_profile_skills_pattern'] = $strongarm;

  return $export;
}
