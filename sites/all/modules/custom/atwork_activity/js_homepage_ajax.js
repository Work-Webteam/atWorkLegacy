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

      // Fixing case where user name returns blank and creates a 500 (employee news case)
      if((name.length < 1) && uid == 0 ){
        name = 'Employee News';
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
  var newMessage = false;
  var feedDetails = function(response){
    var result = $.parseJSON(response);

    // See if we already have had messages outstanding
    var prevNumber = $('#message-count-number').text();
    console.log(prevNumber);
    //  If we previously had a message
    if(prevNumber.length > 0){
      // See if our new number is more than previously - aka has there been a change since the last ajax check
      if(result[1] > prevNumber){
        console.log("New number is larger");
        // If it is, then show the message
        newMessage = true;
      }
    }

    // Get class of message-counter 
    var currentClass = $('#message-counter').attr('class');
    // If we have previously had no new messages, and now have more than 0, add message.
    if( currentClass == "no-new-messages" && result[1] > 0){
      console.log("Net new");
      newMessage = true;
    }
    // Add the result div to the current div ajax-target.
    $('#ajax-target').html(result[0]);
    // We have new messages - alert reader
    if(newMessage === true){
      // See if the div exists already - if so we just have to manipulate it.
      var checkForDiv = $('#notification-pop').text();
      // We already have the div and don't want another
      if(checkForDiv.length > 0){
        $('#notification-pop').slideToggle("fast").delay(3000).slideToggle("slow");
        newMessage = false;
      } else {
        var $message = $('<div class="announce-pop" id="notification-pop">New Messages</div>').hide();
        $('#message-counter').after($message);
        $('#notification-pop').slideToggle("fast").delay(3000).slideToggle("slow");
        newMessage = false;
      }
    }
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
