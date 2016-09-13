<?php
//dpm($content);
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> article">
    <header class="node-content">
      <h2><?php print render($content['title']); ?></h2>
      <p class="submitted posted-date">Posted: <time pubdate datetime="<?php print date('Y-m-d', $node->created).'T'.date('G:iO', $node->created) ?>"><?php print format_date($node->created, 'medium'); ?></time> by <?php print theme('username', array('account' => $user,'new_window' => TRUE,)); ?></p>

    </header><!-- /.node-content -->
    
    <div class="colorbox-image">
      <?php print render($content['field_image']); ?>
    </div>
    
    <div class="colorbox-content">
      <?php print render($content['field_image_description']); ?>
      <?php if (!empty($content['footer'])): ?>
        <div class="terms"><?php print render($content['footer']); ?></div>
    <?php endif; ?>
      <?php print render($content['comments']); ?>
    </div>

</article> <!-- /#node-->