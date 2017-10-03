(function ($) {
  Drupal.behaviors.prem_awards_form = {
    attach: function(context, settings) {
      // Fixing case where user name returns blank and creates a 500 (employee news case)
      if((settings.atwork_prem_awards.user.length < 1) && uid == 0 ){
        setting.atwork_prem_awards.user = 'Employee News';
      }
      // Only run if the link exists in the current page load or fragment refresh.
      // TODO: Create a button or link with a specific ID in the ad space
      $('#prem-awards-form:not(.atwork-prem-awards-processed)', context)
        .addClass('atwork-prem-awards-processed')
        .bind('click', function(){
          $.get('/p-awards/registration/' + settings.atwork_prem_awards.user + '/' + settings.atwork_prem_awards.uid, null, checkForm);
          return false;
       });
    }
  };

  var checkForm = function(response){
    var result = $.parseJSON(response);
    // Create a workable array of results
    // Print it all out in the dom
    printResults(result);
    // Now set click handlers for updating fields
    return false;
  };

  function printResults(items){
    // Need to generate some HTML here and pop a model
    var user_name = items.applicant;
    var formString = '';
    var i = 0;
    $.each(items, function(index, value) {
      console.log(value);
      i ++;
      if(index == 'applicant'){
        // skipping this one\
        return;
      } else {
      //console.log(index);
        formString += '<fieldset sid="' + index + '">';
        formString += '<label for="webcast-' + i + '">Webcast: ' + value.webcast + '</label>';
        // This should be hidden on initial form launch
        formString += '<input type="text" name="webcast-' + i + '" value="' + value.webcast + '" class="prem-award-input">';
        formString += '</fieldset>';
      }
    });

    $('#block-atwork-activity-homepage').append('<div id="modal-pop"></div>');

    $('<div id="premiers-awards-form" class="prem-awards-form-wrapper">' +
      '<p>Hello ' + user_name + ' our records indicate that you have pre-registered for the following webcast(s). Please make any required chagnes and confirm the registration information below.</p>'  +
      '<form>' +
          formString + 
        '</form>' +
      '</div>').appendTo('#modal-pop');
        
    setDialog();
    form = dialog.find("form").on("submit", function(event) {
      event.preventDefault();
      redirectSubmit();
    });
    

    return;
  }

  // This function submits results to php and then redirects
  function redirectSubmit(){
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
      close: function(){
        form[ 0 ].reset();
        allFields.removeClass("ui-state-error");
      }
    });
    return;
  }
})(jQuery);
