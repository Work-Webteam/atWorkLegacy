(function ($) {

  // Close all shown buttons save on click

  function close_button(){
      // At this point, the modules css hides the button after we click it, so no need to do it ourselves.
  }



  // Open relevant button when its text field is clicked
  function open_button(event){
    if(!event){
      event = $(window.event);
    }
    // Check what was clicked
    var target = $(event.target) || $(event.srcElement);

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
        //console.log(err);
      }
    }
    //console.log(target);

    if (target.is("input#edit-field-lsa-home-phone-und-0-value") || target.is("input#edit-field-lsa-work-phone-und-0-value")){
      try {
        target.parent().parent().parent().next().children().css("display","block");
      }
      catch(err){
        //console.log(err);
      }
    }

    // If anything has changed, we should re-run settings()
    settings();
  }

  function settings(){
    // Deciding which fields should be visible to user on initial load

    // If they are not retiring this year, no need to have a field to enter a retirement date.
    var retired = $(".field.field-name-field-lsa-retiring-thisyear.field-type-list-boolean.field-label-inline.clearfix div.field-item").text();

    if (retired == "No"){
      $(".field.field-name-field-lsa-retiring-thisyear").hide();
      $("div.field.field-name-field-lsa-date-of-retirement").hide();
    }

    var years_of_service = $(".field.field-name-field-lsa-years-of-service.field-type-list-integer.field-label-inline.clearfix div.field-items div.field-item").text();

    // Do they get a certificate?
    if(years_of_service != "25"){
      $("div.field.field-name-field-lsa-25year-certificatename").hide();
    }

    var award = $(".field.field-name-field-lsa-award.field-type-text.field-label-inline.clearfix").text();

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
        $('.field.field-name-field-specialrequirement-descrip div.field-label').hide();
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
        $('.field.field-name-field-specialrequirement-descrip div.field-label').text('Please tell us more about your food allergy, and other requirements.');
        $('.field.field-name-field-specialrequirement-descrip div.field-label').show();
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
        $('.field.field-name-field-specialrequirement-descrip div.field-label').html('Please tell us more about your food allergy.');
        $('.field.field-name-field-specialrequirement-descrip div.field-label').show();

        return;
      }
      if($("#edit-field-lsa-specialrequirements-und-1").prop('checked') === false && $("#edit-field-lsa-specialrequirements-und-5").prop('checked') === true){
        // Other only
        // Show special requirements text box
        $('#edit-field-specialrequirement-descrip').show();
        // Required
        $('#edit-field-specialrequirement-descript-und-0-value').prop('required', true);
        // Change help prompt text
        $('.field.field-name-field-specialrequirement-descrip div.field-label').html('Please tell us more about your requirements.');
        $('.field.field-name-field-specialrequirement-descrip div.field-label').show();
        return;
      }
      if($("#edit-field-lsa-specialrequirements-und-1").prop('checked') === false && $("#edit-field-lsa-specialrequirements-und-5").prop('checked') === false){
        // Hide special requirements box
        $('#edit-field-specialrequirement-descrip').hide();
        // Clear the special requirements box
        $('#edit-field-specialrequirement-descrip-und-0-value').val('');
        // No longer required
        $('#edit-field-specialrequirement-descript-und-0-value').prop('required', false);
        $('.field.field-name-field-specialrequirement-descrip div.field-label').hide();

        return;
      }

      $('.field.field-name-field-specialrequirement-descrip div.field-label').hide();

    });

  }


/**
 * Main function, various click handlers/event listener.
 *
 */
  $(document).ready(function(){
    close_button();
    settings();

    document.body.addEventListener('click', open_button, true);

  });
})(jQuery);
