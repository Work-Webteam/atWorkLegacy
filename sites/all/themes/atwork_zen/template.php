<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */

function atwork_zen_preprocess_page(&$variables, $hook) {
  // jquery.cookie plugin is not being loaded for all users
  // causing all jQuery and javascript to break in certain areas of the site
  drupal_add_library('system', 'jquery.cookie');
  //drupal_add_library('system', 'ui.cookie');


   // check if this is a node page
  if (isset($variables['page']['content']['system_main']['nodes'][arg(1)])) {
    $node = $variables['page']['content']['system_main']['nodes'][arg(1)]['#node'];

    $snipet = field_get_items('node', $node, 'field_snipet');

    if ($node->type == 'article' && !$snipet) {
      $snipet[0]['value'] = t('News Article');
    }

    if ($snipet) {
      $variables['title_prefix'] = $snipet[0]['value'];
    }
  }
  
  if (isset($variables['node']->type) && !empty($variables['node']->type) && ($variables['node']->type == 'simplenews')){
  	drupal_add_js('sites/all/themes/atwork_zen/js/newsletter.js');
  }
  
  if (isset($variables['node']->type) && !empty($variables['node']->type) && ($variables['node']->type == 'article')){
  	drupal_add_js('sites/all/themes/atwork_zen/js/article_sidebar_image.js');
  }
  	
}


/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function atwork_zen_preprocess_node(&$variables, $hook) {
  $node = $variables['node'];

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

    $variables['submitted'] = '<p class="submitted posted-date">Last updated: <time pubdate datetime="' .
                            date('Y-m-d', $node->changed) . 'T' . date('G:iO', $node->changed) . '">' .
                            format_date($node->changed, 'medium') .
                            '</time> by <span class="atwork-author">' .
                            $name . '</span></p>';
  }
  else {

    // if node is an image replace submitted info with that of it's gallery
    if ($node->type == 'image') {
      $gallery_nid = field_get_items('node', $node, 'field_gallery');

      if (isset($gallery_nid[0]['target_id'])) {
        $node = node_load($gallery_nid[0]['target_id']);
      }

    }

    $author = user_load($node->uid);
    $author_variables = array(
          'account' => $author,
          'uid' => $author->uid,
          'new_window' => FALSE,
          'name' => $author->name,
          'extra' => '',
          'attributes_array' => array(),
        );
    $name = theme('username', $author_variables);

    $variables['submitted'] = '<p class="submitted posted-date">Posted: <time pubdate datetime="' .
                            date('Y-m-d', $node->created) . 'T' . date('G:iO', $node->created) . '">' .
                            format_date($node->created, 'medium') .
                            '</time> by <span class="atwork-author">' .
                            $name . '</span></p>';
  }

  // all teasers are tiled - very different than full node view so give them their own template
  if (isset($variables['teaser']) && $variables['teaser'] && isset($variables['view'])) {
    $node = $variables['node'];

    $variables['theme_hook_suggestions'][] = 'node__tile';

    $variables['submitted'] = format_date($node->created, 'date_only');

    // delete our already-rendered links as they no longer belong on teasers
    if (isset($variables['content']['footer'])) {
      unset($variables['content']['footer']);
    }

    // and tags
    if (isset($variables['content']['field_tags'])) {
      unset($variables['content']['field_tags']);
    }

    if ($variables['id'] == 1) {
      $author = user_load($node->uid);
      $variables['submitted'] .= '<br />' . t('Posted by:') . ' ' . theme('username', array('account' => $author));
      if (isset($variables['content']['field_image'][0]['#image_style'])) {
        $variables['content']['field_image'][0]['#image_style'] = 'tiled_image_first';
      }

      // add the few links that appear on only the first teaser
      $variables['content']['read_more']['#markup'] = l(t('Read more &raquo;'), 'node/' . $node->nid, array('html' => TRUE));
      $variables['content']['read_more']['#weight'] = 100;
      $variables['content']['read_more']['#prefix'] = '<div class="read-more">';
      $variables['content']['read_more']['#suffix'] = '</div>';

      $ratings = rate_get_results('node', $node->nid, 1);

      $num_likes = '<span class="num-likes">' . _atwork_fa('thumbs-o-up') . ' ' . t('Likes') . ': ' . $ratings['count'] . '</span>';
      $num_comments = '<span class="num-comments">' . _atwork_fa('comment') . ' ' . t('Comments') . ': ' . $node->comment_count . '</span>';

      $variables['content']['footer'] = array(
        '#markup' => $num_comments . $num_likes,
        '#weight' => 101,
        '#prefix' => '<div class="tiled-node-links">',
        '#suffix' => '</div>',
      );

    }
    else {
      if (isset($variables['content']['field_image'][0]['#image_style'])) {
        $variables['content']['field_image'][0]['#image_style'] = 'tiled_image';
      }
    }

  }


  //dpm($variables);
}


/*
 * Implementation of hook_process_page()
 *
 * Do some stuff on the homepage
 */
function atwork_zen_process_page(&$variables, $hooks){

  // do wikis here
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == 'discussion') {
    $variables['title'] = t('Discussion');
  }

  if (arg(0) == 'node' && arg(1) == 'add' && !arg(2)) {
//    $variables['breadcrumb'] =  l(t('@Work'), '<front>');
//    $variables['title'] = t('Create Content');
//    drupal_set_title(t('Create Content'));
  }

  if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2)) {
    if(arg(2) == "following" || arg(2) == "followers"){
      return;
    }
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


}




/**
 * Implements hook_breadcrumb()
 * This is to change strange breadcrumbs that appear in search
 */

function atwork_zen_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    $output = '<nav class="breadcrumb" role="navigation">';
    $output .= '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // dpm($breadcrumb);
    if(arg(0)=='search')
    {
      unset($breadcrumb[1]);
      unset($breadcrumb[2]);
      unset($breadcrumb[3]);
      $breadcrumb[] = l(t('Search'), 'search');
    }

  $output .= '' . implode(" &#8250 ", $breadcrumb) . '</nav>';

  return $output;
  }
}


function atwork_zen_pager($variables) { // used to change 'previous' to just 'prev'. Overkill for whole function?

  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;
  // Having issues with undefined offsets - this line is to take care of that prior to using the above $vars.
  if((isset($pager_page_array[0]) && $pager_page_array[0] == -1) || !isset($pager_page_array) || empty($pager_total) || (isset($pager_page_array[2]) && $pager_page_array[2] == -1)){
    return;
  }
  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  if(isset($pager_total[$element]) && $pager_total[$element]){
    $pager_max = $pager_total[$element];
  } else {
    // We have to eject here if we don't have this variable, or we will run into exceptions below.
    // Mainly an error in for the followers/following blocks on profile page.
    $pager_max = -1;
  }
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ prev')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if (isset($pager_total[$element]) && $pager_total[$element] > 1) {
    if ($li_first && $li_first != 0) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous && $li_previous != 0) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

