(function ($) {
  Drupal.behaviors.atwork_lsa_pin = {
    attach: function(context, settings) {
      var type = "";
      setUpPage();
      // Only run if the link exists in the current page load or fragment refresh.
      $('#edit-field-lsa-registerer-und:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('change', function(){
          rebuiltForm = true;
          type = $('#edit-field-lsa-registerer-und').val();
          $.get('/atwork_lsa_pin_form/' + type, null, feedDetails);
          return false;
        });

      // AFter this choice is changed, we need to run a function that changes the nature of the form depending on ministry
      $('#edit-field-lsa-pin-ministry-org-und:not(.atwork-activity-processed)', context)
        .addClass('.atwork-activity-processed')
        .bind('change', function(){
          setMinistryOptions($('#edit-field-lsa-pin-ministry-org-und').val());
          return;
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
            $('#edit-field-lsa-pin-service-milestone-und').val("_none");
            setMinistryOptions($('#edit-field-lsa-pin-ministry-org-und').val());
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
  /**
   * Helper function that parses returned DB data depending on the users roll, and kickstarts the relevant form
   * @param  {array} response [Holds an array of user, supervisor fields for auto-pop, the response.choice key holds the type of submission this will be]
   */
  var feedDetails = function(response){
    // Ministries are special cases and require their own text. NOTE: If .inArray is not working, make sure keys do not have spaces in that field (i.e. 11|ministry not 11 |ministry)
    special_cases = [
      "6",  //Ministry of Education
      "12", //Ministry of Indigenous Relations and Reconciliation
      "15", //Ministry of Mental Health and Addictions
      "20", //Ministry of Transportation and Infrastructure
      "41", //Environmental Appeal Board
      "42", //Environmental Assessment Office
      "52", //Intergovernmental Relations Secretariat
      "60", //Office of the Information and Privacy Commissioner
      "61", //Office of the Merit Commissioner
      "62", //Office of the Ombudsperson
      "63", //Office of the Police Complaint Commissioner
      ]; 

    checkLabels(response.choice);
    $('#sup-div.required-fields.form-wrapper').hide();

    // User is filling out their own application
    if(response.choice == 1){
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
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases) > -1 ){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() != '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }

    // Supervisor filling out form
    } else if(response.choice == 2){
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
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();

      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() != '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }


    // Ministry Rep if filling out form.
    } else if(response.choice == 3){

      // Show field for ministry
      $('#edit-field-lsa-pin-ministry-org').slideDown('slow');
      $('#field-lsa-ministry-rep-email-add-more-wrapper').show();
      $('#edit-field-lsa-ministry-rep-email-und-0-value').show();

          // depending on the situation, show or change the description field
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() != '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }

    } else {
      // todo - Reset to default?
    }
    return;
  };

  function setUpPage() {
    if($('#edit-field-lsa-registerer-und').val() == '_none'){
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
      if($('#edit-field-lsa-milestone-year-und-0').is(":checked")){
        $('#edit-field-lsa-pin-service-milestone').hide();
      }
      if($('#edit-field-lsa-other-milestone-years-und-0').is(':checked')){
        $('#edit-field-lsa-previous-service-miles').hide();
      }
      setMinistryOptions($("#edit-field-lsa-pin-ministry-org-und option:selected").val());
    }
    if($('#edit-field-lsa-registerer-und').val() != 3){
      $('#edit-field-lsa-ministry-rep-email-und-0-value').hide();
    }
  }

  /**
   * Function that sets form to accept a ministries choices for retroactive awards.
   */

  function setMinistryOptions(ministry){
    console.log(ministry);
    switch(true){
      //Only One retro pin allowed 
      case ministry == 18: //Ministry of Social Development and Poverty Reduction
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
      //multiple retro pins allowed
      case ministry == 1 : //Ministry of Advanced Education, Skills and Training
      case ministry == 2 : //Ministry of Agriculture
      case ministry == 3 : //Ministry of Attorney General
      case ministry == 4 : //Ministry of Children and Family Development
      case ministry == 5 : //Ministry of Citizens' Services
      case ministry == 8 : //Ministry of Environment and Climate Change Strategy
      case ministry == 9 : //Ministry of Finance
      case ministry == 10: // Ministry of Forests, Lands, Natural Resource Operations and Rural Development
      case ministry == 11: // Ministry of Health
      case ministry == 12: // Ministry of Indigenous Relations and Reconciliation
      case ministry == 15: // Ministry of Mental Health and Addictions
      case ministry == 17: // Ministry of Public Safety and Solicitor General
      case ministry == 20: // Ministry of Transportation and Infrastructure
      case ministry == 27: // BC Public Service Agency
      case ministry == 41: // Environmental Appeal Board
      case ministry == 42: // Environmental Assessment Office
      case ministry == 52: // Intergovernmental Relations Secretariat
      case ministry == 60: // Office of the Information and Privacy Commissioner
      case ministry == 61: // Office of the Merit Commissioner
      case ministry == 62: // Office of the Ombudsperson
      case ministry == 63: // Office of the Police Complaint Commissioner
      case ministry == 68: // Public Guardian and Trustee

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
      
      case ministry == 6: // Ministry of Education
      case ministry == 7: // Ministry of Energy, Mines and Petroleum Resources
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
          $('#edit-field-lsa-milestone-year-und').before('<div id="select-message"><p>In order to be eligible for a service pin, employees must be celebrating a current milestone in 2018. If you have questions about your eligibility, please contact your <a href="/career/employee-appreciation/recognition-contacts" target="_blank">ministry recognition contact</a>. </p></div>');
        }
        $('#edit-field-lsa-other-milestone-years').hide();
        $('#edit-field-lsa-previous-service-miles').hide();
        // Don't want to pass old values
        $('#edit-field-lsa-previous-service-miles input.form-checkbox').prop('checked', false);
      break;
    }

    // Show fields or user
    $('.group-recipient-details').slideDown('slow');
    // Show field for current year status
    $('#edit-field-lsa-milestone-year').slideDown('slow');

    var applicationSubmitter = $('#edit-field-lsa-registerer-und option:selected').val();
    var special_cases = new Array();
    special_cases = [
      "6",  //Ministry of Education
      "12", //Ministry of Indigenous Relations and Reconciliation
      "15", //Ministry of Mental Health and Addictions
      "20", //Ministry of Transportation and Infrastructure
      "41", //Environmental Appeal Board
      "42", //Environmental Assessment Office
      "52", //Intergovernmental Relations Secretariat
      "60", //Office of the Information and Privacy Commissioner
      "61", //Office of the Merit Commissioner
      "62", //Office of the Ombudsperson
      "63", //Office of the Police Complaint Commissioner
      ]; 
    // Application by use
    console.log(applicationSubmitter);
    if(applicationSubmitter == 1){
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html("<em>Your pin(s) will be sent directly to your ministry/organization, for presentation to you during Public Service Week (June 12-16).</em>");
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();

      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() != '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html("<em>Service pins will be sent to the employee's supervisor for presentation during Public Service Week - June 11-15, 2018.</em>");
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').show();
      }
      // Application by sup
    } else if(applicationSubmitter == 2){
      // depending on the situation, show or change the description field
      console.log($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases));
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html("<em>The pin(s) will be sent directly to your ministry/organization, for presentation to the employee during Public Service Week (June 12-16).</em>");
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() != '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html("<em>Service pins will be sent to the employee's supervisor for presentation during Public Service Week - June 11-15, 2018.</em>");
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').show();
      } else {
        $('#edit-field-lsa-pin-ministry-org').find('.description').hide();
        $('#sup-div.required-fields.form-wrapper').hide();
      }
      // Application by min contact
    }  else if(applicationSubmitter == 3){
      console.log(special_cases);
      console.log($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases));
      console.log($('#edit-field-lsa-pin-ministry-org-und option:selected').val());
      if($.inArray($('#edit-field-lsa-pin-ministry-org-und option:selected').val(), special_cases) > -1){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html("<em>The pin(s) will be sent directly to your ministry/organization, for presentation to the employee during Public Service Week (June 12-16).</em>");
        $('#edit-field-lsa-pin-ministry-org').find('.description').show();
        $('#sup-div.required-fields.form-wrapper').hide();
      } else if ($('#edit-field-lsa-pin-ministry-org-und option:selected').val() != '_none'){
        $('#edit-field-lsa-pin-ministry-org').find('.description').html("<em>Service pins will be sent to the employee's supervisor for presentation during Public Service Week - June 11-15, 2018.</em>");
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
    return false;
  }

  function validateForm(){
    // May be easier to attach this as a standard php drupal form validate.
    var valid = false;
    // If we have a extra milestones - one must be checked:
    if($('#edit-field-lsa-previous-service-miles').hasClass('atwork-activity-processed')){
      if($('#edit-field-lsa-previous-service-miles input.form-checkbox:checkbox:checked').length > 0){
        valid = true;
      } else {
        valid = false;
      }
    }
  }

  function checkLabels(choice){

    if(choice == 1){
      // This is a user, so check if we need to change anything back. If not leave it.
      $('.form-item-field-lsa-milestone-year-und label:first-child').html('Are you celebrating a current service milestone in 2018? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-ministry-org-und label:first-child').html('What ministry/organization are you with? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-sup-location-und label:first-child').html('Does your supervisor work in a different office location than you? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item-field-lsa-other-milestone-years-und label:first-child').html('Do you wish to request any service pin(s) retroactively? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-checkboxes.form-item-field-lsa-previous-service-miles-und label:first-child').html('Please select the retroactive milestone pin(s) you would like to order <span class="form-required" title="This field is required.">*</span>');
      $('.form-item-field-lsa-pin-terms-und').find($('.description')).html('I declare, to the best of my knowledge and consistent with the <a href="https://gww.gov.bc.ca/career/service-pins-eligibility" target="_blank">Service Pin Recognition Eligibility Guidelines</a> (which I have reviewed) that as of December 31, 2018, I will have reached and/or surpassed a milestone year (5, 10, 15, 20, 25, 30, 35, 40, 45, 50 years) and am therefore eligible to receive a service pin. By providing my contact information, I am allowing the BC Public Service Agency to use this information for the planning and delivery of the corporate pin program.');
    } else {
      // Change this if user is applying on behalf of an employee
      $('.form-item-field-lsa-milestone-year-und label:first-child').html('Is the employee celebrating a current service milestone in 2018? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-ministry-org-und label:first-child').html('What ministry/organization is the employee with? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-select.form-item-field-lsa-pin-sup-location-und label:first-child').html('Does the employee’s supervisor work in a different office location than the employee? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item-field-lsa-other-milestone-years-und label:first-child').html('Do you wish to request any service pin(s) for the employee retroactively? <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-checkboxes.form-item-field-lsa-previous-service-miles-und label:first-child').html('Please select the retroactive milestone pin(s) you would like to order for the employee <span class="form-required" title="This field is required.">*</span>');
      $('.form-item.form-type-checkbox.form-item-field-lsa-pin-terms-und').find($('.description')).html('I declare, to the best of my knowledge and consistent with the <a href="https://gww.gov.bc.ca/career/service-pins-eligibility" target="_blank">Service Pin Recognition Eligibility Guidelines</a> (which I have reviewed) that as of December 31, 2018, the above noted employee will have reached and/or surpassed a milestone year (5, 10, 15, 20, 25, 30, 35, 40, 45, 50 years) and is therefore eligible to receive a service pin. By providing the employee\'s contact information, I am allowing the BC Public Service Agency to use this information for the planning and delivery of the corporate pin program.');

    }
  }
})(jQuery);
