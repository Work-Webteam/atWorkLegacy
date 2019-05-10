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

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

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
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'flag abuse_comments'.
  $permissions['flag abuse_comments'] = array(
    'name' => 'flag abuse_comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag abuse_nodes'.
  $permissions['flag abuse_nodes'] = array(
    'name' => 'flag abuse_nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag activity_feed_messages_flag'.
  $permissions['flag activity_feed_messages_flag'] = array(
    'name' => 'flag activity_feed_messages_flag',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag flag_for_message_replies'.
  $permissions['flag flag_for_message_replies'] = array(
    'name' => 'flag flag_for_message_replies',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'post entity_comments reply'.
  $permissions['post entity_comments reply'] = array(
    'name' => 'post entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'unflag abuse_comments'.
  $permissions['unflag abuse_comments'] = array(
    'name' => 'unflag abuse_comments',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag abuse_nodes'.
  $permissions['unflag abuse_nodes'] = array(
    'name' => 'unflag abuse_nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag activity_feed_messages_flag'.
  $permissions['unflag activity_feed_messages_flag'] = array(
    'name' => 'unflag activity_feed_messages_flag',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag flag_for_message_replies'.
  $permissions['unflag flag_for_message_replies'] = array(
    'name' => 'unflag flag_for_message_replies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'view entity_comments reply'.
  $permissions['view entity_comments reply'] = array(
    'name' => 'view entity_comments reply',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  return $permissions;
}
