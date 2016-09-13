<?php

/**
 * @file
 * Rate widget theme
 */
?>
<?php
//Make some template changes to rate widget to get the icons we want
if(isset($up_button)){
  if(substr($up_button, 0, 2 ) == "<a") {
    $up_button = str_replace('title="up">up', 'title="Vote Up">' . _atwork_fa('fa fa-arrow-circle-up'), $up_button);
  } elseif (substr($up_button, 0, 2) == "<s") {
    $up_button = str_replace('>up', 'title="Vote Up">' . _atwork_fa('fa fa-arrow-circle-up'), $up_button);
  }
}
if(isset($down_button)){
  if(substr($down_button, 0, 2 ) == "<a") {
    $down_button = str_replace('title="down">down', 'title="Vote Down">' . _atwork_fa('fa fa-arrow-circle-down'), $down_button);
  } elseif (substr($down_button, 0, 2) == "<s") {
    $down_button = str_replace('>down', 'title="Vote Down">' . _atwork_fa('fa fa-arrow-circle-down'), $down_button);
  }
}
?>
<ul>
  <li class="thumb-up">
    <?php print $up_button; ?>
    <div class="percent"><?php print $results['up_percent'] . '%'; ?></div>
  </li>
  <li class="thumb-down">
    <?php print $down_button; ?>
    <div class="percent"><?php print $results['down_percent'] . '%'; ?></div>
  </li>
</ul>
<?php
if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
