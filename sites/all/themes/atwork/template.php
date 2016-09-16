<?php

/*
 * Here we override the default HTML output of drupal.
 * refer to http://drupal.org/node/550722
 */

// Auto-rebuild the theme registry during theme development.
// Un-check this in the admin menus in production! :)
if (theme_get_setting('clear_registry')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

// alter some drupal default <head> element attrs
function atwork_html_head_alter(&$head_elements) {

  // remove the Drupal favicon link -- put the favicon.ico and apple-touch-icon.png in root dir of site!
  if (isset($head_elements['drupal_add_html_head_link:shortcut icon:'.$GLOBALS['base_url'].'/misc/favicon.ico'])) {
    unset($head_elements['drupal_add_html_head_link:shortcut icon:'.$GLOBALS['base_url'].'/misc/favicon.ico']);
  }

  // reset the meta charset for html5-y-ness.
  if (isset($head_elements['system_meta_content_type'])) {
    if (isset($head_elements['system_meta_content_type']['#attributes']['http-equiv'])) {
      unset($head_elements['system_meta_content_type']['#attributes']['http-equiv']);
    }
    if (isset($head_elements['system_meta_content_type']['#attributes']['content'])) {
      unset($head_elements['system_meta_content_type']['#attributes']['content']);
    }
    $head_elements['system_meta_content_type']['#attributes']['charset'] = 'utf-8';
  } else {
    $head_elements['system_meta_content_type']['#attributes']['charset'] = 'utf-8';
  }

  // While we are at it, remove the Drupal generator tag.
  // We are an intranet, Drupal cannot check our site for stats sadly (firewalled).
  if (isset($head_elements['system_meta_generator'])) {
    unset($head_elements['system_meta_generator']);
  }

  // gww.gov.bc.ca doesn't really have an RSS feed in the classic sense right now (policy issues). :( Remove this.
  // TODO: hardcode an RSS feed (with icon) on the site somewhere?
  if (isset($head_elements['drupal_add_html_head_link:alternate:' . $GLOBALS['base_url'] . '/rss.xml'])) {
    unset($head_elements['drupal_add_html_head_link:alternate:' . $GLOBALS['base_url'] . '/rss.xml']);
  }

}

/**
 * Preprocesses any non-default output for regions.
 *
 * @param array &$variables
 *   Template variables.
 */
function atwork_preprocess_region(&$vars) {
  if($vars['region'] == 'content_bottom' && $vars['is_front']) {
    // add a class to a region (in this case 'content_bottom')
    $vars['classes_array'][] = 'homepage-lower-column';
  }
}

/**
 * Preprocesses the wrapping HTML.
 *
 * @param array &$variables
 *   Template variables.
 */
function atwork_preprocess_html(&$vars) {
  // Setup IE meta tag to force IE rendering mode
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'content' =>  'IE=IE8,chrome=1',
      'http-equiv' => 'X-UA-Compatible',
    )
  );

  //  Mobile viewport optimized: h5bp.com/viewport
  $meta_viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' =>  'width=device-width',
    )
  );

  drupal_add_html_head($meta_viewport, 'meta_viewport');

  /*
    Add header meta tag for IE8 standards mode to head
    http://stackoverflow.com/questions/6156639/x-ua-compatible-is-set-to-ie-edge-but-it-still-doesnt-stop-compatibility-mode
    NOTE: we modify this now with an apache config -- LEAVE COMMENTED
  */
  // drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');

  // add user idir as class to body
  global $user;
  if (isset($user->name)) {
    $vars['classes_array'][] = 'idir-' . $user->name;
  }
  if (isset($user->roles)) {
    if (count($user->roles) == 1) {
      $vars['classes_array'][] = 'no-roles';
    }

    foreach ($user->roles as $role) {
      array_push($vars['classes_array'], str_replace(' ', '-', $role));
    }
  }
  // add body class 'has-subscriptions' if node has subscriptions
  if(isset($vars['page']['content']['system_main']['nodes'][arg(1)]['subscriptions_ui']['subscriptions_ui_form']['account'])) {
    $vars['classes_array'][] = 'has-subscriptions';
  }

  // don't allow use of sidebar-first on any page but the front page
  $two_sidebars = array_search('two-sidebars', $vars['classes_array']);
  if (!drupal_is_front_page() && $two_sidebars) {
    unset($vars['classes_array'][$two_sidebars]);
    $vars['classes_array'][] = 'sidebar-second';
  }
  $breadcrumb = drupal_get_breadcrumb();
  if (!$breadcrumb || count($breadcrumb) == 1 || !strpos($vars['page']['#children'], 'breadcrumb')) {
    $vars['classes_array'][] = 'no-breadcrumb';
  }
} // preprocess HTML

