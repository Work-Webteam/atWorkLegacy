(function ($) {
  Drupal.behaviors.atwork_activity_undock = {
    attach: function(context, settings) {
      // Only run if the link exists in the current page load or fragment refresh.
      $('.jsNewActivityWindow:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          // opens in new window to the far right of screen, on top and accounting for multiple monitors
          var customWindow = window.open(this.href, "customWindow", "scrollbars=1, width=300, height=850, top=0, left=9000");
          setTimeout(function(){window.blur();},1000);
          setTimeout(function(){customWindow.focus();},1200);
          setTimeout(function(){window.blur();},1250);
          setTimeout(function(){customWindow.focus();},1350);


          if(window.focus){
            setTimeout(customWindow.focus(), 2500);
          }
        // waits for dom to load and then scrolls all the way to the right.
        setTimeout(function() {
          $(customWindow.document).scrollLeft(500);
        }, 10);
          return false;
        });
    }
  };

}(jQuery));
