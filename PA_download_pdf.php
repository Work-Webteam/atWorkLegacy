#!/opt/rh/rh-php56/root/usr/bin/php
<?php

$_SERVER['REMOTE_ADDR'] = '127.0.01';
$_SERVER['REQUEST_METHOD'] = NULL;

// Bootstrap drupal
define('DRUPAL_ROOT', '/var/www/html');
//define('DRUPAL_ROOT', '/Users/RKUYVENH/Sites/atwork');

//define('DRUPAL_ROOT', '/var/www/public/atworkdev');
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
require_once DRUPAL_ROOT . '/modules/user/user.admin.inc';

require(DRUPAL_ROOT . '/sites/all/modules/custom/atwork_lsa_admin/fpdf/fpdf181/fpdf.php');

// bootstrap all drupal modules
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

module_load_include('inc', 'webform', 'includes/webform.submissions');

$submissions = webform_get_submissions(array('nid' => 5990));

$app_type = array(
  '2' => 'Innovation',
  '3' => 'Leadership',
  '4' => 'Organizational Excellence',
  '5' => 'Partnership',
  '6' => 'Legacy',
  '7' => 'Emerging Leader',
  '8' => 'Evidence Based Design',
  '9' => 'Regional Impact',
);


$regions = array(
  'INT' => 'Interior/North',
  'LM' => 'Lower Mainland',
  'VI' => 'Vancouver Island',
  'PR' => 'Province Wide',
);

$labels = array(
  "1" => "Name of Ministry or eligible organization sponsoring this application",
  "41" => "Application Type",
  "4" => "Region",
  "5" => "Title of Nomination",
  "54" => "Name of Nominee",
  "69" => "Name of Legacy Nominee",
  "63" => "Nominator Name",

  //"8" => "Nominator Title",
  //"9" => "Nominator Email",
  //"11" => "Nomination Name",
  //"12" => "Nomination Email",
  //"13" => "Nomination Phone Number",
  //"15" => "Video Contact Name",
  //"16" => "Video Contact Email",
  //"17" => "Filming Location 1",
  //"52" => "Filming Location 2",
  //"53" => "Filming Location 3",
  "21" => "Evaluation Considerations - Summary",
  "23" => "Evaluation Considerations - Context",
  "25" => "Evaluation Considerations - Approach",
  "24" => "Evaluation Considerations - Complexity",
  "26" => "Evaluation Considerations - Valuing People",
  "27" => "Evaluation Considerations - Impact",
  "28" => "Evaluation Considerations - Commitment to the Organization",
  "38" => "Evaluation Considerations - Contribution to BC Public Service excellence",
  //"33" => "Attachment 1",
  //"34" => "Attachment 2",
  //"35" => "Attachment 3",
  //"36" => "Attachment 4",
  //"37" => "Attachment 5",
  //"18" => "Nominee Information",
  //"43" => "Partner Information",
);

$ministries = array(
  "1" => "Advanced Education, Skills and Training",
  "2" => "Agriculture",
  "3" => "Attorney General",
  "4" => "Children and Family Development",
  "5" => "Citizens' Services ",
  "6" => "Education",
  "7" => "Energy, Mines and Petroleum Resources",
  "8" => "Environment and Climate Change Strategy",
  "9" => "Environmental Assessment Office",
  "10" => "Finance",
  "11" => "Forests, Lands, Natural Resource Operations and Rural Development",
  "12" => "Government Communications and Public Engagement",
  "13" => "Health",
  "14" => "Indigenous Relations and Reconciliation",
  "15" => "Jobs, Economic Development and Competitiveness",
  "16" => "Labour",
  "17" => "Mental Health and Addictions",
  "18" => "Municipal Affairs and Housing",
  "19" => "Public Safety and Solicitor General",
  "20" => "Social Development and Poverty Reduction",
  "21" => "Tourism, Arts and Culture",
  "22" => "Transportation and Infrastructure",
  "23" => "BC Public Service Agency",
  "24" => "Government Communications and Public Engagement",
  "25" => "Liquor Distribution Branch",
  "26" => "Public Guardian and Trustee",
);

$fields = array_keys($labels);

