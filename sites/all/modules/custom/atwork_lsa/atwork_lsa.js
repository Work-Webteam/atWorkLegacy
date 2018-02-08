(function ($) {


/**
 * This function handles various form messages and elements, determining when they should be seen.
 * All elements and messages are created in set_form() function below
 *
 */
  function lsaGift() {

    if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 1){
      $('#edit-field-lsa-award-und-0-value').val("2016 Recipient - award received");
      $('#edit-field-lsa-award-id-und-0-value').val(1);
    }
    // Always reset textbox when this value changes, so that we don't have a mis-match between award and years of service
    if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 2 && $('input[name="field_lsa_years_of_service[und]"]:checked').val() <= 40) {
      $("#edit-field-lsa-award-id-und-0-value").val('');
      //$('#edit-field-lsa-award-und-0-value').val('');
      $('#edit-field-lsa-award-und-0-value').hide();
      $('.form-item.form-type-textfield.form-item-field-lsa-award-und-0-value').hide();


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
    }
    if(gift_year_choice != 35){
      $('#edit-field-lsa-engravement-und-0-value').val('');
      $('#edit-field-lsa-engravement-und-0-value').hide();
      $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').hide();
    }

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
    var lost_gift = $('<div id="lost_gift_message"><span style="color:red "> *Please take time to send a quick <a href="mailto:LongServiceAwards@gov.bc.ca?subject=LSA%202015%20information%20request">email</a> to the Long Service Awards team</span></div>');
    $('#edit-field-lsa-received-award').append(lost_gift);
    $('#lost_gift_message').hide();
    // Message for recipients who have completed 45 || 50 years
    var special_gift = $('<div id="special_gift"><span style="color:red;"><strong>*</strong> For the tremendous achievement of your years of service, an LSA team member will connect with you personally to discuss award options that will be most meaningful to you. You will be contacted in May/June by our giftware representative.</span></div>');
    $('#edit-field-lsa-years-of-service').append(special_gift);
    $('#special_gift').hide();

    // Setting award text box - will not be useable by applicant
    $('#edit-field-lsa-award-und-0-value').hide();
    $('.form-item.form-type-textfield.form-item-field-lsa-award-und-0-value').hide();
    $('#edit-field-lsa-award-und-0-value').prop("readonly", true);
    $('#edit-field-lsa-award-und-0-value').css('background-color' , '#DEDEDE');

    // Setting engravement text box - will no be useable by applicant
    $('#edit-field-lsa-engravement-und-0-value').hide();
    $('#edit-field-lsa-engravement-und-0-value').prop("readonly", true);
    $('#edit-field-lsa-engravement-und-0-value').css('background-color' , '#DEDEDE');
    $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').hide();

    // 25 year certificate box will only be used by 25 year recipients
    //$('#field-lsa-25year-certificatename-add-more-wrapper').hide();

    // There will be no instructions unless we actually are choosing an award
    $('#edit-field-lsa-award-sp-instructions').hide();
    // Hide the special requirements box unless we require it
    $('#edit-field-specialrequirement-descrip').hide();
    // Hide PECSF unless user selects this choice
    $('#pecsf-fields').hide();
    // Change text for pecsf options (too long for text box in setup)
    $("label[for=edit-field-lsa-donation-options-und-0]").html('Option A: Make a PECSF donation to the <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity">fund supported pool of charities in my region</a>.');
    $("label[for=edit-field-lsa-donation-options-und-1]").html('Option B: Make a PECSF donation to one or two charities of my choice. (Find the PECSF ID number for your choice(s) by reviewing the <a href="https://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions">charity list by region</a>.)');
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
  }

