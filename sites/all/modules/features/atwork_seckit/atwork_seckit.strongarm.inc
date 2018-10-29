<?php
/**
 * @file
 * atwork_seckit.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function atwork_seckit_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_clickjacking';
  $strongarm->value = array(
    'x_frame' => '1',
    'x_frame_allow_from' => '',
    'js_css_noscript' => 0,
    'noscript_message' => 'Sorry, you need to enable JavaScript to visit this website.',
  );
  $export['seckit_clickjacking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_csrf';
  $strongarm->value = array(
    'origin' => 1,
    'origin_whitelist' => '',
  );
  $export['seckit_csrf'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_ssl';
  $strongarm->value = array(
    'hsts' => 1,
    'hsts_max_age' => '1000',
    'hsts_subdomains' => 0,
  );
  $export['seckit_ssl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_various';
  $strongarm->value = array(
    'from_origin' => 0,
    'from_origin_destination' => 'same',
  );
  $export['seckit_various'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seckit_xss';
  $strongarm->value = array(
    'csp' => array(
      'checkbox' => 1,
      'report-only' => 0,
      'default-src' => '\'self\' *.gov.bc.ca',
      'script-src' => '\'self\' \'unsafe-eval\' *.jquery.com \'unsafe-inline\' *.gov.bc.ca',
      'object-src' => '\'self\' *.gov.bc.ca',
      'style-src' => '\'self\' *.cloudflare.com *.jquery.com \'unsafe-inline\' *.gov.bc.ca',
      'img-src' => '\'self\' *.min.js *.gov.bc.ca data:',
      'media-src' => '\'self\' youtube.com:* *.youtube.com data:',
      'frame-src' => '\'self\' youtube.com:* *.youtube.com',
      'font-src' => '\'self\' *.cloudflare.com',
      'connect-src' => '\'self\' ',
      'report-uri' => 'admin/config/system/seckit/csp-report',
      'policy-uri' => '',
    ),
    'x_xss' => array(
      'select' => '2',
    ),
    'x_content_type' => array(
      'checkbox' => 0,
    ),
  );
  $export['seckit_xss'] = $strongarm;

  return $export;
}
