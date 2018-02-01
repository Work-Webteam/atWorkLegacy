/**
 * JQuery file that allows us to dynamically show and update forms for users who have not registered to watch the R2R. Also allows us to quickly redirect those who have.
 */
(function ($) {
  Drupal.behaviors.r2r_form = {
    attach: function (context, settings) { 
      // Settings we passed from atwork_r2r.module mimic an object here - so we can access them anywhere in this script.
      var localR2rSettings;
      $.noConflict();      
      Object.defineProperty(window, 'r2rSettings', {
        get: function(){
          return localR2rSettings;
        },
        set: function(val) {
          localR2rSettings = window.r2rSettings || val;
        } 
      });
      
      // Setter
      window.r2rSettings = settings.atwork_r2r;
      // Note: this module requires that you activate a block, and that you create a button or link with a specific ID in the ad space
      $('#r2r-form:not(.atwork-prem-awards-processed)', context)
        .addClass('atwork-prem-awards-processed')
        .bind('click', function (){
          // check for submissions and redirect if required
          $.get('/r2r/check', null, checkForm);
          $('#r2r-form').prop('disabled', true);
          $('#r2r-form').after('<div id="r2r-spinner" class="spinner"><div class="rect1"></div><div class="rect2"></div><div class="rect3"></div><div class="rect4"></div><div class="rect5"></div><div class="rect6"></div></div>');
          return false;
       });
      }
    };
  /**
   * 
   * @param {jSON} reply 
   */
  function checkForm(reply){
    var result = $.parseJSON(reply);
    if(result == false){
      $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');            	
      setDialog();
      // get settings
      var r2rSettings = window.r2rSettings;
      // Build form
      var form = buildForm(r2rSettings);
      $(form).appendTo('#modal-pop');
      // Edit button needs to be set / toggle renamed
      setClickHandlers();
      return;
    } else {
      // Already had an application, so redirect them
      window.open(result[2], '_blank');
      // Remove spinner and make button clickable again
      $('#r2r-form').prop('disabled', false);
      $('#r2r-spinner').remove();
      return;      
    }
  }

  /**
   * 
   */
  function setDialog(){
    dialog = $('#modal-pop').dialog({
      autoOpen: true,
      appendTo: "#block-atwork-activity-homepage",
      modal: true,
      opacity: 1,
      draggable: true,
      show: { effect: "blind", duration: 800 },
      buttons: {
        "Continue": function(){
          $(this).prop('disabled', true);
          submitR2RForm();
        },
        Close: function(){
          // Remove any save/error messages that exist
          $('.error-message-r2r-form').remove();
          $('.save-confirmation-r2r-message').remove();
          // Remove spinner and make button clickable again
          $('#r2r-form').prop('disabled', false);
          $('#r2r-spinner').remove();
          // Destroy dialog so we don't double up on fields/classes etc.
          dialog.dialog("destroy").remove();
        }
      },
      close: function () {
        // Remove any save/error messages that exist
        $('.error-message-r2r-form').remove();
        $('.save-confirmation-r2r-message').remove();
        // Remove spinner and make button clickable again
        $('#r2r-form').prop('disabled', false);
        $('#r2r-spinner').remove();
        dialog.dialog("destroy").remove();
      }
    });
    return;
  }

  /**
   * 
   */  
  function submitR2RForm(){
    var data = {};
    // build data array from fields you filled out in the form you popped.
    // TODO: Do we need to grab the uid from dom here?
    data.name = $(".webcast-r2r-name").val();
    data.ministry = $('.webcast-r2r-ministry').val();
    data.email = $('.webcast-r2r-email').val();
    // TODO - These require values
    data.attendance = window.r2rSettings.castId;
    data.session = window.r2rSettings.session;
    // This is static right now, passed from PHP 
    data.webcast =  window.r2rSettings.castName;
    $.ajax({
      type: "POST",
      url: "/r2r/registration",
      dataType: 'json',
      success: ajaxCompleted,
      data: data,
    });
  }

  /**
   * 
   * @param {jSon} response  // Only one value expected
   */
  function ajaxCompleted(response){
    // get settings
    var r2rSettings = window.r2rSettings;
    if(typeof response == 'undefined' || response != "200" ){
      // set error message, and keep form open
      // If we already have an error message, lets not double up 
      $('.error-message-r2r-form').remove();
      $('#modal-pop').append('<div class="error-message-r2r-form"> An error has occured, please try saving again. If this error persists, try refreshing the page or <a href="' + r2rSettings.redirect + '">click here</a> to go to the webcast without registering.</div>').slideDown('slow');

    } else {
      // set saved message, update labels and then delayed redirect.
      $('#modal-pop').append('<div class="save-confirmation-r2r-message"> Saved </div>');
      $('.r2r-input').toggle();
      setTimeout(function(){
        // Pull out our url for redirection
        var redirect = r2rSettings.redirect;
        window.open(redirect);
        // destroy dialog
        dialog.dialog("destroy").remove();      
        // Remove spinner and make button clickable again
        $('#r2r-form').prop('disabled', false);
        $('#r2r-spinner').remove();
      }, 3000);

    }
    return;
  }

  /**
   * 
   * @param {object} r2rSettings - holds list of variables passed from atwork_r2r.module
   */
  function buildForm(r2rSettings){
    var name = r2rSettings.user;
    var ministry = r2rSettings.ministry;
    var email = r2rSettings.email;
    // reminder, this is an array, while all others are strings.
    var cast = r2rSettings.castName;
    var session = r2rSettings.session;
    var domPieces = setDomPieces(name, ministry, email, cast, session);
    return domPieces;
  }

  /**
   * 
   * @param {string} name 
   * @param {string} ministry 
   * @param {string} email 
   * @param {string} castName
   * @param {string} session
   */
  function setDomPieces(name, ministry, email, castName, session){
    // create a string that we can pass to the dom
    // TODO: future version will need to pull out the webcasts seperatly if there are more than one.
    var form = '<div id="r2r-form-div" class="r2r-form-div">' +
      '<p> Hello ' + name + ', please review that the information in the registration form below is correct. Make changes as necessary and then click the "Continue" button at the bottom of the form. </p>' +
      '<form>' + 
        '<fieldset class="fieldset-r2r">' +
          // TODO - This casts should be dynamic - or perhaps pass up only current cast as designated by constant in PHP?
          '<label for="webcast-r2r-webcast" id="webcast-id-name-text"> Live Stream: ' + castName + '</label>' +
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

  /**
   * 
   */
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