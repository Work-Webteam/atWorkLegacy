(function ($) {
  /**
   * Global variables so that we don't lose them on refresh
   */

  $( document ).ajaxStart(function(){
    console.log("ajax starting");
    $(".form-textarea").prop("disabled", true);
    $(".form-textarea").prop("readonly", true);
    //$("#edit-status").prop("disabled", true);
    $(".form-textarea").prop("value", "refreshing feed");
  });

  $( document ).ajaxStop(function(){
    console.log("ajax stopped");
    $(".form-textarea").prop("disabled", false);
    $(".form-textarea").prop("readonly", false);
  });


  // Start with false so that we can tell if it is set or not.
  var refreshFeed = false;
  var timer = false;
  var stateSave = Array();

  Drupal.behaviors.profileFeedJquery = {
    attach: function (context, settings) {

    /**
     * First section has timer related code
     */
    // Page refresh should occur every 5 seconds after initial load
    if(refreshFeed === false && timer=== false){ // Don't want to set this twice
      setFeedInterval();
    }

    // Initialize/take care of comments
    setComments();

    // click handler for the comment toggle function
    $(".comment-count-link").click(function(){
      toggleComments($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
    });

    /**
     * Second section has display related functions/handlers
     */
          //Unless someone is typing in a text field
    $(".form-textarea").click(function(){
      slow_var();
    });

    $("[id^=edit-button").click(function(){
      //TODO - figure out how to replace the div with a spinner.
      //$(this).parent('div').parent('div').effect("blind", 300);
      $('[id^="field-profile-comment-add-more-wrapper"').replaceWith('<div><p id="saving-notification"> SAVING </p></div>');
      // Refresh the page to make it dynamic
      refreshPage();
      //refresh interval and remove timer if present
      resetTimer();
      return;
    });

    /**
     * Function that allows us to set links, show page the way we would like to at initial refresh
     */
    function setComments(){
      console.log(stateSave);
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

          //Grab teh class of this message so we can remember its state
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
              console.log("No new comment");
            } else {
              console.log("New comment");
            }
            return;
          } else {
            // Rebuild the comments link if it does not exist
            var k = $(this).find($(".reply")).length;
            $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments(' + k + ')</a></div>');
          }
        });

        // If we have saved state, we need to deal with it here and either hide or leave comments open
        if(stateSave.length > 1){
          $.each($(".replies"), function(){
            var x = ($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
            // TODO - not inArray is -1, 0 is inarray, but also false.
            if($.inArray(x, stateSave) !== -1){
              // If it is here, it is hidden
              $(this).find(".reply").not(":last").hide();
            } else {
              return;
            }
          });

        }
      }
    }

    /**
     * Function that will allow us to hide all but the last comment, and also create a counted comment link
     */
    function toggleComments(thing){
      // comment counter for link.
      console.log(thing);
      var $i = 0;
      $.each($(".replies"), function(){
        // Hide all but the last link
        $(this).find(".reply").not(":last").slideToggle("fast");
        // Find out how many comments we have in this block
        $i = $(this).find($(".reply")).length;
        // Don't want to double up on the comment links
        if($(this).find($(".comment-count-link")).length > 0){
          console.log("already got one");
          return;
        }
        // If we don't have one yet, lets append it to this block.
        $(this).append('<div class="comment-count-link"><a href="#/">Comments(' + $i + ')</a></div>');
        console.log($i);
      });
      //$(".reply").not(":last").hide();

      //$(".field field-name-field-comment-message-comments field-type-reply field-label-hidden");
      return;
    }


    /**
     * Function that refreshes the profile feed via manual block refresh link
     */
    function refreshPage(){
      // Refresh the block with the link generated by the bock_refresh module
      //if(timer === false){
        console.log("Refreshing");
        $('.block-refresh-button').first().click();
      //}
      return;
    }

    /**
     * Function that stops all refreshes for 10 minutes if someone clicks in a text box, then restarts them
     */
    function slow_var(){
      console.log("slow_var");
      if(refreshFeed !== false){
        clearInterval(refreshFeed);
        refreshFeed = false;
      }
        // If nothing happens in 5 minutes, we will start our refresh again
        console.log(timer);
      if(timer === false){
        timer = setTimeout(setFeedInterval, 300000);
      }
        console.log("timer set for 5 minutes");

      return;
    }

    /**
     * Function in charge of setting the interval to the value we would like
     */
    function setFeedInterval(){
      console.log("setFeedInterval");
      //console.log(refreshFeed.length());
      if(refreshFeed === false){
        refreshFeed = setInterval(refreshPage, 20000);
        console.log("interval set");
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


    /**
     * Function that keeps the user profile up to date
     * @param  var myVar Interval timer that sets a refresh
     */
    $(document).ready(function(){
      // This seemed to be extrenuous after using the drupal attach behavior method above.

    });

   }
  };

}(jQuery));


