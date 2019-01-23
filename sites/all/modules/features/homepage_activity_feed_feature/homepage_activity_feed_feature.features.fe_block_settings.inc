<?php
/**
 * @file
 * homepage_activity_feed_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function homepage_activity_feed_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['atwork_activity-homepage'] = array(
    'cache' => 1,
    'css' => '#social-side .entity-message p[class^="msg-"] + p + p, #social-side .entity-message span.activity-comment {
 line-height: 16px;
}
#social-side p.message {
 line-height:initial;
}
// comment quote adjustment
span.activity-comment:after {
   display:inline-block!important;
    position: absolute!important;
    margin-top: 5px!important;
}

/* Adjust the activity feed height. Might not be needed on move to Prod. */
#block-atwork-activity-homepage {
 height: 1360px!important;
}
/*  Minor styling for the update button */
.status-update-mock-button {
 margin-top: 14px;
 margin-left: 3px;
 color: #26669E;
 background-color: #ECECEC;
}
.status-update-mock-button:hover {
 background-color: #A7A7A7;
 color: #FFFFFF;
}

/*  Change the border setting for the status update field */
.block-atwork-activity .form-textarea {
    border: 1px solid #B7B7B7!important;
}

/* Change the border setting for the HP search box */
.front .custom-search-box.form-text {
 border: solid 5px #26669E!important;
}

/* Activity counter update */
.block-atwork-activity #message-count-number,
.block-atwork-activity #new-message-image-icon {
 display:none;
}

.block-atwork-activity .new-message-count {
width: 75px;
border-bottom: solid 4px red;
left: 28px!important;
}
/* Temporary removal of ellipses before Read More. Permanent fix with next CSS update */
#social-side .entity-message span.activity-comment ~ a::before {
    content: none;
}',
    'custom' => 0,
    'delta' => 'homepage',
    'js' => '',
    'module' => 'atwork_activity',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>
node/21603',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'social_side',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 24,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['atwork_activity-profile_page_activity_feed_block'] = array(
    'cache' => 1,
    'css' => '',
    'custom' => 0,
    'delta' => 'profile_page_activity_feed_block',
    'js' => '',
    'module' => 'atwork_activity',
    'node_types' => array(),
    'noscript' => '',
    'pages' => 'user/*',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'post_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-ad_space'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-ad_space',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'atwork_zen',
        'weight' => 67,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block_1'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_1',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 29,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block_2'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_2',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 27,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block_3'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_3',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 30,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block_4'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_4',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 31,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-home_page_blocks_zen-block_5'] = array(
    'cache' => -1,
    'css' => '',
    'custom' => 0,
    'delta' => 'home_page_blocks_zen-block_5',
    'js' => '',
    'module' => 'views',
    'node_types' => array(),
    'noscript' => '',
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atwork_zen' => array(
        'region' => 'pre_content',
        'status' => 1,
        'theme' => 'atwork_zen',
        'weight' => 18,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
