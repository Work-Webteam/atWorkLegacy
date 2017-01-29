<?php
/**
 * Created region specific block template.
 * Allows adding of markup to mainly the header and content of the atwork block
 * Returns the HTML for a block.
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="atwork-header-wrapper">
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <button class="activity-filters-my" title="show my content filters">M</button>
      <button class="activity-filters-all" title="show all content filters">A</button>
      <a href="node/21100" class="jsNewActivityWindow"><img src="/sites/all/modules/custom/atwork_activity/img/pop-out-white.png" title="Click for pop-out Activity Feed window" /></a>
      </div><!-- /.atwork-header-wrapper -->
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <div class="atwork-activity-block-container">
    <?php print $content; ?>
  </div><!-- /.atwork-activity-block-container -->

</div>
