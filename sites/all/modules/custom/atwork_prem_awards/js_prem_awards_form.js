(function ($) {
  Drupal.behaviors.prem_awards_form = {
    attach: function (context, settings) {
      // Fixing case where user name returns blank and creates a 500 (employee news case)
      uid = (settings.atwork_prem_awards.uid);
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
    var uid = items.uid;
    var count = Object.keys(items).length;
    // If we have at least one form:
    if(count >= 2){
      formString = buildString(items);
      
      $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');
      // TODO: Put this in its own function, to make code a little cleaner.
      $('<div id="premiers-awards-form" class="prem-awards-form-wrapper">' +
          '<p>Hello ' + user_name + ', our records indicate that you have pre-registered for the following webcast(s). Please make any required changes and confirm the registration information below.</p>'  +
          '<form>' +
            formString + 
          '<input type="button" class="add-new-form" id="add-new-form" value="Add new application">' +                      
          '</form>' + 
        '</div>').appendTo('#modal-pop');
      
        // TODO: We need to add another hidden button, may want all of this in its own function as well.
      $('.prem-award-input, .save-form-field, .cancel-show-input-field').hide();
    } else {
      $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');
      formString = newForm(items);
      $('<div id="premiers-awards-form" class="prem-awards-form-wrapper">' +
        '<p>Hello ' + user_name + ', our records indicate that you have not registered for any webcasts. Please create a registration by clicking the "add registration" button below.</p>'  +
        '<form>' +
        formString + 
        '<input type="button" class="add-new-form" id="add-new-form" value="Add new application">' +               
        '</form>' +
      '</div>').appendTo('#modal-pop');
    }
    // Now set up the dialog box    
    setDialog();

    // TODO: Make this into an actual function. 
    // Click handler for "edit" functionality
    $(".show-input-field").click(function (){
      // We need to account for the sid here - so only show fields within the specific fieldset.
      if($(this).attr("sid") != 'Null'){
        var currentSid = $(this).attr("sid");
      } else if (($(this).attr("id").length) > 0 ){
        var currentSid = $(this).attr("id");        
      } 
      
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-input').show();
      $('.fieldset-prem-award-class-' + currentSid + ' .cancel-show-input-field').show();
      $('.fieldset-prem-award-class-' + currentSid + ' .save-form-field').show();
      
      $(this).hide();
    });

    // Click handler for "cancel" functionality
    $(".cancel-show-input-field").click(function (){
      // We need to account for the sid here - so only show fields within the specific fieldset
      if($(this).attr("sid") != 'Null'){
        var currentSid = $(this).attr("sid");
      } else if (($(this).attr("id").length) > 0 ){
        var currentSid = $(this).attr("id");        
      }       
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-input').hide();
      $('.fieldset-prem-award-class-' + currentSid + ' .show-input-field').show();
      $('.fieldset-prem-award-class-' + currentSid + ' .save-form-field').hide();      
      $(this).hide();
    });

    // Click handler for save functionality
    $(".save-form-field").click(function (){
      // Get sid so we know which form we are saving
      if($(this).attr("sid") != 'Null'){
        var currentSid = $(this).attr("sid");
      } else if (($(this).attr("id").length) > 0 ){
        var currentSid = $(this).attr("id");
        var id = true;        
      }   
      var confirmation = saveUpdates(currentSid, uid, id);
    });

    // Click handler to add new form
    $(".add-new-form").click(function (){
      console.log('click');
      var blankForm = newForm();
      $('#add-new-form').before(blankForm);
      // TODO: A function that adds click handlers to the new form. This could be used above as well with a marker class, so we don't double down on it.
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
      if (index == 'applicant' || index == 'uid'){
        // skipping this one
        return;
      } else {
        // Embed the sid in the fieldset to keep information wrapped in the submission id.
        formString += '<fieldset sid="' + index + '" class="fieldset-prem-award-class-' + index + '">';
          // Webcast bundle
          // Using the label to show the current information that is entered. If this changes we should reflect that change here
          formString += '<label for="webcast-' + index + '">Webcast: ' + value.webcast + '</label>';
          // All input fields should be hidden on initial form launch
          // Use this to find default value
          var castValue = "default";
          if(value.webcast.indexOf('Island') > -1) {
            castValue = 'vancouverIsland';
          }
          if(value.webcast.indexOf('Lower') > -1) {
            castValue = 'lowerMainland';
          }
          if(value.webcast.indexOf('Interior') > -1) {
            castValue = 'interiorNorth';
          }
          formString += '<select name="webcast-' + index + '" value="' + castValue + '" class="prem-award-input">';
            // TODO: Get proper dates/times for this.  
            if(castValue == 'vancouverIsland'){
              formString += '<option value="vancouverIsland" selected="selected">Vancouver Island</option>';
            } else {
              formString += '<option value="vancouverIsland">Vancouver Island</option>';              
            }
            if(castValue =='lowerMainland'){
              formString += '<option value="lowerMainland" selected="selected">Lower Mainland</option>';
            } else {
              formString += '<option value="lowerMainland">Lower Mainland</option>';              
            }
            if(castValue == 'interiorNorth'){
              formString += '<option value="interiorNorth" selected="selected">Interior / North</option>';
            } else {
              formString += '<option value="interiorNorth">Interior / North</option>';              
            }
          formString += '</select>';
          // Number attending bundle
          formString += '<label for="attending-' + index + '">Number of Attendies: ' + value.numberAttending + '</label>';
          formString += '<input type="text" name="attending-' + index + '" value="' + value.numberAttending + '" class="prem-award-input prem-award-attending" required>';
          // Name bundle
          formString += '<label for="name-' + index + '">Name: ' + value.name + '</label>';
          formString += '<input type="text" name="name-' + index + '" value="' + value.name + '" class="prem-award-input prem-award-name" required>';
          // Ministry bundle
          formString += '<label for="ministry-' + index + '">Ministry: ' + value.ministry + '</label>';
          formString += '<input type="text" name="ministry-' + index + '" value="' + value.ministry + '" class="prem-award-input prem-award-ministry" required>';
          // City bundle
          formString += '<label for="city-' + index + '">City: ' + value.city + '</label>';
          formString += '<input type="text" name="city-' + index + '" value="' + value.city + '" class="prem-award-input prem-award-city" required>';
          // The field edit and confirm button should be the only button available initially.
          formString += '<input type="button" class="show-input-field" sid="' + index + '" value="Edit">';
          // Cancel button in case they don't want to edit afterall
          formString += '<input type="button" class="cancel-show-input-field" sid="' + index + '" value="Cancel">';
          // Holder button to fire a function to post changes. This is hidden initially
          formString += '<input type="button" class="save-form-field" sid="' + index + '" value="save">';
          
        formString += '</fieldset>';
      }
    });

    return formString;
  }

  function newForm(){
    var formString = '';
    var timeStamp = $.now();
    // Embed the sid in the fieldset to keep information wrapped in the submission id.
    formString += '<fieldset sid="null" class="fieldset-prem-award-class-' + timeStamp + '">';
      // Webcast bundle
      // Using the label to show the current information that is entered. If this changes we should reflect that change here
      formString += '<label for="webcast-' + timeStamp + '">Webcast: </label>';
      // All input fields should be hidden on initial form launch
      formString += '<select name="webcast-' + timeStamp + '" value="webCast" class="prem-award-input">';
        // TODO: Get proper dates/times for this.  
        formString += '<option value="vancouverIsland">Vancouver Island</option>';              
        formString += '<option value="lowerMainland">Lower Mainland</option>';              
        formString += '<option value="interiorNorth">Interior / North</option>';              
      formString += '</select>';
      // Number attending bundle
      formString += '<label for="attending-' + timeStamp + '">Number Attending: </label>';
      formString += '<input type="text" name="attending-' + timeStamp + '" value="0" class="prem-award-input prem-award-attending" required>';
      // Name bundle
      formString += '<label for="name-' + timeStamp + '">Name: </label>';
      formString += '<input type="text" name="name-' + timeStamp + '" value="" class="prem-award-input prem-award-name" required>';
      // Ministry bundle
      formString += '<label for="ministry-' + timeStamp + '">Ministry: </label>';
      formString += '<input type="text" name="ministry-' + timeStamp + '" value="" class="prem-award-input prem-award-ministry" required>';
      // City bundle
      formString += '<label for="city-' + timeStamp + '">City: </label>';
      formString += '<input type="text" name="city-' + timeStamp + '" value="" class="prem-award-input prem-award-city" required>';
      // The field edit and confirm button should be the only button available initially.
      formString += '<input type="button" class="show-input-field" sid="Null" id="'+ timeStamp + '" value="Edit">';
      // Cancel button in case they don't want to edit afterall
      formString += '<input type="button" class="cancel-show-input-field" sid="Null" id="'+ timeStamp + '" value="Cancel">';
      // Holder button to fire a function to post changes. This is hidden initially
      formString += '<input type="button" class="save-form-field" sid="Null" id="'+ timeStamp + '" value="save">';
    formString += '</fieldset>';
    return formString;
  }

  function saveUpdates (sid, uid, id){
    // TODO: something that builds array of changes and sends info to php
    // Required fields and expected order from PHP: $webcast, $number_of_attendees, $name, $ministry, $city, $sid
    var data = {};
    data['webcast'] = $('.fieldset-prem-award-class-' + sid + ' select.prem-award-input').val();
    data['attending'] = $('.fieldset-prem-award-class-' + sid + ' input.prem-award-input.prem-award-attending').val();
    data['name'] = $('.fieldset-prem-award-class-' + sid + ' input.prem-award-input.prem-award-name').val();    
    data['ministry'] = $('.fieldset-prem-award-class-' + sid + ' input.prem-award-input.prem-award-ministry').val();
    data['city'] = $('.fieldset-prem-award-class-' + sid + ' input.prem-award-input.prem-award-city').val();
    if(id == true){
      data['sid'] = null;
    } else {
      data['sid'] = sid;
    }
    data['uid'] = uid;
    console.log(data);
    $.ajax({
      type: 'POST',
      url: '/p-awards/submit',
      dataType: 'json',
      success: ajaxCompleted,
      data: data,
    });
    
    // Now, pass through our json objec
    //$.get('/p-awards/submit/' + jsonObj, null, submitForm);
    // TODO: something that checks if save goes through
    //var submitForm = function (response) {
    //  var result = $.parseJSON(response);
      // Create a workable array of results
      // Print it all out in the dom
    //  console.log(result);
      // Now set click handlers for updating fields
    //  return false;
    //};
    // TODO: If it goes through, change labels to reflect new values and give user a "saved" message - hiding inputs and buttons as needed
    // TODO: If it does not go through, give use an "Error" message asking them to submit again.
  }

  function ajaxCompleted (returnData) {
    console.log(returnData);
    console.log("returned");
    // Add some stuff to your DOM if this was successful - error and mark if it was not.
  }
})(jQuery);
