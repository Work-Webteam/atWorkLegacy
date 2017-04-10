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
$url = $base_url . '/mem_fs/images/lsa/LSA_Invite_June1.jpg';
//$url = "https://gww.gov.bc.ca/mem_fs/images/lsa/LSA_Invite_June1.jpg";


$applicant_subject = t('You Are Invited to the Long Service Awards Ceremony');
$applicant_body = <<<EOT
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
</head>

<body id="mimemail-body" class="atwork-mail-default">
<p> If you are having trouble seeing the images in this email, please ensure you click <strong>“download images”</strong>. </p>
<p> To confirm your attendance, click on the RSVP button below (do not reply to this email).</p> 
<p style = "page-break-after:always">If you are retired, or unable to access the RSVP link below – please contact us at <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20link" target="_top">LongServiceAwards@gov.bc.ca</a>.</p><br /> <br />
<table width="750" border="0" align="center" cellpadding="0" cellspacing="0" style = "page-break-before:always" >
  <tbody>
    <tr>
      <td bgcolor="#E7E7E7" width="750" height="800" valign="top" BACKGROUND="$url"><a href="$base_url/node/$nid">
<!--[if gte mso 9]>
  <v:rect xmlns:v="urn:schemas-microsoft-com:vml" fill="true" stroke="false" style="width:750px;height:800;" href="$base_url/node/$nid">
    <v:fill type="frame" src="https://gww.gov.bc.ca/mem_fs/images/LSA_Invite_June1.jpg" color="##FFFFFF"  />
    <v:textbox inset="0,0,0,0">
  <![endif]-->
        <div id="main">
          <table width="750" height="800" border="0" align="center" cellpadding="0" cellspacing="0">
            <tbody>
              <tr>
                <td height="270"><p>&nbsp;</p></td>
              </tr>
              <tr>
                <td height="60" align="center" valign="middle" style="font-size: $name_font_size; color: #333333; text-align: center; font-family: Cambria, 'Hoefler Text', 'Liberation Serif', Times, 'Times New Roman', serif; font-weight: bold; font-style: oblique;">$applicant_full_name</td>
              </tr>
              <tr>
                <td height="25"><p>&nbsp;</p></td>
              </tr>
              <tr>
                <td height="60" align="center" valign="middle" style="font-size: 21pt; color: #333333; text-align: center; font-family: Cambria, 'Hoefler Text', 'Liberation Serif', Times, 'Times New Roman', serif; font-weight: bold; font-style: oblique;">$ceremony_date</td>
              </tr>
              <tr>
                <td><p>&nbsp;</p></td>
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
<table width="750" border="0" align="center" cellpadding="0" cellspacing="0" style="font-size: 14pt; color:#333333; text-align:center; font-family: Merienda, 'Times New Roman', serif, sans-serif;">
  <tbody>
    <tr>
      <td height="20"><br></td>
    </tr>
    <tr>
      <td>

      <table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
      <tr>
        <td>
          <table align="center" border="0" cellspacing="0" cellpadding="0" style="font-size: 14pt; color:#333333; text-align:center; font-family: Merienda, 'Times New Roman', serif, sans-serif;" >
            <tr>
              <td align="center">
                Please <a href="$base_url/node/$nid" target="_blank" style="color: #ffffff; text-decoration: none; border-radius: 3px; -webkit-border-radius: 3px; -moz-border-radius: 3px; background-color: #EB7035; border-top: 12px solid #EB7035; border-bottom: 12px solid #EB7035; border-right: 18px solid #EB7035; border-left: 18px solid #EB7035; display: inline-block;">RSVP</a> before August 1, 2016.
              </td>
            </tr>
          </table>
        </td>
      </tr>
      </table>
      <p style="font-size: 10pt;">NOTE: If you are a retired employee, or cannot access the online RSVP link above, please contact <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP">longserviceawards@gov.bc.ca</a><br /> or call Jenny Pescod at (250) 356-7916 to confirm your attendance.</p>
      </td>
    </tr>
  </tbody>
</table>
</body>
</html>
EOT;