function atwork_preprocess_page(&$vars, $hook) {
  // tabs?
  if (!isset($vars['tabs']['#primary'][0])) {
    $vars['classes_array'][] = 'no-tabs';
  }
  if (isset($vars['node_title'])) {
    $vars['title'] = $vars['node_title'];
  }
  // Adding classes wether #navigation is here or not
  if (!empty($vars['main_menu']) or !empty($vars['sub_menu'])) {
    $vars['classes_array'][] = 'with-navigation';
  }
  if (!empty($vars['secondary_menu'])) {
    $vars['classes_array'][] = 'with-subnav';
  }
  if(isset($vars['page']['sidebar_second']['boxes_premiers_awards_navigation'])) {
    // add a class to a region
    $vars['classes_array'][] = 'prem-award';
  }
  // add qTips 'in reply to' link: show on hover
  if(isset($vars['node']->type)) {
//    drupal_add_js(drupal_get_path('theme', 'atwork') . '/js/jquery_plugins/qtip/jquery.qtip.js');
//    //drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/qtip2/2.2.0/jquery.qtip.min.js', 'external');
//    drupal_add_css(drupal_get_path('theme', 'atwork') . '/js/jquery_plugins/qtip/jquery.qtip.css');
//    drupal_add_js('jQuery(document).ready(function() { jQuery(\'.node-type-forum .comment .submitted a[href^="/forum"][title]\').qtip(); });','inline');
  }

// FOR THEME SWITCHER BETA RELAUNCH
  global $user;
  // Hide switch block
  if(!in_array('Beta Tester', $user->roles)){
    drupal_add_css(drupal_get_path('theme', 'atwork') . '/beta_specific.css');
  }

}

function atwork_preprocess_node(&$vars) {
  // Add a striping class.
  $vars['classes_array'][] = 'node-' . $vars['zebra'];

  $node = $vars['node'];

  //dpm($node);
  if (!isset($node->type)) {
    return;
  }
  //dpm($vars);


  // edit submitted by
  if ($node->type == 'wiki' && $node->revision_uid > 1) {
    $author = user_load($node->revision_uid);
    $author_variables = array(
          'account' => $author,
          'uid' => $author->uid,
          'new_window' => FALSE,
          'name' => $author->name,
          'extra' => '',
          'attributes_array' => array(),
        );
    $name = theme('username', $author_variables);

    $vars['submitted'] = '<p class="submitted posted-date">Last updated: <time pubdate datetime="' .
                            date('Y-m-d', $node->changed) . 'T' . date('G:iO', $node->changed) . '">' .
                            format_date($node->changed, 'medium') .
                            '</time> by <span class="atwork-author">' .
                            $name . '</span></p>';
  }
  else {
    $author = user_load($node->uid);
    if(isset($author->uid) && isset($author->name)){
      $author_variables = array(
            'account' => $author,
            'uid' => $author->uid,
            'new_window' => FALSE,
            'name' => $author->name,
            'extra' => '',
            'attributes_array' => array(),
          );
    }

    if(!isset($author_variables)) {
      $author_variables = array(
        'account' => $author,
        'uid' => 0,
        'new_window' => FALSE,
        'name' => 'Employee News',
        'extra' => '',
        'attributes_array' => array()
        );
    }

    $name = theme('username', $author_variables);

    $vars['submitted'] = '<p class="submitted posted-date">Posted: <time pubdate datetime="' .
                            date('Y-m-d', $node->created) . 'T' . date('G:iO', $node->created) . '">' .
                            format_date($node->created, 'medium') .
                            '</time> by <span class="atwork-author">' .
                            $name . '</span></p>';
  }
}

