<?php

/**
 * @file
 * advagg_authcache.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function advagg_authcache_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_admin_mode';
  $strongarm->value = '2';
  $export['advagg_admin_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_ajax_render_alter';
  $strongarm->value = 1;
  $export['advagg_ajax_render_alter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_brotli';
  $strongarm->value = FALSE;
  $export['advagg_brotli'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_bundler_active';
  $strongarm->value = 1;
  $export['advagg_bundler_active'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_bundler_admin_mode';
  $strongarm->value = '0';
  $export['advagg_bundler_admin_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_bundler_grouping_logic';
  $strongarm->value = '1';
  $export['advagg_bundler_grouping_logic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_bundler_max_css';
  $strongarm->value = '2';
  $export['advagg_bundler_max_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_bundler_max_js';
  $strongarm->value = '5';
  $export['advagg_bundler_max_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_cache_level';
  $strongarm->value = 3;
  $export['advagg_cache_level'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_combine_css_media';
  $strongarm->value = TRUE;
  $export['advagg_combine_css_media'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_convert_absolute_to_protocol_relative_path';
  $strongarm->value = 1;
  $export['advagg_convert_absolute_to_protocol_relative_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_convert_absolute_to_relative_path';
  $strongarm->value = 1;
  $export['advagg_convert_absolute_to_relative_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_core_groups';
  $strongarm->value = FALSE;
  $export['advagg_core_groups'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_cron_frequency';
  $strongarm->value = 82800;
  $export['advagg_cron_frequency'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_cron_timestamp';
  $strongarm->value = 1560918602;
  $export['advagg_cron_timestamp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_absolute_path';
  $strongarm->value = 0;
  $export['advagg_css_absolute_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_compressor';
  $strongarm->value = '2';
  $export['advagg_css_compressor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_compressor_file_settings';
  $strongarm->value = array(
    'sites__all__modules__contrib__admin_menu__admin_menu_toolbar__admin_menu_toolbar--css' => '-1',
  );
  $export['advagg_css_compressor_file_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_compress_inline';
  $strongarm->value = '0';
  $export['advagg_css_compress_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_compress_inline_if_not_cacheable';
  $strongarm->value = 0;
  $export['advagg_css_compress_inline_if_not_cacheable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_fix_type';
  $strongarm->value = TRUE;
  $export['advagg_css_fix_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_css_remove_empty_files';
  $strongarm->value = TRUE;
  $export['advagg_css_remove_empty_files'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_disable_on_admin';
  $strongarm->value = FALSE;
  $export['advagg_disable_on_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_disable_on_listed_pages';
  $strongarm->value = '';
  $export['advagg_disable_on_listed_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_enabled';
  $strongarm->value = TRUE;
  $export['advagg_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_font_cookie';
  $strongarm->value = 1;
  $export['advagg_font_cookie'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_font_fontfaceobserver';
  $strongarm->value = '4';
  $export['advagg_font_fontfaceobserver'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_font_no_fout';
  $strongarm->value = 0;
  $export['advagg_font_no_fout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_font_storage';
  $strongarm->value = 1;
  $export['advagg_font_storage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_force_https_path';
  $strongarm->value = 0;
  $export['advagg_force_https_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_global_counter';
  $strongarm->value = 249;
  $export['advagg_global_counter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_gzip';
  $strongarm->value = 1;
  $export['advagg_gzip'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_htaccess_symlinksifownermatch';
  $strongarm->value = 0;
  $export['advagg_htaccess_symlinksifownermatch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_ie_css_selector_limiter';
  $strongarm->value = FALSE;
  $export['advagg_ie_css_selector_limiter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_ie_css_selector_limiter_value';
  $strongarm->value = 4095;
  $export['advagg_ie_css_selector_limiter_value'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_include_base_url';
  $strongarm->value = 0;
  $export['advagg_include_base_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_compressor';
  $strongarm->value = '5';
  $export['advagg_js_compressor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_compressor_file_settings';
  $strongarm->value = array(
    'sites__all__modules__custom__atwork_activity__jquery--url--js' => '0',
    'sites__all__modules__custom__atwork_activity__js_atwork_activity_undock--js' => '0',
    'sites__all__modules__custom__atwork_lsa__atwork_lsa--js' => '0',
    'sites__all__modules__custom__atwork_lsa__atwork_lsa_gift--js' => '0',
    'sites__all__modules__custom__atwork_lsa__atwork_lsa_gift_list--js' => '0',
    'sites__all__modules__custom__presence__jellybean__init--js' => '0',
    'sites__all__themes__atwork_zen__js__SpryAssets__SpryCollapsiblePanel--js' => '0',
    'sites__all__themes__atwork_zen__js__SpryAssets__SpryTabbedPanels--js' => '0',
  );
  $export['advagg_js_compressor_file_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_compress_add_license';
  $strongarm->value = '1';
  $export['advagg_js_compress_add_license'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_compress_inline';
  $strongarm->value = '5';
  $export['advagg_js_compress_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_compress_inline_if_not_cacheable';
  $strongarm->value = 0;
  $export['advagg_js_compress_inline_if_not_cacheable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_compress_packer';
  $strongarm->value = 0;
  $export['advagg_js_compress_packer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_fix_type';
  $strongarm->value = TRUE;
  $export['advagg_js_fix_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_js_remove_empty_files';
  $strongarm->value = TRUE;
  $export['advagg_js_remove_empty_files'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_admin_mode';
  $strongarm->value = '2';
  $export['advagg_mod_admin_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_adjust_sort_browsers';
  $strongarm->value = TRUE;
  $export['advagg_mod_css_adjust_sort_browsers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_adjust_sort_external';
  $strongarm->value = TRUE;
  $export['advagg_mod_css_adjust_sort_external'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_adjust_sort_inline';
  $strongarm->value = TRUE;
  $export['advagg_mod_css_adjust_sort_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_defer';
  $strongarm->value = 4;
  $export['advagg_mod_css_defer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_defer_admin';
  $strongarm->value = TRUE;
  $export['advagg_mod_css_defer_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_defer_js_code';
  $strongarm->value = 0;
  $export['advagg_mod_css_defer_js_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_defer_pages';
  $strongarm->value = '';
  $export['advagg_mod_css_defer_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_defer_skip_first_file';
  $strongarm->value = 0;
  $export['advagg_mod_css_defer_skip_first_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_defer_visibility';
  $strongarm->value = 3;
  $export['advagg_mod_css_defer_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_head_extract';
  $strongarm->value = TRUE;
  $export['advagg_mod_css_head_extract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_css_preprocess';
  $strongarm->value = TRUE;
  $export['advagg_mod_css_preprocess'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_defer_inline_js_skip_list';
  $strongarm->value = '';
  $export['advagg_mod_defer_inline_js_skip_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_github_version_loadcss';
  $strongarm->value = '2.0.1';
  $export['advagg_mod_github_version_loadcss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_inline_css_pages';
  $strongarm->value = '';
  $export['advagg_mod_inline_css_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_inline_css_visibility';
  $strongarm->value = '1';
  $export['advagg_mod_inline_css_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_inline_js_pages';
  $strongarm->value = '';
  $export['advagg_mod_inline_js_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_inline_js_visibility';
  $strongarm->value = '1';
  $export['advagg_mod_inline_js_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_inline_pages';
  $strongarm->value = '';
  $export['advagg_mod_inline_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_inline_visibility';
  $strongarm->value = '1';
  $export['advagg_mod_inline_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_adjust_sort_browsers';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_adjust_sort_browsers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_adjust_sort_external';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_adjust_sort_external'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_adjust_sort_inline';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_adjust_sort_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_async';
  $strongarm->value = 0;
  $export['advagg_mod_js_async'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_async_in_header';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_async_in_header'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_async_shim';
  $strongarm->value = 0;
  $export['advagg_mod_js_async_shim'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_defer';
  $strongarm->value = 2;
  $export['advagg_mod_js_defer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_defer_inline_alter';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_defer_inline_alter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_defer_jquery';
  $strongarm->value = 0;
  $export['advagg_mod_js_defer_jquery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_footer';
  $strongarm->value = 3;
  $export['advagg_mod_js_footer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_footer_inline_alter';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_footer_inline_alter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_head_extract';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_head_extract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_inline_resource_hints';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_inline_resource_hints'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_no_ajaxpagestate';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_no_ajaxpagestate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_preprocess';
  $strongarm->value = TRUE;
  $export['advagg_mod_js_preprocess'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_js_remove_unused';
  $strongarm->value = 0;
  $export['advagg_mod_js_remove_unused'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_unified_multisite_dir';
  $strongarm->value = '';
  $export['advagg_mod_unified_multisite_dir'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_wrap_inline_js_skip_list';
  $strongarm->value = '';
  $export['advagg_mod_wrap_inline_js_skip_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_mod_wrap_inline_js_xpath';
  $strongarm->value = TRUE;
  $export['advagg_mod_wrap_inline_js_xpath'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_admin_mode';
  $strongarm->value = '2';
  $export['advagg_relocate_admin_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css';
  $strongarm->value = TRUE;
  $export['advagg_relocate_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_domains_blacklist';
  $strongarm->value = '';
  $export['advagg_relocate_css_domains_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_files_blacklist';
  $strongarm->value = '';
  $export['advagg_relocate_css_files_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_file_settings';
  $strongarm->value = array();
  $export['advagg_relocate_css_file_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_font_domains';
  $strongarm->value = 'fonts.googleapis.com';
  $export['advagg_relocate_css_font_domains'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_inline_external';
  $strongarm->value = TRUE;
  $export['advagg_relocate_css_inline_external'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_inline_import';
  $strongarm->value = TRUE;
  $export['advagg_relocate_css_inline_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_inline_import_browsers';
  $strongarm->value = array(
    'woff2' => 'woff2',
    'woff' => 'woff',
    'ttf' => 'ttf',
    'eot' => 0,
    'svg' => 0,
  );
  $export['advagg_relocate_css_inline_import_browsers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_css_ttl';
  $strongarm->value = '604800';
  $export['advagg_relocate_css_ttl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js';
  $strongarm->value = TRUE;
  $export['advagg_relocate_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_domains_blacklist';
  $strongarm->value = 'js.stripe.com
';
  $export['advagg_relocate_js_domains_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_fbds_local';
  $strongarm->value = TRUE;
  $export['advagg_relocate_js_fbds_local'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_fbevents_local';
  $strongarm->value = TRUE;
  $export['advagg_relocate_js_fbevents_local'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_fbevents_local_ids';
  $strongarm->value = '';
  $export['advagg_relocate_js_fbevents_local_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_files_blacklist';
  $strongarm->value = '';
  $export['advagg_relocate_js_files_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_ga_local';
  $strongarm->value = TRUE;
  $export['advagg_relocate_js_ga_local'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_gtm_local';
  $strongarm->value = TRUE;
  $export['advagg_relocate_js_gtm_local'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_piwik_local';
  $strongarm->value = TRUE;
  $export['advagg_relocate_js_piwik_local'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_relocate_js_ttl';
  $strongarm->value = '604800';
  $export['advagg_relocate_js_ttl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_remove_missing_files_from_db_time';
  $strongarm->value = 1209600;
  $export['advagg_remove_missing_files_from_db_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_remove_old_unused_aggregates_time';
  $strongarm->value = 3888000;
  $export['advagg_remove_old_unused_aggregates_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_resource_hints_dns_prefetch';
  $strongarm->value = TRUE;
  $export['advagg_resource_hints_dns_prefetch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_resource_hints_location';
  $strongarm->value = 1;
  $export['advagg_resource_hints_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_resource_hints_preconnect';
  $strongarm->value = TRUE;
  $export['advagg_resource_hints_preconnect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_resource_hints_preload';
  $strongarm->value = FALSE;
  $export['advagg_resource_hints_preload'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_resource_hints_preload_settings';
  $strongarm->value = array(
    'style' => array(
      '#weight' => '-10',
      'enabled' => 1,
      'external' => 1,
      'local' => 1,
      'push' => 0,
    ),
    'font' => array(
      '#weight' => '-9',
      'enabled' => 1,
      'external' => 1,
      'local' => 1,
      'push' => 0,
    ),
    'script' => array(
      '#weight' => '-8',
      'enabled' => 1,
      'external' => 1,
      'local' => 1,
      'push' => 0,
    ),
    'svg' => array(
      '#weight' => '-7',
      'enabled' => 1,
      'external' => 1,
      'local' => 1,
      'push' => 0,
    ),
    'image' => array(
      '#weight' => '-6',
      'enabled' => 1,
      'external' => 1,
      'local' => 1,
      'push' => 0,
    ),
    'all_others' => array(
      0 => FALSE,
      1 => TRUE,
    ),
  );
  $export['advagg_resource_hints_preload_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_resource_hints_use_immutable';
  $strongarm->value = TRUE;
  $export['advagg_resource_hints_use_immutable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_root_dir_prefix';
  $strongarm->value = 'public://';
  $export['advagg_root_dir_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_scripts_scope_anywhere';
  $strongarm->value = FALSE;
  $export['advagg_scripts_scope_anywhere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_skip_file_create_url_inside_css';
  $strongarm->value = TRUE;
  $export['advagg_skip_file_create_url_inside_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'advagg_use_httprl';
  $strongarm->value = TRUE;
  $export['advagg_use_httprl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_block-atwork_profiles-header';
  $strongarm->value = array(
    'status' => '1',
    'lifespan' => '518400',
    'peruser' => '1',
    'clients' => array(
      'authcache_ajax' => array(
        'status' => '1',
        'weight' => '0',
      ),
    ),
    'fallback' => 'cancel',
    'perpage' => 0,
  );
  $export['authcache_block-atwork_profiles-header'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_block-views-groups-block_2';
  $strongarm->value = array(
    'status' => '1',
    'lifespan' => '0',
    'peruser' => '1',
    'perpage' => '1',
    'clients' => array(
      'authcache_ajax' => array(
        'status' => '1',
        'weight' => '0',
      ),
    ),
    'fallback' => 'cancel',
  );
  $export['authcache_block-views-groups-block_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_debug_users';
  $strongarm->value = array(
    0 => 'clachamb_old_deactivated',
  );
  $export['authcache_debug_users'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_mimetype';
  $strongarm->value = 'text/html
text/javascript
text/plain
application/xml
application/atom+xml
';
  $export['authcache_mimetype'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_noajax';
  $strongarm->value = 1;
  $export['authcache_noajax'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_pagecaching';
  $strongarm->value = array(
    0 => array(
      'option' => '0',
      'pages' => 'user*
news/2016/0805/going-gold/olympic-quiz*
news/2016/0805/going-gold/*
news/2016/0805/going-gold/olympic-quiz/take
node/add/*
premiers-award-2018-application
premiers-award-2018-application*
premiers-award-2018-application/*
node/*/edit
node/*/track
tracker/*
comment/edit/*
civicrm/*
system/files/*
system/temporary*
file/ajax/*
js/admin_menu/cache/*
groups
groups/*
my-groups
groups/region-to-region/webform/*
premiers_awards
career/long-service-awards/form
career/long-service-awards/applications/*
premiers-award-2018-application
premiers-award-2018-application/*
career/long-service-awards/*
node/17274/*
news/2016/0805/going-gold/*
news/2016/0805/going-gold/olympic-quiz/*
news/*/take
career/premiers-awards/*
ecards/*
news/2017/0626/oh-canada/*
news/2017/0626/oh-canada/canada-150-quiz/*
news/2017/0626/oh-canada/canada-150-quiz/take/*
node/*/take/*
quiz/take/*
quiz/quiz-results/*
forward
news/2017/0929/healthy-workplace-month/quiz
news/2017/0929/healthy-workplace-month/quiz/*
news/2017/0929/healthy-workplace-month/quiz/take/*
news/2017/0929/healthy-workplace-month/quiz/quiz-results/*/view',
      'noadmin' => 1,
      'roles' => array(
        'custom' => '1',
        'roles' => array(
          1 => '1',
          2 => '2',
          4 => '4',
          5 => '5',
          6 => '6',
          7 => '7',
          8 => '8',
          10 => '10',
          11 => '11',
          12 => '12',
          13 => '13',
          15 => '15',
          16 => '16',
          17 => '17',
          18 => '18',
          19 => '19',
          20 => '20',
        ),
      ),
    ),
  );
  $export['authcache_pagecaching'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'authcache_roles';
  $strongarm->value = array(
    1 => '1',
    2 => '2',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    10 => '10',
    11 => '11',
    12 => '12',
    13 => '13',
    15 => '15',
    16 => '16',
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
  );
  $export['authcache_roles'] = $strongarm;

  return $export;
}
