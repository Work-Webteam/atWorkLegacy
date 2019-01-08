(function ($) {

/**
 * This function handles various form messages and elements, determining when they should be seen.
 * All elements and messages are created in set_form() function below
 *
 */
  function lsaGift() {
  
    // Hide the certificate name input if they change award
   	$('#edit-field-lsa-25year-certificatename').hide();
  
    if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 1){
      $('#edit-field-lsa-award-und-0-value').val("2017 Recipient - award received");
      $('#edit-field-lsa-award-id-und-0-value').val(1);
    }
    // Always reset textbox when this value changes, so that we don't have a mis-match between award and years of service
    if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 2 && $('input[name="field_lsa_years_of_service[und]"]:checked').val() <= 40) {
      //$("#edit-field-lsa-award-id-und-0-value").val('');
      //$('#edit-field-lsa-award-und-0-value').val('');
      //$("#edit-field-lsa-award-und-0-value").hide();
      //$(".lsa-award-selector-img-display-panel").hide();
      //$("#lsa-award-selector-description-display").remove();
      $(".form-item.form-type-textfield.form-item-field-lsa-award-und-0-value").hide();

      // Also reset the engravement choice - in case it is no longer relevant
      //$('#edit-field-lsa-engravement-und-0-value').val('');
      $('#edit-field-lsa-engravement-und-0-value').hide();
      $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').hide();
    }

    // Gift select button for users who choose 25 - 40 years
    if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 2 && $('input[name="field_lsa_years_of_service[und]"]:checked').val() >= 25 && $('input[name="field_lsa_years_of_service[und]"]:checked').val() <= 40)  {
      $('#gift_select').show();
      $('.form-item.form-type-textfield.form-item-field-lsa-award-und-0-value').show();
      $('#edit-field-lsa-award-sp-instructions').show();
    }  else if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 2 && $('input[name="field_lsa_years_of_service[und]"]:checked').val() >= 25)   {
      $('#gift_select').hide();
      $('.form-item.form-type-textfield.form-item-field-lsa-award-und-0-value').show();
      $('#edit-field-lsa-award-sp-instructions').show();
    } else {
      $('#gift_select').hide();
      $('.form-item.form-type-textfield.form-item-field-lsa-award-und-0-value').hide();
      $('#edit-field-lsa-award-sp-instructions').hide();
    }
    // Message for 45 & 50 year recipients
    if($("input[name='field_lsa_register_last_year[und]']:checked").val() == 2 && ($('input[name="field_lsa_years_of_service[und]"]:checked').val() >= 45)){
      $('#special_gift').show();
    } else {
      $('#special_gift').hide();
    }

    // Determines if last years recipients received their award as they should have
    if($("input[name='field_lsa_received_award[und]']:checked").prop("value") == "0"){
      $('#lost_gift_message').show();
    } else {
      $('#lost_gift_message').hide();
    }

    // Handles specific form elements that are particular to a certain years choice
    var gift_year_choice = $('input[name="field_lsa_years_of_service[und]"]:checked').val();
    if (gift_year_choice != 25){
      //$('#field-lsa-25year-certificatename-add-more-wrapper').hide();
      $("input#edit-field-lsa-25year-certificatename-und-0-value").prop("required", false);
      $('#edit-field-lsa-25year-certificatename-und-0-value').val('');
      checkPECSF();
    }
    if(gift_year_choice != 35){
      $('#edit-field-lsa-engravement-und-0-value').val('');
      $('#edit-field-lsa-engravement-und-0-value').hide();
      $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').hide();
    }
    // Set dietary and accomodation boxes open/closed as appropriate
    // Show textbox if there are accomodation requests
      if($('#edit-field-lsa-ceremony-accommodation-und-1').is(":checked")){
        $('#field-lsa-accommodation-notes-add-more-wrapper').show();
      } 
      // Otherwise hide
      if($('#edit-field-lsa-ceremony-accommodation-und-0').is(":checked")){
        $('#field-lsa-accommodation-notes-add-more-wrapper').hide();
      }
    
        // Show dietary options if required
        if($('#edit-field-lsa-dietary-requirements-und-1').is(":checked")){
          $("#edit-field-lsa-recipient-dietary").show();
          $('#edit-field-lsa-dietary-guest').show();
        } 

        // Otherwise hide
        if($('#edit-field-lsa-dietary-requirements-und-0').is(":checked")){
          $("#edit-field-lsa-recipient-dietary").hide();
          $('#edit-field-lsa-dietary-guest').hide();
        } 
        checkPECSF();

  }

  /**
   * Adds retirement message for recipients who retire this year
   *
   */
  function retirement() {
    if ($('input[name="field_lsa_retiring_thisyear[und]"]:checked').val() == 1){
      $('#retirement_message').show();
      $('#field-lsa-date-of-retirement-add-more-wrapper').show();
    } else {
      $('#retirement_message').hide();
      $('#field-lsa-date-of-retirement-add-more-wrapper').hide();
    }
  }

  /**
   * Helper function that fills hidden form element that records user award year
   *
   */
  function change_award_year() {
    if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 1) {
      $('select#edit-field-lsa-award-year-und option[value="2"]').prop('selected', true);
      $('#edit-field-lsa-received-award').show();
    } else {
      $('select#edit-field-lsa-award-year-und option[value="1"]').prop('selected', true);
      $('#edit-field-lsa-received-award').hide();
    }
  }

  /**
   *  Various notes for specific form elements
   *  Creates gift button linking to atwork_lsa_gift.js functions
   */
  function set_form() {
    // For some reason, we have a term/privacy notice that looks very strange at the bottom of this page. Hide it.
    $('#block-block-31').hide();
    // Gift button - links user to gift choices outlined in atwork_lsa_gift.js
    var gift_button = $('<br /><input type="button" value="Select Award" id="gift_select" />');
    $('#field-lsa-award-add-more-wrapper').append(gift_button);
    $('#gift_select').hide();

    // Message for retired applicants
    var retirement = $('<div id="retirement_message"><p><span style="color:red">Please enter your last scheduled day of work</span></div>');
    $('#edit-field-lsa-retiring-thisyear').append(retirement);
    $('#retirement_message').hide();
    $('#field-lsa-date-of-retirement-add-more-wrapper').hide();
    // Message for users from previous year who never received their gift
    var lost_gift = $('<div id="lost_gift_message"><span style="color:red "> *Please take time to send a quick <a href="mailto:LongServiceAwards@gov.bc.ca?subject=LSA%20award%20not%20yet%20received">email</a> to the Long Service Awards team and let us know your award is still outstanding</span></div>');
    $('#edit-field-lsa-received-award').append(lost_gift);
    $('#lost_gift_message').hide();
    // Message for recipients who have completed 45 || 50 years
    var special_gift = $('<div id="special_gift"><span style="color:red;"><strong>*</strong> Because of your notable milestone, the Long Service Awards program would like to give you an opportunity to identify an award that would be most meaningful to you. Our awards coordinator will contact you in May or June.</span></div>');
    $('#edit-field-lsa-years-of-service').append(special_gift);
    $('#special_gift').hide();

    // Setting award text box - will not be useable by applicant
    // Only hide if user has not chose a milestone
    if(!$("#edit-field-lsa-years-of-service-und input:radio").is(":checked")){
      $('#edit-field-lsa-award-und-0-value').hide();
      $(".lsa-award-selector-img-display-panel").hide();
    }

    //$("#lsa-award-selector-description-display").remove();
    // Shrink word count wording
    $("#edit-field-lsa-25year-certificatename-und-0-value-counter").css("font-size", "smaller");
    
    $('.form-item.form-type-textfield.form-item-field-lsa-award-und-0-value').hide();
    $('#edit-field-lsa-award-und-0-value').prop("readonly", true);
    $('#edit-field-lsa-award-und-0-value').css('background-color' , '#DEDEDE');

    // Setting engravement text box - will no be useable by applicant
    $('#edit-field-lsa-engravement-und-0-value').hide();
    //$('#edit-field-lsa-engravement-und-0-value').prop("readonly", true);
    //$('#edit-field-lsa-engravement-und-0-value').css('background-color' , '#DEDEDE');
    $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').hide();

    // 25 year certificate box will only be used by 25 year recipients, or PECSF recipients
    //$('#field-lsa-25year-certificatename-add-more-wrapper').hide();

    // There will be no instructions unless we actually are choosing an award
    $('#edit-field-lsa-award-sp-instructions').hide();
    // Hide PECSF unless user selects this choice
    var award_value = $('#edit-field-lsa-award-id-und-0-value').val();
    if($.inArray(award_value, ["7","13","33","40","42","44"]) > -1){
      $("#pecsf-fields").show();
      $('#field-lsa-25year-certificatename-add-more-wrapper').show();
    }else if ($('#edit-field-lsa-years-of-service-und-25').is(":checked")){
      $('#field-lsa-25year-certificatename-add-more-wrapper').show();
      // If we made it here, it is not pecsf
      $('#pecsf-fields').hide();
    }else{
      $('#pecsf-fields').hide();
      $('#field-lsa-25year-certificatename-add-more-wrapper').hide();
    }
        // Change text for pecsf options (too long for text box in setup)
    $("label[for=edit-field-lsa-donation-options-und-0]").html('Option A: Make a PECSF donation to the <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity" target="_blank">fund supported pool of charities in my region</a>.');
    $("label[for=edit-field-lsa-donation-options-und-1]").html('Option B: Make a PECSF donation to one or two charities of my choice. (Find the PECSF ID number for your choice(s) by reviewing the <a href="https://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">charity list by region</a>.)');
    $("form-item.form-type-radio.form-item-field-lsa-donation-options-und").attr("style", "display:block");
    // Hide alternate fields until they are required
    $('.collapsible.required-fields.group-lsa-first-donation.field-group-fieldset.form-wrapper.collapse-processed').hide();
    $('.collapsible.required-fields.group-lsa-second-donation.field-group-fieldset.form-wrapper.collapse-processed').hide();
    // Only we can change this:
    $('#edit-field-lsa-donation-amount-und-0-value').prop("readonly", true);
    $('#edit-field-lsa-donation-amount-2-und-0-value').prop("readonly", true);
    // We will manipulate this behind the scenes
    $('#edit-field-lsa-certificate-ordered').hide();
    // We want option A before option b for the PECSF
    ///divB = $('#edit-field-lsa-donation-options-und-0').parent().detach();
    ///divB.insertAfter($('#edit-field-lsa-donation-options-und-1').parent());
    // And no NA option here:
    $('#edit-field-lsa-donation-options-und-none').parent().hide();
    $('#edit-field-lsa-second-donation-und-none').parent().hide();
    // Set special requirements jQuery
    $('#field-lsa-accommodation-notes-add-more-wrapper').hide();
    $('#edit-field-lsa-recipient-dietary').hide();
    $('#edit-field-lsa-dietary-guest').hide();
    // Move the "not known" checks after the "other"
    var move = $('.form-item.form-type-checkbox.form-item-field-lsa-dietary-guest-und-select-Guest-information-is-not-known-at-this-time').detach();
    $('.form-item.form-type-textfield.form-item-field-lsa-dietary-guest-und-other').after(move);
    var accommodationMove = $('.form-item.form-type-checkbox.form-item-field-lsa-guest-accom-und-select-Guest-information-is-not-known-at-this-time');
    $('.form-item.form-type-textfield.form-item-field-lsa-guest-accom-und-other').after(accommodationMove);
  }

  // Make sure phone number is formatted right
  function phone_fix(){
    $("#edit-field-lsa-home-phone-und-0-value").keyup(function(e) {
      if(e.keyCode == 8){
        return;
      }
      var curchr = this.value.length;
      var curval = $(this).val();
      if(curchr == 3) {
        $("#edit-field-lsa-home-phone-und-0-value").val(curval + " ");
      } else if (curchr === 7) {
        $("#edit-field-lsa-home-phone-und-0-value").val(curval + "-");
      }
    });
    $('#edit-field-lsa-work-phone-und-0-value').keyup(function(e) {
      if(e.keyCode == 8){
        return;
      }
      var curchr = this.value.length;
      var curval = $(this).val();
      if(curchr == 3) {
        $("#edit-field-lsa-work-phone-und-0-value").val(curval + " ");
      } else if (curchr === 7) {
        $("#edit-field-lsa-work-phone-und-0-value").val(curval + "-");
      }
    });
  }

  // Populate certificate if not already done with full name.
  function certificate_populate(){
    // Should only populate if they have 25 years of service, and award year == 2016
    if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 25  && ($('input[name="field_lsa_register_last_year[und]"]:checked').val() == 2 )) {
      if($('#edit-field-lsa-25year-certificatename-und-0-value').val().length < 1){
        if($('#edit-field-lsa-middle-name-und-0-value').val().length > 0){
          $('#edit-field-lsa-25year-certificatename-und-0-value').val($('#edit-field-lsa-first-name-und-0-value').val() + ' ' + $('#edit-field-lsa-middle-name-und-0-value').val() + ' ' + $('#edit-field-lsa-last-name-und-0-value').val());
        } else {
          $('#edit-field-lsa-25year-certificatename-und-0-value').val($('#edit-field-lsa-first-name-und-0-value').val() + ' ' + $('#edit-field-lsa-last-name-und-0-value').val());
        }
      }
    }
    // We now allow this for PECSF as well
    checkPECSF();
  }