foreach($submissions as $submission) {

  $dn = DRUPAL_ROOT . '/PA_' . date("Y") . '/';
  mkdir($dn, 0700, TRUE);

  $pdf = new FPDF();
  $pdf->AddPage();
  $pdf->SetRightMargin(20);
  $pdf->SetLeftMargin(20);

  $pdf->SetFont('Arial', 'B', 16);
  $pdf->Cell(40, 10, "Submission #" . $submission->serial . "-" . date("Y"));
  $pdf->SetLineWidth(1.1);
  $pdf->SetDrawColor(128,128,128);
  $pdf->Line(22,25,188,25);
  $pdf->Ln();
  $pdf->Ln();


  if (!is_dir($dn . $submission->serial)) {
    mkdir($dn . $submission->serial, 0700, TRUE);
  }

      	$type = $app_type[$submission->data['41'][0]];
      	switch($type) {
      		case('Innovation'):
  				foreach($fields as $field) {
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(5):
      					// Title of Nomination
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(21):
      					// Evaluation Considerations - Summary
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that summarizes or restates the main points of the nomination (goal and achievement). The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(23):
      					// Evaluation Considerations - Context
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe why the new innovative approach was undertaken.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(24):
      					// Evaluation Considerations - Complexity
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe the scope and scale of the new initiative, streamlined business processes, technology, or creative solution developed including, but not limited to:'));
      					$pdf->SetLeftMargin(25);

                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Size of the project, process, technology solution;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risks encountered;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Challenges around introducing a new approach to solve a challenging problem;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Technical or organizational difficulties addressed;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Financial constraints managed.'),0,"L");

                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', ' '),0,"L");
      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(25):
      					// Evaluation Considerations - Approach
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', 'Describe how the new initiative, product or service was developed from inception to delivery and transformed new ideas into tangible initiatives including, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The process used to generate breakthrough ideas, fresh perspectives and new opportunities;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The use of new technology or tools to enhance program and service delivery or improve upon existing processes and procedures (i.e. Behavioural Insights, Data Science, Service Design, Agile Methodology, etc.);'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Application of a user-centric or citizen-centric approach in the development of the initiative/program;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Adapting and refining the approach or initiative when things did not work well and learning from the setbacks/mistakes;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Explain how the team managed and overcame risks encountered to adapt and refine the process;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Creativity in the design or redesign of the programs or services.'),0,"L");

      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(27):
      					// Evaluation Considerations - Impact
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Capture the impact of, and use metrics to support (if applicable), the innovative approach to programs and services as demonstrated by, but not limited to:'));
      					$pdf->SetLeftMargin(25);

                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Improved performance by doing things that may be unique, leading-edge, or new to the public service;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Changes to the organizational culture or the traditional approach to management or problem solving;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates an experimental or innovative mindset whereby being open to change, taking calculated risks and challenge the status quo to try something new, resulted in a measurable outcome;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect that the innovative approach to the programs or services has had on its intended internal or external stakeholders;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect that the innovative approach to the programs orz services has had on the internal operations of the individuals, teams, or organizations delivering the programs or services;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Quantitative or measurable improvement to the programs or services;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates why and how this was innovative.'),0,"L");
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				default:
      					break;
      			}
      			}
      			break;
      		case('Leadership'):
      			foreach($fields as $field) {
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(54):
      					// Name of Nominee
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      		    case(21):
      		    	// Evaluation Considerations - Summary
      		    	$data = $submission->data[$field][0];
      		    	$pdf->SetFont('Arial', 'B', 12);
      		    	$pdf->Cell(40, 15, $labels[$field]);
      		    	$pdf->SetLineWidth(1.1);
      		    	$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', 'B', 11);
      		    	$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that summarizes or restates the main points of the nomination, submission or personal contribution. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', '', 11);
      		    	$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      		    	$pdf->Ln();
      		    	break;
      		    case(23):
      		    	// Evaluation Considerations - Context
      		    	$data = $submission->data[$field][0];
      		    	$pdf->SetFont('Arial', 'B', 12);
      		    	$pdf->Cell(40, 15, $labels[$field]);
      		    	$pdf->SetLineWidth(1.1);
      		    	$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', 'B', 11);
      		    	$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe the conditions under which the employee demonstrated exemplary leadership.'));
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', '', 11);
      		    	$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      		    	$pdf->Ln();
      		    	break;
      		    case(24):
      		    	// Evaluation Considerations - Complexity
      		    	$data = $submission->data[$field][0];
      		    	$pdf->SetFont('Arial', 'B', 12);
      		    	$pdf->Cell(40, 15, $labels[$field]);
      		    	$pdf->SetLineWidth(1.1);
      		    	$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', 'B', 11);
      		    	$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe the nominee’s ability to demonstrate exemplary leadership acumen including, but not limited to:'));
      		    	$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Size of the organization, project, process, or initiative managed;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Managing complex situations including: large-scale initiatives, managing and mitigating risks, creatively solving problems and implementing solutions;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Constraints encountered and overcome under their leadership (i.e. time frame, technical, financial, organizational, policy, etc.).'),0,"L");
      		    	$pdf->SetLeftMargin(20);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', '', 11);
      		    	$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      		    	$pdf->Ln();
      		    	break;
      		    case(26):
      		    	// Evaluation Considerations - Valuing People
      		    	$data = $submission->data[$field][0];
      		    	$pdf->SetFont('Arial', 'B', 12);
      		    	$pdf->Cell(40, 15, $labels[$field]);
      		    	$pdf->SetLineWidth(1.1);
      		    	$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', 'B', 11);
      		    	$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Identify and describe how the employee has demonstrated their leadership in supporting the workplace either by leading a team or organization or as leader of a substantial project, process, or initiative. Considerations may include, but are not limited to:'));
      			  	$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to create, communicate, and implement a clear and compelling vision for their team and which aligns with the Corporate Plan for the BC Public Service;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to establish trust, motivate, and receive high satisfaction ratings from their employees and/or stakeholders;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to involve, empower, and lead staff through times of change;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates an investment in personal and organizational learning about trends and new ideas in their sector and the broader government context; Champions employee recognition, and collaborative team-based environments;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Commitment to succession management though knowledge transfer and mentorship;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Models the importance of respect, inclusion, ethics and integrity and ensure members are aware of their obligations with regards to ethics and professional conduct;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Proven support for those that are willing to try something new, recognizing their intent and effort but accept failure by not casting blame, but rather learning from it, improving and moving forward.'),0,"L");
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', '', 11);
      		    	$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      		    	$pdf->Ln();
      		    	break;
      		    case(27):
      		    	// Evaluation Considerations - Impact
      		    	$data = $submission->data[$field][0];
      		    	$pdf->SetFont('Arial', 'B', 12);
      		    	$pdf->Cell(40, 15, $labels[$field]);
      		    	$pdf->SetLineWidth(1.1);
      		    	$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', 'B', 11);
      		    	$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support (where applicable), the effect that the leader has had on employees, clients, the public service, and/or citizens of British Columbia. Considerations may include, but are not limited to:'));
      		    	$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrated improvement to the quality of the workplace for employees by contributing to the enhancement of diversity, health and safety, workplace culture and employee development;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrated support for innovation, new technology, and best practices; that resulted in the improvement of workplace processes i.e. reducing costs, increasing efficiencies, etc.'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Significantly improved the quality, cost-effectiveness, or productivity of services to internal or external stakeholders;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrated improvement to the quality of the workplace for employees by contributing to the enhancement of;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Measurable benefits to either their organization(s) and/or the citizens of British Columbia through process improvements to transform business practices, and/or support sustainable revenue generation or savings;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Significantly improved organizational performance as indicated by Work Environment Survey scores.'),0,"L");
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', '', 11);
      		    	$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      		    	$pdf->Ln();
      		    	break;
      		    case(28):
      		    	// Evaluation Considerations - Commitment to the Organization
      		    	$data = $submission->data[$field][0];
      		    	$pdf->SetFont('Arial', 'B', 12);
      		    	$pdf->Cell(40, 15, $labels[$field]);
      		    	$pdf->SetLineWidth(1.1);
      		    	$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', 'B', 11);
      		    	$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support (where applicable), the effect that the leader has had on employees, clients, the public service, and/or citizens of British Columbia. Considerations may include, but are not limited to:'));
      		    	$pdf->SetLeftMargin(25);

                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Anticipates future trends and works with others to develop strategies to meet future challenges;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Exhibits ability to make decisions with considerations of the long-term impacts and context, anticipating not just the current need but also emerging priorities;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Displays ability to demonstrate an experimental or innovative mindset whereby being open to change, taking calculated risks and challenging the status quo to try something new resulting in a measurable outcome;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Enables innovation by visibly and actively inviting and advancing new ideas within their organization and demonstrates the courage to embrace change;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates aptitude for strong client service orientation by ensuring that service design needs are driven by citizens’ needs or client outcomes, rather than internally focused metrics.'),0,"L");
      		    	$pdf->Ln();
      		    	$pdf->SetFont('Arial', '', 11);
      		    	$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      		    	$pdf->Ln();
      		    	break;
      		    default:
      		    	break;
      			}
      			}
      		 	break;
      		case('Organizational Excellence'):
      			foreach($fields as $field) {
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(5):
      					// Title of Nomination
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(21):
      					// Evaluation Considerations - Summary
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that summarizes or restates the main points of the nomination, submission or project. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main ideas and feature of the nomination.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(23):
      					// Evaluation Considerations - Context
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe why the new approach to the process, policy or service was undertaken.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(24):
      					// Evaluation Considerations - Complexity
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe the scope and scale of the delivery of the program, service, or initiative that resulted in substantial benefits to their organization, the public service or citizens of British Columbia, including:'));
      					$pdf->SetLeftMargin(25);
      					$pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Size of the program, service, or initiative;'));
      					$pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risks encountered;'));
      					$pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Identify constraints which may include time frames, financial, policy, etc.;'));
      					$pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Identifies challenges around aligning stakeholder or partner group interests;'));
      					$pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Technical or organizational difficulties identified and addressed;'));

      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(25):
      					// Evaluation Considerations - Approach
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', 'Identify key aspects of the approach taken in the delivery of the new program, service, or initiative that may include, but are not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The use of a citizen-centric or customer-centric approach at the heart of the design and/or implementation of a policy/project;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Support for innovation, risk taking, and a commitment to ongoing improvements by incorporating or contributing to best practices;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Removing barriers to overcome constraints;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Change resilience – demonstration of strategies that support success even while going through change and transformation;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Attention to cross-government processes critical for meeting stakeholder needs.'),0,"L");
      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(27):
      					// Evaluation Considerations - Impact
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support, the outcomes that the program, service, or initiative has had on the organization, public service or citizens of British Columbia including, not limited to:'));
      					$pdf->SetLeftMargin(25);

                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Process improvements in business practices;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Extent to which the outcomes and objectives have significantly improved government-to-business or government-to-citizen program or service delivery;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Extent to which the outcomes and o bjectives significantly improved government-to-business or government-to-citizen service delivery;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Increased client satisfaction to high quality service delivery;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Measurable benefits to either their organization(s) and/or the citizens of British Columbia through process improvements to transform business practices, and/or support sustainable revenue generation or savings;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Operational efficiencies as demonstrated by financial or other key performance indicators.'),0,"L");
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				default:
      					break;
      			}
      			}
      			break;
      		case('Partnership'):
      			foreach($fields as $field) {
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(5):
      					// Title of Nomination
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(21):
      					// Evaluation Considerations - Summary
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that summarizes or restates the main points of the nomination, project or partnership. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(23):
      					// Evaluation Considerations - Context
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe why the partnership was undertaken.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(24):
      					// Evaluation Considerations - Complexity
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe the scope and scale of the joint-ventures or multi-party initiatives including, but not limited to::'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Size of the project, process, or initiative;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risks encountered;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Constraints encountered and overcome (i.e. time frame, technical, financial, organizational, policy, etc.);'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Identify challenges around aligning stakeholder or partner group interests;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Technical or organizational difficulties addressed;'),0,"L");
      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(25):
      					// Evaluation Considerations - Approach
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Identify key aspects of the approach taken in key aspects of the partnership including, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Developing and managing sustained strategic partnerships with other government, private sector, volunteer or non-profit organizations that integrate policy and/or service delivery, with a view to better serving British Columbians;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Building relationships with internal or external stakeholder(s) to achieve mutually beneficial goals or mandates;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The use of a citizen-centric or customer-centric approach at the heart of the design and/or partnership;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Creativity and/or use of new technology or methods (i.e. behavioural insights, service design) to achieve results;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risk and/or change management strategy;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Application and/or development of best practices to remove barriers that may have prevented the successful outcome of the project;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstration of inclusive employee or citizen engagement practices with diverse stakeholder groups.'),0,"L");
      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(27):
      					// Evaluation Considerations - Impact
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support (where applicable), the effect that the partnership has had on the organization, public service or citizens of British Columbia including, not limited to:'));
                $pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Measurable benefits to the organization(s) and/or the citizens of British Columbia through process improvements that transform business practices, and/or support sustainable revenue generation or savings;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect on the community, internal or external stakeholders including any social, economic, and environmental benefits achieved as the result of the partnership;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Extent to which the outcomes and objectives of the project, program or initiative were achieved;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect that the partnership had on operational efficiencies as demonstrated by financial or other key performance indicators;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect on the improved quality, cost-effectiveness, or productivity of services to internal and/or external stakeholders and/or the citizens of British Columbia;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Extent to which the outcomes and objectives have significantly improved government-to-business or government-to-citizen program or service delivery.'),0,"L");
                $pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				default:
      					break;
      			}
      			}
      			break;
      		case('Legacy'):
      			foreach($fields as $field) {
      			// Evaluation Considerations - Legacy
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(69):
      					// Name of Legacy Nominee
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(21):
      					// Evaluation Considerations - Summary
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that that summarizes or restates the main points of the nomination, personal contribution or lasting legacy within the BC Public Service and/or the province of British Columbia. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(23):
      					// Evaluation Considerations - Context
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe the conditions under which the employee demonstrated their contribution to the BC Public Service including career highlights.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(24):
      					// Evaluation Considerations - Complexity
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Explain how the employee has demonstrated exemplary leadership throughout their career including, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to demonstrate superior leadership through complex situations including: large-scale initiatives; managing and mitigating risks; creatively solving problems and implementing solutions;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Constraints encountered and overcome (i.e. time frame, technical, financial, organizational, policy, etc.);'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Application and/or development of best practices to remove barriers that may have prevented successful outcomes.'),0,"L");
      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(26):
      					// Evaluation Considerations - Valuing People
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'Identify and describe how the employee has demonstrated their leadership in supporting the workplace either by leading a team or organization or as leader of a substantial project, process, or initiative. Considerations may include, but are not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to create, communicate, and implement a clear and compelling vision for their team and which aligns with the Corporate Plan for the BC Public Service;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Anticipates future trends and works with others to develop strategies to meet future challenges;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to establish trust, motivate, and receive high satisfaction ratings from their employees and/or stakeholders;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to involve, empower, and lead staff through times of change;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates an investment in personal and organizational learning about trends and new ideas in their sector and the broader government context;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Commitment to succession management though knowledge transfer and mentorship;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Models the importance of respect, inclusion, ethics and integrity and ensure members are aware of their obligations with regards to ethics and professional conduct.'),0,"L");

      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(27):
      					// Evaluation Considerations - Impact
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support (where applicable), the ongoing positive contributions the individual has made to the BC Public Service and/or the province of British Columbia. Considerations may include, but are not limited to:'));
                $pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Measurable benefits to either their organization(s) and/or the citizens of British Columbia;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Impact the nominees’ career has had on the community, internal operations and/or external organizations including any social, economic, and environmental benefits achieved as the result of their body of work;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrated improvement to the quality of the workplace for employees by contributing to the enhancement of diversity, health and safety, workplace culture and employee development;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Proven ability to demonstrate an experimental or innovative mindset whereby being open to change, taking calculated risks and challenging the status quo to try something new resulted in a measurable outcome;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Significantly improved the quality, cost-effectiveness, or productivity of services to internal or external stakeholders;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Significantly improved government-to-business or government-to-citizen service delivery;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Provincial, national or global recognition for the contributions the nominee has made to the development of best practices in their field of expertise.'),0,"L");

      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(38):
      					// Evaluation Considerations - Contribution to BC Public Service Excellence
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe how the individual approached leadership that resulted in public service excellence. Considerations include, but are not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Outstanding dedication to their work while maintaining a high level of commitment to BC Public Service values and government direction;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Leads others in ways that embody the ideal vision of leadership within the BC Public Service;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Exhibits ability to make decisions with considerations of the long-term impacts and context, anticipating not just the current need but also emerging priorities;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Enables innovation by visibly and actively inviting and advancing new ideas within their organization and demonstrates the courage to embrace change;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Facilitating, re-enforcing, and successfully leading through changes necessary to promote innovation, continuous improvement, or improved service delivery to internal or external clients;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates aptitude for strong client service orientation by ensuring that service design needs are driven by citizen’s needs or client outcomes rather than internally focused metrics;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstration of public service values throughout their career while continually developing their subject matter expertise;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstration of their commitment to diversity and inclusiveness in both the work environment and in the development of programs, policies and services.'),0,"L");

      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				default:
      					break;
      			}
      			}
      			break;
      		case('Emerging Leader'):
      			foreach($fields as $field) {
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(54):
      					// Name of Nominee
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(21):
      					// Evaluation Considerations - Summary
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that that summarizes or restates the main points of the nomination, submission or personal contribution. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(23):
      					// Evaluation Considerations - Context
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe the conditions under which the employee has demonstrated exemplary formal or informal leadership.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(26):
      					// Evaluation Considerations - Valuing People
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Identify and describe how the employee has demonstrated their leadership in supporting the workplace including, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Ability to demonstrate leadership through innovative problem solving, team building and collaboration with colleagues at all levels of the organization;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Actively enhancing the quality of the workplace through demonstrating a commitment to diversity and inclusiveness in both the work environment and in the development of programs, policies and services;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Models integrity and a commitment to ethical conduct and decision making.'),0,"L");
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(27):
      					// Evaluation Considerations - Impact
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support (if applicable), how the employee exemplifies the future of corporate leadership as demonstrated through, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The effect that the leader has had on employees, clients, the public service, and/or citizens of British Columbia.'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrated improvement to the quality of the workplace for employees by contributing to the enhancement of diversity, health and safety, workplace culture and employee development;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrated support for innovation, new technology, and best practices; that resulted in the improvement of workplace processes i.e. reducing costs, increasing efficiencies, safety, etc.'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Measurable benefits to either their organization(s) and/or the citizens of British Columbia through process improvements to transform business practices, and/or support sustainable revenue generation or savings.'),0,"L");
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(28):
      					// Evaluation Considerations - Commitment to the Organization
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Identify and describe how the employee has demonstrated their leadership in operations including, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates commitment to and pride in the BC Public Service by contributions that enhance its reputation;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Proven thought-leader who can constructively articulate a strong case for change by challenging assumptions, timelines and recommendations to ensure that they are driven by citizens’ needs rather than administrative convenience;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates support for workplace innovation, new technology, and best practices by modelling a culture of curiosity, seeking out new knowledge, collaboration, encouraging dialogue and inviting competing ideas;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Exhibits ability to make decisions with considerations of the long-term impacts and context, anticipating not just the current need but also emerging priorities;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates thoughtful risk management and ability to accept failure by learning from it, improving and moving forward;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrates success through measurable project/program outcomes.'),0,"L");
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				default:
      					break;
      			}
      			}
      			break;
      		case('Evidence Based Design'):
      			foreach($fields as $field) {
      			switch($field){
      				case(1):
      					// Name of Ministry or eligible organization sponsoring this application
      					$data = $ministries[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(41):
      					// Application Type
      					$data = $app_type[$submission->data[$field][0]];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
//      				case(4):
//      					// Region
//      					$data = $regions[$submission->data[$field][0]];
//      					$pdf->SetFont('Arial', 'B', 12);
//      					$pdf->Cell(40, 5, $labels[$field]);
//      					$pdf->Ln();
//      					$pdf->SetFont('Arial', '', 11);
//      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//      					$pdf->Ln();
//      					break;
      				case(5):
      					// Title of Nomination
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
      					$pdf->Ln();
      					break;
      				case(63):
      					// Nominator Name
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 5, $labels[$field]);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(21):
      					// Evaluation Considerations - Summary
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that that summarizes or restates the main points of the nomination, project or partnership. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(23):
      					// Evaluation Considerations - Context
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe why the policy or program was developed.'));
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(24):
      					// Evaluation Considerations - Complexity
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe the scope and scale of the evidence-based or evidence-informed approach to developing the policy or program including but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' What necessitated the development of the policy or program? Describe the reason and evidence for the change or initiative;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risks encountered and overcome;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Identify constraints which may include time frames, financial, existing policy, etc.;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Identifies challenges around aligning stakeholder or partner group interests;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Technical or organizational difficulties identified and addressed.'),0,"L");

      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(25):
      					// Evaluation Considerations - Approach
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe how the new policy or program used an evidence-based or evidence-informed approach for the development from inception to delivery including, but not limited to:'));
      					$pdf->SetLeftMargin(25);

                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The evidence-based or evidence-informed process in which the policy framework was designed;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstration of the policy cycle including clear problem identification, current state, best practices or leading edge and gap analysis, development and balanced analysis of options, evidence-based or evidence-informed decision making, implementation, evaluation;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The use of foundational policy analysis tools to support recommendations (i.e. data and/or cost analysis, cross-jurisdictional and/or international reviews, peer reviewed research, stakeholder engagement etc.);'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The use of new technology or tools (i.e. Data Science, Service Design, etc. to support policy recommendations);'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Inclusive citizen engagement practices that reflects a diverse population within British Columbia.'),0,"L");
      					$pdf->SetLeftMargin(20);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				case(27):
      					// Evaluation Considerations - Impact
      					$data = $submission->data[$field][0];
      					$pdf->SetFont('Arial', 'B', 12);
      					$pdf->Cell(40, 15, $labels[$field]);
      					$pdf->SetLineWidth(1.1);
      					$pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
      					$pdf->Ln();
      					$pdf->SetFont('Arial', 'B', 11);
      					$pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Capture the impact of, and use metrics to support (if applicable), the evidence-based approach that resulted in the new policy or program as demonstrated by, but not limited to:'));
      					$pdf->SetLeftMargin(25);
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect on the community, internal or external stakeholders including any social, economic, and environmental benefits achieved as the result of the policy or program;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Extent to which the outcomes and objectives of the policy or program were achieved;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect that the policy or program had on operational efficiencies as demonstrated by financial or other key performance indicators;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Quantitative or measurable improvement to the programs or services;'),0,"L");
                $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Application and/or development of best practices to remove barriers that may have prevented the successful outcome of the policy or program.'),0,"L");
      					$pdf->Ln();
      					$pdf->SetFont('Arial', '', 11);
      					$pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
      					$pdf->Ln();
      					break;
      				default:
      					break;
      			}
      			}
      			break;
          case('Regional Impact'):
            foreach($fields as $field) {
              switch($field){
                case(1):
                  // Name of Ministry or eligible organization sponsoring this application
                  $data = $ministries[$submission->data[$field][0]];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 5, $labels[$field]);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                case(41):
                  // Application Type
                  $data = $app_type[$submission->data[$field][0]];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 5, $labels[$field]);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
