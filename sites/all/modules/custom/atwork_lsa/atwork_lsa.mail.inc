<?php


$applicant_to = $node->field_lsa_email[$lang][0]['email'];
$applicant_subject = t('Your Long Service Award Application has been received');
$applicant_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>Thank you for using the Long Service Awards (LSA) e-registration system.</p>

<p>Electronic invitations to the LSA ceremonies will be emailed to recipients in early June. The RSVP deadline is August 1, 2016.
If you do not receive an invitation by the end of June, please <a href="mailto:LongServiceAwards@gov.bc.ca?subject=LSA%20registration">contact us.</a></p>

<p>The 2016 Long Service Award Ceremonies will be held at Government House in Victoria, during the months of October and November.</p>

<p>The particular night for your ministry or organization's ceremony will be specified on your invitation.  Please note, because the ceremonies are tailored to address specific ministries and organizations, it will not be possible to switch your ceremony night with another.</p>

<p>If you have registered but you’re unable to attend the ceremonies this fall, you have a one-year grace period to register for this specific milestone again in 2017, in order to attend the dinner and ceremonies at Government House. Please RSVP your regrets, and re-register for the LSAs the following year.  Arrangements will be made to have your 2016 Long Service Award presented to you at your place of work, sometime following the final ceremony in 2016.</p>

<p>An automated email has been sent to your supervisor so that he or she is aware of your eligibility for a Long Service Award and can provide you with the necessary supports, such as time off and travel coverage (if applicable).</p>

<p>For general inquiries, please contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">Long Service Award Contact</a>.</p>

<p>For more information about the Long Service Awards Program, please visit <a href="https://gww.gov.bc.ca/career/long-service-awards" target="_blank">@Work.</a></p>

<p>Congratulations on your pending award!</p>

<em>The personal information requested is collected under the authority of and used for the purpose of administering the <a href="http://www.bclaws.ca/EPLibraries/bclaws_new/document/LOC/freeside/--%20p%20--/public%20service%20act%20rsbc%201996%20c.%20385/00_96385_01.xml">Public Service Act</a>.  All information provided to us will be considered as supplied in confidence.</p>

Under certain circumstances some information may be released subject to the provisions of the <a href="http://www.bclaws.ca/EPLibraries/bclaws_new/document/ID/freeside/96165_00">Freedom of Information and Protection of Privacy Act</a>.  If you have any questions about the collection and use of this information, please contact the Office of Protocol at (250) 356-7916, PO Box 9422 Stn. Prov. Govt., Victoria BC V8W 9V1.  This information will be kept for a minimum of one year.</em>
EOT;

$supervisor_to = $node->field_lsa_supervisor_email[$lang][0]['email'];
$supervisor_subject = t('An employee you supervise has applied for a Long Service Award');
$supervisor_body = <<<EOT
<span style="background:yellow">THIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.</span>

<p>This email is to advise you that {$node->title}, who you supervise, has registered to receive a {$node->field_lsa_years_of_service[$lang][0]['value']} year Long Service Award this fall.</p>

<p>Eligible employees are any full-time, part-time or seasonal staff who will reach their 25th, 30th, 35th, 40th, 45th or 50th anniversary with the BC Public Service by December 31, 2016, or who have achieved one of these milestones but have not previously been recognized. </p>

<p>Electronic invitations will be emailed to recipients in early June. The 2016 Long Service Award Ceremonies will be held at Government House in Victoria, during the months of October and November.  </p>

<p>Long Service Awards recipients from outside Greater Victoria are considered to be on travel status and are to be granted time off as applicable to attend their Long Service Awards ceremony.  The ministry or organization is responsible for all travel-related costs to and from the ceremony, for both the recipient and their guest.</p>

<p>Although Victoria-based recipients do not need to travel to attend the Long Service Awards ceremony, they must be provided a reasonable amount of time to prepare for the ministry specific pre-ceremony reception (if applicable), as well as the gala dinner event. Therefore, it is recommended that recipients leave their workplace by 2:00 p.m. on the day of their event, without any negative impact on their pay. In cases where the recipient is a front-line worker, arrangements for coverage should be made in advance, as prior notice of the ceremony date will be available months in advance.</p>

<p>As alcohol will be served at the ceremony, taxi expenses will be paid by the employee's ministry or organization for their Victoria-based staff to attend the event and to travel home once the event is over.</p>

<p>For more information about the Long Service Awards Program, including information about eligibility criteria and/or policies that support this program, please visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility" target="_blank">@Work.</a></p>

<p>If you have questions, please contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">Long Service Award Contact</a></p>

EOT;


