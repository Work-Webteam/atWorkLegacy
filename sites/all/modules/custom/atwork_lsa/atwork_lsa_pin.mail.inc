<?php

// Collect all milestones applied for
$milestones = array($node->field_lsa_pin_service_milestone[$lang][0]['value']);
foreach ($node->field_lsa_previous_service_miles[$lang] as $value){
  $milestones[] = $value['value'];
}
// Sort and remove duplicates
sort($milestones);
$milestones = array_unique($milestones);
$email_milestone = '';
// Put it in a string all nice like
$email_milestone = implode(", ", $milestones);

$supervisor_to = $node->field_lsa_supervisor_email[$lang][0]['email'];
$supervisor_subject = t('An employee you supervise has applied for a Service Milestone Pin');
$supervisor_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>FYI – an employee you supervise has registered for a BC Public Service Pin, in celebration of {$email_milestone} years of service.</p>

<p>{$node->field_lsa_pin_first_name[$lang][0]['value']} {$node->field_lsa_pin_last_name[$lang][0]['value']}’s pin(s) will be sent directly to you, in preparation for Public Service Week (June 12-16). We ask that you present this recognition directly to {$node->field_lsa_pin_first_name[$lang][0]['value']} during Public Service Week. This is a wonderful opportunity to thank your employee for their service and commitment to the BC Public Service!</p>

<p>If you have questions about the corporate pin program, please connect with your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a> or the BC Public Service Agency contact, <a href="mailto:Gillian.Kish@gov.bc.ca?subject=Pin%20registration">Gillian Kish</a>.</p>

EOT;



$applicant_to = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject = t('Your Service Milestone Pin application has been received');
$applicant_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>
<p>Thank you for registering for your {$email_milestone} year BC Public Service Pin, and congratulations on this important career milestone!</p>

<p>Your pin(s) will be sent directly to your supervisor, for presentation to you during <strong>Public Service Week (June 12-16)</strong></p>

<p>If you have questions about the corporate pin program, please connect with your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>.

EOT;

