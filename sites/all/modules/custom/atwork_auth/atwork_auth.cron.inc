<?php


/*
 * Perform GAL updates
 * 
 * Different methods are used based on variable settings.
 * atwork_auth_cron_num_days
 *    Don't update users more often than specified here
 * atwork_auth_cron_num_users
 *    number of users to lookup per run
 * atwork_auth_gal_num_days
 *    If set we will filter GAL on last update
 *      IE: don't return users who haven't been updated in the specified time period
 *    If set don't worry about non-returns
 *    The idea here is not to update users who haven't been updated in a long time
 *      as it's better to put our resources to users who need it.
 */
function _atwork_auth_sync() {
  // establish our variables
  $timestamp = REQUEST_TIME - (variable_get('atwork_auth_cron_num_days', 7) * 60 * 60 * 24);
  $limit = variable_get('atwork_auth_cron_num_users', 20);
  $additional_filter = '';
  
  // provide some fancy looking output
  $table_headers = array(t('uid'), t('name'), t('mail'));
  $message = t('INITIATING SYNC...<br />');
  
  if ($gal_fields = list_extract_allowed_values(variable_get('atwork_auth_gal_fieldmap', ''), 'list_text', FALSE)) {
    foreach ($gal_fields as $f => $g) {
      $table_headers[$f] = str_replace('_', ' ', $f);
    }
  }
  
  $table_headers['notes'] = t('Notes');
  
  $table_rows = array();
  
  // we query atwork_auth because we need the GUID and the timestamp field
  // represents the last time we did an update
  $query = db_select('atwork_auth', 'a')
   ->fields('a', array('uid', 'guid'))
   ->condition('a.timestamp', $timestamp, '<')
   ->isNotNull('a.guid')
   ->range(0,$limit)
   ->orderBy('a.timestamp', 'ASC')
   ->execute();
  
  $users = array();
  while ($record = $query->fetchAssoc()) {
    $users[] = $record;
  }
  
  // for output mssage
  $message .= t('Loaded !num users.<br />', array('!num' => count($users)));
  $message .= t('Syncing !num GAL fields.<br />', array('!num' => count($gal_fields)));
  $changed = 0;
  $found = 0;
  
  // deal with whenchanged filtering
  if (variable_get('atwork_auth_gal_num_days', 0)) {
    $message .= t('Filtering on GAL\'s "whenchanged" field for !num days.<br />', array('!num' => variable_get('atwork_auth_gal_num_days', 0)));
    
    $last_update_limit = REQUEST_TIME - (variable_get('atwork_auth_gal_num_days', 0) * 60 * 60 * 24);
    $last_update_limit = date('Ymd', $last_update_limit);
    $last_update_limit .= '070000.0Z';
    $additional_filter = '(whenchanged>=' . $last_update_limit . ')';
  }
  
  // finally ready to go through our results!
  foreach ($users as $uids) {
    // a single ldap query, even by a GUID filter shouldn't take very long
    set_time_limit(3);
    $user = user_load($uids['uid']);
    
    // for our output table
    $table_row = array(
      'uid' => array(
        'data' => l('#' . $user->uid, 'user/' . $user->uid),
        'title' => t('#!uid | !name | !display_name', array(
          '!uid' => $uids['uid'],
          '!name' => $user->name,
          '!display_name' => _atwork_display_name($user),
        )),
      ),
      'name' => array(
        'data' => 'no result',
        'class' => 'empty',
        'title' => t('#!uid | !field', array('!uid' => $uids['uid'], '!field' => 'name')),
      ),
      'mail' => array(
        'data' => 'no result',
        'class' => 'empty',
        'title' => t('#!uid | !field', array('!uid' => $uids['uid'], '!field' => 'mail')),
      ),
    );
    
    // add all our fields to the table headers
    if ($gal_fields = list_extract_allowed_values(variable_get('atwork_auth_gal_fieldmap', ''), 'list_text', FALSE)) {
      foreach ($gal_fields as $f => $g) {
        $table_row[$f] = array(
          'data' => 'no result',
          'class' => 'empty',
          'title' => t('#!uid | !field', array('!uid' => $uids['uid'], '!field' => $f)),
        );
      }
    }
    
    $table_row['notes'] = '';
    
    // default is to not save users unless a change was made
    $save_user = FALSE;
    
    // send our LDAP query using IDIR as filter
    $gal_result = _atwork_auth_add_gal_fields($user, 'samaccountname', $user->name, array('mail', 'bcgovguid', 'samaccountname'), $additional_filter);
    
    // maybe just skip to next user...
    if (!$gal_result && $additional_filter) {
      $table_row['notes'] .= t('LDAP Query returned nothing, probably due to "whenchanged" filter. Skipping to next result');
      continue;
    }
    
    // if we get nothing back with IDIR it might have changed, use GUID
    if (!$gal_result && !$additional_filter) {
      $table_row['notes'] .= t('First LDAP query failed, trying GUID... ');
      $gal_result = _atwork_auth_add_gal_fields($user, 'bcgovguid', $uids['guid'], array('mail', 'bcgovguid', 'samaccountname'), $additional_filter);
    }
    
    // if we didn't use an additional filter the onl reason we shouldn't get a
    // result is if the IDIR no longer exists.
    // we should do something here at some point.....
    if (!$gal_result && !$additional_filter) {
      $table_row['notes'] .= t('GUID query Failed, this user is gone.');
    }
    
    // if we get a result we should have a mail and bcgovguid field
    // can't proceed without them
    elseif (isset($gal_result['additional_fields']['mail']) && isset($gal_result['additional_fields']['bcgovguid']) && isset($gal_result['additional_fields']['samaccountname'])) {
      $found++;
      
      $gal_mail = $gal_result['additional_fields']['mail'];
      $gal_guid = $gal_result['additional_fields']['bcgovguid'];
      $gal_idir = str_replace("idir\\", "", strtolower($gal_result['additional_fields']['samaccountname']));
      
      // check for IDIR-GUID mismatches
      // these occur because IDIRs occasionally get changed
      if ($gal_guid != $uids['guid']) {
        $gal_secondary_result = _atwork_auth_add_gal_fields($user, 'bcgovguid', $uids['guid'], array('mail', 'samaccountname'), $additional_filter);
        watchdog('atwork_auth_sync_mismatch', 'IDIR - GUID mismatch with ' . $user->name . '. Querying their GUID:' . print_r($gal_secondary_result, TRUE));
      }
      
      // at this point we have a properly matched GAL(LDAP)-Drupal account
      // update all our GAL fields in Drupal as well as the email if needed
      else {
        if (strtolower($gal_mail) != strtolower($user->mail)) {
          $table_row['mail']['class'] = 'change';
          $table_row['mail']['data'] = 'changed';
          $table_row['mail']['title'] .= t(' | from !from to !to', array(
            '!from' => $user->mail,
            '!to' => $gal_mail,
          ));
          
          $user->mail = $gal_mail;
          $save_user = TRUE;
        }
        else {
          $table_row['mail']['class'] = 'match';
          $table_row['mail']['data'] = 'unchanged';
        }
        
        // the following can happen if the initial query by name failed and we queried by GUID
        if ($gal_idir != $user->name) {
          $table_row['name']['class'] = 'change';
          $table_row['name']['data'] = 'changed';
          $table_row['name']['title'] .= t(' | from !from to !to', array(
            '!from' => $user->name,
            '!to' => $gal_idir,
          ));
          
          // we want to give $user this new name but need to check it first
          $potential_name = _atwork_auth_get_unique_name($gal_idir);
          
          // if $gal_idir is taken rename the account using it
          if ($potential_name != $gal_idir) {
            _atwork_auth_rename_user($gal_idir, $potential_name);
          }
          
          _atwork_auth_rename_user($user->name, $gal_idir);
          
          // reload the $user and reset the cache to proceed
          $user = user_load($user->uid, TRUE);
        }
        else {
          $table_row['name']['class'] = 'match';
          $table_row['name']['data'] = 'unchanged';
        }
        
        // since we already got our data from additional_fields unset it now
        // so we can pass the whole rest of $gal_result right into our user object
        unset($gal_result['additional_fields']);
        foreach ($gal_result as $field_name => $field) {
          if ($user->$field_name != $field) {
            // table stuff
            $field_language = field_language('user', $user, $field_name); 
            $table_row[$field_name]['class'] = 'change';
            $table_row[$field_name]['data'] = 'changed';
            
            if (isset($user->{$field_name}[$field_language][0]['value'])) {
              $from = $user->{$field_name}[$field_language][0]['value'];
            }
            else {
              $from = 'NULL';
            }
            
            $table_row[$field_name]['title'] .= t(' | from !from to !to', array(
              '!from' => $from,
              '!to' => $field[$field_language][0]['value'],
            ));
              
            $user->$field_name = $field;
            $save_user = TRUE;
          }
          else {
            $table_row[$field_name]['class'] = 'match';
            $table_row[$field_name]['data'] = 'unchanged';
          }
        }
        
        // finally save our updated user!
        if ($save_user) {
          $table_row['notes'] .= 'Saved!';
          user_save($user);
          $changed++;
        }
        else {
          $table_row['notes'] .= 'No changed found.';
        }
      }
    }
    
    // end of check for mail and guid
    // we shouldn't ever end up here so record the event
    else {
      watchdog('atwork_auth_sync', 'LDAP Query failed to retrieve LDAP fields "mail" and "bcgovguid": <strong>' . $user->mail . '</strong>, UID: ' . $user->uid . ', IDIR: ' . $user->name);
    }
    
    // set a last updated field so we won't query them again for a bit
    _atwork_auth_user_updated($user->uid);
    $table_rows[] = $table_row;
  }
  
  // prepare our awesome table :)
  $variables = array(
    'header' => $table_headers,
    'rows' => $table_rows,
    'attributes' => array('class' => array('atwork-sync-results'))
  );
  
  $message .= t('Found !num users in GAL.<br />', array('!num' => $found));
  $message .= t('Updated !num users.<br />', array('!num' => $changed));
  $message .= t('Script took !num seconds.', array('!num' => (time() - REQUEST_TIME)));
  drupal_set_message($message);
  
  if (variable_get('atwork_auth_cron_watchdog', 0)) {
    watchdog('atwork_auth_sync_summary', t('!message<br />!summary', array(
      '!message' => $message, 
      '!summary' => theme('table', $variables),
    )));
  }
  else {
    watchdog('atwork_auth_sync', $message);
  }
}

/*
 * If the site is set to store a lot of watchdog entries we might 
 * want to restrict the number of sync results
 */
function _atwork_auth_trim_watchdog() {
  $wids_to_save = array();
  $latest_wdogs = _atwork_auth_get_recent_cron_runs();
  if ($latest_wdogs) {
    foreach ($latest_wdogs as $latest_wdog) {
      $wids_to_save[] = $latest_wdog['wid'];
    }
  
    $num_deleted = db_delete('watchdog')
      ->condition('wid', $wids_to_save,'NOT IN')
      ->condition('type', 'atwork_auth_sync_summary')
      ->execute();
  }
}