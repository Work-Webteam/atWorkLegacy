<?php
// Changing this to take advantage of mem_fs functionality, especially since beta2 and test2 do not have cert, so image never opens in email. 
//$image_source = drupal_get_path('module', 'atwork_lsa') . '/Invitation/LongServiceAwards_2017_Feb21.jpg';
//
$image_source = "https://gww.gov.bc.ca/mem_fs/images/lsa/LongServiceAwards_2017_Feb21.jpg";

$applicant_attending_subject = t('Long Service Awards – RSVP Confirmation');
$applicant_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <center><img src="$image_source" height="120" width="120" align="middle"></center>
        <br />
        <p>This is an automated email. No response is required. </p>
        <p>Thank you for confirming your attendance for your Long Service Awards ceremony. If you need to make changes to your RSVP information or cancel your attendance, please email the <a href="mailto:LongServiceAwards@gov.bc.ca?subject=RSVP%20to%20ceremony">Long Service Awards team</a> as soon as possible.</p>
        <p>The ceremony will take place at <a href="http://www.ltgov.bc.ca/getting-here">Government House</a>, and business attire is recommended. <strong>Doors open at 5:45 p.m</strong>. Your invitation is not required for entry to the ceremony. </p>
        <p><strong>Itinerary:</strong>
            <ul>
                <li>5:45-6:15 p.m. - Registration, reception and welcome</li>
                <li>6:15-7:20 p.m. - Dinner Buffet</li>
                <li>7:20-7:40 p.m. - Speeches</li>
                <li>7:40-8:30 p.m. - Awards Presentation</li>
                <li>8:15 p.m. - Dessert Buffet</li>
                <li>9:00-10:00 p.m. - Dancing</li>
                <li>10:00 p.m. - Evening Concludes</li>
            </ul>
        </p>
        <p>For information about travel reimbursement and taking time off, visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">@Work</a> or contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Awards contact</a>. If you have questions about the ceremony, email the <a href="mailto:longserviceawards@gov.bc.ca?subject=Question%20about%20LSA%20ceremony">Long Service Awards team</a>.</p>
        <p>We look forward to welcoming you to Government House this fall!</p>
        <p>Thank you,</p>
        <br />
        <p>Long Service Awards Team</p>
    </body>
</html>
EOT;

$applicant_not_attending_subject = t('Long Service Awards – Regrets');
$applicant_not_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <center><img height="100" width="100" src="$image_source" align="middle"></center>
        <br />
        <p>This is an automated email. No response is required.</p>
        <p>Thank you for confirming that you will not be attending your Long Service Award ceremony.</p>
        <p>Long Service Awards are presented the year an you register. <strong>Your award will be mailed to your organization following the 2019 fall ceremonies, and your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">ministry/organization contact</a> will make arrangements to have your award presented to you.</strong></p>
        <p>Note: You can defer your attendance at the ceremony for one year. You will need to re-register in March/April 2020 to take advantage of the one-year deferral.</p>
        <p>If you have any questions, please read the <a href="https://gww.gov.bc.ca/career/long-service-awards/faq">FAQs on @Work</a>, connect with your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award contact</a> or email the <a href="mailto:longserviceawards@gov.bc.ca?subject=Question%20about%20LSA%20ceremony">Long Service Awards team</a>.</p>
    </body>
</html>
EOT;

