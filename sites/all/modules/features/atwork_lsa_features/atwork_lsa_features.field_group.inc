<?php
/**
 * @file
 * atwork_lsa_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function atwork_lsa_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_delivery_details|node|lsa_pin_application|form';
  $field_group->group_name = 'group_delivery_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '6',
    'children' => array(
      0 => 'field_lsa_pin_sup_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'sup-div',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_delivery_details|node|lsa_pin_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_accom|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_accom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ceremony Accommodations',
    'weight' => '18',
    'children' => array(
      0 => 'field_lsa_accommodation_notes',
      1 => 'field_lsa_ceremony_accommodation',
      2 => 'field_lsa_guest_accom',
      3 => 'field_lsa_recipient_accom',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Ceremony Accommodations',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lsa-accom field-group-fieldset',
        'description' => '<span class="ceremony-acc-note">Do you or your guest require any accommodations to attend the Long Service Award ceremony at Government House? (e.g. sign language interpreter (ASL), service dog, accessible parking/entrance, etc.)</span>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_accom|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_administration|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_administration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administration',
    'weight' => '22',
    'children' => array(
      0 => 'field_lsa_notes',
      1 => 'field_lsa_form_date_stamp',
      2 => 'field_lsa_watch_engraving_sent',
      3 => 'field_lsa_retro_active',
      4 => 'group_lsa_ceremony_details',
      5 => 'group_lsa_rsvp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Administration',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lsa-administration field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_lsa_administration|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_ceremony_details|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_ceremony_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lsa_administration';
  $field_group->data = array(
    'label' => 'Ceremony Details',
    'weight' => '26',
    'children' => array(
      0 => 'field_lsa_alternate_min_org',
      1 => 'field_lsa_actual_min_org',
      2 => 'field_lsa_ceremonydate',
      3 => 'field_lsa_ceremony_night',
      4 => 'field_lsa_ceremony_response',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Ceremony Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-lsa-ceremony-details field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_ceremony_details|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_contact_info|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lsa_personal_info';
  $field_group->data = array(
    'label' => 'Home Mailing Address',
    'weight' => '13',
    'children' => array(
      0 => 'field_lsa_street',
      1 => 'field_lsa_city',
      2 => 'field_lsa_email',
      3 => 'field_lsa_home_phone',
      4 => 'field_lsa_work_phone',
      5 => 'field_lsa_alt_email_address',
      6 => 'field_lsa_work_phone_ext',
      7 => 'field_lsa_home_postal_code',
      8 => 'field_lsa_home_province',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Home Mailing Address',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lsa-contact-info field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_contact_info|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_dietary_acc|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_dietary_acc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dietary Requirements',
    'weight' => '20',
    'children' => array(
      0 => 'field_lsa_dietary_guest',
      1 => 'field_lsa_dietary_requirements',
      2 => 'field_lsa_recipient_dietary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Dietary Requirements',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lsa-dietary-acc field-group-fieldset',
        'description' => '<span id="dietary-requirements-text">Do you or your guest have any food allergies or dietary restrictions?</span>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_dietary_acc|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_first_donation|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_first_donation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lsa_pecsf';
  $field_group->data = array(
    'label' => '',
    'weight' => '17',
    'children' => array(
      0 => 'field_lsa_donation_amount',
      1 => 'field_lsa_pecsf_charity_name',
      2 => 'field_lsa_pecsf_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-lsa-first-donation field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_lsa_first_donation|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_office_contact_info|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_office_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Information',
    'weight' => '17',
    'children' => array(
      0 => 'field_lsa_org',
      1 => 'field_lsa_branch_department',
      2 => 'field_lsa_ministry_id',
      3 => 'field_lsa_office_address',
      4 => 'field_lsa_office_city',
      5 => 'field_lsa_office_postal_code',
      6 => 'field_lsa_office_province',
      7 => 'group_lsa_supervisor_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-lsa-office-contact-info field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_office_contact_info|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_office_contact|node|lsa_application|default';
  $field_group->group_name = 'group_lsa_office_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_lsad_contact_info';
  $field_group->data = array(
    'label' => 'Office Information',
    'weight' => '14',
    'children' => array(
      0 => 'field_lsa_org',
      1 => 'field_lsa_work_phone',
      2 => 'field_lsa_branch_department',
      3 => 'field_lsa_work_phone_ext',
      4 => 'field_lsa_office_address',
      5 => 'field_lsa_office_city',
      6 => 'field_lsa_office_postal_code',
      7 => 'field_lsa_office_province',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Office Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-lsa-office-contact field-group-fieldset ',
        'description' => '<p>If retired, please enter the last organization and supervisor you worked with.</p><br />',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_lsa_office_contact|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_pecsf|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_pecsf';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Charitable donation',
    'weight' => '12',
    'children' => array(
      0 => 'field_lsa_donation_options',
      1 => 'field_lsa_pecsf_region',
      2 => 'field_lsa_second_donation',
      3 => 'group_lsa_first_donation',
      4 => 'group_lsa_second_donation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Charitable donation',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'pecsf-fields',
        'classes' => 'group-lsa-pecsf field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_lsa_pecsf|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_personal_info|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_personal_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recipient Contact Information',
    'weight' => '16',
    'children' => array(
      0 => 'field_lsa_first_name',
      1 => 'field_lsa_middle_name',
      2 => 'field_lsa_last_name',
      3 => 'group_lsa_contact_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Recipient Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lsa-personal-info field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_personal_info|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_pin_terms|node|lsa_pin_application|form';
  $field_group->group_name = 'group_lsa_pin_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '8',
    'children' => array(
      0 => 'field_lsa_pin_terms',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'lsa-pin-terms',
        'classes' => 'group-lsa-pin-terms field-group-fieldset',
        'description' => '<br /><div id="term-red">If the above information is complete, and you have agreed to the terms below, click the SUBMIT button.</div>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_pin_terms|node|lsa_pin_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_rsvp|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_rsvp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lsa_administration';
  $field_group->data = array(
    'label' => 'RSVP Information',
    'weight' => '25',
    'children' => array(
      0 => 'field_lsa_rsvp',
      1 => 'field_lsa_attending_ceremony',
      2 => 'field_lsa_guest',
      3 => 'field_lsa_invitation_sent',
      4 => 'field_lsa_number_attending',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'RSVP Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-lsa-rsvp field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_rsvp|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_second_donation|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_second_donation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lsa_pecsf';
  $field_group->data = array(
    'label' => '',
    'weight' => '18',
    'children' => array(
      0 => 'field_lsa_charity_name_2',
      1 => 'field_lsa_donation_amount_2',
      2 => 'field_lsa_pecsf_id_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-lsa-second-donation field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_lsa_second_donation|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_special_requirements|node|lsa_application|default';
  $field_group->group_name = 'group_lsa_special_requirements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Special Requirements',
    'weight' => '0',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Special Requirements',
      'instance_settings' => array(
        'id' => 'node_lsa_application_full_group_lsad_special_requirements',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_special_requirements|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_supervisor_info|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_supervisor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lsa_office_contact_info';
  $field_group->data = array(
    'label' => 'Supervisor Information',
    'weight' => '23',
    'children' => array(
      0 => 'field_lsa_supervisor_first_name',
      1 => 'field_lsa_supervisor_last_name',
      2 => 'field_lsa_supervisor_email',
      3 => 'field_lsa_supervisor_city',
      4 => 'field_lsa_supervisor_postal_code',
      5 => 'field_lsa_supervisor_province',
      6 => 'field_supervisor_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Supervisor Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-lsa-supervisor-info field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_supervisor_info|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsa_survey|node|lsa_application|form';
  $field_group->group_name = 'group_lsa_survey';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Long Service Award Survey',
    'weight' => '21',
    'children' => array(
      0 => 'field_lsa_survey',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Long Service Award Survey',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-lsa-survey field-group-fieldset',
        'description' => 'At the end of the year, a follow-up survey may be sent to collect feedback about your experience with the Long Service Awards program. Please indicate if you do not want to participate below.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_survey|node|lsa_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsad_contact_info|node|lsa_application|default';
  $field_group->group_name = 'group_lsad_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_lsa_street',
      1 => 'field_lsa_city',
      2 => 'field_lsa_email',
      3 => 'field_lsa_home_phone',
      4 => 'field_lsa_alt_email_address',
      5 => 'field_lsa_home_postal_code',
      6 => 'field_lsa_home_province',
      7 => 'group_lsa_office_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_lsa_application_full_group_lsad_contact_info',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsad_contact_info|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsad_personal_info|node|lsa_application|default';
  $field_group->group_name = 'group_lsad_personal_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'id' => 'node_lsa_application_full_group_lsad_personal_info',
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsad_personal_info|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lsad_supervisor_info|node|lsa_application|default';
  $field_group->group_name = 'group_lsad_supervisor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supervisor Information',
    'weight' => '13',
    'children' => array(
      0 => 'field_lsa_supervisor_first_name',
      1 => 'field_lsa_supervisor_last_name',
      2 => 'field_lsa_supervisor_email',
      3 => 'field_lsa_supervisor_city',
      4 => 'field_lsa_supervisor_postal_code',
      5 => 'field_lsa_supervisor_province',
      6 => 'field_supervisor_address',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Supervisor Information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_lsa_application_full_group_lsad_supervisor_info',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsad_supervisor_info|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pin_options|node|lsa_pin_application|form';
  $field_group->group_name = 'group_pin_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pin Options',
    'weight' => '4',
    'children' => array(
      0 => 'field_lsa_pin_service_milestone',
      1 => 'field_lsa_milestone_year',
      2 => 'field_lsa_ministry_rep_email',
      3 => 'field_lsa_other_milestone_years',
      4 => 'field_lsa_pin_ministry_org',
      5 => 'field_lsa_previous_service_miles',
      6 => 'field_lsa_registerer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pin Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-pin-options field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_pin_options|node|lsa_pin_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recipient_details|node|lsa_pin_application|form';
  $field_group->group_name = 'group_recipient_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recipient Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_lsa_pin_employee_number',
      1 => 'field_lsa_pin_first_name',
      2 => 'field_lsa_pin_last_name',
      3 => 'field_lsa_branch_department',
      4 => 'field_lsa_email',
      5 => 'field_lsa_home_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Recipient Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-recipient-details field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_recipient_details|node|lsa_pin_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_service_information|node|lsa_application|default';
  $field_group->group_name = 'group_service_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Service Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_lsa_years_of_service',
      1 => 'field_lsa_received_award',
      2 => 'field_lsa_award',
      3 => 'field_lsa_date_of_retirement',
      4 => 'field_lsa_charity_name_2',
      5 => 'field_lsa_pecsf_charity_name',
      6 => 'field_lsa_pecsf_region',
      7 => 'field_lsa_second_donation',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Service Information',
      'instance_settings' => array(
        'classes' => 'group-service-information',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_lsa_application_full_group_service_information',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_service_information|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_special_requirements|node|lsa_application|default';
  $field_group->group_name = 'group_special_requirements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Requirements',
    'weight' => '5',
    'children' => array(
      0 => 'field_lsa_dietary_guest',
      1 => 'field_lsa_dietary_requirements',
      2 => 'field_lsa_recipient_dietary',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Requirements',
      'instance_settings' => array(
        'id' => 'special-dietary-requirements',
        'classes' => 'group-special-requirements field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_special_requirements|node|lsa_application|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supervisor_details|node|lsa_pin_application|form';
  $field_group->group_name = 'group_supervisor_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supervisor Details',
    'weight' => '7',
    'children' => array(
      0 => 'field_lsa_supervisor_first_name',
      1 => 'field_lsa_supervisor_last_name',
      2 => 'field_lsa_supervisor_email',
      3 => 'field_lsa_office_address',
      4 => 'field_lsa_office_city',
      5 => 'field_lsa_work_phone',
      6 => 'field_lsa_office_postal_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-supervisor-details field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_supervisor_details|node|lsa_pin_application|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administration');
  t('Ceremony Accommodations');
  t('Ceremony Details');
  t('Charitable donation');
  t('Contact Information');
  t('Dietary Requirements');
  t('Home Mailing Address');
  t('Long Service Award Survey');
  t('Name');
  t('Office Information');
  t('Pin Options');
  t('RSVP Information');
  t('Recipient Contact Information');
  t('Recipient Details');
  t('Requirements');
  t('Service Information');
  t('Special Requirements');
  t('Supervisor Details');
  t('Supervisor Information');
  t('Work Information');

  return $field_groups;
}
