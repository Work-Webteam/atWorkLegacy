(function ($) {

/*********** Begin My Actions vs All Activity interaction ***********/ 

function allActivityRules() {
  $('#edit-feed-choices-2').attr('checked', true);
  $("#edit-feed-choices-2").removeAttr("disabled"); // enable 'All Activity'
  $("#edit-feed-choices-3").attr("disabled", true);
  $("#edit-feed-choices-6").attr("disabled", true);
}

function myActionsRules() {
  $('#edit-feed-choices-2').attr('checked', false);
  $("#edit-feed-choices-2").attr({"disabled": true}); // enable and check 'All Activity'
  $("#edit-feed-choices-3").removeAttr("disabled");
  $("#edit-feed-choices-6").removeAttr("disabled");
}

// First, enforce that only My Actions or All Activity can be checked
if ($('#edit-feed-choices-1').is(':checked')) { // when My Actions is checked
  myActionsRules();
} else {
  $('#edit-feed-choices-2').attr('checked', true); // else enable 'All Activity'
  allActivityRules();
}

// Next, listen for My Actions checkbox changes
$('#edit-feed-choices-1').change( 
  function(){
    if ($('#edit-feed-choices-1').is(':checked')) { // when checked
      myActionsRules();
    } else {
      allActivityRules();
    }
  }
);

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
