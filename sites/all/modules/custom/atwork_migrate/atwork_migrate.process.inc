<?php

function _atwork_migrate_d6_database() {
  $database = array(
      'database' => 'drupal',
      'username' => 'drupal_ro',
      'password' => 'aal1^Ong',
      'host' => '142.34.152.24',
      'driver' => 'mysql',
      'prefix' => 'atwork_',
  );
  
  Database::addConnectionInfo('D6Database', 'default', $database);
  db_set_active('D6Database');
}

function atwork_migrate_prepare_batch(&$context) {
  // clear users table manually because we don't want to lose our #1 account
  $num_deleted = db_delete('users')
    ->condition('uid', 1, '>')
    ->execute();
  
  $message = 'Cleared ' . $num_deleted . ' user accounts.<br />';
  
  // clear subscriptions table manually - it uses uid of -2 to set global defaults
  $num_deleted = db_delete('subscriptions_user')
    ->condition('uid', 0, '>')
    ->execute();
  
  $message = 'Cleared ' . $num_deleted . ' subscriptions.<br />';
  
  // files are done manually because of video files
  // we don't want to have to delete/restore them every time!
//  $num_deleted = db_delete('file_managed')
//    ->condition('filemime', 'video/mp4', '!=')
//    ->condition('filemime', 'video/x-flv', '!=')
//    ->execute();
  
  $context['results'][] = $message;
  $context['message'] = 'Pre-Migration tasks';
}

function atwork_migrate_process_batch($table, &$context) {
  // get our list of tables
  // this array has all the information we need to migrate the database
  $tables = _atwork_migrate_table_list();
  
  // now connect to the source database
  _atwork_migrate_d6_database();
  
  // submit our query
  $result = db_query($tables[$table]['select_query']);
  
  // we have our data now go back to destination (local) database
  db_set_active();
  
  // grab the first row so we can get the fields for use in our insert function
  $sample_record = $result->fetchObject();
  $fields = array();
  foreach ($sample_record as $field => $value) {
    $fields[] = $field;
  }
  
  
  // set up our db_insert variable to be re-used for each record
  $insert = db_insert($tables[$table]['new_name'])->fields($fields);
  
  foreach ($result as $record) {
    // turn into array
    $data = array();
    foreach ($record as $field => $value) {
      $data[$field] = $value;
    }
    
    $key = $insert->values($data)->execute();
    
  }
  
  $context['results'][] = t('Migrated {!table} table', array('!table' => $table));
  $context['message'] = t('Migrating {!table} table', array('!table' => $table));
}