/**
 * Main function, various click handlers.
 *
 */
  $(document).ready(function(){
    //jQuery.error = console.error;
    set_form();
    lsaGift();
    
    // Show textbox if there are accomodation requests
    $('#edit-field-lsa-ceremony-accommodation-und-1').click(function() {
      if($('#edit-field-lsa-ceremony-accommodation-und-1').is(":checked")){
        $('#field-lsa-accommodation-notes-add-more-wrapper').slideDown("slow");
      } 
    });
    // Otherwise hide
    $('#edit-field-lsa-ceremony-accommodation-und-0').click(function() {
      if($('#edit-field-lsa-ceremony-accommodation-und-0').is(":checked")){
        $('#field-lsa-accommodation-notes-add-more-wrapper').slideUp("slow");
      }
    });
    
    // Show dietary options if required
    $('#edit-field-lsa-dietary-requirements-und-1').click(function() {
      if($('#edit-field-lsa-dietary-requirements-und-1').is(":checked")){
        $("#edit-field-lsa-recipient-dietary").slideDown();
        $('#edit-field-lsa-dietary-guest').slideDown();
      } 
    });
    // Otherwise hide
    $('#edit-field-lsa-dietary-requirements-und-0').click(function() {
      if($('#edit-field-lsa-dietary-requirements-und-0').is(":checked")){
        $("#edit-field-lsa-recipient-dietary").slideUp();
        $('#edit-field-lsa-dietary-guest').slideUp();
      } 
    });

    $('#edit-field-lsa-register-last-year-und').change(function () {
      lsaGift();
      change_award_year();
      certificate_populate();
      checkPECSF();
    });

    $('#edit-field-lsa-years-of-service').change(function () {
      // If they change year - wipe award
      $("#edit-field-lsa-award-und-0-value").val("");
      // Wipe out picture
      $(".lsa-award-selector-img-display-panel.imageeditor-inline-processed").hide();
      // Wipe award ID
      $("#edit-field-lsa-award-id-und-0-value").val("");
      lsaGift();
      certificate_populate();
      checkPECSF();
    });
    
    $('#edit-field-lsa-received-award').change(function () {
      lsaGift();
    });

    $('#edit-field-lsa-retiring-thisyear-und').change(function () {
      retirement();
    });

    $('#edit-field-lsa-home-phone-und-0-value').keyup(function(){
      phone_fix();
    });

    $('#edit-field-lsa-work-phone-und-0-value').keyup(function(){
      phone_fix();
    });

    $('#edit-submit').click(function(){
      checkPECSF();
      certificate_populate();
    });

    // PECSF donation settings
    $('#edit-field-lsa-second-donation-und-1').on('click', function(){
      // User has decided to split their donation, we need to alter amounts
      if($('#edit-field-lsa-second-donation-und-1').prop("checked", true)){
        // Grab existing value
        let amount = $('#edit-field-lsa-donation-amount-und-0-value').val();
        // Remove $ sign
        amount = amount.substring(1, amount.length);
        // Split in half
        amount = amount/2;
        // Round to dolar amount
        amount = amount.toFixed(2);
        // Readd the dolar sign
        amount = '$' + amount;
        // Add it into the two donation text boxes
        $('#edit-field-lsa-donation-amount-und-0-value').val(amount);
        $('#edit-field-lsa-donation-amount-und-0-value').prop("readonly", true);
        $('#edit-field-lsa-donation-amount-2-und-0-value').val(amount);
        $('#edit-field-lsa-donation-amount-2-und-0-value').prop("readonly", true);
        $('.collapsible.required-fields.group-lsa-second-donation.field-group-fieldset.form-wrapper.collapse-processed').slideDown('fast');
        $('#edit-field-lsa-pecsf-id-2').slideDown('fast');
        $('#edit-field-lsa-charity-name-2').slideDown('fast');
        $('#edit-field-lsa-donation-amount-2').slideDown('fast');
      }
    });
    // If user selects no, we can  reassign all $ to first choice.
    $('#edit-field-lsa-second-donation-und-0').on('click', function(){
      set_pecsef($("input[name='field_lsa_years_of_service[und]']:checked").val());
      $('#edit-field-lsa-donation-amount-2-und-0-value').val('');
      $('#edit-field-lsa-pecsf-id-2-und-0-value').val('');
      $('#edit-field-lsa-charity-name-2-und-0-value').val('');

      // Also reset form fields so we don't get strange data
      $('.collapsible.required-fields.group-lsa-second-donation.field-group-fieldset.form-wrapper.collapse-processed').slideUp('fast');
      $('#edit-field-lsa-pecsf-id-2').slideUp('fast');
      $('#edit-field-lsa-charity-name-2').slideUp('fast');
      $('#edit-field-lsa-donation-amount-2').slideUp('fast');

    });
        // If user selects na, we can  reassign all $ to first choice.
    $('#edit-field-lsa-second-donation-und-none').on('click', function(){
      set_pecsef($("input[name='field_lsa_years_of_service[und]']:checked").val());
      $('#edit-field-lsa-donation-amount-2-und-0-value').val('');
      $('.collapsible.required-fields.group-lsa-second-donation.field-group-fieldset.form-wrapper.collapse-processed').slideUp('fast');
    });

    // Handle choice B in PECSF form
    $('#edit-field-lsa-donation-options-und-1').on('click', function(){
      $('.collapsible.required-fields.group-lsa-first-donation.field-group-fieldset.form-wrapper.collapse-processed').slideDown('fast');
      // For IE we have to explicitly tell it to open the field under here for some stupid reason
      $('#edit-field-lsa-pecsf-region').show();
      $('#edit-field-lsa-pecsf-id').show();
      $('#edit-field-lsa-pecsf-charity-name').show();
      $('#edit-field-lsa-donation-amount').show();
      $('#edit-field-lsa-second-donation').show();
      set_pecsef($("input[name='field_lsa_years_of_service[und]']:checked").val());
    });
    $('#edit-field-lsa-donation-options-und-0').on('click', function(){
      $('.collapsible.required-fields.group-lsa-first-donation.field-group-fieldset.form-wrapper.collapse-processed').slideUp('fast');
      // For IE we have to explicitly tell it to open the field under here for some stupid reason
      $('#edit-field-lsa-pecsf-region').show();
      $('#edit-field-lsa-pecsf-id').hide();
      $('#edit-field-lsa-pecsf-charity-name').hide();
      $('#edit-field-lsa-donation-amount').hide();
      $('#edit-field-lsa-second-donation').hide();
      $('#edit-field-lsa-donation-amount-und-0-value').val('');
      $('#edit-field-lsa-donation-amount-2-und-0-value').val('');
      $('.collapsible.required-fields.group-lsa-second-donation.field-group-fieldset.form-wrapper.collapse-processed').slideUp('fast');
      $('#edit-field-lsa-pecsf-id-2').slideUp('fast');
      $('#edit-field-lsa-charity-name-2').slideUp('fast');
      $('#edit-field-lsa-donation-amount-2').slideUp('fast');
      $('#edit-field-lsa-second-donation-und-0').prop("checked", true);
    });
    $('#edit-field-lsa-donation-options-und-none').on('click', function(){
      $('.collapsible.required-fields.group-lsa-first-donation.field-group-fieldset.form-wrapper.collapse-processed').slideUp('fast');
      $('#edit-field-lsa-pecsf-region').hide();
      $('#edit-field-lsa-pecsf-id').hide();
      $('#edit-field-lsa-pecsf-charity-name').hide();
      $('#edit-field-lsa-donation-amount').hide();
      $('#edit-field-lsa-second-donation').hide();
      set_pecsef($("input[name='field_lsa_years_of_service[und]']:checked").val());
    });

    $("#edit-field-do-you-need-to-update-your").hide();
    $("#edit-field-specialrequirement-descrip").hide();
    $("#edit-field-accessibility").hide();
  });

  /** Helper function to set PECSEF options anv values
 *
 */
  function set_pecsef(year){
    // Show and open pecsf block
    if(year == 'none'){
      $('#pecsf-fields').slideUp('slow');
    } else {
      $('#pecsf-fields').slideDown('slow');
    }
    switch(true){
      case year == 25:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$75.00');
        break;
      case year == 30:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$150.00');
        break;
      case year == 35:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$300.00');
        break;
      case year == 40:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$400.00');
        break;
      case year == 45:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$450.00');
        break;
      case year == 50:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$500.00');
        break;
    }
  }

  /**
   * Here we need to make required fields required if specific options have been checked.
   */
  function checkPECSF(){
    // If we are on Donation Option B (choose donation charities) we must have these fields filled out
    if($('#edit-field-lsa-donation-options-und-1').is(":checked") && $('#edit-field-lsa-donation-options-und-1').is(":visible")){
      $('#edit-field-lsa-pecsf-id-und-0-value').prop("required", true);
      $('#edit-field-lsa-pecsf-charity-name-und-0-value').prop("required", true);
    } else {
      // If this is not chose, or user has chosen a different award - we no longer require these.
      $('#edit-field-lsa-pecsf-id-und-0-value').prop("required", false);
      $('#edit-field-lsa-pecsf-charity-name-und-0-value').prop("required", false);
    }
    if($('#edit-field-lsa-donation-options-und-0').is(":visible")){
      $("#edit-field-lsa-25year-certificatename-und-0-value").show();
      $('#edit-field-lsa-25year-certificatename').show();
      $("#edit-field-lsa-25year-certificatename-und-0-value").prop("required", true);
    } else {
      $("#edit-field-lsa-25year-certificatename-und-0-value").hide();
      $("#edit-field-lsa-25year-certificatename-und-0-value").prop("required", false);
    }
  }
})(jQuery);
