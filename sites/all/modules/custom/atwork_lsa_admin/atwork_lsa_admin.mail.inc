<?php
global $base_url;
// Gather first and last names, make sure they are proper format
$applicant_first_name =  $lsa_node->field_lsa_first_name['und'][0]['safe_value'];
//$applicant_first_name = ucfirst(strtolower($applicant_first_name));
$applicant_last_name = $lsa_node->field_lsa_last_name['und'][0]['safe_value'];
//$applicant_last_name = ucfirst(strtolower($applicant_last_name));
$applicant_full_name = $applicant_first_name . ' ' . $applicant_last_name;
// Need to shrink font if the name is too long
switch(true){
  case (strlen($applicant_full_name)<= 27):
    $name_font_size = '21pt';
    break;
  case (strlen($applicant_full_name) >27 && strlen($applicant_full_name) <= 35):
    $name_font_size = '16pt';
    break;
  case (strlen($applicant_full_name) > 35 && strlen($applicant_full_name) <= 40):
    $name_font_size = '14pt';
    break;
  case (strlen($applicant_full_name) >40):
    $name_font_size = '10pt';
    break;
  default:
    $name_font_size = '8pt';
}
// Get ceremony date label value
//$all_fields = field_info_fields();
$list_of_values = list_allowed_values(field_info_field('field_lsa_ceremonydate'));
$ceremony_date_key = $lsa_node->field_lsa_ceremonydate['und'][0]['value'];
foreach($list_of_values as $key=>$value){
  if($key == $ceremony_date_key){
    $ceremony_date = $value;
  }
}

// Grab Node id for link
$nid = $lsa_node->nid;

// Get a url value
//$invite = $base_url . '/sites/all/modules/custom/atwork_lsa_admin/Invitation/LSA_print.jpg';
//$invite_button = $base_url . '/sites/all/modules/custom/atwork_lsa_admin/Invitation/LSA_RSVP.png';

$invite = "https://gww.gov.bc.ca/mem_fs/images/lsa/LSA_Invite_complete.jpg";
//$invite_button = 'https://gww.gov.bc.ca/mem_fs/images/lsa/LSA_RSVP.jpg';

$applicant_subject = t('Your Long Service Awards invitation is enclosed – please RSVP using the clickable button');
$applicant_body = <<<EOT
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
</head>

<body id="mimemail-body" class="atwork-mail-default">
<p><strong>**DO NOT REPLY TO THIS EMAIL – PLEASE FOLLOW THE INSTRUCTIONS BELOW TO RSVP.**</strong></p>
<p> Your electronic invitation with RSVP button should appear below. If you are having trouble seeing the image in this email, please ensure you click <strong>“download images”</strong>. </p>
<p> To confirm your attendance OR to confirm you are unable to attend, <strong>please click on the <a href="$base_url/node/$nid">RSVP button</a></strong> in the invitation below.</p>
<p style = "page-break-after:always">If you are retired, or unable to access the RSVP link below – please contact us at <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20link" target="_top">LongServiceAwards@gov.bc.ca</a>.</p>
<p> If you would like to print your invitation as a keepsake, the attached PDF version has been provided. </p><br />
<table width="750" border="0" align="center" cellpadding="0" cellspacing="0" style = "page-break-before:always" >
  <tbody>
    <tr>
      <td bgcolor="#E7E7E7" width="750" height="800" valign="top" BACKGROUND="$invite"><a href="$base_url/node/$nid">
<!--[if gte mso 9]>
  <v:rect xmlns:v="urn:schemas-microsoft-com:vml" fill="true" stroke="false" style="width:750px;height:800;" href="$base_url/node/$nid">
    <v:fill type="frame" src="$invite" color="##FFFFFF"  />
    <v:textbox inset="0,0,0,0">
  <![endif]-->
        <div id="main">
          <table width="750" height="800" border="0" align="center" cellpadding="0" cellspacing="0">
            <tbody>
              <tr>
                <td height="290"><p>&nbsp;</p></td>
              </tr>
              <tr>
                <td height="60" align="center" valign="middle" style="font-size: 18pt; color: #333333; text-align: center; font-family: Times; font-weight: bold; "><strong>$applicant_full_name</strong></td>
              </tr>
              <tr>
                <td height="30"><p>&nbsp;</p></td>
              </tr>
              <tr>
                <td height="60" align="center" valign="middle" style="font-size: 18pt; color: #333333; text-align: center; font-family: Times; font-weight: bold;"><strong>$ceremony_date</strong></td>
              </tr>
              <tr>
                <td height="20"><p>&nbsp;</p></td>
              </tr>
            </tbody>
          </table>
        </div>
  <!--[if gte mso 9]>
    </v:textbox>
  </v:rect>
  <![endif]-->
  </a>
  </td>
    </tr>
  </tbody>
</table>
</body>
</html>
EOT;

