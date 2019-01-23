<?php
// Changing this to take advantage of mem_fs functionality, especially since beta2 and test2 do not have cert, so image never opens in email. 
//$image_source = drupal_get_path('module', 'atwork_lsa') . '/Invitation/LongServiceAwards_2017_Feb21.jpg';
//
$image_source = "https://gww.gov.bc.ca/mem_fs/images/lsa/LongServiceAwards_2017_Feb21.jpg";

$applicant_attending_subject = t('Long Service Awards 2018 – RSVP Confirmation');
$applicant_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <center><img src="$image_source" height="120" width="120" align="middle"></center>
        <br />
        <p>Thank you for confirming your attendance for your Long Service Award ceremony. If you need to make changes to your RSVP information or cancel your attendance, please email the <a href="mailto:LongServiceAwards@gov.bc.ca?subject=RSVP%20to%20ceremony">Long Service Awards team</a> as soon as possible. </p>
        <p>The ceremony will take place at <a href="http://www.ltgov.bc.ca/getting-here">Government House</a>, and business attire is recommended. Doors open at 5:45 p.m. Your invitation is not required for entry to the ceremony. </p>
        <p><strong>Program:</strong>
            <ul>
                <li>5:45 p.m. - Registration, Reception and Welcome</li>
                <li>6:15 p.m. - Dinner Buffet</li>
                <li>7:20 p.m. - Speeches</li>
                <li>7:40 p.m. - Awards Presentation</li>
                <li>8:15 p.m. - Dessert Buffet</li>
                <li>9:00 p.m. - Dancing</li>
                <li>10:00 p.m. - Evening Concludes</li>
            </ul>
        </p>
        <p>For information about travel reimbursement and taking time off, visit <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">@Work</a> or contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award contact</a>. If you have questions about the ceremony, email the <a href="mailto:longserviceawards@gov.bc.ca?subject=Question%20about%20LSA%20ceremony">Long Service Awards team</a>.</p>
        <p>We look forward to welcoming you to Government House this fall!</p>
        <p>Thank you,<br>Long Service Awards Team</p>
    </body>
</html>
EOT;

$applicant_not_attending_subject = t('Long Service Awards ceremony 2018 – Regrets');
$applicant_not_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <center><img height="100" width="100" src="$image_source" align="middle"></center>
        <br />
        <p>Thank you for notifying us that you will not be attending this year's Long Service Award ceremony. </p>
        <p>Long Service Awards are presented the year an employee registers. Your award will be mailed to your organization following the 2018 fall ceremonies, and your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">ministry/organization contact</a> will make arrangements to have your award presented to you.</p>
        <p>NOTE: You will need to re-register in March/April 2019 on <a href="https://gww.gov.bc.ca/career/long-service-awards">@Work</a> in order to take advantage of the one-year deferral. </p>
        <p>If you have any questions, please read the <a href="https://gww.gov.bc.ca/career/long-service-awards/faq">FAQs on @Work</a>, connect with your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">Long Service Award contact</a> or email the <a href="mailto:longserviceawards@gov.bc.ca?subject=Question%20about%20LSA%20ceremony">Long Service Awards team</a>.</p>
    </body>
</html>
EOT;

