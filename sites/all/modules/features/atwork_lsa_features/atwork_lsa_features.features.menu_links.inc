<?php
/**
 * @file
 * atwork_lsa_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function atwork_lsa_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_lsa-admin:admin/structure/menu/manage/menu-lsa-admin.
  $menu_links['management_lsa-admin:admin/structure/menu/manage/menu-lsa-admin'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-lsa-admin',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'LSA Admin',
    'options' => array(
      'identifier' => 'management_lsa-admin:admin/structure/menu/manage/menu-lsa-admin',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: menu-lsa-admin_lsa-admin:<nolink>.
  $menu_links['menu-lsa-admin_lsa-admin:<nolink>'] = array(
    'menu_name' => 'menu-lsa-admin',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'LSA Admin',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-lsa-admin_lsa-admin:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-lsa-admin_lsa-application:node/add/lsa-application.
  $menu_links['menu-lsa-admin_lsa-application:node/add/lsa-application'] = array(
    'menu_name' => 'menu-lsa-admin',
    'link_path' => 'node/add/lsa-application',
    'router_path' => 'node/add/lsa-application',
    'link_title' => 'LSA Application',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-lsa-admin_lsa-application:node/add/lsa-application',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-lsa-admin_lsa-admin:<nolink>',
  );
  // Exported menu link: menu-lsa-admin_lsa-dashboard:lsa-admin.
  $menu_links['menu-lsa-admin_lsa-dashboard:lsa-admin'] = array(
    'menu_name' => 'menu-lsa-admin',
    'link_path' => 'lsa-admin',
    'router_path' => 'lsa-admin',
    'link_title' => 'LSA Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-lsa-admin_lsa-dashboard:lsa-admin',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-lsa-admin_lsa-admin:<nolink>',
  );
  // Exported menu link: menu-lsa-admin_service-pin-application:node/add/lsa-pin-application.
  $menu_links['menu-lsa-admin_service-pin-application:node/add/lsa-pin-application'] = array(
    'menu_name' => 'menu-lsa-admin',
    'link_path' => 'node/add/lsa-pin-application',
    'router_path' => 'node/add/lsa-pin-application',
    'link_title' => 'Service Pin Application',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-lsa-admin_service-pin-application:node/add/lsa-pin-application',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-lsa-admin_lsa-admin:<nolink>',
  );
  // Exported menu link: menu-lsa-admin_service-pin-registrations:administration/long-service-pin.
  $menu_links['menu-lsa-admin_service-pin-registrations:administration/long-service-pin'] = array(
    'menu_name' => 'menu-lsa-admin',
    'link_path' => 'administration/long-service-pin',
    'router_path' => 'administration/long-service-pin',
    'link_title' => 'Service Pin Registrations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-lsa-admin_service-pin-registrations:administration/long-service-pin',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-lsa-admin_lsa-admin:<nolink>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('LSA Admin');
  t('LSA Application');
  t('LSA Dashboard');
  t('Service Pin Application');
  t('Service Pin Registrations');

  return $menu_links;
}
