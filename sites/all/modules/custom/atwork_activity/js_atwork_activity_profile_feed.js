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
          if($(this).find(".comment-count-link").length === 0 && i > 1){
            $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments(' + i + ')</a></div>');
          }
        });
      } else if (stateSave.length > 0){
        // If we have saved state, we need to deal with it here and either hide or leave comments open
        $.each($(".replies"), function(){
          var x = ($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
          // Not inArray is returned as a -1, 0 is a spot in the array, but will return as false in an if statement. Need to explicitly check for -1.
          if($.inArray(x, stateSave) !== -1){
            // If it is here, it should be shown
          } else {
            // hide it
           $(this).find(".reply").not(":last").hide();
          }
          // If we don't have one yet, lets append it to this block.
          var k = $(this).find($(".reply")).length;

          if($(this).find(".comment-count-link").length === 0 && k > 1){
            $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments(' + k + ')</a></div>');
          }
        });
      }
      return;
    }

    /**
     * Function that will allow us to hide all but the last comment, and also create a counted comment link
     * classDiv is the class of the div holding the replies that the user clicked the link for.
     */
    function toggleComments(classDiv){
      //Get rid of the spaces, so we can use this as a selector
      divClass = classDiv.split(' ').join('.');
      // There is nothing in the array, so this needs to be opened and added to array.
     if(stateSave.length > 0){
        // We have something in our array, so lets see if this is supposed to be closed or open.
        var arraySpot = $.inArray(classDiv, stateSave);
        if(arraySpot === -1){
          // If it is not in our array, it has been closed, and now should be opened - toggle open
          $("." + divClass).find(".replies").find(".reply").not(":last").slideDown("fast");
          //and add it to the array
          stateSave.push(classDiv);
        } else {
           // If it is in our array, it is opened and should be closed
          $("." + divClass).find(".replies").find(".reply").not(":last").slideUp("fast");
          // and removed from the array
          stateSave.splice(arraySpot, 1);
        }
      } else {
        // Everything is closed, and this is the first opened comment
        $("." + divClass).find(".replies").find(".reply").not(":last").slideDown("fast");
        // And add it to our array
        stateSave.push(classDiv);
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

  // This section is for toggling visibility of the comments textarea and submit button
  $(function() {
    // comment submit and textarea are initially hidden with css

    // next, allow the toggle button to show/hide comment elements
    $(".toggle-com-button").click(function(e) {
      e.preventDefault(); 
      $(this).nextAll(".comment-submit-button").toggleClass("comment-submit-button-show");
      $(this).nextAll(".field-name-field-profile-comment").toggleClass("field-name-field-profile-comment-show");
    });
});

}(jQuery));


