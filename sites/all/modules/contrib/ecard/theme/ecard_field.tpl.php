<?php
/**
 * Tepmlate for ecard text display.
 */

// Get rid of hardcoded salutation
$str = $name_to;

$salutation = substr($str,3);
$salutation = "Hi" . $salutation;
$name_to = $salutation;

?>

<div class="ecard">
  <div class="name-to"><?php print $name_to; ?></div>
  <div class="content"><?php print $content; ?></div>
  <div class="footer"><?php print $footer; ?></div>
</div>
