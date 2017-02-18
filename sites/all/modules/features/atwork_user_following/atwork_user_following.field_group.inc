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
  $field_group->identifier = 'group_interests_tab|user|user|default';
  $field_group->group_name = 'group_interests_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_skills_interests';
  $field_group->data = array(
    'label' => 'Interests',
    'weight' => '39',
    'children' => array(
      0 => 'field_employee_interests',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Interests',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-interests-tab field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_interests_tab|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_div_set|user|user|default';
  $field_group->group_name = 'group_location_div_set';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_profile_identity_bundle';
  $field_group->data = array(
    'label' => 'Location_bundle',
    'weight' => '57',
    'children' => array(
      0 => 'field_gal_address',
      1 => 'field_gal_city',
      2 => 'field_gal_postal_code',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location_bundle',
      'instance_settings' => array(
        'id' => 'user_user_full_group_location_div_set',
        'classes' => 'group-profile-location-bundle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_location_div_set|user|user|default'] = $field_group;

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
      1 => 'masquerade',
      2 => 'group_profile_identity_bundle',
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
    'weight' => '56',
    'children' => array(
      0 => 'field_display_name',
      1 => 'field_gal_phone_number',
      2 => 'field_linkedin',
      3 => 'field_joined_public_service',
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
    'weight' => '2',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_summary',
      1 => 'group_location_div_set',
      2 => 'group_profile_contact_bundle',
      3 => 'group_profile_name_bundle',
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
  $field_group->identifier = 'group_profile_name_bundle|user|user|default';
  $field_group->group_name = 'group_profile_name_bundle';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_profile_identity_bundle';
  $field_group->data = array(
    'label' => 'Name Bundle',
    'weight' => '55',
    'children' => array(
      0 => 'field_gal_title',
      1 => 'field_gal_first_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Name Bundle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-profile-name-bundle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_name_bundle|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile|user|user|form';
  $field_group->group_name = 'group_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '4',
    'children' => array(
      0 => 'field_summary',
      1 => 'field_career',
      2 => 'field_philosophy_influences',
      3 => 'field_personal',
      4 => 'field_favourites',
      5 => 'field_image',
      6 => 'field_skills',
      7 => 'field_linkedin',
      8 => 'field_extended_biography',
      9 => 'field_joined_public_service',
      10 => 'field_employee_interests',
      11 => 'group_blog_byline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Profile',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-profile field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_profile|user|user|form'] = $field_group;

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
  t('Interests');
  t('Location_bundle');
  t('Name Bundle');
  t('Profile');
  t('Profile Card');
  t('Profile Extra');
  t('Skills');
  t('Skills-Interests');

  return $field_groups;
}
