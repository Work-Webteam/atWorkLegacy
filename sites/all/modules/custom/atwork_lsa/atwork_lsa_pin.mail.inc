<?php

// Collect all milestones applied for
$milestones = array();
if(isset($node->field_lsa_pin_service_milestone[$lang][0]['value']) && $node->field_lsa_pin_service_milestone[$lang][0]['value']){
  $milestones[] = array($node->field_lsa_pin_service_milestone[$lang][0]['value']);
}
if(isset($node->field_lsa_previous_service_miles[$lang]) && $node->field_lsa_previous_service_miles[$lang]){
  foreach ($node->field_lsa_previous_service_miles[$lang] as $value){
    $milestones[] = $value['value'];
  }
}

// Sort and remove duplicates
sort($milestones);
$milestones = array_unique($milestones);
$email_milestone = '';

$years = count($milestones);
if($years == 1){
  $email_milestone = $milestones[0];
} elseif($years == 2){
  $email_milestone = $milestones[0] . " and " . $milestones[1];
} else {
  // Put it in a string all nice like
  $email_milestone = implode(", ", $milestones);
  // Need to put an "and" in at the end of this string, removing the last comma
  $email_milestone = strrev(implode(strrev(' and'), explode(strrev(','), strrev($email_milestone), 2)));
}


$supervisor_to = $node->field_lsa_supervisor_email[$lang][0]['email'];
$supervisor_subject = t('An employee you supervise has applied for a Service Pin');
$supervisor_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>FYI – an employee you supervise has registered for a BC Public Service Pin, in celebration of a service milestone they are currently celebrating, or have missed celebrating in the past.</p>

<p><strong> {$node->field_lsa_pin_first_name[$lang][0]['value']} {$node->field_lsa_pin_last_name[$lang][0]['value']}</strong> is registered for a $email_milestone year Service Pin(s)</p>

<p>The pin(s) will be mailed directly to you at the beginning of June, and will include a list of all your employees who have registered. </p>

<p><strong>Please present the pin(s) to {$node->field_lsa_pin_first_name[$lang][0]['value']} during Public Service Week  - June 12-16, 2017.</strong></p>

<p>If you have questions about the corporate pin program, please connect with your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.</p>

EOT;



$applicant_to = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject = t('Your Service Milestone Pin application has been received');
$applicant_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>
<p>Thank you for registering for your {$email_milestone} year BC Public Service Pin, and congratulations on this important career milestone!</p>

<p>Your pin(s) will be sent directly to your supervisor, for presentation to you during <strong>Public Service Week (June 12-16)</strong></p>

<p>If you have questions about the corporate pin program, please connect with your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.

EOT;

if(isset($node->field_lsa_ministry_rep_email[$lang][0]['value']) && $ministry_rep_to = $node->field_lsa_ministry_rep_email[$lang][0]['value']){
  $ministry_rep_to = $node->field_lsa_ministry_rep_email[$lang][0]['value'];
} else {
  $ministry_rep_to = false;
}
$ministry_rep_subject = t('You have registered someone for a Service Pin.');
$ministry_rep_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>Thank you for registering <strong>{$node->field_lsa_pin_first_name[$lang][0]['value']} {$node->field_lsa_pin_last_name[$lang][0]['value']}</strong> for a $email_milestone year Service Pin(s)</p>

<p>The pin(s) will be be mailed directly to {$node->field_lsa_pin_first_name[$lang][0]['value']}'s supervisor at the beginning of June, in order to <strong>present the pin(s) to {$node->field_lsa_pin_first_name[$lang][0]['value']} during Public Service Week  - June 12-16, 2017.</strong></p>

<p>If you have questions about the corporate pin program, please connect with your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.</p>

EOT;
