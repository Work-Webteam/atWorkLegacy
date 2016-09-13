<?php

/**
 * @file
 * Rate widget theme
 */
$org_info = $info;
$up_button = str_replace('title="up"', 'title="Like This"', $up_button);
$info = str_replace('users have voted', 'people like this', $info);
$info = str_replace('user has voted', 'person likes this', $info);
$info = str_replace('Only you voted.', 'You like this.', $info);
if ($info == '0 people like this.') {
  $info = 'Like';
}

if (strpos($info, 'people like this, including you.')) {
  //dpm($info);
  
  $arr = explode(' ', $info);
  $num = (int) $arr[0];
  $replacement = $num - 1;
  
  if ($num == 2) {
    $info = 'You and one person likes this.';
  }
  else {
    $info = str_replace($num, $replacement, $info);
    $info = str_replace(', including you', '', $info);
    $info = 'You and ' . $info;
  }
}

if (isset($results['user_vote']) ? $results['user_vote'] : FALSE) {
  print '<div class="rate-thumbs-up-btn-up"><i class="icon-thumbs-up"></i></div>';
}
else {
  print $up_button;
}

if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
