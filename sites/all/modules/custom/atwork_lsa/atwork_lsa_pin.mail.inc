<?php

// Collect all milestones applied for
$milestones = array();
if(isset($node->field_lsa_pin_service_milestone[$lang][0]['value']) && $node->field_lsa_pin_service_milestone[$lang][0]['value']){
  $milestones[] = $node->field_lsa_pin_service_milestone[$lang][0]['value'];
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
$supervisor_subject = t('An employee you supervise has applied for a service pin');
$supervisor_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>An employee you supervise has registered for a corporate service pin in celebration of a service milestone they are currently celebrating or have missed celebrating in the past.</p>

<p>{$node->field_lsa_pin_first_name[$lang][0]['value']} {$node->field_lsa_pin_last_name[$lang][0]['value']} is registered for a {$email_milestone}-year service pin(s)</p>

<p>The pin(s) will be mailed directly to you at the beginning of June, and will include a list of all your employees who have registered. </p>

<p>Please present the pin(s) to {$node->field_lsa_pin_first_name[$lang][0]['value']} during <strong>Public Service Week (June 10-14, 2019)</strong>. This is an ideal opportunity to thank your employees for their service and celebrate their commitment to the BC Public Service!</p>

<p>For more information about service pins, visit <a href="https://gww.gov.bc.ca/career/service-pins">@Work</a>. If you have additional questions, connect with your <a href="https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.</p>

EOT;



$applicant_to = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject = t('Your service pin application has been received');
$applicant_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>
<p>Thank you for registering for your {$email_milestone}-year corporate service pin, and congratulations on this important career milestone!</p>

<p>Your pin(s) will be sent directly to your supervisor for presentation to you during <strong>Public Service Week (June 10-14, 2019)</strong>.</p>

<p>For more information about service pins, visit <a href="https://gww.gov.bc.ca/career/service-pins" target="_blank">@Work</a>. If you have additional questions, connect with your <a href="https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.</p>

EOT;

if(isset($node->field_lsa_ministry_rep_email[$lang][0]['value']) && $ministry_rep_to = $node->field_lsa_ministry_rep_email[$lang][0]['value']){
  $ministry_rep_to = $node->field_lsa_ministry_rep_email[$lang][0]['value'];
} else {
  $ministry_rep_to = false;
}
$ministry_rep_subject = t('You have registered someone for a Service Pin.');
$ministry_rep_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>Thank you for registering {$node->field_lsa_pin_first_name[$lang][0]['value']} {$node->field_lsa_pin_last_name[$lang][0]['value']} for a {$email_milestone}-year service pin(s)</p>

<p>The pin(s) will be mailed directly to {$node->field_lsa_pin_first_name[$lang][0]['value']}'s supervisor, for presentation during <strong>Public Service Week (June 10-14, 2019).</strong></p>

<p>For more information about service pins, visit <a href="https://gww.gov.bc.ca/career/service-pins" target="_blank">@Work</a>. If you have additional questions, connect with your <a href="https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.</p>

EOT;



/**
 * Some ministries require specific email changes: These updates are only for the following:
 * 21|Community Living BC
 * 24|Education
 * 25|Elections BC
 * 29|Energy, Mines & Petroleum Resources
 * 32|Environmental Assessment Office
 * 40|Government Communications & Public Engagement
 * 46|Indigenous Relations & Reconciliation
 * 48|Intergovernmental Relations Secretariat
 * 55|Mental Health & Addictions
 * 60|Office of the Information and Privacy Commissioner
 * 62|Office of the Ombudsperson
 * 63|Office of the Police Complaints Commissioner
 * 68|Property Assessment Appeal Board
 * 81|Transportation & Infrastructure
 */


$supervisor_to_special_condition = $node->field_lsa_supervisor_email[$lang][0]['email'];
$supervisor_subject_special_condition = t('You have registered someone for a service pin');
$supervisor_body_special_condition = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>Thank you for registering {$node->field_lsa_pin_first_name[$lang][0]['value']} {$node->field_lsa_pin_last_name[$lang][0]['value']} for a {$email_milestone}-year service pin(s)</p>

<p>The pin(s) will be mailed directly to your ministry/organization, for presentation during <strong>Public Service Week (June 10-14, 2019).</strong></p>

<p>If you have questions about the corporate pin program, please connect with your <a href="https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.</p>

EOT;


$applicant_to_special_condition = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject_special_condition = t('Your service pin application has been received');
$applicant_body_special_condition = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>
<p>Thank you for registering for your {$email_milestone}-year corporate service pin(s), and congratulations on this important career milestone!</p>

<p>Your pin(s) will be sent directly to your ministry/organization, for presentation to you during <strong>Public Service Week (June 10-14, 2019)</strong>.</p>

<p>If you have questions about the corporate pin program, please connect with your <a href="https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.

EOT;
