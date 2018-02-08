(function($) {
  Drupal.behaviors.atworkHotkeys = {
    attach: function() {

      $('body').bind('keypress', function(e) {

        var keycode = (e.keyCode ? e.keyCode : e.which),
          searchbox = document.activeElement;

        if (searchbox.name == "search_block_form") {
          return;
        }

        if (keycode != 18 && keycode != 8 && keycode != 17 && keycode != 16) { // shift, alt, backspace

          switch(keycode) { // go to selected application
            case 97: // a
              window.location = "http://gww.cas.gov.bc.ca/";
              break;
            case 99:  // c
              window.location = "https://www.wheregreenideaswork.gov.bc.ca/smarttec.html";
              break;
            case 100: // d
              window.location = "http://www.dir.gov.bc.ca/";
              break;
            case 101: // e
              window.location = "https://chips.gov.bc.ca:7002/CHIPSBC/signon.html";
              break;
            case 102: // f
              window.location = "/forum";
              break;
            case 106: // j
              window.location = "https://search.employment.gov.bc.ca/cgi-bin/i/internal_mycenter.cgi";
              break;
            case 112: // p
              window.location = "http://www.gov.bc.ca/";
              break;
            case 115: // s
              window.location = "https://gww.gov.bc.ca/tools/online-store";
              break;
            case 116: // t
              window.location = "https://tol.gov.bc.ca/wfc/logonWithUID";
              break;
            case 104: // h
              window.location = "http://www2.gov.bc.ca/myhr/";
              break;
            case 103: // g
              window.location = "https://employee.gov.bc.ca/epm/";
              break;
            default:
              // alert(keycode); // for testing!
              return;
          }

        }

      });

    }

  };
})(jQuery);
