<?php
/**
 * @file
 * atwork_lsa_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function atwork_lsa_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content';
  $view->description = 'Admin content on the site';
  $view->tag = 'vbo';
  $view->base_table = 'node';
  $view->human_name = 'Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Long Service Awards Pin Application';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'uid' => 'uid',
    'field_display_name' => 'field_display_name',
    'status' => 'status',
    'created' => 'created',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content yet';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['empty'] = 'Employee News';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  /* Field: Content: Supervisor Email */
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['id'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['field'] = 'field_lsa_supervisor_email';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = 'All';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  $handler->display->display_options['filters']['promote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted to front page';
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  $handler->display->display_options['filters']['promote']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = 'All';
  $handler->display->display_options['filters']['sticky']['group'] = 1;
  $handler->display->display_options['filters']['sticky']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sticky']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['sticky']['expose']['label'] = 'Sticky';
  $handler->display->display_options['filters']['sticky']['expose']['operator'] = 'sticky_op';
  $handler->display->display_options['filters']['sticky']['expose']['identifier'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['sticky']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author (IDIR)';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Field: Email (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Display Name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['identifier'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['empty'] = 'Employee News';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '0';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  $handler->display->display_options['filters']['promote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted to front page';
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  $handler->display->display_options['filters']['promote']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = 'All';
  $handler->display->display_options['filters']['sticky']['group'] = 1;
  $handler->display->display_options['filters']['sticky']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sticky']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['sticky']['expose']['label'] = 'Sticky';
  $handler->display->display_options['filters']['sticky']['expose']['operator'] = 'sticky_op';
  $handler->display->display_options['filters']['sticky']['expose']['identifier'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ad_space' => 'ad_space',
    'page' => 'page',
    'blog' => 'blog',
    'classified' => 'classified',
    'ecard' => 'ecard',
    'event' => 'event',
    'forum' => 'forum',
    'gallery' => 'gallery',
    'section' => 'section',
    'section_page' => 'section_page',
    'image' => 'image',
    'lsa_application' => 'lsa_application',
    'article' => 'article',
    'poll' => 'poll',
    'quiz' => 'quiz',
    'lsa_pin_application' => 'lsa_pin_application',
    'webform' => 'webform',
    'wiki' => 'wiki',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author (IDIR)';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Field: Email (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Display Name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['identifier'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'admin/content';

  /* Display: Page: OG Admin */
  $handler = $view->new_display('page', 'Page: OG Admin', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'administer og menu';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'uid' => 'uid',
    'field_display_name' => 'field_display_name',
    'status' => 'status',
    'created' => 'created',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="content_type_title">Manage Content<h2>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_display_name']['label'] = 'Author';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['empty'] = 'Employee News';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'event' => 'event',
    'gallery' => 'gallery',
    'section_page' => 'section_page',
    'article' => 'article',
    'poll' => 'poll',
    'question' => 'question',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field: Email (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['identifier'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['path'] = 'node/%/admin';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Manage Content';
  $handler->display->display_options['menu']['description'] = 'Administer group content';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page: LSA */
  $handler = $view->new_display('page', 'Page: LSA', 'lsa');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Long Service Awards Applications';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_lsa_years_of_service' => 'field_lsa_years_of_service',
    'field_lsa_org' => 'field_lsa_org',
    'field_lsa_register_last_year' => 'field_lsa_register_last_year',
    'field_lsa_received_award' => 'field_lsa_received_award',
    'field_lsa_employee_number' => 'field_lsa_employee_number',
    'field_lsa_gift_option' => 'field_lsa_gift_option',
    'nothing' => 'nothing',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_years_of_service' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_org' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_register_last_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_received_award' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_employee_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_gift_option' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: Did you register last year but were unable to attend the ceremony? */
  $handler->display->display_options['fields']['field_lsa_register_last_year']['id'] = 'field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['table'] = 'field_data_field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['field'] = 'field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['label'] = 'Missed Ceremony?';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['element_label_colon'] = FALSE;
  /* Field: Content: Did you receive your award? */
  $handler->display->display_options['fields']['field_lsa_received_award']['id'] = 'field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['table'] = 'field_data_field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['field'] = 'field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['label'] = 'Received award?';
  $handler->display->display_options['fields']['field_lsa_received_award']['element_label_colon'] = FALSE;
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] - [delete_node]';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Supervisor Email (field_lsa_supervisor_email) */
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['id'] = 'field_lsa_supervisor_email_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['field'] = 'field_lsa_supervisor_email_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['operator_id'] = 'field_lsa_supervisor_email_email_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['label'] = 'Supervisor Email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['operator'] = 'field_lsa_supervisor_email_email_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['identifier'] = 'supervisor_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_field'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_raw_dropdown'] = 0;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Ministry/Organization (field_lsa_org) */
  $handler->display->display_options['filters']['field_lsa_org_value']['id'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['filters']['field_lsa_org_value']['field'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator_id'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['label'] = 'Ministry/Organization';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['identifier'] = 'ministry';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Years of Service (field_lsa_years_of_service) */
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['id'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['field'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator_id'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['label'] = 'Years of Service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['identifier'] = 'years_of_service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  $handler->display->display_options['path'] = 'administration/long-service-awards';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'lsa_export');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Content: Retiring in 2018? */
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['id'] = 'field_lsa_retiring_thisyear';
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['table'] = 'field_data_field_lsa_retiring_thisyear';
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['field'] = 'field_lsa_retiring_thisyear';
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['label'] = 'Retiring in 2016?';
  /* Field: Content: Date of Retirement */
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['id'] = 'field_lsa_date_of_retirement';
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['table'] = 'field_data_field_lsa_date_of_retirement';
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['field'] = 'field_lsa_date_of_retirement';
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Did you register last year but were unable to attend the ceremony? */
  $handler->display->display_options['fields']['field_lsa_register_last_year']['id'] = 'field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['table'] = 'field_data_field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['field'] = 'field_lsa_register_last_year';
  /* Field: Content: Did you receive your award? */
  $handler->display->display_options['fields']['field_lsa_received_award']['id'] = 'field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['table'] = 'field_data_field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['field'] = 'field_lsa_received_award';
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Certificate Name */
  $handler->display->display_options['fields']['field_lsa_25year_certificatename']['id'] = 'field_lsa_25year_certificatename';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename']['table'] = 'field_data_field_lsa_25year_certificatename';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename']['field'] = 'field_lsa_25year_certificatename';
  /* Field: Content: Engravement */
  $handler->display->display_options['fields']['field_lsa_engravement']['id'] = 'field_lsa_engravement';
  $handler->display->display_options['fields']['field_lsa_engravement']['table'] = 'field_data_field_lsa_engravement';
  $handler->display->display_options['fields']['field_lsa_engravement']['field'] = 'field_lsa_engravement';
  /* Field: Content: Watch Engraving Sent */
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['id'] = 'field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['table'] = 'field_data_field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['field'] = 'field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Award Special Instructions */
  $handler->display->display_options['fields']['field_lsa_award_sp_instructions']['id'] = 'field_lsa_award_sp_instructions';
  $handler->display->display_options['fields']['field_lsa_award_sp_instructions']['table'] = 'field_data_field_lsa_award_sp_instructions';
  $handler->display->display_options['fields']['field_lsa_award_sp_instructions']['field'] = 'field_lsa_award_sp_instructions';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_first_name']['id'] = 'field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['field'] = 'field_lsa_first_name';
  /* Field: Content: Middle Name */
  $handler->display->display_options['fields']['field_lsa_middle_name']['id'] = 'field_lsa_middle_name';
  $handler->display->display_options['fields']['field_lsa_middle_name']['table'] = 'field_data_field_lsa_middle_name';
  $handler->display->display_options['fields']['field_lsa_middle_name']['field'] = 'field_lsa_middle_name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_last_name']['id'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['field'] = 'field_lsa_last_name';
  /* Field: Content: Street */
  $handler->display->display_options['fields']['field_lsa_street_1']['id'] = 'field_lsa_street_1';
  $handler->display->display_options['fields']['field_lsa_street_1']['table'] = 'field_data_field_lsa_street';
  $handler->display->display_options['fields']['field_lsa_street_1']['field'] = 'field_lsa_street';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_city']['id'] = 'field_lsa_city';
  $handler->display->display_options['fields']['field_lsa_city']['table'] = 'field_data_field_lsa_city';
  $handler->display->display_options['fields']['field_lsa_city']['field'] = 'field_lsa_city';
  /* Field: Content: Street */
  $handler->display->display_options['fields']['field_lsa_street']['id'] = 'field_lsa_street';
  $handler->display->display_options['fields']['field_lsa_street']['table'] = 'field_data_field_lsa_street';
  $handler->display->display_options['fields']['field_lsa_street']['field'] = 'field_lsa_street';
  /* Field: Content: Province */
  $handler->display->display_options['fields']['field_lsa_office_province']['id'] = 'field_lsa_office_province';
  $handler->display->display_options['fields']['field_lsa_office_province']['table'] = 'field_data_field_lsa_office_province';
  $handler->display->display_options['fields']['field_lsa_office_province']['field'] = 'field_lsa_office_province';
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['id'] = 'field_lsa_home_postal_code';
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['table'] = 'field_data_field_lsa_home_postal_code';
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['field'] = 'field_lsa_home_postal_code';
  /* Field: Content: Alternate Email Address */
  $handler->display->display_options['fields']['field_lsa_alt_email_address']['id'] = 'field_lsa_alt_email_address';
  $handler->display->display_options['fields']['field_lsa_alt_email_address']['table'] = 'field_data_field_lsa_alt_email_address';
  $handler->display->display_options['fields']['field_lsa_alt_email_address']['field'] = 'field_lsa_alt_email_address';
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_lsa_email']['id'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['table'] = 'field_data_field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['field'] = 'field_lsa_email';
  /* Field: Content: Home Phone */
  $handler->display->display_options['fields']['field_lsa_home_phone']['id'] = 'field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['table'] = 'field_data_field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['field'] = 'field_lsa_home_phone';
  /* Field: Content: Work Phone */
  $handler->display->display_options['fields']['field_lsa_work_phone']['id'] = 'field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['table'] = 'field_data_field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['field'] = 'field_lsa_work_phone';
  /* Field: Content: Work Phone Extension */
  $handler->display->display_options['fields']['field_lsa_work_phone_ext']['id'] = 'field_lsa_work_phone_ext';
  $handler->display->display_options['fields']['field_lsa_work_phone_ext']['table'] = 'field_data_field_lsa_work_phone_ext';
  $handler->display->display_options['fields']['field_lsa_work_phone_ext']['field'] = 'field_lsa_work_phone_ext';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: Ministry ID */
  $handler->display->display_options['fields']['field_lsa_ministry_id']['id'] = 'field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['table'] = 'field_data_field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['field'] = 'field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
  /* Field: Content: Work Street Address */
  $handler->display->display_options['fields']['field_lsa_office_address']['id'] = 'field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['table'] = 'field_data_field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['field'] = 'field_lsa_office_address';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_city_1']['id'] = 'field_lsa_city_1';
  $handler->display->display_options['fields']['field_lsa_city_1']['table'] = 'field_data_field_lsa_city';
  $handler->display->display_options['fields']['field_lsa_city_1']['field'] = 'field_lsa_city';
  /* Field: Content: Province */
  $handler->display->display_options['fields']['field_lsa_home_province']['id'] = 'field_lsa_home_province';
  $handler->display->display_options['fields']['field_lsa_home_province']['table'] = 'field_data_field_lsa_home_province';
  $handler->display->display_options['fields']['field_lsa_home_province']['field'] = 'field_lsa_home_province';
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['id'] = 'field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['table'] = 'field_data_field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['field'] = 'field_lsa_office_postal_code';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['id'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['table'] = 'field_data_field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['field'] = 'field_lsa_supervisor_first_name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['id'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['table'] = 'field_data_field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['field'] = 'field_lsa_supervisor_last_name';
  /* Field: Content: Supervisor Email */
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['id'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['field'] = 'field_lsa_supervisor_email';
  /* Field: Content: Notes */
  $handler->display->display_options['fields']['field_lsa_notes']['id'] = 'field_lsa_notes';
  $handler->display->display_options['fields']['field_lsa_notes']['table'] = 'field_data_field_lsa_notes';
  $handler->display->display_options['fields']['field_lsa_notes']['field'] = 'field_lsa_notes';
  /* Field: Content: RSVP */
  $handler->display->display_options['fields']['field_lsa_rsvp']['id'] = 'field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['field'] = 'field_lsa_rsvp';
  /* Field: Content: Attending Ceremony */
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['id'] = 'field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['field'] = 'field_lsa_attending_ceremony';
  /* Field: Content: Guest Attending */
  $handler->display->display_options['fields']['field_lsa_guest']['id'] = 'field_lsa_guest';
  $handler->display->display_options['fields']['field_lsa_guest']['table'] = 'field_data_field_lsa_guest';
  $handler->display->display_options['fields']['field_lsa_guest']['field'] = 'field_lsa_guest';
  /* Field: Content: Number Attending */
  $handler->display->display_options['fields']['field_lsa_number_attending']['id'] = 'field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['table'] = 'field_data_field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['field'] = 'field_lsa_number_attending';
  /* Field: Content: Invitation Send Date */
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['id'] = 'field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['table'] = 'field_data_field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['field'] = 'field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Attending with alternate Min/Org */
  $handler->display->display_options['fields']['field_lsa_alternate_min_org']['id'] = 'field_lsa_alternate_min_org';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org']['table'] = 'field_data_field_lsa_alternate_min_org';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org']['field'] = 'field_lsa_alternate_min_org';
  /* Field: Content: Actual_Min/Org */
  $handler->display->display_options['fields']['field_lsa_actual_min_org']['id'] = 'field_lsa_actual_min_org';
  $handler->display->display_options['fields']['field_lsa_actual_min_org']['table'] = 'field_data_field_lsa_actual_min_org';
  $handler->display->display_options['fields']['field_lsa_actual_min_org']['field'] = 'field_lsa_actual_min_org';
  /* Field: Content: Ceremony Date */
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['id'] = 'field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['field'] = 'field_lsa_ceremonydate';
  /* Field: Content: Ceremony Night */
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['id'] = 'field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['table'] = 'field_data_field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['field'] = 'field_lsa_ceremony_night';
  $handler->display->display_options['path'] = 'administration/long-service-awards/lsa-applications.csv';
  $handler->display->display_options['displays'] = array(
    'lsa' => 'lsa',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'page_2' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Block: User Content */
  $handler = $view->new_display('block', 'Block: User Content', 'block_user');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content yet';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );

  /* Display: LSA Pin */
  $handler = $view->new_display('page', 'LSA Pin', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Service Pin Applications';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    11 => '11',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'title' => 'title',
    'nothing' => 'nothing',
    'created' => 'created',
    'field_lsa_pin_ministry_org' => 'field_lsa_pin_ministry_org',
    'field_lsa_pin_employee_number' => 'field_lsa_pin_employee_number',
    'field_lsa_pin_first_name' => 'field_lsa_pin_first_name',
    'field_lsa_pin_last_name' => 'field_lsa_pin_last_name',
    'field_lsa_pin_service_milestone' => 'field_lsa_pin_service_milestone',
    'field_lsa_previous_service_miles' => 'field_lsa_previous_service_miles',
    'field_lsa_email' => 'field_lsa_email',
    'field_lsa_branch_department' => 'field_lsa_branch_department',
    'field_lsa_office_address' => 'field_lsa_office_address',
    'field_lsa_office_city' => 'field_lsa_office_city',
    'field_lsa_office_postal_code' => 'field_lsa_office_postal_code',
    'field_lsa_supervisor_first_name' => 'field_lsa_supervisor_first_name',
    'field_lsa_supervisor_last_name' => 'field_lsa_supervisor_last_name',
    'field_lsa_supervisor_email' => 'field_lsa_supervisor_email',
    'field_lsa_work_phone' => 'field_lsa_work_phone',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_pin_ministry_org' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_pin_employee_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_pin_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_pin_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_pin_service_milestone' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_previous_service_miles' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_branch_department' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_office_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_office_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_office_postal_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_supervisor_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_supervisor_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_supervisor_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_work_phone' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[delete_node] - [edit_node]';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: What ministry/organization are you with? */
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['id'] = 'field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['table'] = 'field_data_field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['field'] = 'field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['label'] = 'Ministry/Organization';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['id'] = 'field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['table'] = 'field_data_field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['field'] = 'field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['field_api_classes'] = TRUE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['id'] = 'field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['table'] = 'field_data_field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['field'] = 'field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['exclude'] = TRUE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['id'] = 'field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['table'] = 'field_data_field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['field'] = 'field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['exclude'] = TRUE;
  /* Field: Content: Service Milestone */
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['id'] = 'field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['table'] = 'field_data_field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['field'] = 'field_lsa_pin_service_milestone';
  /* Field: Content: Please select the retroactive milestone pin(s) you would like to order */
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['id'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['table'] = 'field_data_field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['field'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['label'] = 'Retroactive pin(s) ';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['delta_offset'] = '0';
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_lsa_email']['id'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['table'] = 'field_data_field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['field'] = 'field_lsa_email';
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['exclude'] = TRUE;
  /* Field: Content: Work Street Address */
  $handler->display->display_options['fields']['field_lsa_office_address']['id'] = 'field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['table'] = 'field_data_field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['field'] = 'field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['exclude'] = TRUE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_office_city']['id'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['field'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['exclude'] = TRUE;
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['id'] = 'field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['table'] = 'field_data_field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['field'] = 'field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['exclude'] = TRUE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['id'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['table'] = 'field_data_field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['field'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['exclude'] = TRUE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['id'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['table'] = 'field_data_field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['field'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['exclude'] = TRUE;
  /* Field: Content: Supervisor Email */
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['id'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['field'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['exclude'] = TRUE;
  /* Field: Content: Work Phone */
  $handler->display->display_options['fields']['field_lsa_work_phone']['id'] = 'field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['table'] = 'field_data_field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['field'] = 'field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_pin_application' => 'lsa_pin_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author (IDIR)';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Employee Number (field_lsa_pin_employee_number) */
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['id'] = 'field_lsa_pin_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['table'] = 'field_data_field_lsa_pin_employee_number';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['field'] = 'field_lsa_pin_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['operator_id'] = 'field_lsa_pin_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['label'] = 'Employee Number';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['operator'] = 'field_lsa_pin_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['identifier'] = 'field_lsa_pin_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['autocomplete_field'] = 'field_lsa_pin_employee_number';
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_employee_number_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: First Name (field_lsa_pin_first_name) */
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['id'] = 'field_lsa_pin_first_name_value';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['table'] = 'field_data_field_lsa_pin_first_name';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['field'] = 'field_lsa_pin_first_name_value';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['operator_id'] = 'field_lsa_pin_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['operator'] = 'field_lsa_pin_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['identifier'] = 'field_lsa_pin_first_name_value';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['autocomplete_field'] = 'field_lsa_pin_first_name';
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Last Name (field_lsa_pin_last_name) */
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['id'] = 'field_lsa_pin_last_name_value';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['table'] = 'field_data_field_lsa_pin_last_name';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['field'] = 'field_lsa_pin_last_name_value';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['operator_id'] = 'field_lsa_pin_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['operator'] = 'field_lsa_pin_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['identifier'] = 'field_lsa_pin_last_name_value';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['autocomplete_field'] = 'field_lsa_pin_last_name';
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: What ministry/organization are you with? (field_lsa_pin_ministry_org) */
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['id'] = 'field_lsa_pin_ministry_org_value';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['table'] = 'field_data_field_lsa_pin_ministry_org';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['field'] = 'field_lsa_pin_ministry_org_value';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['expose']['operator_id'] = 'field_lsa_pin_ministry_org_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['expose']['label'] = 'Ministry/Organization';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['expose']['operator'] = 'field_lsa_pin_ministry_org_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['expose']['identifier'] = 'field_lsa_pin_ministry_org_value';
  $handler->display->display_options['filters']['field_lsa_pin_ministry_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Service Milestone (field_lsa_pin_service_milestone) */
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['id'] = 'field_lsa_pin_service_milestone_value';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['table'] = 'field_data_field_lsa_pin_service_milestone';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['field'] = 'field_lsa_pin_service_milestone_value';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['expose']['operator_id'] = 'field_lsa_pin_service_milestone_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['expose']['label'] = 'Service Milestone';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['expose']['operator'] = 'field_lsa_pin_service_milestone_value_op';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['expose']['identifier'] = 'field_lsa_pin_service_milestone_value';
  $handler->display->display_options['filters']['field_lsa_pin_service_milestone_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  /* Filter criterion: Content: Supervisor Email (field_lsa_supervisor_email) */
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['id'] = 'field_lsa_supervisor_email_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['field'] = 'field_lsa_supervisor_email_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['operator_id'] = 'field_lsa_supervisor_email_email_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['label'] = 'Supervisor Email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['operator'] = 'field_lsa_supervisor_email_email_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['identifier'] = 'field_lsa_supervisor_email_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_field'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_email_email']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: First Name (field_lsa_supervisor_first_name) */
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['id'] = 'field_lsa_supervisor_first_name_value';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['table'] = 'field_data_field_lsa_supervisor_first_name';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['field'] = 'field_lsa_supervisor_first_name_value';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['operator_id'] = 'field_lsa_supervisor_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['label'] = 'Supervisor First Name';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['operator'] = 'field_lsa_supervisor_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['identifier'] = 'field_lsa_supervisor_first_name_value';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['autocomplete_field'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Last Name (field_lsa_supervisor_last_name) */
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['id'] = 'field_lsa_supervisor_last_name_value';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['table'] = 'field_data_field_lsa_supervisor_last_name';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['field'] = 'field_lsa_supervisor_last_name_value';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['operator_id'] = 'field_lsa_supervisor_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['label'] = 'Supervisor Last Name';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['operator'] = 'field_lsa_supervisor_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['identifier'] = 'field_lsa_supervisor_last_name_value';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['autocomplete_field'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_supervisor_last_name_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'administration/long-service-pin';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'lsa_pin_export');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Pin Export';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    11 => '11',
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Who is registering for this service pin? */
  $handler->display->display_options['fields']['field_lsa_registerer']['id'] = 'field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['table'] = 'field_data_field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['field'] = 'field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['label'] = 'Who is registering';
  $handler->display->display_options['fields']['field_lsa_registerer']['type'] = 'list_key';
  /* Field: Content: Ministry Representative Email */
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['id'] = 'field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['table'] = 'field_data_field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['field'] = 'field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['label'] = 'Ministry Rep Email';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Employee Name';
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['id'] = 'field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['table'] = 'field_data_field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['field'] = 'field_lsa_pin_employee_number';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['id'] = 'field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['table'] = 'field_data_field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['field'] = 'field_lsa_pin_first_name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['id'] = 'field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['table'] = 'field_data_field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['field'] = 'field_lsa_pin_last_name';
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_lsa_email']['id'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['table'] = 'field_data_field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['field'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['label'] = 'Employee Email';
  /* Field: Content: Are you celebrating a current service milestone in 2018? */
  $handler->display->display_options['fields']['field_lsa_milestone_year']['id'] = 'field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year']['table'] = 'field_data_field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year']['field'] = 'field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year']['label'] = 'Celebrating a current service milestone in 2017';
  /* Field: Content: Service Milestone */
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['id'] = 'field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['table'] = 'field_data_field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['field'] = 'field_lsa_pin_service_milestone';
  /* Field: Content: Do you wish to request any service pin(s) for any past milestones? */
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['id'] = 'field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['table'] = 'field_data_field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['field'] = 'field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['label'] = 'service pin(s) retroactively?';
  /* Field: Content: Please select the retroactive milestone pin(s) you would like to order */
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['id'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['table'] = 'field_data_field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['field'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['label'] = 'retroactive milestones';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['delta_offset'] = '0';
  /* Field: Content: What ministry/organization are you with? */
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['id'] = 'field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['table'] = 'field_data_field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['field'] = 'field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['label'] = 'ministry/organization';
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  /* Field: Content: Does your supervisor work in a different office location than you?  */
  $handler->display->display_options['fields']['field_lsa_pin_sup_location']['id'] = 'field_lsa_pin_sup_location';
  $handler->display->display_options['fields']['field_lsa_pin_sup_location']['table'] = 'field_data_field_lsa_pin_sup_location';
  $handler->display->display_options['fields']['field_lsa_pin_sup_location']['field'] = 'field_lsa_pin_sup_location';
  $handler->display->display_options['fields']['field_lsa_pin_sup_location']['label'] = ' supervisor work in a different office? ';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['id'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['table'] = 'field_data_field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['field'] = 'field_lsa_supervisor_first_name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['id'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['table'] = 'field_data_field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['field'] = 'field_lsa_supervisor_last_name';
  /* Field: Content: Work Street Address */
  $handler->display->display_options['fields']['field_lsa_office_address_1']['id'] = 'field_lsa_office_address_1';
  $handler->display->display_options['fields']['field_lsa_office_address_1']['table'] = 'field_data_field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address_1']['field'] = 'field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address_1']['label'] = 'Supervisor Street Address';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_office_city']['id'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['field'] = 'field_lsa_office_city';
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['id'] = 'field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['table'] = 'field_data_field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['field'] = 'field_lsa_office_postal_code';
  /* Field: Content: Supervisor Email */
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['id'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['field'] = 'field_lsa_supervisor_email';
  /* Field: Content: Work Phone */
  $handler->display->display_options['fields']['field_lsa_work_phone']['id'] = 'field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['table'] = 'field_data_field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['field'] = 'field_lsa_work_phone';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_pin_application' => 'lsa_pin_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
  );
  $handler->display->display_options['path'] = 'administration/long-service-pin/lsa-applications.csv';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'lsa' => 0,
    'block_user' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Status Updates';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['empty'] = 'Employee News';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'status' => 'status',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author (IDIR)';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Field: Email (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Display Name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['identifier'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['path'] = 'admin/status-updates';

  /* Display: Page: OG Stats */
  $handler = $view->new_display('page', 'Page: OG Stats', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'administer og menu';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'uid' => 'uid',
    'field_display_name' => 'field_display_name',
    'status' => 'status',
    'totalcount' => 'totalcount',
    'comment_count' => 'comment_count',
    'value' => 'value',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'totalcount' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="content_type_title">Group Statistics<h2>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote_thumbs_node',
    'function' => 'sum',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_display_name']['label'] = 'Author';
  $handler->display->display_options['fields']['field_display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['empty'] = 'Employee News';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'Reads';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Likes';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'event' => 'event',
    'gallery' => 'gallery',
    'section_page' => 'section_page',
    'article' => 'article',
    'poll' => 'poll',
    'question' => 'question',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'node/%/stats';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Group Stats';
  $handler->display->display_options['menu']['description'] = 'Administer group content';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['content'] = $view;

  $view = new view();
  $view->name = 'lsa_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'LSA Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LSA Admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    11 => '11',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_lsa_employee_number' => 'field_lsa_employee_number',
    'field_lsa_notes_editable' => 'field_lsa_notes_editable',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_employee_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_notes_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );

  /* Display: Page: LSA Admin */
  $handler = $view->new_display('page', 'Page: LSA Admin', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Retro-Active (editable) */
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['id'] = 'field_lsa_retro_active_editable';
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['table'] = 'field_data_field_lsa_retro_active';
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['field'] = 'field_lsa_retro_active_editable';
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['label'] = 'Retro-Active';
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_retro_active_editable']['suppress_description'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Award (field_lsa_award) */
  $handler->display->display_options['filters']['field_lsa_award_value']['id'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['field'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_award_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator_id'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['label'] = 'Award ';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['identifier'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_field'] = 'field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Award Year (field_lsa_award_year) */
  $handler->display->display_options['filters']['field_lsa_award_year_value']['id'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['field'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['operator_id'] = 'field_lsa_award_year_value_op';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['label'] = 'Award Year';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['operator'] = 'field_lsa_award_year_value_op';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['identifier'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Ministry/Organization (field_lsa_org) */
  $handler->display->display_options['filters']['field_lsa_org_value']['id'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['filters']['field_lsa_org_value']['field'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator_id'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['label'] = 'Ministry/Organization ';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['identifier'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Years of Service (field_lsa_years_of_service) */
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['id'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['field'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator_id'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['label'] = 'Years of Service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['identifier'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Retro-Active (field_lsa_retro_active) */
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['id'] = 'field_lsa_retro_active_value';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['table'] = 'field_data_field_lsa_retro_active';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['field'] = 'field_lsa_retro_active_value';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['operator_id'] = 'field_lsa_retro_active_value_op';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['label'] = 'Retro-Active';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['operator'] = 'field_lsa_retro_active_value_op';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['identifier'] = 'field_lsa_retro_active_value';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin';
  $handler->display->display_options['menu']['title'] = 'LSA Admin';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-lsa-admin';

  /* Display: Page:LSA Admin Tab */
  $handler = $view->new_display('page', 'Page:LSA Admin Tab', 'page_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'lsa-admin/lsa-admin';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LSA Admin';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page:LSA Ceremony */
  $handler = $view->new_display('page', 'Page:LSA Ceremony', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Ceremony';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_lsa_attending_ceremony_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_lsa_branch_department_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_lsa_office_city_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_lsa_org_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'keys' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_lsa_award_year' => 'field_lsa_award_year',
    'field_lsa_org' => 'field_lsa_org',
    'field_lsa_branch_department' => 'field_lsa_branch_department',
    'field_lsa_office_work_group' => 'field_lsa_office_work_group',
    'field_lsa_office_city' => 'field_lsa_office_city',
    'field_lsa_attending_ceremony' => 'field_lsa_attending_ceremony',
    'field_lsa_ceremonydate_editable' => 'field_lsa_ceremonydate_editable',
    'field_lsa_ceremony_night_editable' => 'field_lsa_ceremony_night_editable',
    'field_lsa_notes_ceremony_editable' => 'field_lsa_notes_ceremony_editable',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_award_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_org' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_branch_department' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_office_work_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_office_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_attending_ceremony' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ceremonydate_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ceremony_night_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_notes_ceremony_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_lsa_office_work_group']['id'] = 'field_lsa_office_work_group';
  $handler->display->display_options['fields']['field_lsa_office_work_group']['table'] = 'field_data_field_lsa_office_work_group';
  $handler->display->display_options['fields']['field_lsa_office_work_group']['field'] = 'field_lsa_office_work_group';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_office_city']['id'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['field'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['label'] = 'Office City';
  /* Field: Content: RSVP */
  $handler->display->display_options['fields']['field_lsa_rsvp']['id'] = 'field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['field'] = 'field_lsa_rsvp';
  /* Field: Content: Attending Ceremony */
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['id'] = 'field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['field'] = 'field_lsa_attending_ceremony';
  /* Field: Content: Ceremony Date (editable) */
  $handler->display->display_options['fields']['field_lsa_ceremonydate_editable']['id'] = 'field_lsa_ceremonydate_editable';
  $handler->display->display_options['fields']['field_lsa_ceremonydate_editable']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate_editable']['field'] = 'field_lsa_ceremonydate_editable';
  $handler->display->display_options['fields']['field_lsa_ceremonydate_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_ceremonydate_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_ceremonydate_editable']['suppress_description'] = 0;
  /* Field: Content: Ceremony Night (editable) */
  $handler->display->display_options['fields']['field_lsa_ceremony_night_editable']['id'] = 'field_lsa_ceremony_night_editable';
  $handler->display->display_options['fields']['field_lsa_ceremony_night_editable']['table'] = 'field_data_field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night_editable']['field'] = 'field_lsa_ceremony_night_editable';
  $handler->display->display_options['fields']['field_lsa_ceremony_night_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_ceremony_night_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_ceremony_night_editable']['suppress_description'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Attending Ceremony (field_lsa_attending_ceremony) */
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['id'] = 'field_lsa_attending_ceremony_value';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['field'] = 'field_lsa_attending_ceremony_value';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['operator_id'] = 'field_lsa_attending_ceremony_value_op';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['label'] = 'Attending Ceremony ';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['operator'] = 'field_lsa_attending_ceremony_value_op';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['identifier'] = 'field_lsa_attending_ceremony_value';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Branch (field_lsa_branch_department) */
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['id'] = 'field_lsa_branch_department_value';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['field'] = 'field_lsa_branch_department_value';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['operator_id'] = 'field_lsa_branch_department_value_op';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['label'] = 'Branch/Department ';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['operator'] = 'field_lsa_branch_department_value_op';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['identifier'] = 'field_lsa_branch_department_value';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_field'] = 'field_lsa_branch_department';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: City (field_lsa_office_city) */
  $handler->display->display_options['filters']['field_lsa_office_city_value']['id'] = 'field_lsa_office_city_value';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['field'] = 'field_lsa_office_city_value';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['operator_id'] = 'field_lsa_office_city_value_op';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['label'] = 'Office City';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['operator'] = 'field_lsa_office_city_value_op';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['identifier'] = 'field_lsa_office_city_value';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_field'] = 'field_lsa_office_city';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Ministry/Organization (field_lsa_org) */
  $handler->display->display_options['filters']['field_lsa_org_value']['id'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['filters']['field_lsa_org_value']['field'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator_id'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['label'] = 'Ministry/Organization ';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['identifier'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: RSVP (field_lsa_rsvp) */
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['id'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['field'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator_id'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['label'] = 'RSVP';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['identifier'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'lsa-admin/ceremony';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Ceremony';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: LSA Notes */
  $handler = $view->new_display('page', 'LSA Notes', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Notes';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Content: Notes (editable) */
  $handler->display->display_options['fields']['field_lsa_notes_editable']['id'] = 'field_lsa_notes_editable';
  $handler->display->display_options['fields']['field_lsa_notes_editable']['table'] = 'field_data_field_lsa_notes';
  $handler->display->display_options['fields']['field_lsa_notes_editable']['field'] = 'field_lsa_notes_editable';
  $handler->display->display_options['fields']['field_lsa_notes_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_notes_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_notes_editable']['suppress_description'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Employee Number (field_lsa_employee_number) */
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['id'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['field'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator_id'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['label'] = 'Employee Number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['identifier'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_field'] = 'field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Notes (field_lsa_notes) */
  $handler->display->display_options['filters']['field_lsa_notes_value']['id'] = 'field_lsa_notes_value';
  $handler->display->display_options['filters']['field_lsa_notes_value']['table'] = 'field_data_field_lsa_notes';
  $handler->display->display_options['filters']['field_lsa_notes_value']['field'] = 'field_lsa_notes_value';
  $handler->display->display_options['filters']['field_lsa_notes_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_lsa_notes_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['operator_id'] = 'field_lsa_notes_value_op';
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['label'] = 'Notes (field_lsa_notes)';
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['operator'] = 'field_lsa_notes_value_op';
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['identifier'] = 'field_lsa_notes_value';
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['autocomplete_field'] = 'field_lsa_notes_editable';
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_notes_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'lsa-admin/notes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Notes';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: LSA Engravement */
  $handler = $view->new_display('page', 'LSA Engravement', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Engravement';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_lsa_award_year' => 'field_lsa_award_year',
    'field_lsa_years_of_service' => 'field_lsa_years_of_service',
    'field_lsa_award' => 'field_lsa_award',
    'field_lsa_award_id' => 'field_lsa_award_id',
    'field_lsa_engravement' => 'field_lsa_engravement',
    'field_lsa_engravement_editable' => 'field_lsa_engravement_editable',
    'field_lsa_watch_engraving_sent_editable' => 'field_lsa_watch_engraving_sent_editable',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_award_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_years_of_service' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_award' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_award_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_engravement' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_engravement_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_watch_engraving_sent_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Engravement (editable) */
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['id'] = 'field_lsa_engravement_editable';
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['table'] = 'field_data_field_lsa_engravement';
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['field'] = 'field_lsa_engravement_editable';
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['label'] = 'Engravement';
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_lsa_engravement_editable']['suppress_description'] = 1;
  /* Field: Content: Watch Engraving Sent (editable) */
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['id'] = 'field_lsa_watch_engraving_sent_editable';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['table'] = 'field_data_field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['field'] = 'field_lsa_watch_engraving_sent_editable';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['label'] = 'Watch Engraving Sent ';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent_editable']['suppress_description'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: RSVP */
  $handler->display->display_options['fields']['field_lsa_rsvp']['id'] = 'field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['field'] = 'field_lsa_rsvp';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Years of Service (field_lsa_years_of_service) */
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['id'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['field'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator_id'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['label'] = 'Years of Service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['identifier'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Award (field_lsa_award) */
  $handler->display->display_options['filters']['field_lsa_award_value']['id'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['field'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_award_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator_id'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['label'] = 'Award ';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['identifier'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_field'] = 'field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Award ID (field_lsa_award_id) */
  $handler->display->display_options['filters']['field_lsa_award_id_value']['id'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['field'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['operator_id'] = 'field_lsa_award_id_value_op';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['label'] = 'Award ID';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['operator'] = 'field_lsa_award_id_value_op';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['identifier'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Award (field_lsa_award) */
  $handler->display->display_options['filters']['field_lsa_award_value_1']['id'] = 'field_lsa_award_value_1';
  $handler->display->display_options['filters']['field_lsa_award_value_1']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value_1']['field'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_award_value_1']['value'] = 'Watch';
  /* Filter criterion: Content: RSVP (field_lsa_rsvp) */
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['id'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['field'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator_id'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['label'] = 'RSVP ';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['identifier'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin/engravement';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Engravement';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: LSA 25 Year Certificate */
  $handler = $view->new_display('page', 'LSA 25 Year Certificate', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA 25 Year Certificate';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Certificate Name (editable) */
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['id'] = 'field_lsa_25year_certificatename_editable';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['table'] = 'field_data_field_lsa_25year_certificatename';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['field'] = 'field_lsa_25year_certificatename_editable';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['label'] = '25 Year Certificate';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_lsa_25year_certificatename_editable']['suppress_description'] = 1;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_first_name']['id'] = 'field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['field'] = 'field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_last_name']['id'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['field'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Employee Number (field_lsa_employee_number) */
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['id'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['field'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator_id'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['label'] = 'Employee Number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['identifier'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_field'] = 'field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Years of Service (field_lsa_years_of_service) */
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['id'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['field'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['value'] = array(
    25 => '25',
  );
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['group'] = 1;
  /* Filter criterion: Content: Award Year (field_lsa_award_year) */
  $handler->display->display_options['filters']['field_lsa_award_year_value']['id'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['field'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: First Name (field_lsa_first_name) */
  $handler->display->display_options['filters']['field_lsa_first_name_value']['id'] = 'field_lsa_first_name_value';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['field'] = 'field_lsa_first_name_value';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['operator_id'] = 'field_lsa_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['operator'] = 'field_lsa_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['identifier'] = 'field_lsa_first_name_value';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_field'] = 'field_lsa_first_name';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Last Name (field_lsa_last_name) */
  $handler->display->display_options['filters']['field_lsa_last_name_value']['id'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['field'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['operator_id'] = 'field_lsa_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['label'] = 'Last Name ';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['operator'] = 'field_lsa_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['identifier'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_field'] = 'field_lsa_last_name';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'lsa-admin/25-year-certificate';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Certificates';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: LSA Special Requirements */
  $handler = $view->new_display('page', 'LSA Special Requirements', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Special Requirements';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_lsa_specialrequirements_editable']['id'] = 'field_lsa_specialrequirements_editable';
  $handler->display->display_options['fields']['field_lsa_specialrequirements_editable']['table'] = 'field_data_field_lsa_specialrequirements';
  $handler->display->display_options['fields']['field_lsa_specialrequirements_editable']['field'] = 'field_lsa_specialrequirements_editable';
  $handler->display->display_options['fields']['field_lsa_specialrequirements_editable']['label'] = 'Special Requirements';
  /* Field: Content: Please Specify Your Requirements (editable) */
  $handler->display->display_options['fields']['field_specialrequirement_descrip_editable']['id'] = 'field_specialrequirement_descrip_editable';
  $handler->display->display_options['fields']['field_specialrequirement_descrip_editable']['table'] = 'field_data_field_specialrequirement_descrip';
  $handler->display->display_options['fields']['field_specialrequirement_descrip_editable']['field'] = 'field_specialrequirement_descrip_editable';
  $handler->display->display_options['fields']['field_specialrequirement_descrip_editable']['label'] = 'Please Specify Your Requirements ';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Employee Number (field_lsa_employee_number) */
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['id'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['field'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator_id'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['label'] = 'Employee Number ';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['identifier'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_field'] = 'field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['id'] = 'field_lsa_specialrequirements_value';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['table'] = 'field_data_field_lsa_specialrequirements';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['field'] = 'field_lsa_specialrequirements_value';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['value'] = array(
    6 => '6',
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['expose']['operator_id'] = 'field_lsa_specialrequirements_value_op';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['expose']['label'] = 'Special Requirements';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['expose']['operator'] = 'field_lsa_specialrequirements_value_op';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['expose']['identifier'] = 'field_lsa_specialrequirements_value';
  $handler->display->display_options['filters']['field_lsa_specialrequirements_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin/special-requirements';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Special Requirements';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Multi-Record Update */
  $handler = $view->new_display('page', 'Multi-Record Update', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Multi-Record Update';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_lsa_years_of_service' => 'field_lsa_years_of_service',
    'field_lsa_org' => 'field_lsa_org',
    'field_lsa_ministry_id' => 'field_lsa_ministry_id',
    'field_lsa_branch_department' => 'field_lsa_branch_department',
    'field_lsa_office_city' => 'field_lsa_office_city',
    'field_lsa_rsvp' => 'field_lsa_rsvp',
    'field_lsa_attending_ceremony' => 'field_lsa_attending_ceremony',
    'field_lsa_ceremonydate' => 'field_lsa_ceremonydate',
    'field_lsa_ceremony_night' => 'field_lsa_ceremony_night',
    'field_lsa_last_name' => 'field_lsa_last_name',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_years_of_service' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_org' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ministry_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_branch_department' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_office_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_rsvp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_attending_ceremony' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ceremonydate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ceremony_night' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['element_type'] = 'div';
  $handler->display->display_options['fields']['views_bulk_operations']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'lsa_application::field_lsa_org' => 'lsa_application::field_lsa_org',
          'lsa_application::field_lsa_ministry_id' => 'lsa_application::field_lsa_ministry_id',
          'lsa_application::field_lsa_invitation_sent' => 'lsa_application::field_lsa_invitation_sent',
          'lsa_application::field_lsa_ceremonydate' => 'lsa_application::field_lsa_ceremonydate',
          'lsa_application::field_lsa_watch_engraving_sent' => 'lsa_application::field_lsa_watch_engraving_sent',
          'lsa_application::field_lsa_ceremony_night' => 'lsa_application::field_lsa_ceremony_night',
          'lsa_application::field_lsa_retro_active' => 'lsa_application::field_lsa_retro_active',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: Ministry ID */
  $handler->display->display_options['fields']['field_lsa_ministry_id']['id'] = 'field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['table'] = 'field_data_field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['field'] = 'field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_office_city']['id'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['field'] = 'field_lsa_office_city';
  /* Field: Content: RSVP */
  $handler->display->display_options['fields']['field_lsa_rsvp']['id'] = 'field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['field'] = 'field_lsa_rsvp';
  /* Field: Content: Attending Ceremony */
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['id'] = 'field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['field'] = 'field_lsa_attending_ceremony';
  /* Field: Content: Ceremony Date */
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['id'] = 'field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['field'] = 'field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['element_label_colon'] = FALSE;
  /* Field: Content: Ceremony Night */
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['id'] = 'field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['table'] = 'field_data_field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['field'] = 'field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_last_name']['id'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['field'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['element_label_colon'] = FALSE;
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Ministry/Organization (field_lsa_org) */
  $handler->display->display_options['filters']['field_lsa_org_value']['id'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['filters']['field_lsa_org_value']['field'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator_id'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['label'] = 'Ministry/Organization';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['identifier'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Ministry ID (field_lsa_ministry_id) */
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['id'] = 'field_lsa_ministry_id_value';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['table'] = 'field_data_field_lsa_ministry_id';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['field'] = 'field_lsa_ministry_id_value';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['expose']['operator_id'] = 'field_lsa_ministry_id_value_op';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['expose']['label'] = 'Ministry ID ';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['expose']['operator'] = 'field_lsa_ministry_id_value_op';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['expose']['identifier'] = 'field_lsa_ministry_id_value';
  $handler->display->display_options['filters']['field_lsa_ministry_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Branch (field_lsa_branch_department) */
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['id'] = 'field_lsa_branch_department_value';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['field'] = 'field_lsa_branch_department_value';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['operator_id'] = 'field_lsa_branch_department_value_op';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['label'] = 'Branch/Department';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['operator'] = 'field_lsa_branch_department_value_op';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['identifier'] = 'field_lsa_branch_department_value';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_field'] = 'field_lsa_branch_department';
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_branch_department_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: City (field_lsa_office_city) */
  $handler->display->display_options['filters']['field_lsa_office_city_value']['id'] = 'field_lsa_office_city_value';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['field'] = 'field_lsa_office_city_value';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['operator_id'] = 'field_lsa_office_city_value_op';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['label'] = 'Office City';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['operator'] = 'field_lsa_office_city_value_op';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['identifier'] = 'field_lsa_office_city_value';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_field'] = 'field_lsa_office_city';
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_office_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Years of Service (field_lsa_years_of_service) */
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['id'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['field'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator_id'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['label'] = 'Years of Service ';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['operator'] = 'field_lsa_years_of_service_value_op';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['identifier'] = 'field_lsa_years_of_service_value';
  $handler->display->display_options['filters']['field_lsa_years_of_service_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Award Year (field_lsa_award_year) */
  $handler->display->display_options['filters']['field_lsa_award_year_value']['id'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['field'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['operator_id'] = 'field_lsa_award_year_value_op';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['label'] = 'Award Year';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['operator'] = 'field_lsa_award_year_value_op';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['identifier'] = 'field_lsa_award_year_value';
  $handler->display->display_options['filters']['field_lsa_award_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Attending Ceremony (field_lsa_attending_ceremony) */
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['id'] = 'field_lsa_attending_ceremony_value';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['field'] = 'field_lsa_attending_ceremony_value';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['operator_id'] = 'field_lsa_attending_ceremony_value_op';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['label'] = 'Attending Ceremony ';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['operator'] = 'field_lsa_attending_ceremony_value_op';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['identifier'] = 'field_lsa_attending_ceremony_value';
  $handler->display->display_options['filters']['field_lsa_attending_ceremony_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: RSVP (field_lsa_rsvp) */
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['id'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['field'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator_id'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['label'] = 'RSVP';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['identifier'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Last Name (field_lsa_last_name) */
  $handler->display->display_options['filters']['field_lsa_last_name_value']['id'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['field'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['operator_id'] = 'field_lsa_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['label'] = 'Last Name (field_lsa_last_name)';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['operator'] = 'field_lsa_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['identifier'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_field'] = 'field_lsa_last_name';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Ceremony Date (field_lsa_ceremonydate) */
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['id'] = 'field_lsa_ceremonydate_value';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['field'] = 'field_lsa_ceremonydate_value';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['operator_id'] = 'field_lsa_ceremonydate_value_op';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['label'] = 'Ceremony Date ';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['operator'] = 'field_lsa_ceremonydate_value_op';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['identifier'] = 'field_lsa_ceremonydate_value';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Award (field_lsa_award) */
  $handler->display->display_options['filters']['field_lsa_award_value']['id'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['field'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_award_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator_id'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['label'] = 'Award';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['identifier'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_field'] = 'field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Award ID (field_lsa_award_id) */
  $handler->display->display_options['filters']['field_lsa_award_id_value']['id'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['field'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['operator_id'] = 'field_lsa_award_id_value_op';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['label'] = 'Award ID';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['operator'] = 'field_lsa_award_id_value_op';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['identifier'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin/multi-record-update';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Multi-Record Update';
  $handler->display->display_options['menu']['weight'] = '7';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'lsa_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Export';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Content yet';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Content: Retiring in 2018? */
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['id'] = 'field_lsa_retiring_thisyear';
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['table'] = 'field_data_field_lsa_retiring_thisyear';
  $handler->display->display_options['fields']['field_lsa_retiring_thisyear']['field'] = 'field_lsa_retiring_thisyear';
  /* Field: Content: Date of Retirement */
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['id'] = 'field_lsa_date_of_retirement';
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['table'] = 'field_data_field_lsa_date_of_retirement';
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['field'] = 'field_lsa_date_of_retirement';
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_date_of_retirement']['settings'] = array(
    'format_type' => 'lsa_export_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Did you register last year but were unable to attend the ceremony? */
  $handler->display->display_options['fields']['field_lsa_register_last_year']['id'] = 'field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['table'] = 'field_data_field_lsa_register_last_year';
  $handler->display->display_options['fields']['field_lsa_register_last_year']['field'] = 'field_lsa_register_last_year';
  /* Field: Content: Did you receive your award? */
  $handler->display->display_options['fields']['field_lsa_received_award']['id'] = 'field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['table'] = 'field_data_field_lsa_received_award';
  $handler->display->display_options['fields']['field_lsa_received_award']['field'] = 'field_lsa_received_award';
  /* Field: Content: Award Year */
  $handler->display->display_options['fields']['field_lsa_award_year']['id'] = 'field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['table'] = 'field_data_field_lsa_award_year';
  $handler->display->display_options['fields']['field_lsa_award_year']['field'] = 'field_lsa_award_year';
  /* Field: Content: Award ID */
  $handler->display->display_options['fields']['field_lsa_award_id']['id'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['field'] = 'field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award */
  $handler->display->display_options['fields']['field_lsa_award']['id'] = 'field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award']['field'] = 'field_lsa_award';
  /* Field: Content: Certificate Name */
  $handler->display->display_options['fields']['field_lsa_25year_certificatename']['id'] = 'field_lsa_25year_certificatename';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename']['table'] = 'field_data_field_lsa_25year_certificatename';
  $handler->display->display_options['fields']['field_lsa_25year_certificatename']['field'] = 'field_lsa_25year_certificatename';
  /* Field: Content: Engravement */
  $handler->display->display_options['fields']['field_lsa_engravement']['id'] = 'field_lsa_engravement';
  $handler->display->display_options['fields']['field_lsa_engravement']['table'] = 'field_data_field_lsa_engravement';
  $handler->display->display_options['fields']['field_lsa_engravement']['field'] = 'field_lsa_engravement';
  /* Field: Content: Watch Engraving Sent */
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['id'] = 'field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['table'] = 'field_data_field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['field'] = 'field_lsa_watch_engraving_sent';
  $handler->display->display_options['fields']['field_lsa_watch_engraving_sent']['settings'] = array(
    'format_type' => 'lsa_export_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Award Special Instructions */
  $handler->display->display_options['fields']['field_lsa_award_sp_instructions']['id'] = 'field_lsa_award_sp_instructions';
  $handler->display->display_options['fields']['field_lsa_award_sp_instructions']['table'] = 'field_data_field_lsa_award_sp_instructions';
  $handler->display->display_options['fields']['field_lsa_award_sp_instructions']['field'] = 'field_lsa_award_sp_instructions';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_first_name']['id'] = 'field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['field'] = 'field_lsa_first_name';
  /* Field: Content: Middle Name */
  $handler->display->display_options['fields']['field_lsa_middle_name']['id'] = 'field_lsa_middle_name';
  $handler->display->display_options['fields']['field_lsa_middle_name']['table'] = 'field_data_field_lsa_middle_name';
  $handler->display->display_options['fields']['field_lsa_middle_name']['field'] = 'field_lsa_middle_name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_last_name']['id'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['field'] = 'field_lsa_last_name';
  /* Field: Content: Street */
  $handler->display->display_options['fields']['field_lsa_street']['id'] = 'field_lsa_street';
  $handler->display->display_options['fields']['field_lsa_street']['table'] = 'field_data_field_lsa_street';
  $handler->display->display_options['fields']['field_lsa_street']['field'] = 'field_lsa_street';
  $handler->display->display_options['fields']['field_lsa_street']['label'] = 'Home_Address';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_city']['id'] = 'field_lsa_city';
  $handler->display->display_options['fields']['field_lsa_city']['table'] = 'field_data_field_lsa_city';
  $handler->display->display_options['fields']['field_lsa_city']['field'] = 'field_lsa_city';
  $handler->display->display_options['fields']['field_lsa_city']['label'] = 'Home_City';
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['id'] = 'field_lsa_home_postal_code';
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['table'] = 'field_data_field_lsa_home_postal_code';
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['field'] = 'field_lsa_home_postal_code';
  $handler->display->display_options['fields']['field_lsa_home_postal_code']['label'] = 'Home_Postal';
  /* Field: Content: Province */
  $handler->display->display_options['fields']['field_lsa_home_province']['id'] = 'field_lsa_home_province';
  $handler->display->display_options['fields']['field_lsa_home_province']['table'] = 'field_data_field_lsa_home_province';
  $handler->display->display_options['fields']['field_lsa_home_province']['field'] = 'field_lsa_home_province';
  /* Field: Content: Alternate Email Address */
  $handler->display->display_options['fields']['field_lsa_alt_email_address']['id'] = 'field_lsa_alt_email_address';
  $handler->display->display_options['fields']['field_lsa_alt_email_address']['table'] = 'field_data_field_lsa_alt_email_address';
  $handler->display->display_options['fields']['field_lsa_alt_email_address']['field'] = 'field_lsa_alt_email_address';
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_lsa_email']['id'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['table'] = 'field_data_field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['field'] = 'field_lsa_email';
  /* Field: Content: Home Phone */
  $handler->display->display_options['fields']['field_lsa_home_phone']['id'] = 'field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['table'] = 'field_data_field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['field'] = 'field_lsa_home_phone';
  /* Field: Content: Work Phone */
  $handler->display->display_options['fields']['field_lsa_work_phone']['id'] = 'field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['table'] = 'field_data_field_lsa_work_phone';
  $handler->display->display_options['fields']['field_lsa_work_phone']['field'] = 'field_lsa_work_phone';
  /* Field: Content: Work Phone Extension */
  $handler->display->display_options['fields']['field_lsa_work_phone_ext']['id'] = 'field_lsa_work_phone_ext';
  $handler->display->display_options['fields']['field_lsa_work_phone_ext']['table'] = 'field_data_field_lsa_work_phone_ext';
  $handler->display->display_options['fields']['field_lsa_work_phone_ext']['field'] = 'field_lsa_work_phone_ext';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: Ministry ID */
  $handler->display->display_options['fields']['field_lsa_ministry_id']['id'] = 'field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['table'] = 'field_data_field_lsa_ministry_id';
  $handler->display->display_options['fields']['field_lsa_ministry_id']['field'] = 'field_lsa_ministry_id';
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
  /* Field: Content: Work Street Address */
  $handler->display->display_options['fields']['field_lsa_office_address']['id'] = 'field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['table'] = 'field_data_field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['field'] = 'field_lsa_office_address';
  $handler->display->display_options['fields']['field_lsa_office_address']['label'] = 'Office_Address';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_lsa_office_city']['id'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['table'] = 'field_data_field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['field'] = 'field_lsa_office_city';
  $handler->display->display_options['fields']['field_lsa_office_city']['label'] = 'Office_City';
  /* Field: Content: Province */
  $handler->display->display_options['fields']['field_lsa_office_province']['id'] = 'field_lsa_office_province';
  $handler->display->display_options['fields']['field_lsa_office_province']['table'] = 'field_data_field_lsa_office_province';
  $handler->display->display_options['fields']['field_lsa_office_province']['field'] = 'field_lsa_office_province';
  $handler->display->display_options['fields']['field_lsa_office_province']['label'] = 'Office_Province';
  /* Field: Content: Postal Code */
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['id'] = 'field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['table'] = 'field_data_field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['field'] = 'field_lsa_office_postal_code';
  $handler->display->display_options['fields']['field_lsa_office_postal_code']['label'] = 'Office_Postal';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['id'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['table'] = 'field_data_field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['field'] = 'field_lsa_supervisor_first_name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['id'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['table'] = 'field_data_field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['field'] = 'field_lsa_supervisor_last_name';
  /* Field: Content: Supervisor Email */
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['id'] = 'field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['table'] = 'field_data_field_lsa_supervisor_email';
  $handler->display->display_options['fields']['field_lsa_supervisor_email']['field'] = 'field_lsa_supervisor_email';
  /* Field: Content: Notes */
  $handler->display->display_options['fields']['field_lsa_notes']['id'] = 'field_lsa_notes';
  $handler->display->display_options['fields']['field_lsa_notes']['table'] = 'field_data_field_lsa_notes';
  $handler->display->display_options['fields']['field_lsa_notes']['field'] = 'field_lsa_notes';
  /* Field: Content: RSVP */
  $handler->display->display_options['fields']['field_lsa_rsvp']['id'] = 'field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['field'] = 'field_lsa_rsvp';
  /* Field: Content: Attending Ceremony */
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['id'] = 'field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony']['field'] = 'field_lsa_attending_ceremony';
  /* Field: Content: Guest Attending */
  $handler->display->display_options['fields']['field_lsa_guest']['id'] = 'field_lsa_guest';
  $handler->display->display_options['fields']['field_lsa_guest']['table'] = 'field_data_field_lsa_guest';
  $handler->display->display_options['fields']['field_lsa_guest']['field'] = 'field_lsa_guest';
  /* Field: Content: Number Attending */
  $handler->display->display_options['fields']['field_lsa_number_attending']['id'] = 'field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['table'] = 'field_data_field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['field'] = 'field_lsa_number_attending';
  /* Field: Content: Invitation Send Date */
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['id'] = 'field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['table'] = 'field_data_field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['field'] = 'field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['settings'] = array(
    'format_type' => 'lsa_export_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Attending with alternate Min/Org */
  $handler->display->display_options['fields']['field_lsa_alternate_min_org']['id'] = 'field_lsa_alternate_min_org';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org']['table'] = 'field_data_field_lsa_alternate_min_org';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org']['field'] = 'field_lsa_alternate_min_org';
  /* Field: Content: Actual_Min/Org */
  $handler->display->display_options['fields']['field_lsa_actual_min_org']['id'] = 'field_lsa_actual_min_org';
  $handler->display->display_options['fields']['field_lsa_actual_min_org']['table'] = 'field_data_field_lsa_actual_min_org';
  $handler->display->display_options['fields']['field_lsa_actual_min_org']['field'] = 'field_lsa_actual_min_org';
  /* Field: Content: Ceremony Date */
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['id'] = 'field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['field'] = 'field_lsa_ceremonydate';
  /* Field: Content: Ceremony Night */
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['id'] = 'field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['table'] = 'field_data_field_lsa_ceremony_night';
  $handler->display->display_options['fields']['field_lsa_ceremony_night']['field'] = 'field_lsa_ceremony_night';
  /* Field: Content: Retro-Active */
  $handler->display->display_options['fields']['field_lsa_retro_active']['id'] = 'field_lsa_retro_active';
  $handler->display->display_options['fields']['field_lsa_retro_active']['table'] = 'field_data_field_lsa_retro_active';
  $handler->display->display_options['fields']['field_lsa_retro_active']['field'] = 'field_lsa_retro_active';
  /* Field: Content: Certificate Ordered */
  $handler->display->display_options['fields']['field_lsa_certificate_ordered']['id'] = 'field_lsa_certificate_ordered';
  $handler->display->display_options['fields']['field_lsa_certificate_ordered']['table'] = 'field_data_field_lsa_certificate_ordered';
  $handler->display->display_options['fields']['field_lsa_certificate_ordered']['field'] = 'field_lsa_certificate_ordered';
  /* Field: Content: Donation options */
  $handler->display->display_options['fields']['field_lsa_donation_options']['id'] = 'field_lsa_donation_options';
  $handler->display->display_options['fields']['field_lsa_donation_options']['table'] = 'field_data_field_lsa_donation_options';
  $handler->display->display_options['fields']['field_lsa_donation_options']['field'] = 'field_lsa_donation_options';
  $handler->display->display_options['fields']['field_lsa_donation_options']['label'] = 'Donation_Option';
  /* Field: Content: PECSF Region */
  $handler->display->display_options['fields']['field_lsa_pecsf_region']['id'] = 'field_lsa_pecsf_region';
  $handler->display->display_options['fields']['field_lsa_pecsf_region']['table'] = 'field_data_field_lsa_pecsf_region';
  $handler->display->display_options['fields']['field_lsa_pecsf_region']['field'] = 'field_lsa_pecsf_region';
  $handler->display->display_options['fields']['field_lsa_pecsf_region']['label'] = 'PECSF_Region';
  /* Field: Content: Charity Name */
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name']['id'] = 'field_lsa_pecsf_charity_name';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name']['table'] = 'field_data_field_lsa_pecsf_charity_name';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name']['field'] = 'field_lsa_pecsf_charity_name';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name']['label'] = 'PECSF_Charity_Name';
  /* Field: Content: PECSF ID */
  $handler->display->display_options['fields']['field_lsa_pecsf_id']['id'] = 'field_lsa_pecsf_id';
  $handler->display->display_options['fields']['field_lsa_pecsf_id']['table'] = 'field_data_field_lsa_pecsf_id';
  $handler->display->display_options['fields']['field_lsa_pecsf_id']['field'] = 'field_lsa_pecsf_id';
  $handler->display->display_options['fields']['field_lsa_pecsf_id']['label'] = 'PECSF_Charity_ID';
  /* Field: Content: Donation Amount */
  $handler->display->display_options['fields']['field_lsa_donation_amount']['id'] = 'field_lsa_donation_amount';
  $handler->display->display_options['fields']['field_lsa_donation_amount']['table'] = 'field_data_field_lsa_donation_amount';
  $handler->display->display_options['fields']['field_lsa_donation_amount']['field'] = 'field_lsa_donation_amount';
  $handler->display->display_options['fields']['field_lsa_donation_amount']['label'] = 'Donation_Amount';
  /* Field: Content: Second Charity */
  $handler->display->display_options['fields']['field_lsa_second_donation']['id'] = 'field_lsa_second_donation';
  $handler->display->display_options['fields']['field_lsa_second_donation']['table'] = 'field_data_field_lsa_second_donation';
  $handler->display->display_options['fields']['field_lsa_second_donation']['field'] = 'field_lsa_second_donation';
  $handler->display->display_options['fields']['field_lsa_second_donation']['label'] = 'Second_Charity_Selected';
  /* Field: Content: Charity Name 2 */
  $handler->display->display_options['fields']['field_lsa_charity_name_2']['id'] = 'field_lsa_charity_name_2';
  $handler->display->display_options['fields']['field_lsa_charity_name_2']['table'] = 'field_data_field_lsa_charity_name_2';
  $handler->display->display_options['fields']['field_lsa_charity_name_2']['field'] = 'field_lsa_charity_name_2';
  $handler->display->display_options['fields']['field_lsa_charity_name_2']['label'] = 'Second_Charity_Name';
  /* Field: Content: PECSF ID 2 */
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2']['id'] = 'field_lsa_pecsf_id_2';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2']['table'] = 'field_data_field_lsa_pecsf_id_2';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2']['field'] = 'field_lsa_pecsf_id_2';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2']['label'] = 'Second_Charity_ID';
  /* Field: Content: Donation Amount 2 */
  $handler->display->display_options['fields']['field_lsa_donation_amount_2']['id'] = 'field_lsa_donation_amount_2';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2']['table'] = 'field_data_field_lsa_donation_amount_2';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2']['field'] = 'field_lsa_donation_amount_2';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2']['label'] = 'Donation_Amount_Charity2';
  /* Field: Content: <em>I do <u>not</u> wish to take part in the Long Service Awards survey.</em> */
  $handler->display->display_options['fields']['field_lsa_survey']['id'] = 'field_lsa_survey';
  $handler->display->display_options['fields']['field_lsa_survey']['table'] = 'field_data_field_lsa_survey';
  $handler->display->display_options['fields']['field_lsa_survey']['field'] = 'field_lsa_survey';
  $handler->display->display_options['fields']['field_lsa_survey']['label'] = 'LSA_Survey';
  $handler->display->display_options['fields']['field_lsa_survey']['type'] = 'list_key';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['path'] = 'lsa-admin/export.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'page_3' => 'page_3',
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
    'page_4' => 0,
    'page_5' => 0,
    'page_6' => 0,
    'page_7' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: LSA Email */
  $handler = $view->new_display('page', 'LSA Email', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Email';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_lsa_ceremonydate' => 'field_lsa_ceremonydate',
    'field_lsa_org' => 'field_lsa_org',
    'field_lsa_rsvp' => 'field_lsa_rsvp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ceremonydate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_org' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_rsvp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select to send Email.';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '30';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::mimemail_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Ceremony Date */
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['id'] = 'field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['field'] = 'field_lsa_ceremonydate';
  /* Field: Content: Ministry/Organization */
  $handler->display->display_options['fields']['field_lsa_org']['id'] = 'field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['fields']['field_lsa_org']['field'] = 'field_lsa_org';
  /* Field: Content: RSVP */
  $handler->display->display_options['fields']['field_lsa_rsvp']['id'] = 'field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp']['field'] = 'field_lsa_rsvp';
  /* Field: Content: Retro-Active */
  $handler->display->display_options['fields']['field_lsa_retro_active']['id'] = 'field_lsa_retro_active';
  $handler->display->display_options['fields']['field_lsa_retro_active']['table'] = 'field_data_field_lsa_retro_active';
  $handler->display->display_options['fields']['field_lsa_retro_active']['field'] = 'field_lsa_retro_active';
  /* Field: Content: Invitation Send Date */
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['id'] = 'field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['table'] = 'field_data_field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['field'] = 'field_lsa_invitation_sent';
  $handler->display->display_options['fields']['field_lsa_invitation_sent']['settings'] = array(
    'format_type' => 'lsa_export_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  /* Filter criterion: Content: Ceremony Date (field_lsa_ceremonydate) */
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['id'] = 'field_lsa_ceremonydate_value';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['field'] = 'field_lsa_ceremonydate_value';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['operator_id'] = 'field_lsa_ceremonydate_value_op';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['label'] = 'Ceremony Date';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['operator'] = 'field_lsa_ceremonydate_value_op';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['identifier'] = 'field_lsa_ceremonydate_value';
  $handler->display->display_options['filters']['field_lsa_ceremonydate_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Ministry/Organization (field_lsa_org) */
  $handler->display->display_options['filters']['field_lsa_org_value']['id'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['table'] = 'field_data_field_lsa_org';
  $handler->display->display_options['filters']['field_lsa_org_value']['field'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator_id'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['label'] = 'Ministry/Organization (field_lsa_org)';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['operator'] = 'field_lsa_org_value_op';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['identifier'] = 'field_lsa_org_value';
  $handler->display->display_options['filters']['field_lsa_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: RSVP (field_lsa_rsvp) */
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['id'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['field'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator_id'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['label'] = 'RSVP (field_lsa_rsvp)';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['operator'] = 'field_lsa_rsvp_value_op';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['identifier'] = 'field_lsa_rsvp_value';
  $handler->display->display_options['filters']['field_lsa_rsvp_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Retro-Active (field_lsa_retro_active) */
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['id'] = 'field_lsa_retro_active_value';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['table'] = 'field_data_field_lsa_retro_active';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['field'] = 'field_lsa_retro_active_value';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['operator_id'] = 'field_lsa_retro_active_value_op';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['label'] = 'Retro-Active ';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['operator'] = 'field_lsa_retro_active_value_op';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['identifier'] = 'field_lsa_retro_active_value';
  $handler->display->display_options['filters']['field_lsa_retro_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin/email';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'LSA-Email';
  $handler->display->display_options['menu']['weight'] = '8';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: LSA RSVP Block */
  $handler = $view->new_display('block', 'LSA RSVP Block', 'block_lsa_rsvp');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'RSVP Response';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>&nbsp;</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p>&nbsp;</p>

';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Ceremony Date */
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['id'] = 'field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['table'] = 'field_data_field_lsa_ceremonydate';
  $handler->display->display_options['fields']['field_lsa_ceremonydate']['field'] = 'field_lsa_ceremonydate';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Attending Ceremony (editable) */
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['id'] = 'field_lsa_attending_ceremony_editable';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['table'] = 'field_data_field_lsa_attending_ceremony';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['field'] = 'field_lsa_attending_ceremony_editable';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_attending_ceremony_editable']['suppress_description'] = 0;
  /* Field: Content: Guest Attending (editable) */
  $handler->display->display_options['fields']['field_lsa_guest_editable']['id'] = 'field_lsa_guest_editable';
  $handler->display->display_options['fields']['field_lsa_guest_editable']['table'] = 'field_data_field_lsa_guest';
  $handler->display->display_options['fields']['field_lsa_guest_editable']['field'] = 'field_lsa_guest_editable';
  $handler->display->display_options['fields']['field_lsa_guest_editable']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_guest_editable']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_guest_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lsa_guest_editable']['widget_type'] = 'options_onoff';
  $handler->display->display_options['fields']['field_lsa_guest_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_guest_editable']['suppress_description'] = 0;
  /* Field: Content: Number Attending */
  $handler->display->display_options['fields']['field_lsa_number_attending']['id'] = 'field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['table'] = 'field_data_field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['field'] = 'field_lsa_number_attending';
  $handler->display->display_options['fields']['field_lsa_number_attending']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_number_attending']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_number_attending']['element_label_colon'] = FALSE;
  /* Field: Content: RSVP (editable) */
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['id'] = 'field_lsa_rsvp_editable';
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['table'] = 'field_data_field_lsa_rsvp';
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['field'] = 'field_lsa_rsvp_editable';
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_rsvp_editable']['suppress_description'] = 0;
  /* Field: Content: Ceremony Response (editable) */
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['id'] = 'field_lsa_ceremony_response_editable';
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['table'] = 'field_data_field_lsa_ceremony_response';
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['field'] = 'field_lsa_ceremony_response_editable';
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['widget_type'] = 'options_select';
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_lsa_ceremony_response_editable']['suppress_description'] = 0;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['uid']['validate_options']['types'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'ignore';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: LSA Award */
  $handler = $view->new_display('page', 'LSA Award', 'page_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA Award';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    11 => '11',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Years of Service */
  $handler->display->display_options['fields']['field_lsa_years_of_service']['id'] = 'field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['table'] = 'field_data_field_lsa_years_of_service';
  $handler->display->display_options['fields']['field_lsa_years_of_service']['field'] = 'field_lsa_years_of_service';
  /* Field: Content: Award (editable) */
  $handler->display->display_options['fields']['field_lsa_award_editable']['id'] = 'field_lsa_award_editable';
  $handler->display->display_options['fields']['field_lsa_award_editable']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['fields']['field_lsa_award_editable']['field'] = 'field_lsa_award_editable';
  $handler->display->display_options['fields']['field_lsa_award_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_award_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_award_editable']['suppress_description'] = 0;
  /* Field: Content: Award ID (editable) */
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['id'] = 'field_lsa_award_id_editable';
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['field'] = 'field_lsa_award_id_editable';
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['label'] = 'Award ID';
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_award_id_editable']['suppress_description'] = 0;
  /* Field: Content: Donation options */
  $handler->display->display_options['fields']['field_lsa_donation_options']['id'] = 'field_lsa_donation_options';
  $handler->display->display_options['fields']['field_lsa_donation_options']['table'] = 'field_data_field_lsa_donation_options';
  $handler->display->display_options['fields']['field_lsa_donation_options']['field'] = 'field_lsa_donation_options';
  $handler->display->display_options['fields']['field_lsa_donation_options']['alter']['max_length'] = '10';
  $handler->display->display_options['fields']['field_lsa_donation_options']['alter']['trim'] = TRUE;
  /* Field: Content: PECSF Region (editable) */
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['id'] = 'field_lsa_pecsf_region_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['table'] = 'field_data_field_lsa_pecsf_region';
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['field'] = 'field_lsa_pecsf_region_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['label'] = 'PECSF Region';
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_pecsf_region_editable']['suppress_description'] = 0;
  /* Field: Content: Second Charity (editable) */
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['id'] = 'field_lsa_second_donation_editable';
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['table'] = 'field_data_field_lsa_second_donation';
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['field'] = 'field_lsa_second_donation_editable';
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['label'] = 'Second Charity';
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_second_donation_editable']['suppress_description'] = 0;
  /* Field: Content: Charity Name (editable) */
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['id'] = 'field_lsa_pecsf_charity_name_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['table'] = 'field_data_field_lsa_pecsf_charity_name';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['field'] = 'field_lsa_pecsf_charity_name_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['label'] = 'Charity Name ';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_pecsf_charity_name_editable']['suppress_description'] = 0;
  /* Field: Content: PECSF ID (editable) */
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['id'] = 'field_lsa_pecsf_id_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['table'] = 'field_data_field_lsa_pecsf_id';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['field'] = 'field_lsa_pecsf_id_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['label'] = 'PECSF ID ';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_pecsf_id_editable']['suppress_description'] = 0;
  /* Field: Content: Donation Amount (editable) */
  $handler->display->display_options['fields']['field_lsa_donation_amount_editable']['id'] = 'field_lsa_donation_amount_editable';
  $handler->display->display_options['fields']['field_lsa_donation_amount_editable']['table'] = 'field_data_field_lsa_donation_amount';
  $handler->display->display_options['fields']['field_lsa_donation_amount_editable']['field'] = 'field_lsa_donation_amount_editable';
  $handler->display->display_options['fields']['field_lsa_donation_amount_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_donation_amount_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_donation_amount_editable']['suppress_description'] = 0;
  /* Field: Content: Charity Name 2 (editable) */
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['id'] = 'field_lsa_charity_name_2_editable';
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['table'] = 'field_data_field_lsa_charity_name_2';
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['field'] = 'field_lsa_charity_name_2_editable';
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['label'] = 'Charity Name 2';
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_charity_name_2_editable']['suppress_description'] = 0;
  /* Field: Content: PECSF ID 2 (editable) */
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['id'] = 'field_lsa_pecsf_id_2_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['table'] = 'field_data_field_lsa_pecsf_id_2';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['field'] = 'field_lsa_pecsf_id_2_editable';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['label'] = 'PECSF ID 2 ';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_pecsf_id_2_editable']['suppress_description'] = 0;
  /* Field: Content: Donation Amount 2 (editable) */
  $handler->display->display_options['fields']['field_lsa_donation_amount_2_editable']['id'] = 'field_lsa_donation_amount_2_editable';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2_editable']['table'] = 'field_data_field_lsa_donation_amount_2';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2_editable']['field'] = 'field_lsa_donation_amount_2_editable';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_donation_amount_2_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_donation_amount_2_editable']['suppress_description'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Award (field_lsa_award) */
  $handler->display->display_options['filters']['field_lsa_award_value']['id'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['table'] = 'field_data_field_lsa_award';
  $handler->display->display_options['filters']['field_lsa_award_value']['field'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_award_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator_id'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['label'] = 'Award';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['operator'] = 'field_lsa_award_value_op';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['identifier'] = 'field_lsa_award_value';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_field'] = 'field_lsa_award_editable';
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_award_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Award ID (field_lsa_award_id) */
  $handler->display->display_options['filters']['field_lsa_award_id_value']['id'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['table'] = 'field_data_field_lsa_award_id';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['field'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['operator_id'] = 'field_lsa_award_id_value_op';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['label'] = 'Award ID';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['operator'] = 'field_lsa_award_id_value_op';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['identifier'] = 'field_lsa_award_id_value';
  $handler->display->display_options['filters']['field_lsa_award_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin/lsa_award';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'LSA Award';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Alt Ministry */
  $handler = $view->new_display('page', 'Alt Ministry', 'page_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Alt Ministry';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Attending with alternate Min/Org (editable) */
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['id'] = 'field_lsa_alternate_min_org_editable';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['table'] = 'field_data_field_lsa_alternate_min_org';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['field'] = 'field_lsa_alternate_min_org_editable';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['label'] = 'Attending with alternate Min/Org';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_alternate_min_org_editable']['suppress_description'] = 0;
  /* Field: Content: Actual_Min/Org (editable) */
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['id'] = 'field_lsa_actual_min_org_editable';
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['table'] = 'field_data_field_lsa_actual_min_org';
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['field'] = 'field_lsa_actual_min_org_editable';
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['label'] = 'Actual_Min/Org';
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_actual_min_org_editable']['suppress_description'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Attending with alternate Min/Org (field_lsa_alternate_min_org) */
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['id'] = 'field_lsa_alternate_min_org_value';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['table'] = 'field_data_field_lsa_alternate_min_org';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['field'] = 'field_lsa_alternate_min_org_value';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['expose']['operator_id'] = 'field_lsa_alternate_min_org_value_op';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['expose']['label'] = 'Attending with alternate Min/Org (field_lsa_alternate_min_org)';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['expose']['operator'] = 'field_lsa_alternate_min_org_value_op';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['expose']['identifier'] = 'field_lsa_alternate_min_org_value';
  $handler->display->display_options['filters']['field_lsa_alternate_min_org_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'lsa-admin/alt_ministry';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'LSA Alt Ministry';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: People */
  $handler = $view->new_display('page', 'People', 'page_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'LSA 25 Year Certificate';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_lsa_employee_number' => 'field_lsa_employee_number',
    'field_lsa_first_name_editable' => 'field_lsa_first_name_editable',
    'field_lsa_middle_name_editable' => 'field_lsa_middle_name_editable',
    'field_lsa_last_name_editable' => 'field_lsa_last_name_editable',
    'field_lsa_first_name' => 'field_lsa_first_name',
    'field_lsa_last_name' => 'field_lsa_last_name',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_employee_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_first_name_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_middle_name_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_last_name_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_employee_number']['id'] = 'field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['fields']['field_lsa_employee_number']['field'] = 'field_lsa_employee_number';
  /* Field: Content: First Name (editable) */
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['id'] = 'field_lsa_first_name_editable';
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['field'] = 'field_lsa_first_name_editable';
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['label'] = 'First Name ';
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_lsa_first_name_editable']['suppress_description'] = 1;
  /* Field: Content: Middle Name (editable) */
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['id'] = 'field_lsa_middle_name_editable';
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['table'] = 'field_data_field_lsa_middle_name';
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['field'] = 'field_lsa_middle_name_editable';
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['label'] = 'Middle Name';
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_lsa_middle_name_editable']['suppress_description'] = 1;
  /* Field: Content: Last Name (editable) */
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['id'] = 'field_lsa_last_name_editable';
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['field'] = 'field_lsa_last_name_editable';
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['label'] = 'Last Name';
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_lsa_last_name_editable']['suppress_description'] = 1;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_first_name']['id'] = 'field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['field'] = 'field_lsa_first_name';
  $handler->display->display_options['fields']['field_lsa_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_last_name']['id'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['field'] = 'field_lsa_last_name';
  $handler->display->display_options['fields']['field_lsa_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_lsa_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lsa_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lsa_application' => 'lsa_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Employee Number (field_lsa_employee_number) */
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['id'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['table'] = 'field_data_field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['field'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator_id'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['label'] = 'Employee Number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['operator'] = 'field_lsa_employee_number_value_op';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['identifier'] = 'field_lsa_employee_number_value';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_field'] = 'field_lsa_employee_number';
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_employee_number_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: First Name (field_lsa_first_name) */
  $handler->display->display_options['filters']['field_lsa_first_name_value']['id'] = 'field_lsa_first_name_value';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['table'] = 'field_data_field_lsa_first_name';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['field'] = 'field_lsa_first_name_value';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['operator_id'] = 'field_lsa_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['operator'] = 'field_lsa_first_name_value_op';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['identifier'] = 'field_lsa_first_name_value';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_field'] = 'field_lsa_first_name';
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Last Name (field_lsa_last_name) */
  $handler->display->display_options['filters']['field_lsa_last_name_value']['id'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['table'] = 'field_data_field_lsa_last_name';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['field'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['operator_id'] = 'field_lsa_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['label'] = 'Last Name ';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['operator'] = 'field_lsa_last_name_value_op';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['identifier'] = 'field_lsa_last_name_value';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_field'] = 'field_lsa_last_name';
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_lsa_last_name_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'lsa-admin/people';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'menu-lsa-admin';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page LSA Volunteers */
  $handler = $view->new_display('page', 'Page LSA Volunteers', 'page_12');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'value' => 'value',
    'value_1' => 'value_1',
    'value_2' => 'value_2',
    'value_3' => 'value_3',
    'value_4' => 'value_4',
    'value_5' => 'value_5',
    'value_6' => 'value_6',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_4' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_5' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_6' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style="text/css">
  table.views-table.cols-7 {
    width: 100%;
  }
</style>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href="https://gww.gov.bc.ca/career/long-service-awards/call-volunteers/webform-results/download">Download CSV</a>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content: Webform submission */
  $handler->display->display_options['relationships']['webform_submission']['id'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['table'] = 'node';
  $handler->display->display_options['relationships']['webform_submission']['field'] = 'webform_submission';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value']['label'] = 'Availability';
  $handler->display->display_options['fields']['value']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value']['webform_cid'] = '13';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_1']['label'] = 'Cancellations';
  $handler->display->display_options['fields']['value_1']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '14';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_2']['label'] = 'Last Name';
  $handler->display->display_options['fields']['value_2']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '19';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_3']['label'] = 'First Name';
  $handler->display->display_options['fields']['value_3']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_4']['label'] = 'Email';
  $handler->display->display_options['fields']['value_4']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value_4']['alter']['text'] = '<a href="mailto:[value_4]">[value_4]</a>';
  $handler->display->display_options['fields']['value_4']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '9';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_5']['label'] = 'Work Phone';
  $handler->display->display_options['fields']['value_5']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '20';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_6']['label'] = 'Cell Phone';
  $handler->display->display_options['fields']['value_6']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '21';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Webform: Node */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'webform';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform: Node */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'webform';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '6007';
  $handler->display->display_options['path'] = 'lsa-admin/lsa-volunteers';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'LSA Volunteers';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export - Volunteers */
  $handler = $view->new_display('views_data_export', 'Data export - Volunteers', 'views_data_export_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content: Webform submission */
  $handler->display->display_options['relationships']['webform_submission']['id'] = 'webform_submission';
  $handler->display->display_options['relationships']['webform_submission']['table'] = 'node';
  $handler->display->display_options['relationships']['webform_submission']['field'] = 'webform_submission';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value']['label'] = 'Avaialbility';
  $handler->display->display_options['fields']['value']['format'] = 'text';
  $handler->display->display_options['fields']['value']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value']['webform_cid'] = '13';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_1']['label'] = 'Cancellations';
  $handler->display->display_options['fields']['value_1']['format'] = 'text';
  $handler->display->display_options['fields']['value_1']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '14';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_2']['label'] = '';
  $handler->display->display_options['fields']['value_2']['format'] = 'text';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '19';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_3']['label'] = '';
  $handler->display->display_options['fields']['value_3']['format'] = 'text';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_10']['id'] = 'value_10';
  $handler->display->display_options['fields']['value_10']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_10']['field'] = 'value';
  $handler->display->display_options['fields']['value_10']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_10']['label'] = '';
  $handler->display->display_options['fields']['value_10']['format'] = 'text';
  $handler->display->display_options['fields']['value_10']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_10']['webform_cid'] = '9';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_4']['label'] = '';
  $handler->display->display_options['fields']['value_4']['format'] = 'text';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '3';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_5']['label'] = '';
  $handler->display->display_options['fields']['value_5']['format'] = 'text';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '4';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_6']['label'] = '';
  $handler->display->display_options['fields']['value_6']['format'] = 'text';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '5';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_7']['label'] = '';
  $handler->display->display_options['fields']['value_7']['format'] = 'text';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_8']['id'] = 'value_8';
  $handler->display->display_options['fields']['value_8']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_8']['field'] = 'value';
  $handler->display->display_options['fields']['value_8']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_8']['label'] = '';
  $handler->display->display_options['fields']['value_8']['format'] = 'text';
  $handler->display->display_options['fields']['value_8']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_8']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_9']['id'] = 'value_9';
  $handler->display->display_options['fields']['value_9']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_9']['field'] = 'value';
  $handler->display->display_options['fields']['value_9']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_9']['label'] = '';
  $handler->display->display_options['fields']['value_9']['format'] = 'text';
  $handler->display->display_options['fields']['value_9']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_9']['webform_cid'] = '8';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_11']['id'] = 'value_11';
  $handler->display->display_options['fields']['value_11']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_11']['field'] = 'value';
  $handler->display->display_options['fields']['value_11']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_11']['label'] = '';
  $handler->display->display_options['fields']['value_11']['format'] = 'text';
  $handler->display->display_options['fields']['value_11']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_11']['webform_cid'] = '20';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_12']['id'] = 'value_12';
  $handler->display->display_options['fields']['value_12']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_12']['field'] = 'value';
  $handler->display->display_options['fields']['value_12']['relationship'] = 'webform_submission';
  $handler->display->display_options['fields']['value_12']['label'] = '';
  $handler->display->display_options['fields']['value_12']['format'] = 'text';
  $handler->display->display_options['fields']['value_12']['webform_nid'] = '6007';
  $handler->display->display_options['fields']['value_12']['webform_cid'] = '21';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Webform: Node */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'webform';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform: Node */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'webform';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '6007';
  $handler->display->display_options['path'] = 'lsa-admin/lsa-volunteers/export.csv';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'page_3' => 0,
    'page_1' => 0,
    'page_2' => 0,
    'page_4' => 0,
    'page_5' => 0,
    'page_6' => 0,
    'page_7' => 0,
    'page_8' => 0,
    'block_lsa_rsvp' => 0,
    'page_9' => 0,
    'page_10' => 0,
    'page_11' => 0,
    'page_12' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['lsa_admin'] = $view;

  return $export;
}
