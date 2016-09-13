<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> article">
  <?php if ($display_submitted && $submitted): ?>
        <!--
          here we support the new (feb 2012) html5 datetime attr.
          see: http://www.brucelawson.co.uk/2012/best-of-time/
          "pubdate" is a boolean and (at the time of writing) may or may not 
          stay in the spec, but we leave it for now...
          For syntax/formatting see: http://www.w3.org/TR/html-markup/datatypes.html#common.data.datetime
        -->
        <?php print $submitted; ?>
      <?php endif; ?>
    <div class="content">
      <?php
        // We hide the subscription links and standard links now so that we can render them later.
        // comments are usually removed at this point via hook_node_load in @Work Comments Module
        hide($content['links']);
        hide($content['subscriptions_ui']);
        
        // just incase we aren't using atwork_comments
        if (isset($content['comments'])) {
          hide($content['comments']);
        }
        
        print render($content);
       ?>
    </div>

    <?php if (!empty($content['links']['terms']) || !empty($content['links'])): ?>

      <footer <?php if ($view_mode == 'teaser') { print 'class="teaser-footer"'; } ?>>

        <?php if (!empty($content['links']['terms'])): ?>
          <div class="terms"><?php print render($content['links']['terms']); ?></div>
        <?php endif;?>

        <?php if (!empty($content['links'])): ?>
          <div class="links"><?php print render($content['links']); ?></div>
        <?php endif; ?>

        <?php if (!empty($content['subscriptions_ui'])): ?>
          <div class="subscription-links"><?php print render($content['subscriptions_ui']); ?></div>
        <?php endif; ?>

      </footer>

    <?php endif; ?>

    <?php print render($content['comments']); ?>

</article> <!-- /#node-->