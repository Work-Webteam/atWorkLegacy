
(function ($) {
  // Global variable to check if we have already set this handler
  var clickHandlerSet = false;
  Drupal.behaviors.atwork_profiles = {
    attach: function (context, settings) {
      if(clickHandlerSet === false){
        $("#bio-toggle-button").mousedown(function () {
          var $this = $(this);
          if($this.data('expanded') == "yes"){
              $this.data('expanded',"no");
              $('#user-user-full-group-profile-extra').animate({height:'154px'});
              $('#bio-toggle-button').text("Show More");
          } else {
              $this.data('expanded',"yes");
              $('#user-user-full-group-profile-extra').css({height:'auto'});
              $('#bio-toggle-button').text("Show Less");
          }
        });
        clickHandlerSet = true;
      }
    }
  };
}(jQuery));
