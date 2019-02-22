<?php
$applicant_to = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject = t('Your Long Service Award registration');
$applicant_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>You have successfully registered for a {$node->field_lsa_years_of_service[$lang][0]['value']} year Long Service Award.</p> 

<p>The 2019 ceremonies will be held at Government House in Victoria this October and November. Your invitation will be emailed to you in June.</p>

<p>The date for your ceremony will be specified on your invitation. Because the ceremonies are tailored to host specific ministries and organizations it is not possible to change your ceremony date.</p>

<p>If you have registered but find that you’re unable to attend your ceremony this fall, you have a one-year grace period to attend the ceremony next year. In this case, please RSVP your regrets and re-register for the Long Service Awards in 2020. Arrangements will be made to have your award presented to you towards the end of the year.</p>

<p>An email has been sent to your supervisor so they are aware of your registration and can provide you with the necessary supports to attend your Long Service Award ceremony.</p>

<p><strong>Travel:</strong></p>

<p>Please connect with your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award Contact</a> to confirm if your organization has a particular travel process to follow and/or if someone will be coordinating travel/hotel arrangements for you.</p>

<p>For information on the Long Service Awards travel policy and reimbursement process, visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">@Work</a> or contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award Contact</a>. </p>

<p>Congratulations on reaching this milestone in your career! We hope to see you at the ceremony this fall. </p>

<p>Long Service Awards team</p>
EOT;

$supervisor_to = $node->field_lsa_supervisor_email[$lang][0]['email'];
$supervisor_subject = t('An employee you supervise has registered for a Long Service Award');
$supervisor_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>This email is to advise you that {$node->title}, who you supervise, has registered to receive a {$node->field_lsa_years_of_service[$lang][0]['value']} year Long Service Award in 2019.</p>

<p>Eligible employees are any full-time, part-time or seasonal employees who will reach their 25th, 30th, 35th, 40th, 45th or 50th anniversary with the BC Public Service by December 31, 2019, or who have achieved one of these milestones prior to this year but have not been recognized for it.</p>

<p>The 2019 Long Service Awards ceremonies will be held at Government House in Victoria in October and November. Invitations will be emailed to recipients in June, and the dates of the ceremonies will be posted on <a href="https://gww.gov.bc.ca/career/long-service-awards/ceremonies">@Work</a> at that time.</p>

<p><strong><u>Travel and Time Off:</u></strong></p>

<p>Long Service Awards recipients from outside Greater Victoria are to be approved time off to attend their ceremony. <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">Travel costs</a>, including transportation, hotel and meal expenses for the recipient and one guest, will be covered by the employee’s organization.</p>

<p>For Victoria-based recipients, <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">taxi expenses</a> to and from their ceremony are to be covered by their organization. In addition, Victoria-based recipients must be provided a reasonable amount of time to prepare for their ceremony; it is recommended that recipients be able to leave their workplace by at least 2 p.m. on the day of their event without any negative impact to their pay. In cases where the recipient is a front-line worker, arrangements for coverage should be made in advance.</p>

<p>For more information about the Long Service Awards, including details about travel reimbursement and time off for recipients, visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">@Work</a>. If you have additional questions, contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award Contact</a>.</p>
EOT;


