<?php
$applicant_to = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject = t('Your Long Service Award registration');
$applicant_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>You have successfully registered for a Long Service Award.</p> 

<p>The 2018 ceremonies will be held at Government House in Victoria this fall between September and November.</p>

<p>An electronic invitation to your Long Service Award ceremony will be emailed to you in June. The date for your ceremony will be specified on your invitation. Please note, because the ceremonies are tailored to host specific ministries and organizations, it will not be possible to change your ceremony date.</p>

<p>If you have registered but find that you’re unable to attend your ceremony this fall, you have a one-year grace period to attend the ceremony next year. In this case, please RSVP your regrets and re-register for the Long Service Awards in 2019. Arrangements will be made to have your award presented to you at your workplace in 2018.</p>

<p>An email has been sent to your supervisor so that he/she is aware of your registration for a Long Service Award and can provide you with the necessary supports to attend your ceremony. For information about travel reimbursement and taking time off, visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">@Work</a> or contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award Contact.</a></p>

<p>Note: You are responsible for booking your own travel to the ceremony. Please connect with your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award Contact</a> to confirm if your organization has an internal travel process to follow and/or if someone will be coordinating specific hotel arrangements for you.</p>
EOT;

$supervisor_to = $node->field_lsa_supervisor_email[$lang][0]['email'];
$supervisor_subject = t('An employee you supervise has registered for a Long Service Award');
$supervisor_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>This email is to advise you that {$node->title}, who you supervise, has registered to receive a milestone {$node->field_lsa_years_of_service[$lang][0]['value']} year Long Service Award in 2018.</p>

<p>Eligible employees are any full-time, part-time or seasonal employees who will reach their 25th, 30th, 35th, 40th, 45th or 50th anniversary with the BC Public Service by December 31, 2018, or who have achieved one of these milestones before this year but have not previously been recognized.</p>

<p>The 2018 Long Service Award ceremonies will be held at Government House in Victoria this fall.  Invitations will be emailed to recipients in June, and the dates of the ceremonies will be posted on @Work at that time.</p>

<p>Long Service Awards recipients from outside Greater Victoria are to be approved time off to attend their ceremony. Travel costs, including transportation, hotel and meal expenses for the recipient and one guest, will be covered by the employee’s ministry or organization. </p>

<p>For Victoria-based recipients, taxi expenses to and from their ceremony are to be covered by their ministry or organization. In addition, Victoria-based recipients must be provided a reasonable amount of time to prepare for their ceremony; therefore, it is recommended that recipients leave their workplace by 2 p.m. on the day of their event without any negative impact to their pay. In cases where the recipient is a front-line worker, arrangements for coverage should be made in advance.</p>

<p>For more information about the Long Service Awards, including details about travel reimbursement and time off for recipients, visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">@Work</a>. If you have additional questions, contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award Contact</a>.</p>
EOT;


