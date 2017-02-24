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
    'label' => 'Delivery Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_lsa_office_address',
      1 => 'field_lsa_office_city',
      2 => 'field_lsa_office_postal_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Delivery Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-delivery-details field-group-fieldset ',
        'description' => '*NOTE: Service pins will be mailed directly to the recipient\'s supervisor between June 1-10. Please enter the address and contact details for your supervisor, below.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_delivery_details|node|lsa_pin_application|form'] = $field_group;

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
    'weight' => '21',
    'children' => array(
      0 => 'field_lsa_notes',
      1 => 'field_lsa_form_date_stamp',
      2 => 'field_lsa_retro_active',
      3 => 'group_lsa_rsvp',
      4 => 'group_lsa_ceremony_details',
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
    'weight' => '38',
    'children' => array(
      0 => 'field_lsa_alternate_min_org',
      1 => 'field_lsa_actual_min_org',
      2 => 'field_lsa_ceremonydate',
      3 => 'field_lsa_notes_ceremony',
      4 => 'field_lsa_ceremony_night',
      5 => 'field_lsa_ceremony_response',
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
    'label' => 'Home Contact Information',
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
      'label' => 'Home Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-lsa-contact-info field-group-fieldset ',
        'description' => 'Your home mailing address.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lsa_contact_info|node|lsa_application|form'] = $field_group;

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
      3 => 'field_lsa_office_work_group',
      4 => 'field_lsa_office_address',
      5 => 'field_lsa_office_city',
      6 => 'field_lsa_office_postal_code',
      7 => 'field_lsa_office_province',
      8 => 'group_lsa_supervisor_info',
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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Office Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_lsa_org',
      1 => 'field_lsa_work_phone',
      2 => 'field_lsa_branch_department',
      3 => 'field_lsa_office_work_group',
      4 => 'field_lsa_work_phone_ext',
      5 => 'field_lsa_office_address',
      6 => 'field_lsa_office_city',
      7 => 'field_lsa_office_postal_code',
      8 => 'field_lsa_office_province',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-lsa-office-contact field-group-fieldset ',
      ),
    ),
  );
  $field_groups['group_lsa_office_contact|node|lsa_application|default'] = $field_group;

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
    'label' => 'Name',
    'weight' => '16',
    'children' => array(
      0 => 'field_lsa_prefix',
      1 => 'field_lsa_first_name',
      2 => 'field_lsa_middle_name',
      3 => 'field_lsa_last_name',
      4 => 'group_lsa_contact_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Name',
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
    'weight' => '7',
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
        'description' => 'If the above information is complete, and you have agreed to the terms below, click the “SUBMIT” button at the bottom of the screen. You will then receive:
<ul>
<li> a confirmation page displaying all of the information you’ve entered. Please check this page to ensure the information is accurate. If something is incorrect, contact Gillian Kish <a href="mailto:gillian.kish@gov.bc.ca?Subject=LSA%20pin%20application%20question">(Gillian.kish@gov.bc.ca)</a></li>
<li>an automated email thanking you for your registration.</li>
</ul>
<p class="style-red"> <strong>IMPORTANT:</strong> If you do not receive a confirmation email, you will need to re-submit the request again.</p>
',
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
    'weight' => '37',
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
  $field_group->identifier = 'group_lsa_special_requirements|node|lsa_application|default';
  $field_group->group_name = 'group_lsa_special_requirements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Special Requirements',
    'weight' => '8',
    'children' => array(
      0 => 'field_lsa_specialrequirements',
      1 => 'field_specialrequirement_descrip',
    ),
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
  $field_group->identifier = 'group_lsad_contact_info|node|lsa_application|default';
  $field_group->group_name = 'group_lsad_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_lsa_street',
      1 => 'field_lsa_city',
      2 => 'field_lsa_email',
      3 => 'field_lsa_home_phone',
      4 => 'field_lsa_alt_email_address',
      5 => 'field_lsa_home_postal_code',
      6 => 'field_lsa_home_province',
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
    'weight' => '1',
    'children' => array(
      0 => 'field_lsa_prefix',
      1 => 'field_lsa_first_name',
      2 => 'field_lsa_middle_name',
      3 => 'field_lsa_last_name',
    ),
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
    'weight' => '4',
    'children' => array(
      0 => 'field_lsa_supervisor_first_name',
      1 => 'field_lsa_supervisor_last_name',
    ),
    'format_type' => 'div',
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
      2 => 'field_lsa_other_milestone_years',
      3 => 'field_lsa_pin_ministry_org',
      4 => 'field_lsa_previous_service_miles',
      5 => 'field_lsa_registerer',
      6 => 'field_lsa_pin_sup_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pin-options field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
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
      1 => 'field_lsa_pin_prefix',
      2 => 'field_lsa_pin_first_name',
      3 => 'field_lsa_pin_last_name',
      4 => 'field_lsa_branch_department',
      5 => 'field_lsa_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-recipient-details field-group-fieldset ',
        'required_fields' => 1,
      ),
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
    'weight' => '0',
    'children' => array(
      0 => 'field_lsa_register_last_year',
      1 => 'field_lsa_employee_number',
      2 => 'field_lsa_years_of_service',
      3 => 'field_lsa_received_award',
      4 => 'field_lsa_engravement',
      5 => 'field_lsa_retiring_thisyear',
      6 => 'field_lsa_25year_certificatename',
      7 => 'field_lsa_award',
      8 => 'field_lsa_date_of_retirement',
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
  $field_group->identifier = 'group_supervisor_details|node|lsa_pin_application|form';
  $field_group->group_name = 'group_supervisor_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lsa_pin_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supervisor Details',
    'weight' => '6',
    'children' => array(
      0 => 'field_lsa_supervisor_first_name',
      1 => 'field_lsa_supervisor_last_name',
      2 => 'field_lsa_supervisor_email',
      3 => 'field_lsa_office_address',
      4 => 'field_lsa_office_city',
      5 => 'field_lsa_work_phone',
      6 => 'field_lsa_work_phone_ext',
      7 => 'field_lsa_office_postal_code',
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
  t('Ceremony Details');
  t('Contact Information');
  t('Delivery Details');
  t('Home Contact Information');
  t('Name');
  t('Office Information');
  t('Pin Options');
  t('RSVP Information');
  t('Recipient Details');
  t('Service Information');
  t('Special Requirements');
  t('Supervisor Details');
  t('Supervisor Information');
  t('Work Information');

  return $field_groups;
}
