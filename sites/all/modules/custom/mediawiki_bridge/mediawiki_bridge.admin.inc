<?php

function mediawiki_bridge_settings_form() {
  $form = array();
  
  $form['mediawiki_bridge_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL to MediaWiki server'),
    '#default_value' => variable_get('mediawiki_bridge_url', ''),
    '#field_suffix' => '/api.php',
    '#field_prefix' => 'http://',
    '#description' => t('Unfortunately api.php cannot be at the site root.
      <br />We need something like "www.yourdomain.com/<strong>pathtomediawiki</strong>" for proper linking to work.
      <br />Ideally it is something unique that does not exist on your drupal site!'),
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['mediawiki_bridge_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('mediawiki_bridge_user', ''),
  );

  $form['mediawiki_bridge_pass'] = array(
    '#type' => 'textfield', 
    '#title' => t('Password'),
    '#default_value' => variable_get('mediawiki_bridge_pass', ''),
  );
  
  $form['mediawiki_bridge_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enforce unique titles? (Only disable if another module is doing this)'),
    '#default_value' => variable_get('mediawiki_bridge_title', 1),
  );

  return system_settings_form($form);
}

