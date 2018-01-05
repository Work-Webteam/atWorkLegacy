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
  });
  
  var i = 1;
  $("#ministry-top-three .wes-bar").each(function() {
    var percent = $(this).parent().siblings(".percent").text();
    var max_width = $(this).parent().width();
    var wesbar_width = (max_width * percent) / 100; 
    $(this).delay(200*i).animate({width: wesbar_width}, 500);
    i++;
  }); 
});

