(function ($) {

  var stateSave = Array();
  var refreshFeed = false;
  /**
   * Drupal attach function - click handlers etc.
   */
  Drupal.behaviors.profileFeedJquery = {
    attach: function(context, settings) {



    // Initialize/take care of comments
    setComments();

    // This is a check to fix a problem where IE changes the placeholder
    internetExplorerCheck();

    // Only run if the link exists in the current page load or fragment refresh.
    $('#ajax-target:not(.atwork-activity-processed)', context)
      .addClass('atwork-activity-processed')
      .bind('click', function(){
        ajaxRefresh();
        return false;
    });

    if(refreshFeed === false){
      setFeedInterval();
    }

    // click handler for the comment toggle function
    // Make sure we are not rebinding this improperly on profile page
    $("#block-atwork-activity-profile-page-activity-feed-block .comment-count-link").unbind();
    $("#block-atwork-activity-profile-page-activity-feed-block .comment-count-link").click(function(){
      toggleComments($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));
    });

    // Make sure we are not rebinding this improperly on homepage
    $("#block-atwork-activity-homepage .comment-count-link").unbind();
    $("#block-atwork-activity-homepage .comment-count-link").click(function(){
      toggleComments($(this).parentsUntil('#activity-feed').closest("div").prop("class"));
    });

    // Comment update
      $("[id^=edit-button").click(function(){
        //TODO - figure out how to replace the div with a spinner.
        //TODO - find out why we have a second box appearing when we submit
        // Remove text blocks and show that it is saving
        $('[id^="field-profile-comment-add-more-wrapper"').replaceWith('<div><p id="saving-notification-comment" class="saving-activity"> SAVING </p></div>');

        // close the filter options
        $("#atwork-advanced-feed-settings").hide();
        // Refresh the page after .5 seconds (to let db update)
        setTimeout(ajaxRefresh, 500);
        // Also open all comments so that user can see the comment they just made
        setOpenOnReloadComments($(this).parentsUntil('[id^="activity-feed"').closest("div").prop("class"));

        return;
      });

    // Updates status
    $("[id^=edit-post").once("updateStatus", function(){
      $("[id^=edit-post").click(function(){
        $('[id^="atwork-activity-form"').replaceWith('<div><p id="saving-notification-status" class="saving-activity"> SAVING </p></div>');
        // Delay this for .5 second so that we have time to commit to db
        setTimeout(ajaxRefresh, 500);
      });
    });

    // Updates feed choices on the homepage
    $("#edit-update").once("toggleChoices", function(){
      $("#edit-update").click(function(){
        setTimeout(ajaxRefresh, 500);
        resetTimer();
      });
    });

    // Toggle comments
      $('[id^=edit-toggle-com-button]').click(function(){
        toggleCommentVis($(this));
      });
  }
 };


/**
 * Function to see if we are using internet explorer
 */
    function internetExplorerCheck(){

      var ua = window.navigator.userAgent;
      var msie = ua.indexOf('MSIE ');
      var trident = ua.indexOf('Trident/');
      var edge = ua.indexOf('Edge/');

      // IE specific jQuery
      if (trident > 0 || edge > 0 || msie > 0) {
        // This is IE, so lets check what is in the textbox.
        var checkText = $('#edit-status').attr('value');
        if(checkText == "What are you working on?"){
          $('#edit-status').on("focus", function(){
            // Grab this again so that we don't erase user input after the handler is set.
            var checkText = $('#edit-status').attr('value');
            if(checkText == "What are you working on?"){
              $('#edit-status').attr('value', '');
            }
          });
        }
      }
    }


    /**
     * Function that allows us to set links, show page the way we would like to at initial refresh
     */
    function setComments(){
      // On initial load we want to check if our array has any items or not (if not, then this is the very first load and not a reload)
      // Have not loaded this page yet, or everything was left closed
      if(stateSave.length < 1){
        $.each($(".replies"), function(){
          // Hide all but the last link
          $(this).find(".reply").hide();
          // Find out how many comments we have in this block
          var i = $(this).find($(".reply")).length;
          // If we don't have one yet, lets append it to this block.
          if($(this).find(".comment-count-link").length === 0 && i > 0){
            $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments (' + i + ')</a></div>');
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
           $(this).find(".reply").hide();
          }
          // If we don't have one yet, lets append it to this block.
          var k = $(this).find($(".reply")).length;

          if($(this).find(".comment-count-link").length === 0 && k > 0){
            $(this).append('<div class="comment-count-link"><a class="comment-count-link-text" href="#/">Comments (' + k + ')</a></div>');
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
          $("." + divClass).find(".replies").find(".reply").slideDown("fast");
          //and add it to the array
          stateSave.push(classDiv);
        } else {
           // If it is in our array, it is opened and should be closed
          $("." + divClass).find(".replies").find(".reply").slideUp("fast");
          // and removed from the array
          stateSave.splice(arraySpot, 1);
        }
      } else {
        // Everything is closed, and this is the first opened comment
        $("." + divClass).find(".replies").find(".reply").slideDown("fast");
        // And add it to our array
        stateSave.push(classDiv);
      }
      return;
    }


    /**
     * Function that sets comments to be opened when page refreshes, after adding a comment
     */
     function setOpenOnReloadComments(classDiv){
       //Get rid of the spaces, so we can use this as a selector
       divClass = classDiv.split(' ').join('.');
       //If this is already open, we can ignore it
        var arraySpot = $.inArray(classDiv, stateSave);
        if(arraySpot === -1){
          stateSave.push(classDiv);
        }
     }


    /**
     * Function that clicks on relevant update links created by the block_refresh module
     */
    function ajaxRefresh(){
      // Profile page
      $('#block-views-people-admin-block-following').find('.block-refresh-button').first().trigger("click");
      $('#block-views-people-admin-block-followers').find('.block-refresh-button').first().trigger("click");
      $('#block-atwork-activity-profile-page-activity-feed-block').find('.block-refresh-button').first().trigger("click");
      $(".form-textarea").prop("disabled", true);
      $('[id^="edit-status"').replaceWith('<div><p id="saving-notification" class="saving-activity"> Refreshing </p></div>');
      // home page
      $('#block-atwork-activity-homepage').find('.block-refresh-button').trigger("click");
    }


    /**
     * Function in charge of setting the interval to the value we would like
     */
    function setFeedInterval(){
      if(refreshFeed === false){
        refreshFeed = setInterval(checkMessageCount, 30000);
      }
    }


    function checkMessageCount(){
      checkLink = $('#profile-comment-link').length;
      console.log(checkLink);
      if(checkLink > 0){
        $('#profile-comment-link').trigger('click');
      }
    }



  /**
   * Function to accept 'this' argument from click handler
   * to toggle visibility on comment for elements
   */

  function toggleCommentVis(thisObj){
    //dpm(thisObj);
    thisObj.nextAll(".comment-submit-button").toggleClass("comment-submit-button-show");
    thisObj.nextAll(".field-name-field-profile-comment").toggleClass("field-name-field-profile-comment-show");
    // change the value of the thisObj button
    if ($.trim($(thisObj).attr("value")) === 'Comment') {
      $(thisObj).val('Cancel');
    } else {
      $(thisObj).val('Comment');
    }
  }


}(jQuery));


