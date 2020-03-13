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
<p> <span style="display:block;float:right;">May 23, 2020</span></p>
<p><br /></p>
<p>Dear {$supervisor_first}, </p>

<p>Enclosed are the service pins to present to your employees celebrating a career milestone. See below for details on which pins go to which employees. </p>

<p><strong>Please present the pins during Public Service Week, June 10-14</strong>. It&apos;s a wonderful opportunity to thank your employees for their service and celebrate their commitment to the BC Public Service.  </p>

<p>Consider the employee&apos;s individual preference when planning how and when to present these pins. If your employee works in a different location, please consider hosting a virtual presentation during a team meeting, or connect with the employee directly to offer your congratulations. Don&apos;t forget to personalize and sign (or ask an executive to sign) the pin card for the employee!</p>

<p>The pin(s) included in this package are to be presented to:</p>

<table>
<p>{$recipient_list}</p>
</table>

<p>Important: only employees who registered themselves, or were registered by you or a ministry representative, are included in this package. If you have an employee who is eligible and did not register, please connect with your ministry recognition contact to enquire about additional pins. Pins and pin cards can be ordered at your organization&apos;s cost at any time from the Distribution Centre Victoria. Find links to these products on the Service Pin section of @Work (gww.gov.bc.ca/career/service-pins).</p>

<p>Registration for the corporate pin program takes place annually in March. If you have questions about the  program, you&apos;ll find further information on @Work or you can connect with your organization&apos;s recognition contact.</p>

<p>Thank you,</p>

<p>Gillian</p>

<p><font size="-2">Gillian Kish, Corporate Recognition and Long Service Awards Manager<br />
Public Service Engagement and Corporate Initiatives | BC Public Service Agency<br />
Email: Gillian.Kish@gov.bc.ca</font></p> <br />
</font>
<!-- This should double as a page break as .md takes html -->
<!-- <div style="page-break-after: always;"></div> -->
<div clear=all style='page-break-before:always'></div>
<!-- <p clear=all style='page-break-before:always'></p> ---->


EOT;
