<?php

function _atwork_prem_awards_ministry_contacts() {
  return array(
    // All ministry contacts must be included in the exact same order as the ministry dropdown (i.e. aboriginal contact in array [1], advanced ed in array [2])
    1 => 'Jeff.Keene@gov.bc.ca;Ross.Palin@gov.bc.ca', //Aboriginal Relations & Reconciliation
    2 => 'Ross.Palin@gov.bc.ca', //Ministry of Advanced Education
    3 => 'Susan.Fair@gov.bc.ca', //Agriculture
    4 => 'Gail.Crosby@gov.bc.ca', //Children & Family Development
    5 => 'Alicia.Matthews@gov.bc.ca', //Community Sport and Cultural Development
    6 => 'Karli.Reeve@gov.bc.ca', //Education
    7 => 'Janine.Crockett@gov.bc.ca', //Energy and Mines & Natural Gas Development
    8 => 'Bev.Crozier@gov.bc.ca', //Environment
    9 => 'Shelley.MacLean@gov.bc.ca', //Finance
    10 => 'Dana.Eckardt@gov.bc.ca', //Forests, Lands and Natural Resource Operations
    11 => 'Laura.Smithson@gov.bc.ca', //Health
    12 => 'Rachel.Rilkoff@gov.bc.ca', //Health
    13 => 'Alicia.Matthews@gov.bc.ca',  //International Trade
    14 => 'Alicia.Matthews@gov.bc.ca', //Jobs, Tourism and Skills Training
    15 => 'Marlene.Dayman@gov.bc.ca', //Justice and the Attorney General
    16 => 'Robert.Meseyton@gov.bc.ca', //Justice and the Attorney General
    17 => 'Marlene.Dayman@gov.bc.ca', //Justice and the Attorney General
    18 => 'Kathy.Cornett@gov.bc.ca', //Public Safety & Solicitor General
    19 => 'Karla.Limion@gov.bc.ca', //Public Safety & Solicitor General
    20 => 'Robert.Meseyton@gov.bc.ca', //Public Safety & Solicitor General
    21 => 'Janine.Crockett@gov.bc.ca', //Natural Gas Development
    22 => 'Alicia.Matthews@gov.bc.ca', //Small Business and Red Tape Reduction
    23 => 'Carolyn.Babakaiff@gov.bc.ca', //Social Development and Social Innovation
    24 => 'Jeannette.Cook@gov.bc.ca', //Technology, Innovation and Citizens’ Services
    25 => 'Gloria.Valle@gov.bc.ca', //Transportation and Infrastructure
    26 => 'Sandra.Roe@gov.bc.ca', //BC Public Service Agency
    27 => 'Janelle.Heron@gov.bc.ca', //Government Communications and Public Engagement
    28 => 'Sandy.Wharf@gov.bc.ca', //Office of the Premier
    29 => 'Elizabeth.Thomson@partnershipsbc.ca', //Partnerships BC
    30 => 'smaloney@Trustee.bc.ca', //Public Guardian and Trustee
    31 => 'Barbara.Wilson@gov.bc.ca', //Public Sector Employers Council
    32 => 'Christina.Dawkins@gov.bc.ca', //Finance
    33 => 'Yvonne.ChadwickWhittome@gov.bc.ca', //Finance
    34 => 'Sabrina.Loiacono@gov.bc.ca', //EAO
  );
}

