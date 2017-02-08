<?php
/**
 * @file
 * homepage_activity_feed_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function homepage_activity_feed_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ad_space-field_content'.
  $field_instances['node-ad_space-field_content'] = array(
    'bundle' => 'ad_space',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_content',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'authcache' => array(
        'clients' => array(
          'authcache_ajax' => array(
            'status' => 1,
            'weight' => 0,
          ),
        ),
        'fallback' => 'cancel',
        'lifespan' => 3600,
        'perpage' => 0,
        'peruser' => 1,
        'status' => 0,
      ),
      'display_summary' => 0,
      'semantic_field_format' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 165,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_label_summary' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_summary' => 165,
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-ad_space-field_hashtags'.
  $field_instances['node-ad_space-field_hashtags'] = array(
    'bundle' => 'ad_space',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hashtags',
    'label' => 'Hashtags',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-ad_space-field_image_adspace'.
  $field_instances['node-ad_space-field_image_adspace'] = array(
    'bundle' => 'ad_space',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_adspace',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'alt_field_default' => '',
      'alt_field_hide' => 0,
      'alt_field_sync_title' => 1,
      'alt_field_update_on_edit' => 1,
      'default_image' => 21941,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => 'announcement/image/[current-date:custom:Y]/[current-date:custom:m][current-date:custom:d]',
        ),
        'redirect' => 0,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '1 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'semantic_field_format' => '',
      'title_field' => 1,
      'title_field_default' => '',
      'title_field_hide' => 0,
      'title_field_update_on_edit' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'adobe_creative_sdk_enabled' => 0,
        'adobe_creative_sdk_position' => 0,
        'aviary_feather_enabled' => 0,
        'aviary_feather_position' => 0,
        'deviantartmuro_enabled' => 0,
        'deviantartmuro_position' => 0,
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imageeditor' => 0,
            'imce' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imageeditor' => array(
            'source_imageeditor_image' => 0,
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'flauntr_styler_enabled' => 0,
        'flauntr_styler_position' => 0,
        'fotoflexer_enabled' => 0,
        'fotoflexer_position' => 0,
        'imageeditor_icons_position' => 'bottom',
        'imageeditor_inline_revert_enabled' => 0,
        'imageeditor_inline_revert_position' => 0,
        'imageeditor_mailru_camera_enabled' => 0,
        'imageeditor_mailru_camera_position' => 0,
        'imageeditor_photobooth_enabled' => 0,
        'imageeditor_photobooth_position' => 0,
        'imageeditor_replace' => 0,
        'imageeditor_scriptcam_enabled' => 0,
        'imageeditor_scriptcam_position' => 0,
        'imageeditor_webcam_enabled' => 0,
        'imageeditor_webcam_position' => 0,
        'imageshack_upload_enabled' => 0,
        'imageshack_upload_position' => 0,
        'immio_upload_enabled' => 0,
        'immio_upload_position' => 0,
        'insert' => 1,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__article_-_right_sidebar__240_wide_' => 0,
          'colorbox__atwork_newsletter_feature_image' => 0,
          'colorbox__atwork_newsletter_other_image' => 0,
          'colorbox__block' => 0,
          'colorbox__blogger_photo' => 0,
          'colorbox__classified_full' => 0,
          'colorbox__classified_teaser' => 0,
          'colorbox__classified_thumb' => 0,
          'colorbox__ecard_thumb' => 0,
          'colorbox__employee_landing_page' => 0,
          'colorbox__exec_profile_landing__226x193' => 0,
          'colorbox__follow_thumbs' => 0,
          'colorbox__gallery_image' => 0,
          'colorbox__gallery_image_small' => 0,
          'colorbox__gallery_import' => 0,
          'colorbox__group_home_page__184x138_' => 0,
          'colorbox__homepage_block' => 0,
          'colorbox__homepage_block_image' => 0,
          'colorbox__homepage_feature' => 0,
          'colorbox__homepage_image' => 0,
          'colorbox__homepage_photos' => 0,
          'colorbox__homepage_slideshow' => 0,
          'colorbox__icon_image' => 0,
          'colorbox__inline_image' => 0,
          'colorbox__large' => 0,
          'colorbox__media_thumbnail' => 0,
          'colorbox__medium' => 0,
          'colorbox__news___poll_style__231x174_' => 0,
          'colorbox__node_full' => 0,
          'colorbox__node_image' => 0,
          'colorbox__node_med' => 0,
          'colorbox__node_small' => 0,
          'colorbox__profile_thumbs_med' => 0,
          'colorbox__related_content' => 0,
          'colorbox__teaser_image' => 0,
          'colorbox__threshold-480' => 0,
          'colorbox__threshold-768' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__tiled_image' => 0,
          'colorbox__tiled_image_first' => 0,
          'colorbox__user_picture' => 0,
          'colorbox__user_thumb' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_article_-_right_sidebar__240_wide_' => 0,
          'image_atwork_newsletter_feature_image' => 0,
          'image_atwork_newsletter_other_image' => 0,
          'image_block' => 0,
          'image_blogger_photo' => 0,
          'image_classified_full' => 0,
          'image_classified_teaser' => 0,
          'image_classified_thumb' => 0,
          'image_ecard_thumb' => 0,
          'image_employee_landing_page' => 0,
          'image_exec_profile_landing__226x193' => 0,
          'image_follow_thumbs' => 0,
          'image_gallery_image' => 0,
          'image_gallery_image_small' => 0,
          'image_gallery_import' => 0,
          'image_group_home_page__184x138_' => 0,
          'image_homepage_block' => 0,
          'image_homepage_block_image' => 0,
          'image_homepage_feature' => 0,
          'image_homepage_image' => 0,
          'image_homepage_photos' => 0,
          'image_homepage_slideshow' => 0,
          'image_icon_image' => 0,
          'image_inline_image' => 0,
          'image_large' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_news___poll_style__231x174_' => 0,
          'image_node_full' => 0,
          'image_node_image' => 0,
          'image_node_med' => 0,
          'image_node_small' => 0,
          'image_profile_thumbs_med' => 0,
          'image_related_content' => 0,
          'image_teaser_image' => 0,
          'image_threshold-480' => 0,
          'image_threshold-768' => 0,
          'image_thumbnail' => 0,
          'image_tiled_image' => 0,
          'image_tiled_image_first' => 0,
          'image_user_picture' => 0,
          'image_user_thumb' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'paintweb_enabled' => 0,
        'paintweb_position' => 0,
        'picmonkey_enabled' => 0,
        'picmonkey_position' => 0,
        'picozu_enabled' => 0,
        'picozu_position' => 0,
        'pixlr_editor_enabled' => 0,
        'pixlr_editor_position' => 0,
        'pixlr_express_enabled' => 0,
        'pixlr_express_position' => 0,
        'pixlr_upload_enabled' => 0,
        'pixlr_upload_position' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
        'snipshot_enabled' => 0,
        'snipshot_position' => 0,
        'sumopaint_enabled' => 0,
        'sumopaint_position' => 0,
        'svgedit_enabled' => 0,
        'svgedit_position' => 0,
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-ad_space-field_sticky_start_date'.
  $field_instances['node-ad_space-field_sticky_start_date'] = array(
    'bundle' => 'ad_space',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => '',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 4,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-ad_space-field_sticky_to_activity_feeds'.
  $field_instances['node-ad_space-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'ad_space',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-article-field_sticky_start_date'.
  $field_instances['node-article-field_sticky_start_date'] = array(
    'bundle' => 'article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 18,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-article-field_sticky_to_activity_feeds'.
  $field_instances['node-article-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'article',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-blog-field_sticky_start_date'.
  $field_instances['node-blog-field_sticky_start_date'] = array(
    'bundle' => 'blog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 10,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-blog-field_sticky_to_activity_feeds'.
  $field_instances['node-blog-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'blog',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-event-field_sticky_start_date'.
  $field_instances['node-event-field_sticky_start_date'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 12,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-event-field_sticky_to_activity_feeds'.
  $field_instances['node-event-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-forum-field_sticky_start_date'.
  $field_instances['node-forum-field_sticky_start_date'] = array(
    'bundle' => 'forum',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 6,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-forum-field_sticky_to_activity_feeds'.
  $field_instances['node-forum-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'forum',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-gallery-field_sticky_start_date'.
  $field_instances['node-gallery-field_sticky_start_date'] = array(
    'bundle' => 'gallery',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 8,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-gallery-field_sticky_to_activity_feeds'.
  $field_instances['node-gallery-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'gallery',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-page-field_sticky_start_date'.
  $field_instances['node-page-field_sticky_start_date'] = array(
    'bundle' => 'page',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-page-field_sticky_to_activity_feeds'.
  $field_instances['node-page-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'page',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-poll-field_sticky_start_date'.
  $field_instances['node-poll-field_sticky_start_date'] = array(
    'bundle' => 'poll',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 7,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-poll-field_sticky_to_activity_feeds'.
  $field_instances['node-poll-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'poll',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-section_page-field_sticky_start_date'.
  $field_instances['node-section_page-field_sticky_start_date'] = array(
    'bundle' => 'section_page',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 13,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-section_page-field_sticky_to_activity_feeds'.
  $field_instances['node-section_page-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'section_page',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 12,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-status_update-field_sticky_start_date'.
  $field_instances['node-status_update-field_sticky_start_date'] = array(
    'bundle' => 'status_update',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'semantic_field_format' => 0,
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 3,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_start_date',
    'label' => 'Sticky date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'M j Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'node-status_update-field_sticky_to_activity_feeds'.
  $field_instances['node-status_update-field_sticky_to_activity_feeds'] = array(
    'bundle' => 'status_update',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => 0,
        ),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'question' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'scs' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sticky_to_activity_feeds',
    'label' => 'Sticky to activity feeds',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'user-user-field_feed_options'.
  $field_instances['user-user-field_feed_options'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
      1 => array(
        'value' => 2,
      ),
      2 => array(
        'value' => 3,
      ),
      3 => array(
        'value' => 4,
      ),
      4 => array(
        'value' => 5,
      ),
      5 => array(
        'value' => 6,
      ),
      6 => array(
        'value' => 7,
      ),
      7 => array(
        'value' => 8,
      ),
      8 => array(
        'value' => 9,
      ),
      9 => array(
        'value' => 10,
      ),
      10 => array(
        'value' => 11,
      ),
      11 => array(
        'value' => 12,
      ),
      12 => array(
        'value' => 13,
      ),
      13 => array(
        'value' => 14,
      ),
      14 => array(
        'value' => 15,
      ),
      15 => array(
        'value' => 16,
      ),
      16 => array(
        'value' => 17,
      ),
      17 => array(
        'value' => 18,
      ),
      18 => array(
        'value' => 19,
      ),
      19 => array(
        'value' => 20,
      ),
      20 => array(
        'value' => 21,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'ecard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_feed_options',
    'label' => 'Feed Options',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 46,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Feed Options');
  t('Hashtags');
  t('Image');
  t('Sticky date');
  t('Sticky to activity feeds');

  return $field_instances;
}
