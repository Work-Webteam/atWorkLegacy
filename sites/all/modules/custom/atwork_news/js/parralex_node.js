(function ($) {
  // Global variable to check if we have already set this handler
  var clickHandlerSet = false;
  Drupal.behaviors.atwork_profiles = {
    attach: function (context, settings) {

      // Check position of the element we are passing in.
      function testInView($el){
        var wTop = $(window).scrollTop();
        var wBot = wTop + $(window).height();
        var wMid = wBot - ($(window).height()/2);
        var eTop = $el.offset().top;
        var eBot = eTop + $el.height();
        return ((eTop <= wMid) && (eBot >= wMid));
      }
      // Set our class to the most central div.
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
      // Show only most central div, and obfuscate others.
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

      // Check as we scroll - must debounce this or it computes way too many times,
      // slowing down the response.
      $(document).scroll($.debounce(250, function(){
        setInView();
      }));
      // If a user resizes a page, recheck locations.
      $(document).resize(function(){
        setInView();
      });
      // Initial load - set most central div as showing.
      $(document).ready(function(){
        setInView();
      });
    }
  };
}(jQuery));
