<div class="<?php print $classes . ' ' . $zebra; ?>">
  <div class="comment-inner">
    <?php print $picture ?>
    <span class="submitted">Posted <?php print $created; ?> by <?php print $author; ?></span>
    <div class="content">
      <?php 
        hide($content['links']);
        print render($content);
        ?>
      <?php if ($signature): ?>
        <div class="signature"><?php print $signature ?></div>
      <?php endif; ?>
    </div>
    
    <?php if (!empty($content['links'])): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>
  </div> <!-- /comment-inner -->
</div> <!-- /comment -->