function _atwork_prem_awards_headers() {
  return array(
    1 => '<h3>CROSS GOVERNMENT INTEGRATION</h3>This award, which is presented <em>regionally and provincially</em>, recognizes two or more BC Public Service organizations that have collaboratively delivered a program or service that has resulted in substantial benefits to clients, the public service, or citizens.',
    2 => '<h3>INNOVATION</h3>The Innovation award recognizes groups, teams or organizations within the BC Public Service that have developed and transformed new ideas into tangible initiatives, programs or projects. Innovations may streamline business processes, leverage technology, or pursue creative solutions to fulfill organizational mandates. This award is recognized both regionally and provincially. <strong>Approache</strong>s to innovation in the workplace may include:
	  <ul><li>The use of new technology to enhance program and service delivery or improve upon existing processes and procedures;</li>
      <li>Improves performance by doing things that may be unique, leading-edge, or new to the public sector;</li>
      <li>Changes the organizational culture or the traditional <strong>approach </strong>to management or problem solving; or</li>
      <li>Challenging the status quo, trying something new, adapting and refining when things have not worked well, and learning from the development of policy or services.</li>
      <li>Commitment to service delivery in exceeding the needs/expectations of internal or external clients;</li></ul>',
    3 => '<h3>LEADERSHIP</h3>The Leadership award recognizes a BC Public Service employee who demonstrates the highest levels of exemplary leadership attributes and abilities. This award is recognized both regionally and provincially. Considerations include, but are not limited to:
      <ul><li>Ability to create, communicate, and implement a clear and compelling vision;</li>
	<li>Ability to establish trust, motivate, and receive high satisfaction ratings from their employees; </li>
	<li>Anticipates future trends and works with others to develop strategies to meet future challenges;</li>
	<li>Commitment to continuous learning, employee recognition, and collaborative team-based environments; </li>
	<li>Ability to involve, empower, and lead staff through times of change;</li>
	<li>Commitment to service delivery in exceeding the needs/expectations of internal or external clients;</li>
	<li>Demonstrated support for innovation, new technology, and best practices; </li>
	<li>Demonstrated leadership to achieve significant and superior results.</li>
</ul>',
    4 => '<h3>ORGANIZATIONAL EXCELLENCE</h3>The Organizational Excellence award recognizes one or more BC Public Service organizations that have delivered a program, service, or initiative resulting in substantial benefits to their organization(s), the public service, or citizens of British Columbia. This award is recognized both regionally and provincially. Considerations may include, but are not limited to:
      <ul>
	<li>Placing customer needs and feedback at the heart of the design and/or implementation of a policy/project and being open to new ways of working and new delivery models;</li>
	<li>Significantly improving the quality, cost-effectiveness or productivity of services to internal or external stakeholders;</li>
	<li>Outstanding contributions to the delivery of quality customer service; or</li>
	<li>Measureable benefits to either their organizations(s) and/or the citizens of British Columbia through process improvements to transform business practices, and/or support sustainable revenue generation or savings.</li>
	  </ul>',
    5 => '<h3>PARTNERSHIP</h3>The Partnership award recognizes joint-ventures or multi-party initiatives between BC Public Service organizations and organizations in the broader public sector, other levels of government, First Nations communities, or in the private or not-for-profit sectors. This award is recognized both regionally and provincially.',
    6 => '<h3>LEGACY</h3>The Legacy award recognizes individuals who have made exceptional and lasting contributions to the BC Public Service and/or the province of British Columbia during a public service career of at least 15 years. The contributions may cover a nominee’s entire career or portions of it, provided that the contribution has a lasting and ongoing positive impact. This award is presented at the provincial level only.',
    7 => '<h3>EMERGING LEADER</h3>The Emerging Leader award recognizes an employee, under the age of forty (40) and below the level of Director, who has made a significant impact on their ministry, division, workgroup, or the greater BC Public Service.  This award is presented at the provincial level only.',
  );
}
// "<br /><ul><li></li><li></li><li></li><li></li></ul>";
function _atwork_prem_awards_questions() {
  $translations = array();
  $translations[1][1] = "The submission should describe two or more BC Public Service organizations for taking an integrated <strong>approach </strong>to service/program delivery that produces substantial benefits.";
  $translations[1][2] = "Breadth and degree of impact the program or service has had on its intended audience (internal or external)";
  $translations[1][3] = "Alignment with public service vision, values and overall government direction";
  $translations[1][4] = "Complexity involved including:<ul><li>the scope of the initiative;</li><li>risks encountered and overcome;</li><li>creativity demonstrated;</li><li>technical or organizational difficulties addressed;</li><li>financial constraints managed</li></ul>";
  $translations[1][5] = "Application of and/or development of best practices including:<ul><li>Attention to cross-government processes critical for meeting client needs;</li><li>Involvement of clients/suppliers/partners in integration initiatives (e.g.: problem solving);</li><li>Use of external resources and or benchmarking to compare performance and stimulate ongoing improvement.</li></ul>";
  $translations[1][6] = '';
  $translations[1][7] = '';
  $translations[1][8] = '';
  $translations[1][9] = '';

  $translations[2][0] = 'In this section, provide a brief statement that that summarizes or restates the main points of the nomination, submission or project. The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.<br />(Note that this section will be used by the Premier’s Awards team for communications purposes if this nomination is selected as a finalist.)';
  $translations[2][1] = "To establish a background that will provide perspective to the work achieved, briefly describe why the new innovative <strong>approach </strong>was undertaken.";
  $translations[2][3] = "<strong>Approach:</strong><br />Briefly describe how the new product or service was developed from inception to delivery including, but not limited to:<ul><li>Identify how the new <strong>approach </strong>demonstrates an improved process, product or service;</li><li>Using new technology to enhance a program or service delivery to improve upon existing processes and procedures;</li><li>Demonstrates why and how this was innovative;</li><li>Describe the any testing and process improvements along the way;</li><li>Explain how the team managed and overcame risks encountered to adapt and refine the process; or </li><li>Creativity in the design or redesign the programs or services.</li></ul>";
  $translations[2][2] = "<strong>Complexity:</strong><br />Identify and outline scope of the streamlined business processes, technology, or creative solutions to fulfill organizational mandates including, but not limited to:<ul><li>Size of the project, process, technology solution;</li><li>Risks encountered and overcome;</li><li>Technical or organizational difficulties addressed;</li><li>Financial constraints managed.</li><li>Challenges around introducing a new <strong>approach </strong>to solve a challenging problem;</li></ul>";
  $translations[2][4] = "<strong>Impact:</strong><br />Capture the impact of, and use metrics to support (if applicable), the innovative <strong>approach </strong>to programs and services as demonstrated by, but not limited to:<ul><li>Improved performance by doing things that may be unique, leading-edge, or new to the public service;</li><li>Describe the long-term benefits to internal or external stakeholders;</li><li>Effect that the innovative <strong>approach </strong>to the programs or services has had on its intended internal or external stakeholders;</li><li>Effect that the innovative <strong>approach </strong>to the programs or services has had on the internal operations of the individuals, teams, or organizations delivering the programs or services;</li><li>Quantitative or measurable improvement to the programs or services.</li></ul>";
  $translations[2][5] = "";
  $translations[2][6] = "";
  $translations[2][7] = '';
  $translations[2][8] = '';
  $translations[2][9] = '';

  $translations[3][0] = 'In this section, provide a brief statement that that summarizes or restates the main points of the nomination, submission or personal contribution.  The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.<br /> (Note that this section will be used by the Premier’s Awards team for communications purposes if this nomination is selected as a finalist.)';
  $translations[3][1] = "To establish a background that will provide perspective to the work achieved, briefly describe the conditions under which the employee demonstrated exemplary leadership.";
  $translations[3][2] = "<strong>Complexity:</strong><br />Describe the scope and scale of the nominee’s superior leadership acumen including, but not limited to:<ul><li>Size of the project, process, or initiative managed;</li><li>Constraints encountered and overcome under their leadership (i.e. time frame, technical, financial, organizational and/or policy);</li><li>Identify challenges around aligning stakeholder or partner group interests;</li><li>Technical or organizational difficulties addressed.</li></ul>";
  $translations[3][3] = "<strong>Valuing People:</strong><br />Identify and describe the “people” element, in relation to:<ul><li>Champions continuous learning, employee recognition, and collaborative team-based environments;</li><li>Engages people and partners in developing opportunities for innovation and continuous learning;</li><li>Committed to service delivery in exceeding the needs/expectations of internal or external clients;</li><li>Involves, empowers, and leads staff through times of change.</li></ul>";
  $translations[3][4] = "<strong>Impact:</strong><br />Describe, and use metrics to support (where applicable), the effect that the leader has had on employees, clients, the public service, and/or citizens of British Columbia. Considerations may include, but are not limited to:<ul><li>Creating, communicating and implementing a clear and compelling vision;</li><li>Measurable outcomes in client and/or organizational satisfaction;</li><li>Demonstrated improvement to the quality of the workplace for employees by contributing to the enhancement of diversity, health and safety, workplace culture and employee development; </li><li>Improvement to workplace processes by adopting innovative <strong>approache</strong>s to existing procedures, reducing costs and/or increasing efficiencies.</li></ul>";
  $translations[3][5] = "";
  $translations[3][6] = "";
  $translations[3][7] = '';
  $translations[3][8] = '';
  $translations[3][9] = '';

  $translations[4][0] = "In this section, provide a brief statement that that summarizes or restates the main points of the nomination, submission or project.  The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main ideas and feature of the nomination.<br/> (Note that this section will be used by the Premier’s Awards team for communications purposes if this nomination is selected as a finalist.)";
  $translations[4][1] = "To establish a background that will provide perspective to the work achieved, briefly describe why the new <strong>approach </strong>to the process, policy or service was undertaken.";
  $translations[4][2] = "<strong>Complexity:</strong><br />Describe the scope and scale of the process, policy or service to citizens including, but not limited to:<ul><li>Size of the program, service, or initiative;</li><li>Risks encountered;</li><li>Identify constraints which may include time frames, financial, policy, etc.;</li><li>Use of creativity or fresh <strong>approach </strong>in achieving desired outcomes;</li><li>Technical or organizational difficulties identified and addressed;</li></ul>";
  $translations[4][3] = "<strong>Approach:</strong><br />Identify key aspects of the program, service, or initiative that may include, but are not limited to:<ul><li>Customer consultation and the incorporation of the feedback;</li><li>Support for innovation, risk taking, and a commitment to ongoing improvements by incorporating  or contributing to best practices;</li><li>Removing barriers to overcome constraints;</li><li>Change resilience – demonstration of strategies that support success even while going through change and transformation;</li><li>Attention to cross-government processes critical for meeting stakeholder needs.</li></ul>";
  $translations[4][4] = "<strong>Impact:</strong><br />Describe, and use metrics to support, the outcomes that the process, policy or services to citizens has had including, not limited to;<ul><li>Process improvements in business practices;</li><li>Increased client satisfaction to high quality service delivery;</li><li>Improved quality, cost-effectiveness or productivity of services to the public;</li><li>Operational efficiencies as demonstrated by financial or other key performance indicators.</li></ul>";
  $translations[4][5] = "";
  $translations[4][6] = "";
  $translations[4][7] = "";
  $translations[4][8] = "";
  $translations[4][9] = "";


  $translations[5][0] = "In this section, provide a brief statement that that summarizes or restates the main points of the nomination, project or partnership.  The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.<br />(Note that this section will be used by the Premier’s Awards team for communications purposes if this nomination is selected as a finalist.)";
  $translations[5][1] = "To establish a background that will provide perspective to the work achieved, briefly describe why the partnership was undertaken.";
  $translations[5][2] = "<strong>Complexity:</strong><br />Identify and outline scope of partnership including, but not limited to:<ul><li>Size of the project or initiative;</li><li>Constraints encountered and overcome (i.e. time frame, technical, financial, organizational and/or policy);</li><li>Identify challenges around aligning stakeholder or partner group interests;</li><li>Technical or organizational difficulties addressed.</li></ul>";
  $translations[5][3] = "<strong>Approach:</strong><br />Identify key aspects of the partnership including, but not limited to:<ul><li>Creativity and/or use of new technology to achieve results;</li><li>Building relationships with internal or external stakeholder(s) to achieve mutually beneficial goals or mandates;</li><li>Risk and/or change management strategy;</li><li>Use of, or development of, best practices;</li><li>Application and/or development of best practices to remove barriers that may have prevented the successful outcome of the project.</li></ul>";
  $translations[5][4] = "<strong>Impact:</strong><br />Describe, and use metrics to support (where applicable), the effect that the partnership has had including, not limited to:<ul><li>Effect on the community, internal or external stakeholders including any social, economic, and environmental benefits achieved as the result of the partnership;</li><li>Extent to which the outcomes and objectives of the project, program or initiative were achieved;</li><li>Effect that the partnership had on operational efficiencies as demonstrated by financial or other key performance indicators;</li><li>Quantitative or measurable improvement to the programs or services.</li></ul>";
  $translations[5][5] = "";
  $translations[5][6] = '';
  $translations[5][7] = '';
  $translations[5][8] = '';

  $translations[6][0] = "In this section, provide a brief statement that that summarizes or restates the main points of the nomination, personal contribution or lasting legacy within the BC Public Service and/or the province of British Columbia.  The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.<br/>(Note that this section will be used by the Premier’s Awards team for communications purposes if this nomination is selected as a finalist.)";
  $translations[6][1] = "To establish a background that will provide perspective to the work achieved, briefly describe the conditions under which the employee demonstrated their contribution to the BC Public Service including career highlights.";
  $translations[6][2] = "Complexity:<br />Explain how the employee has demonstrated superior leadership through complex situations including, but not limited to:<ul><li>Large-scale initiatives;</li><li>Managing and mitigating risks;</li><li>Creatively solving problems and implementing solutions;</li><li>Achieving outcomes in spite of constraints (e.g. technical, organizational, financial).</li></ul>";
  $translations[6][3] = "<strong>Contribution to BC Public Service excellence:</strong><br />Describe how the individual <strong>approache</strong>d leadership in public service excellence through, but not limited to:<ul><li>Facilitating, re-enforcing, and successfully leading through changes necessary to promote innovation, continuous improvement, or improved service delivery to internal or external clients;</li><li>Continually demonstrating the ability to exceed the needs of stakeholders and internal or external clients;</li><li>Outstanding dedication to their work while maintaining a high level of commitment to BC Public Service values;</li><li>Mentoring and empowering colleagues, coworkers, and staff to strive for excellence.</li></ul>";
  $translations[6][4] = "<strong>Impact:</strong><br />Describe, and use metrics to support (if applicable) the ongoing positive contributions the individual has made to the BC Public Service and/or the province of British Columbia.";
  $translations[6][5] = '';
  $translations[6][6] = '';
  $translations[6][7] = '';
  $translations[6][8] = '';

  $translations[7][0] = 'In this section, provide a brief statement that that summarizes or restates the main points of the nomination, submission or personal contribution.  The purpose of the summary is to give the adjudicators and judges a condensed and objective account of the main idea(s) and accomplishment(s) of the nomination.<br />(Note that this section will be used by the Premier’s Awards team for communications purposes if this nomination is selected as a finalist.)';
  $translations[7][1] = "To establish a background that will provide perspective to the work achieved, briefly describe the conditions under which the employee demonstrated exemplary leadership.";
  $translations[7][2] = "<strong>Valuing People:</strong><br />Identify and describe how the employee has demonstrated their leadership in supporting the workplace through, but not limited to:<ul><li>Actively enhancing the quality of the workplace through innovative problem solving, collaboration and a strong client service orientation;</li><li>Championing continuous learning, employee recognition and collaborative team-based environments;</li><li>Articulating a vision that involves, empowers, and motivates others through times of change;</li><li>Demonstrating superior informal leadership abilities with colleagues and co-workers at all levels.</li></ul>";
  $translations[7][3] = "<strong>Commitment to the Organization:</strong><br />Identify and describe how the employee has demonstrated their leadership in operations through, but not limited to:<ul><li>Improving workplace processes;</li><li>Seeking creative solutions to improve efficiency;</li><li>Significantly reducing operating expenses without compromising service delivery to internal or external clients.</li></ul>";
  $translations[7][4] = "<strong>Impact:</strong><br />Describe, and use metrics to support (if applicable), how the employee exemplifies the future of corporate leadership as demonstrated through, but not limited to:<ul><li>Outstanding MyPerformance scores and corporate engagement results;</li><li>Measurable outcomes in client and/or organizational satisfaction;</li><li>Improvement to workplace processes by adopting innovative <strong>approache</strong>s to existing procedures, reducing costs and/or increasing efficiencies.</li></ul>";
  $translations[7][5] = "";
  $translations[7][6] = '';
  $translations[7][7] = '';
  $translations[7][8] = '';
  $translations[7][9] = '';

  return $translations;
}
