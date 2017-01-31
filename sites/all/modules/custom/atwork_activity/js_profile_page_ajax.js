(function ($) {
  Drupal.behaviors.my_custom_module = {
    attach: function(context, settings) {
      currentTimeStamp = settings.atwork_activity.time;
      uid = settings.atwork_activity.uid;
      name = settings.atwork_activity.user;
      console.log(settings.atwork_activity);
      // Settings does not seem to update the timestamp on reload - so we need to update that here through the most recent php span
      phpTimeStamp = $('#timestamp-latest').text();
      if(currentTimeStamp < phpTimeStamp){
        currentTimeStamp = phpTimeStamp;
      }
      // Only run if the link exists in the current page load or fragment refresh.
      $('#profile-comment-link:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          $.get('/noodle/' + name + '/' + uid + '/' + currentTimeStamp, null, feedDetails);
          return false;
        });

      console.log(phpTimeStamp);
    }
  };
  var currentTimeStamp = '';
  var uid = '';
  var name = '';
  var phpTimeStamp = '';


  var feedDetails = function(response){
    //var result = $.parseJSON(response);
    $('#ajax-target').html(response);

  };
})(jQuery);