/**
 * Helper function to decide when whe need special requirements text box - to set it to required - and to change label instructions
 */
  function special_requirements(){
    var checked_boxes = $('.form-checkbox');
    $(checked_boxes).each(function() {
      // None can only be checked if nothing else is
      if($("#edit-field-lsa-specialrequirements-und-6").prop('checked') === true) {
        $("#edit-field-lsa-specialrequirements-und-5").prop('checked',false);
        $("#edit-field-lsa-specialrequirements-und-5").prop('disabled', true);
        $("#edit-field-lsa-specialrequirements-und-4").prop('checked',false);
        $("#edit-field-lsa-specialrequirements-und-4").prop('disabled',true);
        $("#edit-field-lsa-specialrequirements-und-3").prop('checked',false);
        $("#edit-field-lsa-specialrequirements-und-3").prop('disabled',true);
        $("#edit-field-lsa-specialrequirements-und-2").prop('checked',false);
        $("#edit-field-lsa-specialrequirements-und-2").prop('disabled',true);
        $("#edit-field-lsa-specialrequirements-und-1").prop('checked',false);
        $("#edit-field-lsa-specialrequirements-und-1").prop('disabled',true);
        $('#edit-field-specialrequirement-descrip-und-0-value').val("");
      } else {
        $("#edit-field-lsa-specialrequirements-und-5").prop('disabled', false);
        $("#edit-field-lsa-specialrequirements-und-4").prop('disabled',false);
        $("#edit-field-lsa-specialrequirements-und-3").prop('disabled',false);
        $("#edit-field-lsa-specialrequirements-und-2").prop('disabled',false);
        $("#edit-field-lsa-specialrequirements-und-1").prop('disabled',false);
      }

      if($("#edit-field-lsa-specialrequirements-und-1").prop('checked') === true && $("#edit-field-lsa-specialrequirements-und-5").prop('checked') === true){
        // We have an allergy and other box checked
        // Show special requirements text box
        $('#edit-field-specialrequirement-descrip').show();
        //  Change the help prompt text
        $("label[for=edit-field-specialrequirement-descrip-und-0-value]").html('Please tell us more about your food allergy, and other requirements.');
        //  This is now required
        $('#edit-field-specialrequirement-descript-und-0-value').prop('required', true);

        return;
      }
      if($("#edit-field-lsa-specialrequirements-und-1").prop('checked') === true && $("#edit-field-lsa-specialrequirements-und-5").prop('checked') === false){
        // Allergies only
        // Show special requirements text box
        $('#edit-field-specialrequirement-descrip').show();
        // Required
        $('#edit-field-specialrequirement-descript-und-0-value').prop('required', true);
        // Change help prompt text
        $("label[for=edit-field-specialrequirement-descrip-und-0-value]").html('Please tell us more about your food allergy.');


        return;
      }
      if($("#edit-field-lsa-specialrequirements-und-1").prop('checked') === false && $("#edit-field-lsa-specialrequirements-und-5").prop('checked') === true){
        // Other only
        // Show special requirements text box
        $('#edit-field-specialrequirement-descrip').show();
        // Required
        $('#edit-field-specialrequirement-descript-und-0-value').prop('required', true);
        // Change help prompt text
        $("label[for=edit-field-specialrequirement-descrip-und-0-value]").html('Please tell us more about your requirements.');


        return;
      }
      if($("#edit-field-lsa-specialrequirements-und-1").prop('checked') === false && $("#edit-field-lsa-specialrequirements-und-5").prop('checked') === false){
        // Hide special requirements box
        $('#edit-field-specialrequirement-descrip').hide();
        // Clear the special requirements box
        $('#edit-field-specialrequirement-descrip-und-0-value').val('');
        // No longer required
        $('#edit-field-specialrequirement-descript-und-0-value').prop('required', false);
        return;
      }

    });

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
  }


/**
 * Main function, various click handlers.
 *
 */
  $(document).ready(function(){
    //jQuery.error = console.error;
    set_form();
    lsaGift();

    $('#edit-field-lsa-register-last-year-und').change(function () {
      lsaGift();
      change_award_year();
      certificate_populate();

    });

    $('#edit-field-lsa-years-of-service').change(function () {
      lsaGift();
      certificate_populate();
    });

    $('#edit-field-lsa-received-award').change(function () {
      lsaGift();
    });

    $('#edit-field-lsa-retiring-thisyear-und').change(function () {
      retirement();
    });


    // Click handler for special requirements
    $('.form-checkbox').change(function(){
      special_requirements();
    });

    $('#edit-field-lsa-home-phone-und-0-value').keyup(function(){
      phone_fix();
    });

    $('#edit-field-lsa-work-phone-und-0-value').keyup(function(){
      phone_fix();
    });

    $('#edit-submit').click(function(){
      certificate_populate();
    });

    // PECSF donation settings
    $('#edit-field-lsa-second-donation-und-1').on('click', function(){
      // User has decided to split their donation, we need to alter amounts
      if($('#edit-field-lsa-second-donation-und-1').prop("checked", true)){
        // Grab existing value
        amount = $('#edit-field-lsa-donation-amount-und-0-value').val();
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
<<<<<<< HEAD
=======

      // Also reset form fields so we don't get strange data
>>>>>>> LSA-11-test-and-fix-pecsf-donation-amoun
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

    // Handle choice A in PECSF form
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

  });

  /** Helper function to set PECSEF options anv values
 *
 */
  function set_pecsef(year){
    // Show and open pecsf block
    $('#pecsf-fields').slideDown('slow');
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
})(jQuery);
