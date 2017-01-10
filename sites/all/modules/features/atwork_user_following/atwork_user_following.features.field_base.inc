<?php
/**
 * @file
 * atwork_user_following.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function atwork_user_following_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_extended_biography'.
  $field_bases['field_extended_biography'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_extended_biography',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_feed_options'.
  $field_bases['field_feed_options'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_feed_options',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'My Actions',
        2 => 'All Activity',
        3 => 'Actions by Colleagues I Follow',
        4 => 'Connections Between Colleagues',
        5 => 'Group Subscriptions',
        6 => 'Activity In My Groups',
        7 => 'Answered a Question',
        8 => 'Comments',
        9 => 'Images',
        10 => 'Content',
        11 => 'Status Updates',
        12 => 'Profile Updates',
        13 => 'Blogs',
        14 => 'Events',
        15 => 'Forums',
        16 => 'News Articles',
        17 => 'Group Pages',
        18 => 'Created a Group',
        19 => 'Galleries',
        20 => 'Questions',
        21 => 'Answers',
        22 => 'Polls',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_summary'.
  $field_bases['field_summary'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_summary',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
