<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<!-- #page This is basically just a wrapper for styling. -->

  <header class="main-header">

    <?php 
      if ($site_name) {
        print '<h1 class="site-name"><a href="'. $front_page . '">' . $site_name . '</a></h1>';
        print '<a class="home-link" href="/"></a>';
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

  </header><!-- /.main-header -->

  <div id="main" class="clearfix" role="main">
    <section class="content inner">
      <div id="top-content">
        <i title="Print This Page" class="icon-print"></i>
        <?php if ($breadcrumb): ?>
          <div id="breadcrumb">
            <!-- START $breadcrumb -->
            <nav><?php print $breadcrumb; ?></nav>
            <!-- /END $breadcrumb -->
          </div>
        <?php endif; ?>

        <?php if ($page['content_top']): ?>
          <div id="content_top"><?php print render($page['content_top']) ?></div>
        <?php endif; ?>

        <?php if ($title): ?>
          <h2 class="main-title"><?php print $title; ?></h2>
        <?php endif; ?>

        <?php 
          if ($tabs && !empty($tabs)) {
            $rendered_tabs = render($tabs);
            if ($rendered_tabs) {
              print '<div class="tabs">'.render($tabs).'</div>';
            }
          }
        ?>

        <?php if ($messages): ?>
          <div id="messages">
            <!-- START $messages -->
            <?php print $messages; ?>
            <!-- /END $messages -->
          </div>
        <?php endif; ?>

        <?php print render($page['help']); ?>

        <?php if ($action_links): ?>
          <div>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          </div>
        <?php endif; ?>
        
        <?php if ($page['pre_content']): ?>
          <div id="pre-content"><?php print render($page['pre_content']) ?></div>
        <?php endif; ?>
          
        <!-- START content -->
        <?php print render($page['content']) ?>
        <!-- /END content -->
      </div>

      <?php if ($page['sidebar_second']): ?>
        <aside id="sidebar-second" class="column sidebar second">
          <div id="sidebar-second-inner" class="inner">
            <?php print render($page['sidebar_second']); ?>
          </div>
        </aside>
      <?php endif; ?> <!-- /.sidebar.second -->

      <?php if ($page['content_bottom']): ?>
        <?php print render($page['content_bottom']) ?>
      <?php endif; ?> <!-- /END REGION 'content_bottom' -->
    </section> <!-- /.content.inner -->

    <?php if ($page['footer']): ?>
      <nav id="footer"><!-- should this be <footer>? -->
        <?php print render($page['footer']); ?>
        <span class="footer-copyright">Copyright &copy; 2010–<?php print date("Y"); ?> BC Public Service. All rights reserved.</span>
      </nav> <!-- /#footer -->
    <?php endif; ?>
  </div> <!-- /#main -->

</div> <!-- /#page -->