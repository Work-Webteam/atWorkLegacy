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

      // TODO - Should we always see this? Maybe highlight them here if they are not filled out yet.
      $('#edit-field-lsa-milestone-year-und-1:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          if($('#edit-field-lsa-milestone-year-und-1').is(':checked')){
            $('#edit-field-lsa-pin-service-milestone').slideDown('slow');
            $('#edit-field-lsa-pin-ministry-org').slideDown('slow');
          }
        });

      // Click handler to clear fields if this option changes.
      $('#edit-field-lsa-milestone-year-und-0:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          //Checked "No" so lets clear the field and hide it again.
          if($('#edit-field-lsa-milestone-year-und-0').is(':checked')){
            $('#edit-field-lsa-pin-service-milestone-und').val("_none");
            $('#edit-field-lsa-pin-service-milestone').slideUp('slow');
          }
        });

      $('#edit-field-lsa-other-milestone-years:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('change', function(){
          $('#edit-field-lsa-previous-service-miles').show();
          // Hide annoying "required" flag on each option.
          $('.option').find('span').removeClass('form-required').hide();
        });
    }
  };
  /**
   * Helper function that parses returned DB data depending on the users roll, and kickstarts the relevant form
   * @param  {array} response [Holds an array of user, supervisor fields for auto-pop, the response.choice key holds the type of submission this will be]
   */
  var feedDetails = function(response){
     console.log(response);

    // User is filling out their own application
    if(response.choice == 1){
      // Show field for ministry
      $('#edit-field-lsa-pin-ministry-org').slideDown('slow');

      // Show fields or user
      $('.group-recipient-details').slideDown('slow');
      // Show field for current year status
      $('#edit-field-lsa-milestone-year').slideDown('slow');
      $('#edit-field-lsa-pin-service-milestone').slideDown('slow');

      // Show fields for supervisors
      $('.collapsible.required-fields.group-supervisor-details.field-group-fieldset.form-wrapper.collapse-processed').slideDown('slow');

      // populate fields for user - we know they are filling this out for themselves.
      $('#edit-field-lsa-branch-department-und-0-value').val(response.branch[0].safe_value);
      $('#edit-field-lsa-pin-first-name-und-0-value').val(response.first_name[0].safe_value);
      $('#edit-field-lsa-pin-last-name-und-0-value').val(response.last_name[0].safe_value);
      $('#edit-field-lsa-pin-employee-number-und-0-value').val(response.employee_number[0].safe_value);
      $('#edit-field-lsa-email-und-0-email').val(response.email);
      $('#edit-field-lsa-home-phone-und-0-value').val(response.phone[0].safe_value);
      $('#edit-field-lsa-branch-und-0-value').val(response.work_group[0].safe_value);
      $('.collapsible.required-fields.group-delivery-details.field-group-fieldset.form-wrapper.collapse-processed').slideDown('slow');
      $('#edit-field-lsa-pin-terms').slideDown('slow');
      $('#edit-field-lsa-pin-sup-location').slideDown('slow');
      $('#lsa-pin-terms').slideDown('slow');
    // Supervisor filling out form
    } else if(response.choice == 2){
      // Show fields or user
      $('.group-recipient-details').slideDown('slow');
      // Show field for current year status
      $('#edit-field-lsa-milestone-year').slideDown('slow');
      $('#edit-field-lsa-pin-service-milestone').slideDown('slow');
      // Show fields for supervisors
      $('.collapsible.required-fields.group-supervisor-details.field-group-fieldset.form-wrapper.collapse-processed').slideDown('slow');
      $('.collapsible.required-fields.group-delivery-details.field-group-fieldset.form-wrapper.collapse-processed').slideDown('slow');
      $('#edit-field-lsa-pin-terms').slideDown('slow');
      $('#edit-field-lsa-pin-sup-location').slideDown('slow');
      $('#lsa-pin-terms').slideDown('slow');


      // Populated fields for supervisors
      $('#edit-field-lsa-supervisor-first-name-und-0-value').val(response.first_name[0].safe_value);
      $('#edit-field-lsa-supervisor-last-name-und-0-value').val(response.last_name[0].safe_value);
      $('#edit-field-lsa-supervisor-email-und-0-email').val(response.email);
      $('#edit-field-lsa-work-phone-und-0-value').val(response.phone_number[0].safe_value);

    // Ministry Rep if filling out form.
    } else if(response.choice == 3){
      // Show whole form, and don't fill anything.
            // Show fields or user
      $('.group-recipient-details').slideDown('slow');
      // Show field for current year status
      $('#edit-field-lsa-milestone-year').slideDown('slow');
      $('#edit-field-lsa-pin-service-milestone').slideDown('slow');
      $('#edit-field-lsa-pin-terms').slideDown('slow');
      $('#edit-field-lsa-pin-sup-location').slideDown('slow');
      $('#lsa-pin-terms').slideDown('slow');
      // Show fields for supervisors
      $('.collapsible.required-fields.group-supervisor-details.field-group-fieldset.form-wrapper.collapse-processed').slideDown('slow');
    } else {
      // todo - Reset to default?
    }
    return;
  };

  function setUpPage() {
    console.log($('#edit-field-lsa-registerer-und').val());
    if($('#edit-field-lsa-registerer-und').val() == '_none'){
      // Hide top fields that user should not have access to
      $('#edit-field-lsa-pin-service-milestone').hide();
      $('#edit-field-lsa-pin-ministry-org').hide();
      $('#edit-field-lsa-milestone-year').hide();
      $('#edit-field-lsa-pin-service-milestone').hide();
      $('#edit-field-lsa-other-milestone-years').hide();
      $('#edit-field-lsa-previous-service-miles').hide();
      // Hide other fields for now.
      $('.collapsible.required-fields.group-recipient-details.field-group-fieldset.form-wrapper.collapse-processed').hide();
      $('.collapsible.required-fields.group-supervisor-details.field-group-fieldset.form-wrapper.collapse-processed').hide();
      $('.collapsible.required-fields.group-delivery-details.field-group-fieldset.form-wrapper.collapse-processed').hide();
      $('#edit-field-lsa-pin-terms').hide();
      $('#edit-field-lsa-pin-sup-location').hide();
      $('#lsa-pin-terms').hide();
    }
  }

  /**
   * Function that sets form to accept a ministries choices for retroactive awards.
   */

  function setMinistryOptions(ministry){
    switch(true){
      //Only One: 9, 19
      case ministry == (9 || 19):
        // We can only allow one box to be checked if they have chosen 9 or 19
        // Also change labels
        $('.form-item-field-lsa-other-milestone-years-und label:first-child').text("Do you wish to request a service pin retroactively?");
        $('.form-item-field-lsa-previous-service-miles-und label:first-child').text("Please select the retroactive milestone pin you would like to order");
        $('#edit-field-lsa-other-milestone-years').slideDown('slow');
        if($('#edit-field-lsa-previous-service-miles').not('atwork-activity-processed')){
          $('#edit-field-lsa-previous-service-miles').addClass('atwork-activity-processed');
          // Allow them to choose one pin:
          $('#edit-field-lsa-previous-service-miles input.form-checkbox').on('change', function() {
            $('#edit-field-lsa-previous-service-miles input.form-checkbox').not(this).prop('checked', false);
          });
        }
      break;
      //multiple: 1,2,3,5,7,8,11,12,15,16,17
      case ministry == (1 || 2 || 3 || 5 || 7 || 8 || 11 || 12 || 15 || 16 || 17):
        // If we have previous set handlers on this - lets remove them.
        if($('#edit-field-lsa-previous-service-miles').hasClass('atwork-activity-processed')){
          // Remove class
          $('#edit-field-lsa-previous-service-miles').removeClass('atwork-activity-processed');
          // unbind any restrictions we previously had set.
          $('#edit-field-lsa-previous-service-miles').unbind();
          // Reset labels
          $('.form-item-field-lsa-other-milestone-years-und label:first-child').text("Do you wish to request any service pin(s) retroactively?");
          $('.form-item-field-lsa-previous-service-miles-und label:first-child').text("Please select the retroactive milestone pin(s) you would like to order");
        }
        // Show choices so users can choose
        $('#edit-field-lsa-other-milestone-years').slideDown('slow');
      break;

      //If this is on of their award years then they can choose multiple extras: 20
      case ministry = 20:
        // Check if this had other restrictions previously
        if($('#edit-field-lsa-previous-service-miles').hasClass('atwork-activity-processed')){
          $('#edit-field-lsa-previous-service-miles').removeClass('atwork-activity-processed');
          // Reset labels
          $('.form-item-field-lsa-other-milestone-years-und label:first-child').text("Do you wish to request any service pin(s) retroactively?");
          $('.form-item-field-lsa-previous-service-miles-und label:first-child').text("Please select the retroactive milestone pin(s) you would like to order");
          $('#edit-field-lsa-previous-service-miles').unbind();
        }
        // Check if they are celebrating this year
        if($('#edit-field-lsa-milestone-year-und-1').val == 1){
          $('#edit-field-lsa-other-milestone-years').slideDown('slow');
        } else {
          $('#edit-field-lsa-other-milestone-years').hide();
          $('#edit-field-lsa-other-milestone-years-und-1').prop('checked', false);
          $('#edit-field-lsa-other-milestone-years-und-0').prop('checked', true);
        }
        break;
      // Any other number is not allowed to have retroactive
      default:
        $('#edit-field-lsa-previous-service-miles').hide();
        // Don't want to pass old values
        $('#edit-field-lsa-previous-service-miles input.form-checkbox').prop('checked', false);
      break;
    }

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
})(jQuery);
