<?php
/**
 * @file
 * Custom styling for the Activity Feed pop up node/21100
 *
 */
?>


<div id="page" class="new-activity-window">

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


  <?php print render($page['header']); ?>

</header>

<div id="main">

  <div id="content" class="column" role="main">
    <?php print render($page['highlighted']); ?>
    <a id="main-content"></a>

    <div id="social-side"> 
      <?php print render($page['social_side']); ?>
    </div><!-- /#social-side -->

  </div><!-- /#content -->

</div><!-- /#main -->

</div><!-- /#page -->



<?php print render($page['bottom']); ?>


