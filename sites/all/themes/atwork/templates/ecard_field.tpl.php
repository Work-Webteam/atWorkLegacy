<?php
/**
 * Tepmlate for E-card text display.
 */
 
$text = $variables['ecard']->text;
$text = _filter_autop($text);
?>

<div class="ecard">
  <fieldset class=" collapsible">
    <legend><span class="fieldset-legend">Message</span></legend>
    <div class="fieldset-wrapper">
      <?php print $text; ?>
    </div>
  </fieldset>
</div>