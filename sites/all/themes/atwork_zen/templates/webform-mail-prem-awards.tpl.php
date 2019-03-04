<?php

/**
 * @file
 * Customize the e-mails sent by Webform after successful submission.
 *
 * This file may be renamed "webform-mail-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-mail.tpl.php" to affect all webform e-mails on your site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $submission: The webform submission.
 * - $email: The entire e-mail configuration settings.
 * - $user: The current user submitting the form.
 * - $ip_address: The IP address of the user submitting the form.
 *
 * The $email['email'] variable can be used to send different e-mails to different users
 * when using the "default" e-mail template.
 */
//dpm($renderable_fields);
//dpm($submission);

require_once drupal_get_path('module', 'atwork_prem_awards') . '/atwork_prem_awards.replacements.inc';

$translations = _atwork_prem_awards_questions();

$form = $node->atwork_form;

// get a bunch of variables we will use below
$application_type = $submission->data[41][0];
$application_title = $submission->data[5][0];

if (isset($form['submitted']['name_of_ministry_or_eligible_organization_sponsoring_this_application']['#options']['Ministries'][$submission->data[1][0]])) {
  $ministry = $form['submitted']['name_of_ministry_or_eligible_organization_sponsoring_this_application']['#options']['Ministries'][$submission->data[1][0]];
} else {
  $ministry = $form['submitted']['name_of_ministry_or_eligible_organization_sponsoring_this_application']['#options']['Agencies'][$submission->data[1][0]];
}

$region = $form['submitted']['region']['#options'][$submission->data[4][0]];

// remove non-standard fields
unset($renderable_fields['name_of_ministry_or_eligible_organization_sponsoring_this_application']);
unset($renderable_fields['application_type']);
unset($renderable_fields['region']);
unset($renderable_fields['nominees']);

$application_type_map = array(
  1 => 'Cross-Government Integration',
  2 => 'Innovation',
  3 => 'Leadership',
  4 => 'Organizational Excellence',
  5 => 'Partnership',
  6 => 'Legacy',
  7 => 'Emerging Leader',
	8 => 'Evidence-Based Design'
);

file_put_contents('submission.txt', print_r($submission->data, true));
file_put_contents('renderable_fields.txt', print_r($renderable_fields, true));

print 'Thank you for submitting the following nomination:<br /><br />';
if($application_type_map[$application_type] == "Leadership" || $application_type_map[$application_type] == "Emerging Leader"){
	// Emerging Leader or Leadership (Individual)
	print 'Nomination Name - ' . $submission->data[54][0] . '<br />';
}else {
	//Group type application
	print 'Nomination Name - ' . $submission->data[5][0] . '<br />';
}

print 'Ministry - '. $ministry .'<br />';
print 'Category - '. $application_type_map[$application_type] .'<br />';
print 'Region - '. $region .'<br /><br />';

print 'Please ensure the above-listed information is accurate for this nomination. If any information is incorrect, please contact Shanna Tom at: <a href="mailto:Shanna.Tom@gov.bc.ca">Shanna.Tom@gov.bc.ca</a><br /><br />A formal announcement will be made on @Work, and communication will be shared with Ministry Contacts when finalists are determined. In the meantime, please share the nomination information with the nominator(s), nomination contacts and nominees.<br /><br />Your participation in this year’s Premier\'s Innovation and Excellence Awards is greatly appreciated. The significant efforts of all involved in the nomination process is integral to the program’s success. Thank you!';

print '<br /><br /><h2>' . $application_title . '</h2>';

print drupal_render($renderable_fields);
