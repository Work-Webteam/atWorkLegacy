<?php

function atwork_auth_get_missing_guids() {
  $atwork_ldap = new atwork_ldap;

  $query = db_select('atwork_auth', 'a')->fields('a', array('uid'));

  $query
    ->join('users', 'u', 'u.uid = a.uid');

  $result = $query->fields('u', array('name', 'mail'))
    ->condition('a.timestamp', REQUEST_TIME - (60*60*24*7), '<')
    ->condition('a.guid', NULL)
    ->range(0,4000)
    ->execute();

  $users = array();
  while ($record = $result->fetchAssoc()) {
    $users[] = $record;
  }

  if (!$users) return '<p>' . t('GUIDs are up-to-date!') . '</p>';

  foreach ($users as &$user) {
    $result = $atwork_ldap->query('person', 'mail', $user['mail'], array('bcgovGUID'));
    $user['guid'] = isset($result[0]['bcgovguid'][0]) ? $result[0]['bcgovguid'][0] : '';
  }

  foreach ($users as $user) {
    if (!$user['guid']) {
      $user['guid'] = NULL;
    }

    // exclude duplicates
    $exists = db_select('atwork_auth', 'a')
      ->fields('a', array('uid'))
      ->condition('a.guid', $user['guid'])
      ->execute()
      ->fetchAssoc();

    if (!$exists) {
      db_update('atwork_auth')
        ->fields(array(
          'guid' => $user['guid'],
        ))
        ->condition('uid', $user['uid'])
        //   ->condition('guid', NULL, 'IS NOT')
        ->execute();
    }
    // set time stamp
    db_update('atwork_auth')
      ->fields(array(
        'timestamp' => REQUEST_TIME,
      ))
      ->condition('uid', $user['uid'])
      ->execute();
  }

  return '<p>' . t('Processed !num users in !time seconds', array('!num' => count($users), '!time' => time() - REQUEST_TIME)) . '</p>';
}