function atwork_preprocess_field(&$variables, $hook) {
  //dpm($variables);
  //$variables['theme_hook_suggestions'][] = 'field';
  if($variables['element']['#field_name'] == 'field_tags' ) {
    // nothing here yet!
  }
}

// Alter feild tags that are changed via the semantic feilds module.
// add in a tag icon to the tags heading
function atwork_semantic_field__field_tags(&$variables) {
  $output = '';
  // Token support for nodes
  if (module_exists('token') == TRUE) {
    global $user;

    if (arg(0) == 'node') {
      $nid = arg(1);
    }
    if (isset($nid)) {
      $node = node_load($nid);
      $data = array('node' => $node, 'user' => $user);
    }
  }
  $tag_icon = '<i class="icon-tag"></i> ';
  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    if (!empty($variables['label_element'])) {
      $output .= $tag_icon . '<' . $variables['label_element'] . ' class="' . $variables['label_classes'] . '"' . $variables['title_attributes'] . '>';
    }
    $output .= $variables['label'] . $variables['label_suffix'] . '&nbsp;';
    if (!empty($variables['label_element'])) {
      $output .= '</' . $variables['label_element'] . '>';
    }
  }
  // Render the items.
  if (!empty($variables['content_element'])) {
    $output .= '<' . $variables['content_element'] . ' class="' . $variables['content_classes'] . '"' . $variables['content_attributes'] . '>';
  }
  foreach ($variables['items'] as $delta => $item) {
    if ($variables['item_element']) {
      $output .= '<' . $variables['item_element'] . ' class="' . $variables['item_classes'][$delta] . '"' . $variables['item_attributes'][$delta] . '>';
    }
    $output .= drupal_render($item);
    if ($variables['item_element']) {
      $output .= '</' . $variables['item_element'] . '>';
    }
    if (!empty($variables['item_separator']) && $delta < (count($variables['items']) - 1)) {
      $output .= $variables['item_separator'];
    }
  }
  if (!empty($variables['content_element'])) {
    $output .= '</' . $variables['content_element'] . '>';
  }
  // Render the top-level DIV.
  if (!empty($variables['field_element'])) {
    $output = '<' . $variables['field_element'] . ' class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</' . $variables['field_element'] . '>';
  }
  // Add a prefix and suffix to the field, if specified
  if (!empty($variables['field_prefix'])) {
    $output = $variables['field_prefix'] . $output;
  }
  if (!empty($variables['field_suffix'])) {
    $output .= $variables['field_suffix'];
  }
  if (isset($nid)) {
    return token_replace($output, $data);
  }
  else {
    return $output;
  }
}

function atwork_preprocess_block(&$vars, $hook) {
  // Add a striping class.
  $vars['classes_array'][] = 'block-' . $vars['zebra'];
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function atwork_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('atwork_breadcrumb');
  if ($show_breadcrumb == 'yes' || ($show_breadcrumb == 'admin' && arg(0) == 'admin')) {

    // Optionally get rid of the homepage link.
    $show_breadcrumb_home = theme_get_setting('atwork_breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }

    // Return the breadcrumb with separators.
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = theme_get_setting('atwork_breadcrumb_separator');
      $trailing_separator = $title = '';
      if (theme_get_setting('atwork_breadcrumb_title')) {
        $item = menu_get_item();
        if (!empty($item['tab_parent'])) {
          // If we are on a non-default tab, use the tab's title.
          $title = check_plain($item['title']);
        }
        else {
          $title = drupal_get_title();
        }
        if ($title) {
          $trailing_separator = $breadcrumb_separator;
        }
      }
      elseif (theme_get_setting('atwork_breadcrumb_trailing')) {
        $trailing_separator = $breadcrumb_separator;
      }

      return '<h2 class="breadcrumb">' . implode($breadcrumb_separator, $breadcrumb) . $trailing_separator . $title . '</h2>';
    }
  }
  // Otherwise, return an empty string.
  return '';
}

