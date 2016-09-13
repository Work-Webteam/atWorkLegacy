jQuery(document).ready(function($) {
  $(".wes-graph-container").click(function() {
    var thisId = '#' + $(this).parent().attr('id') + '-branches';
    var clicked = this;
    if ($('.wes-branches.selected').length ) {
      $('.wes-branches.selected').slideUp( "fast", function() {
        if (!$(clicked).hasClass('selected')) {
          $(thisId).slideDown();
          $('#wes-popup .selected').removeClass('selected');
    
          $(clicked).addClass('selected');
          $(thisId).addClass('selected');
        }
        else {
          $('#wes-popup .selected').removeClass('selected');
        }
      });
    }
    else {
      $(thisId).slideDown();
      $('#wes-popup .selected').removeClass('selected');

      $(this).addClass('selected');
      $(thisId).addClass('selected');
    }
    

    
    //console.log(thisId);
  });
});

