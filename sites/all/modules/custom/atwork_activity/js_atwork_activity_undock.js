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
      });
      return false;
    });
  });
}(jQuery));