/*
 *   Converts a string to a suitable html ID attribute.
 *
 *    http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 *    valid ID attribute in HTML. This function:
 *
 *   - Ensure an ID starts with an alpha character by optionally adding an 'n'.
 *   - Replaces any character except A-Z, numbers, and underscores with dashes.
 *   - Converts entire string to lowercase.
 *
 *   @param $string
 *     The string
 *   @return
 *     The converted string
 */
function atwork_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id'. $string;
  }
  return $string;
}

/**
 * Generate the HTML output for a menu link and submenu.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: Structured array data for a menu link.
 *
 * @return
 *   A themed HTML string.
 *
 * @ingroup themeable
 */
function atwork_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  // Adding a class depending on the TITLE of the link (not constant)
  $element['#attributes']['class'][] = atwork_id_safe($element['#title']);
  // Adding a class depending on the ID of the link (constant)
  $element['#attributes']['class'][] = 'mid-' . $element['#original_link']['mlid'];
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Override or insert variables into theme_menu_local_task().
 */
function atwork_preprocess_menu_local_task(&$variables) {
  $link =& $variables['element']['#link'];

  // If the link does not contain HTML already, check_plain() it now.
  // After we set 'html'=TRUE the link will not be sanitized by l().
  if (empty($link['localized_options']['html'])) {
    $link['title'] = check_plain($link['title']);
  }
  $link['localized_options']['html'] = TRUE;
  $link['title'] = '<span class="tab">' . $link['title'] . '</span>';
}


function atwork_menu_local_task($variables) {
  $extra_class = '';
  if (isset($variables['element']['#link']['path']) && strpos(' ' . $variables['element']['#link']['path'], 'node/%/')) {
    $extra_class = ' ' . str_replace('node/%/', '', $variables['element']['#link']['path']);
  }

  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  if (isset($link['description']) && $link['description']) {
    $link['localized_options']['attributes']['title'] = $link['description'];
  }

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }

    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  return '<li' . (!empty($variables['element']['#active']) ? ' class="active' . $extra_class . '"' : '') . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/*
 *  Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function atwork_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
//    foreach ($variables['primary'] as $key => $tab) {
//      if (isset($tab['#link']['path']) && strpos(' ' . $tab['#link']['path'], 'node/%/')) {
//        dpm('.');
//        $variables['primary'][$key]['attributes']['class'][] = str_replace('node/%/', '', $tab['#link']['path']);
//      }
//    }
//
//    dpm($variables);


   // $variables['primary']['#prefix'] = '';
    $variables['primary']['#prefix'] = '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    //$variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] = '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;

}

/**
 * Override of theme_forward_email
 *
 * @param $variables
 *   An array of email variables
 */
function atwork_forward_email($variables) {
  $vars = $variables['vars'];

  $vars['forward_message'] = str_replace('&quot;', '', strip_tags($vars['forward_message']));

  // redo the teaser
  if (isset($vars['content']->content['body'][0]['#markup'])) {
    $vars['content']->teaser = $vars['content']->content['body'][0]['#markup'];
  }

  $output = '
<html>
  <body>
    <table cellspacing="0" cellpadding="10" border="0">
      <thead>
        <tr><td><h1 style="font-family: Arial, Helvetica, sans-serif; font-size: 18px;">' . l($vars['site_name'], 'forward/emailref', array('absolute' => TRUE, 'query' => array('path' => $vars['path']), 'html' => TRUE)) . '</h1></td></tr>
      </thead>
      <tbody>
        <tr>
          <td style="font-family: Arial, Helvetica, sans-serif; font-size: 12px;">' .
            $vars['forward_message'];
  if ($vars['message']) {
    $output .= '<p>' . t('Message from Sender') . ':</p><p>' . $vars['message'] . '</p>';
  }
  $output .= '<h2 style="font-size: 14px;">' . l($vars['content']->title, 'forward/emailref', array('absolute' => TRUE, 'query' => array('path' => $vars['path']))) . '</h2>';
  if (variable_get('node_submitted_' . $vars['content']->type)) {
    $output .= '<p><em>'.((!empty($vars['content']->name)) ? t('by %author', array('%author' => $vars['content']->name)) : t('by %author', array('%author' => variable_get('anonymous' , 'Anonymous')))).'</em></p>';
  }
  $output .= '<div>' . $vars['content']->teaser . '</div><p>' . l(t('Click here to read more on our site'), 'forward/emailref', array('absolute' => TRUE, 'query' => array('path' => $vars['path']))) . '</p>';
  $output .= '
          </td>
        </tr>
        <tr><td style="font-family: Arial, Helvetica, sans-serif; font-size: 12px;">' . $vars['dynamic_content'] . '</td></tr>
        <tr><td style="font-family: Arial, Helvetica, sans-serif; font-size: 12px;">' . $vars['forward_ad_footer'] . '</td></tr>
        <tr><td style="font-family: Arial, Helvetica, sans-serif; font-size: 12px;">' . $vars['forward_footer'] . '</td></tr>
      </tbody>
    </table>
  </body>
</html>
  ';

  return $output;
}

