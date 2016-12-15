<?php
/**
 * @file
 * profile_feed_comments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function profile_feed_comments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "semantic_fields" && $api == "semantic_fields") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function profile_feed_comments_flag_default_flags() {
  $flags = array();
  // Exported flag: "Activity Feed Messages Flag".
  $flags['activity_feed_messages_flag'] = array(
    'entity_type' => 'message',
    'title' => 'Activity Feed Messages Flag',
    'global' => 1,
    'types' => array(
      0 => 'following_user',
      1 => 'group_subscribe',
      2 => 'group_unsubscribe',
      3 => 'new_answer',
      4 => 'new_comment',
      5 => 'new_image',
      6 => 'new_node',
      7 => 'node_updated',
      8 => 'status',
      9 => 'updated_user',
      10 => 'user_liked_comment',
      11 => 'user_liked_node',
      12 => 'user_received_ecard',
      13 => 'user_sent_ecard',
    ),
    'flag_short' => 'Flag as inappropriate',
    'flag_long' => 'Flag as inappropriate',
    'flag_message' => '',
    'unflag_short' => 'Remove Flag',
    'unflag_long' => 'Remove Flag',
    'unflag_message' => '',
    'unflag_denied_text' => 'flagged',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 'diff_standard',
      'token' => 'token',
      'ecard' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'flag_confirmation' => 'Please provide a reason this content is inappropriate.',
    'unflag_confirmation' => 'Are you sure you want to unflag this content?',
    'module' => 'profile_feed_comments',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Flag for message replies".
  $flags['flag_for_message_replies'] = array(
    'entity_type' => 'reply',
    'title' => 'Flag for message replies',
    'global' => 1,
    'types' => array(
      0 => 'entity_comments',
    ),
    'flag_short' => 'Flag as inappropriate',
    'flag_long' => 'Flag as inappropriate',
    'flag_message' => '',
    'unflag_short' => 'Remove Flag',
    'unflag_long' => 'Remove Flag',
    'unflag_message' => '',
    'unflag_denied_text' => 'flagged',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 'diff_standard',
      'token' => 'token',
      'ecard' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'flag_confirmation' => 'Please provide a reason this content is inappropriate.',
    'unflag_confirmation' => 'Are you sure you want to unflag this content?',
    'module' => 'profile_feed_comments',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function profile_feed_comments_image_default_styles() {
  $styles = array();

  // Exported image style: profile_thumbs_med.
  $styles['profile_thumbs_med'] = array(
    'label' => 'Profile Thumbs Med',
    'effects' => array(
      98 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 43,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      99 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 40,
          'height' => 40,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function profile_feed_comments_default_message_type() {
  $items = array();
  $items['following_user'] = entity_import('message_type', '{
    "name" : "following_user",
    "description" : "Following User",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional]\\u0026nbsp;is following [message:field-message-user:author-themed].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['group_subscribe'] = entity_import('message_type', '{
    "name" : "group_subscribe",
    "description" : "Joined Group",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional] joined the \\u003Ca href=\\u0022[message:field-message-node:url:relative]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E group.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['group_unsubscribe'] = entity_import('message_type', '{
    "name" : "group_unsubscribe",
    "description" : "Left Group",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional] left the \\u003Ca href=\\u0022[message:field-message-node:url:relative]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E group.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_answer'] = entity_import('message_type', '{
    "name" : "new_answer",
    "description" : "New Answer",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-message-node:author:author-conditional] posted an answer to the question titled\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-node:field-answer-question:url:relative]\\u0022\\u003E[message:field-message-node:field-answer-question:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_comment'] = entity_import('message_type', '{
    "name" : "new_comment",
    "description" : "New Comment",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-message-comment:author:author-conditional] posted a comment in \\u003Ca href=\\u0022[message:field-message-node:url:relative]?c=[message:field-message-comment:cid]#comment-[message:field-message-comment:cid]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E[atwork-groups:in-groups-text].\\u003Cbr\\u003E\\r\\n\\t\\u003Cspan class=\\u0022activity-comment\\u0022\\u003E[message:field-message-comment:teaser]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_image'] = entity_import('message_type', '{
    "name" : "new_image",
    "description" : "New Image",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-message-node:author:author-conditional] posted a new image to the gallery titled \\u003Ca href=\\u0022[message:field-message-node:field-gallery:url]\\u0022\\u003E[message:field-message-node:field-gallery:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_node'] = entity_import('message_type', '{
    "name" : "new_node",
    "description" : "New Node",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-message-node:author:author-conditional]\\u0026nbsp;posted the [message:field-message-node:content-type] titled \\u003Ca href=\\u0022[message:field-message-node:url:relative]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E[atwork-groups:in-groups-text].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['node_updated'] = entity_import('message_type', '{
    "name" : "node_updated",
    "description" : "Node Updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-message-node:author:author-conditional] updated the [message:field-message-node:content-type]\\u0026nbsp;titled\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-node:url:relative]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['status'] = entity_import('message_type', '{
    "name" : "status",
    "description" : "Status update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:field-message-node:author:author-conditional] updated their [message:field-message-node:content-type].\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[message:field-message-node:body]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['updated_user'] = entity_import('message_type', '{
    "name" : "updated_user",
    "description" : "Updated User",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional] updated [message:user:author-their-your] profile.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_liked_comment'] = entity_import('message_type', '{
    "name" : "user_liked_comment",
    "description" : "User Liked Comment",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional] liked a comment in \\u003Ca href=\\u0022[message:field-message-node:url:relative]?c=[message:field-message-comment:cid]#comment-[message:field-message-comment:cid]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E[atwork-groups:in-groups-text].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_liked_node'] = entity_import('message_type', '{
    "name" : "user_liked_node",
    "description" : "User Liked Node",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional] liked the post\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-node:url:relative]\\u0022 title=\\u0022[message:field-message-node:title]\\u0022\\u003E[message:field-message-node:title]\\u003C\\/a\\u003E[atwork-groups:in-groups-text].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_received_ecard'] = entity_import('message_type', '{
    "name" : "user_received_ecard",
    "description" : "User Received Ecard",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional]\\u0026nbsp;received an \\u003Ca href=\\u0022[message:field-message-node:url]?ecard=[message:field-message-ecard:hash]\\u0022\\u003Eecard\\u003C\\/a\\u003E from\\u0026nbsp;[message:field-message-ecard:sender-themed].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_sent_ecard'] = entity_import('message_type', '{
    "name" : "user_sent_ecard",
    "description" : "User Sent Ecard",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:author-conditional]\\u0026nbsp;sent an \\u003Ca href=\\u0022[message:field-message-node:url]?ecard=[message:field-message-ecard:hash]\\u0022\\u003Eecard\\u003C\\/a\\u003E to [message:field-message-ecard:receiver-themed].\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_reply_bundle().
 */
function profile_feed_comments_default_reply_bundle() {
  $items = array();
  $items['entity_comments'] = entity_import('reply_bundle', '{
    "bundle" : "entity_comments",
    "name" : "Entity Comments",
    "access" : "2",
    "display" : "2",
    "description" : "Comments that are used on entities",
    "form" : "1",
    "allow_reply" : "1",
    "locked" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
