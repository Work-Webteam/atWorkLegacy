<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<script type="text/javascript">

	//MAIN MENU TARGETING
	window.onload = function(){
		var a = [
   9181, 6897, 6524, 6534,
   6537, 6540, 6533, 9514, 6525,
   6895, 6536, 7916, 6535, 6532,
   6539, 6680, 9513, 6681, 6682,
   6530, 6531, 6522, 6538, 6526,
   6896, 11065, 12331, 21212, 6674,
   22868, 19493, 37208
   ];

   var c = document.getElementById('block-tb-megamenu-menu-main-menu-zen').getElementsByTagName('li');

   for(var i = 0; i < a.length; i++){
     for(var j = 0; j < c.length; j++){
      if(c[j].getAttribute("data-id") == a[i]){
       c[j].onclick = function(){
        var d = this.getElementsByTagName('a');
        return !window.open(d[0], '_blank');
      }
    }
  }
}
}
</script>


<div id="page">

  <header class="header" id="header" role="banner">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
    <?php endif; ?>
    <div id="header-box">
     <div id="home-link" alt="" title=""><a href="/index.php">&nbsp;</a> </div>
     <?php if ($site_name || $site_slogan): ?>
      <div class="header__name-and-slogan" id="name-and-slogan">
        <?php if ($site_name): ?>
          <h1 class="header__site-name" id="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if ($secondary_menu): ?>
    <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
      <?php print theme('links__system_secondary_menu', array(
        'links' => $secondary_menu,
        'attributes' => array(
          'class' => array('links', 'inline', 'clearfix'),
          ),
        'heading' => array(
          'text' => $secondary_menu_heading,
          'level' => 'h2',
          'class' => array('element-invisible'),
          ),
          )); ?>
    </nav>
  <?php endif; ?>

  <?php print render($page['header']); ?>

  </header>

  <div id="navigation">

      <?php if ($main_menu): ?>
        <nav id="main-menu" role="navigation" tabindex="-1">
          <?php
          // This code snippet is hard to modify. We recommend turning off the
          // "Main menu" on your sub-theme's settings form, deleting this PHP
          // code block, and, instead, using the "Menu block" module.
          // @see https://drupal.org/project/menu_block
          print theme('links__system_main_menu', array(
            'links' => $main_menu,
            'attributes' => array(
              'class' => array('links', 'inline', 'clearfix'),
              ),
            'heading' => array(
              'text' => t('Main menu'),
              'level' => 'h2',
              'class' => array('element-invisible'),
              ),
              )); ?>
        </nav>
      <?php endif; ?>

      <?php print render($page['navigation']); ?>

  </div><!-- /#navigation -->

  <?php print $breadcrumb; ?>
  <div id="main">

    <div id="content" class="column" role="main">
      <?php print render($page['highlighted']); ?>
      <a id="main-content"></a>

      <?php // ***GROUP SPECIFIC TITLE CHANGES*** ?>
      <?php if ($title): ?>
        <?php // change this for group ?>
        <?php $og_context = og_context(); ?>
        <?php if($og_context && (arg(0) == 'node') && is_numeric(arg(1)) && (arg(2) == NULL)): ?>
          <?php switch($node->type) {
            case 'article':
            case 'blog':
            case 'poll':
            case 'question':
            case 'section_page':
            case 'event':
              $group = node_load($og_context['gid']);
              $title_prefix = $title;
              $title = $group->title;
            break;
            default:
            break;
          }
          ?>
        <?php endif; ?>
        <?php // Sometimes we need to get the gid ourselves ?>
        <?php if(empty($og_context) && isset($node->og_group_ref['und'][0]['target_id'])): ?>
          <?php
            switch($node->type) {
              case 'article':
              case 'blog':
              case 'poll':
              case 'question':
              case 'section_page':
              case 'event':
                $group = node_load($node->og_group_ref['und'][0]['target_id']);
                $title_prefix = $title;
                $title = $group->title;
                break;
              default:
                break;
            }
          ?>
        <?php endif; ?>
      <?php endif ?>
      <?php // ***END GROUP SPECIFIC CHANGES*** ?>

      <?php if ($title_prefix): ?>
        <span class="pre-title-snipet"><?php print render($title_prefix); ?></span>
      <?php endif; ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print render($page['pre_tabs']); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <div id="social-side">
          <?php print render($page['social_side']); ?>
       </div>
      <?php print render($page['pre_content']); ?>
      <?php print render($page['content']); ?>
      <?php print render($page['post_content']); ?>
      <?php print $feed_icons; ?>
    </div><!-- /#content -->

    <?php
    // Render the sidebars to see if there's anything in them.
        $sidebar_first  = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>
    <?php if (isset($node) && isset($node->type) && $node->type == "image"): ?>
      <?php drupal_add_js(drupal_get_path('module', 'atwork_images') . '/' . 'js_atwork_images.js'); ?>
    <?php endif; ?>
  </div><!-- /#main -->

</div><!-- /#page -->

<?php if ($is_front):

    $interval   = REQUEST_TIME - variable_get('user_block_seconds_online', 900);
    $count_auth = admin_menu_session_count($interval, FALSE);
    if ($count_auth == 1) {
      $users_online = '<div id="users_online"><p> <strong><strong>' . $count_auth . ' </strong></strong> person is currently on @Work. </p></div>';
    }
    else{
      $users_online = '<div id="users_online"><p> <strong><strong>' . $count_auth . ' </strong></strong> people are currently on @Work.</p></div>';
    }
    if(isset($page['footer']['boxes_copyright_terms_user']['#markup']) && $page['footer']['boxes_copyright_terms_user']['#markup']){
      $page['footer']['boxes_copyright_terms_user']['#markup'] .= $users_online;
    }
endif; ?>

<?php print render($page['bottom']); ?>
<?php print render($page['footer']); ?>
