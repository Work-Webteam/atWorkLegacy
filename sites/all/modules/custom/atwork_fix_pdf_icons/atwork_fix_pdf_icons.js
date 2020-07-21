Drupal.behaviors.atwork_fix_pdf_icons = {
  attach: function (context, settings) {

    (function($) {

      // pdf icons
      $('a[href$=".pdf"]')
        .not(':has(img, .no-icon)')
        .each(function () {

          // icon is outside <a> tag
          if ($(this).next().is('img.pdf'))
            $(this).next('img').remove();

          // icon is placed outside <a> tag in souce
          if ($(this).has('img.pdf'))
            $(this).children('img.pdf').remove();

          $(this).addClass('pdf');
      });

      // word doc icons
      $('a[href$=".doc"], a[href$=".docx"]').not(':has(img)').each(function () { // was using actual classes on the images inside an <a> tag ending in ".doc(x)" such as: .imagecache-node_image, img.no-border but was easier to just select all images inside an <a> tag

        if ($(this).next().is('img'))
          $(this).next('img').remove();
        // this helps with legacy css TODO: fix this.

        $(this).addClass('word');

      });

    })(jQuery);

  } // attach
};
