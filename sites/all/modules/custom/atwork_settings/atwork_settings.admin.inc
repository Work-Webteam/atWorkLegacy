<?php

function atwork_settings_general_form() {
  $form = array();

  $form['atwork_settings_enforce_revision_message'] = array(
    '#title' => t('Require a revision message on every edit'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('atwork_settings_enforce_revision_message', 0),
  );

  return system_settings_form($form);
}
function atwork_settings_copy_form() {
  $form = array();

  $form['comments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Comments'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $form['comments']['atwork_comment_subscription_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Subscription wording'),
    '#default_value' => variable_get('atwork_comment_subscription_text',''),
    '#weight' => 5,
  );

  $form['terms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Terms that need agreeing to'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $image_terms = variable_get('atwork_image_terms','');

  $form['terms']['atwork_image_terms'] = array(
    '#type' => 'text_format',
    '#title' => t('Image Terms'),
    '#default_value' => $image_terms['value'],
    '#format' => 'full_html',
    '#weight' => 0,
  );

  $comment_terms = variable_get('atwork_comment_terms','');

  $form['terms']['atwork_comment_terms'] = array(
    '#type' => 'text_format',
    '#title' => t('Comment Terms and Notes'),
    '#default_value' => $comment_terms['value'],
    '#format' => 'full_html',
    '#weight' => 0,
  );

  $group_terms = variable_get('atwork_group_terms','');

  $form['terms']['atwork_group_terms'] = array(
    '#type' => 'text_format',
    '#title' => t('Group Terms'),
    '#default_value' => $group_terms['value'],
    '#format' => 'full_html',
    '#weight' => 0,
  );

  $form['instructions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Instructions (The hover pop-ups)'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $atwork_instructions_blog = variable_get('atwork_instructions_blog','');

  $form['instructions']['atwork_instructions_blog'] = array(
    '#type' => 'text_format',
    '#title' => t('Blog Instructions'),
    '#default_value' => $atwork_instructions_blog['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_blog')),
  );

  $atwork_instructions_event = variable_get('atwork_instructions_event','');

  $form['instructions']['atwork_instructions_event'] = array(
    '#type' => 'text_format',
    '#title' => t('Event Instructions'),
    '#default_value' => $atwork_instructions_event['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_event')),
  );

  $atwork_instructions_status_update = variable_get('atwork_instructions_status_update', '');

  $form['instructions']['atwork_instructions_status_update'] = array(
    '#type' => 'text_format',
    '#title' => t('Status Update Instructions'),
    '#default_value' => $atwork_instructions_status_update['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_status_update')),
    );

  $atwork_instructions_gallery = variable_get('atwork_instructions_gallery','');

  $form['instructions']['atwork_instructions_gallery'] = array(
    '#type' => 'text_format',
    '#title' => t('Image/Gallery Instructions'),
    '#default_value' => $atwork_instructions_gallery['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_gallery')),
  );

  $atwork_instructions_group_page = variable_get('atwork_instructions_group_page','');

  $form['instructions']['atwork_instructions_group_page'] = array(
    '#type' => 'text_format',
    '#title' => t('Group-Page Instructions'),
    '#default_value' => $atwork_instructions_group_page['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_group_page')),
  );

  $atwork_instructions_task_list = variable_get('atwork_instructions_task_list','');

  $form['instructions']['atwork_instructions_task_list'] = array(
    '#type' => 'text_format',
    '#title' => t('Tasks Instructions'),
    '#default_value' => $atwork_instructions_task_list['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_task_list')),
  );

  $atwork_instructions_article = variable_get('atwork_instructions_article','');

  $form['instructions']['atwork_instructions_article'] = array(
    '#type' => 'text_format',
    '#title' => t('News Instructions'),
    '#default_value' => $atwork_instructions_article['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_article')),
  );

  $atwork_instructions_poll = variable_get('atwork_instructions_poll','');

  $form['instructions']['atwork_instructions_poll'] = array(
    '#type' => 'text_format',
    '#title' => t('Poll Instructions'),
    '#default_value' => $atwork_instructions_poll['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_poll')),
  );

  $atwork_instructions_document = variable_get('atwork_instructions_document','');

  $form['instructions']['atwork_instructions_document'] = array(
    '#type' => 'text_format',
    '#title' => t('Document Instructions'),
    '#default_value' => $atwork_instructions_document['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_document')),
  );

  $atwork_instructions_qa = variable_get('atwork_instructions_qa','');

  $form['instructions']['atwork_instructions_qa'] = array(
    '#type' => 'text_format',
    '#title' => t('Q&A Instructions'),
    '#default_value' => $atwork_instructions_qa['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_instructions_qa')),
  );

  $instructions_question = variable_get('atwork_instructions_question', '');

  $form['instructions']['atwork_instructions_question'] = array(
    '#type' => 'text_format',
    '#title' => t('Question Instructions'),
    '#default_value' => $instructions_question['value'],
    '#format' => 'full_html',
    '#weight' => 0,
  );


  $form['misc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Misc'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $atwork_tag_instructions = variable_get('atwork_tag_instructions','');

  $form['misc']['atwork_tag_instructions'] = array(
    '#type' => 'text_format',
    '#title' => t('Description of Tags'),
    '#default_value' => $atwork_tag_instructions['value'],
    '#format' => 'full_html',
    '#weight' => 0,
    '#description' => t('Drupal variable: !var_name', array('!var_name' => 'atwork_tag_instructions')),
  );

  return system_settings_form($form);
}

