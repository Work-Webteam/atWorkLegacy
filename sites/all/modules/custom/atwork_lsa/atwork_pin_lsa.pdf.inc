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
    
<p>Please find enclosed one or more service pins and cards with which to recognize your employee(s) for their career milestone(s). Details of your registered employee(s) and their service milestone(s) are shown below.</p>

<p><strong>We encourage you to present the pin(s) directly to your employee(s) during Public Service Week, June 11-15</strong>. This is a wonderful opportunity to thank your employees for their service and celebrate their commitment to the BC Public Service! </p>

<p>When planning how to present the pin(s), consider individual employee preferences – you may choose to make a splash at a work unit or ministry event, or you may decide to do something low-key.  For employees that work in a different location to you, this can still be a special presentation. In addition to mailing the pins, consider hosting a virtual presentation commemorating their years of service.</p>   

<p>Pins will come affixed to a card that can be signed by you or an executive member.</p>

<p>The pins included in this package are to be presented to:</p>

<br />
<table>
<p>{$recipient_list}</p>
</table>

<br />

<p>Registration for the corporate pin program takes place annually in March. You can order additional pins and pin plaques through Distribution Centre Victoria at any point throughout the year, but note there is a cost associated with this option.</p>

<p>If you have questions about the corporate pin program, please connect with your organization’s <a href="https://gww.gov.bc.ca/career/employee-appreciation/recognition-contacts" target="_blank">Recognition contact</a>, or email me directly.</p>

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
