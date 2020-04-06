<?php

/**
 * @file
 * atwork_lsa_pins.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function atwork_lsa_pins_views_default_views() {
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
  /* Relationship: Content: Content author */
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
  /* Field: Content: Published status */
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
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  /* Filter criterion: Content: Promoted to front page status */
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
  /* Filter criterion: Content: Published status */
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
  /* Filter criterion: Content: Sticky status */
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
    4 => '4',
    13 => '13',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Content author */
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
  /* Field: Content: Published status */
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
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  /* Filter criterion: Content: Promoted to front page status */
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
  /* Filter criterion: Content: Published status */
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
  /* Filter criterion: Content: Sticky status */
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date (node)';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['date_filter']['group_info']['label'] = 'Date (node)';
  $handler->display->display_options['filters']['date_filter']['group_info']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+5';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
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
  /* Relationship: Content: Content author */
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
  /* Field: Content: Published status */
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
  /* Field: Content: Link to edit content */
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
  /* Filter criterion: Content: Published status */
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
  /* Relationship: Content: Content author */
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
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  /* Field: Content: Retiring in 2019? */
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
  /* Field: Content: Government Email Address */
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
  /* Field: Content: Published status */
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
  /* Field: Content: Link to edit content */
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
  /* Filter criterion: Content: Published status */
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
    'field_lsa_milestone_year_editable' => 'field_lsa_milestone_year_editable',
    'field_lsa_other_milestone_years' => 'field_lsa_other_milestone_years',
    'field_lsa_ministry_rep_email' => 'field_lsa_ministry_rep_email',
    'field_lsa_home_phone' => 'field_lsa_home_phone',
    'field_lsa_registerer' => 'field_lsa_registerer',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
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
      'default_sort_order' => 'asc',
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
    'field_lsa_milestone_year_editable' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_other_milestone_years' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_ministry_rep_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_home_phone' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsa_registerer' => array(
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
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  /* Field: Content: Current Service Milestone */
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['id'] = 'field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['table'] = 'field_data_field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['field'] = 'field_lsa_pin_service_milestone';
  /* Field: Content: Please select the retroactive milestone pin(s) you would like to order */
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['id'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['table'] = 'field_data_field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['field'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['label'] = 'Retroactive pin(s) ';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['delta_offset'] = '0';
  /* Field: Content: Government Email Address */
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
  /* Field: Content: Are you celebrating a current service milestone in 2020? (editable) */
  $handler->display->display_options['fields']['field_lsa_milestone_year_editable']['id'] = 'field_lsa_milestone_year_editable';
  $handler->display->display_options['fields']['field_lsa_milestone_year_editable']['table'] = 'field_data_field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year_editable']['field'] = 'field_lsa_milestone_year_editable';
  $handler->display->display_options['fields']['field_lsa_milestone_year_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_lsa_milestone_year_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_lsa_milestone_year_editable']['suppress_description'] = 0;
  /* Field: Content: Do you wish to request service pin(s) for any past milestones? */
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['id'] = 'field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['table'] = 'field_data_field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['field'] = 'field_lsa_other_milestone_years';
  /* Field: Content: Ministry Representative Email */
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['id'] = 'field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['table'] = 'field_data_field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['field'] = 'field_lsa_ministry_rep_email';
  /* Field: Content: Home Phone */
  $handler->display->display_options['fields']['field_lsa_home_phone']['id'] = 'field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['table'] = 'field_data_field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['field'] = 'field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['label'] = 'Phone';
  /* Field: Content: Who is registering for this service pin? */
  $handler->display->display_options['fields']['field_lsa_registerer']['id'] = 'field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['table'] = 'field_data_field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['field'] = 'field_lsa_registerer';
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
  /* Filter criterion: Content: Current Service Milestone (field_lsa_pin_service_milestone) */
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
  /* Field: Content: What ministry/organization are you with? */
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['id'] = 'field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['table'] = 'field_data_field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['field'] = 'field_lsa_pin_ministry_org';
  $handler->display->display_options['fields']['field_lsa_pin_ministry_org']['label'] = 'Ministry/Organization';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Employee Name';
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['id'] = 'field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['table'] = 'field_data_field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['field'] = 'field_lsa_pin_first_name';
  $handler->display->display_options['fields']['field_lsa_pin_first_name']['label'] = 'Employee First Name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['id'] = 'field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['table'] = 'field_data_field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['field'] = 'field_lsa_pin_last_name';
  $handler->display->display_options['fields']['field_lsa_pin_last_name']['label'] = 'Employee Last Name';
  /* Field: Content: Employee Number */
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['id'] = 'field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['table'] = 'field_data_field_lsa_pin_employee_number';
  $handler->display->display_options['fields']['field_lsa_pin_employee_number']['field'] = 'field_lsa_pin_employee_number';
  /* Field: Content: Home Phone */
  $handler->display->display_options['fields']['field_lsa_home_phone']['id'] = 'field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['table'] = 'field_data_field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['field'] = 'field_lsa_home_phone';
  $handler->display->display_options['fields']['field_lsa_home_phone']['label'] = 'Employee Phone';
  /* Field: Content: Government Email Address */
  $handler->display->display_options['fields']['field_lsa_email']['id'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['table'] = 'field_data_field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['field'] = 'field_lsa_email';
  $handler->display->display_options['fields']['field_lsa_email']['label'] = 'Employee Email';
  /* Field: Content: Are you celebrating a current service milestone in 2020? */
  $handler->display->display_options['fields']['field_lsa_milestone_year']['id'] = 'field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year']['table'] = 'field_data_field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year']['field'] = 'field_lsa_milestone_year';
  $handler->display->display_options['fields']['field_lsa_milestone_year']['label'] = 'Celebrating Current Milestone';
  /* Field: Content: Current Service Milestone */
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['id'] = 'field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['table'] = 'field_data_field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['field'] = 'field_lsa_pin_service_milestone';
  $handler->display->display_options['fields']['field_lsa_pin_service_milestone']['label'] = 'Current Milestone';
  /* Field: Content: Do you wish to request service pin(s) for any past milestones? */
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['id'] = 'field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['table'] = 'field_data_field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['field'] = 'field_lsa_other_milestone_years';
  $handler->display->display_options['fields']['field_lsa_other_milestone_years']['label'] = 'Celebrating Retroactive Milestones?';
  /* Field: Content: Please select the retroactive milestone pin(s) you would like to order */
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['id'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['table'] = 'field_data_field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['field'] = 'field_lsa_previous_service_miles';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['label'] = 'retroactive milestones';
  $handler->display->display_options['fields']['field_lsa_previous_service_miles']['delta_offset'] = '0';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['id'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['table'] = 'field_data_field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['field'] = 'field_lsa_supervisor_first_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_first_name']['label'] = 'Supervisor First Name';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['id'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['table'] = 'field_data_field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['field'] = 'field_lsa_supervisor_last_name';
  $handler->display->display_options['fields']['field_lsa_supervisor_last_name']['label'] = 'Supervisor Last Name';
  /* Field: Content: Branch */
  $handler->display->display_options['fields']['field_lsa_branch_department']['id'] = 'field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['table'] = 'field_data_field_lsa_branch_department';
  $handler->display->display_options['fields']['field_lsa_branch_department']['field'] = 'field_lsa_branch_department';
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
  $handler->display->display_options['fields']['field_lsa_work_phone']['label'] = 'Supervisor Phone';
  /* Field: Content: Who is registering for this service pin? */
  $handler->display->display_options['fields']['field_lsa_registerer']['id'] = 'field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['table'] = 'field_data_field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['field'] = 'field_lsa_registerer';
  $handler->display->display_options['fields']['field_lsa_registerer']['label'] = 'Who is registering';
  /* Field: Content: Ministry Representative Email */
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['id'] = 'field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['table'] = 'field_data_field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['field'] = 'field_lsa_ministry_rep_email';
  $handler->display->display_options['fields']['field_lsa_ministry_rep_email']['label'] = 'Ministry Rep Email';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  /* Relationship: Content: Content author */
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
  /* Field: Content: Published status */
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
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  /* Relationship: Content: Content author */
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
  /* Field: Content: Published status */
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
  /* Filter criterion: Content: Published status */
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

  return $export;
}