/**
 * Override theme_field_collection_view formatter.
 *
 * Support accordian based answers to save space
 *
 */
function atwork_field_collection_view($variables) {

  $fcid = reset(array_keys($variables['element']['entity']['field_collection_item']));
  $field_collection = field_collection_item_load($fcid);

  $question_field = '';
  switch ($field_collection->field_name) {
    case 'field_career':
      $question_field = 'field_career_question';
      break;
    case 'field_personal':
      $question_field = 'field_personal_question';
      break;
    case 'field_philosophy_influences':
      $question_field = 'field_philosophy_question';
      break;
  }

  if ($question_field) {

    $display = field_get_items('field_collection_item', $field_collection, 'field_display');
    $answer = field_get_items('field_collection_item', $field_collection, 'field_answer');

    $question = field_get_items('field_collection_item', $field_collection, $question_field);
    $question_info = field_info_instance('field_collection_item', $question_field, $field_collection->field_name);
    $questions = list_extract_allowed_values($question_info['widget']['settings']['select_list_options'], 'list_text', FALSE);
    if (is_numeric($question[0]['value'])) {
      $question[0]['value'] = $questions[$question[0]['value']];
    }

    if ($display[0]['value'] == 1 && $question[0]['value'] && $answer[0]['value']) {
      drupal_add_library('system', 'drupal.collapse');

      $dom = filter_dom_load($variables['element']['#children']);
      $xpath = new DOMXPath($dom);
      foreach ($xpath->query('//ul[@class="field-collection-view-links"]') as $links) {
        $field_collection_links = $dom->saveXML($links);
      }

      $class = str_replace('_', '-', $field_collection->field_name);

      $variables['element']['#children'] = <<<EOT
<div class="entity entity-field-collection-item field-collection-item-$class clearfix" about="/field-collection/$class/$fcid" typeof="">
  <div class="content">
    <fieldset class=" collapsible collapsed">
      <legend><span class="fieldset-legend">{$question[0]['value']}</span></legend>
      <div class="fieldset-wrapper">
        {$answer[0]['value']}
      </div>
    </fieldset>
 </div>
</div>
EOT;
    }
  }

  $element = $variables['element'];
  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}


/**
 * Theme rate button OVERRIDE.
 *
 * @param array $variables
 * @return string
 */
function atwork_rate_button($variables) {
  $text = $variables['text'];
  $href = $variables['href'];
  $class = $variables['class'];
  static $id = 0;
  $id++;

  $classes = 'rate-button';
  if ($class) {
    $classes .= ' ' . $class;
  }
  if (empty($href)) {
    // Widget is disabled or closed.
    return '<span class="' . $classes . '" id="rate-button-' . $id . '">' .
      '<i class="icon-thumbs-up"></i></span>';
  }
  else {
    return '<a class="' . $classes . '" id="rate-button-' . $id . '" rel="nofollow" href="' . htmlentities($href) . '" title="' . check_plain($text) . '">' .
      '<i class="icon-thumbs-up"></i></a>';
  }
}


/**
 * Theme subscriptions page controls table.
 *
 * @param array $variables
 * @return string
 *
 * @ingroup themeable
 */
