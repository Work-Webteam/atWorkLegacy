(function ($) {
  /**
   * Function that sets form to accept a ministries choices for retroactive awards.
   */
  function setMinistryOptions(ministry){
    switch(true){
      //Only One retro pin allowed
      case ministry === '4': // Ministry of Agriculture, Food and Fisheries
      case ministry === '3': // Agricultural Land Commission
        // We can only allow one box to be checked if they have chosen
        $('#edit-field-lsa-other-milestone-years').slideDown('slow');
        // Make sure our labels are set correctly
        if($('#edit-field-lsa-previous-service-miles-und').not('atwork-activity-processed')){
          $('#edit-field-lsa-previous-service-miles-und').addClass('atwork-activity-processed');
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').prop('checked', false);
          // Allow them to choose one pin:
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').on('change', function() {
            $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').not(this).prop('checked', false);
          });
        }
      break;

      case ministry === '111' : //Nobody is this case for now. Turning off.
      /**  Pin option should only be available if a person indicates they are currently
      *	  celebrating a milestone, and choose a "current year pin". They may request one retro pin in addition to that.
      **/
       // Check if this had other restrictions previously
        if($('#edit-field-lsa-previous-service-miles-und').hasClass('atwork-activity-processed')){
          $('#edit-field-lsa-previous-service-miles-und').removeClass('atwork-activity-processed');
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').unbind();
        }
        if($('#edit-field-lsa-milestone-year-und').hasClass('atwork-activity-processed')){
          // If we have a notice we don't need, detach it, and be ready to re-apply as necessary
          $('#select-message').detach();
          $('#edit-field-lsa-milestone-year-und').removeClass('atwork-activity-processed');
        }
        // Check if they are celebrating this year
        if($('#edit-field-lsa-milestone-year-und-1').is(':checked')){
          // If so, then they can choose prev years.
          $('#edit-field-lsa-other-milestone-years').slideDown('slow');

        } else {
          // Add note
          if($('#edit-field-lsa-milestone-year-und').hasClass('atwork-activity-processed')){
            // We are fine, nothing to do
          } else {
            $('#edit-field-lsa-milestone-year-und').addClass('atwork-activity-processed');
            $('#edit-field-lsa-milestone-year-und').after('<div id="select-message"><p><em>In order to be eligible for a service pin, employees must be celebrating a current milestone in 2021. If you have questions about your eligibility, please contact your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">recognition contact</a>.</em></p></div>');
          }
          $('#edit-field-lsa-other-milestone-years').hide();
          $('#edit-field-lsa-other-milestone-years-und-1').prop('checked', false);
          $('#edit-field-lsa-other-milestone-years').hide();
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').prop('checked', false); //checked
          $('#edit-field-lsa-previous-service-miles').slideUp('slow');
        }

        //$('#edit-field-lsa-other-milestone-years').slideDown('slow');
        // We can only allow one box to be checked if they have chosen
        // Make sure our labels are set correctly
        if($('#edit-field-lsa-previous-service-miles-und').not('atwork-activity-processed')){
          $('#edit-field-lsa-previous-service-miles-und').addClass('atwork-activity-processed');
          //$('#edit-field-lsa-previous-service-miles-und input.form-checkbox').prop('checked', false);
          // Allow them to choose one pin:
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').on('change', function() {
            $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').not(this).prop('checked', false);
          });
        }

      break;
      //multiple retro pins allowed
      case ministry === '2' :   // Ministry of Advanced Education, Skills & Training
      case ministry === '5' :   // Ministry of Attorney General
      case ministry === '12' :  // BC Public Service Agency
      case ministry === '17' :  // Ministry of Children & Family Development
      case ministry === '18' :  // Ministry of Citizens' Services
      case ministry === '23' :  // Destination BC Corp
      case ministry === '24' :  // Ministry of Education
      case ministry === '25' :  // Elections BC
      case ministry === '29' :  // Ministry of Energy and Mines and Low Carbon Innovations
      case ministry === '30' :  // Ministry of Environment & Climate Change Strategy
      case ministry === '32' :  // Environmental Assessment Office
      case ministry === '34' :  // Ministry of Finance
      case ministry === '39' :  // Ministry of Forests, Lands, Natural Resource Operations & Rural Development
      case ministry === '40' :  // Government Communications & Public Engagement
      case ministry === '42' :  // Ministry of Health
      case ministry === '46' :  // Ministry of Indigenous Relations & Reconciliation
      case ministry === '48' :  // Intergovernmental Relations Secretariat
      case ministry === '55' :  // Ministry of Mental Health & Addictions
      case ministry === '60' :  // Office of the Information and Privacy Commissioner
      case ministry === '62' :  // Office of the Ombudsperson
      case ministry === '63' :  // Office of the Police Complaints Commissioner
      case ministry === '70' :  // Public Guardian and Trustee
      case ministry === '71' :  // Ministry of Public Safety and Solicitor General and Emergency BC
      case ministry === '81' :  // Ministry of Transportation & Infrastructure
      case ministry === '11' :  // BC Pension Corporation
      case ministry === '21' :  // Community Living BC
      case ministry === '61' : // Office of the Merit Commissioner
      case ministry === '76' : // Ministry of Social Development and Poverty Reduction

        // If we have previous set handlers on this - lets remove them.
        if($('#edit-field-lsa-previous-service-miles-und').hasClass('atwork-activity-processed')){

          // Remove class
          $('#edit-field-lsa-previous-service-miles-und').removeClass('atwork-activity-processed');
          // unbind any restrictions we previously had set.
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').unbind();
        }
        if($('#edit-field-lsa-milestone-year-und').hasClass('atwork-activity-processed')){
          // If we have a notice we don't need, detach it, and be ready to re-apply as necessary
          $('#select-message').detach();
          $('#edit-field-lsa-milestone-year-und').removeClass('atwork-activity-processed');
        }
        // Show choices so users can choose
        $('#edit-field-lsa-other-milestone-years').slideDown('slow');
      break;

      //If this is one of their award years then they can choose multiple extras: 20
      // Turn off for now
      case ministry === '99': //Community Living BC EDIT: We are using 99 here so that we don't  use this.
        // Check if this had other restrictions previously
        if($('#edit-field-lsa-previous-service-miles-und').hasClass('atwork-activity-processed')){
          $('#edit-field-lsa-previous-service-miles-und').removeClass('atwork-activity-processed');
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').unbind();
        }
        if($('#edit-field-lsa-milestone-year-und').hasClass('atwork-activity-processed')){
          // If we have a notice we don't need, detach it, and be ready to re-apply as necessary
          $('#select-message').detach();
          $('#edit-field-lsa-milestone-year-und').removeClass('atwork-activity-processed');
        }
        // Check if they are celebrating this year
        if($('#edit-field-lsa-milestone-year-und-1').is(':checked')){
          // If so, then they can choose prev years.
          $('#edit-field-lsa-other-milestone-years').slideDown('slow');
        } else {
          // Add note
          if($('#edit-field-lsa-milestone-year-und').hasClass('atwork-activity-processed')){
            // We are fine, nothing to do
          } else {
            $('#edit-field-lsa-milestone-year-und').addClass('atwork-activity-processed');
            $('#edit-field-lsa-milestone-year-und').after('<div id="select-message"><p><em>In order to be eligible for a service pin, employees must be celebrating a current milestone in 2021. If you have questions about your eligibility, please contact your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">recognition contact</a>.</em></p></div>');
          }
          $('#edit-field-lsa-other-milestone-years').hide();
          $('#edit-field-lsa-other-milestone-years-und-1').prop('checked', false);
          $('#edit-field-lsa-other-milestone-years').hide();
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').prop('checked', false);
          $('#edit-field-lsa-previous-service-miles').slideUp('slow');
        }
        break;

      // Any other number is not allowed to have retroactive
      default:
        if($('#edit-field-lsa-milestone-year-und').hasClass('atwork-activity-processed')){
          // We are fine, nothing to do
        } else {
          $('#edit-field-lsa-milestone-year-und').addClass('atwork-activity-processed');
          $('#edit-field-lsa-milestone-year-und').after('<div id="select-message"><p><em>In order to be eligible for a service pin, employees must be celebrating a current milestone in 2021. If you have questions about your eligibility, please contact your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">recognition contact</a>.</em></p></div>');
        }
        $('#edit-field-lsa-other-milestone-years').hide();
        $('#edit-field-lsa-previous-service-miles').hide();
        // Don't want to pass old values
        $('#edit-field-lsa-previous-service-miles input.form-checkbox').prop('checked', false); //checked
      break;
    }

    // Show fields or user
    $('.group-recipient-details').slideDown('slow');
    // Show field for current year status
    $('#edit-field-lsa-milestone-year').slideDown('slow');

    let applicationSubmitter = $('#edit-field-lsa-registerer-und option:selected').val();
    const specialCases = [
      '21', //Community Living BC
      '29', //Ministry of Energy, Mines & Petroleum Resources
      '32', //Environmental Assessment Office
      '46', //Ministry of Indigenous Relations & Reconciliation
      '55', //Ministry of Mental Health & Addictions
      '60', //Office of the Information and Privacy Commissioner
      '62', //Office of the Ombudsperson
      '70', //Public Guardian and Trustee
      '81', //Ministry of Transportation & Infrastructure
      '11', //BC Pension Corporation
      '25', //Elections BC
      '61', //Office of the Merit Commissioner
      '63', // Office of Police Complaint Commissioner
      '23', // Destination BC Corp
      '48', // Intergovernmental Relations Secretariat
      ];
    // Application by user
    if(applicationSubmitter === '1'){
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), specialCases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html('<p style="color:red;"><em>Service Pin(s) will be sent directly to your ministry/organization, for presentation during Public Service Week - June 15-19, 2021</em></p>');
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();

      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() !== '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html('<p style="color:red;"><em>Service pins will be sent to the employee&#39s supervisor for presentation during Public Service Week - June 15-19, 2021</em></p>');
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').show();
      }
      // Application by sup
    } else if(applicationSubmitter === 2){
      // depending on the situation, show or change the description field
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), specialCases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html('<p style="color:red;"><em>Service pin(s) will be sent directly to your ministry/organization, for presentation to the employee during Public Service Week - June 15-19, 2021.</em></p>');
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() !== '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html('<p style="color:red;"><em>Service pins will be sent to the employee&#39s supervisor for presentation during Public Service Week - June 15-19, 2021</em></p>');
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }
      // Application by min contact
    }  else if(applicationSubmitter === 3){
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), specialCases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html('<p style="color:red;"><em>Service pin(s) will be sent directly to your ministry/organization, for presentation to the employee during Public Service Week - June 15-19, 2021.</em></p>');
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() !== '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html('<p style="color:red;"><em>Service pins will be sent to the employee&#39s supervisor for presentation during Public Service Week - June 15-19, 2021.</em></p>');
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }

    }
    // Show fields for supervisors
    $('.collapsible.required-fields.group-supervisor-details.field-group-fieldset.form-wrapper.collapse-processed').slideDown('slow');
    $('#edit-field-lsa-pin-terms').slideDown('slow');
    $('#edit-field-lsa-pin-sup-location').slideDown('slow');
    $('#lsa-pin-terms').slideDown('slow');
    // Updates to instructions that don't go well in Drupal itself
    if($('#edit-field-lsa-office-address-und-0-value').hasClass('atwork-activity-processed')){
      // We are fine, nothing to do
    } else {
      $('#edit-field-lsa-office-address-und-0-value').addClass('atwork-activity-processed');
      //$('#edit-field-lsa-office-address-und-0-value').after('<div id="po-message" align="center"><em>For Victoria locations, please use the P.O. Box address</em></div>');
      $('#term-red').css('color', 'red');
    }
    return false;
  }
  /**
   * Function to manage pin year checkboxes for all ministries that can choose retros
   */
  function setUpPage() {
    // We want to turn off submit button initially, until we are sure we have some type of milestone.
    //$('#edit-submit').prop("disabled", "disabled");
    if($('#edit-field-lsa-registerer-und').val() === '_none'){
      // Hide top fields that user should not have access to
      $('#edit-field-lsa-pin-service-milestone').hide();
      $('#edit-field-lsa-pin-ministry-org').hide();
      $('#edit-field-lsa-milestone-year').hide();
      $('#edit-field-lsa-other-milestone-years').hide();
      $('#edit-field-lsa-previous-service-miles').hide();
      // Hide other fields for now.
      $('.collapsible.required-fields.group-recipient-details.field-group-fieldset.form-wrapper.collapse-processed').hide();
      $('.collapsible.required-fields.group-supervisor-details.field-group-fieldset.form-wrapper.collapse-processed').hide();
      $('.collapsible.required-fields.group-delivery-details.field-group-fieldset.form-wrapper.collapse-processed').hide();
      $('#edit-field-lsa-pin-terms').hide();
      $('#edit-field-lsa-pin-sup-location').hide();
      $('#lsa-pin-terms').hide();
      $('#sup-div.required-fields.form-wrapper').hide();
      // don't want to show the title for terms field.
      $('#edit-field-lsa-pin-terms').find('.option').html('<span class="form-required" title="This field is required.">*</span>');
      //$('#edit-field-lsa-pin-terms label:first-child').hide();
      $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
      $('#field-lsa-ministry-rep-email-add-more-wrapper').hide();
    } else {
      if($('#edit-field-lsa-milestone-year-und-0').is(':checked')){
        $('#edit-field-lsa-pin-service-milestone').hide();
      }
      if($('#edit-field-lsa-other-milestone-years-und-0').is(':checked')){
        $('#edit-field-lsa-previous-service-miles').hide();
      }
      setMinistryOptions($('#edit-field-lsa-pin-ministry-org-und option:selected').val());
    }
    if($('#edit-field-lsa-registerer-und').val() !== 3){
      $('#edit-field-lsa-ministry-rep-email-und-0-value').hide();
    }
    // We always want the province field to be none editable
    if(!$('#edit-field-province-und-0-value').hasClass('no-edit-prov')){
      $('#edit-field-province-und-0-value').attr('readonly', true)
        .addClass('no-edit-prov')
        .css('background-color' , '#DEDEDE');
    }
    // We want to move nudge supervisor field and also make the instructions for Victoria red
    if(!($('.group-service-pin-sup').hasClass('updated-for-page'))){
      $('.group-service-pin-sup').addClass('updated-for-page').css({'border':'1px solid black', 'margin':'15px 10px 10px 0px', 'padding':'5px'});
      $('.red-font').css({'color':'red', 'position':'relative', 'left':'5px'});
    }
  }
  function validateForm(){
    // May be easier to attach this as a standard php drupal form validate.
    let valid = false;
    // If we have a extra milestones - one must be checked:
    if($('#edit-field-lsa-previous-service-miles').hasClass('atwork-activity-processed') && $('#edit-field-lsa-previous-service-miles input.form-checkbox:checkbox:checked').length > 0){
        valid = true;
    }
  }

  function checkLabels(choice){

    if(choice === 1){
      // This is a user, so check if we need to change anything back. If not leave it.
      $('.form-item-field-lsa-milestone-year-und label:first-child').html('Are you celebrating a current service milestone in 2021? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-ministry-org-und label:first-child').html('What ministry/organization are you with? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-sup-location-und label:first-child').html('Does your supervisor work in a different office location than you? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item-field-lsa-other-milestone-years-und label:first-child').html('Do you wish to request any service pin(s) retroactively? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-checkboxes.form-item-field-lsa-previous-service-miles-und label:first-child').html('Please select the retroactive milestone pin(s) you would like to order <span class="form-required" title="This field is required.">*</span>');
      $('.form-item-field-lsa-pin-terms-und').find($('.description')).html('I declare, to the best of my knowledge and consistent with the <a href="https://gww.gov.bc.ca/career/service-pins-eligibility" target="_blank">service pin recognition eligibility guidelines</a> (which I have reviewed) that as of December 31, 2021, I will have reached and/or surpassed a milestone year (5, 10, 15, 20, 25, 30, 35, 40, 45, 50 years) and am therefore eligible to receive a service pin. By providing my contact information, I am allowing the BC Public Service Agency to use this information for the planning and delivery of the corporate pin program.');
    } else {
      // Change this if user is applying on behalf of an employee
      $('.form-item-field-lsa-milestone-year-und label:first-child').html('Is the employee celebrating a current service milestone in 2021? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-ministry-org-und label:first-child').html('What ministry/organization is the employee with? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-sup-location-und label:first-child').html('Does the employee’s supervisor work in a different office location than the employee? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item-field-lsa-other-milestone-years-und label:first-child').html('Do you wish to request any service pin(s) for the employee retroactively? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-checkboxes.form-item-field-lsa-previous-service-miles-und label:first-child').html('Please select the retroactive milestone pin(s) you would like to order for the employee <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-checkbox.form-item-field-lsa-pin-terms-und').find($('.description')).html('I declare, to the best of my knowledge and consistent with the <a href="https://gww.gov.bc.ca/career/service-pins-eligibility" target="_blank">service pin recognition eligibility guidelines</a> (which I have reviewed) that as of December 31, 2021, the above noted employee will have reached and/or surpassed a milestone year (5, 10, 15, 20, 25, 30, 35, 40, 45, 50 years) and is therefore eligible to receive a service pin. By providing the employee\'s contact information, I am allowing the BC Public Service Agency to use this information for the planning and delivery of the corporate pin program.');

    }
  }

  /**
   *  Function that checks if ministry can have more than one pin
   *  @params ministry [int]
   *     Variable holding ministry id. Ministry id is set in the Drupal form itself.
   **/
  function checkMinistry(ministry){
    let $ministryMultiple = false;
    switch(true){
      // Multiple retro's
      case ministry === '2' :   // Ministry of Advanced Education, Skills & Training
      case ministry === '5' :   // Ministry of Attorney General
      case ministry === '12' :  // BC Public Service Agency
      case ministry === '17' :  // Ministry of Children & Family Development
      case ministry === '18' :  // Ministry of Citizens' Services
      case ministry === '23' :  // Destination BC Corp
      case ministry === '24' :  // Ministry of Education
      case ministry === '25' :  // Elections BC
      case ministry === '29' :  // Ministry of Energy and Mines and Low Carbon Innovations
      case ministry === '30' :  // Ministry of Environment & Climate Change Strategy
      case ministry === '32' :  // Environmental Assessment Office
      case ministry === '34' :  // Ministry of Finance
      case ministry === '39' :  // Ministry of Forests, Lands, Natural Resource Operations & Rural Development
      case ministry === '40' :  // Government Communications & Public Engagement
      case ministry === '42' :  // Ministry of Health
      case ministry === '46' :  // Ministry of Indigenous Relations & Reconciliation
      case ministry === '48' :  // Intergovernmental Relations Secretariat
      case ministry === '55' :  // Ministry of Mental Health & Addictions
      case ministry === '60' :  // Office of the Information and Privacy Commissioner
      case ministry === '62' :  // Office of the Ombudsperson
      case ministry === '63' :  // Office of the Police Complaints Commissioner
      case ministry === '70' :  // Public Guardian and Trustee
      case ministry === '71' :  // Ministry of Public Safety and Solicitor General and Emergency BC
      case ministry === '81' :  // Ministry of Transportation & Infrastructure
      case ministry === '11' :  // BC Pension Corporation
      case ministry === '21' :  // Community Living BC
      case ministry === '61' : // Office of the Merit Commissioner
      case ministry === '76' : // Ministry of Social Development and Poverty Reduction
      // Single retro.
      case ministry === '4': // Ministry of Agriculture, Food and Fisheries
      case ministry === '3': // Agricultural Land Commission
      case ministry === '50' : //Ministry of Jobs, Economic Recovery and Innovation
      case ministry === '57' : //Ministry of Municipal Affairs
      case ministry === '79' : //Ministry of Tourism, Arts, Culture, and Sport

        $ministryMultiple = true;
        break;
    }
    return $ministryMultiple;
  }

  /**
   * Helper function that parses returned DB data depending on the users roll, and kickstarts the relevant form
   * @param  {array} response [Holds an array of user, supervisor fields for auto-pop, the response.choice key holds the type of submission this will be]
   */
  let feedDetails = function(response){
    // Ministries are special cases that will send all pins to ministry contact rather than supervisor, and require their own text. NOTE: If .inArray is not working, make sure keys do not have spaces in that field (i.e. 11|ministry not 11 |ministry)
    const specialCases = [
      '21', //Community Living BC
      '29', //Ministry of Energy, Mines & Petroleum Resources
      '32', //Environmental Assessment Office
      '46', //Ministry of Indigenous Relations & Reconciliation
      '55', //Ministry of Mental Health & Addictions
      '60', //Office of the Information and Privacy Commissioner
      '62', //Office of the Ombudsperson
      '70', //Public Guardian and Trustee
      '81', //Ministry of Transportation & Infrastructure
      '11', //BC Pension Corporation
      '25', //Elections BC
      '61', //Office of the Merit Commissioner
      '63', // Office of Police Complaint Commisioner
      '23', // Destination BC Corps
      '48', // Intergovernmental Relations Secretariat
    ];

    checkLabels(response.choice);
    $('#sup-div.required-fields.form-wrapper').hide();

    // User is filling out their own application
    if(response.choice === 1){
      // Show field for ministry
      $('#edit-field-lsa-pin-ministry-org').slideDown('slow');
      $('#edit-field-lsa-ministry-rep-email-und-0-value').val('');
      $('#field-lsa-ministry-rep-email-add-more-wrapper').hide();


      // populate fields for user - we know they are filling this out for themselves.
      $('#edit-field-lsa-branch-department-und-0-value').val(response.branch[0].safe_value);
      $('#edit-field-lsa-pin-first-name-und-0-value').val(response.first_name[0].safe_value);
      $('#edit-field-lsa-pin-last-name-und-0-value').val(response.last_name[0].safe_value);
      $('#edit-field-lsa-pin-employee-number-und-0-value').val(response.employee_number[0].safe_value);
      $('#edit-field-lsa-email-und-0-email').val(response.email);
      $('#edit-field-lsa-home-phone-und-0-value').val(response.phone[0].safe_value);
      $('#edit-field-lsa-branch-und-0-value').val(response.work_group[0].safe_value);
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), specialCases) > -1 ){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() !== '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }

      // Supervisor filling out form
    } else if(response.choice === 2){
      // Show field for ministry
      $('#edit-field-lsa-pin-ministry-org').slideDown('slow');
      $('#edit-field-lsa-ministry-rep-email-und-0-value').val('');
      $('#field-lsa-ministry-rep-email-add-more-wrapper').hide();
      // Populated fields for supervisors
      $('#edit-field-lsa-supervisor-first-name-und-0-value').val(response.first_name[0].safe_value);
      $('#edit-field-lsa-supervisor-last-name-und-0-value').val(response.last_name[0].safe_value);
      $('#edit-field-lsa-supervisor-email-und-0-email').val(response.email);
      $('#edit-field-lsa-work-phone-und-0-value').val(response.phone_number[0].safe_value);

      // depending on the situation, show or change the description field
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), specialCases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();

      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() !== '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }

      // Ministry Rep if filling out form.
    } else if(response.choice === 3){

      // Show field for ministry
      $('#edit-field-lsa-pin-ministry-org').slideDown('slow');
      $('#field-lsa-ministry-rep-email-add-more-wrapper').show();
      $('#edit-field-lsa-ministry-rep-email-und-0-value').show();

      // depending on the situation, show or change the description field
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), specialCases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() !== '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }

    } else {
      // TODO - Reset to default?
    }
  };
  /**
   * Main()
   * **/
  Drupal.behaviors.atwork_lsa_pin = {
    attach: function(context, settings) {
      let type = '';
      setUpPage();
      // Only run if the link exists in the current page load or fragment refresh.
      $('#edit-field-lsa-registerer-und:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('change', function(){
          let rebuiltForm = true;
          type = $('#edit-field-lsa-registerer-und').val();
          $.get('/atwork_lsa_pin_form/' + type, null, feedDetails);
          return false;
        });

      // AFter this choice is changed, we need to run a function that changes the nature of the form depending on ministry
      $('#edit-field-lsa-pin-ministry-org-und:not(.atwork-activity-processed)', context)
        .addClass('.atwork-activity-processed')
        .bind('change', function(){
          setMinistryOptions($('#edit-field-lsa-pin-ministry-org-und').val());
        });

      // Should we always see this? Maybe highlight them here if they are not filled out yet.
      $('#edit-field-lsa-milestone-year-und-1:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          if($('#edit-field-lsa-milestone-year-und-1').is(':checked')){
            $('#edit-field-lsa-pin-service-milestone').slideDown('slow');
            // Double Check our options here (Mainly for MTICS)
            setMinistryOptions($('#edit-field-lsa-pin-ministry-org-und').val());
          }
        });

      // Click handler to clear fields if this option changes.
      $('#edit-field-lsa-milestone-year-und-0:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          //Checked "No" so lets clear the field and hide it again.
          if($('#edit-field-lsa-milestone-year-und-0').is(':checked')){
            $('#edit-field-lsa-pin-service-milestone').slideUp('slow');
            $('#edit-field-lsa-pin-service-milestone-und').val('_none');
            setMinistryOptions($('#edit-field-lsa-pin-ministry-org-und').val());
          }
        });

      // Try to stop doubling years
      $('#edit-field-lsa-pin-service-milestone-und:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('change', function(){
          // Check ministry, only continue if they area allowed multiple pins
          let ministryMultiple = checkMinistry($('#edit-field-lsa-pin-ministry-org-und option:selected').val());
          // Check which value we have assigned here
          if(ministryMultiple === true) {
            // TODO: Refactor this to run in a loop incrementing numbers by 5.
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '5') {
              $('#edit-field-lsa-previous-service-miles-und-5').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-5').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-5').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-5').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '10') {
              $('#edit-field-lsa-previous-service-miles-und-10').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-10').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-10').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-10').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '15') {
              $('#edit-field-lsa-previous-service-miles-und-15').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-15').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-15').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-15').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '20') {
              $('#edit-field-lsa-previous-service-miles-und-20').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-20').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-20').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-20').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '25') {
              $('#edit-field-lsa-previous-service-miles-und-25').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-25').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-25').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-25').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '30') {
              $('#edit-field-lsa-previous-service-miles-und-30').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-30').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-30').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-30').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '35') {
              $('#edit-field-lsa-previous-service-miles-und-35').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-35').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-35').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-35').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '40') {
              $('#edit-field-lsa-previous-service-miles-und-40').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-40').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-40').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-40').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '45') {
              $('#edit-field-lsa-previous-service-miles-und-45').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-45').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-45').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-45').show();
            }
            if($('#edit-field-lsa-pin-service-milestone-und option:selected').val() === '50') {
              $('#edit-field-lsa-previous-service-miles-und-50').attr('checked', false);
              $('#edit-field-lsa-previous-service-miles-und-50').on('click', false);
              $('.form-item-field-lsa-previous-service-miles-und-50').hide();
            } else {
              // Just in case we hid this previously
              $('.form-item-field-lsa-previous-service-miles-und-50').show();
            }
          }
        });

      $('#edit-field-lsa-other-milestone-years-und-1:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          $('#edit-field-lsa-previous-service-miles').slideDown('slow');
          // Hide annoying "required" flag on each option.
          $('.option').find('span').removeClass('form-required').hide();
        });

      $('#edit-field-lsa-other-milestone-years-und-0:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          $('#edit-field-lsa-previous-service-miles-und input.form-checkbox').prop('checked', false);
          $('#edit-field-lsa-previous-service-miles').slideUp('slow');
        });
    }
  };
})(jQuery);
