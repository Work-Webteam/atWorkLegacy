<?php
global $base_url;
// Gather first and last names, make sure they are proper format
$applicant_first_name =  $lsa_node->field_lsa_first_name['und'][0]['safe_value'];
//$applicant_first_name = ucfirst(strtolower($applicant_first_name));
$applicant_last_name = $lsa_node->field_lsa_last_name['und'][0]['safe_value'];
//$applicant_last_name = ucfirst(strtolower($applicant_last_name));
if(isset($lsa_node->field_lsa_middle_name['und'][0]['safe_value']) && $lsa_node->field_lsa_middle_name['und'][0]['safe_value']){
  $applicant_middle_name = $lsa_node->field_lsa_middle_name['und'][0]['safe_value'] . ' ';
} else {
  $applicant_middle_name = '';
}
$applicant_full_name = $applicant_first_name . ' ' . $applicant_middle_name . $applicant_last_name;
// Need to shrink font if the name is too long
/*
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
*/
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

$invite = "https://gww.gov.bc.ca/mem_fs/images/lsa/LSA_invite_Apr28_with_RSVP.jpg";
$invite_sized = "https://gww.gov.bc.ca/mem_fs/images/lsa/LSA_720x800.jpg";
//$invite_button = 'https://gww.gov.bc.ca/mem_fs/images/lsa/LSA_RSVP.jpg';

$applicant_subject = t('Your Long Service Awards invitation is enclosed – please RSVP using the clickable button');
$applicant_body = <<<EOT
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style>
    /* Your Outlook-specific CSS goes here. */
  .ExternalClass{
    width:100%;
  }

  .ExternalClass,
  .ExternalClass p,
  .ExternalClass span,
  .ExternalClass font,
  .ExternalClass td,
  .ExternalClass div{
    line-height: 100%;
    padding: 0px !important;
  }

  #outlook a{
      padding:0;
  }

  table{
      mso-table-lspace:0pt;
      mso-table-rspace:0pt;
  }

   img{
        -ms-interpolation-mode:bicubic;
    }


    </style>
<!--[if gte mso 11]>
  <style>
    /* For outlook only - OWA spaces just a tiny bit differently. */
    .outlook-box {
      height: 345 !important;
    }
  </style>
<![endif]-->

</head>

<body id="mimemail-body" class="atwork-mail-default" style="padding:0;">
<p><strong>**DO NOT REPLY TO THIS EMAIL – PLEASE FOLLOW THE INSTRUCTIONS BELOW TO RSVP.**</strong></p>
<p> Your electronic invitation with RSVP button should appear below. If you are having trouble seeing the image in this email, please ensure you click <strong>“download images”</strong>. </p>
<p> To confirm your attendance OR to confirm you are unable to attend, <strong>please click on the <a href="$base_url/node/$nid">RSVP button</a></strong> in the invitation below.</p>
<p style = "page-break-after:always">If you are retired, or unable to access the RSVP link below – please contact us at <a href="mailto:longserviceawards@gov.bc.ca?Subject=RSVP%20link" target="_top">LongServiceAwards@gov.bc.ca</a>.</p>
<p> If you would like to print your invitation as a keepsake, the attached PDF version has been provided. </p><br />
<table width="750" height="886" border="0" cellpadding="0" cellspacing="0" style = "page-break-before:always; padding:0;" >
  <tbody>
    <tr  style="width:720px !important; height:886px !important; max-height:886px !important; background-size:100%; padding:0 !important; vertical-align:top; float: left;">
     <td bgcolor="#E7E7E7" BACKGROUND="$invite_sized" width="750" style="width:720px !important;height:886px !important; max-height:886px !important; background-size:100%; padding:0 !important; vertical-align:top; float: left;"><a href="$base_url/node/$nid">
<!--[if gte mso 11]>
  <v:rect xmlns:v="urn:schemas-microsoft-com:vml" fill="true" stroke="false" style="width:750px;height:886px;top:10pt;" href="$base_url/node/$nid" >
  <v:fill type="frame" src="$invite" color="#FFFFFF" />
  <v:textbox inset="0,0,0,0">
<![endif]-->
  <div id="main" style="padding:0 !important">
          <table width="750" height="886" border="0" cellpadding="0" cellspacing="0" border-spacing="0">
            <tbody>
              <tr style="max-height:315px; padding:0 !important; vertical-align:top;float:left;">
                <td class="outlook-box" width="750" height="315" style="max-height:315px !important; padding:0 !important; vertical-align:top;"><span style="padding:0 !important vertical-align:top; float:left;">&nbsp;</span></td>
              </tr>
              <tr style="max-height:60px; padding:0 !important; vertical-align:top;float:left;">
                <td class="initial-height-box" width="750" height="60"style="max-height:60px !important;font-size: 19pt; color: #333333; text-align: center; font-family: Times, 'Times New Roman', 'serif'; font-weight: 900; padding:0 !important; vertical-align:top;float:left;"><span style="padding:0 !important"><i><b>$applicant_full_name</b></i></span></td>
              </tr>
              <tr style="max-height:30px; padding:0 !important; vertical-align:top;float:left;">
                <td width="750" height="30" style="max-height:30px; padding:0 !important; vertical-align:top;float:left;"><span style="padding:0 !important">&nbsp;</span></td>
              </tr>
              <tr style="max-height:60px !important; font-size: 19pt; color: #333333; text-align: center; font-family: Times; font-weight: 900; padding:0 !important; vertical-align:top;float:left;">
                <td width="750" height="60" style="max-height:60px !important; font-size: 19pt; color: #333333; text-align: center; font-family: Times; font-weight: 900; padding:0 !important; vertical-align:top;float:left;"><i><b>$ceremony_date</b></i></span></td>
              </tr>
              <tr style="max-height:20px !important; padding:0 !important; vertical-align:top;float:left;"><span style="padding:0 !important vertical-align:top;">
                <td width="750" height="20" style="max-height:20px !important; padding:0 !important; vertical-align:top;float:left;"><span style="padding:0 !important vertical-align:top;">&nbsp;</span></td>
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

