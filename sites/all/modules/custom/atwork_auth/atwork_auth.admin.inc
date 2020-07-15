<?php

/*
 * Page callback
 *
 * Provides a form to system_settings_form() to administer our settings
 *
 */
function atwork_auth_settings_form() {
  if (variable_get('atwork_auth_sync_enabled', 0)) {
    $css = <<<EOD
table.atwork-sync-results td.empty {
  background-color: white;
}
table.atwork-sync-results td.match {
  background-color: green;
}
table.atwork-sync-results td.change {
  background-color: orange;
}
EOD;

    drupal_add_css($css, array(
      'group' => CSS_THEME,
      'type' => 'inline',
      'media' => 'screen',
      'preprocess' => FALSE,
    ));

    $form = array();

    // provide some information on the staleness of our users
    $oldest_record = db_select('atwork_auth', 'a')
      ->fields('a', array('timestamp'))
      ->orderBy('timestamp', 'ASC')
      ->range(0,1)
      ->execute()
      ->fetchObject();

    if (isset($oldest_record->timestamp)) {

      $ago = format_interval(time() - $oldest_record->timestamp, 2);

      $status = TRUE;
      $oldest_user = array(
        '#markup' => t('Our oldest user was updated !num ago', array('!num' => $ago)),
      );
    }

    if (variable_get('atwork_auth_sync_enabled', 0)) {
      $latest_wdogs = _atwork_auth_get_recent_cron_runs();

      if ($latest_wdogs) {

        $watchdogs = array(
          '#type' => 'fieldset',
          '#title' => t('Recent Cron Runs'),
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
        );

        foreach ($latest_wdogs as $wdog) {
          $watchdogs[$wdog['wid']] = array(
            '#type' => 'fieldset',
            '#title' => format_date($wdog['timestamp']),
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
          );

          $watchdogs[$wdog['wid']][$wdog['timestamp']] = array(
            '#markup' => $wdog['message'],
          );
        }
      }
    }

    $form['status'] = array(
      '#type' => 'fieldset',
      '#title' => t('Status'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    if (isset($oldest_user)) {
      $form['status']['oldest_user'] = $oldest_user;
    }

    if (isset($watchdogs)) {
      $form['status']['watchdogs'] = $watchdogs;
    }

    $form['status']['run_sync'] = array(
      '#type' => 'button',
      '#value' => t('Sync Now'),
    );
  }

  $form['atwork_auth_watchdog_new'] = array(
    '#type' => 'checkbox',
    '#title' => t('Record new external users in watchdog'),
    '#default_value' => variable_get('atwork_auth_watchdog_new', 1),
  );

  $form['atwork_auth_watchdog_rename'] = array(
    '#type' => 'checkbox',
    '#title' => t('Record renamed users in watchdog'),
    '#default_value' => variable_get('atwork_auth_watchdog_rename', 1),
  );

  $form['atwork_auth_watchdog_nosm'] = array(
    '#type' => 'checkbox',
    '#title' => t('Record site access without Siteminder headers'),
    '#default_value' => variable_get('atwork_auth_watchdog_nosm', 1),
  );

  $form['atwork_auth_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix to use for renaming users'),
    '#default_value' => variable_get('atwork_auth_prefix', 'old'),
    '#size' => 6,
    '#description' => t('Example: myidir_<strong>old</strong>1'),
    '#maxlength' => 20,
  );

  $form['atwork_auth_excluded_idirs'] = array(
    '#type' => 'textarea',
    '#title' => t('A list of excluded IDIRs'),
    '#default_value' => variable_get('atwork_auth_excluded_idirs', ''),
//    '#rows' => 6,
    '#description' => t('These users will not be logged in, they will reach the site as anonymous users.'),
  );

  $form['atwork_auth_rename_fields'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update email, display name and/or ministry code on site access'),
    '#default_value' => variable_get('atwork_auth_rename_fields', 1),
  );

  $form['field_mapping'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field Mapping'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => t('Leave blank to ignore field.<br /><strong>Note:</strong> If enabled, $user->mail is automatically mapped to HTTP_SMGOV_USEREMAIL.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="atwork_auth_rename_fields"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['field_mapping']['atwork_auth_display_name_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Field to use for HTTP_SMGOV_USERDISPLAYNAME'),
    '#default_value' => variable_get('atwork_auth_display_name_field', ''),
    '#size' => 30,
    '#description' => t('Example: <strong>field_profile_display_name</strong>'),
    '#maxlength' => 255,
  );
  $form['field_mapping']['atwork_auth_min_code_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Field to use for Ministry Code'),
    '#default_value' => variable_get('atwork_auth_min_code_field', ''),
    '#size' => 30,
    '#description' => t('Example: <strong>field_profile_ministry_code</strong>.<br /><strong>Note:</strong> This is derived from HTTP_SMGOV_USERDISPLAYNAME.'),
    '#maxlength' => 255,
  );

  $form['atwork_auth_sync_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sync GAL with Drupal fields'),
    '#default_value' => variable_get('atwork_auth_sync_enabled', 0),
  );

  $form['atwork_auth_sync_on_user_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sync GAL with Drupal fields when a user edits their profile (kinda slow)'),
    '#default_value' => variable_get('atwork_auth_sync_on_user_edit', 0),
  );

  $form['atwork_auth_cron'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sync Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#states' => array(
      'invisible' => array(
        ':input[name="atwork_auth_sync_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['atwork_auth_cron']['atwork_auth_gal_fieldmap'] = array(
    '#type' => 'textarea',
    '#title' => t('Drupal - GAL field map'),
    '#default_value' => variable_get('atwork_auth_gal_fieldmap', ''),
    '#description' => t('Provide a list of key|value pairs in the format of drupal_field|gal_field<br />Example: <strong>field_gal_title|title</strong>'),
  );

  $form['atwork_auth_cron']['atwork_auth_disable_gal_fields'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable these fields from being edited'),
    '#default_value' => variable_get('atwork_auth_disable_gal_fields', 1),
    '#description' => t('Highly recommended!'),
  );

  $form['atwork_auth_cron']['atwork_auth_disable_gal_fields_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Provide a message explaining the disabled fields'),
    '#default_value' => variable_get('atwork_auth_disable_gal_fields_message', ''),
    '#description' => t('Leave blank to provide no message.'),
    '#maxlength' => 255,
    '#length' => 120,
    '#states' => array(
      'invisible' => array(
        ':input[name="atwork_auth_disable_gal_fields"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['atwork_auth_cron']['atwork_auth_disable_gal_fields_fieldgroup'] = array(
    '#type' => 'textfield',
    '#title' => t('Apply the message to a field group as well'),
    '#default_value' => variable_get('atwork_auth_disable_gal_fields_fieldgroup', ''),
    '#description' => t('Example: "group_contact_info". Leave blank to disable.'),
    '#maxlength' => 100,
    '#states' => array(
      'invisible' => array(
        ':input[name="atwork_auth_disable_gal_fields"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['atwork_auth_cron']['atwork_auth_gal_on_creation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sync fields on user creation'),
    '#default_value' => variable_get('atwork_auth_gal_on_creation', 0),
  );

  $form['atwork_auth_cron']['atwork_auth_cron_num_users'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of users to process per cron run'),
    '#default_value' => variable_get('atwork_auth_cron_num_users', 10),
    '#size' => 4,
    '#maxlength' => 4,
  );

  $form['atwork_auth_cron']['atwork_auth_cron_num_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of days to wait until updating a user again'),
    '#default_value' => variable_get('atwork_auth_cron_num_days', 3),
    '#size' => 4,
    '#maxlength' => 4,
  );

  $form['atwork_auth_cron']['atwork_auth_gal_num_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of days from last GAL update'),
    '#default_value' => variable_get('atwork_auth_gal_num_days', 0),
    '#description' => t('To save resources, filter "whenchanged" in our LDAP query by this many days. This field is optional (leave blank or zero).'),
    '#size' => 4,
    '#maxlength' => 4,
  );

  $form['atwork_auth_cron']['atwork_auth_cron_watchdog'] = array(
    '#type' => 'checkbox',
    '#title' => t('Record detailed summary of cron run in watchdog'),
    '#default_value' => variable_get('atwork_auth_cron_watchdog', 0),
  );

  $form['atwork_auth_cron']['atwork_auth_cron_watchdog_num'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of cron runs to save in watchdog'),
    '#default_value' => variable_get('atwork_auth_cron_watchdog_num', 10),
    '#description' => t('Leave blank to leave it up to Drupal to delete old watchdog entries.'),
    '#size' => 4,
    '#maxlength' => 4,
    '#states' => array(
      'invisible' => array(
        ':input[name="atwork_auth_cron_watchdog"]' => array('checked' => FALSE),
      ),
    ),
  );


  if (!module_exists('atwork_ldap')) {
    variable_set('atwork_auth_sync_enabled', 0);
    $form['atwork_auth_sync_enabled']['#disabled'] = TRUE;
    $form['atwork_auth_sync_enabled']['#default_value'] = 0;
    $form['atwork_auth_sync_enabled']['#description'] = t('GAL Syncing is not available without the atwork_ldap module');
  }

  return system_settings_form($form);
}

function atwork_auth_settings_form_validate(&$form, &$form_state) {
  if ($form_state['clicked_button']['#parents'][0] == 'run_sync') {
    require_once(drupal_get_path('module', 'atwork_auth') . '/atwork_auth.cron.inc');
    _atwork_auth_sync();
    _atwork_auth_trim_watchdog();
  }
}
