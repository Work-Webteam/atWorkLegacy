//GALLERY THUMBS
(function ($) {
  Drupal.behaviors.galleryPagerFix = {
    attach: function (context, settings) {
      // We need to save the page we are on in Galleries, or the pager attached to the side keeps resetting to page=0
      // Build our URL from browser
      var newURL = window.location.protocol + "//" + window.location.host + "/" + window.location.pathname;
      // Split into chunks
      var pathArray = window.location.pathname.split( '/' );
      // Make sure we are on the correct page
      if($(pathArray).length >= 4 && pathArray[3] == 'gallery'){
        var match = RegExp('[?&]' + 'page' + '=([^&]*)').exec(window.location.search);
        // Capture our page number
        var galPg = match && decodeURIComponent(match[1].replace(/\+/g, ' '));
        if(galPg !== null) {
          // Add page query string on every image, so clicking will pass it in the URL
          $('.views-field-field-image a').each(function() {
            var $this = $(this);
            href = $this.attr('href');
            $this.attr('href', href +'?page='+ galPg);
          });
        }
      }
    }
  };
}(jQuery));