function atwork_settings_profile_form() {
  $form = array();

  $profile_instructions = variable_get('atwork_profile_instructions','');

  $form['atwork_profile_instructions'] = array(
    '#type' => 'text_format',
    '#title' => t('Profile Instructions'),
    '#default_value' => $profile_instructions['value'],
    '#format' => 'full_html',
    '#weight' => 0,
  );

  $profile_questions_instructions = variable_get('atwork_profile_questions_instructions','');

  $form['atwork_profile_questions_instructions'] = array(
    '#type' => 'text_format',
    '#title' => t('Profile Questions Instructions'),
    '#default_value' => $profile_questions_instructions['value'],
    '#format' => 'full_html',
    '#weight' => 1,
  );

  $profile_byline_instructions  = variable_get('atwork_profile_byline_instructions','');

  $form['atwork_profile_byline_instructions'] = array(
    '#type' => 'text_format',
    '#title' => t('Profile Byline Instructions'),
    '#default_value' => $profile_byline_instructions['value'],
    '#format' => 'full_html',
    '#weight' => 2,
  );

  $profile_employee_skills_instructions = variable_get('atwork_profile_employee_skills_instructions', '');

  $form['atwork_profile_employee_skills_instructions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile Employee Skills Instructions'),
    '#default_value' => $profile_employee_skills_instructions['value'],
    '#format' => 'full_html',
    '#weight' =>3,
  );

  $profile_employee_interests_instructions = variable_get('atwork_profile_employee_interests_instructions', '');

  $form['atwork_profile_employee_interests_instructions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile Employee Interests Instructions'),
    '#default_value' => $profile_employee_interests_instructions['value'],
    '#format' => 'full_html',
    '#weight' =>4,
  );

  $profile_extended_biography_instructions = variable_get('atwork_profile_extended_biography_instructions', '');

  $form['atwork_profile_extended_biography_instructions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile Extended Biography Instructions'),
    '#default_value' => $profile_extended_biography_instructions['value'],
    '#format' => 'full_html',
    '#weight' =>5,
  );

  $profile_linked_in_instructions = variable_get('atwork_profile_linked_in_instructions', '');

  $form['atwork_profile_linked_in_instructions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile LinkedIn Instructions'),
    '#default_value' => $profile_linked_in_instructions['value'],
    '#format' => 'full_html',
    '#weight' =>6,
  );

  $profile_hire_date_instructions = variable_get('atwork_profile_hire_date_instructions', '');

  $form['atwork_profile_hire_date_instructions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile Hire Date Instructions'),
    '#default_value' => $profile_hire_date_instructions['value'],
    '#format' => 'full_html',
    '#weight' =>7,
  );

  $profile_field_image_instructions = variable_get('atwork_profile_field_image_instructions', '');

  $form['atwork_profile_field_image_instructions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile Images Instructions'),
    '#default_value' => $profile_field_image_instructions['value'],
    '#format' => 'full_html',
    '#weight' => 8,
  );

  $profile_terms_and_conditions = variable_get('atwork_profile_terms_and_conditions', '');

  $form['atwork_profile_terms_and_conditions'] = array (
    '#type' => 'text_format',
    '#title' => t('Profile Terms and Conditions'),
    '#default_value' => $profile_terms_and_conditions['value'],
    '#format' => 'full_html',
    '#weight' => 8,
  );
  //dpm($form);
  return system_settings_form($form);
}
