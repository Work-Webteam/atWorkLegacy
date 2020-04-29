<?php

// Print out recipients for this supervisor here, into a single variable
$recipient_list = "";
$year_milestones = "";
//dpm($recipients);
//dpm($supervisor_first);
foreach($recipients as $key => $value){
  // Let's add some comma's to our milestones if necessary
  if(isset($value['milestones']) && !is_numeric(trim($value['milestones']))){
    // Make sure we don't have any double spaces that will mess up the explode implode
    $value['milestones'] = str_replace("  ", " ", $value['milestones']);
    $year_milestones = explode(" ", trim($value['milestones']));
    // Last dup check
    $year_milestones = array_unique($year_milestones);
    $year_append_milestones = implode(", ", $year_milestones) . " years";
  } else {
      $year_append_milestones = $value['milestones'] . " years";
  }
  $recipient_list .= "<tr><td><strong><font size='-1'>" . $value['name'] . ": &emsp;</font></strong></td><td><strong><font size='-1'>" . $year_append_milestones . "</font></strong></td></td>";
}

// User our Base64 image to imbed it in the doc. Shrink the image to half size.
$image_string = '<img src="data:' . $size['mime'] . ';base64,' . $image_64 . '"' . 'height="' . $size[1]/2 . '"' . 'weight="' . $size[0]/2 . '" />';
// Now create an HTML file - this is appended to one html file, and can be printed from the browser all at once.
$letter_text = <<< EOT
<br style="page-break-before: always">
<br clear=all style='page-break-before:always'>

{$image_string}
<font size="-1">
<p>{$label}</p>
<p><br /></p>
<p><br /></p>
<p>Dear {$supervisor_first}, </p>

<p>Enclosed are the service pins for those employees celebrating a career milestone. Below is a list of which pin(s) goes to each employee.</p>

<p><strong>Public Service Week is taking place June 14-20th</strong> and is a wonderful opportunity to thank your employees for their contributions and celebrate their commitment to the BC Public Service. With physical distancing measures currently in place, in-person presentations may not be possible. If you are unable to present the pins during Public Service Week, you are encouraged to save the presentation for a future date. </p>

<p>However, please still make an effort to recognize your employees’ service milestones in some way during Public Service Week. Remember to consider the employee’s individual preference when planning the type of recognition. If your employee works in a different location, you could host a virtual presentation during a team meeting or connect with the employee directly to offer your congratulations. A Public Service Week e-card is available on @Work. <a href="https://gww.gov.bc.ca/ecards/public-service-week/stronger-together">gww.gov.bc.ca/ecards/public-service-week/stronger-together</a></p>
<p>The attached pin card can be signed by you and/or a member of your executive, with a personalized message for the employee.</p>

<p>The pin(s) included in this package are to be presented to:</p>

<table>
<p>{$recipient_list}</p>
</table>

<p><strong>Important</strong>: only employees who registered themselves, or were registered by you or a ministry representative, are included in this package. If you have an employee who is eligible and did not register, you can order additional service pins (at your organization’s cost) at any time from the Distribution Centre Victoria: <a href="https://gww.gov.bc.ca/career/service-pins">gww.gov.bc.ca/career/service-pins</a></p>

<p>If you have questions about service pins, please connect with your organization’s recognition contact. </p>

<p>Thank you for taking the time to recognize your employees and colleagues!</p>
<br />
<p>Public Service Engagement and Corporate Initiatives | BC Public Service Agency<br />
<a href="mailto:corporate.engagement@gov.bc.ca">Corporate.Engagement@gov.bc.ca</a>
</p>
<!-- This should double as a page break as .md takes html -->
<!-- <div style="page-break-after: always;"></div> -->
<div clear=all style='page-break-before:always'></div>
<!-- <p clear=all style='page-break-before:always'></p> ---->

EOT;
