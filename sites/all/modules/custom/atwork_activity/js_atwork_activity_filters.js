(function ($) {

  // Need to know if the advanced feed info has been opened or not
  var advancedFilters = false;

       /*********** Begin My Actions vs All Activity interaction ***********/

      function myActionsRules() {// when My Actions is button clicked
        // these will change for prod but for now, keeping checkboxes visible for testing
        $(".activity-filters-my").addClass("active"); // gray
        $(".activity-filters-all").removeClass("active"); // green
        $("#edit-feed-choices-1").attr("disabled", false);
        $('#edit-feed-choices-1').attr('checked', true);
        $('#edit-feed-choices-2').attr('checked', false);
        // we will eventually hide this altogether but for now
        $("#edit-feed-choices-2").attr("disabled", true);
        $("#edit-feed-choices-3").attr("checked", true);
        $("#edit-feed-choices-4").attr("checked", true);
        $("#edit-feed-choices-5").attr("checked", true);
        $("#edit-feed-choices-6").attr("checked", true);
        $("#edit-feed-choices-7").attr("checked", true);
        $("#edit-feed-choices-8").attr("checked", true);
        $("#edit-feed-choices-9").attr("checked", true);
        $("#edit-feed-choices-10").attr("checked", true);
        $("#edit-feed-choices-11").attr("checked", true);
        $("#edit-feed-choices-12").attr("checked", true);
        $("#edit-feed-choices-13").attr("checked", true);
        $("#edit-feed-choices-14").attr("checked", true);
        $("#edit-feed-choices-15").attr("checked", true);
        $("#edit-feed-choices-16").attr("checked", true);
        $("#edit-feed-choices-17").attr("checked", true);
        $("#edit-feed-choices-18").attr("checked", true);
        $("#edit-feed-choices-19").attr("checked", true);
        $("#edit-feed-choices-20").attr("checked", true);
        $("#edit-feed-choices-21").attr("checked", true);
        $("#edit-feed-choices-22").attr("checked", true);




        // The above must be marked prior to submit
        submitChanges();
      }

      function allActivityRules() {// when All Activity button is clicked
        // these will change for prod but for now, keeping checkboxes visible for testing
        $(".activity-filters-my").removeClass("active"); // gray
        $(".activity-filters-all").addClass("active"); // green
        $("#edit-feed-choices-2").attr("disabled", false);
        $('#edit-feed-choices-2').attr('checked', true);
        $('#edit-feed-choices-1').attr('checked', false);
        $("#edit-feed-choices-1").attr("disabled", true);

        // Fields that should not be checked
        $("#edit-feed-choices-3").attr("checked", false);
        $("#edit-feed-choices-6").attr("checked", false);
        // Fields that should be checked
        $("#edit-feed-choices-4").attr("checked", true);
        $("#edit-feed-choices-5").attr("checked", true);
        $("#edit-feed-choices-7").attr("checked", true);
        $("#edit-feed-choices-8").attr("checked", true);
        $("#edit-feed-choices-9").attr("checked", true);
        $("#edit-feed-choices-10").attr("checked", true);
        $("#edit-feed-choices-11").attr("checked", true);
        $("#edit-feed-choices-12").attr("checked", true);
        $("#edit-feed-choices-13").attr("checked", true);
        $("#edit-feed-choices-14").attr("checked", true);
        $("#edit-feed-choices-15").attr("checked", true);
        $("#edit-feed-choices-16").attr("checked", true);
        $("#edit-feed-choices-17").attr("checked", true);
        $("#edit-feed-choices-18").attr("checked", true);
        $("#edit-feed-choices-19").attr("checked", true);
        $("#edit-feed-choices-20").attr("checked", true);
        $("#edit-feed-choices-21").attr("checked", true);
        $("#edit-feed-choices-22").attr("checked", true);
        submitChanges();
      }

      function setChoices(){
        // All activity
        if($("#edit-feed-choices-1").prop("checked")){
          $(".activity-filters-my").addClass("active"); // gray
          $(".activity-filters-all").removeClass("active"); // green
        }
        if($('#edit-feed-choices-2').prop("checked")){
          $(".activity-filters-my").removeClass("active"); // gray
          $(".activity-filters-all").addClass("active"); // green
        }
      }


      function submitChanges(){
        $('#edit-update').trigger("click");
      }


  /**
   * Drupal attach function - click handlers etc.
   */
  Drupal.behaviors.profileFilterJquery = {
    attach: function(context, settings) {

      setChoices();
      // Hide this block if we haven't opened the advanced menu
      if(advancedFilters === false){
        $("#edit-feed-choices").hide();
        $("#edit-update").hide();
      }


      // Listen for My Actions vs All Activity button changes
    // Make sure we are not rebinding this
    $('.activity-filters-my:not(.atwork-activity-processed)', context)
      .addClass('atwork-activity-processed')
      .bind('click', function(){
        myActionsRules();
      });
    $('.activity-filters-all:not(.atwork-activity-processed)', context)
      .addClass('atwork-activity-processed')
      .bind('click', function(){
        allActivityRules();
        // Also need to lock these in - so click the update button
      });


      /*********** End My Actions vs All Activity interaction ***********/


      // Link handles whether we see advanced filters or not.
    $('#activity-feed-advanced-filters:not(.atwork-activity-processed)', context)
      .addClass('atwork-activity-processed')
      .bind('click', function(){
        if(advancedFilters === false){
          advancedFilters = true;
          $('#edit-feed-choices').slideDown("slow");
          $('#edit-update').slideDown("slow");
        } else {
          $('#edit-feed-choices').slideUp("slow");
          $('#edit-update').slideUp("slow");
          advancedFilters = false;
        }
        setChoices();
      });

      /*********** End Content Filter rules ***********/
    }

  };
}(jQuery));