function _atwork_migrate_table_list() {
  $tables = array(
    'authmap' => array( 
      'new_name' => 'authmap',
      'select_query' => 'SELECT * FROM {authmap}',
    ),
    
    'poll' => array(
      'new_name' => 'poll',
      'select_query' => 'SELECT nid, runtime, active FROM {atworkpoll}',
    ),
    
    // splitting our current modified poll table into 2
    // new poll customizations build on core poll module, don't replace it
    'poll_2' => array(
      'new_name' => 'atwork_polls',
      'select_query' => 'SELECT nid, multichoice FROM {atworkpoll}',
    ),
    
    'poll_choice' => array(
      'new_name' => 'poll_choice',
      'select_query' => 'SELECT chid, nid, chtext, chvotes, chorder as weight FROM {atworkpoll_choices}',
    ),
    
    'poll_vote' => array(
      'new_name' => 'poll_vote',
      'select_query' => 'SELECT (SELECT c.chid FROM {atworkpoll_choices} c WHERE c.nid = v.nid AND c.chorder = v.chorder) as chid, v.nid, v.uid FROM {atworkpoll_votes} v',
    ),
    
    'comments' => array(
      'new_name' => 'comment',
      'select_query' => "SELECT 
          cid, 
          pid, 
          nid, 
          uid, 
          subject, 
          hostname, 
          timestamp as created, 
          timestamp as changed, 
          status,
          CASE status
            WHEN 0 THEN 1
            WHEN 3 THEN 0
            ELSE 0
          END as status, 
          thread, 
          name, 
          'und' as language 
        FROM {comments}",
    ),
    
    // comments now go in multiple places!
    'comments_2' => array(
      'new_name' => 'field_data_comment_body',
      'select_query' => "SELECT 
          'comment' as entity_type, 
          CASE n.type
            WHEN 'video' THEN 'comment_node_article'
            WHEN 'announcement' THEN 'comment_node_event'
            ELSE CONCAT('comment_node_', n.type)
          END as bundle, 
          0 as deleted, c.cid as entity_id, 
          c.cid as revision_id, 
          'und' as language, 
          0 as delta, 
          c.comment as comment_body_value, 
          'comment' as comment_body_format 
        FROM {comments} c 
        LEFT JOIN {node} n ON (c.nid = n.nid)",
    ),
    
    // comment body revision table
    'comments_3' => array(
      'new_name' => 'field_revision_comment_body',
      'select_query' => "SELECT 
          'comment' as entity_type, 
          CASE n.type
            WHEN 'video' THEN 'comment_node_article'
            WHEN 'announcement' THEN 'comment_node_event'
            ELSE CONCAT('comment_node_', n.type)
          END as bundle, 
          0 as deleted, 
          c.cid as entity_id, 
          c.cid as revision_id, 
          'und' as language, 
          0 as delta, 
          c.comment as comment_body_value, 
          'comment' as comment_body_format 
        FROM {comments} c 
        LEFT JOIN {node} n ON (c.nid = n.nid)",
    ),
    
    'contact' => array(
      'new_name' => 'contact',
      'select_query' => 'SELECT * FROM {contact}',
    ),
    
    // merged into general image field
    'content_field_classifieds_image' => array(
      'new_name' => 'field_data_field_image',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, f.delta, f.field_classifieds_image_fid as field_image_fid 
        FROM {content_field_classifieds_image} f
        LEFT JOIN {node} n ON (f.nid = n.nid)
        WHERE f.field_classifieds_image_fid IS NOT NULL
        AND f.vid = n.vid",
    ),
    
    // classified image field revisions
    'content_field_classifieds_image_2' => array(
      'new_name' => 'field_revision_field_image',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, f.delta, f.field_classifieds_image_fid as field_image_fid 
        FROM {content_field_classifieds_image} f
        WHERE field_classifieds_image_fid IS NOT NULL",
    ),
    
    // image field
    'content_field_node_image' => array(
      'new_name' => 'field_data_field_image',
      'select_query' => "SELECT 
          'node' as entity_type, 
          CASE n.type
            WHEN 'video' THEN 'article'
            WHEN 'announcement' THEN 'event'
            WHEN 'tabcontentpage' THEN 'section_page'
            ELSE n.type
          END as bundle, 
          f.nid as entity_id, 
          n.vid as revision_id, 
          'und' as language, 
          f.delta, 
          f.field_node_image_fid as field_image_fid 
        FROM {content_field_node_image} f 
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_image_fid IS NOT NULL
        AND n.vid = f.vid",
    ),
    
    // image field revisions
    'content_field_node_image_2' => array(
      'new_name' => 'field_revision_field_image',
      'select_query' => "SELECT 
          'node' as entity_type, 
          CASE n.type
            WHEN 'video' THEN 'article'
            WHEN 'announcement' THEN 'event'
            WHEN 'tabcontentpage' THEN 'section_page'
            ELSE n.type
          END as bundle, 
          f.nid as entity_id, 
          f.vid as revision_id, 
          'und' as language, 
          f.delta, 
          f.field_node_image_fid as field_image_fid 
        FROM {content_field_node_image} f
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_image_fid IS NOT NULL",
    ),
    
    // wiki images merged into general image field
    'content_field_wiki_image' => array(
      'new_name' => 'field_data_field_image',
      'select_query' => "SELECT 'node' as entity_type, 'wiki' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, FLOOR((RAND() * 100000000)) as delta, f.field_wiki_image_fid as field_image_fid 
        FROM {content_field_wiki_image} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE field_wiki_image_fid IS NOT NULL
        AND n.vid = f.vid",
    ),
    
    // wiki images revisions
    'content_field_wiki_image_2' => array(
      'new_name' => 'field_revision_field_image',
      'select_query' => "SELECT 'node' as entity_type, 'wiki' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, FLOOR((RAND() * 100000000)) as delta, f.field_wiki_image_fid as field_image_fid 
        FROM {content_field_wiki_image} f
        WHERE f.field_wiki_image_fid IS NOT NULL",
    ),
    
    // video images merged into general image field
    'content_field_node_thumbnail' => array(
      'new_name' => 'field_data_field_image',
      'select_query' => "SELECT 'node' as entity_type, 'article' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, FLOOR((RAND() * 100000000)) as delta, f.field_node_thumbnail_fid as field_image_fid 
        FROM {content_field_node_thumbnail} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE field_node_thumbnail_fid IS NOT NULL
        AND n.type != 'audio'
        AND n.vid = f.vid",
    ),
    
    // video images revisions
    'content_field_node_thumbnail_2' => array(
      'new_name' => 'field_revision_field_image',
      'select_query' => "SELECT 'node' as entity_type, 'article' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, FLOOR((RAND() * 100000000)) as delta, f.field_node_thumbnail_fid as field_image_fid 
        FROM {content_field_node_thumbnail} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE f.field_node_thumbnail_fid IS NOT NULL
        AND n.type != 'audio'",
    ),
    
    // date field
    'content_field_event_date_time' => array(
      'new_name' => 'field_data_field_date',
      'select_query' => "SELECT 'node' as entity_type, 'event' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, UNIX_TIMESTAMP(f.field_event_date_time_value) as field_date_value, UNIX_TIMESTAMP(f.field_event_date_time_value2) as field_date_value2 
        FROM {content_field_event_date_time} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // date field revisions
    'content_field_event_date_time_2' => array(
      'new_name' => 'field_revision_field_date',
      'select_query' => "SELECT 'node' as entity_type, 'event' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, UNIX_TIMESTAMP(f.field_event_date_time_value) as field_date_value, UNIX_TIMESTAMP(f.field_event_date_time_value2) as field_date_value2 
        FROM {content_field_event_date_time} f
        WHERE f.field_event_date_time_value IS NOT NULL",
    ),
    
    // text field
    'content_field_event_location' => array(
      'new_name' => 'field_data_field_location',
      'select_query' => "SELECT 'node' as entity_type, 'event' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_event_location_value as field_location_value 
        FROM {content_field_event_location} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // text field revisions
    'content_field_event_location_2' => array(
      'new_name' => 'field_revision_field_location',
      'select_query' => "SELECT 'node' as entity_type, 'event' as bundle, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_event_location_value as field_location_value 
        FROM {content_field_event_location} f
        WHERE f.field_event_location_value IS NOT NULL",
    ),
    
    // long text field
    'content_field_node_additional_info' => array(
      'new_name' => 'field_data_field_additional_info',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_node_additional_info_value as field_additional_info_value, 'full_html' as field_additional_info_format 
        FROM {content_field_node_additional_info} f 
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_additional_info_value IS NOT NULL
        AND f.vid = n.vid",
    ),
    
    // long text revisions
    'content_field_node_additional_info_2' => array(
      'new_name' => 'field_revision_field_additional_info',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_node_additional_info_value as field_additional_info_value, 'full_html' as field_additional_info_format 
        FROM {content_field_node_additional_info} f
        LEFT JOIN {node} n ON (n.nid = f.nid) 
        WHERE f.field_node_additional_info_value IS NOT NULL",
    ),
    
    // term reference (classified category)
    'field_data_field_classified_category' => array(
      'new_name' => 'field_data_field_classified_category',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, n.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_classified_category_tid 
        FROM {term_node} t 
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 17
        AND n.vid = t.vid",
    ),
    
    // term reference (classified category) revisions
    'field_revision_field_classified_category' => array(
      'new_name' => 'field_revision_field_classified_category',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, t.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_classified_category_tid 
        FROM {term_node} t
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 17",
    ),
    
    // term reference (classified location)
    'field_data_field_classified_location' => array(
      'new_name' => 'field_data_field_classified_location',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, n.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_classified_location_tid 
        FROM {term_node} t 
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 18
        AND n.vid = t.vid",
    ),
    
    // term reference (classified location) revisions
    'field_revision_field_classified_location' => array(
      'new_name' => 'field_revision_field_classified_location',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, t.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_classified_location_tid 
        FROM {term_node} t
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 18",
    ),
    
    // term reference (ecard category)
    'field_data_field_ecard_category' => array(
      'new_name' => 'field_data_field_ecard_category',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, n.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_ecard_category_tid 
        FROM {term_node} t 
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 15
        AND n.vid = t.vid",
    ),
    
    // term reference (ecard category) revisions
    'field_revision_field_ecard_category' => array(
      'new_name' => 'field_revision_field_ecard_category',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, t.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_ecard_category_tid 
        FROM {term_node} t
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 15",
    ),
    
    // term reference (wiki category)
    'field_data_field_wiki_categories' => array(
      'new_name' => 'field_data_field_wiki_categories',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, n.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_wiki_categories_tid 
        FROM {term_node} t 
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 7
        AND n.vid = t.vid",
    ),
    
    // term reference (wiki category) revisions
    'field_revision_field_wiki_categories' => array(
      'new_name' => 'field_revision_field_wiki_categories',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, t.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_wiki_categories_tid 
        FROM {term_node} t
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 7",
    ),
    
    // term reference (tags)
    'field_data_field_tags' => array(
      'new_name' => 'field_data_field_tags',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, n.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_tags_tid 
        FROM {term_node} t 
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid IN (2,11,13,6,4,12,8,9,10,14)
        AND n.vid = t.vid",
    ),
    
    // term reference (tags) revisions
    'field_revision_field_tags' => array(
      'new_name' => 'field_revision_field_tags',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, t.vid as revision_id, 'und' as language, t.tid as delta, t.tid as field_tags_tid 
        FROM {term_node} t
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid IN (2,11,13,6,4,12,8,9,10,14)",
    ),
    
    // file field 
    'content_field_node_file' => array(
      'new_name' => 'field_data_field_file',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, delta, f.field_node_file_fid as field_file_fid, 1 as field_file_display 
        FROM {content_field_node_file} f 
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_file_fid IS NOT NULL
        AND n.type NOT IN ('audio', 'files', 'panel')
        AND n.vid = f.vid",
    ),
    
    // file field revisions
    'content_field_node_file_2' => array(
      'new_name' => 'field_revision_field_file',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, delta, f.field_node_file_fid as field_file_fid, 1 as field_file_display 
        FROM {content_field_node_file} f
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_file_fid IS NOT NULL
        AND n.type NOT IN ('audio', 'files', 'panel')",
    ),
    
    // link field
    'content_field_node_link' => array(
      'new_name' => 'field_data_field_related_links',
      'select_query' => "SELECT 
          'node' as entity_type,
          CASE n.type
            WHEN 'announcement' THEN 'event'
            ELSE n.type
          END as bundle, 
          0 as deleted, 
          f.nid as entity_id, 
          f.vid as revision_id, 
          'und' as language, 
          delta, 
          f.field_node_link_url as field_related_links_url, 
          f.field_node_link_title as field_related_links_title, 
          'a:0:{}' as field_related_links_attributes 
        FROM {content_field_node_link} f 
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_link_url IS NOT NULL
        AND n.vid = f.vid",
    ),
    
    // link field revisions
    'content_field_node_link_2' => array(
      'new_name' => 'field_revision_field_related_links',
      'select_query' => "SELECT 
          'node' as entity_type, 
          CASE n.type
            WHEN 'announcement' THEN 'event'
            ELSE n.type
          END as bundle, 
          0 as deleted, 
          f.nid as entity_id, 
          f.vid as revision_id, 
          'und' as language, 
          delta, 
          f.field_node_link_url as field_related_links_url, 
          f.field_node_link_title as field_related_links_title, 
          'a:0:{}' as field_related_links_attributes 
        FROM {content_field_node_link} f
        LEFT JOIN {node} n ON (f.nid = n.nid) 
        WHERE f.field_node_link_url IS NOT NULL",
    ),
    
    // wiki file field
    'content_field_wiki_file' => array(
      'new_name' => 'field_data_field_file',
      'select_query' => "SELECT 'node' as entity_type, 'wiki' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, delta+20 as delta, f.field_wiki_file_fid as field_file_fid, 1 as field_file_display 
        FROM {content_field_wiki_file} f 
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE f.field_wiki_file_fid IS NOT NULL
        AND n.vid = f.vid",
    ),
    
    // wiki file field revisions
    'content_field_wiki_file_2' => array(
      'new_name' => 'field_revision_field_file',
      'select_query' => "SELECT 'node' as entity_type, 'wiki' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, delta+20 as delta, f.field_wiki_file_fid as field_file_fid, 1 as field_file_display 
        FROM {content_field_wiki_file} f
        WHERE f.field_wiki_file_fid IS NOT NULL",
    ),
    
    // event type
    'field_data_field_event_type' => array(
      'new_name' => 'field_data_field_event_type',
      'select_query' => "SELECT 
          'node' as entity_type, 
          'event' as bundle, 
          0 as deleted, 
          f.nid as entity_id, 
          f.vid as revision_id, 
          'und' as language, 
          0 as delta, 
          CASE f.field_event_type_value
            WHEN NULL THEN 0
            ELSE f.field_event_type_value
          END as field_event_type_value
        FROM {content_type_event} f 
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // event type revisions
    'field_revision_field_event_type' => array(
      'new_name' => 'field_revision_field_event_type',
      'select_query' => "SELECT 
          'node' as entity_type, 
          'event' as bundle, 
          0 as deleted, 
          f.nid as entity_id, 
          r.vid as revision_id, 
          'und' as language, 
          0 as delta, 
          CASE f.field_event_type_value
            WHEN NULL THEN 0
            ELSE f.field_event_type_value
          END as field_event_type_value
        FROM {node_revisions} r
        LEFT JOIN {content_type_event} f ON (f.vid = r.vid)
        WHERE f.nid IS NOT NULL",
    ),
    
    // event type (announcements)
    'field_data_field_event_type_2' => array(
      'new_name' => 'field_data_field_event_type',
      'select_query' => "SELECT 
          'node' as entity_type, 
          'event' as bundle, 
          0 as deleted, 
          f.nid as entity_id, 
          f.vid as revision_id, 
          'und' as language, 
          0 as delta, 
          1 as field_event_type_value
        FROM {content_type_announcement} f 
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // event type (announcements) revisions
    'field_revision_field_event_type_2' => array(
      'new_name' => 'field_revision_field_event_type',
      'select_query' => "SELECT 
          'node' as entity_type, 
          'event' as bundle, 
          0 as deleted, 
          f.nid as entity_id, 
          f.vid as revision_id, 
          'und' as language, 
          0 as delta, 
          1 as field_event_type_value
        FROM {node_revisions} r
        LEFT JOIN {content_type_announcement} f ON (f.vid = r.vid)
        WHERE f.nid IS NOT NULL",
    ),
    
    // decimal field
    'content_type_ed_classified' => array(
      'new_name' => 'field_data_field_price',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_price_value as field_price_value 
        FROM {content_type_ed_classified} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // decimal field revisions
    'content_type_ed_classified_1' => array(
      'new_name' => 'field_revision_field_price',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_price_value as field_price_value 
        FROM {node_revisions} r
        LEFT JOIN {content_type_ed_classified} f ON (f.vid = r.vid)
        WHERE f.field_classifieds_price_value IS NOT NULL",
    ),
    
    // text field
    'content_type_ed_classified_2' => array(
      'new_name' => 'field_data_field_phone',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_phone_value as field_phone_value 
        FROM {content_type_ed_classified} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE field_classifieds_phone_value IS NOT NULL
        AND n.vid = f.vid",
    ),
    
    // text field revisions
    'content_type_ed_classified_3' => array(
      'new_name' => 'field_revision_field_phone',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_phone_value as field_phone_value 
        FROM {node_revisions} r
        LEFT JOIN {content_type_ed_classified} f ON (f.vid = r.vid)
        WHERE f.field_classifieds_phone_value IS NOT NULL",
    ),
    
    // text field
    'content_type_ed_classified_4' => array(
      'new_name' => 'field_data_field_contact_name',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_contact_value as field_contact_name_value 
        FROM {content_type_ed_classified} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE field_classifieds_contact_value IS NOT NULL
        AND n.vid = f.vid",
    ),
    
    // text field revisions
    'content_type_ed_classified_5' => array(
      'new_name' => 'field_revision_field_contact_name',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_contact_value as field_contact_name_value 
        FROM {node_revisions} r
        LEFT JOIN {content_type_ed_classified} f ON (f.vid = r.vid)
        WHERE f.field_classifieds_contact_value IS NOT NULL",
    ),
    
    // integer field
    'content_type_ed_classified_6' => array(
      'new_name' => 'field_data_field_terms_of_use',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, 1 as field_terms_of_use_value 
        FROM {content_type_ed_classified} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // integer field revisions
    'content_type_ed_classified_7' => array(
      'new_name' => 'field_revision_field_terms_of_use',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, 1 as field_terms_of_use_value 
        FROM {node_revisions} r
        LEFT JOIN {content_type_ed_classified} f ON (f.vid = r.vid)
        WHERE f.nid IS NOT NULL",
    ),
    
    // text to integer field
    'content_type_ed_classified_8' => array(
      'new_name' => 'field_data_field_obo',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta,
        CASE f.field_classifieds_obo_value
          WHEN 'Firm' THEN 0
          ELSE 1
        END as field_obo_value
        FROM {content_type_ed_classified} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // text to integer field revisions
    'content_type_ed_classified_9' => array(
      'new_name' => 'field_revision_field_obo',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta,
        CASE f.field_classifieds_obo_value
          WHEN 'Firm' THEN 0
          ELSE 1
        END as field_obo_value
        FROM {node_revisions} r
        LEFT JOIN {content_type_ed_classified} f ON (f.vid = r.vid)
        WHERE f.nid IS NOT NULL",
    ),
    
    // integer field
    'content_type_ed_classified_10' => array(
      'new_name' => 'field_data_field_email',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_email_email as field_email_email 
        FROM {content_type_ed_classified} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // integer field revisions
    'content_type_ed_classified_11' => array(
      'new_name' => 'field_revision_field_email',
      'select_query' => "SELECT 'node' as entity_type, 'classified' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, f.field_classifieds_email_email as field_email_email
        FROM {node_revisions} r
        LEFT JOIN {content_type_ed_classified} f ON (f.vid = r.vid)
        WHERE f.nid IS NOT NULL",
    ),
    
//    // integer field
//    'content_type_event' => array(
//      'new_name' => 'field_data_field_event_type',
//      'select_query' => "SELECT 'node' as entity_type, 'event' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, f.field_event_type_value as field_event_type_value 
//        FROM {content_type_event} f
//        LEFT JOIN {node} n ON (n.nid = f.nid)
//        WHERE n.vid = f.vid",
//    ),
//    
//    // integer field revisions
//    'content_type_event' => array(
//      'new_name' => 'field_revision_field_event_type',
//      'select_query' => "SELECT 'node' as entity_type, 'event' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, f.field_event_type_value as field_event_type_value 
//        FROM {node_revisions} r
//        LEFT JOIN {content_type_event} f ON (f.vid = r.vid)
//        WHERE f.field_event_type_value IS NOT NULL",
//    ),
    
    // ecard field
    'content_type_ecard' => array(
      'new_name' => 'field_data_field_e_card',
      'select_query' => "SELECT 'node' as entity_type, 'ecard' as bundle, 0 as deleted, f.nid as entity_id, f.vid as revision_id, 'und' as language, 0 as delta, 'ecard-message' as field_e_card_class, 300 as field_e_card_width, 12 as field_e_card_font_size 
        FROM {content_type_ecard} f
        LEFT JOIN {node} n ON (n.nid = f.nid)
        WHERE n.vid = f.vid",
    ),
    
    // ecard field revisions
    'content_type_ecard' => array(
      'new_name' => 'field_revision_field_e_card',
      'select_query' => "SELECT 'node' as entity_type, 'ecard' as bundle, 0 as deleted, f.nid as entity_id, r.vid as revision_id, 'und' as language, 0 as delta, 'ecard-message' as field_e_card_class, 300 as field_e_card_width, 12 as field_e_card_font_size 
        FROM {node_revisions} r
        LEFT JOIN {content_type_ecard} f ON (f.vid = r.vid)
        WHERE f.nid IS NOT NULL",
    ),
    
    // term reference (wiki category)
    'field_data_taxonomy_forums' => array(
      'new_name' => 'field_data_taxonomy_forums',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, n.vid as revision_id, 'und' as language, t.tid as delta, t.tid as taxonomy_forums_tid 
        FROM {term_node} t 
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 1
        AND n.vid = t.vid",
    ),
    
    // term reference (wiki category) revisions
    'field_revision_taxonomy_forums' => array(
      'new_name' => 'field_revision_taxonomy_forums',
      'select_query' => "SELECT 'node' as entity_type, n.type as bundle, 0 as deleted, t.nid as entity_id, t.vid as revision_id, 'und' as language, t.tid as delta, t.tid as taxonomy_forums_tid 
        FROM {term_node} t
        LEFT JOIN {node} n ON (t.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 1",
    ),
    
    // weird forum_index table
    'forum_index' => array(
      'new_name' => 'forum_index',
      'select_query' => "SELECT 
        t.nid,
        n.title,
        t.tid,
        0 as sticky,
        n.created,
        (SELECT c.timestamp FROM {comments} c WHERE c.nid = t.nid ORDER BY timestamp DESC LIMIT 1) as last_comment_timestamp,
        (SELECT COUNT(cid) FROM {comments} c2 WHERE c2.nid = t.nid) as comment_count
        FROM {node} n
        LEFT JOIN {term_node} t ON (t.nid = n.nid)
        LEFT JOIN {comments} c ON (c.nid = n.nid)
        LEFT JOIN {term_data} v ON (t.tid = v.tid)
        WHERE v.vid = 1
        AND n.status = 1
        AND t.vid = n.vid
        AND c.cid IS NOT NULL
        GROUP BY n.nid",
    ),
    
    'ecard' => array(
      'new_name' => 'ecard',
      'select_query' => "SELECT e.random as hash, 'node' as entity_type, 'ecard' as bundle, e.nid as entity_id, u.uid, e.sender_email as mail_from, e.sender_name as name_from, e.recp_mail as mail_to, e.recp_mail as name_to, e.message as text, 0 as pick_up, send_time as timestamp 
        FROM {ecard} e 
        LEFT JOIN {users} u ON (e.sender_email = u.mail)
        WHERE u.uid IS NOT NULL
        GROUP BY e.random",
    ),
    
    'files' => array(
      'new_name' => 'file_managed',
      'select_query' => "SELECT fid, uid, filename, REPLACE(filepath, 'sites/default/files', 'public:/') as uri, filemime, filesize, status, timestamp, filename as origname 
        FROM {files}",
    ),
    
    // file to node relationship, screw it just use node 256
    'files_2' => array(
      'new_name' => 'file_usage',
      'select_query' => "SELECT fid, 'file' as module, 'node' as type, 256 as id, 1 as count FROM {files}",
    ),
    
    'forum' => array(
      'new_name' => 'forum',
      'select_query' => "SELECT * FROM {forum}",
    ),
    
    'node' => array(
      'new_name' => 'node',
      'select_query' => "SELECT 
          nid, 
          vid, 
          CASE type
            WHEN 'announcement' THEN 'event'
            WHEN 'video' THEN 'article'
            WHEN 'ed_classified' THEN 'classified'
            WHEN 'atworkpoll' THEN 'poll'
            WHEN 'sectionhomepage' THEN 'page'
            WHEN 'tabcontentpage' THEN 'section_page'
            ELSE type
          END as type,
          'und' as language, 
          title, 
          uid, 
          status, 
          created, 
          changed, 
          comment, 
          promote, 
          sticky, 
          tnid, 
          translate 
        FROM {node} 
        WHERE type NOT IN ('audio', 'files', 'panel')",
    ),
    
    'node_comment_statistics' => array(
      'new_name' => 'node_comment_statistics',
      'select_query' => "SELECT 
          s.nid, 
          IFNULL((SELECT c.cid FROM atwork_comments c WHERE s.nid = c.nid ORDER BY c.cid DESC LIMIT 1), 0) as cid, 
          s.last_comment_timestamp, 
          s.last_comment_name, 
          s.last_comment_uid, 
          s.comment_count 
        FROM {node_comment_statistics} s",
    ),
    
    'node_counter' => array(
      'new_name' => 'node_counter',
      'select_query' => "SELECT * FROM {node_counter}",
    ),
    
    'node_revisions' => array(
      'new_name' => 'node_revision',
      'select_query' => "SELECT r.nid, r.vid, r.uid, r.title, r.log, r.timestamp, n.status, n.comment, n.promote, n.sticky FROM {node_revisions} r LEFT JOIN {node} n ON (n.nid = r.nid)",
    ),
    
    'field_data_body' => array(
      'new_name' => 'field_data_body',
      'select_query' => "SELECT 
          'node' as entity_type, 
          n.type as bundle, 
          0 as deleted, 
          r.nid as entity_id, 
          r.vid as revision_id, 
          'und' as language, 
          0 as delta,
          r.body as body_value, 
          r.teaser as body_summary,
          CASE r.format
            WHEN 1 THEN 'filtered_html'
            WHEN 2 THEN 'full_html'
            WHEN 3 THEN 'php_code'
            ELSE 'full_html'
          END as body_format
        FROM {node} n 
        LEFT JOIN {node_revisions} r ON (n.vid = r.vid)",
    ),
    
    'field_data_body_2' => array(
      'new_name' => 'field_revision_body',
      'select_query' => "SELECT 
          'node' as entity_type, 
          n.type as bundle, 
          0 as deleted, 
          r.nid as entity_id, 
          r.vid as revision_id, 
          'und' as language, 
          0 as delta,
          r.body as body_value, 
          r.teaser as body_summary,
          CASE r.format
            WHEN 1 THEN 'filtered_html'
            WHEN 2 THEN 'full_html'
            WHEN 3 THEN 'php_code'
            ELSE 'full_html'
          END as body_format
        FROM {node_revisions} r 
        LEFT JOIN {node} n ON (n.nid = r.nid)",
    ),
    
    'profile_values' => array(
      'new_name' => 'field_data_field_display_name',
      'select_query' => "SELECT 'user' as entity_type, 'user' as bundle, 0 as deleted, uid as entity_id, uid as revision_id, 'und' as language, 0 as delta, value as field_display_name_value FROM {profile_values} WHERE fid = 1",
    ),
    
    'quiz_multichoice_answers' => array(
      'new_name' => 'quiz_multichoice_answers',
      'select_query' => "SELECT * FROM {quiz_multichoice_answers}",
    ),
    
    'quiz_multichoice_properties' => array(
      'new_name' => 'quiz_multichoice_properties',
      'select_query' => "SELECT * FROM {quiz_multichoice_properties}",
    ),
    
    'quiz_multichoice_user_answers' => array(
      'new_name' => 'quiz_multichoice_user_answers',
      'select_query' => "SELECT * FROM {quiz_multichoice_user_answers}",
    ),
    
    'quiz_multichoice_user_answer_multi' => array(
      'new_name' => 'quiz_multichoice_user_answer_multi',
      'select_query' => "SELECT * FROM {quiz_multichoice_user_answer_multi}",
    ),
    
    'quiz_node_properties' => array(
      'new_name' => 'quiz_node_properties',
      'select_query' => "SELECT
          vid,
          nid,
          aid,
          number_of_random_questions,
          max_score_for_random,
          pass_rate,
          summary_pass,
          'plain_text' as summary_pass_format,
          summary_default,
          'plain_text' as summary_default_format,
          randomization,
          backwards_navigation,
          keep_results,
          repeat_until_correct,
          feedback_time,
          display_feedback,
          quiz_open,
          quiz_close,
          takes,
          show_attempt_stats,
          time_limit,
          quiz_always,
          tid,
          has_userpoints,
          time_left,
          max_score,
          allow_skipping,
          allow_resume,
          allow_jumping,
          1 as show_passed
        FROM {quiz_node_properties}",
    ),
    
    'quiz_node_relationship' => array(
      'new_name' => 'quiz_node_relationship',
      'select_query' => "SELECT * FROM {quiz_node_relationship}",
    ),
    
    'quiz_node_results' => array(
      'new_name' => 'quiz_node_results',
      'select_query' => "SELECT * FROM {quiz_node_results}",
    ),
    
    'quiz_node_results_answers' => array(
      'new_name' => 'quiz_node_results_answers',
      'select_query' => "SELECT * FROM {quiz_node_results_answers}",
    ),
    
    'quiz_node_result_options' => array(
      'new_name' => 'quiz_node_result_options',
      'select_query' => "SELECT
          option_id,
          nid,
          vid,
          option_name,
          option_summary,
          'plain_text' as option_summary_format,
          option_start,
          option_end
        FROM {quiz_node_result_options}",
    ),
    
    'quiz_question_properties' => array(
      'new_name' => 'quiz_question_properties',
      'select_query' => "SELECT * FROM {quiz_question_properties}",
    ),
    
    'quiz_truefalse_node' => array(
      'new_name' => 'quiz_truefalse_node',
      'select_query' => "SELECT * FROM {quiz_truefalse_node}",
    ),
    
    'quiz_truefalse_user_answers' => array(
      'new_name' => 'quiz_truefalse_user_answers',
      'select_query' => "SELECT * FROM {quiz_truefalse_user_answers}",
    ),
    
    'term_data' => array(
      'new_name' => 'taxonomy_term_data',
      'select_query' => "SELECT 
        tid,
        CASE vid
          WHEN 2 THEN 6
          WHEN 11 THEN 6
          WHEN 13 THEN 6
          WHEN 6 THEN 6
          WHEN 4 THEN 6
          WHEN 12 THEN 6
          WHEN 8 THEN 6
          WHEN 9 THEN 6
          WHEN 10 THEN 6
          WHEN 14 THEN 6
          WHEN 19 THEN 6
          WHEN 7 THEN 4
          WHEN 1 THEN 7
          WHEN 17 THEN 2
          WHEN 18 THEN 3
          WHEN 15 THEN 5
          ELSE vid
        END as vid,
        name,
        description,
        'full_html' as format,
        weight
        FROM {term_data}
        WHERE vid NOT IN (5,16)",
    ),
    
    'term_hierarchy' => array(
      'new_name' => 'taxonomy_term_hierarchy',
      'select_query' => "SELECT
        h.tid,
        CASE d.vid
          WHEN 2 THEN 493
          WHEN 11 THEN 494
          WHEN 13 THEN 495
          WHEN 6 THEN 496
          WHEN 4 THEN 497
          WHEN 12 THEN 498
          WHEN 8 THEN 499
          WHEN 9 THEN 500
          WHEN 10 THEN 501
          WHEN 14 THEN 502
          ELSE h.parent
        END as parent
        FROM {term_hierarchy} h
        LEFT JOIN {term_data} d ON (h.tid = d.tid)
        WHERE d.vid NOT IN (5,16)",
    ),
    
    'term_node' => array(
      'new_name' => 'taxonomy_index',
      'select_query' => "SELECT t.nid, t.tid, 0 as sticky, n.created FROM {term_node} t LEFT JOIN {node} n ON (t.nid = n.nid) WHERE n.status = 1",
    ),
    
    'url_alias' => array(
      'new_name' => 'url_alias',
      'select_query' => "SELECT pid, src as source, dst as alias, 'und' as language FROM {url_alias}",
    ),
    
    'users' => array(
      'new_name' => 'users',
      'select_query' => "SELECT 
        uid,
        name,
        pass,
        mail,
        'filtered_html' as signature_format,
        created,
        access,
        login,
        status,
        init
        FROM {users}
        WHERE uid > 1",
    ),
    
    'users_roles' => array(
      'new_name' => 'users_roles',
      'select_query' => "SELECT
        uid,
        CASE rid
          WHEN 3 THEN 3
          WHEN 12 THEN 5
          WHEN 10 THEN 6
          WHEN 7 THEN 4
          WHEN 14 THEN 7
          WHEN 15 THEN 8
          WHEN 16 THEN 9
          WHEN 17 THEN 10
        END as rid
        FROM {users_roles}
        WHERE rid NOT IN (4,6,5,9,11,8)",
    ),
    
    'votingapi_cache' => array(
      'new_name' => 'votingapi_cache',
      'select_query' => "SELECT
        vote_cache_id,
        content_type as entity_type,
        content_id as entity_id,
        value,
        value_type,
        tag,
        function,
        timestamp
        FROM {votingapi_cache}",
    ),
    
    'votingapi_vote' => array(
      'new_name' => 'votingapi_vote',
      'select_query' => "SELECT
        vote_id,
        content_type as entity_type,
        content_id as entity_id,
        value,
        value_type,
        tag,
        uid,
        timestamp,
        vote_source
        FROM {votingapi_vote}",
    ),
    
    'webform' => array(
      'new_name' => 'webform',
      'select_query' => "SELECT
        nid,
        confirmation,
        'full_html' as confirmation_format,
        '<confirmation>' as redirect_url,
        1 as status,
        0 as block,
        teaser,
        0 as allow_draft,
        0 as auto_save,
        1 as submit_notice,
        submit_text,
        submit_limit,
        submit_interval,
        -1 as total_submit_limit,
        -1 as total_submit_interval
        FROM {webform}",
    ),
    
    'webform_component' => array(
      'new_name' => 'webform_component',
      'select_query' => "SELECT
        nid,
        cid,
        pid,
        form_key,
        name,
        type,
        value,
        extra,
        mandatory,
        weight
        FROM {webform_component}",
    ),
    
    'webform_roles' => array(
      'new_name' => 'webform_roles',
      'select_query' => "SELECT
        nid,
        CASE rid
          WHEN 14 THEN 7
          WHEN 15 THEN 8
          ELSE rid
        END as rid
        FROM {webform_roles}
        WHERE rid NOT IN (4,6,5,9,11)",
    ),
    
    'webform_submissions' => array(
      'new_name' => 'webform_submissions',
      'select_query' => "SELECT
        sid,
        nid,
        uid,
        0 as is_draft,
        submitted,
        remote_addr
        FROM {webform_submissions}",
    ),
    
    'webform_submitted_data' => array(
      'new_name' => 'webform_submitted_data',
      'select_query' => "SELECT * FROM {webform_submitted_data}",
    ),
    
    'forward_log' => array(
      'new_name' => 'forward_log',
      'select_query' => "SELECT path, type, timestamp, '1' as uid, '142.36.131.110' as hostname FROM {forward_log}",
    ),
    
    'forward_statistics' => array(
      'new_name' => 'forward_statistics',
      'select_query' => "SELECT * FROM {forward_statistics}",
    ),
    
    // subscriptions without author
    'subscriptions' => array(
      'new_name' => 'subscriptions',
      'select_query' => "SELECT
        n.sid,
        'node' as module,
        CASE n.type
          WHEN 'thread' THEN 'nid'
          WHEN 'nodetype' THEN 'type'
          WHEN 'taxonomy' THEN 'tid'
          ELSE n.type
        END as field,
        f.value as value,
        n.uid as recipient_uid,
        CASE n.send_interval
          WHEN 0 THEN -1
          ELSE n.send_interval
        END as send_interval,
        -1 as author_uid,
        1 as send_updates,
        1 as send_comments
        FROM {notifications} n
        LEFT JOIN {notifications_fields} f ON (n.sid = f.sid)
        WHERE n.type != 'author'",
    ),
    
    // now subscriptions with author
    'subscriptions_2' => array(
      'new_name' => 'subscriptions',
      'select_query' => "SELECT
        n.sid,
        'node' as module,
        'type' as field,
        'blog' as value,
        n.uid as recipient_uid,
        CASE n.send_interval
          WHEN 0 THEN -1
          ELSE n.send_interval
        END as send_interval,
        f.value as author_uid,
        1 as send_updates,
        1 as send_comments
        FROM {notifications} n
        LEFT JOIN {notifications_fields} f ON (n.sid = f.sid)
        WHERE n.type = 'author'",
    ),
    
    // now subscriptions user table
    'subscriptions_user' => array(
      'new_name' => 'subscriptions_user',
      'select_query' => "SELECT
        uid
        FROM {notifications}
        GROUP BY uid",
    ),
    
  );
  return $tables;
}

function atwork_migrate_image_fixes(&$context) {
  _atwork_migrate_d6_database();
  
  $data = array();
  
  $result = db_query("SELECT 
                        field_classifieds_image_fid as fid, 
                        field_classifieds_image_data as data
                      FROM {content_field_classifieds_image} 
                      WHERE field_classifieds_image_data IS NOT NULL GROUP BY field_classifieds_image_fid");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  $result = db_query("SELECT 
                        field_node_image_fid as fid, 
                        field_node_image_data as data
                      FROM {content_field_node_image} 
                      WHERE field_node_image_data IS NOT NULL GROUP BY field_node_image_fid");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  $result = db_query("SELECT 
                        field_node_thumbnail_fid as fid, 
                        field_node_thumbnail_data as data
                      FROM {content_field_node_thumbnail} 
                      WHERE field_node_thumbnail_data IS NOT NULL GROUP BY field_node_thumbnail_fid");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  $result = db_query("SELECT 
                        field_wiki_image_fid as fid, 
                        field_wiki_image_data as data
                      FROM {content_field_wiki_image} 
                      WHERE field_wiki_image_data IS NOT NULL GROUP BY field_wiki_image_fid");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  
  
  foreach ($data as $key => $image) {
    $image_data = unserialize($image->data);
    if (!isset($image_data['description'])) $image_data['description'] = '';
    if (!$image_data['description'] && !$image_data['alt'] && !$image_data['title']) {
      // nothing to collect
      unset($data[$key]);
    }
    else {
      if (strlen($image_data['description']) >= strlen($image_data['alt']) && strlen($image_data['description']) >= strlen($image_data['title'])) {
        $data[$key]->title = $image_data['description'];
      }
      if (strlen($image_data['alt']) >= strlen($image_data['description']) && strlen($image_data['alt']) >= strlen($image_data['title'])) {
        $data[$key]->title = $image_data['alt'];
      }
      if (strlen($image_data['title']) >= strlen($image_data['description']) && strlen($image_data['title']) >= strlen($image_data['alt'])) {
        $data[$key]->title = $image_data['title'];
      }
      unset($data[$key]->data);
    }
  }
  
  db_set_active('default');
  
  foreach ($data as $image) {
    db_update('field_data_field_image')
      ->fields(array(
        'field_image_alt' => $image->title,
        'field_image_title' => $image->title,
      ))
      ->condition('field_image_fid', $image->fid)
      ->execute();
  }
  
  $context['results'][] = 'Fixed ' . count($data) . ' images';
  $context['message'] = 'Fixing images';
}

function atwork_migrate_file_fixes(&$context) {
  _atwork_migrate_d6_database();
  
  $data = array();
  
  $result = db_query("SELECT 
                        field_node_file_fid as fid, 
                        field_node_file_data as data
                      FROM {content_field_node_file} 
                      WHERE field_node_file_data IS NOT NULL GROUP BY field_node_file_fid");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  $result = db_query("SELECT 
                        field_wiki_file_fid as fid, 
                        field_wiki_file_data as data
                      FROM {content_field_wiki_file} 
                      WHERE field_wiki_file_data IS NOT NULL GROUP BY field_wiki_file_fid");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  
  
  foreach ($data as $key => $file) {
    $file_data = unserialize($file->data);
    if (!isset($file_data['description'])) $file_data['description'] = '';
    if (!$file_data['description']) {
      // nothing to collect
      unset($data[$key]);
    }
    else {
      $data[$key]->description = $file_data['description'];
      unset($data[$key]->data);
    }
  }
  
  db_set_active('default');
  
  foreach ($data as $file) {
    db_update('field_data_field_file')
      ->fields(array(
        'field_file_description' => $file->description,
      ))
      ->condition('field_file_fid', $file->fid)
      ->execute();
  }
  
  $context['results'][] = 'Fixed ' . count($data) . ' files';
  $context['message'] = 'Fixing images';
}

function atwork_migrate_convert_videos(&$context) {

  _atwork_migrate_d6_database();
  
  $data = array();
  
  $result = db_query("SELECT *
                      FROM {node} n
                      LEFT JOIN {content_field_node_media} f ON (n.nid = f.nid)
                      LEFT JOIN {content_type_video} c ON (c.nid = n.nid)
                      LEFT JOIN {files} files ON (f.field_node_media_fid = files.fid)
                      WHERE n.type = 'video'");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  db_set_active('default');
  
  $num = count($data);
  
  foreach ($data as $video_node) {
    $node = node_load($video_node->nid);
    
    $file = file_load($video_node->fid);
    
    $file->type = 'video';
    $file->field_transcript['und'][0]['value'] = $video_node->field_media_transcript_value;
    $file->field_transcript['und'][0]['safe_value'] = $video_node->field_media_transcript_value;
    file_save($file);
    
    if (!strpos($node->body['und'][0]['value'], '[[{"fid":"' . $file->fid . '","view_mode":"default","type":"media"')) {
      $node->body['und'][0]['value'] .= '<p>[[{"fid":"' . $file->fid . '","view_mode":"default","type":"media","attributes":{"height":404,"width":665,"alt":"' . $video_node->title . '","class":"media-element file-default"}}]]</p>';
      node_save($node);
    }
  }
  
  $context['results'][] = 'Converted ' . count($data) . ' videos';
  $context['message'] = 'Converting videos';
}

function atwork_migrate_convert_inline_videos(&$context) {
  module_load_include('inc', 'media_youtube', 'includes/MediaInternetYouTubeHandler.inc');
  
  _atwork_migrate_d6_database();
  
  $data = array();
  
  $result = db_query("SELECT *
                      FROM {node} n
                      LEFT JOIN {term_node} t ON (t.vid = n.vid)
                      LEFT JOIN {node_revisions} r ON (n.vid = r.vid)
                      WHERE (n.type = 'article' OR n.type = 'blog')
                      AND (
                        r.body LIKE '%youtube%' OR t.tid = 41 OR r.body LIKE '%[swf file=%'
                      )");
  //t.tid = 41 OR r.body LIKE '%[swf file=%'
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  db_set_active('default');
  
  foreach ($data as &$video_node) {
    preg_match_all( '/(?:youtube\.com\/(?:[^\/]+\/[^\/]+\/|(?:v|e(?:mbed)?)\/|[^#]*[?&]v=)|youtu\.be\/)([^"&?\/ ]{11})/i', $video_node->body, $result);
    if (!count($result[0])) {
      // dealing with an swf file
      if (preg_match_all('@(?:<p>)?\[(swflist|swf)\s*(.*?)\](?:</p>)?@s', $video_node->body, $match)) {
        foreach ($match[2] as $key => $passed_parameters) {
          preg_match_all('/(\w*)=(?:\"|&quot;)(.*?)(?:\"|&quot;)/', $passed_parameters, $file_result);
          if (isset($file_result[2][0])) {
            // some paths are absolute :(
            $path = str_replace('https://gww.gov.bc.ca/sites/default/files/', '', $file_result[2][0]);
            $path = str_replace('/sites/default/files/', '', $path);
            $path = str_replace('sites/default/files/', '', $path);
            $filename = basename($path);
            
            $file = db_query("SELECT fid FROM {file_managed} WHERE origname = :filename", array(':filename' => $filename))->fetch();
            if (!isset($file->fid)) {
              // file hasn't been added yet
              $file = new stdClass();
              $file->uid = 1;
              $file->filename = $filename;
              $file->uri = 'public://' . $path;
              $file->status = 1;
              $file->type = 'video';
            }
            else {
              // resave anyway
              $file = file_load($file->fid);
            }
            if (file_exists($file->uri)) {
              file_save($file);
            }
            else {
              dpm('Could not find: ' . $file->uri);
            }
            
            $replacement = '<p>[[{"fid":"' . $file->fid . '","view_mode":"default","type":"media","attributes":{"height":404,"width":665,"alt":"video","class":"media-element file-default"}}]]</p>';
            $video_node->body = str_replace($match[0][$key], $replacement, $video_node->body);
            
          }
        }
      }
    }
    else {
      // dealing with a youtube video
      // find objects and iframes
      preg_match_all('#\<(object|iframe)(.+?)\<\/(object|iframe)\>#s' , $video_node->body, $object_results);
      if (isset($object_results[0][0])) {
        foreach ($object_results[0] as $match) {
          preg_match_all( '/(?:youtube\.com\/(?:[^\/]+\/[^\/]+\/|(?:v|e(?:mbed)?)\/|[^#]*[?&]v=)|youtu\.be\/)([^"&?\/ ]{11})/i', $match, $youtube_results);
          if (isset($youtube_results[1][0])) {
//            $file = new stdClass();
//            $file->uid = 1;
//            $file->filename = $video_node->title;
//            $file->uri = 'youtube://v/' . $youtube_results[1][0];
//            $file->filemime = 'video/youtube';
//            $file->filesize = 0;
//            $file->status = 1;
//            $file->type = 'video';
//            
//            $fid_result = db_query("SELECT fid FROM {file_managed} WHERE uri = :uri", array(':uri' => $file->uri))->fetch();
//            
//            if (isset($fid_result->fid)) {
//              $fid = $fid_result->fid;
//              dpm($fid_result->fid . ' exists...');
//            }
//            else {
//              file_save($file);
//              $fid = $file->fid;
//              dpm('saved ' . $fid . '...');
//            }
            
            if ($obj = new MediaInternetYouTubeHandler('http://www.youtube.com/watch?v=' . $youtube_results[1][0])) {
              $file = $obj->getFileObject();
              $file->display = 1;
              $file->type = 'video';
              if ($file->uri) {
                //dpm($file);
                file_save($file);
                //dpm($file);

                if (isset($file->fid)) {
                  $replacement = '<p>[[{"fid":"' . $file->fid . '","view_mode":"default","type":"media","attributes":{"height":404,"width":665,"alt":"video","class":"media-element file-default"}}]]</p>';
                  $video_node->body = str_replace($match, $replacement, $video_node->body);

                }
              }
            }
          }
        }
      }
    }
  }
  
  foreach ($data as $video_node) {
    $node = node_load($video_node->nid);
    $node->body['und'][0]['value'] = $video_node->body;
    $node->atwork_migrating = TRUE;
    node_save($node);
  }
  
  $context['results'][] = 'Converted ' . count($data) . ' inline videos';
  $context['message'] = 'Converting inline videos';
}

function atwork_migrate_save_inline_videos(&$context) {
  _atwork_migrate_d6_database();
  
  $data = array();
  
  $result = db_query("SELECT *
                      FROM {node} n
                      LEFT JOIN {term_node} t ON (t.vid = n.vid)
                      LEFT JOIN {node_revisions} r ON (n.vid = r.vid)
                      WHERE (n.type = 'article' OR n.type = 'blog')
                      AND (
                        r.body LIKE '%youtube%' OR t.tid = 41 OR r.body LIKE '%[swf file=%video'
                      )");
  //t.tid = 41 OR r.body LIKE '%[swf file=%'
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  db_set_active('default');
  
  foreach ($data as $video_node) {
    $node = node_load($video_node->nid);
    node_save($node);
  }
  
  $context['results'][] = 'Saved ' . count($data) . ' inline videos';
  $context['message'] = 'Saving inline videos';
}

function atwork_migrate_convert_inline_polls(&$context) {
  _atwork_migrate_d6_database();
  
  $data = array();
  
  $result = db_query("SELECT *
                      FROM {node} n
                      LEFT JOIN {term_node} t ON (t.vid = n.vid)
                      WHERE t.tid = 40
                      AND n.type = 'article'");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  db_set_active('default');
  
  foreach ($data as $poll) {
    $node = node_load($poll->nid);
    if ($node) {
      $node->body['und'][0]['value'] = str_replace('[block:atworkpoll=', '[block:poll=', $node->body['und'][0]['value']);
      $node->body['und'][0]['summary'] = str_replace('[block:atworkpoll=', '[block:poll=', $node->body['und'][0]['summary']);
      node_save($node);
    }
  }
  
  $context['results'][] = 'Converted ' . count($data) . ' inline polls';
  $context['message'] = 'Converting inline polls';
}

function atwork_migrate_remove_teaser_breaks(&$context) {
  $result = db_query("SELECT entity_id
                      FROM {field_data_body}
                      WHERE body_value LIKE '%<!--break-->%'");
  
  foreach ($result as $record) {
    $node = node_load($record->entity_id);
    $node->body['und'][0]['value'] = str_replace('<!--break-->', '', $node->body['und'][0]['value']);
    node_save($node);
  }
  
  $context['results'][] = 'Removed ' . count($result) . ' teaser breaks';
  $context['message'] = 'Removing teaser breaks';
}

function atwork_migrate_export_wiki_html(&$context) {
  require_once 'sites/all/libraries/htmlpurifier/library/HTMLPurifier.auto.php';
  
  $purifier = new HTMLPurifier();
  
  $fp = fopen('/var/www/tools/wiki_html.csv', 'w+');
    
  $result = db_query("SELECT n.nid, b.body_value
                      FROM {node} n
                      LEFT JOIN {mediawiki_bridge} m ON (n.nid = m.nid)
                      LEFT JOIN {field_data_body} b ON (n.nid = b.entity_id)
                      WHERE n.type = 'wiki'");
  
  $data = array();
  foreach ($result as $record) {
    $data[$record->nid] = $record->body_value;
  }
  
  // for now we are grabbing our old body values
  // delete this on a fresh import
  _atwork_migrate_d6_database();
  
  foreach ($data as $nid => &$body) {
    $body_result = db_query("SELECT 
                        r.body 
                      FROM {node} n
                      LEFT JOIN {node_revisions} r ON (n.vid = r.vid)
                      WHERE n.nid = :nid
                      LIMIT 1", array(':nid' => $nid))->fetchObject();
    $body = transliteration_get($body_result->body, '');
    $body = html_entity_decode($body);
    $body = $purifier->purify($body);
    
  }
  
  db_set_active('default');
  
  foreach ($data as $nid => &$body) {
    $body_dom = filter_dom_load($body);
    $xpath = new DOMXPath($body_dom);
    
    $matches = array();
    $replacements = array();
    
    foreach ($xpath->query('//a') as $match) {
      $href = $match->getAttribute('href');
      $pos = strpos($href, '/wiki/items/');
      if ($pos !== FALSE) {
        // this is a wiki item, find the title and replace with [title]
        
        // prepare the href for path alias query
        $href = str_replace('https://gww.gov.bc.ca', '', $href);
        $href = str_replace('http://gww.gov.bc.ca', '', $href);
        $href = substr($href, 1);
        
        $alias_result = db_query("SELECT REPLACE(source,'node/','') as nid FROM {url_alias} WHERE alias = :href LIMIT 1", array(':href' => $href))->fetchObject();
        
        // check for a space at the end of the a tag
        $add_ending_space = '';
        $reversed_title = strrev($match->nodeValue);
        if ($reversed_title{0} == ' ') {
          $add_ending_space = ' ';
        }
        
        $match_title = trim($match->nodeValue);
        
        $return = '[' . $match_title . ']';
        
        if (isset($alias_result->nid)) {
          $title_result = db_query("SELECT title FROM {node} WHERE nid = :nid LIMIT 1", array(':nid' => $alias_result->nid))->fetchObject();
          if (isset($title_result->title)) {
            if ($title_result->title != $match_title) {
              $return = '[' . trim($title_result->title) . '|' . $match_title . ']';
            }
          }
        }
        
         $return .= $add_ending_space;
        
        $matches[] = $body_dom->saveXML($match);
        $replacements[] = $return;
      }
    }
    
    if ($matches) {
      $body = str_replace($matches, $replacements, $body);
    }
    
    $body = check_markup($body, 'mail');
    $body = str_replace($GLOBALS['base_url'], 'https://gww.gov.bc.ca/', $body);
    $body = str_replace('<div>', '', $body);
    $body = str_replace('</div>', '', $body);
    if (!$body) {
      $body = ' ';
    }
    fputcsv($fp, array($nid, $body));
  }
  
  fclose($fp);
  
  $context['results'][] = 'Exported ' . count($data) . ' wiki entries';
  $context['message'] = 'Exporting wiki HTML';
}

function atwork_migrate_fix_wiki_images(&$context) {
  // fix wiki files
  $files = array();
  $it = new RecursiveDirectoryIterator("/var/www/html-8000/sites/default/files/wiki");
  $display = array ( 'jpeg', 'jpg', 'png', 'gif' );
  foreach(new RecursiveIteratorIterator($it) as $file) {
    if (in_array(strtolower(array_pop(explode('.', $file))), $display)) {
      $files[] = array(
        'filepath' => $file->getPath(),
        'filename' => $file->getFilename(),
      );
    }
  }
  
  foreach ($files as $image_file) {
  
    //$result = db_query('SELECT fid FROM {file_managed} WHERE uri = :filename', array(':filename' => 'public://wiki/userimage/' . $image_file['filename']))->fetchObject();
    $result = db_query('SELECT fid FROM {file_managed} WHERE filename = :filename', array(':filename' => $image_file['filename']))->fetchObject();
    
    if (isset($result->fid)) {

      $file = file_load($result->fid);

      $new_filename = str_replace(' ', '_', $file->filename);
      $new_filename = str_replace('%20', '_', $new_filename);
      $new_filename = ucwords($new_filename);
      
      // update body fields for inline images
      // first get nids this image is attached to
      
      $query = db_select('field_data_field_image', 'i')
        ->condition('field_image_fid', $file->fid)
        ->fields('i', array('entity_id'))
        ->execute();
      
      $nids = array();
      while ($record = $query->fetchAssoc()) {
        $nids[] = $record['entity_id'];
      }
      
      if ($nids) {
        db_query("
          UPDATE {field_data_body}
          SET body_value = REPLACE(body_value, 'bridge.jpg', 'Bridge.jpg')
          WHERE entity_id IN (" . implode(',', $nids) . ")
        ");

        db_query("
          UPDATE {field_revision_body} 
          SET body_value = REPLACE(body_value, 'bridge.jpg', 'Bridge.jpg')
          WHERE entity_id IN (" . implode(',', $nids) . ")
        ");
      }
      
      // all files not located in /userimage 
      if (strpos($image_file['filepath'], '/sites/default/files/wiki/image')) {
        $file->filename = $new_filename;
        file_move($file, file_default_scheme().'://wiki/userimage/'. $new_filename);
      }
      elseif ($file->filename != $new_filename) {
        $file->filename = $new_filename;
        file_move($file, file_default_scheme().'://wiki/userimage/'. $new_filename, FILE_EXISTS_REPLACE);
      }
    }
  }
  
  $context['results'][] = 'Fixed ' . count($files) . ' wiki images';
  $context['message'] = 'Fixing wiki images';
}

function atwork_migrate_convert_sections(&$context) {
  // convert sections
  // arrc
  $gid = 2637;
  
  $node = node_load($gid);
  $node->type = 'section';
  node_save($node);
  
  // clear existing menu
  $menu_links = menu_load_links('menu-og-' . $gid);
  foreach ($menu_links as $link) {
    menu_link_delete($link['mlid']);
  }
  
  $section_pages = array(
    2655 => array(
      2973 => 2973,
      2974 => 2974,
      2975 => 2975,
      2976 => 2976,
      2977 => 2977,
      2978 => 2978,
      2979 => 2979,
      2980 => 2980,
      2981 => 2981,
    ),
    5738 => 5738,
    2694 => 2694,
    2692 => 2692,
    2678 => 2678,
    2679 => array(
      2680 => 2680,
      2681 => array(
        2959 => 2959,
        2960 => 2960,
        2961 => 2961,
        4089 => 4089,
        4090 => 4090,
        4091 => 4091,
        5818 => 5818,
        2962 => 2962,
        2963 => 2963,
        2964 => 2964,
        2965 => 2965,
        2966 => 2966,
        2967 => 2967,
        2968 => 2968,
        2969 => 2969,
        4049 => 4049,
        4096 => 4096,
        2970 => 2970,
        2971 => 2971,
        4097 => 4097,
      ),
      2955 => 2955,
    ),
    3898 => array(
      5047 => 5047,
    ),
  );
  
  $weight = 0;
  foreach ($section_pages as $nid => $value) {
    $sub_node = node_load($nid);
    $sub_node->type = 'section_page';
    node_save($sub_node);
    $sub_node->og_group_ref['und'][0]['target_id'] = $gid;
    node_save($sub_node);
    
    $item = array(
      'link_path' => 'node/' . $nid,
      'link_title' => $sub_node->title,
      'menu_name' => 'menu-og-' . $gid,
      'weight' => $weight,
    );
    $mlid = menu_link_save($item);
    
    if (is_array($value)) {
      foreach ($value as $sub_nid => $sub_value) {
        $sub_sub_node = node_load($sub_nid);
        $sub_sub_node->type = 'section_page';
        node_save($sub_sub_node);
        $sub_sub_node->og_group_ref['und'][0]['target_id'] = $gid;
        node_save($sub_sub_node);
    
        $item = array(
          'link_path' => 'node/' . $sub_nid,
          'link_title' => $sub_sub_node->title,
          'menu_name' => 'menu-og-' . $gid,
          'weight' => $weight,
        );
        
        if ($mlid) {
          $item['plid'] = $mlid;
        }
        $sub_mlid = menu_link_save($item);
        
        if (is_array($sub_value)) {
          foreach ($sub_value as $sub_sub_nid => $sub_sub_value) {
            $sub_sub_sub_node = node_load($sub_sub_nid);
            $sub_sub_sub_node->type = 'section_page';
            node_save($sub_sub_sub_node);
            $sub_sub_sub_node->og_group_ref['und'][0]['target_id'] = $gid;
            node_save($sub_sub_sub_node);
            
            $item = array(
              'link_path' => 'node/' . $sub_sub_nid,
              'link_title' => $sub_sub_sub_node->title,
              'menu_name' => 'menu-og-' . $gid,
              'weight' => $weight,
            );

            if ($sub_mlid) {
              $item['plid'] = $sub_mlid;
            }
            menu_link_save($item);
            $weight++;
          }
        }
        
        $sub_mlid = 0;
        $weight++;
      }
    }
    
    $mlid = 0;
    $weight++;
  }
  
  // ce
  $gid = 2186;
  
  $node = node_load($gid);
  $node->type = 'section';
  node_save($node);
  
  // clear existing menu
  $menu_links = menu_load_links('menu-og-' . $gid);
  foreach ($menu_links as $link) {
    menu_link_delete($link['mlid']);
  }
  
  $section_pages = array(
    2184 => array(
      2196 => 2196,
      2197 => 2197,
      6032 => 6032,
      6397 => 6397,
      3049 => 3049,
      2687 => 2687,
    ),
    3949 => array(
      5020 => 5020,
      4032 => 4032,
      4104 => 4104,
      5226 => 5226,
      5227 => 5227,
      5750 => 5750,
    ),
    6396 => array(
      5499 => 5499,
      5068 => array(
        5027 => 5027,
        5028 => 5028,
        5031 => 5031,
        5032 => 5032,
        5034 => 5034,
        5035 => 5035,
        5036 => 5036,
        5037 => 5037,
      ),
    ),
    2185 => array(
      2193 => array(
        2210 => 2210,
        2211 => 2211,
        2200 => 2200,
        2205 => 2205,
        2204 => 2204,
        2199 => 2199,
        2274 => 2274,
        2201 => 2201,
        2202 => 2202,
        2198 => 2198,
        2203 => 2203,
      ),
      2216 => 2216,
      2208 => array(
        2176 => 2176,
        2175 => 2175,
        2177 => 2177,
        2174 => 2174,
        2179 => 2179,
        2178 => 2178,
        2181 => 2181,
        2182 => 2182,
        2180 => 2180,
      ),
      2187 => 2187,
      2188 => 2188,
      2190 => array(
        2192 => array(
          2171 => 2171,
          2173 => 2173,
          2170 => 2170,
          2172 => 2172,
          2160 => 2160,
        ),
        2206 => array(
          2161 => 2161,
          2164 => 2164,
          2163 => 2163,
          2162 => 2162,
          2159 => 2159,
        ),
        2207 => array(
          2169 => 2169,
          2165 => 2165,
          2167 => 2167,
          2168 => 2168,
          2166 => 2166,
        ),
        3656 => array(
          3369 => 3369,
          3370 => 3370,
          3372 => 3372,
          3376 => 3376,
          3377 => 3377,
        ),
        4123 => array(
          4105 => 4105,
          4108 => 4108,
          4119 => 4119,
          4120 => 4120,
          4121 => 4121,
        ),
        4201 => array(
          4185 => 4185,
          4186 => 4186,
          4188 => 4188,
          4189 => 4189,
          4190 => 4190
        ),
      ),
    ),
    2223 => array(
      5324 => 5324,
      3734 => 3734,
      5749 => 5749,
      2227 => 2227,
    ),
  );
  
  $weight = 0;
  foreach ($section_pages as $nid => $value) {
    $sub_node = node_load($nid);
    $sub_node->type = 'section_page';
    node_save($sub_node);
    $sub_node->og_group_ref['und'][0]['target_id'] = $gid;
    node_save($sub_node);
    
    $item = array(
      'link_path' => 'node/' . $nid,
      'link_title' => $sub_node->title,
      'menu_name' => 'menu-og-' . $gid,
      'weight' => $weight,
    );
    $mlid = menu_link_save($item);
    
    if (is_array($value)) {
      foreach ($value as $sub_nid => $sub_value) {
        $sub_sub_node = node_load($sub_nid);
        $sub_sub_node->type = 'section_page';
        node_save($sub_sub_node);
        $sub_sub_node->og_group_ref['und'][0]['target_id'] = $gid;
        node_save($sub_sub_node);
    
        $item = array(
          'link_path' => 'node/' . $sub_nid,
          'link_title' => $sub_sub_node->title,
          'menu_name' => 'menu-og-' . $gid,
          'weight' => $weight,
        );
        
        if ($mlid) {
          $item['plid'] = $mlid;
        }
        $sub_mlid = menu_link_save($item);
        
        if (is_array($sub_value)) {
          foreach ($sub_value as $sub_sub_nid => $sub_sub_value) {
            $sub_sub_sub_node = node_load($sub_sub_nid);
            $sub_sub_sub_node->type = 'section_page';
            node_save($sub_sub_sub_node);
            $sub_sub_sub_node->og_group_ref['und'][0]['target_id'] = $gid;
            node_save($sub_sub_sub_node);
            
            $item = array(
              'link_path' => 'node/' . $sub_sub_nid,
              'link_title' => $sub_sub_sub_node->title,
              'menu_name' => 'menu-og-' . $gid,
              'weight' => $weight,
            );

            if ($sub_mlid) {
              $item['plid'] = $sub_mlid;
            }
            $sub_sub_mlid = menu_link_save($item);
            
            if (is_array($sub_sub_value)) {
              foreach ($sub_sub_value as $sub_sub_sub_nid => $sub_sub_sub_value) {
                $sub_sub_sub_sub_node = node_load($sub_sub_sub_nid);
                $sub_sub_sub_sub_node->type = 'section_page';
                node_save($sub_sub_sub_sub_node);
                $sub_sub_sub_sub_node->og_group_ref['und'][0]['target_id'] = $gid;
                node_save($sub_sub_sub_sub_node);

                $item = array(
                  'link_path' => 'node/' . $sub_sub_sub_nid,
                  'link_title' => $sub_sub_sub_sub_node->title,
                  'menu_name' => 'menu-og-' . $gid,
                  'weight' => $weight,
                );

                if ($sub_sub_mlid) {
                  $item['plid'] = $sub_sub_mlid;
                }
                menu_link_save($item);

                $weight++;
              }
            }
            
            $sub_sub_mlid = 0;
            $weight++;
          }
        }
        
        $sub_mlid = 0;
        $weight++;
      }
    }
    
    $mlid = 0;
    $weight++;
  }
  
  $context['results'][] = 'Dealt with ARRC and CE';
  $context['message'] = 'Dealing with ARRC and CE';
}

function atwork_migrate_save_ecards(&$context) {
  $data = array();
  
  $ecard_field['und'][0] = array(
    'id' => '',
    'class' => 'ecard-message',
    'top' => 0,
    'left' => 0,
    'width' => '300',
    'color' => '000000',
    'font' => '',
    'font_size' => 12,
  );
  
  $result = db_query("SELECT *
                      FROM {node} n
                      WHERE n.type = 'ecard'");
  
  foreach ($result as $record) {
    $data[] = $record;
  }
  
  foreach ($data as $ecard) {
    $node = node_load($ecard->nid);
    if ($node) {
      $node->field_e_card = $ecard_field;
      node_save($node);
    }
  }
  
  $context['results'][] = 'Saved ' . count($data) . ' ecards';
  $context['message'] = 'Saving ecards';
}

function atwork_migrate_clean_blogs(&$context) {
  $result = db_query("
    SELECT nid 
    FROM {node} n
    LEFT JOIN {field_data_body} b ON (b.revision_id = n.vid)
    WHERE b.body_value LIKE '%Previous post </a>by this blogger%'
    OR b.body_value LIKE '%Previous post</a> by this blogger%'
  ");
  
  
  foreach ($result as $record) {
    if ($node = node_load($record->nid)) {
      $body = preg_replace('/\r\n/', "\n", $node->body[$node->language][0]['value']);
      $dom = filter_dom_load($body);
      $dom->preserveWhiteSpace = false;
      $xpath = new DOMXPath($dom);
      
      foreach ($xpath->query("//p[contains(.,'by this blogger')]") as $p) {
        $p->parentNode->removeChild($p);
      }
      
      $body = filter_dom_serialize($dom);
      
      $node->body[$node->language][0]['value'] = $body;
      node_save($node);
    }
  }
  
  $context['results'][] = 'Cleaned ' . count($result) . ' blog posts';
  $context['message'] = 'Cleaning Blog Posts';
}

function atwork_migrate_fill_auth_table(&$context) {
  $query = db_select('authmap', 'a');
  $query->addField('a','uid');

  // Perform the insert.
  db_insert('atwork_auth')
    ->from($query)
    ->execute();
  
  $context['results'][] = 'Filled atwork_auth';
  $context['message'] = 'Filling atwork_auth';
}

function atwork_migrate_fill_comment_revision(&$context) {
  db_update('comment')
    ->expression('vid', 'cid')
    ->execute();
  
  
  $query = db_select('comment', 'c');
  $query->addField('c','cid');
  $query->addField('c','vid');
  $query->addField('c','uid', 'revision_uid');
  $query->addField('c','uid');
  $query->addField('c','subject');
  $query->addField('c','changed', 'timestamp');
  $query->addField('c','created');
  $query->addField('c','mail');
  $query->addField('c','homepage');
  $query->addField('c','status');
  $query->addField('c','language');

  // Perform the insert.
  db_insert('comment_revision')
    ->from($query)
    ->execute();
  
  $context['results'][] = 'Filled comment_revision';
  $context['message'] = 'Filling comment_revision';
}

function atwork_migrate_fix_related_links(&$context) {
  db_update('field_data_field_related_links')
      ->fields(array(
        'field_related_links_attributes' => 'a:0:{}',
      ))
      ->execute();
  
  db_update('field_revision_field_related_links')
      ->fields(array(
        'field_related_links_attributes' => 'a:0:{}',
      ))
      ->execute();
  
  $context['results'][] = 'Fixed related_links';
  $context['message'] = 'Fixing related_links';
}

function atwork_migrate_remove_inline_js(&$context) {
  $data = array();
  
  $result = db_query("SELECT *
                      FROM {node} n
                      LEFT JOIN {field_data_body} f ON f.entity_id = n.nid
                      WHERE f.body_value LIKE '%<script%'
                      AND n.type != 'blog'
                      AND n.status = 1
                      AND f.entity_id NOT IN (364,370,2013,2028,2040,2042,2043,2046,2047,2048,2191,2530,2268)");
  
  foreach ($result as $record) {
    $data[] = $record;
  }

  foreach ($data as $nid) {
    $node = node_load($nid->nid);
    if ($node) {
      if (isset($node->body[$node->language][0]['value']) && $node->body[$node->language][0]['value']) {
        $dom =  filter_dom_load($node->body[$node->language][0]['value']);
        $xpath = new DOMXPath($dom);

        $list = $xpath->query("//script");
        
        for($j=0; $j<$list->length; ++$j) {
          $dom_node = $list->item($j);
          if ($dom_node == null) continue;
          $dom_node->parentNode->removeChild($dom_node);
        }
        $body = filter_dom_serialize($dom);
        $node->body[$node->language][0]['value'] = $body;
        node_save($node);
      }
    }
  }
  
  $context['results'][] = 'Removed inline js from ' . count($result) . ' nodes';
  $context['message'] = 'Removing inline js';
}

function atwork_migrate_remove_dup_transcripts(&$context) {
  $data = array();
  return;
  $result = db_query("SELECT *
                      FROM {node} n
                      LEFT JOIN {field_data_body} f ON f.entity_id = n.nid
                      LEFT JOIN {field_data_field_video} v ON v.entity_id = n.nid 
                      WHERE f.body_value LIKE '%media-element%'
                      AND f.body_value LIKE '%field-field-media-transcript%'
                      AND v.field_video_fid IS NULL
                      AND n.status = 1");
  
  foreach ($result as $record) {
    $data[] = $record;
  }

  $changed = 0;
  
  foreach ($data as $nid) {
    $node = node_load($nid->nid);
    if ($node) {
      $fids = _media_fids_in_text($node->body[$node->language][0]['value']);
      if (count($fids) == 1) {
        foreach ($fids as $fid) {
          $file = file_load($fid);
          if ($file) {
            $transcript = field_get_items('file', $file, 'field_transcript');
            if ($transcript) {
              $dom =  filter_dom_load($node->body[$node->language][0]['value']);
              $xpath = new DOMXPath($dom);
              
              $list = $xpath->query("//div[contains(concat(' ', @class, ' '), ' field-field-media-transcript ')]");        
              for($j=0; $j<$list->length; ++$j) {
                $dom_node = $list->item($j);
                if ($dom_node == null) continue;
                $dom_node->parentNode->removeChild($dom_node);
                $changed++;
              }
              $body = filter_dom_serialize($dom);
              $node->body[$node->language][0]['value'] = $body;
              //dpm($node);
              node_save($node);
              
            }
          }
        }
      }
      elseif (count($fids) > 1) {
        //dpm($node);
      }
      
//      if (isset($node->body[$node->language][0]['value']) && $node->body[$node->language][0]['value']) {
//        $dom =  filter_dom_load($node->body[$node->language][0]['value']);
//        $xpath = new DOMXPath($dom);
//
//        $list = $xpath->query("//script");
//        
//        for($j=0; $j<$list->length; ++$j) {
//          $dom_node = $list->item($j);
//          if ($dom_node == null) continue;
//          $dom_node->parentNode->removeChild($dom_node);
//        }
//        $body = filter_dom_serialize($dom);
//        $node->body[$node->language][0]['value'] = $body;
//        node_save($node);
//      }
    }
  }
  
  $context['results'][] = 'Removed duplicate transcript from ' . $changed . ' nodes';
  $context['message'] = 'Removing duplicate transcripts';
}