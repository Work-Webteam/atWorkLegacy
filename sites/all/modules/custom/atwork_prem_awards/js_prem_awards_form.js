(function ($) {
  Drupal.behaviors.prem_awards_form = {
    attach: function (context, settings) {
      // Fixing case where user name returns blank and creates a 500 (employee news case)
      uid = (settings.atwork_prem_awards.uid);
      if((settings.atwork_prem_awards.user.length < 1) && uid == 0 ){
        settings.atwork_prem_awards.user = 'Employee News';
      }
      // Only run if the link exists in the current page load or fragment refresh.
      // Note: this module requires the activiation of a block, and that you create a button or link with a specific ID in the ad space
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

  /**
   * Main function that sets form/modal and click-handlers.
   * @param {array} items 
   */
  function printResults(items) {
    // Need to generate some HTML here and pop a model
    var user_name = items.applicant;
    var formString = '';
    var uid = items.uid;
    var count = Object.keys(items).length;
    // If we have at least one form:
    if(count >= 3){
      formString = buildString(items);
      
      $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');
      $('<div id="premiers-awards-form" class="prem-awards-form-wrapper">' +
          '<p>Hello ' + user_name + ', our records indicate that you have pre-registered for the following webcast(s). Please make any required changes and confirm the registration information below.</p>'  +
          '<form>' +
            formString + 
          '<input type="button" class="add-new-form" id="add-new-form" value="Add new application">' +                      
          '</form>' + 
        '</div>').appendTo('#modal-pop');
      
      $('.prem-award-input, .save-form-field, .cancel-show-input-field').hide();
    } else {
      $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');
      formString = newForm(items);
      $('<div id="premiers-awards-form" class="prem-awards-form-wrapper">' +
        '<p>Hello ' + user_name + ', our records indicate that you have not registered for any webcasts. Please create a registration and then click the "save" button below.</p>'  +
        '<form>' +
        formString + 
        '<input type="button" class="add-new-form" id="add-new-form" value="Add new application">' +               
        '</form>' +
      '</div>').appendTo('#modal-pop');
      $('#add-new-form').hide();
      $('.show-input-field').hide();
    }
    // Now set up the dialog box    
    setDialog();
    // Disbable the continue button until we have at least one submission
    if(count <= 2){
      $(".ui-dialog-buttonset :first(.ui-button.ui-widget.ui-corner-all)").prop("disabled", true);
    }
    // Set all existing click handlers
    setClickHandlers();
    // End
    return;
  }

  /**
   * Function that sets all click handlers, and makes sure we are not setting them twice. Passes off logic to seperate functions
   */
  function setClickHandlers(){
    // Click handler for "edit" functionality
    $('.show-input-field:not(.atwork-prem-awards-processed)')
      .addClass('atwork-prem-awards-processed')
      .bind('click', function (){
        editButtonClickHandler($(this));
      });

    // Click handler for "cancel" functionality
    $(".cancel-show-input-field:not(.atwork-prem-awards-processed)")
      .addClass('atwork-prem-awards-processed')
      .bind('click', function (){
        cancelButtonClickHandler($(this));
      });

    // Click handler for "cancel" functionality
    $(".save-form-field:not(.atwork-prem-awards-processed)")
      .addClass('atwork-prem-awards-processed')
      .bind('click', function (){
        saveButtonClickHandler($(this), uid);
      });

    // Click handler to add new form
    $(".add-new-form:not(.atwork-prem-awards-processed)")
    .addClass('atwork-prem-awards-processed')
    .bind('click', function (){
      var blankForm = newForm();
      $('#add-new-form').before(blankForm);
      setClickHandlers();
    });
    // Submit handler - this simply redirects form to video
    form = dialog.find("form").on("submit", function(event) {
      event.preventDefault();
      redirectSubmit();
    });
  }

  /**
   * This functoin handles save logic
   */
  function saveButtonClickHandler(element, uid){
    // We need to account for the sid here - so only show fields within the specific fieldset.
    if((element).attr("sid") != 'Null'){
      var currentSid = (element).attr("sid");
    } else if (((element).attr("id").length) > 0 ){
      var currentSid = (element).attr("id");        
    } 
    var id = (element).attr("id");
    // Check that all fields are filled out.
    var attend = $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-attending').val();
    var name = $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-name').val();
    var ministry = $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-ministry').val();
    var city = $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-city').val();
    if(attend.length < 1 || attend == 0 || ($.isNumeric(attend)==false)){
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-attending').css('border-color', 'red');
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-attending').after('<p class="error-note-attend" style="color: red;">* Attending field cannot be blank and must be numeric, please enter number of viewers.</p>');
      return;
    } else {
      $('.error-note-attend').remove();
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-attending').css('border-color', 'green');       
    }
    if(name.length < 1){
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-name').css('border-color', 'red');
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-name').after('<p class="error-note-name" style="color: red;">* Name field cannot be blank, please enter name.</p>');
      return;
    } else {
      $('.error-note-name').remove();
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-name').css('border-color', 'green');      
    }
    if(ministry.length < 1){
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-ministry').css('border-color', 'red');
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-ministry').after('<p class="error-note-ministry" style="color: red;">* Ministry field cannot be blank, please enter the name of your Ministry.</p>');
      return;
    } else {
      $('.error-note-ministry').remove();   
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-ministry').css('border-color', 'green');      
    }
    if(city.length < 1){
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-city').css('border-color', 'red');
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-city').after('<p class="error-note-city" style="color: red;">* City field cannot be blank, please enter the name of the city you work in.</p>');
      return;
    } else {
      $('.error-note-city').remove();   
      $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-city').css('border-color', 'green');       
    }

    // If they are, then save items.
    var confirmation = saveUpdates(currentSid, uid, id);
    // If they were restricted from adding another form, now they can
    $('#add-new-form').show();
    // If they were restricted from continuing to prem awards, now they can go there (have at least one form filled out)
    $(".ui-dialog-buttonset :first(.ui-button.ui-widget.ui-corner-all)").prop("disabled", false);
    return;
  }

  /**
   * This function handles edit button functions
   */
  function editButtonClickHandler(element){
    // We need to account for the sid here - so only show fields within the specific fieldset.
    if((element).attr("sid") != 'Null'){
      var currentSid = (element).attr("sid");
    } else if (((element).attr("id").length) > 0 ){
      var currentSid = (element).attr("id");        
    } 

    $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-input').show();
    $('.fieldset-prem-award-class-' + currentSid + ' .cancel-show-input-field').show();
    $('.fieldset-prem-award-class-' + currentSid + ' .save-form-field').show();

    $(element).hide();
    return;
  }

  /**
   * This function handles edit button functions
   */
  function cancelButtonClickHandler(element){
    // We need to account for the sid here - so only show fields within the specific fieldset.
    if((element).attr("sid") != 'Null'){
      var currentSid = (element).attr("sid");
    } else if (((element).attr("id").length) > 0 ){
      var currentSid = (element).attr("id");        
    } 

    $('.fieldset-prem-award-class-' + currentSid + ' .prem-award-input').hide();
    $('.fieldset-prem-award-class-' + currentSid + ' .show-input-field').show();
    $('.fieldset-prem-award-class-' + currentSid + ' .save-form-field').hide();      
    $(element).hide();
  }
  /**
   * This function submits redirects user to prem awards video
   **/ 
  function redirectSubmit(){
    // TODO: At this point we have already saved any changes via AJAX, so we can just redirect to prem awards vid.
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
      formString += '<input type="button" class="show-input-field" sid="Null" id="'+ timeStamp + '" value="Edit" hidden="true">';
      // Cancel button in case they don't want to edit afterall
      formString += '<input type="button" class="cancel-show-input-field" sid="Null" id="'+ timeStamp + '" value="Cancel">';
      // Holder button to fire a function to post changes. This is hidden initially
      formString += '<input type="button" class="save-form-field" sid="Null" id="'+ timeStamp + '" value="save">';
    formString += '</fieldset>';
    return formString;
  }

  function saveUpdates (sid, uid, id){
    // Gather all fields and post to php
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
    data['id'] = id;
    $.ajax({
      type: 'POST',
      url: '/p-awards/submit',
      dataType: 'json',
      success: ajaxCompleted,
      data: data,
    });
  }
  
  function updateFieldLabels(currentSid){
    var webcast = $('.fieldset-prem-award-class-' + currentSid + ' select.prem-award-input').val();
    var attending = $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-attending').val();
    var name = $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-name').val();    
    var ministry = $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-ministry').val();
    var city = $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-city').val();

    $('.fieldset-prem-award-class-' + currentSid + ' label[for="webcast-' + currentSid + '"]').html('Webcast: ' + webcast);
    $('.fieldset-prem-award-class-' + currentSid + ' label[for="attending-' + currentSid + '"]').html('Number Attending: ' + attending);
    $('.fieldset-prem-award-class-' + currentSid + ' label[for="name-' + currentSid + '"]').html('Name: ' + name);
    $('.fieldset-prem-award-class-' + currentSid + ' label[for="ministry-' + currentSid + '"]').html('Ministry: ' + ministry);
    $('.fieldset-prem-award-class-' + currentSid + ' label[for="city-' + currentSid + '"]').html('City: ' + city);
     
    $('.fieldset-prem-award-class-' + currentSid + ' select.prem-award-input').slideUp("slow");
    $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-attending').slideUp("slow");
    $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-name').slideUp("slow");
    $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-ministry').slideUp("slow");
    $('.fieldset-prem-award-class-' + currentSid + ' input.prem-award-input.prem-award-city').slideUp("slow");

    $('.fieldset-prem-award-class-' + currentSid + ' .cancel-show-input-field').hide();
    $('.fieldset-prem-award-class-' + currentSid + ' .save-form-field').hide();
    $('.fieldset-prem-award-class-' + currentSid + ' .show-input-field').show();
    
    $('<div id="save-confirmation-message-' + currentSid + ' class="save-confirmation-message"><p>Saved</p></div>').insertAfter('.fieldset-prem-award-class-' + currentSid + ' .show-input-field').slideDown();

    setTimeout(function(){
      $('#save-confirmation-message-' + currentSid).slideToggle("fast");    
      $('#save-confirmation-message-' + currentSid).remove();
    }, 5000);
  }


  // set teh confirmation message and save on returnData. Will need relevant sid to do this.
  function ajaxCompleted (returnData) {
    if(returnData['response'] == 200){
      updateFieldLabels(returnData['sid']);
    // general error, and one that appears in form-field
    } else if ("response" in returnData && returnData['response'] == "500"){
      // Something is wrong, so lets let them know and keep teh form open for review/resubmit.
      $('<div id="error-message" class="error-message-prem-form"><p>Something went wrong. Please review information and try to save again.</p></div>').insertAfter('.fieldset-prem-award-class-' + returnData['sid']).slideDown();
      setTimeout(function(){
        $('#error-message').slideToggle("fast");    
        $('#error-message').remove();
      }, 10000);
    } else {
      // Something is wrong, we received no legible response so lets let them know and keep teh form open for review/resubmit.
      $('<div id="error-message" class="error-message-prem-form"><p>Something went wrong. Please review information and try to save again.</p></div>').insertAfter('#premiers-awards-form').slideDown();
      setTimeout(function(){
        $('#error-message').slideToggle("fast");    
        $('#error-message').remove();
      }, 10000);
    }
  }
})(jQuery);
