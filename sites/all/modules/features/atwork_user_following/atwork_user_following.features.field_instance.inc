<?php
/**
 * @file
 * atwork_user_following.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function atwork_user_following_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_employee_interests'.
  $field_instances['user-user-field_employee_interests'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 39,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_employee_interests',
    'label' => 'Interests',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'active_tags',
      'settings' => array(
        'apply_chosen' => 1,
        'autocomplete_path' => 'taxonomy/autocomplete',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'mode' => 'single',
        'size' => 60,
      ),
      'type' => 'active_tags_taxonomy_autocomplete',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'user-user-field_skills'.
  $field_instances['user-user-field_skills'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 38,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_skills',
    'label' => 'Skills',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'active_tags',
      'settings' => array(
        'apply_chosen' => 1,
        'autocomplete_path' => 'taxonomy/autocomplete',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'mode' => 'single',
        'size' => 60,
      ),
      'type' => 'active_tags_taxonomy_autocomplete',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Interests');
  t('Skills');

  return $field_instances;
}
