(function ($) {
  Drupal.behaviors.my_custom_module = {
    attach: function(context, settings) {
      currentTimeStamp = settings.atwork_activity.time;
      uid = settings.atwork_activity.uid;
      name = settings.atwork_activity.user;
      // Only run if the link exists in the current page load or fragment refresh.
      $('#my-special-link:not(.atwork-activity-processed)', context)
        .addClass('mymodule-processed')
        .bind('click', function(){
          $.get('/noodle/' + name + '/' + uid + '/' + currentTimeStamp, null, feedDetails);
          return false;
        });
    }
  };
  var currentTimeStamp = '';
  var uid = '';
  var name = '';

  var feedDetails = function(response){
    //var result = $.parseJSON(response);
    $('#ajax-target').html(response);
  };
})(jQuery);


