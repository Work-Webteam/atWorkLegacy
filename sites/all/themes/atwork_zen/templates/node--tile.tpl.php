<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

if (isset($content['field_image'])) {
  hide($content['field_image']);
}


?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> tile clearfix"<?php print $attributes; ?>>
  <?php 
  if (isset($content['field_image'])) {
    print render($content['field_image']);
  }
  ?>
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php if ($title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    print render($content);
  ?>
</article>
