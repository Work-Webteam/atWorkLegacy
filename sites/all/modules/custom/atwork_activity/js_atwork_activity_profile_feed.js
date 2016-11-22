(function ($) {

  /**
   * Global variables so that we don't lose them on refresh
   */
  $( document ).ajaxStart(function(){
    $(".form-textarea").prop("disabled", true);
    $(".form-textarea").prop("readonly", true);
    //$("#edit-status").prop("disabled", true);
    $(".form-textarea").prop("value", "refreshing feed");
  });

  $( document ).ajaxStop(function(){
    $(".form-textarea").prop("disabled", false);
    $(".form-textarea").prop("readonly", false);
  });

  // Start with false so that we can tell if it is set or not.
  var refreshFeed = false;
  var timer = false;
  var stateSave = Array();

  /**
   * Drupal attach function - click handlers etc.
   */
  Drupal.behaviors.profileFeedJquery = {
    attach: function (context, settings) {
    // Page refresh should occur every 5 seconds after initial load
    if(refreshFeed === false && timer=== false){ // Don't want to set this twice
      setFeedInterval();
    }

    //Unless someone is typing in a text field
    $(".form-textarea").click(function(){
      slow_var();
    });

    // Initialize/take care of comments
    setComments();

    // click handler for the comment toggle function
    $(".comment-count-link").click(function(){
      toggleComments($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
    });

    $("[id^=edit-button").click(function(){
      //TODO - figure out how to replace the div with a spinner.
      //TODO - find out why we have a second box appearing when we submit
      // Remove text blocks and show that it is saving
      $('[id^="field-profile-comment-add-more-wrapper"').replaceWith('<div><p id="saving-notification"> SAVING </p></div>');
      // Refresh the page to make it dynamic
      refreshPage();
      setComments();
      //refresh interval and remove timer if present
      resetTimer();
      return;
    });

    /**
     * Function that allows us to set links, show page the way we would like to at initial refresh
     */
    function setComments(){
      // On initial load we want to check if our array has any items or not (if not, then this is the very first load and not a reload)
      // Have not loaded this page yet, or everything was left closed
      if(stateSave.length < 1){
        $.each($(".replies"), function(){
          // Hide all but the last link
          $(this).find(".reply").not(":last").hide();
          // Find out how many comments we have in this block
          var i = $(this).find($(".reply")).length;
                  // If we don't have one yet, lets append it to this block.
          $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments(' + i + ')</a></div>');
          //Grab the class of this message so we can remember its state
          var y = ($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
          stateSave.push(y);
        });
      } else {
        $.each($(".replies"), function(){
          // Don't want to double up on the comment links
          if($(this).find(".comment-count-link").length > 0){
            var j = $(this).find($(".reply")).length;
            // Check if our j value is still relevant here
            var comments = $(this).find("a.comment-count-link-text").text();
            var commentNumber = comments.split("(");
            var commentInt = commentNumber[1].split(")");
            if(commentInt === j){
              return;
            } else {
              // TODO - update comment number link
            }
            return;
          } else {
            // Rebuild the comments link if it does not exist
            var k = $(this).find($(".reply")).length;
            $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments(' + k + ')</a></div>');
          }
        });

        // If we have saved state, we need to deal with it here and either hide or leave comments open
        if(stateSave.length > 0){
          $.each($(".replies"), function(){
            var x = ($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
            // Not inArray is returned as a -1, 0 is a spot in the array, but will return as false in an if statement. Need to explicitly check for -1.
            var test = ($.inArray(x, stateSave));
            if($.inArray(x, stateSave) !== -1){
              // If it is here, it is hidden
              $(this).find(".reply").not(":last").hide();
            } else {
              // leave it alone
              return;
            }
          });

        }
      }
    }

    /**
     * Function that will allow us to hide all but the last comment, and also create a counted comment link
     * classDiv is the class of the div holding the replies that the user clicked the link for.
     */
    function toggleComments(classDiv){
      //Get rid of the spaces, so we can use this as a selector
      divClass = classDiv.split(' ').join('.');
      // Nothing is hidden right now, so add this to the list and hide it
      if(stateSave.length < 1){
        // comment counter for link.
        var $i = 0;
        $.each($(".replies"), function(){
          // Hide all but the last link
          $(this).find(".reply").not(":last").slideUp("fast");
          // Find out how many comments we have in this block
          $i = $(this).find($(".reply")).length;
          // Don't want to double up on the comment links
          stateSave.push(classDiv);
          if($(this).find($(".comment-count-link")).length > 0){
            // TODO - check if count is accurate
            return;
          }
          // If we don't have one yet, lets append it to this block.
          $(this).append('<div class="comment-count-link"><a href="#/">Comments(' + $i + ')</a></div>');
        });
      } else {
        // We have something in our array, so lets see if this is supposed to be closed or open.
        var arraySpot = $.inArray(classDiv, stateSave);
        if(arraySpot !== -1){
          // If it is in our array, it has been closed, and now should be opened - toggle open
          $("." + divClass).find(".replies").find(".reply").not(":last").slideDown("fast");
          //and remove it from the array
          stateSave.splice(arraySpot, 1);
        } else {
         // If it is not in our array, it is opened and should be closed, toggle closed
        $("." + divClass).find(".replies").find(".reply").not(":last").slideUp("fast");
       // and add to array
       stateSave.push(classDiv);
        }
      }
      return;
    }

    /**
     * Function that refreshes the profile feed via manual block refresh link
     */
    function refreshPage(){
      // Refresh the block with the link generated by the bock_refresh module
      $('.block-refresh-button').first().click();
      return;
    }

    /**
     * Function that stops all refreshes for 10 minutes if someone clicks in a text box, then restarts them
     */
    function slow_var(){
      if(refreshFeed !== false){
        clearInterval(refreshFeed);
        refreshFeed = false;
      }
      // If nothing happens in 5 minutes, we will start our refresh again
      if(timer === false){
        timer = setTimeout(setFeedInterval, 300000);
      }
      return;
    }

    /**
     * Function in charge of setting the interval to the value we would like
     */
    function setFeedInterval(){
      if(refreshFeed === false){
        refreshFeed = setInterval(refreshPage, 20000);
      }
      // Make sure our timer is turned off
      if(timer !== false){
        clearTimeout(timer);
        timer = false;
      }
      return;
    }

    /**
     * Function to clear timer if any form is submitted on the profile feed
     */
    function resetTimer(){
      // Lets clear the interval here, as we are reseting the timer anyways
      clearInterval(refreshFeed);
      refreshFeed = false;
      setFeedInterval();
      return;
    }
   }
  };

}(jQuery));


