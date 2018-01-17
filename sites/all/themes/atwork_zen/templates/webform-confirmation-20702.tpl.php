<?php

/**
 * @file
 * Customize confirmation screen after successful submission.
 *
 * This file may be renamed "webform-confirmation-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-confirmation.tpl.php" to affect all webform confirmations on your
 * site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $progressbar: The progress bar 100% filled (if configured). This may not
 *   print out anything if a progress bar is not enabled for this node.
 * - $confirmation_message: The confirmation message input by the webform
 *   author.
 * - $sid: The unique submission ID of this submission.
 * - $url: The URL of the form (or for in-block confirmations, the same page).
 */
?>
<?php print $progressbar; ?>

<div class="webform-confirmation">
  <?php if ($confirmation_message): ?>
    <?php
      global $user;
      $current_user = user_load($user->nid);
      include_once(drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc');
      $submissions = webform_get_submission($node->nid, $sid);
      // We want to append ics for user choice.
      // Current list is:
      // 01| Vancouver – Wednesday, February 7 -  Holiday Inn and Suites Vancouver Downtown
      // 02| Prince George – Wednesday, February 21 - Ramada Prince George
      // 03| Surrey – Wednesday, March 7 - Sheraton Vancouver Guilford Hotel
      // 04| Kamloops – Wednesday, March 21 - Sandman Signature Kamloops Hotel
      // 05| Cranbrook – Wednesday, April 11 - Prestige Rocky Mountain Resort Cranbrook

      $choice = $submissions->data[2][0];
      $calendar_insert = '';
      switch ($choice) {
        // Vancouver
        case 1:
          $calendar_insert = "<div class='r2r-ics'><p><a href='https://gww.gov.bc.ca/sites/default/files/ics/2018/r2r-vancouver/event.ics' ><button>Add to Calendar</button></a></p></div>";
          break;
        // PG
        case 2:
          $calendar_insert = "<div class='r2r-ics'><p><a href='https://gww.gov.bc.ca/sites/default/files/ics/2018/r2r-princegeorge/event.ics' ><button>Add to Calendar</button></a></p></div>";
          break;
        // Surrey
        case 3:
          $calendar_insert = "<div class='r2r-ics'><p><a href='https://gww.gov.bc.ca/sites/default/files/ics/2018/r2r-surrey/event.ics' ><button>Add to Calendar</button></a></p></div>";
          break;
        // Kamloops
        case 4:
          $calendar_insert = "<div class='r2r-ics'><p><a href='https://gww.gov.bc.ca/sites/default/files/ics/2018/r2r-kamloops/event.ics'><button>Add to Calendar</button></a></p></div>";
          break;
        // Cranbrook
        case 5:
          $calendar_insert = "<div class='r2r-ics'><p><a href='https://gww.gov.bc.ca/sites/default/files/ics/2018/r2r-cranbrook/event.ics'><button>Add to Calendar</button></a></p></div>";
          break;
      }

      $confirmation_message = $confirmation_message . $calendar_insert;

    ?>
    <?php print $confirmation_message ?>
  <?php else: ?>
    <p><?php print t('Thank you, your submission has been received.'); ?></p>
  <?php endif; ?>
</div>

<div class="links">
  <a href="<?php print $url; ?>"><?php print t('Go back to the form'); ?></a>
</div>
