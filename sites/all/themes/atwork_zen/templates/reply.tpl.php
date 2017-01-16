<?php

/**
 * @file
 * Default theme implementation for a reply.
 */

?>
<!-- We need to add a depth class in so we can nest these replies -->
<?php $vars = get_defined_vars(); ?>
<?php $depth = ' reply-depth-' . $vars['elements']['#entity']->depth; ?>
<div id="reply-<?php print $id ?>" class="<?php print 'reply ' . $classes . ' ' . $depth ?>">
  <div class="reply-body"><?php print render($content) ?></div>
  <div class="reply-links"><?php print render($links) ?></div>
</div>


