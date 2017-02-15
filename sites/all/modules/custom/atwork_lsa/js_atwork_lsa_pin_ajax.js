(function ($) {
  Drupal.behaviors.atwork_lsa_pin = {
    attach: function(context, settings) {
      console.log(settings);
      var type = "";
      setUpPage();
      // Only run if the link exists in the current page load or fragment refresh.
      $('#edit-field-lsa-registerer-und:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('change', function(){
          type = $('#edit-field-lsa-registerer-und').val();
          $.get('/atwork_lsa_pin_form/' + type, null, feedDetails);
          return false;
        });

      // AFter this choice is changed, we need to run a function that changes the nature of the form depending on ministry
      $('#edit-field-lsa-pin-ministry-org:not(.atwork-activity-processed)', context)
        .addClass('.atwork-activity-processed')
        .bind('change', function(){
          setMinistryOptions($('#edit-field-lsa-pin-ministry-org').val());
          return;
        });
      $('#edit-field-lsa-milestone-year-und-1:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          if($('#edit-field-lsa-milestone-year-und-1').is(':checked')){
            $('#edit-field-lsa-pin-service-milestone').slideDown('slow');
            $('#edit-field-lsa-pin-ministry-org').slideDown('slow');
          }
        });

      $('#edit-field-lsa-milestone-year-und-0:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          //Checked "No" so lets clear the field and hide it again.
          if($('#edit-field-lsa-milestone-year-und-0').is(':checked')){
            $('#edit-field-lsa-pin-service-milestone-und').val("_none");
            $('#edit-field-lsa-pin-service-milestone').slideUp('slow');
          }
        });
    }
  };
  /**
   * Helper function that parses returned DB data depending on the users roll, and kickstarts the relevant form
   * @param  {array} response [Holds an array of user, supervisor fields for auto-pop, the response.choice key holds the type of submission this will be]
   */
  var feedDetails = function(response){
    //var result = $.parseJSON(response);
    console.log(response);
    if(response.choice == 1){
      // Show fields
      $('.group-recipient-details').slideDown('slow');
      $('#edit-field-lsa-milestone-year').slideDown('slow');

      // populate fields
      $('#edit-field-lsa-branch-department-und-0-value').val(response.branch[0].safe_value);
      $('#edit-field-lsa-pin-first-name-und-0-value').val(response.first_name[0].safe_value);
      $('#edit-field-lsa-pin-last-name-und-0-value').val(response.last_name[0].safe_value);
      $('#edit-field-lsa-pin-employee-number-und-0-value').val(response.employee_number[0].safe_value);
      $('#edit-field-lsa-email-und-0-email').val(response.email);
    } else if(response.choice == 2){

    } else if(response.choice == 3){

    } else {

    }
    return;
  };

  function setUpPage() {
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
  }


  function setMinistryOptions(ministry){

  }
})(jQuery);
