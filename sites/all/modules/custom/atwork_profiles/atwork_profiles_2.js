
(function ($) {
  // Global variable to check if we have already set this handler
  var clickHandlerSet = false;
  Drupal.behaviors.atwork_profiles = {
    attach: function (context, settings) { 
      
      if ($('#user-user-full-group-profile-extra').height() > 70) {
        // if there's more to show, show at least 3 lines and the more button
        $('#user-user-full-group-profile-extra').css({height:'140'});
        if(clickHandlerSet === false){
          $("#bio-toggle-button").mousedown(function () {
              var $this = $(this);
              if($this.data('expanded') == "yes"){
                  $this.data('expanded',"no");
                  $('#user-user-full-group-profile-extra').animate({height:'140px'});
                  $('#bio-toggle-button').text("Show More");
              } else {
                  $this.data('expanded',"yes");
                  // fetch the DOM Element auto height from the jQuery Element by calling get(0)
                  $("#user-user-full-group-profile-extra").animate({height: $("#user-user-full-group-profile-extra").get(0).scrollHeight}, 500 );
                  $('#bio-toggle-button').text("Show Less");
              }         
          });
          clickHandlerSet = true;
        }
      } else {
        // otherwise hide the button because section is empty
        $('#bio-toggle-button').hide();
      }   
    }
  };
}(jQuery));


