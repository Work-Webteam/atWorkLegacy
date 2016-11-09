
(function ($) {
  Drupal.behaviors.atwork_profiles = {
    attach: function (context, settings) {
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
    });
    }
  };
}(jQuery));
