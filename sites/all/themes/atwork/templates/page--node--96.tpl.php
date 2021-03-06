<!-- THE HOMEPAGE NODE! :) NODE# 96 -->

<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<!-- #page This is basically just a wrapper for styling. -->

  <header class="main-header">

    <?php 
      if ($site_name) {
          print '<h1 class="site-name"><a href="'. $front_page . '">' . $site_name . '</a></h1>';
      }
      if ($page['pagetop']) {
        print '<!-- HEADER region -->' . render($page['pagetop']) . '<!-- /HEADER region -->';
      }
    ?>

    <?php if ($main_menu): ?>
      <nav id="navigation" role="navigation" class="menu <?php if (!empty($main_menu)) {print "with-primary";} ?>">
        <?php print theme('links', array('links' => $main_menu, 'attributes' => array('id' => 'primary', 'class' => array('links', 'clearfix', 'main-menu')))); ?>
      </nav>
    <?php endif; ?>

    <!-- A placeholder element for the dropdown navigation on small screens -->
    <div id="dropdown-nav"></div>

  </header> <!-- /.main-header -->

  <div id="main" class="clearfix" role="main">

    <?php if ($messages): ?>
      <div id="messages">
        <!-- START $messages -->
        <?php print $messages; ?>
        <!-- /END $messages -->
      </div>
    <?php endif; ?>
    
    <?php if ($page['content_top']): ?>
          <div id="content_top"><?php print render($page['content_top']) ?></div>
    <?php endif; ?>

    <section class="content inner">

      <?php print render($page['help']); ?>

      <?php if ($action_links): ?>
        <div>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        </div>
      <?php endif; ?>

      <!-- START content -->
      <?php print render($page['content']) ?>
      <!-- /END content -->

      <?php if ($page['sidebar_first']): ?>
        <aside id="sidebar-first" class="column sidebar first homepage-lower-column">
          <div id="sidebar-first-inner" class="inner">
            <?php print render($page['sidebar_first']); ?>
          </div>
        </aside>
      <?php endif; ?> <!-- /.sidebar.first -->

      <?php if ($page['content_bottom']): ?>
        
        <?php print render($page['content_bottom']) ?>
      <?php endif; ?> <!-- /END 'content_bottom' -->

      <?php if ($page['sidebar_second']): ?>
        <aside id="sidebar-second" class="column sidebar second homepage-lower-column">
          <div id="sidebar-second-inner" class="inner">
            <?php print render($page['sidebar_second']); ?>
          </div>
        </aside>
      <?php endif; ?> <!-- /.sidebar.second -->

    </section> <!-- /.content.inner -->

    <?php if ($page['footer']): ?>
      <nav id="footer"><!-- should this be <footer>? -->
        <?php print render($page['footer']); ?>
      </nav> <!-- /#footer -->
    <?php endif; ?>

  </div> <!-- /#main -->

</div> <!-- /#page -->
