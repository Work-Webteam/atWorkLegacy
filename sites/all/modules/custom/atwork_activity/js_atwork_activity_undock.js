(function ($) {
  Drupal.behaviors.atwork_activity_undock = {
    attach: function(context) {
      // Change hover-over title if in activity feed popup window.
      if($('body').hasClass('not-front')) {
        $('#ActivityWindowButton').attr("title", "Close Activity Window");
      }
      // Only run if the link exists in the current page load or fragment refresh.
      $('.jsNewActivityWindow:not(.atwork-activity-processed)', context)
      .addClass('atwork-activity-processed')
      .bind('click', function(){
        // Close window if in activity feed popup window.
        if($('body').hasClass('not-front')) {
          window.close();
        } else {
          // opens in new window to the far right of screen, on top and accounting for multiple monitors
          const customWindow = window.open(this.href, "customWindow", "scrollbars=1, width=305, height=850");
          // waits for dom to load and then scrolls all the way to the right.
          setTimeout(function() {
            $(customWindow.document).scrollLeft(2000);
            $(customWindow.document).focus();
            }, 10);
          return false;
        }
      });
    }
  };

}(jQuery));
