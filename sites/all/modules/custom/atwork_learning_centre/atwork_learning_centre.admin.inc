<?php

function atwork_learning_centre_admin() {
  $form = array();


  $form['atwork_learning_centre_courses_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Course Feed URL'),
    '#default_value' => variable_get('atwork_learning_centre_courses_url', ""),
     '#description' => t("The maximum number of links to display in the block."),
    '#required' => TRUE,
  );

  $form['atwork_learning_centre_courses_wait'] = array(
    '#type' => 'textfield',
    '#title' => t('Process Every # Hours'),
    '#default_value' => variable_get('atwork_learning_centre_courses_wait', "24"),
    '#description' => t("Number of hours between processing course feed."),
    '#required' => TRUE,
  );


  return system_settings_form($form);
}
