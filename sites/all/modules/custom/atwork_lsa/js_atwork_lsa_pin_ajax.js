(function ($) {
  Drupal.behaviors.atwork_lsa_pin = {
    attach: function(context, settings) {
      console.log(settings);
      var type = "";
      // Only run if the link exists in the current page load or fragment refresh.
      $('#edit-field-lsa-registerer-und:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('change', function(){
          console.log("captured a change");
          type = $('#edit-field-lsa-registerer-und').val();
          console.log(type);
          $.get('/atwork_lsa_pin_form/' + type, null, feedDetails);
          return false;
       });
    }
  };
  var feedDetails = function(response){
    //var result = $.parseJSON(response);
    console.log(response);
    if(response.choice == 1){
      // Show fields
      // populate fields
      console.log(response.branch[0].safe_value);
      $('#edit-field-lsa-branch-department-und-0-value').val(response.branch[0].safe_value);
    } else if(response.choice == 2){

    } else if(response.choice == 3){

    } else {

    }
  };

})(jQuery);
