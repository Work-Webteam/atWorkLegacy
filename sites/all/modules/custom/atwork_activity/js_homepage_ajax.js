(function ($) {
  Drupal.behaviors.my_custom_module = {
    attach: function(context, settings) {
      currentTimeStamp = settings.atwork_activity.time;
      uid = settings.atwork_activity.uid;
      name = settings.atwork_activity.user;
      query = getUrlVars();
      // Settings does not seem to update the timestamp on reload - so we need to update that here through the most recent php span
      phpTimeStamp = $('#timestamp-latest').text();
      if(currentTimeStamp < phpTimeStamp){
        currentTimeStamp = phpTimeStamp;
      }
      // Only run if the link exists in the current page load or fragment refresh.
      $('#profile-comment-link:not(.atwork-activity-processed)', context)
        .addClass('atwork-activity-processed')
        .bind('click', function(){
          $.get('/atwork-activity/' + name + '/' + uid + '/' + currentTimeStamp + '/' + query.page, null, feedDetails);
          return false;
       });
    }
  };
  var currentTimeStamp = '';
  var uid = '';
  var name = '';
  var phpTimeStamp = '';
  var query = '';
  var feedDetails = function(response){
    //var result = $.parseJSON(response);
    //console.log(response);
    $('#ajax-target').html(response);
    return false;
  };

  // Read a page's GET URL variables and return them as an associative array.
  function getUrlVars(){
    var vars = [], hash;
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
  }
})(jQuery);
