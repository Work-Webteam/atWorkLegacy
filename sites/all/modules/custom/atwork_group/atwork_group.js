/**
 * Quick function to control the admin menu in groups - allows for accordian functionality.
 */
(function ($) {
  $( document ).ready(function(){
    $("#group-admin-block").click(function(){
        if($("#fieldset-admin-block").hasClass("collapsed")){
          $("#admin-list-accordian").slideToggle();
          $("#fieldset-admin-block").removeClass("collapsed");
        } else {
          // Wrap this in a function so we don't collapse before sliding
          $("#admin-list-accordian").slideToggle(function(){
            $("#fieldset-admin-block").addClass("collapsed");
          });
        }
    });
  });

}(jQuery));
