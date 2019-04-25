(function ($) {
  /**
  $(document).ready(function () {
    var awardName = $(".field-name-field-lsa-award .field-item.odd").text();
	  var giftImages = giftListImages(); 
  
    var selectedAward= giftImages[awardName.trim()];
	  $(".field-name-field-lsa-award").after('<div><img id="lsa-award-selector-img-display-panel" /></div>');
	  if(typeof selectedAward !== 'undefined') {
      $("#lsa-award-selector-img-display-panel").css({
        "border-radius": "9px",
        "box-shadow": "2px 2px lightgrey",
        "padding": "10px",
        "border": "1px solid gray",
        "margin": "5px 0 20px 50px"
      }).attr({"src": selectedAward["URI"]});
    }

	  //Move RSVP block down the page
	  $("#block-views-lsa-admin-block-lsa-rsvp").insertAfter("#lsa-award-selector-img-display-panel");
	  $(".node-type-lsa-application #edit-actions--21").css({'text-align':'center','margin-top':'15px','margin-bottom':'15px'});


    $('.field-name-field-lsa-ceremony-response select option[value="_none"]').text('- Select your RSVP -');
    
    // Hide and style recipient/guest dietary requirements dropdown
    $(".field.field-name-field-lsa-recipient-dietary.field-type-text.field-label-above").hide();
    $(".field.field-name-field-lsa-dietary-guest.field-type-text.field-label-above").hide().parent().css("overflow", "hidden");
    $(".field.field-name-field-lsa-ceremony-accommodation").hide();
    
    //Show/hide dietary requirements input
    if($("input[name='field_lsa_dietary_requirements[und]']:checked").val() == '1') {
    	$(".field-name-field-lsa-recipient-dietary").show();
    	if(!$('.field-name-field-lsa-ceremony-response select option[value="1"]').prop("selected")) {
    	  $(".field-name-field-lsa-dietary-guest").show();
    	}
    }else if($("input[name='field_lsa_dietary_requirements[und]']:checked").val() == '0') {
    	$(".field.field-name-field-lsa-recipient-dietary.field-type-text.field-label-above").hide();
    	$(".field.field-name-field-lsa-dietary-guest.field-type-text.field-label-above").hide();
    }
    
    //Show/hide contact information for updating
    if($("input[name='field_do_you_need_to_update_your[und]']:checked").val() == 0) {
    	$("#node-lsa-application-full-group-lsad-contact-info").hide();
    	$(".collapsible.group-lsa-office-contact.field-group-fieldset.form-wrapper.collapse-processed").hide();
    } else if($("input[name='field_do_you_need_to_update_your[und]']:checked").val() == 1) {
    	$("#node-lsa-application-full-group-lsad-contact-info").show();
    	$(".collapsible.group-lsa-office-contact.field-group-fieldset.form-wrapper.collapse-processed").show();
    }

    // Show accessibility textbox instructions
    var accessibilityInstructions = "<p> If needed, please confirm the accessibility requirements that you and/or your guest " +
    	"require to attend the Long Service Awards ceremony (e.g. sign language interpreter (ASL), service dog, " +
    	"accessible parking/entrance, etc.).</p><br>";
    
    // Show accessibility instructions
    $(accessibilityInstructions).insertAfter(".field.field-name-field-lsa-accommodation-notes.field-type-text-long.field-label-above .field-label");
    $('.field.field-name-field-do-you-need-to-update-your.field-type-list-boolean.field-label-above').css({"margin-top": "15px"});
    
    var consentText = "<br><br><strong>Notice of Collection, Consent, and Authorization</strong><br>" +
    	"<em>Employees attending this event may appear on camera. " +
    	"Personal information including photo, video and/or voice, and any other information " +
    	"may be collected and used by the BC Public Service Agency to support communications " +
    	"and engagement within and on behalf of the BC Public Service. This information is " +
    	"being collected under the authority of section 26(c) of the Freedom of Information " +
    	"and Protection of Privacy Act (FOIPPA). <br>By registering for this ceremony, " +
    	"you agree to your personal information being disclosed to BC Public Service " +
    	"employees (e.g. @Work Corporate Intranet, @Work Newsletter, events, brochures, " +
    	"reports) and/or used and disclosed outside of Canada to a public site " +
    	"(e.g. YouTube, Twitter). This personal information will be accessed by BC Public " +
    	"Service employees and may also be accessed by the public. Should you have any " +
    	"questions about the collection or disclosure of this information, please contact: " +
    	"EmployeeNews@gov.bc.ca, 976 Meares St. Victoria, BC, V8V 3J4.</em>";

    $(consentText).insertAfter(".node-lsa-application #node-lsa-application-full-group-lsad-contact-info");

    //Hide fields if not attending
    if($('.field-name-field-lsa-ceremony-response select option[value="3"]').prop("selected")) {
    	$("#special-dietary-requirements").hide();
    	$(".field.field-name-field-lsa-accommodation-notes.field-type-text-long.field-label-above").hide();
    }

    // Set our change handlers, but only on initial load - don't want them going crazy. We can add a class to the title element in order to check.
    if(!$("#page-title").hasClass("page-processed-with-js")) {
      $("#page-title").addClass("page-processed-with-js");
      // We need to show both the dietary and special request choices, along with the option to update info if the user is either attending, or attending with a guest.
      // We can check on a change action
      $(".field-name-field-lsa-ceremony-response select").change(function () {
        // If no-on is attending, we don't need to show anything
        if($('.field-name-field-lsa-ceremony-response select option[value="3"]').prop("selected")) {
          // We already have a function for - the original setup to hide everything.
          // This will fire if anyone chooses an attending action, then changes their mind (hide previous choices).
          hideAttendingFields();
        }
      });
    }
  }); **/
  // Hide guest dietary requests if no-guest-attending is selected.
  $(".field-name-field-lsa-ceremony-response select").change(function() {
    console.log("Select has been changed");
    alert("Changed");
    if($('.field-name-field-lsa-ceremony-response select option[value="1"]').prop("selected")) {
      console.log("Attending without guest");
    	//attending without guest
    	$("#special-dietary-requirements").show();
    	$(".field.field-name-field-lsa-accommodation-notes.field-type-text-long.field-label-above").show();
    	if($('.form-item.form-type-radio.form-item-field-lsa-dietary-requirements-und input[value="1"]').prop('checked')) {
    		$('#special-dietary-requirements .field.field-name-field-lsa-dietary-guest.field-type-text.field-label-above').css({"display": "none"});
    	}
    } else if($('.field-name-field-lsa-ceremony-response select option[value="2"]').prop("selected")){
      console.log("Attending with a guest");
    	//attending with guest
    	$("#special-dietary-requirements").show();
    	$(".field.field-name-field-lsa-accommodation-notes.field-type-text-long.field-label-above").show();
    	if($('.form-item.form-type-radio.form-item-field-lsa-dietary-requirements-und input[value="1"]').prop('checked')) {
    		$('#special-dietary-requirements .field.field-name-field-lsa-dietary-guest.field-type-text.field-label-above').css({"display": "inline-block"});
    	}
    } else if ($('.field-name-field-lsa-ceremony-response select option[value="3"]').prop("selected")){
      console.log("Not attending");
    	$("#special-dietary-requirements").hide();
    	$(".field.field-name-field-lsa-accommodation-notes.field-type-text-long.field-label-above").hide();
    }
  });
  
  //Show/hide dietary requirements input
  $("#special-dietary-requirements").click(function () {
    if($("input[name='field_lsa_dietary_requirements[und]']:checked").val() == '1') {
    	$(".field.field-name-field-lsa-recipient-dietary.field-type-text.field-label-above").css({"display": "inline-block"});
    	if(!$('.field-name-field-lsa-ceremony-response select option[value="1"]').prop("selected")) {
    	  $(".field.field-name-field-lsa-dietary-guest.field-type-text.field-label-above").css({"display": "inline-block"});
    	}
    }else if($("input[name='field_lsa_dietary_requirements[und]']:checked").val() == '0') {
    	$(".field.field-name-field-lsa-recipient-dietary.field-type-text.field-label-above").css({"display": "none"});
    	$(".field.field-name-field-lsa-dietary-guest.field-type-text.field-label-above").css({"display": "none"});
    }
  });
  
  //Show/hide contact information 
  $(".field.field-name-field-do-you-need-to-update-your.field-type-list-boolean.field-label-above").click(function () {
  if($("input[name='field_do_you_need_to_update_your[und]']:checked").val() == 0) {
  	$("#node-lsa-application-full-group-lsad-contact-info").hide();
  	$(".collapsible.group-lsa-office-contact.field-group-fieldset.form-wrapper.collapse-processed").hide();
  } else if($("input[name='field_do_you_need_to_update_your[und]']:checked").val() == 1) {
  	$("#node-lsa-application-full-group-lsad-contact-info").show();
  	$(".collapsible.group-lsa-office-contact.field-group-fieldset.form-wrapper.collapse-processed").show();
  }
  });

  // Close all shown buttons save on click
  function close_button(){
      // At this point, the modules css hides the button after we click it, so no need to do it ourselves.
      // Misses this one:
      $('[id^=edit-field-lsa-specialrequirements]').next().children().hide();
      $(".message").hide();
  }


  // Open relevant button when its text field is clicked
  function open_button(event){
    if(!event){
      event = $(window.event);
    }
    // Check what was clicked
    var target = $(event.target) || $(event.srcElement);

    // If it is a special requirements textbox
    if(target.is("[id^=edit-field-specialrequirement-descrip]")){
      target.parent().parent().parent().parent().next().children().show();
      // If they click to change this  - make sure the checkbox's are already saved or else user could save in wrong order and lose text
      $('input[type=submit]','.field-name-field-lsa-specialrequirements').click();
    }

    // If it is a special requirements checkbox.
    if(target.is("[id^=edit-field-lsa-specialrequirements-und]")){
      //console.log(target);
      target.parent().parent().parent().parent().next().children().show();
    }


    // If it is a textbox
    if(target.is("input.text-full") ) {
      // show the submit button that is generally found in this area
      try {
        target.parent().parent().parent().next().children().css("display", "block");
      }
      // If it is not there, we will suppress the error message
      catch(err){

      }
    }
    

    if (target.is("input.form-text")){
      try {
        target.parent().parent().parent().parent().next().children().css("display","block");
      }
      catch(err){
      }
    }

    if (target.is("input#edit-field-lsa-home-phone-und-0-value") || target.is("input#edit-field-lsa-work-phone-und-0-value")){
      try {
        target.parent().parent().parent().next().children().css("display","block");
      }
      catch(err){
        //console.log(err);
      }
    }
    // We want to send feedback as a checkmark when the user clicks to save changes.
    if(target.is(".form-submit.ajax-processed")){
      if(target.parent().parent().parent().parent().hasClass('editablefield-processed')){
        // Only want to attach this once
        if(target.parent().parent().parent().next().hasClass('change-confirmed-message')){
          // Do not reattache saving logo in this case..
          target.parent().parent().parent().next().fadeIn();
          setTimeout(function(){
            target.parent().parent().parent().next().fadeOut();
          }, 2000);
          setTimeout(function(){
            target.fadeOut();
          }, 2000);
        } else {
          target.parent().parent().parent().after('<span class="change-confirmed-message">&nbsp<i class="fa fa-check-circle"/>&nbsp<p>Changes&nbspsaved...</p></span>');
          target.parent().parent().parent().next().hide();
          target.parent().parent().parent().next().fadeIn();
          setTimeout(function(){
            target.parent().parent().parent().next().fadeOut();
          }, 2000);
          setTimeout(function(){
            target.fadeOut();
          }, 2000);
        }
      }
    }

    // If anything has changed, we should re-run settings()
    settings();
  }



  function settings(){
    // Deciding which fields should be visible to user on initial load
    // Move the messages to just above the Step 2 message.
    // Get text, and make sure it is the correct message.
    var checkMessage = $('.messages--status.messages.status').text();
    if(checkMessage.indexOf("RSVP") >= 0){
      // If it is the string we are looking for, place the message lower and focus on it.
      //$('.messages--status.messages.status').insertAfter('#editableviews-entity-form-lsa-admin');
      // replace the text with a call to move to step 2
      //$('.messages--status.messages.status').text("Your RSVP has been received. Thank you!");
      //$(submitMessage).insertAfter(".messages--status.messages.status");
    }

    // Change all save buttons to "save changes"
    $('.form-submit.ajax-processed').val('Save Change');
    
    // If they are not retiring this year, no need to have a field to enter a retirement date.
    if($("input[name='field_lsa_retiring_thisyear[und]']:checked").prop('value') == 0){
      $("div.field.field-name-field-lsa-date-of-retirement").hide();
    } else {
      $("div.field.field-name-field-lsa-date-of-retirement").show();
    }

    var years_of_service = $(".field.field-name-field-lsa-years-of-service.field-type-list-integer.field-label-inline.clearfix div.field-items div.field-item").text();
    var award_name = $(".field.field-name-field-lsa-award.field-type-text.field-label-inline.clearfix div.field-items div.field-item").text();

    // Do they get a certificate?
    if(years_of_service != "25" && award_name.indexOf("PECSF") < 0){
    	$(".field.field-name-field-lsa-25year-certificatename.field-type-text.field-label-inline.clearfix").hide();
    }else {
    	$(".field.field-name-field-lsa-25year-certificatename.field-type-text.field-label-inline.clearfix").show();
    }

    // Did they choose a watch?
    if(years_of_service == "35" && award.indexOf("Watch") >= 0){
      if(award.indexOf('Ladies') >= 0){
        $(".field-name-field-lsa-engravement").show();
        $("#edit-field-lsa-engravement-und-0-value").attr('maxlength', "27");
      } else if(award.indexOf('Men\'s') >= 0){
        $(".field-name-field-lsa-engravement").show();
        $("#edit-field-lsa-engravement-und-0-value").attr('maxlength', "33");
      } else {
        $(".field-name-field-lsa-engravement").hide();
      }
      // Mens


    }else {
        $(".field-name-field-lsa-engravement").hide();
    }

    // Now to handle special requirements
    var checked_boxes = $('.form-checkbox');
    $(checked_boxes).each(function() {
      // None can only be checked if nothing else is
      if($("[id^=edit-field-lsa-specialrequirements-und-6]").prop('checked') === true) {
        $("[id^=edit-field-lsa-specialrequirements-und-5]").prop('checked',false);
        $("[id^=edit-field-lsa-specialrequirements-und-5]").prop('disabled', true);
        $("[id^=edit-field-lsa-specialrequirements-und-4]").prop('checked',false);
        $("[id^=edit-field-lsa-specialrequirements-und-4]").prop('disabled',true);
        $("[id^=edit-field-lsa-specialrequirements-und-3]").prop('checked',false);
        $("[id^=edit-field-lsa-specialrequirements-und-3]").prop('disabled',true);
        $("[id^=edit-field-lsa-specialrequirements-und-2]").prop('checked',false);
        $("[id^=edit-field-lsa-specialrequirements-und-2]").prop('disabled',true);
        $("[id^=edit-field-lsa-specialrequirements-und-1]").prop('checked',false);
        $("[id^=edit-field-lsa-specialrequirements-und-1]").prop('disabled',true);
        $('.field.field-name-field-specialrequirement-descrip div.field-label').hide();
      } else {
        $("[id^=edit-field-lsa-specialrequirements-und-5]").prop('disabled', false);
        $("[id^=edit-field-lsa-specialrequirements-und-4]").prop('disabled',false);
        $("[id^=edit-field-lsa-specialrequirements-und-3]").prop('disabled',false);
        $("[id^=edit-field-lsa-specialrequirements-und-2]").prop('disabled',false);
        $("[id^=edit-field-lsa-specialrequirements-und-1]").prop('disabled',false);
      }


      if($("[id^=edit-field-lsa-specialrequirements-und-1]").prop('checked') === true && $("[id^=edit-field-lsa-specialrequirements-und-5]").prop('checked') === true){
        // We have an allergy and other box checked
        // Show special requirements text box
        $('[id^=edit-field-specialrequirement-descrip]').show();
        //  Change the help prompt text
        $('.field.field-name-field-specialrequirement-descrip div.field-label').text('Please tell us more about your food allergy, and other requirements.');
        $('.field.field-name-field-specialrequirement-descrip div.field-label').show();
        //  This is now required
        $('[id^=edit-field-specialrequirement-descript-und-0-value]').prop('required', true);

        return;
      }
      if($("[id^=edit-field-lsa-specialrequirements-und-1]").prop('checked') === true && $("[id^=edit-field-lsa-specialrequirements-und-5]").prop('checked') === false){
        // Allergies only
        // Show special requirements text box
        $('[id^=edit-field-specialrequirement-descrip]').show();
        // Required
        $('[id^=edit-field-specialrequirement-descript-und-0-value]').prop('required', true);
        // Change help prompt text
        $('.field.field-name-field-specialrequirement-descrip div.field-label').html('Please tell us more about your food allergy.');
        $('.field.field-name-field-specialrequirement-descrip div.field-label').show();

        return;
      }
      if($("[id^=edit-field-lsa-specialrequirements-und-1]").prop('checked') === false && $("[id^=edit-field-lsa-specialrequirements-und-5]").prop('checked') === true){
        // Other only
        // Show special requirements text box
        $('[id^=edit-field-specialrequirement-descrip]').show();
        // Required
        $('[id^=edit-field-specialrequirement-descript-und-0-value]').prop('required', true);
        // Change help prompt text
        $('.field.field-name-field-specialrequirement-descrip div.field-label').html('Please tell us more about your requirements.');
        $('.field.field-name-field-specialrequirement-descrip div.field-label').show();
        return;
      }
      if($("[id^=edit-field-lsa-specialrequirements-und-1").prop('checked') === false && $("[id^=edit-field-lsa-specialrequirements-und-5").prop('checked') === false){
        // Hide special requirements box
        $('[id^=edit-field-specialrequirement-descrip]').hide();
        // Clear the special requirements box
        $('[id^=edit-field-specialrequirement-descrip-und-0-value]').val('');
        // No longer required
        $('[id^=edit-field-specialrequirement-descript-und-0-value]').prop('required', false);
        $('.field.field-name-field-specialrequirement-descrip div.field-label').hide();

        return;
      }

      $('.field.field-name-field-specialrequirement-descrip div.field-label').hide();

    });
  }
  function setTooltip(){
    // First add an icon behind the block we wish to mark
    // For the "Attending" dropdown
    $(".chosen-disable.form-select").after('<i class="fa fa-info-circle" id="attending-icon"></i>');
    $("#attending-icon").qtip({
      content: {
        title: "RSVP Status",
        text: "Recipients are scheduled with the ministry/organization they currently work for. Because of the logistical complexity of scheduling ceremonies for over 1500 recipients, it’s extremely difficult to allow recipients to switch nights. However, if your ministry has another ceremony date scheduled, please email the longserviceawards@gov.bc.ca with your request.",
      },
      style: {
        classes: "qtip-blue qtip-shadow qtip-rounded",
        def: false,
      },
      show: {
        effect: function() {
          $(this).fadeTo(250, 1);
        }
      },
      hide: {
        effect: function() {
          $(this).hide('puff', 250);
        }
      }
    });

    // For Step 2 note
    $('#node-lsa-application-full-group-lsad-special-requirements h2').after('&nbsp<i class="fa fa-info-circle special-requirements-lsa"></i>');
    $('.special-requirements-lsa').qtip({
      content: {
        title: "Special Requirements",
        text: "If you indicate that you or your guest have special requirements, the Long Service Awards team will contact you to discuss your specific needs in more detail.",
      },
      style: {
        classes: "qtip-blue qtip-shadow qtip-rounded",
        def: false,
      },
      show: {
        effect: function() {
          $(this).fadeTo(250, 1);
        }
      },
      hide: {
        effect: function() {
          $(this).hide('puff', 250);
        }
      }
    });
  }

  function addGiftImage() {
    let awardName = $(".field-name-field-lsa-award .field-item.odd").text();
    let giftImages = giftListImages();

    let selectedAward= giftImages[awardName.trim()];
    $(".field-name-field-lsa-award").after('<div><img id="lsa-award-selector-img-display-panel" /></div>');
    if(typeof selectedAward !== 'undefined') {
      $("#lsa-award-selector-img-display-panel").css({
        "border-radius": "9px",
        "box-shadow": "2px 2px lightgrey",
        "padding": "10px",
        "border": "1px solid gray",
        "margin": "5px 0 20px 50px"
      }).attr({"src": selectedAward["URI"]});
    }

    //Move RSVP block down the page
    $("#block-views-lsa-admin-block-lsa-rsvp").insertAfter("#lsa-award-selector-img-display-panel");
    $(".node-type-lsa-application #edit-actions--21").css({'text-align':'center','margin-top':'15px','margin-bottom':'15px'});
  }

  /**
   * Only show any of these if the user is actually attending the show
   * We are using pseudo selectors set up with form elements here
   */
  function hideAttendingFields(){
    // Dietary info.
    $specialRequirements = hideField($("#special-dietary-requirements"));

    // Accommodation info.
    $ceremonyAccommodations = hideField($("#special-ceremony-accomodations"));

    // User info
    $contactInfo = hideField($("#node-lsa-application-full-group-lsad-contact-info"));

    // Update contact info boolean
    $update = hideField($(".field-name-field-do-you-need-to-update-your"));
  }

  function hideField($field){
    if(!$field.hasClass("hidden")){
      if($field.hasClass("show")){
        $field.removeClass("show");
      }
      $field.addClass("hidden");
      $field.hide();
    }
    return $field;
  }

  function showField($field){
    if(!$field.hasClass("show")){
      if($field.hasClass("hidden")){
        $field.removeClass("hidden");
      }
      $field.addClass("show");
      $field.show();
    }
    return $field;
  }

  /**
   * Helper function that returns if a user is bringing a guest or not
   * @return boolean
   */
  function checkAttendees(){
    // has guest, return true, only one case where this applies.
    return $('.field-name-field-lsa-ceremony-response select option[value="2"]').prop("selected");
  }

  // We want to cache each form element independently so that we can manipulate it easily and quickly - we will do this at global scope for this page.
  let $specialRequirements = $("#special-dietary-requirements");
  let $ceremonyAccommodations = $("#special-ceremony-accomodations");
  let $contactInfo = $("#node-lsa-application-full-group-lsad-contact-info");
  let $update = $(".field-name-field-do-you-need-to-update-your");
  let $rsvp = $(".field-name-field-lsa-ceremony-response");

  /**
 * Main function, various click handlers/event listener.
 *
 */
  $(document).ready(function(){
    // Some things should be hidden
    hideAttendingFields();
    // Pull in an image of the gift
    addGiftImage();
    // change the first option in the RSVP block:
    $('.field-name-field-lsa-ceremony-response select option[value="_none"]').text('- Select your RSVP -');

    close_button();
    settings();
    // Fieldset titles are super annoying, and can't be turned off.
    $('.fieldset-legend').hide();
    $('.fieldset-title').hide();
    //setTooltip();
    document.body.addEventListener('click', open_button, true);

  });

  $(document).ajaxComplete(function() {
    close_button();
    settings();
  });
})(jQuery);