function atwork_subscriptions_form_table(array $variables) {
  $element = $variables['element'];
  $output = '';
  $rows = array();
  drupal_add_js(drupal_get_path('module', 'subscriptions') . '/subscriptions_tableselect.js', array('preprocess' => FALSE));
  $columns['checkboxes']      = array('data' => '', 'width' => '1%', 'class' => 'subscriptions-table select-all');
  $columns['labels']          = array('data' => t('Subscription'), 'width' => '18%');
  if (isset($element['send_interval']) && $element['send_interval']['#access']) {
    $columns['send_interval'] = array('data' => t('Send interval'), 'width' => '20%');
  }
  if (isset($element['send_updates']) && $element['send_updates']['#access']) {
    $columns['send_updates']  = array('data' => t('Updates&nbsp;to&nbsp;page&nbsp;content'), 'width' => '10%');
  }
  if (isset($element['send_comments']) && $element['send_comments']['#access'] && module_exists('comment')) {
    $columns['send_comments'] = array('data' => t('New&nbsp;comments&nbsp;posted'), 'width' => '10%');
  }

  // check whether we have an Author column
  if (isset($element['author'])) {
    foreach (element_children($element['checkboxes']) as $key) {
      foreach (element_children($element['checkboxes'][$key]) as $key1) {
        if ($key1 != -1) {
          $tr = 't';
          $columns['author'] = array('data' => $tr('Author'), 'width' => '20%');
        }
      }
    }
  }
  if (isset($element['extra_info'])) {
    $columns['extra_info']['data'] = $element['extra_info']['#title'];
  }
  $column_keys = array_keys($columns);
  unset($columns[end($column_keys)]['width']);  // let the last column grow

  if (isset($element['checkboxes'])) {
    foreach (element_children($element['checkboxes']) as $key) {
      foreach (element_children($element['checkboxes'][$key]) as $key1) {
        if (empty($element['checkboxes'][$key][$key1]['#disabled'])) {
          $element['checkboxes'][$key][$key1]['#attributes']['class'] = array('select-row');
        }
        $row = array();
        foreach ($column_keys as $colkey) {
          $row[] = drupal_render($element[$colkey][$key][$key1]);
        }
        $rows[] = $row;
      }
    }
  }
  if ($rows) {
    $output .= theme('table', array('header' => array_values($columns), 'rows' => $rows));
    //$output .= drupal_render($element);
  }
  return $output;
}


/**
 * Theme subscriptions node subform table.
 *
 * @param array $element
 *
 * @return string
 *
 * @ingroup themeable
 */
function atwork_subscriptions_ui_table($element) {
  $rows = array();
  $headers = array();
  $header_strings = array(
    array('class' => 'subscriptions-table', 'width' => '30%'),
    array('data'  => t('Updates&nbsp;to&nbsp;page&nbsp;content'), 'width' => '1*', 'style' => 'writing-mode: lr-tb'),
    array('data'  => t('New&nbsp;comments&nbsp;posted'))
  );
  $element = $element['element'];
  foreach (element_children($element['subscriptions']) as $key) {
    $row = array();
    foreach (array('subscriptions', 'updates', 'comments') as $eli => $elv) {
      if (isset($element[$elv]) && $element[$elv]['#access']) {
        $row[] = drupal_render($element[$elv][$key]);
        $headers[$eli] = $header_strings[$eli];
      }
    }
    $rows[] = $row;
  }
  $col_indexes = array_keys($headers);
  unset($headers[end($col_indexes)]['width']);
  $output = theme('table', array('header' => $headers, 'rows' => $rows));
  $output .= drupal_render_children($element);
  drupal_add_js(drupal_get_path('module', 'subscriptions') . '/subscriptions_tableselect.js');
  return $output;
}

