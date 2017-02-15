<?php
/**
 * @file
 * atwork_lsa_features.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function atwork_lsa_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-lsa-admin.
  $menus['menu-lsa-admin'] = array(
    'menu_name' => 'menu-lsa-admin',
    'title' => 'LSA Admin',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('LSA Admin');
  t('Management');
  t('The <em>Management</em> menu contains links for administrative tasks.');

  return $menus;
}
