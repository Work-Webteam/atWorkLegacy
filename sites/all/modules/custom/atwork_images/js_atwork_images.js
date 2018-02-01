//GALLERY THUMBS
(function ($) {
  Drupal.behaviors.galleryPagerFix = {
    attach: function (context, settings) {
      $('.pager li:not(.atwork-activity-processed)', context).addClass('atwork-activity-processed');
      console.log("attached");
      var newURL = window.location.protocol + "//" + window.location.host + "/" + window.location.pathname;
      var pathArray = window.location.pathname.split( '/' );
      if(pathArray[3] == 'gallery'){
        var match = RegExp('[?&]' + 'page' + '=([^&]*)').exec(window.location.search);
        var galPg = match && decodeURIComponent(match[1].replace(/\+/g, ' '));
        if(galPg == null) {
          galPg = 0;
        }
        console.log(galPg);
        $('.views-field-field-image a').each(function() {
          var $this = $(this);
          console.log($this);
          href = $this.attr('href');
          $this.attr('href', href +'?page='+ galPg);
          console.log($this);
        });
      }
    }
  }
}(jQuery));
