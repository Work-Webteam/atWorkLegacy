(function ($) {

/*********** Begin My Actions vs All Activity interaction ***********/ 

function myActionsRules() {// when My Actions is button clicked
  // these will change for prod but keeping checkboxes visible for testing
  $("#edit-feed-choices-1").removeAttr("disabled"); // enable 'My Actions'
  $('#edit-feed-choices-1').attr('checked', true);
  $('#edit-feed-choices-2').attr('checked', false);
  // we will eventually hide this altogether but for now
  $("#edit-feed-choices-2").attr("disabled", true);
  
  $("#edit-feed-choices-3").removeAttr("disabled");
  $("#edit-feed-choices-6").removeAttr("disabled");
}

function allActivityRules() {// when All Activity button is clicked
  // these will change for prod but keeping checkboxes visible for testing
  $("#edit-feed-choices-2").removeAttr("disabled"); // enable 'All Activity'
  $('#edit-feed-choices-2').attr('checked', true);
  $('#edit-feed-choices-1').attr('checked', false);
  // we will eventually hide this altogether but for now disable customizations
  $("#edit-feed-choices-1").attr("disabled", true);  
  $("#edit-feed-choices-3").attr("disabled", true);
  $("#edit-feed-choices-6").attr("disabled", true);
}

// Listen for My Actions vs All Activity button changes   
$("#atwork-advanced-feed-settings").hide(); // initially hide the filter lists
$(".activity-filters-my").click(function() {
  if(!$("#atwork-advanced-feed-settings").is(":visible")) { // if filters aren't already showing
    $("#atwork-advanced-feed-settings").show();
  } 
  myActionsRules();
}); 
$(".activity-filters-all").click(function() {
  if(!$("#atwork-advanced-feed-settings").is(":visible")) { // if filters aren't already showing
    $("#atwork-advanced-feed-settings").show();
  } 
  allActivityRules();
}); 




/*********** End My Actions vs All Activity interaction ***********/ 


/*********** Start Content Filter rules ***********/

function contentActive() {
  $('#edit-feed-choices-13').attr('checked', false); // blogs
  $('#edit-feed-choices-14').attr('checked', false); // events
  $('#edit-feed-choices-15').attr('checked', false); // forums
  $('#edit-feed-choices-16').attr('checked', false); // news
  $('#edit-feed-choices-17').attr('checked', false); // group pages
  $('#edit-feed-choices-19').attr('checked', false); // galleries
  $('#edit-feed-choices-20').attr('checked', false); // questions
  $('#edit-feed-choices-21').attr('checked', false); // polls
}

// If content is checked, uncheck all sub-content types
$('#edit-feed-choices-10').change(
  function(){  
    if($('#edit-feed-choices-10').is(':checked')) {
      contentActive();
    }
  }
);

// If any sub-content filters are applied, uncheck content
$('#edit-feed-choices-13,#edit-feed-choices-14,#edit-feed-choices-15,#edit-feed-choices-16,#edit-feed-choices-17,#edit-feed-choices-19,#edit-feed-choices-20,#edit-feed-choices-21').change( 
  function(){
    if ($('#edit-feed-choices-13,#edit-feed-choices-14,#edit-feed-choices-15,#edit-feed-choices-16,#edit-feed-choices-17,#edit-feed-choices-19,#edit-feed-choices-20,#edit-feed-choices-21').is(':checked')) { // when checked
      $('#edit-feed-choices-10').attr('checked', false); // blogs
    }
});

/*********** End Content Filter rules ***********/

}(jQuery));
