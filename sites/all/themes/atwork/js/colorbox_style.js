(function ($) {

Drupal.behaviors.initColorboxDefaultStyle = {
  attach: function (context, settings) {
    $(document).bind('cbox_complete', function () {
      // Only run if there is a title.
      if ($('#cboxTitle:empty', context).length == false) {
        //$('#cboxToggle').remove();
        var isIframe = false;
        if ($('#cboxLoadedContent iframe').length) {
          isIframe = true;
        }
        
        var caption = $('#cboxTitle').html();
        if ($('#atworkCaption').length) {
          var caption = $('#atworkCaption').html();
          $('#cboxTitle').html('');
        }
        
        if (isIframe && caption) {
          var colorboxHeight = $('#colorbox').height();
          var titleHeight = $('#cboxTitle').height();
          
          if (titleHeight > 200) {
            titleHeight = 200;
            $('#cboxTitle').css('overflow-y', 'scroll');
          }
          
          $('#cboxContent').css('height', 'auto');
          $('#cboxWrapper').css('height', 'auto');
          $('#cboxTitle').css('position', 'relative');
          $('#cboxTitle').css('height', titleHeight + 'px');
          $('#colorbox').css('height', (colorboxHeight + titleHeight + 20) + 'px');
          $('#colorbox').css('top', '10px');
        }
        else if (caption) {
          $('#cboxContent', context).prepend('<div id="cboxToggle">Caption On</div>');
          $('#cboxTitle').html('<div id="atworkCaption" style="height:auto; width:100%;"></div>');
          $('#atworkCaption').html(caption);
        }
        
        $('#cboxToggle').on("click", function() {
          if (!isIframe) {
            $('#cboxTitle', context).slideToggle(400, function () {
              if ($('#cboxTitle', context).is(":visible")) {
                $('#cboxToggle').text('Caption On', context);
              }
              else {
                $('#cboxToggle').text('Caption Off', context);
              }
            });
          }
        });
      }
      else {
        $('#cboxTitle', context).hide();
      }
    });
    $(document).bind('cbox_cleanup', function () {
      // Only run if there is a title.
      $('#cboxToggle').remove();
      $('#atworkCaption').remove();
    });
  }
};

})(jQuery);