function atwork_quiz_admin_summary($variables) {
  $quiz = $variables['quiz'];
  $questions = $variables['questions'];
  $score = $variables['score'];
  $summary = $variables['summary'];
  // To adjust the title uncomment and edit the line below:
  // drupal_set_title(check_plain($quiz->title));
  if (!$score['is_evaluated']) {
    drupal_set_message(t('This quiz has not been scored yet.'), 'warning');
  }

  foreach ($summary as &$value) {
    $value = html_entity_decode($value);
    if (trim($value) == '<p>&nbsp;</p>') {
      $value = '';
    }
  }

  // Display overall result.
  $output = '';
  $params = array('%num_correct' => $score['numeric_score'], '%question_count' => $score['possible_score']);
  $output .= '<div id="quiz_score_possible">' . t('This person got %num_correct of %question_count possible points.', $params) . '</div>' . "\n";
  $output .= '<div id="quiz_score_percent">' . t('Total score: @score %', array('@score' => $score['percentage_score'])) . '</div>' . "\n";
  if (isset($summary['passfail'])) {
    $output .= '<div id="quiz_summary">' . check_markup($summary['passfail'], $quiz->body['und'][0]['format']) . '</div>' . "\n";
  }
  if (isset($summary['result'])) {
    $output .= '<div id="quiz_summary">' . check_markup($summary['result'], $quiz->body['und'][0]['format']) . '</div>' . "\n";
  }

  // Get the feedback for all questions.
  require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'quiz') . '/quiz.pages.inc';
  $output .= drupal_render(drupal_get_form('quiz_report_form', $questions, TRUE, TRUE, TRUE));
  return $output;
}

function atwork_quiz_take_summary($variables) {
  $quiz = $variables['quiz'];
  $questions = $variables['questions'];
  $score = $variables['score'];
  $summary = $variables['summary'];
  // Set the title here so themers can adjust.
  drupal_set_title($quiz->title);

  foreach ($summary as &$value) {
    $value = html_entity_decode($value);
    if (trim($value) == '<p>&nbsp;</p>') {
      $value = '';
    }
  }

  // Display overall result.
  $output = '';
  if (!empty($score['possible_score'])) {
    if (!$score['is_evaluated']) {
      $msg = t('Parts of this @quiz have not been evaluated yet. The score below is not final.', array('@quiz' => QUIZ_NAME));
      drupal_set_message($msg, 'warning');
    }
    $output .= '<div id="quiz_score_possible">' . t('You got %num_correct of %question_count possible points.', array('%num_correct' => $score['numeric_score'], '%question_count' => $score['possible_score'])) . '</div>' . "\n";
    $output .= '<div id="quiz_score_percent">' . t('Your score: %score %', array('%score' => $score['percentage_score'])) . '</div>' . "\n";
  }
  if (isset($summary['passfail'])) {
    $output .= '<div id="quiz_summary">' . $summary['passfail'] . '</div>' . "\n";
  }
  if (isset($summary['result'])) {
    $output .= '<div id="quiz_summary">' . $summary['result'] . '</div>' . "\n";
  }
  // Get the feedback for all questions. These are included here to provide maximum flexibility for themers
  if ($quiz->display_feedback) {
    $form = drupal_get_form('quiz_report_form', $questions);
    $output .= drupal_render($form);
  }
  return $output;
}

/**
 * Create a direct relationship link
 */
function atwork_user_relationships_request_relationship_direct_link($variables) {
  $relate_to = $variables['relate_to'];
  $relationship_type = $variables['relationship_type'];
  //safety, revert to  a generic link
  if (!isset($relationship_type)) {
    return theme('user_relationships_request_relationship_link', array('relate_to' => $relate_to));
  }
  return l(
    t("Follow", array('%name' => format_username($relate_to)) + user_relationships_type_translations($relationship_type)),
    "relationship/{$relate_to->uid}/request/{$relationship_type->rtid}",
    array(
      'query' => drupal_get_destination(),
      'html'  => TRUE,
      'attributes' => array('class' => array('user_relationships_popup_link')),
    )
  );
}

/**
 * Remove relationship link
 */
function atwork_user_relationships_remove_link($variables) {
  $uid = $variables['uid'];
  $rid = $variables['rid'];
  return l(
    t('Stop Following'),
    "user/{$uid}/relationships/{$rid}/remove",
    array(
      'title' => array('title' => t('Stop Following')),
      'query' => drupal_get_destination(),
      'attributes' => array('class' => array('user_relationships_popup_link')),
    )
  );
}

