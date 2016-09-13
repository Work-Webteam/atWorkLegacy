<?php

/**
 * @file
 * Rate widget theme
 *
 */

?>
<?php
if(isset($up_button)){
  if(substr($up_button, 0, 2 ) == "<a") {
    $up_button = str_replace('title="+1">+1', 'title="Vote Up">' . _atwork_fa('fa fa-arrow-circle-up'), $up_button);
  } elseif (substr($up_button, 0, 2) == "<s") {
    $up_button = str_replace('>+1', 'title="Vote Up">' . _atwork_fa('fa fa-arrow-circle-up'), $up_button);
  }
}
if(isset($down_button)){
  if(substr($down_button, 0, 2 ) == "<a") {
    $down_button = str_replace('title="-1">-1', 'title="Vote Down">' . _atwork_fa('fa fa-arrow-circle-down'), $down_button);
  } elseif (substr($down_button, 0, 2) == "<s") {
    $down_button = str_replace('>-1', 'title="Vote Down">' . _atwork_fa('fa fa-arrow-circle-down'), $down_button);
  }
}
?>

<?php print $up_button; ?>

<?php
// We need to hide 0's that are really NULL's
if($results['count'] == 0 && $score == 0) {
  $score = "~";
}

?>
<div class="rate-number-up-down-rating <?php print $score_class ?>"><?php print $score; ?></div>

<?php print $down_button; ?>

<?php

if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
