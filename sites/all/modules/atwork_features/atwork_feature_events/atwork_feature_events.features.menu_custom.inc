<?php
/**
 * @file
 * atwork_feature_events.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function atwork_feature_events_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-main-menu-zen.
  $menus['menu-main-menu-zen'] = array(
    'menu_name' => 'menu-main-menu-zen',
    'title' => 'Main Menu Zen',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main Menu Zen');

  return $menus;
}