//                case(4):
//                  // Region
//                  $data = $regions[$submission->data[$field][0]];
//                  $pdf->SetFont('Arial', 'B', 12);
//                  $pdf->Cell(40, 5, $labels[$field]);
//                  $pdf->Ln();
//                  $pdf->SetFont('Arial', '', 11);
//                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
//                  $pdf->Ln();
//                  break;
                case(5):
                  // Title of Nomination
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 5, $labels[$field]);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT', $data));
                  $pdf->Ln();
                  break;
                case(63):
                  // Nominator Name
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 5, $labels[$field]);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                case(21):
                  // Evaluation Considerations - Summary
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 15, $labels[$field]);
                  $pdf->SetLineWidth(1.1);
                  $pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', 'B', 11);
                  $pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','In this section, provide a brief statement that summarizes or restates the main points of the nomination, submission or project, including a brief description of the town, city, or region. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
//                  $pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.'));
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                case(23):
                  // Evaluation Considerations - Context
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 15, $labels[$field]);
                  $pdf->SetLineWidth(1.1);
                  $pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', 'B', 11);
                  $pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','To establish a background that will provide perspective to the work achieved, briefly describe why the policy or program was developed.'));
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                case(24):
                  // Evaluation Considerations - Complexity
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 15, $labels[$field]);
                  $pdf->SetLineWidth(1.1);
                  $pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', 'B', 11);
                  $pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe the scope and scale of the program, project or initiative that resulted in significant impact that directly benefited local citizens, including but not limited to:'));
                  $pdf->SetLeftMargin(25);
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Size of the program, service, or initiative;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risks encountered;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Challenges around introducing a new approach to solve a problem;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Constraints encountered and overcome, which may include timeframes, financial, policy, technical, etc.;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Challenges around aligning stakeholder or partner group interests.'),0,"L");
                  $pdf->SetLeftMargin(20);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                case(25):
                  // Evaluation Considerations - Approach
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 15, $labels[$field]);
                  $pdf->SetLineWidth(1.1);
                  $pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', 'B', 11);
                  $pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe key aspects of the approach taken throughout the development of the new program, project or initiative including, but not limited to:'));
                  $pdf->SetLeftMargin(25);
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' The process used to generate innovative ideas, fresh perspectives, new opportunities, and creativity in the design;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Application of a user-centric or citizen-centric approach in the development of the initiative/program;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Adapting and refining the approach when things did not work well and learning from the setbacks/mistakes;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Application and/or development of best practices to remove barriers that may have prevented the successful outcome of the project;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Risk and/or change management strategy;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Building relationships with external stakeholder(s) to achieve mutually beneficial goals or mandates;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstration of inclusive citizen engagement practices with diverse stakeholder groups.'),0,"L");
//                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' '),0,"L");

                  $pdf->SetLeftMargin(20);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                case(27):
                  // Evaluation Considerations - Impact
                  $data = $submission->data[$field][0];
                  $pdf->SetFont('Arial', 'B', 12);
                  $pdf->Cell(40, 15, $labels[$field]);
                  $pdf->SetLineWidth(1.1);
                  $pdf->Line(21.5,$pdf->GetY() + 11,188,$pdf->GetY() + 11);
                  $pdf->Ln();
                  $pdf->SetFont('Arial', 'B', 11);
                  $pdf->MultiCell(166.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT','Describe, and use metrics to support (if applicable), the outcomes and impact that the program, project or initiative has had on the BC Public Service and local citizens including, but not limited to:'));
                  $pdf->SetLeftMargin(25);
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Demonstrate how an experimental or innovative mindset that was open to change, taking calculate risks, and challenging the status quo resulted in a measurable outcome;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Extent to which the outcomes and objectives of the project, program or initiative were achieved;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Quantitative or measurable improvement to the program, project or initiative;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Efficiencies, improvements as demonstrated by financial or other key performance indicators;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect on the community, internal or external stakeholders including any social, economic, and environmental benefits achieved;'),0,"L");
                  $pdf->MultiCell(161.5, 5, iconv('UTF-8', 'ASCII//TRANSLIT', chr(127) . ' Effect that the impact has had on external stakeholders such as increased client satisfaction to high quality service delivery.'),0,"L");

                  $pdf->Ln();
                  $pdf->SetFont('Arial', '', 11);
                  $pdf->MultiCell(0, 5, iconv('UTF-8', 'ASCII//TRANSLIT',$data));
                  $pdf->Ln();
                  break;
                default:
                  break;
              }
            }
            break;
      		default:
      			break;
    }


  $attachments = array('33','34','35','36','37');
  $has_attachment = TRUE;

  foreach($attachments as $attachment) {
    //Only print attachments title once, IFF there are any attachments
    if($has_attachment && isset($submission->data[$attachment][0])) {
      $pdf->SetFont('Arial', 'B', 16);
      $pdf->Cell(40, 10, 'Attachments');
      $pdf->Ln();
      $has_attachment = FALSE;
    }
    if(isset($submission->data[$attachment][0])){
      $fid = $submission->data[$attachment][0];
      $result = db_query(
        "Select filename from atwork_file_managed where fid like " . $fid
      );
      $filename = $result->fetch()->filename;
      $pdf->SetFont('Arial', '', 12);
      $pdf->Cell(40, 10, $filename);
      $pdf->Ln();
      copy(DRUPAL_ROOT . '/sites/default/files/webform/' . $filename, DRUPAL_ROOT . '/PA/' . $submission->serial . '/' . $filename);
    }
  }

  $pdf->Output('F', $dn . $submission->serial . '/submission_data.pdf');
}
