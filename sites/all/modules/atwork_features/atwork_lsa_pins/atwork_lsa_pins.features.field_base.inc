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
        1 => 'Accommodation & Real Estate Services (ARES)',
        2 => 'Advanced Education, Skills & Training',
        3 => 'Agricultural Land Commission',
        4 => 'Agriculture',
        5 => 'Attorney General',
        6 => 'Auditor General for Local Government',
        7 => 'BC Arts Council',
        8 => 'BC Coroners Service',
        9 => 'BC Farm Industry Review Board',
        10 => 'BC Human Rights Tribunal',
        11 => 'BC Pension Corporation',
        12 => 'BC Public Service Agency',
        13 => 'BC Review Board',
        14 => 'BC Transportation Financing Authority',
        15 => 'Board Resourcing & Development Office',
        16 => 'Building Code Appeal Board',
        17 => 'Children & Family Development',
        18 => 'Citizens\' Services',
        19 => 'Civil Resolution Tribunal',
        20 => 'Community Care & Assisted Living Appeal Board',
        21 => 'Community Living BC',
        22 => 'Crown Agencies Resource Office',
        23 => 'Destination BC Corp',
        24 => 'Education',
        25 => 'Elections BC',
        26 => 'Emergency Management BC',
        27 => 'Employment & Assistance Appeal Tribunal',
        28 => 'Employment Standards Tribunal',
        29 => 'Energy, Mines & Petroleum Resources',
        30 => 'Environment & Climate Change Strategy',
        31 => 'Environmental Appeal Board',
        32 => 'Environmental Assessment Office',
        33 => 'Family Maintenance Enforcement Program',
        34 => 'Finance',
        35 => 'Financial Institutions Commission (FICOM)',
        36 => 'Financial Services Tribunal',
        37 => 'Forest Appeals Commission',
        38 => 'Forest Practices Board',
        39 => 'Forests, Lands, Natural Resource Operations & Rural Development',
        40 => 'Government Communications & Public Engagement',
        41 => 'Government House',
        42 => 'Health',
        43 => 'Health Professions Review Board',
        44 => 'Hospital Appeal Board',
        45 => 'Independent Investigations Office',
        46 => 'Indigenous Relations & Reconciliation',
        47 => 'Industry Training Appeal Board',
        48 => 'Intergovernmental Relations Secretariat',
        49 => 'Islands Trust',
        50 => 'Jobs, Trade & Technology',
        51 => 'Labour',
        52 => 'Labour Relations Board',
        53 => 'Land and Water BC',
        54 => 'Legislative Assembly of BC',
        55 => 'Mental Health & Addictions',
        56 => 'Mental Health Review Board',
        57 => 'Municipal Affairs & Housing',
        58 => 'Office of the Auditor General',
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
        71 => 'Public Safety & Solicitor General',
        72 => 'Public Sector Employers\' Council Secretariat',
        73 => 'Queen\'s Printer',
        74 => 'Royal BC Museum Corporation',
        75 => 'Safety Standards Appeal Board',
        76 => 'Social Development & Poverty Reduction',
        77 => 'Supreme Court of British Columbia',
        78 => 'Surface Rights Board of BC',
        79 => 'Tourism, Arts and Culture',
        80 => 'Tourism BC',
        81 => 'Transportation & Infrastructure',
        82 => 'Vital Statistics',
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

  return $field_bases;
}
