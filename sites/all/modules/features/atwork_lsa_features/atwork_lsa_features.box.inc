<?php
/**
 * @file
 * atwork_lsa_features.box.inc
 */

/**
 * Implements hook_default_box().
 */
function atwork_lsa_features_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'lsa_admin_links';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'LSA Admin Links';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="/administration/long-service-awards">Long Service Awards Administration</a></p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['lsa_admin_links'] = $box;

  return $export;
}
