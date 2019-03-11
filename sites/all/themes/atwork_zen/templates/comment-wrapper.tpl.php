<?php
/**
 * @file
 * Returns the HTML for a wrapping container around comments.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728230
 */

// Render the comments and form first to see if we need headings.
$comments = render($content['comments']);
$comment_form = render($content['comment_form']);
?>
<section id="comments" class="comments <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="comment-disclaimer-block">
    <p>
      @Work is an employer website and you should apply the same judgment when posting comments here as you would when speaking them in the workplace. Please ensure your comments align with the <a href="https://www2.gov.bc.ca/assets/gov/careers/about-the-bc-public-service/public-service-agency-programs-strategies/what_we_value_booklet.pdf">Public Service Values</a>.&nbsp;You should also refer to the <a href="/org/terms-use">Terms of Use</a> for more information. Comments may be removed at the editor’s discretion.
    </p>
    <p>
      If you have questions or concerns about a particular topic and would like to be put in touch with the relevant program area, please email <a href="mailto:EmployeeNews@gov.bc.ca">Employee News</a>. Alternatively, you can speak with your supervisor.
    </p>
  </div>

  <?php print render($title_prefix); ?>
  <?php if ($comments && $node->type != 'forum'): ?>
    <h2 class="comments__title title"><?php print t('Comments'); ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php print $comments; ?>

  <?php if ($comment_form): ?>
    <h2 class="comments__form-title title comment-form"><?php print t('Add new comment'); ?></h2>
    <?php print $comment_form; ?>
  <?php endif; ?>
</section>