function atwork_short_answer_user_answer($variables) {
  $answer = $variables['answer'];
  $correct = $variables['correct'];
  $header = array(t('Correct Answer'), t('Your Answer'));
  $row = array(array($correct, $answer));
  return theme('table', array('header' => $header, 'rows' => $row));
}


/*
 * Implementation of hook_process_page()
 *
 * Do some breadcrumb things because our site is weird
 * and sometimes uses breadcrumbs as a title
 */
function atwork_process_page(&$variables, $hooks){
  //dpm($variables);

  // get rid of titles
  if (arg(0) == 'blogs'
      || arg(0) == 'news'
      || arg(0) == 'ecards'
      || arg(0) == 'polls'
      || arg(0) == 'videos'
      || (arg(0) == 'classifieds' && arg(1) == 'list')
      || (arg(0) == 'wiki' && arg(1) == 'items')
      || (arg(0) == 'node' && arg(1) == 77)
      || (arg(0) == 'node' && arg(1) == 115)
  ) {
    $variables['title'] = '';
  }
  // do wikis here
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == 'discussion') {
    $variables['title'] = t('Discussion');
  }
  if ((arg(0) == 'wiki' && arg(1) == 'items')) {
    $variables['breadcrumb'] = '<h2 class="breadcrumb">' . l(t('Wikilumbia'), 'wiki') . '</h2>';
  }

  // revisions
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == 'revisions' && is_numeric(arg(3)) && arg(4) == 'view' && isset($variables['page']['content']['system_main']['nodes'][arg(1)])) {
    $node = $variables['page']['content']['system_main']['nodes'][arg(1)]['#node'];
    $variables['breadcrumb'] = '<h2 class="breadcrumb">' . l($node->title, 'node/' . $node->nid) . ' &raquo; ' . l(t('Revisions'), 'node/' . $node->nid . '/revisions') . '</h2>';
    $variables['title'] = t('Revision !num', array('!num' => $node->vid));
  }

  if (arg(0) == 'forum') {
    if (!arg(1)) {
      $variables['breadcrumb'] = '<h2 class="breadcrumb">' . l(t('Discussion Forum'), 'forum') . '</h2>';
    }
    else {
      $term = taxonomy_term_load(arg(1));
      if ($term) {
        $variables['breadcrumb'] = '<h2 class="breadcrumb">' . l(t('Discussion Forum'), 'forum') . ' &raquo; ' . l($term->name, 'forum/' . arg(1)) . '</h2>';
      }
    }
    $variables['title'] = '';
  }

  // get rid of breadcrumbs
  if (arg(0) == 'search'
     || (arg(0) == 'node' && arg(1) == 5548)
     || (arg(0) == 'employees')
     || (arg(0) == 'groups' && !arg(1))
  ) {
    $variables['breadcrumb'] = '';
  }

  if (arg(0) == 'node' && arg(1) == 'add' && !arg(2)) {
    $variables['breadcrumb'] =  l(t('@Work'), '<front>');
    $variables['title'] = t('Create Content');
    drupal_set_title(t('Create Content'));
  }

  if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2)) {
    $account = user_load(arg(1));
    $variables['breadcrumb'] = '<h2 class="breadcrumb">' . l(_atwork_display_name($account), 'user/' . $account->uid) . '</h2>';
    switch (arg(2)) {
      case 'subscriptions':
        $variables['title'] = t('Subscription Settings');
        break;
      case 'myresults':
        $variables['title'] = t('Quiz Results');
        break;
      case 'edit':
        $variables['title'] = t('Build Your Profile');
        break;
      case 'activity':
        $variables['title'] = t('News Feed');
        break;
    }
  }


  // disable tabs on hom page
  if (drupal_is_front_page()) {
    $variables['tabs'] = array();
    $variables['title'] = '';
  }

  if (!$variables['title']) {
    $variables['classes_array'][] = 'no-title';
  }

  if (request_path() == 'classifieds') {
    $variables['classes_array'][] = 'classified-homepage';
  }

  $variables['classes'] = implode(' ', $variables['classes_array']);
}
