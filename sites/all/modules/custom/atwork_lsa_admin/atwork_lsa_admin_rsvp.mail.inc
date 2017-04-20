<?php
$image_source = drupal_get_path('module', 'atwork_lsa') . '/Invitation/LongServiceAwards_2017_Feb21.jpg';
$applicant_attending_subject = t('Long Service Awards 2017 – RSVP Confirmation');
$applicant_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <p><img src="$image_source" align="left"></p>
        <p>Thank you for confirming your attendance for your Long Service Award (LSA) ceremony.  We have now received your RSVP information. </p>
        <p>If you have any questions relating to travel arrangements, pre-receptions, or reimbursement, please visit our <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">website</a>  or contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">LSA contact</a>.  If your questions are related to the LSA ceremonies at Government House, please contact <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20question" target="_top">longserviceawards@gov.bc.ca</a>.</p>
        <p><strong>Please Note:</strong></p>
        <p>The LSA ceremonies take place at <a href="http://www.ltgov.bc.ca/contact/default.html" target="_blank">Government House</a>, the home of the Lieutenant Governor of British Columbia. It is recommended that you “dress your best” for these formal, evening occasions and, in consideration of others, <strong>please be “scent-aware” and refrain from wearing heavily scented products.</strong></p>
        <table border="1" bordercolor="#000000" bgcolor="#ffffcc">
            <tbody>
                <tr>
                    <td>
                        <p><strong> Need to Make Changes? </strong></p>      
                    </td>
                </tr>
                <tr>
                    <td>
                        <p>If you previously indicated that you or your guest has special requirements, <strong>we will contact you</strong> to discuss these further. If you need to notify us of any changes to your information, or to cancel your attendance, please email us as <u>prior to your ceremony date</u> at <a href="mailto:longserviceawards@gov.bc.ca?Subject=Changes%20to%20Application" target="_top">longserviceawards@gov.bc.ca</a>.</p>
                    </td>
                <tr>
            </tbody>
        </table>
        <br />
        <p><strong>Itinerary:</strong>
            <ul>
                <li>5:45 – 6:15 p.m.- Registration</li>
                <li>6:15 – 6:40 p.m.- Dinner Buffet</li>
                <li>6:40 – 7:40 p.m.- Speeches</li>
                <li>7:40 – 8:30 p.m.- Awards Presentation</li>
                <li>8:15 p.m.- Dessert Buffet</li>
                <li>9:00 – 10:00 p.m.- Dancing</li>
            </ul>
        </p>
        <p>If you have any questions, please visit our website <a href="https://gww.gov.bc.ca/career/long-service-awards/faq" target="_blank">FAQs</a>, connect with your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">ministry LSA contact</a> or send an email to <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20question" target="_top">longserviceawards@gov.bc.ca</a>.</p>
        <p>We look forward to welcoming you to your LSA ceremony this fall. Congratulations on reaching this important milestone in your career! </p>
        <p>Long Service Awards Team</p>
    </body>
</html>
EOT;

$applicant_not_attending_subject = t('Regrets – Long Service Awards ceremony 2017');
$applicant_not_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <p><img src="$image_source" align="left"></p>
        <p>Thank you for notifying us that you will <u>not</u> be attending this year’s Long Service Award (LSA) ceremony. </p>
        <p>Long Service Awards are presented the year the employee registers. <strong>Your award will be sent to your organization following the fall ceremonies, and your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">ministry/organization contact</a> will make the arrangements to have your award presented to you internally</strong>.</p>
        <p><strong>Reminder:</strong> If this is the first year you have registered, you have the option of a one-year deferral to attend next year. You are responsible for <a href="https://gww.gov.bc.ca/career/long-service-awards" target="_blank"> re-registering next year</a>. The registration period is from the beginning of March to the end of April each year.</p>
        <p>If you have any questions, please visit our website <a href="https://gww.gov.bc.ca/career/long-service-awards/faq" target="_blank">FAQs</a>, connect with your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">ministry LSA contact</a> or send an email to <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20question" target="_top">longserviceawards@gov.bc.ca</a>.</p>
        <p>Long Service Awards Team</p>
    </body>
</html>
EOT;

