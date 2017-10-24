(function ($) {
  Drupal.behaviors.r2r_form = {
    attach: function (context, settings) { 
      // Only run if the link exists in the current page load or fragment refresh.
      // Note: this module requires the activiation of a block, and that you create a button or link with a specific ID in the ad space
      $('#r2r-form:not(.atwork-prem-awards-processed)', context)
        .addClass('atwork-prem-awards-processed')
        .bind('click', function (){
            // Create our Model.
            $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');            	
            setDialog();
            var form = buildForm(settings);
            $(form).appendTo('#modal-pop');
            // Edit button needs to be set / toggle renamed
            setClickHandlers();
          return false;
       });
      }
    };

  function setDialog(){
    dialog = $('#modal-pop').dialog({
      title: "Premier's Awards Webcast Registration",
      autoOpen: true,
      appendTo: "#block-atwork-activity-homepage",
      modal: true,
      opacity: 1,
      draggable: true,
      show: { effect: "blind", duration: 800 },
      buttons: {
        "Continue": submitR2RForm,
        Close: function(){
          // Remove any save/error messages that exist
          $('.error-message-r2r-form').remove();
          $('.save-confirmation-r2r-message').remove();
          dialog.dialog("destroy").remove();
        }
      },
      close: function () {
        dialog.dialog("destroy").remove();
      }
    });
    return;
  }

  function submitR2RForm(){
    var data = {};
    // TODO: build data array from fields you filled out in the form you popped.

    
    $.ajax({
      type: "POST",
      url: "/r2r/registration",
      dataType: 'json',
      success: ajaxCompleted,
      data: data,
    });
  }

  function ajaxCompleted(response){
    // TODO: Parse response and give feedback
    return;
  }

  function buildForm(settings){
    var name = settings.atwork_r2r.user;
    var ministry = settings.atwork_r2r.ministry;
    var email = settings.atwork_r2r.email;
    // reminder, this is an array, while all others are strings.
    var casts = settings.atwork_r2r.casts;
    var domPieces = setDomPieces(name, ministry, email, casts);
    return domPieces;
  }

  function setDomPieces(name, ministry, email, casts){
    // create a string that we can pass to the dom
    // TODO: future version will need to pull out the webcasts seperatly if there are more than one.
    var form = '<div id="r2r-form-div" class="r2r-form-div">' +
      '<p> Hello ' + name + ', please review that the information in the registration form below is correct. Make changes as necessary and then click the "Continue" button at the bottom of the form. </p>' +
      '<form>' + 
        '<fieldset class="fieldset-r2r">' +
          '<label for="webcast-r2r-webcast"> Live Stream: ' + casts['01'] + '</label>' +
          // For now this cannot be changed
          //'<input type="text" name="webcast-r2r-webcast" value="' + casts['01'] + '" class="r2r-input webcast-r2r-webcast" readonly>' +
          '<label for="webcast-r2r-name"> Name: ' + name + '</label>' +
          '<input type="text" name="webcast-r2r-name" value="' + name + '" class="r2r-input webcast-r2r-name">' +
          '<label for="webcast-r2r-ministry"> Ministry: ' + ministry + '</label>' +
          '<input type="text" name="webcast-r2r-ministry" value="' + ministry + '" class="r2r-input webcast-r2r-ministry">' +
          '<label for="webcast-r2r-email"> Email: ' + email + '</label>' +
          '<input type="text" name="webcast-r2r-email" value="' + email + '" class="r2r-input webcast-r2r-email">' +
        '</fieldset>'+
        '<input type="button" class="show-input-field" value="Edit">' +
      '</form>' +
      '</div>';
      return form;
  }

  function setClickHandlers(){
    if($('.show-input-field').hasClass('atwork-r2r-processed')){
      return;
    }
    $('.r2r-input').hide();
    $('.show-input-field')
      .addClass('atwork-r2r-processed')
      .bind('click', function(){
        $('.r2r-input').toggle();
    });
  }
})(jQuery);