(function ($) {
  Drupal.behaviors.prem_awards_form = {
    attach: function (context, settings) {
      // Fixing case where user name returns blank and creates a 500 (employee news case)
      if((settings.atwork_prem_awards.user.length < 1) && uid == 0 ){
        settings.atwork_prem_awards.user = 'Employee News';
      }
      // Only run if the link exists in the current page load or fragment refresh.
      // TODO: Create a button or link with a specific ID in the ad space
      $('#prem-awards-form:not(.atwork-prem-awards-processed)', context)
        .addClass('atwork-prem-awards-processed')
        .bind('click', function (){
          $.get('/p-awards/registration/' + settings.atwork_prem_awards.user + '/' + settings.atwork_prem_awards.uid, null, checkForm);
          return false;
       });
    }
  };

  var checkForm = function (response) {
    var result = $.parseJSON(response);
    // Create a workable array of results
    // Print it all out in the dom
    printResults(result);
    // Now set click handlers for updating fields
    return false;
  };

  function printResults(items) {
    // Need to generate some HTML here and pop a model
    var user_name = items.applicant;
    var formString = '';

    formString = buildString(items);

    $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');
    // TODO: Put this in its own function, to make code a little cleaner.
    $('<div id="premiers-awards-form" class="prem-awards-form-wrapper">' +
        '<p>Hello ' + user_name + ', our records indicate that you have pre-registered for the following webcast(s). Please make any required changes and confirm the registration information below.</p>'  +
        '<form>' +
          formString + 
        
        '</form>' +
      '</div>').appendTo('#modal-pop');
    
      // TODO: We need to add another hidden button, may want all of this in its own function as well.
    $('.prem-award-input').hide();
    
    // Now set up the dialog box    
    setDialog();

    // TODO: Make this into an actual function
    $(".show-input-field").click(function (){
      // We need to account for the sid here - so only show fields within the specific fieldset.
      var currentSid = $(this).attr("sid");
      
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-input').show();
      $('.fieldset-prem-award-class-' + currentSid + ' .cancel-show-input-field').show();
      $('.fieldset-prem-award-class-' + currentSid + ' save-form-field').show();
      $(this).hide();
    });

    $(".cancel-show-input-field").click(function (){
      // We need to account for the sid here - so only show fields within the specific fieldset
      var currentSID = $(this)attr("sid");
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-input').hide();
      $('.fieldset-prem-award-class-' + currentSid + ' .show-input-field').show();
      $('.fieldset-prem-award-class-' + currentSid + ' save-form-field').hide();      
      $(this).hide();
      
    });

    form = dialog.find("form").on("submit", function(event) {
      event.preventDefault();
      redirectSubmit();
    });
    // End
    return;
  }

  // This function submits results to php and then redirects
  function redirectSubmit(){
    // TODO: At this point we have already saved any changes via AJAX, so we can just redirect.
    window.location.replace("/user/twerdal");
  }

  // Set the dialogue box
  function setDialog(){
    dialog = $('#modal-pop').dialog({
      autoOpen: true,
      modal: true,
      opacity: 1,
      draggable: true,
      show: { effect: "blind", duration: 800 },
      background: '#FFFFFF',
      buttons: {
        "Continue to awards show": redirectSubmit,
        Cancel: function(){
          dialog.dialog("close");
        }
      },
      close: function () {
        form[0].reset();
      }
    });
    return;
  }

  /**
   * helper function that is used to parse out information from the array we pulled from drupal
   * @param {array} items - array of form fields and stored answers
   * @return {string} formString - a string containing markup to add to modal block
   */
  function buildString(items) {
    var formString = '';
    $.each(items, function (index, value) {
      if (index == 'applicant'){
        // skipping this one
        return;
      } else {
        // Embed the sid in the fieldset to keep information wrapped in the submission id.
        formString += '<fieldset sid="' + index + '" class="fieldset-prem-award-class-' + index + '">';
          // Webcast bundle
          // Using the label to show the current information that is entered. If this changes we should reflect that change here
          formString += '<label for="webcast-' + index + '">Webcast: ' + value.webcast + '</label>';
          // All input fields should be hidden on initial form launch
          formString += '<input type="text" name="webcast-' + index + '" value="' + value.webcast + '" class="prem-award-input">';
          // Number attending bundle
          formString += '<label for="attending-' + index + '">Number of Attendies: ' + value.numberAttending + '</label>';
          formString += '<input type="text" name="attending-' + index + '" value="' + value.numberAttending + '" class="prem-award-input">';
          // Name bundle
          formString += '<label for="name-' + index + '">Name: ' + value.name + '</label>';
          formString += '<input type="text" name="name-' + index + '" value="' + value.name + '" class="prem-award-input">';
          // Ministry bundle
          formString += '<label for="ministry-' + index + '">Ministry: ' + value.ministry + '</label>';
          formString += '<input type="text" name="ministry-' + index + '" value="' + value.ministry + '" class="prem-award-input">';
          // City bundle
          formString += '<label for="city-' + index + '">City: ' + value.city + '</label>';
          formString += '<input type="text" name="city-' + index + '" value="' + value.city + '" class="prem-award-input">';
          // The field edit and confirm button should be the only button available initially.
          formString += '<input type="button" class="show-input-field" sid="' + index + '" value="Edit">';
          // Cancel button in case they don't want to edit afterall
          formString += '<input type="button" class="cancel-show-input-field" sid="' + index + '" value="Cancel">';
          // Holder button to fire a function to post changes. This is hidden initially
          formString += '<input type="button" class="save-form-field" id="save-form-field-' + index + '" value="save">';
        formString += '</fieldset>';
      }
    });
    return formString;
  }
})(jQuery);
