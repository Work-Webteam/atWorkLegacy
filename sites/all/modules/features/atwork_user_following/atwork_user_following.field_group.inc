<?php
/**
 * @file
 * atwork_user_following.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function atwork_user_following_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_card|user|user|default';
  $field_group->group_name = 'group_profile_card';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile Card',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'group_profile_identity_bundle',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Profile Card',
      'instance_settings' => array(
        'id' => 'user_user_full_group_profile_card',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_card|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact_bundle|user|user|default';
  $field_group->group_name = 'group_profile_contact_bundle';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_profile_identity_bundle';
  $field_group->data = array(
    'label' => 'Contact_bundle',
    'weight' => '43',
    'children' => array(
      0 => 'field_display_name',
      1 => 'field_gal_title',
      2 => 'field_gal_phone_number',
      3 => 'field_gal_first_name',
      4 => 'field_linkedin',
      5 => 'field_joined_public_service',
      6 => 'masquerade',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact_bundle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-profile-contact-bundle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_contact_bundle|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_extra|user|user|default';
  $field_group->group_name = 'group_profile_extra';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile Extra',
    'weight' => '1',
    'children' => array(
      0 => 'field_extended_biography',
      1 => 'group_skills_interests',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Profile Extra',
      'instance_settings' => array(
        'id' => 'user_user_full_group_profile_extra',
        'classes' => 'group_profile_extra',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_extra|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_identity_bundle|user|user|default';
  $field_group->group_name = 'group_profile_identity_bundle';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_profile_card';
  $field_group->data = array(
    'label' => 'Identity_bundle',
    'weight' => '2',
    'children' => array(
      0 => 'field_summary',
      1 => 'group_location_div_set',
      2 => 'group_profile_contact_bundle',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Identity_bundle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-profile-identity-bundle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_identity_bundle|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_skills_interests|user|user|default';
  $field_group->group_name = 'group_skills_interests';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_profile_extra';
  $field_group->data = array(
    'label' => 'Skills-Interests',
    'weight' => '12',
    'children' => array(
      0 => 'group_interests_tab',
      1 => 'group_skills_tab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_skills_interests|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_skills_tab|user|user|default';
  $field_group->group_name = 'group_skills_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_skills_interests';
  $field_group->data = array(
    'label' => 'Skills',
    'weight' => '37',
    'children' => array(
      0 => 'field_skills',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-skills-tab field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_skills_tab|user|user|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact_bundle');
  t('Identity_bundle');
  t('Profile Card');
  t('Profile Extra');
  t('Skills');
  t('Skills-Interests');

  return $field_groups;
}
