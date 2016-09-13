<?php

/**
 * @file
 * Admin-page callbacks for the sharepoint module.
 */

function sharepoint_admin_endpoints() {
  $endpoints = sharepoint_get_endpoints();
  $endpoint_table = array();
  foreach ($endpoints as $endpoint) {
    $edit = l(t('Edit'), 'admin/structure/sharepoint/endpoint/' . $endpoint['name'] . '/edit');
    $delete = l(t('Delete'), 'admin/structure/sharepoint/endpoint/' . $endpoint['name'] . '/delete');
    $endpoint_table[] = array($endpoint['server_url'], $endpoint['server_username'], $endpoint['server_authtype'], $edit . ' | ' . $delete);
  }
  return theme('table', array('header' => array(t('Server URL'), t('Server Username'), t('Authentication Type'), t('Operations')), 'rows' => $endpoint_table));
}

function sharepoint_admin_endpoint($endpoint) {
  sharepoint_load_includes();
  if (!isset($endpoint['lists'])) {
    $endpoint['lists'] = array();
  }
  $endpoint_form = drupal_get_form('sharepoint_admin_endpoint_form', $endpoint);
  $lists_form = drupal_get_form('sharepoint_admin_endpoint_lists_form', $endpoint);
  $output = drupal_render($endpoint_form);
  $output .= drupal_render($lists_form);
  $output .= theme('item_list', array('items' => $endpoint['lists'], 'title' => t('Lists')));
  return $output;
}

function sharepoint_admin_endpoint_lists_form($form, &$form_state, $endpoint) {
  $form = array();
  $form_state['endpoint'] = $endpoint;
  try {
    $client = sharepoint_get_client($endpoint);
    $lists = sharepoint_get_splist_collection($client);
    $options = array();
    foreach ($lists as $list) {
      if (!in_array($list['!Title'], $endpoint['lists'])) {
        $options[$list['!Title']] = $list['!Title'];
      }
    }
    $form['list'] = array(
      '#type' => 'select',
      '#title' => t('Lists'),
      '#options' => $options,
      '#required' => TRUE,
      '#description' => t('The name of the List you want to publish on your site'),
    );
    $form['add'] = array(
      '#type' => 'submit',
      '#value' => t('Add list'),
    );
  }
  catch(Exception $exception) {
    drupal_set_message(t('Can\'t connect to SharePoint endpoint'), 'error');
  }
  return $form;
}

function sharepoint_admin_endpoint_lists_form_submit($form, &$form_state) {
  $endpoint = $form_state['endpoint'];
  $endpoints = variable_get('sharepoint_endpoints');
  if (!in_array($form['list'], $endpoint['lists'])) {
    $endpoint['lists'][] = $form_state['values']['list'];
  }
  $endpoints[$endpoint['name']] = $endpoint;
  variable_set('sharepoint_endpoints', $endpoints);
}

function sharepoint_admin_endpoint_form($form, &$form_state, $endpoint = NULL) {
  $form = array();
  if (!isset ($endpoint)) {
    $form['name'] = array(
      '#type' => 'machine_name',
      '#default_value' => isset($endpoint['name']) ? $endpoint['name'] : NULL,
      '#exists' => 'exists',
      '#machine_name' => array(
        'exists' => 'sharepoint_machine_name_exists',
      ),
    );
  }
  else {
    $form_state['endpoint'] = $endpoint;
  }
  $form['server_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL'),
    '#default_value' => isset($endpoint['server_url']) ? $endpoint['server_url'] : NULL,
    '#size' => 100,
    '#required' => TRUE,
    '#maxlength' => 100,
    '#description' => t("The base URL to the sharepoint webservice endpoint (including the port number if it's not running on port 80), but excluding _vti_bin.<br />E.g. %example_url", array('%example_url' => 'http://sharepoint.example.com:5966/')),
  );

  $form['server_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => isset($endpoint['server_username']) ? $endpoint['server_username'] : NULL,
    '#size' => 100,
    '#maxlength' => 300,
    '#description' => t('The username for the sharepoint webservice.'),
  );

  $form['server_password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#default_value' => isset($endpoint['server_password']) ? $endpoint['server_password'] : NULL,
    '#size' => 100,
    '#maxlength' => 300,
    '#description' => t('The password for the sharepoint webservice.'),
  );

  $form['server_authtype'] = array(
    '#type' => 'select',
    '#title' => t('Authentication type'),
    '#default_value' => isset($endpoint['server_authtype']) ? $endpoint['server_authtype'] : NULL,
    '#options' => array('basic'=>'basic', 'digest'=>'digest', 'ntlm'=>'ntlm'),
    '#description' => t('The sharepoint authentication type.'),
  );

  $form['debug'] = array(
    '#type' => 'select',
    '#title' => t('Display debugging information'),
    '#default_value' => isset($endpoint['debug']) ? $endpoint['debug'] : NULL,
    '#options' => array(1 => 'yes', 0 => 'no'),
    '#description' => t('Display extra debugging information.'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

function sharepoint_machine_name_exists($element, $form_state) {
  $endpoints = sharepoint_get_endpoints();
  return isset($endpoints[$element]);
}

function sharepoint_admin_endpoint_form_submit($form, &$form_state) {
  if (isset($form_state['values']['name'])) {
    $name = $form_state['values']['name'];
    $message = t('The endpoint %name was created', array('%name' => $name));
  }
  else {
    $name = $form_state['endpoint']['name'];
    $message = t('The endpoint %name was updated', array('%name' => $name));
    // If we don't provide a password, don't change it.
    if (!isset($form_state['values']['server_password'])) {
      $form_state['values']['server_password'] = $form_state['endpoint']['server_password'];
    }
  }
  $endpoint = array(
    'name' => $name,
    'server_url' => $form_state['values']['server_url'],
    'server_username' => $form_state['values']['server_username'],
    'server_password' => $form_state['values']['server_password'],
    'server_authtype' => $form_state['values']['server_authtype'],
    'debug' => $form_state['values']['debug'],
  );
  sharepoint_endpoint_save($endpoint);
  $form_state['redirect'] = 'admin/structure/sharepoint';
  drupal_set_message($message);
}

function sharepoint_admin_endpoint_delete_confirm($form, &$form_state, $endpoint) {
  $form_state['endpoint'] = $endpoint;
  return confirm_form($form,
    t('Are you sure you want to delete %name?', array('%name' => $endpoint['name'])),
    'admin/structure/sharepoint/',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

function sharepoint_admin_endpoint_delete_confirm_submit($form, &$form_state) {
  sharepoint_endpoint_delete($form_state['endpoint']['name']);
  $form_state['redirect'] = 'admin/structure/sharepoint';
}
