<?php
/**
 * @file
 * atwork_user_following.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function atwork_user_following_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'people_admin';
  $view->description = 'Admin users on site';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'name' => 'name',
    'field_display_name' => 'field_display_name',
    'field_gal_title' => 'field_gal_title',
    'rid' => 'rid',
    'created' => 'created',
    'access' => 'access',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'access';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'name' => array(
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
    'field_gal_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
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
    'access' => array(
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
  );
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
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
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['fields']['name']['format_username'] = FALSE;
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Member for';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: User: Permission */
  $handler->display->display_options['filters']['permission']['id'] = 'permission';
  $handler->display->display_options['filters']['permission']['table'] = 'role_permission';
  $handler->display->display_options['filters']['permission']['field'] = 'permission';
  $handler->display->display_options['filters']['permission']['group'] = 1;
  $handler->display->display_options['filters']['permission']['exposed'] = TRUE;
  $handler->display->display_options['filters']['permission']['expose']['operator_id'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['label'] = 'Permission';
  $handler->display->display_options['filters']['permission']['expose']['operator'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['identifier'] = 'permission';
  $handler->display->display_options['filters']['permission']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['permission']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
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
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'IDIR';
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
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['fields']['name']['format_username'] = FALSE;
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Member for';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: Permission */
  $handler->display->display_options['filters']['permission']['id'] = 'permission';
  $handler->display->display_options['filters']['permission']['table'] = 'role_permission';
  $handler->display->display_options['filters']['permission']['field'] = 'permission';
  $handler->display->display_options['filters']['permission']['group'] = 1;
  $handler->display->display_options['filters']['permission']['exposed'] = TRUE;
  $handler->display->display_options['filters']['permission']['expose']['operator_id'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['label'] = 'Permission';
  $handler->display->display_options['filters']['permission']['expose']['operator'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['identifier'] = 'permission';
  $handler->display->display_options['filters']['permission']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['permission']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
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
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'IDIR';
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
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['path'] = 'admin/people';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'email_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'mail' => 'mail',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Public List */
  $handler = $view->new_display('page', 'Public List', 'public_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Employee Profiles';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 50, 100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'intro text';
  $handler->display->display_options['header']['area']['content'] = '<?php 
global $user;
echo(\'<p style="margin-bottom:10px;">Putting a face to a name is a great way to connect with your colleagues across the province. Search our employee profiles to find similar (or sought after) skills, interests, ministries or geographies.</p>\');

echo(\'<p style="margin-top:10px;">To update and publish <a href="/employees/\' . $user->name . \'">your profile</a>, go to your personalization menu (The “Hello” menu in the blue ribbon, top right corner). Then select “My Profile” and go to the “Edit” tab above your profile photo.</p>\');

?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p align="center" style="margin-bottom:12px;"><bold>No results found.</bold></p>
<p style="margin-bottom:12px;">It’s possible the name you entered was misspelled or the employee you searched for has not published their profile.</p>
 
<p style="margin-bottom:12px;">To publish your profile, go to your personalization menu (The “Hello” menu in the blue ribbon, top right corner). Then select “My Profile” and go to the “Edit” tab above your profile photo.</p>
<p style="margin-bottom:12px;">To publish your profile, check the box that shows: “Share your profile.”</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_image']['alter']['alt'] = 'View Profile';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'image-employee-landing';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'employee_landing_page',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_class'] = 'name-employee-landing';
  $handler->display->display_options['fields']['field_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_gal_last_name']['id'] = 'field_gal_last_name';
  $handler->display->display_options['fields']['field_gal_last_name']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['fields']['field_gal_last_name']['field'] = 'field_gal_last_name';
  $handler->display->display_options['fields']['field_gal_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_gal_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_last_name']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_gal_first_name']['id'] = 'field_gal_first_name';
  $handler->display->display_options['fields']['field_gal_first_name']['table'] = 'field_data_field_gal_first_name';
  $handler->display->display_options['fields']['field_gal_first_name']['field'] = 'field_gal_first_name';
  $handler->display->display_options['fields']['field_gal_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_gal_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_class'] = 'title-employee-landing';
  $handler->display->display_options['fields']['field_gal_title']['element_default_classes'] = FALSE;
  /* Field: User: Branch */
  $handler->display->display_options['fields']['field_gal_branch']['id'] = 'field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['table'] = 'field_data_field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['field'] = 'field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['label'] = '';
  $handler->display->display_options['fields']['field_gal_branch']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_branch']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_branch']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_branch']['element_default_classes'] = FALSE;
  /* Field: User: City */
  $handler->display->display_options['fields']['field_gal_city']['id'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['field'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['label'] = '';
  $handler->display->display_options['fields']['field_gal_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_city']['element_label_colon'] = FALSE;
  /* Field: User: Ministry */
  $handler->display->display_options['fields']['field_gal_ministry_name']['id'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['field'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['label'] = '';
  $handler->display->display_options['fields']['field_gal_ministry_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_default_classes'] = FALSE;
  /* Field: User: Work Group */
  $handler->display->display_options['fields']['field_gal_work_group']['id'] = 'field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['table'] = 'field_data_field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['field'] = 'field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['label'] = '';
  $handler->display->display_options['fields']['field_gal_work_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_work_group']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="employee-profile">
  <div class="image-employee-landing">[field_image]</div>
  <div class="employee-info">
    <div class="name-employee-landing">[field_display_name]</div>
    <div class="title-employee-landing">[field_gal_title]</div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Image (field_image:fid) */
  $handler->display->display_options['sorts']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['sorts']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['order'] = 'DESC';
  /* Sort criterion: Global: Random seed */
  $handler->display->display_options['sorts']['random_seed']['id'] = 'random_seed';
  $handler->display->display_options['sorts']['random_seed']['table'] = 'views';
  $handler->display->display_options['sorts']['random_seed']['field'] = 'random_seed';
  $handler->display->display_options['sorts']['random_seed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['random_seed']['expose']['label'] = 'Random';
  /* Sort criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['sorts']['field_gal_last_name_value']['id'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gal_last_name_value']['expose']['label'] = 'Last Name | A to Z';
  /* Sort criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['id'] = 'field_gal_last_name_value_1';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['expose']['label'] = 'Last Name | Z to A';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['filters']['field_gal_last_name_value']['id'] = 'field_gal_last_name_value';
  $handler->display->display_options['filters']['field_gal_last_name_value']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['filters']['field_gal_last_name_value']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['filters']['field_gal_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_gal_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['operator_id'] = 'field_gal_last_name_value_op';
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['operator'] = 'field_gal_last_name_value_op';
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['identifier'] = 'last_name';
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['autocomplete_items'] = '25';
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['autocomplete_field'] = 'field_gal_last_name';
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: First Name (field_gal_first_name) */
  $handler->display->display_options['filters']['field_gal_first_name_value']['id'] = 'field_gal_first_name_value';
  $handler->display->display_options['filters']['field_gal_first_name_value']['table'] = 'field_data_field_gal_first_name';
  $handler->display->display_options['filters']['field_gal_first_name_value']['field'] = 'field_gal_first_name_value';
  $handler->display->display_options['filters']['field_gal_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_gal_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['operator_id'] = 'field_gal_first_name_value_op';
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['operator'] = 'field_gal_first_name_value_op';
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['identifier'] = 'first_name';
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['autocomplete_items'] = '20';
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['autocomplete_field'] = 'field_gal_first_name';
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_first_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_1']['id'] = 'field_display_name_value_1';
  $handler->display->display_options['filters']['field_display_name_value_1']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_1']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_display_name_value_1']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_field'] = 'field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['id'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator_id'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['label'] = 'Ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['identifier'] = 'ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_field'] = 'field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: City (field_gal_city) */
  $handler->display->display_options['filters']['field_gal_city_value']['id'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['field'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator_id'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_field'] = 'field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Skills (field_skills) */
  $handler->display->display_options['filters']['field_skills_tid']['id'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['table'] = 'field_data_field_skills';
  $handler->display->display_options['filters']['field_skills_tid']['field'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_skills_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator_id'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['label'] = 'Skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['identifier'] = 'skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_skills_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['vocabulary'] = 'profile_skills';
  /* Filter criterion: User: Interests (field_employee_interests) */
  $handler->display->display_options['filters']['field_employee_interests_tid']['id'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['table'] = 'field_data_field_employee_interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['field'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['value'] = '';
  $handler->display->display_options['filters']['field_employee_interests_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_employee_interests_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator_id'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['label'] = 'Interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['identifier'] = 'interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_employee_interests_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['vocabulary'] = 'profile_interests';
  /* Filter criterion: User: Share your profile (field_public_profile) */
  $handler->display->display_options['filters']['field_public_profile_value']['id'] = 'field_public_profile_value';
  $handler->display->display_options['filters']['field_public_profile_value']['table'] = 'field_data_field_public_profile';
  $handler->display->display_options['filters']['field_public_profile_value']['field'] = 'field_public_profile_value';
  $handler->display->display_options['filters']['field_public_profile_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_public_profile_value']['group'] = 1;
  $handler->display->display_options['filters']['field_public_profile_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['mail']['value'] = '1';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['id'] = 'field_gal_ministry_name_value_1';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['value'] = '1';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['group'] = 1;
  /* Filter criterion: User: Phone (field_gal_phone_number) */
  $handler->display->display_options['filters']['field_gal_phone_number_value']['id'] = 'field_gal_phone_number_value';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['table'] = 'field_data_field_gal_phone_number';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['field'] = 'field_gal_phone_number_value';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['value'] = '1';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_2']['id'] = 'field_display_name_value_2';
  $handler->display->display_options['filters']['field_display_name_value_2']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_2']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_2']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_display_name_value_2']['value'] = '[a-zA-z]+([ \'-][a-zA-Z]+)*';
  $handler->display->display_options['filters']['field_display_name_value_2']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_3']['id'] = 'field_display_name_value_3';
  $handler->display->display_options['filters']['field_display_name_value_3']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_3']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_3']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_3']['value'] = 'ADMIN';
  $handler->display->display_options['filters']['field_display_name_value_3']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_4']['id'] = 'field_display_name_value_4';
  $handler->display->display_options['filters']['field_display_name_value_4']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_4']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_4']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value_4']['value'] = ',';
  $handler->display->display_options['filters']['field_display_name_value_4']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_5']['id'] = 'field_display_name_value_5';
  $handler->display->display_options['filters']['field_display_name_value_5']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_5']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_5']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_5']['value'] = 'zz';
  $handler->display->display_options['filters']['field_display_name_value_5']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_6']['id'] = 'field_display_name_value_6';
  $handler->display->display_options['filters']['field_display_name_value_6']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_6']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_6']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_6']['value'] = 'XT:';
  $handler->display->display_options['filters']['field_display_name_value_6']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_7']['id'] = 'field_display_name_value_7';
  $handler->display->display_options['filters']['field_display_name_value_7']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_7']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_7']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_7']['value'] = 'OSMV,';
  $handler->display->display_options['filters']['field_display_name_value_7']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_1']['id'] = 'field_gal_title_value_1';
  $handler->display->display_options['filters']['field_gal_title_value_1']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_1']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_1']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_gal_title_value_1']['value'] = 'Owner:';
  $handler->display->display_options['filters']['field_gal_title_value_1']['group'] = 2;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_2']['id'] = 'field_gal_title_value_2';
  $handler->display->display_options['filters']['field_gal_title_value_2']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_2']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_gal_title_value_2']['group'] = 2;
  $handler->display->display_options['path'] = 'employees';

  /* Display: Hidden List */
  $handler = $view->new_display('page', 'Hidden List', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Employee Profiles';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 50, 100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'employee/[uid]';
  $handler->display->display_options['fields']['field_image']['alter']['alt'] = 'View Profile';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  /* Field: User: Branch */
  $handler->display->display_options['fields']['field_gal_branch']['id'] = 'field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['table'] = 'field_data_field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['field'] = 'field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['label'] = '';
  $handler->display->display_options['fields']['field_gal_branch']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_branch']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_branch']['element_label_colon'] = FALSE;
  /* Field: User: City */
  $handler->display->display_options['fields']['field_gal_city']['id'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['field'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['label'] = '';
  $handler->display->display_options['fields']['field_gal_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_city']['element_label_colon'] = FALSE;
  /* Field: User: Ministry */
  $handler->display->display_options['fields']['field_gal_ministry_name']['id'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['field'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['label'] = '';
  $handler->display->display_options['fields']['field_gal_ministry_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_label_colon'] = FALSE;
  /* Field: User: Work Group */
  $handler->display->display_options['fields']['field_gal_work_group']['id'] = 'field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['table'] = 'field_data_field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['field'] = 'field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['label'] = '';
  $handler->display->display_options['fields']['field_gal_work_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_work_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Sort criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['sorts']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['sorts']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['sorts']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['identifier'] = 'name';
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
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_1']['id'] = 'field_display_name_value_1';
  $handler->display->display_options['filters']['field_display_name_value_1']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_1']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_display_name_value_1']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_field'] = 'field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Branch (field_gal_branch) */
  $handler->display->display_options['filters']['field_gal_branch_value']['id'] = 'field_gal_branch_value';
  $handler->display->display_options['filters']['field_gal_branch_value']['table'] = 'field_data_field_gal_branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['field'] = 'field_gal_branch_value';
  $handler->display->display_options['filters']['field_gal_branch_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_branch_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['operator_id'] = 'field_gal_branch_value_op';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['label'] = 'Branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['operator'] = 'field_gal_branch_value_op';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['identifier'] = 'branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_field'] = 'field_gal_branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['id'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator_id'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['label'] = 'Ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['identifier'] = 'ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_field'] = 'field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: City (field_gal_city) */
  $handler->display->display_options['filters']['field_gal_city_value']['id'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['field'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator_id'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_field'] = 'field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Skills (field_skills) */
  $handler->display->display_options['filters']['field_skills_tid']['id'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['table'] = 'field_data_field_skills';
  $handler->display->display_options['filters']['field_skills_tid']['field'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_skills_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator_id'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['label'] = 'Skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['identifier'] = 'skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_skills_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['vocabulary'] = 'profile_skills';
  /* Filter criterion: User: Interests (field_employee_interests) */
  $handler->display->display_options['filters']['field_employee_interests_tid']['id'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['table'] = 'field_data_field_employee_interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['field'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['value'] = '';
  $handler->display->display_options['filters']['field_employee_interests_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_employee_interests_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator_id'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['label'] = 'Interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['identifier'] = 'interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_employee_interests_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['vocabulary'] = 'profile_interests';
  $handler->display->display_options['path'] = 'hidden-employees';

  /* Display: Block: Refresh Public List */
  $handler = $view->new_display('block', 'Block: Refresh Public List', 'employee_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['link_url'] = 'employees/';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 50, 100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'image-employee-landing';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_class'] = 'name-employee-landing';
  $handler->display->display_options['fields']['field_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_class'] = 'title-employee-landing';
  $handler->display->display_options['fields']['field_gal_title']['element_default_classes'] = FALSE;
  /* Field: User: Branch */
  $handler->display->display_options['fields']['field_gal_branch']['id'] = 'field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['table'] = 'field_data_field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['field'] = 'field_gal_branch';
  $handler->display->display_options['fields']['field_gal_branch']['label'] = '';
  $handler->display->display_options['fields']['field_gal_branch']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_branch']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_branch']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_branch']['element_default_classes'] = FALSE;
  /* Field: User: City */
  $handler->display->display_options['fields']['field_gal_city']['id'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['field'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['label'] = '';
  $handler->display->display_options['fields']['field_gal_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_city']['element_label_colon'] = FALSE;
  /* Field: User: Ministry */
  $handler->display->display_options['fields']['field_gal_ministry_name']['id'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['field'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['label'] = '';
  $handler->display->display_options['fields']['field_gal_ministry_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_ministry_name']['element_default_classes'] = FALSE;
  /* Field: User: Work Group */
  $handler->display->display_options['fields']['field_gal_work_group']['id'] = 'field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['table'] = 'field_data_field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['field'] = 'field_gal_work_group';
  $handler->display->display_options['fields']['field_gal_work_group']['label'] = '';
  $handler->display->display_options['fields']['field_gal_work_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_work_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Sort criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['sorts']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['sorts']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['sorts']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['identifier'] = 'name';
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_1']['id'] = 'field_display_name_value_1';
  $handler->display->display_options['filters']['field_display_name_value_1']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_1']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_display_name_value_1']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_2']['id'] = 'field_display_name_value_2';
  $handler->display->display_options['filters']['field_display_name_value_2']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_2']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_2']['operator'] = 'not';
  $handler->display->display_options['filters']['field_display_name_value_2']['value'] = '_old1, .old1, deleted';
  $handler->display->display_options['filters']['field_display_name_value_2']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_field'] = 'field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_1']['id'] = 'field_gal_title_value_1';
  $handler->display->display_options['filters']['field_gal_title_value_1']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_1']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_gal_title_value_1']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_2']['id'] = 'field_gal_title_value_2';
  $handler->display->display_options['filters']['field_gal_title_value_2']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_2']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_2']['operator'] = 'not';
  $handler->display->display_options['filters']['field_gal_title_value_2']['value'] = 'Owner:';
  $handler->display->display_options['filters']['field_gal_title_value_2']['group'] = 1;
  /* Filter criterion: User: Branch (field_gal_branch) */
  $handler->display->display_options['filters']['field_gal_branch_value']['id'] = 'field_gal_branch_value';
  $handler->display->display_options['filters']['field_gal_branch_value']['table'] = 'field_data_field_gal_branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['field'] = 'field_gal_branch_value';
  $handler->display->display_options['filters']['field_gal_branch_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_branch_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['operator_id'] = 'field_gal_branch_value_op';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['label'] = 'Branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['operator'] = 'field_gal_branch_value_op';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['identifier'] = 'branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_field'] = 'field_gal_branch';
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_branch_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['id'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator_id'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['label'] = 'Ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['identifier'] = 'ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_field'] = 'field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: City (field_gal_city) */
  $handler->display->display_options['filters']['field_gal_city_value']['id'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['field'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator_id'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_field'] = 'field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Skills (field_skills) */
  $handler->display->display_options['filters']['field_skills_tid']['id'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['table'] = 'field_data_field_skills';
  $handler->display->display_options['filters']['field_skills_tid']['field'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['value'] = '';
  $handler->display->display_options['filters']['field_skills_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_skills_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator_id'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['label'] = 'Skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['identifier'] = 'skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_skills_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['vocabulary'] = 'profile_skills';
  /* Filter criterion: User: Interests (field_employee_interests) */
  $handler->display->display_options['filters']['field_employee_interests_tid']['id'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['table'] = 'field_data_field_employee_interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['field'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['value'] = '';
  $handler->display->display_options['filters']['field_employee_interests_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_employee_interests_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator_id'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['label'] = 'Interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['identifier'] = 'interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  $handler->display->display_options['filters']['field_employee_interests_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['vocabulary'] = 'profile_interests';
  $handler->display->display_options['block_description'] = 'Refresh Employees Page';

  /* Display: Classic Employees Page */
  $handler = $view->new_display('block', 'Classic Employees Page', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'This employees profile page is not available in this version of the @Work site';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['block_description'] = 'Classic Employee Profiles';

  /* Display: Page: Following */
  $handler = $view->new_display('page', 'Page: Following', 'page_following2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Following';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'people-following';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 50, 100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_image']['alter']['alt'] = 'View Profile';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'image-employee-landing';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'employee_landing_page',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_class'] = 'name-employee-landing';
  $handler->display->display_options['fields']['field_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_class'] = 'title-employee-landing';
  $handler->display->display_options['fields']['field_gal_title']['element_default_classes'] = FALSE;
  /* Field: User: Ministry */
  $handler->display->display_options['fields']['field_gal_ministry_name']['id'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['field'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_gal_ministry_name']['exclude'] = TRUE;
  /* Field: User: City */
  $handler->display->display_options['fields']['field_gal_city']['id'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['field'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_gal_city']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random seed */
  $handler->display->display_options['sorts']['random_seed']['id'] = 'random_seed';
  $handler->display->display_options['sorts']['random_seed']['table'] = 'views';
  $handler->display->display_options['sorts']['random_seed']['field'] = 'random_seed';
  $handler->display->display_options['sorts']['random_seed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['random_seed']['expose']['label'] = 'Random';
  /* Sort criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['sorts']['field_gal_last_name_value']['id'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gal_last_name_value']['expose']['label'] = 'Last Name | A to Z';
  /* Sort criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['id'] = 'field_gal_last_name_value_1';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['expose']['label'] = 'Last Name | Z to A';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requester user */
  $handler->display->display_options['arguments']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requester_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['requester_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['requester_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requester_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requester_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Name';
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
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '15';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_1']['id'] = 'field_display_name_value_1';
  $handler->display->display_options['filters']['field_display_name_value_1']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_1']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_display_name_value_1']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_field'] = 'field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['id'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator_id'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['label'] = 'Ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['identifier'] = 'ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_field'] = 'field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: City (field_gal_city) */
  $handler->display->display_options['filters']['field_gal_city_value']['id'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['field'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator_id'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_field'] = 'field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Skills (field_skills) */
  $handler->display->display_options['filters']['field_skills_tid']['id'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['table'] = 'field_data_field_skills';
  $handler->display->display_options['filters']['field_skills_tid']['field'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_skills_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator_id'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['label'] = 'Skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['identifier'] = 'skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_skills_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['vocabulary'] = 'profile_skills';
  /* Filter criterion: User: Interests (field_employee_interests) */
  $handler->display->display_options['filters']['field_employee_interests_tid']['id'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['table'] = 'field_data_field_employee_interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['field'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['value'] = '';
  $handler->display->display_options['filters']['field_employee_interests_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_employee_interests_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator_id'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['label'] = 'Interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['identifier'] = 'interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_employee_interests_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['vocabulary'] = 'profile_interests';
  /* Filter criterion: User: Share your profile (field_public_profile) */
  $handler->display->display_options['filters']['field_public_profile_value']['id'] = 'field_public_profile_value';
  $handler->display->display_options['filters']['field_public_profile_value']['table'] = 'field_data_field_public_profile';
  $handler->display->display_options['filters']['field_public_profile_value']['field'] = 'field_public_profile_value';
  $handler->display->display_options['filters']['field_public_profile_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_public_profile_value']['group'] = 1;
  $handler->display->display_options['filters']['field_public_profile_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['mail']['value'] = '1';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['id'] = 'field_gal_ministry_name_value_1';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['value'] = '1';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['group'] = 1;
  /* Filter criterion: User: Phone (field_gal_phone_number) */
  $handler->display->display_options['filters']['field_gal_phone_number_value']['id'] = 'field_gal_phone_number_value';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['table'] = 'field_data_field_gal_phone_number';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['field'] = 'field_gal_phone_number_value';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['value'] = '1';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_2']['id'] = 'field_display_name_value_2';
  $handler->display->display_options['filters']['field_display_name_value_2']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_2']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_2']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_display_name_value_2']['value'] = '[a-zA-z]+([ \'-][a-zA-Z]+)*';
  $handler->display->display_options['filters']['field_display_name_value_2']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_3']['id'] = 'field_display_name_value_3';
  $handler->display->display_options['filters']['field_display_name_value_3']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_3']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_3']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_3']['value'] = 'ADMIN';
  $handler->display->display_options['filters']['field_display_name_value_3']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_4']['id'] = 'field_display_name_value_4';
  $handler->display->display_options['filters']['field_display_name_value_4']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_4']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_4']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value_4']['value'] = ',';
  $handler->display->display_options['filters']['field_display_name_value_4']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_5']['id'] = 'field_display_name_value_5';
  $handler->display->display_options['filters']['field_display_name_value_5']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_5']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_5']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_5']['value'] = 'zz';
  $handler->display->display_options['filters']['field_display_name_value_5']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_6']['id'] = 'field_display_name_value_6';
  $handler->display->display_options['filters']['field_display_name_value_6']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_6']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_6']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_6']['value'] = 'XT:';
  $handler->display->display_options['filters']['field_display_name_value_6']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_7']['id'] = 'field_display_name_value_7';
  $handler->display->display_options['filters']['field_display_name_value_7']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_7']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_7']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_7']['value'] = 'OSMV,';
  $handler->display->display_options['filters']['field_display_name_value_7']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_1']['id'] = 'field_gal_title_value_1';
  $handler->display->display_options['filters']['field_gal_title_value_1']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_1']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_1']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_gal_title_value_1']['value'] = 'Owner:';
  $handler->display->display_options['filters']['field_gal_title_value_1']['group'] = 2;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_2']['id'] = 'field_gal_title_value_2';
  $handler->display->display_options['filters']['field_gal_title_value_2']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_2']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_gal_title_value_2']['group'] = 2;
  $handler->display->display_options['path'] = 'user/%/following';

  /* Display: Page: Followers */
  $handler = $view->new_display('page', 'Page: Followers', 'page_followers2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Followers';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'people-following';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '20, 50, 100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_image']['alter']['alt'] = 'View Profile';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'image-employee-landing';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'employee_landing_page',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_display_name']['element_wrapper_class'] = 'name-employee-landing';
  $handler->display->display_options['fields']['field_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_gal_title']['element_wrapper_class'] = 'title-employee-landing';
  $handler->display->display_options['fields']['field_gal_title']['element_default_classes'] = FALSE;
  /* Field: User: Ministry */
  $handler->display->display_options['fields']['field_gal_ministry_name']['id'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['field'] = 'field_gal_ministry_name';
  $handler->display->display_options['fields']['field_gal_ministry_name']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_gal_ministry_name']['exclude'] = TRUE;
  /* Field: User: City */
  $handler->display->display_options['fields']['field_gal_city']['id'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['field'] = 'field_gal_city';
  $handler->display->display_options['fields']['field_gal_city']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_gal_city']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random seed */
  $handler->display->display_options['sorts']['random_seed']['id'] = 'random_seed';
  $handler->display->display_options['sorts']['random_seed']['table'] = 'views';
  $handler->display->display_options['sorts']['random_seed']['field'] = 'random_seed';
  $handler->display->display_options['sorts']['random_seed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['random_seed']['expose']['label'] = 'Random';
  /* Sort criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['sorts']['field_gal_last_name_value']['id'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gal_last_name_value']['expose']['label'] = 'Last Name | A to Z';
  /* Sort criterion: User: Last Name (field_gal_last_name) */
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['id'] = 'field_gal_last_name_value_1';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['table'] = 'field_data_field_gal_last_name';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['field'] = 'field_gal_last_name_value';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gal_last_name_value_1']['expose']['label'] = 'Last Name | Z to A';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['operator_id'] = 'field_display_name_value_op';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['label'] = 'Name';
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
  );
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_items'] = '15';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_field'] = 'field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_display_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_1']['id'] = 'field_display_name_value_1';
  $handler->display->display_options['filters']['field_display_name_value_1']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_1']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_display_name_value_1']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value']['id'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_title_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator_id'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['operator'] = 'field_gal_title_value_op';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_field'] = 'field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_title_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['id'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator_id'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['label'] = 'Ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['operator'] = 'field_gal_ministry_name_value_op';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['identifier'] = 'ministry';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_field'] = 'field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_ministry_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: City (field_gal_city) */
  $handler->display->display_options['filters']['field_gal_city_value']['id'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['table'] = 'field_data_field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['field'] = 'field_gal_city_value';
  $handler->display->display_options['filters']['field_gal_city_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_gal_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator_id'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['operator'] = 'field_gal_city_value_op';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_field'] = 'field_gal_city';
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_gal_city_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Skills (field_skills) */
  $handler->display->display_options['filters']['field_skills_tid']['id'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['table'] = 'field_data_field_skills';
  $handler->display->display_options['filters']['field_skills_tid']['field'] = 'field_skills_tid';
  $handler->display->display_options['filters']['field_skills_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_skills_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator_id'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['label'] = 'Skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['operator'] = 'field_skills_tid_op';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['identifier'] = 'skills';
  $handler->display->display_options['filters']['field_skills_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_skills_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_skills_tid']['vocabulary'] = 'profile_skills';
  /* Filter criterion: User: Interests (field_employee_interests) */
  $handler->display->display_options['filters']['field_employee_interests_tid']['id'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['table'] = 'field_data_field_employee_interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['field'] = 'field_employee_interests_tid';
  $handler->display->display_options['filters']['field_employee_interests_tid']['value'] = '';
  $handler->display->display_options['filters']['field_employee_interests_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_employee_interests_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator_id'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['label'] = 'Interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['operator'] = 'field_employee_interests_tid_op';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['identifier'] = 'interests';
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_employee_interests_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_employee_interests_tid']['vocabulary'] = 'profile_interests';
  /* Filter criterion: User: Share your profile (field_public_profile) */
  $handler->display->display_options['filters']['field_public_profile_value']['id'] = 'field_public_profile_value';
  $handler->display->display_options['filters']['field_public_profile_value']['table'] = 'field_data_field_public_profile';
  $handler->display->display_options['filters']['field_public_profile_value']['field'] = 'field_public_profile_value';
  $handler->display->display_options['filters']['field_public_profile_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_public_profile_value']['group'] = 1;
  $handler->display->display_options['filters']['field_public_profile_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['mail']['value'] = '1';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  /* Filter criterion: User: Ministry (field_gal_ministry_name) */
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['id'] = 'field_gal_ministry_name_value_1';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['table'] = 'field_data_field_gal_ministry_name';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['field'] = 'field_gal_ministry_name_value';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['value'] = '1';
  $handler->display->display_options['filters']['field_gal_ministry_name_value_1']['group'] = 1;
  /* Filter criterion: User: Phone (field_gal_phone_number) */
  $handler->display->display_options['filters']['field_gal_phone_number_value']['id'] = 'field_gal_phone_number_value';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['table'] = 'field_data_field_gal_phone_number';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['field'] = 'field_gal_phone_number_value';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['value'] = '1';
  $handler->display->display_options['filters']['field_gal_phone_number_value']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_2']['id'] = 'field_display_name_value_2';
  $handler->display->display_options['filters']['field_display_name_value_2']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_2']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_2']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_display_name_value_2']['value'] = '[a-zA-z]+([ \'-][a-zA-Z]+)*';
  $handler->display->display_options['filters']['field_display_name_value_2']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_3']['id'] = 'field_display_name_value_3';
  $handler->display->display_options['filters']['field_display_name_value_3']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_3']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_3']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_3']['value'] = 'ADMIN';
  $handler->display->display_options['filters']['field_display_name_value_3']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_4']['id'] = 'field_display_name_value_4';
  $handler->display->display_options['filters']['field_display_name_value_4']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_4']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_4']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_display_name_value_4']['value'] = ',';
  $handler->display->display_options['filters']['field_display_name_value_4']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_5']['id'] = 'field_display_name_value_5';
  $handler->display->display_options['filters']['field_display_name_value_5']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_5']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_5']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_5']['value'] = 'zz';
  $handler->display->display_options['filters']['field_display_name_value_5']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_6']['id'] = 'field_display_name_value_6';
  $handler->display->display_options['filters']['field_display_name_value_6']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_6']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_6']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_6']['value'] = 'XT:';
  $handler->display->display_options['filters']['field_display_name_value_6']['group'] = 1;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value_7']['id'] = 'field_display_name_value_7';
  $handler->display->display_options['filters']['field_display_name_value_7']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value_7']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value_7']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_display_name_value_7']['value'] = 'OSMV,';
  $handler->display->display_options['filters']['field_display_name_value_7']['group'] = 1;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_1']['id'] = 'field_gal_title_value_1';
  $handler->display->display_options['filters']['field_gal_title_value_1']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_1']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_1']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['field_gal_title_value_1']['value'] = 'Owner:';
  $handler->display->display_options['filters']['field_gal_title_value_1']['group'] = 2;
  /* Filter criterion: User: Title (field_gal_title) */
  $handler->display->display_options['filters']['field_gal_title_value_2']['id'] = 'field_gal_title_value_2';
  $handler->display->display_options['filters']['field_gal_title_value_2']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['filters']['field_gal_title_value_2']['field'] = 'field_gal_title_value';
  $handler->display->display_options['filters']['field_gal_title_value_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_gal_title_value_2']['group'] = 2;
  $handler->display->display_options['path'] = 'user/%/followers';

  /* Display: Block: Following */
  $handler = $view->new_display('block', 'Block: Following', 'block_following');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Following';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'relationships-following-block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_following2';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_image' => array(
      'element_type' => '',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['label'] = 'total record count';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '@total';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'haven\'t started following';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div id="not-following"><p>Not following anyone. Find colleagues to follow on the <a href="/employees">Employees Profile Page</a>.</p></div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '<a href="/employees/[name]"><img src=[field_image] alt="[field_display_name]" title="[field_display_name]" /></a>';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'follow_thumbs',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requester user */
  $handler->display->display_options['arguments']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requester_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['requester_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['requester_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requester_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requester_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Display Name (field_display_name) */
  $handler->display->display_options['filters']['field_display_name_value']['id'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['filters']['field_display_name_value']['field'] = 'field_display_name_value';
  $handler->display->display_options['filters']['field_display_name_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_display_name_value']['value'] = 'Employee News';
  $handler->display->display_options['block_description'] = 'views - following';

  /* Display: Block: Followers */
  $handler = $view->new_display('block', 'Block: Followers', 'block_followers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Followers';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'relationships-followers-block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_followers2';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '2';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_image' => array(
      'element_type' => '',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['label'] = 'total record count';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '@total';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'have no followers';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div id="no-followers"><p> Currently, you have no followers. When your colleagues follow you, they will appear here.</p></div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Display Name */
  $handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
  $handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
  $handler->display->display_options['fields']['field_display_name']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_display_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_gal_title']['id'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['table'] = 'field_data_field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['field'] = 'field_gal_title';
  $handler->display->display_options['fields']['field_gal_title']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_gal_title']['label'] = '';
  $handler->display->display_options['fields']['field_gal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gal_title']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '<a href="/employees/[name]"><img src=[field_image] alt="[field_display_name]" title="[field_display_name]" /></a>';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'follow_thumbs',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['block_description'] = 'views - followers';
  $export['people_admin'] = $view;

  return $export;
}
