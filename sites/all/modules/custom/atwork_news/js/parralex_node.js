(function ($) {
  // Global variable to check if we have already set this handler
  var clickHandlerSet = false;
  Drupal.behaviors.atwork_profiles = {
    attach: function (context, settings) {

      function testInView($el){
        var wTop = $(window).scrollTop();
        var wBot = wTop + $(window).height();
        var wMid = wBot - ($(window).height()/2);
        var eTop = $el.offset().top;
        var eBot = eTop + $el.height();
        return ((eTop <= wMid) && (eBot >= wMid));
      }
      function setInView(){
        $(".story").each(function(){
          var $zis = $(this);
          $zis.removeClass("inview");
          if(testInView($zis)){
            $zis.addClass("inview");

          }
        });
        setOutView();
      }
      function setOutView(){
        $(".story").each(function(){
          var $zat = $(this);
          if($zat.hasClass("inview")) {
            $zat.fadeTo("fast", 1, function () {
              //Animation complete.
            });
          } else {
            $zat.fadeTo("fast", 0.5, function() {
              //Animation complete.
            });
          }
        });
      }

      $(document).scroll($.debounce(500, function(){
        setInView();
      }));
      $(document).resize(function(){
        setInView();

      });
      $(document).ready(function(){
        setInView();
      });
    }
  };
}(jQuery));
