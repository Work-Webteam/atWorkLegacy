(function ($) {

$(document).ready(function(){
    $('.jsNewActivityWindow').click(function() {
      // opens in new window to the far right of screen, on top and accounting for multiple monitors
      var customWindow = window.open(this.href, "customWindow", "scrollbars=1, width=305, height=950, top=0, left=9000");
      setTimeout(function(){window.blur();},500);
      setTimeout(function(){customWindow.focus();},1000);

      $(function() {
        // waits for dom to load and then scrolls all the way to the right.
        setTimeout(function() {
          $(customWindow.document).scrollLeft(2000);
        }, 10);

        customWindow.focus(); // focus, damn you
        // Hide admin wrapper here it is annoying
        setTimeout(function() {
          customWindow.$("#admin-menu-wrapper").hide();
        }, 1000);
        // Only allow N/S resizing
       setTimeout(function() {
         customWindow.resizable({
           handles: 'n,s',
           resize: function(event, ui) {
             ui.size.width = ui.originalSize.width;
           }
         });
       }, 1000);
      });
      return false;
    });
  });
}(jQuery));
