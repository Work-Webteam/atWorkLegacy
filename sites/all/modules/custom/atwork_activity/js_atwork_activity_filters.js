(function ($) {

  // Need to know if the advanced feed info has been opened or not
  var advancedFilters = false;
  var showAdvancedContent = false;

  /**
   * Drupal attach function - click handlers etc.
   */
  Drupal.behaviors.profileFilterJquery = {
    attach: function(context, settings) {
      // We will manipulate these choices with the image buttons at the top of the feed, hide them.
      $('.form-item.form-type-checkbox.form-item-feed-choices-1').hide();
      $('.form-item.form-type-checkbox.form-item-feed-choices-2').hide();

      // hide advanced content filters and add link
      if(showAdvancedContent === false){
        $('.form-item.form-type-checkbox.form-item-feed-choices-11, .form-item.form-type-checkbox.form-item-feed-choices-12, .form-item.form-type-checkbox.form-item-feed-choices-13, .form-item.form-type-checkbox.form-item-feed-choices-14, .form-item.form-type-checkbox.form-item-feed-choices-15, .form-item.form-type-checkbox.form-item-feed-choices-16, .form-item.form-type-checkbox.form-item-feed-choices-17, .form-item.form-type-checkbox.form-item-feed-choices-18,.form-item.form-type-checkbox.form-item-feed-choices-19, .form-item.form-type-checkbox.form-item-feed-choices-20, .form-item.form-type-checkbox.form-item-feed-choices-21, .form-item.form-type-checkbox.form-item-feed-choices-22').hide();
      }
     // reorder the description div to display before the form
      $('#atwork-activity-customize-feed-form .description').insertBefore('#atwork-activity-customize-feed-form #edit-feed-choices');
      setChoices();
      // Hide this block if we haven't opened the advanced menu
      if(advancedFilters === false){
        $("#edit-feed-choices").hide();
        $("#edit-update").hide();
      }
      $('<div id="show-advanced-content-div"><p><a href="#" id="show-advanced-content">Choose by content type</a></p></div>').insertAfter("div.form-item.form-type-checkbox.form-item-feed-choices-22");


      /*********** Begin My Actions vs All Activity interaction ***********/

      function myActionsRules() {// when My Actions is button clicked
        // these will change for prod but for now, keeping checkboxes visible for testing
        $("#edit-feed-choices-1").removeAttr("disabled"); // enable 'My Actions'
        $('#edit-feed-choices-1').attr('checked', true);
        $('#edit-feed-choices-2').attr('checked', false);
        // we will eventually hide this altogether but for now
        $("#edit-feed-choices-2").attr("disabled", true);

        $("#edit-feed-choices-3").removeAttr("disabled");
        $("#edit-feed-choices-6").removeAttr("disabled");
      }

      function allActivityRules() {// when All Activity button is clicked
        // these will change for prod but for now, keeping checkboxes visible for testing
        $("#edit-feed-choices-2").removeAttr("disabled"); // enable 'All Activity'
        $('#edit-feed-choices-2').attr('checked', true);
        $('#edit-feed-choices-1').attr('checked', false);
        // we will eventually hide this altogether but for now disable customizations
        $("#edit-feed-choices-1").attr("disabled", true);
        $("#edit-feed-choices-3").attr("disabled", true);
        $("#edit-feed-choices-6").attr("disabled", true);
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
        if(advancedFilters === true){
          // advanced filters are open, show relevant filters
          advancedFiltersChoices();
        }
      }

      function submitChanges(){
        $('#edit-update').trigger("click");
      }

      // Listen for My Actions vs All Activity button changes
      //$("#atwork-advanced-feed-settings").hide(); // initially hide the filter lists
      $(".activity-filters-my").unbind();
      $(".activity-filters-my").click(function() {
        setChoices();
        myActionsRules();
        // Also need to lock these in - so click the update button
        setTimeout(submitChanges, 1500);
      });
      $('.activity-filters-all').unbind();
      $(".activity-filters-all").click(function() {
        setChoices();
        allActivityRules();
        // Also need to lock these in - so click the update button
        setTimeout(submitChanges, 1500);
      });



      /*********** End My Actions vs All Activity interaction ***********/


      /*********** Start Content Filter rules ***********/

      function advancedFiltersChoices() {

        // If this is all activity
        if($("#edit-feed-choices-2").prop("checked")){
          // Actions by colleages
          $(".form-item.form-type-checkbox.form-item-feed-choices-3").hide();
          $("#edit-feed-choices-3").attr("checked", false);
          $("#edit-feed-choices-3").attr("disabled", true);
          // My Groups
          $(".form-item.form-type-checkbox.form-item-feed-choices-6").hide();
          $("#edit-feed-choices-6").attr("checked", false);
          $("#edit-feed-choices-6").attr("disabled", true);
        }
        // If this is my activity
        if($("#edit-feed-choices-1").prop("checked")){

        }
      }

      function advancedContentToggle(){
        if(showAdvancedContent === false){
          $('.form-item.form-type-checkbox.form-item-feed-choices-10').slideDown("fast");
          $('.form-item.form-type-checkbox.form-item-feed-choices-11, .form-item.form-type-checkbox.form-item-feed-choices-12, .form-item.form-type-checkbox.form-item-feed-choices-13, .form-item.form-type-checkbox.form-item-feed-choices-14, .form-item.form-type-checkbox.form-item-feed-choices-15, .form-item.form-type-checkbox.form-item-feed-choices-16, .form-item.form-type-checkbox.form-item-feed-choices-17, .form-item.form-type-checkbox.form-item-feed-choices-18,.form-item.form-type-checkbox.form-item-feed-choices-19, .form-item.form-type-checkbox.form-item-feed-choices-20, .form-item.form-type-checkbox.form-item-feed-choices-21, .form-item.form-type-checkbox.form-item-feed-choices-22').slideUp("slow");
        } else {
          $('.form-item.form-type-checkbox.form-item-feed-choices-10').slideUp("fast");
          $('.form-item.form-type-checkbox.form-item-feed-choices-11, .form-item.form-type-checkbox.form-item-feed-choices-12, .form-item.form-type-checkbox.form-item-feed-choices-13, .form-item.form-type-checkbox.form-item-feed-choices-14, .form-item.form-type-checkbox.form-item-feed-choices-15, .form-item.form-type-checkbox.form-item-feed-choices-16, .form-item.form-type-checkbox.form-item-feed-choices-17, .form-item.form-type-checkbox.form-item-feed-choices-18,.form-item.form-type-checkbox.form-item-feed-choices-19, .form-item.form-type-checkbox.form-item-feed-choices-20, .form-item.form-type-checkbox.form-item-feed-choices-21, .form-item.form-type-checkbox.form-item-feed-choices-22').slideDown("slow");
        }
      }

      // Link handles whether we see advanced filters or not.
      $("#activity-feed-advanced-filters").unbind();
      $("#activity-feed-advanced-filters").click(function() {
        console.log("clicky");
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

      // Link handles whether we see advanced content filters or not
     $('#show-advanced-content').unbind();
      $('#show-advanced-content').click(function() {
        console.log("click");
        if(showAdvancedContent === false){
          showAdvancedContent = true;
          advancedContentToggle();
        } else {
          showAdvancedContent = false;
           advancedContentToggle();
        }
      });

      $('#edit-feed-choices-10').unbind();
      $('#edit-feed-choices-10').click(
        function(){
          if($("#edit-feed-choices-10").is(':checked')){
            $('#edit-feed-choices-11,#edit-feed-choices-12,#edit-feed-choices-13,#edit-feed-choices-14,#edit-feed-choices-15,#edit-feed-choices-16,#edit-feed-choices-17,#edit-feed-choices-18,#edit-feed-choices-19,#edit-feed-choices-20,#edit-feed-choices-21, #edit-feed-choices-21').attr('checked',true);
          }
        });

      // If any sub-content filters are applied, check content
      $('#edit-feed-choices-11,#edit-feed-choices-12,#edit-feed-choices-13,#edit-feed-choices-14,#edit-feed-choices-15,#edit-feed-choices-16,#edit-feed-choices-17,#edit-feed-choices-19,#edit-feed-choices-20,#edit-feed-choices-21').change(
        function(){
          if ($('#edit-feed-choices-11,#edit-feed-choices-13,#edit-feed-choices-14,#edit-feed-choices-15,#edit-feed-choices-16,#edit-feed-choices-17,#edit-feed-choices-19,#edit-feed-choices-20,#edit-feed-choices-21,#edit-feed-choices-22').is(':checked')) { // when checked
            $('#edit-feed-choices-10').attr('checked', true); // blogs
          } else {
            $('#edit-feed-choices-10').attr('checked', false);
          }
      });

      /*********** End Content Filter rules ***********/
    }
  };
}(jQuery));
