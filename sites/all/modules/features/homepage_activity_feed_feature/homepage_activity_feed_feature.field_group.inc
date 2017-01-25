<?php
/**
 * @file
 * homepage_activity_feed_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function homepage_activity_feed_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_js_files|node|article|form';
  $field_group->group_name = 'group_js_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi5';
  $field_group->data = array(
    'label' => 'Custom Code',
    'weight' => '10',
    'children' => array(
      0 => 'field_js_files',
      1 => 'field_js_effects',
      2 => 'cpn',
      3 => 'redirect',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Custom Code',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-js-files field-group-tab ',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_js_files|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi2|node|poll|form';
  $field_group->group_name = 'group_multi2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => ' - Poll Question and Options',
    'weight' => '2',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_promoted',
      2 => 'title',
      3 => 'path',
      4 => 'choice_wrapper',
      5 => 'settings',
      6 => 'redirect',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => ' - Poll Question and Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-multi2 ',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi2|node|poll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi4|node|blog|form';
  $field_group->group_name = 'group_multi4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => '- Blog Tags',
    'weight' => '18',
    'children' => array(
      0 => 'field_tags',
      1 => 'og_group_ref',
      2 => 'field_promoted',
      3 => 'cpn',
      4 => 'redirect',
      5 => 'group_js_files',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => '- Blog Tags',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'blog-step4',
        'description' => '<p>Choose some tags for your blog. Tags are keywords that reflect your blog’s content and theme. They help your colleagues to find information they’re looking for. Ideally you’ll want to choose no more than 2-3 tags. Make sure they’re specific and no more than 2-3 words each.</p>
<p>The tags available to you will automatically appear as you type the letters.</p>',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi4|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi4|node|section_page|form';
  $field_group->group_name = 'group_multi4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'section_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => 'Group Page Tags',
    'weight' => '21',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_tags',
      2 => 'field_exclude_from_search',
      3 => 'field_show_menu',
      4 => 'field_show_menu_siblings',
      5 => 'field_promoted',
      6 => 'cpn',
      7 => 'path',
      8 => 'redirect',
      9 => 'group_js_files',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Group Page Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-multi4 ',
        'description' => '<p>Choose some tags for your article. Tags are keywords that reflect your article’s content and theme. They help your colleagues to find information they’re looking for. Ideally you’ll want to choose no more than 2-3 tags. Make sure they’re specific and no more than 2-3 words each.</p>
<p>The tags available to you will automatically appear as you type the letters.</p>
<p>After adding your tags, you can add your group page to your menu. Click "Menu Settings" below and choose a  link title to appear in the group menu on the left side of your group page. Keep it short and relevant.</p>
<p>After adding your page to your menu, click on "Publishing Options" to make sure the "Published" checkbox is checked. Your new custom group page will show up in your menu after you save!</p> 
',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi4|node|section_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi5|node|article|form';
  $field_group->group_name = 'group_multi5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_multi';
  $field_group->data = array(
    'label' => 'News Tags',
    'weight' => '6',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_poll',
      2 => 'field_news',
      3 => 'path',
      4 => 'group_js_files',
      5 => 'group_relationship',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'News Tags',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'news-step5',
        'description' => '<p>Choose some tags for your article. Tags are keywords that reflect your article’s content and theme. They help your colleagues to find information they’re looking for. Ideally you’ll want to choose no more than 2-3 tags. Make sure they’re specific and no more than 2-3 words each.</p>
<p>The tags available to you will automatically appear as you type the letters.</p>',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_multi5|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi|node|article|form';
  $field_group->group_name = 'group_multi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'News Settings',
    'weight' => '0',
    'children' => array(
      0 => 'group_multi1',
      1 => 'group_multi2',
      2 => 'group_multi4',
      3 => 'group_multi5',
      4 => 'group_multi6',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'News Settings',
      'instance_settings' => array(
        'classes' => 'group-multi field-group-multipage-group ',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '0',
        'move_additional' => '0',
      ),
    ),
  );
  $field_groups['group_multi|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi|node|blog|form';
  $field_group->group_name = 'group_multi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Blog Settings',
    'weight' => '0',
    'children' => array(
      0 => 'group_multi1',
      1 => 'group_multi4',
      2 => 'group_multi3',
      3 => 'group_multi5',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Blog Settings',
      'instance_settings' => array(
        'classes' => '',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '0',
        'move_additional' => '0',
      ),
    ),
  );
  $field_groups['group_multi|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi|node|poll|form';
  $field_group->group_name = 'group_multi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Poll Settings',
    'weight' => '0',
    'children' => array(
      0 => 'group_multi1',
      1 => 'group_multi2',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Poll Settings',
      'instance_settings' => array(
        'classes' => '',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '1',
        'move_additional' => '0',
      ),
    ),
  );
  $field_groups['group_multi|node|poll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi|node|section_page|form';
  $field_group->group_name = 'group_multi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'section_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Page Settings',
    'weight' => '0',
    'children' => array(
      0 => 'group_multi1',
      1 => 'group_multi2',
      2 => 'group_multi3',
      3 => 'group_multi4',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-multi field-group-multipage-group ',
        'page_header' => 3,
        'move_additional' => 1,
        'page_counter' => 1,
        'move_button' => 0,
      ),
    ),
  );
  $field_groups['group_multi|node|section_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t(' - Poll Question and Options');
  t('- Blog Tags');
  t('Blog Settings');
  t('Custom Code');
  t('Group Page Settings');
  t('Group Page Tags');
  t('News Settings');
  t('News Tags');
  t('Poll Settings');

  return $field_groups;
}
