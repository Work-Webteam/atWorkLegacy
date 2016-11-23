
(function ($) {
  // Global variable to check if we have already set this handler
  var clickHandlerSet = false;

  Drupal.behaviors.atwork_profiles = {
    attach: function (context, settings) {
      if(clickHandlerSet === false){

        $("#clickmeplease").click(function () {
          var $this = $(this);
          console.log('yes, it loaded');
          if($this.data('expanded') == "yes"){
              $this.data('expanded',"no");
              $('#user-user-full-group-profile-extra').animate({height:'90px'});
          } else {
              $this.data('expanded',"yes");
              $('#user-user-full-group-profile-extra').css({height:'auto'});
          }
          clickHandlerSet = true;
        });
      }
    }
  };
}(jQuery));
