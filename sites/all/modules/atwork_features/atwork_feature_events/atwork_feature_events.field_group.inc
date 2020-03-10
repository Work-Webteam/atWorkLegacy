<?php
/**
 * @file
 * atwork_feature_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function atwork_feature_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_time|node|event|default';
  $field_group->group_name = 'group_date_time';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date/Time Div',
    'weight' => '4',
    'children' => array(
      0 => 'field_date',
      1 => 'field_location',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date/Time Div',
      'instance_settings' => array(
        'classes' => 'group-date-time field-group-div ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_event_full_group_date_time',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_time|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi1|node|event|form';
  $field_group->group_name = 'group_multi1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => ' - Event Title and Description',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_event_type',
      2 => 'field_image',
      3 => 'title',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => ' - Event Title and Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'event-multi1 ',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $field_groups['group_multi1|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi2|node|event|form';
  $field_group->group_name = 'group_multi2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => ' - Date and Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_date',
      1 => 'field_location',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => ' - Date and Location',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'event-multi2 ',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi2|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi3|node|event|form';
  $field_group->group_name = 'group_multi3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => ' - File Upload',
    'weight' => '3',
    'children' => array(
      0 => 'field_file',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => ' - File Upload',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'event-multi3 ',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi3|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi4|node|event|form';
  $field_group->group_name = 'group_multi4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => ' - Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_tags',
      1 => 'og_group_ref',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => ' - Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'event-multi4 ',
        'description' => '<p>Choose 2 - 3 tags for your event. Tags are keywords that reflect your event’s content and theme. They help your colleagues find information.</p>
<p>Previously created tags will automatically appear as you type. Enter one tag at a time and click Add after each entry. Remove a tag by clicking the red x.</p>
<p>You can create your own tags. Tags can be more than one word. If you create a tag, make it specific. </p>

',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi4|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi|node|event|form';
  $field_group->group_name = 'group_multi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Settings',
    'weight' => '0',
    'children' => array(
      0 => 'group_multi1',
      1 => 'group_multi2',
      2 => 'group_multi3',
      3 => 'group_multi4',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-multi field-group-multipage-group ',
        'page_header' => 3,
        'move_additional' => 1,
        'page_counter' => 1,
        'move_button' => 0,
      ),
    ),
  );
  $field_groups['group_multi|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t(' - Date and Location');
  t(' - Event Title and Description');
  t(' - File Upload');
  t(' - Tags');
  t('Date/Time Div');
  t('Event Settings');

  return $field_groups;
}
