(function ($) {
  Drupal.behaviors.atwork_activity_undock = {
    attach: function(context, settings) {
      // Only run if the link exists in the current page load or fragment refresh.
      $('.jsNewActivityWindow:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          // opens in new window to the far right of screen, on top and accounting for multiple monitors
          var customWindow = window.open(this.href, "customWindow", "scrollbars=1, width=305, height=850");
          /*
          setTimeout(function(){
            if(!customWindow.focus){
              console.log("was not focus");
              setTimeout(customWindow.focus(), 1000);
              //setTimeout(function(){window.blur();},900);
            }
          }, 5002);
          */
        // waits for dom to load and then scrolls all the way to the right.
        setTimeout(function() {
          $(customWindow.document).scrollLeft(2000);
          $(customWindow.document).focus();
        }, 10);
          return false;
        });
    }
  };

}(jQuery));
