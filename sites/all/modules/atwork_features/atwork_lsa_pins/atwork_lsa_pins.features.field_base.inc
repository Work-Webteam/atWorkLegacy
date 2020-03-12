<?php

/**
 * @file
 * atwork_lsa_pins.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function atwork_lsa_pins_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_lsa_branch_department'.
  $field_bases['field_lsa_branch_department'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_branch_department',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_email'.
  $field_bases['field_lsa_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_lsa_home_phone'.
  $field_bases['field_lsa_home_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_home_phone',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'phone',
    'settings' => array(
      'country' => 'ca',
    ),
    'translatable' => 0,
    'type' => 'phone',
  );

  // Exported field_base: 'field_lsa_milestone_year'.
  $field_bases['field_lsa_milestone_year'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_milestone_year',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_lsa_ministry_rep_email'.
  $field_bases['field_lsa_ministry_rep_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_ministry_rep_email',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_office_address'.
  $field_bases['field_lsa_office_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_office_address',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_office_city'.
  $field_bases['field_lsa_office_city'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_office_city',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_office_postal_code'.
  $field_bases['field_lsa_office_postal_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_office_postal_code',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 7,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_other_milestone_years'.
  $field_bases['field_lsa_other_milestone_years'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_other_milestone_years',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_lsa_pin_employee_number'.
  $field_bases['field_lsa_pin_employee_number'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_pin_employee_number',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 8,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_pin_first_name'.
  $field_bases['field_lsa_pin_first_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_pin_first_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_pin_last_name'.
  $field_bases['field_lsa_pin_last_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_pin_last_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_pin_ministry_org'.
  $field_bases['field_lsa_pin_ministry_org'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_pin_ministry_org',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        3 => 'Agricultural Land Commission',
        6 => 'Auditor General for Local Government',
        7 => 'BC Arts Council',
        9 => 'BC Farm Industry Review Board',
        87 => 'BC Financial Services Authority',
        10 => 'BC Human Rights Tribunal',
        11 => 'BC Pension Corporation',
        12 => 'BC Public Service Agency',
        13 => 'BC Review Board',
        14 => 'BC Transportation Financing Authority',
        15 => 'Board Resourcing and Development Office',
        19 => 'Civil Resolution Tribunal',
        20 => 'Community Care and Assisted Living Appeal Board',
        21 => 'Community Living BC',
        8 => 'Coroners Service of BC',
        22 => 'Crown Agencies Resource Office',
        23 => 'Destination BC Corp',
        25 => 'Elections BC',
        27 => 'Employment and Assistance Appeal Tribunal',
        31 => 'Environmental Appeal Board',
        32 => 'Environmental Assessment Office',
        36 => 'Financial Services Tribunal',
        37 => 'Forest Appeals Commission',
        38 => 'Forest Practices Board',
        40 => 'Government Communications and Public Engagement',
        41 => 'Government House',
        43 => 'Health Professions Review Board',
        84 => 'Healthlink BC',
        44 => 'Hospital Appeal Board',
        45 => 'Independent Investigations Office',
        48 => 'Intergovernmental Relations Secretariat',
        49 => 'Islands Trust',
        54 => 'Legislative Assembly of BC',
        85 => 'Liquor Distribution Branch',
        56 => 'Mental Health Review Board',
        2 => 'Ministry of Advanced Education, Skills and Training',
        4 => 'Ministry of Agriculture',
        5 => 'Ministry of Attorney General',
        17 => 'Ministry of Children and Family Development',
        18 => 'Ministry of Citizens\' Services',
        24 => 'Ministry of Education',
        29 => 'Ministry of Energy, Mines and Petroleum Resources',
        30 => 'Ministry of Environment and Climate Change Strategy',
        34 => 'Ministry of Finance',
        39 => 'Ministry of Forests, Lands, Natural Resource Operations and Rural Development',
        42 => 'Ministry of Health',
        46 => 'Ministry of Indigenous Relations and Reconciliation',
        50 => 'Ministry of Jobs, Economic Development and Competitiveness',
        51 => 'Ministry of Labour',
        55 => 'Ministry of Mental Health and Addictions',
        57 => 'Ministry of Municipal Affairs and Housing',
        71 => 'Ministry of Public Safety and Solicitor General',
        76 => 'Ministry of Social Development and Poverty Reduction',
        79 => 'Ministry of Tourism, Arts and Culture',
        81 => 'Ministry of Transportation and Infrastructure',
        58 => 'Office of the Auditor General',
        86 => 'Office of the Container Trucking Commissioner',
        59 => 'Office of the Fire Commissioner',
        60 => 'Office of the Information and Privacy Commissioner',
        61 => 'Office of the Merit Commissioner',
        62 => 'Office of the Ombudsperson',
        63 => 'Office of the Police Complaints Commissioner',
        64 => 'Office of the Premier',
        65 => 'Office of the Representative for Children and Youth',
        66 => 'Oil and Gas Appeal Tribunal',
        67 => 'Passenger Transportation Board',
        68 => 'Property Assessment Appeal Board',
        69 => 'Provincial Court',
        70 => 'Public Guardian and Trustee',
        72 => 'Public Sector Employers\' Council Secretariat',
        73 => 'Queen\'s Printer',
        88 => 'Registrar of Lobbyists',
        74 => 'Royal BC Museum Corporation',
        75 => 'Safety Standards Appeal Board',
        78 => 'Surface Rights Board of BC',
        83 => 'Workers’ Compensation Appeal Tribunal',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_lsa_pin_service_milestone'.
  $field_bases['field_lsa_pin_service_milestone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_pin_service_milestone',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        5 => '5 Years',
        10 => '10 Years',
        15 => '15 Years',
        20 => '20 Years',
        25 => '25 Years',
        30 => '30 Years',
        35 => '35 Years',
        40 => '40 Years',
        45 => '45 Years',
        50 => '50 Years',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_lsa_pin_terms'.
  $field_bases['field_lsa_pin_terms'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_pin_terms',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_lsa_previous_service_miles'.
  $field_bases['field_lsa_previous_service_miles'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_previous_service_miles',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        5 => 5,
        10 => 10,
        15 => 15,
        20 => 20,
        25 => 25,
        30 => 30,
        35 => 35,
        40 => 40,
        45 => 45,
        50 => 50,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_lsa_registerer'.
  $field_bases['field_lsa_registerer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_registerer',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'I am registering for myself',
        2 => 'I am a supervisor, registering on behalf of my employee',
        3 => 'I am a ministry rep, registering on behalf of an employee in our ministry/organization',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_lsa_supervisor_email'.
  $field_bases['field_lsa_supervisor_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_supervisor_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_lsa_supervisor_first_name'.
  $field_bases['field_lsa_supervisor_first_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_supervisor_first_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_supervisor_last_name'.
  $field_bases['field_lsa_supervisor_last_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_supervisor_last_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_lsa_work_phone'.
  $field_bases['field_lsa_work_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_lsa_work_phone',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'phone',
    'settings' => array(
      'country' => 'ca',
    ),
    'translatable' => 0,
    'type' => 'phone',
  );

  // Exported field_base: 'field_province'.
  $field_bases['field_province'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_province',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 2,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
