<?php
$applicant_attending_subject = t('RSVP Confirmed ');
$applicant_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <p>Thank you for confirming your attendance for your Long Service Award ceremony.  We have now received your RSVP information. </p>
        <p>If you have any questions relating to travel arrangements, pre-receptions, or reimbursement, please visit our <a href="https://gww.gov.bc.ca/career/long-service-awards/eligibility/policy">website</a>  or contact your workplace <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts">LSA contact</a>.  If your questions are related to the LSA ceremonies at Government House, please contact <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20question" target="_top">longserviceawards@gov.bc.ca</a>.</p>
        <p><strong>Some Reminders:</strong></p>
        <p>The LSA ceremonies take place at <a href="http://www.ltgov.bc.ca/contact/default.html" target="_blank">Government House</a>, the home of the Lieutenant Governor of British Columbia. It is recommended that you “dress your best” for these formal, evening occasions and, in consideration of others, <strong>please be “scent-aware” and refrain from wearing heavily scented products.</strong></p>
        <p>If you or your guest has severe allergies (besides food preferences), uses a wheelchair, requires sign-language/interpretation, uses a service-assistance dog, or has any other special requirement, please email the <a href="mailto:longserviceawards@gov.bc.ca?Subject=Special%20Requests" target="_top">Long Service Awards program</a> <u>prior to your ceremony date</u>, if you have not provided this information already</p>
        <ul><strong>Itinerary:</strong>
            <li>5:45 – 6:15pm: Registration</li>
            <li>6:15 – 6:40pm – Speeches Dinner Buffet</li>
            <li>6:40 – 7:40pm - Speeches</li>
            <li>7:40 – 8:30pm - Awards Presentation</li>
            <li>8:00pm - Dessert Buffet</li>
            <li>9:00 – 10:00pm - Dancing</li>
        </ul>
        <p>If you have any questions, please visit our website <a href="https://gww.gov.bc.ca/career/long-service-awards/faq" target="_blank">FAQs</a>, connect with your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">ministry LSA contact</a> or send an email to <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20question" target="_top">longserviceawards@gov.bc.ca</a>.</p>
        <p>We look forward to welcoming you to your LSA ceremony this fall. Congratulations on reaching this important milestone in your career! </p>
        <p>Long Service Awards Team</p>
    </body>
</html>
EOT;

$applicant_not_attending_subject = t('Regrets – LSA Ceremony 2017');
$applicant_not_attending_body = <<<EOT
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <body id="mimemail-body" class="atwork-mail-default">
        <p>Thank you for notifying us that you will <u>not</u> be attending this year’s Long Service Award Ceremony. </p>
        <p>Long Service Awards are presented in the year the employee registers. <strong>Your award will be sent to your organization following the fall ceremonies, and your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">ministry/organization contact</a> will make the arrangements to have your award presented to you internally</strong>.</p>
        <p><strong>Reminder:</strong> If this is the first year you have registered, you have a one-year deferral to attend next year. You are responsible for <a href="https://gww.gov.bc.ca/career/long-service-awards" target="_blank"> re-registering next year </a>. The registration period is from the beginning of March to the end of April each year.</p>
        <p>If you have any questions, please visit our website <a href="https://gww.gov.bc.ca/career/long-service-awards/faq" target="_blank">FAQs</a>, connect with your <a href="https://gww.gov.bc.ca/career/long-service-awards/long_service_awards_contacts" target="_blank">ministry LSA contact</a> or send an email to <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20question" target="_top">longserviceawards@gov.bc.ca</a>.</p>
        <p>Long Service Awards Team</p>
    </body>
</html>
EOT;