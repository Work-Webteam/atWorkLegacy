(function ($) {

  $( document ).ready(function(){
    $("#admin-list-accordian").hide();
    $("#group-admin-block").click(function(){
      $("#admin-list-accordian").slideToggle();
    });
  });

}(jQuery));
