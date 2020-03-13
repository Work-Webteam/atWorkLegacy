<?php

/**
 * @file
 * atwork_lsa_pins.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function atwork_lsa_pins_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_pin_sup|node|lsa_pin_application|form';
  $field_group->group_name = 'group_service_pin_sup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supervisor Contact Info',
    'weight' => '16',
    'children' => array(
      0 => 'field_lsa_supervisor_first_name',
      1 => 'field_lsa_supervisor_last_name',
      2 => 'field_lsa_supervisor_email',
      3 => 'field_lsa_office_address',
      4 => 'field_lsa_office_city',
      5 => 'field_lsa_work_phone',
      6 => 'field_lsa_office_postal_code',
      7 => 'field_province',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-service-pin-sup field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_service_pin_sup|node|lsa_pin_application|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Supervisor Contact Info');

  return $field_groups;
}
