<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <button id="clickmeplease">Toggle Bio</button>

  <script type="text/javascript">
    (function ($) {
        $("#clickmeplease").click(function () {
          var $this = $(this);
          if($this.data('expanded') == "yes"){
              $this.data('expanded',"no");
              $('#user-user-full-group-profile-extra').animate({height:'90px'});
          } else {
              $this.data('expanded',"yes");
              $('#user-user-full-group-profile-extra').css({height:'auto'});
          }
        });
    }(jQuery));
  </script>

</div>
