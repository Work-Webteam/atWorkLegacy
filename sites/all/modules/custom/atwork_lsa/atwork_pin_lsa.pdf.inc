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
  $recipient_list .= "<tr><td>" . $value['name'] . ": &emsp;</td><td>" . $year_append_milestones . "</td></td>";
}

// User our Base64 image to imbed it in the doc. Shrink the image to half size.
$image_string = '<img src="data:' . $size['mime'] . ';base64,' . $image_64 . '"' . 'height="' . $size[1]/2 . '"' . 'weight="' . $size[0]/2 . '" />';
// Now create an HTML file - this is appended to one html file, and can be printed from the browser all at once.
$letter_text = <<< EOT
<br style="page-break-before: always">
<br clear=all style='page-break-before:always'>

{$image_string}
        
<p>{$label}</p>

<p ><br /></p>

<p>Dear {$supervisor_first}, <span style="display:block;float:right;">{$date}</span> </p>
    
<p>Enclosed are the service pins to present to your employees celebrating a career milestone. See below for details on which pins go to which employees. </p>

<p><em>Please present the pins during Public Service Week, June 10-14</em>. It’s a wonderful opportunity to thank your employees for their service and celebrate their commitment to the BC Public Service.  </p>

<p>Consider the employees’ individual preferences when planning how and when to present these pins. If your employee works in a different location, please mail the pins and consider hosting a virtual presentation commemorating their years of service.</p>   

<p>Don’t forget to personalize and sign (or ask an executive to sign) the pin card for the employee!</p>

<p>The pins included in this package are to be presented to:</p>

<table>
<p>{$recipient_list}</p>
</table>

<br />

<p>Note that only employees who registered themselves or were registered by you or a ministry representative, are included in this package. If you have an employee who is eligible and did not register, please connect with your ministry recognition contact (email below) to enquire about additional pins. Pins can be ordered at your organization’s cost at any time from the Distribution Centre Victoria. Pin cards are also available for purchase. Find links to these products on the Service Pin section of @Work (https://gww.gov.bc.ca/career/service-pins).</p>

<p>Registration for the corporate pin program takes place annually in March. If you have questions about the corporate pin program, please connect with your organization’s recognition contact (list can be found on @Work <https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts>), or email me directly.</p>

<p>Thank you,</p>

<p>Gillian</p>

<p><strong style="color: blue">Gillian Kish, Corporate Recognition and Long Service Awards Manager</strong><br />
Public service Engagement and Corporate Initiatives | BC Public Service Agency<br />
Contact: Gillian.Kish@gov.bc.ca</p> <br />

<!-- This should double as a page break as .md takes html -->
<div style="page-break-after: always;"></div>
<div clear=all style='page-break-before:always'></div>
<p clear=all style='page-break-before:always'></p>


EOT;
