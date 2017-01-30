<?php

/**
 * @file
 * Default theme implementation for a reply.
 */

?>
<?php $vars = get_defined_vars(); ?>
<?php $depth = ' reply-depth-' . $vars['elements']['#entity']->depth; ?>
<div id="reply-<?php print $id ?>" class="<?php print 'reply ' . $classes . ' ' . $depth ?>">
  <div class="reply-body"><?php print render($content) ?></div><!-- /.reply-body -->
  <div class="reply-links"><?php print render($links) ?></div><!-- /.reply-links -->
</div><!-- /.entity-reply -->


