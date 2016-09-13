<?php
/**
 * @file
 * The core that allows content to be submitted to the site. Modules and
 * scripts may programmatically submit nodes using the usual form API pattern.
 */

function atwork_ldap_settings_form() {
  
  if (!_atwork_ldap_working()) {
    $status = '<span style="color:red"><strong>' . t("Can't Connect") . '</strong></span>';
  }
  else {
    $status = '<span style="color:green"><strong>' . t('Connected') . '</strong></span>';
  }
  
  $form = array();
  
  $form['atwork_ldap_status'] = array(
    '#markup' => t('LDAP status with these credentials: !status', array('!status' => $status)),
  );
  
  $form['atwork_ldap_url'] = array(
    '#type' => 'textfield', 
    '#title' => t('LDAP URL'), 
    '#default_value' => variable_get('atwork_ldap_url', ''),
  );
  
  $form['atwork_ldap_domain'] = array(
    '#type' => 'textfield', 
    '#title' => t('LDAP Domain'), 
    '#default_value' => variable_get('atwork_ldap_domain', ''),
  );
  
  $form['atwork_ldap_dn'] = array(
    '#type' => 'textfield', 
    '#title' => t('LDAP DN'), 
    '#default_value' => variable_get('atwork_ldap_dn', ''),
  );
  
  $form['atwork_ldap_user'] = array(
    '#type' => 'textfield', 
    '#title' => t('LDAP Username'), 
    '#default_value' => variable_get('atwork_ldap_user', ''),
  );
  
  $form['atwork_ldap_pass'] = array(
    '#type' => 'password', 
    '#title' => t('LDAP Password'), 
    '#default_value' => variable_get('atwork_ldap_pass', ''),
  );
  
  return system_settings_form($form);
}