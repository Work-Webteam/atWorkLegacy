<?php
/**
 * @file
 * atwork_feature_events.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function atwork_feature_events_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-main-menu-zen_premiers-awards:node/245.
  $menu_links['menu-main-menu-zen_premiers-awards:node/245'] = array(
    'menu_name' => 'menu-main-menu-zen',
    'link_path' => 'node/245',
    'router_path' => 'node/%',
    'link_title' => 'Premier\'s Awards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-main-menu-zen_premiers-awards:node/245',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-main-menu-zen_corporate-programs:<nolink>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Premier\'s Awards');

  return $menu_links;
}
