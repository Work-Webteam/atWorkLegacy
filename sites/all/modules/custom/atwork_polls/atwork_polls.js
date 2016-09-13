(function ($) {

  $( document ).ready(function(){

  	//helper function for setup
    atwork_polls_initial_setup_table();

    // hide deleted rows
    $('[id*="_has_been_deleted"]').hide();
    
    // What to do when the delete button is clicked
    $( ".delete_row_from_table ").click(function(){
      atwork_polls_delete_table_row($(this));
    });

    // Check to see if button is hidden or if it shows
    $('input[id*="-chtext"').keyup(function(){
      atwork_polls_text_input_count();
    });

    //Whenever we click to add a new line, ajax is called, so we need to handle that situation as well
    $( document ).ajaxComplete(function(){

      // helper function
	  atwork_polls_after_ajax_setup_table();      

	  // hide deleted rows
      //$('[id*="_has_been_deleted"]').css("border", "3px solid red");
      $('[id*="_has_been_deleted"]').hide();

      // What to do when the delete button is clicked
      $( ".delete_row_from_table ").click(function(){
      	atwork_polls_delete_table_row($(this));
      });

      // enable or disable the keys
      $('input[id*="-chtext"').keyup(function(){
        atwork_polls_text_input_count();
      });
    });
  });

  

  // Helper function for initial setup
  function atwork_polls_initial_setup_table(){
  	// Disable add button - the error message that it pops if fields are empty messes with our jQuery - we can handle it ourselves
    atwork_polls_text_input_count();

  	// another error may reload entire page - triggering this path and missing that the table has been manipulated.  If so, lets redirect.
 	if($('#poll-choice-table tbody tr').length > 2){
 		atwork_polls_after_ajax_setup_table();
 		return;
 	}

 	// One x for each row
    $('#poll-choice-table > tbody > tr').each(function(){
      $(this).find('td:last').after('<td class="delete_table_data"><a href="javascript:void(0)" class = "delete_row_from_table"><img src="/sites/all/themes/atwork_zen/images/redX.png"></a></td>');
    });

    return;
  }

  // Helper function for setup after ajax call
  function atwork_polls_after_ajax_setup_table(){

  	// need dynamic id's, so we add in numerical modifier
  	var k = 0;

  	$('#poll-choice-table > tbody > tr').each(function(){
      // set delete x image
      $(this).find('td:last').after('<td><a href="javascript:void(0)" class = "delete_row_from_table"><img src="/sites/all/themes/atwork_zen/images/redX.png"></a></td>');
      // iterate through the table - if we have any empty rows besides the last, we need to id and hide it (Ajax is killing our ids).
      if($(this).prev('tr').find('input[id*="chtex"]').val() == ""){
        $(this).prev('tr').attr('id', k + '_has_been_deleted');
        k++;
      }
    });

    return;
  }

  // Helper function to delete rows in the table
  function atwork_polls_delete_table_row(deleted_row_request){
  	// Count for number of rows total
    var i = $('#poll-choice-table tbody tr').length;

    // Find out how many rows have been deleted
    var j = $('#poll-choice-table tbody tr[id*="_has_been_deleted"]').length;

    // If we only have two rows we can't delete anymore
    if( (i - j <= 2) ) {
      //alert("Must have at least two choices.");
      $('#poll-choices').prepend('<div class="messages error"> You must have at least two choices. </div>');
      return;
    }

    // If we have more than two rows, then we can "delete" one
    // Strip out any characters in text box (so it is deleted after we save)
    $(deleted_row_request).closest('tr').find('input[id*="-chtex"]').attr("value", "");
    $(deleted_row_request).closest('tr').attr('id', '_has_been_deleted');
    // Then hide it
    $(deleted_row_request).closest("tr").hide();

    atwork_polls_text_input_count();

    return;
  }

  /**
   * Helper function to control if user can add another choice or not
   **/

  function atwork_polls_text_input_count(){
  	var check_row_numbers = atwork_polls_text_box_check();
    if(check_row_numbers === true){
      $('#edit-poll-more').attr('disabled', false);
    } else {
      $('#edit-poll-more').attr('disabled', true);
      // disabled button needs its own tool tip.
      $('#edit-poll-more:disabled').wrap(function(){
        return '<div mouseover="' + $(this).attr("title", "You must fill in both fields before you can add another") + '" />';
      });
    }
    return;
  }

  // Helper function to keep track of how many rows have text (must have 2 at least).
  function atwork_polls_text_box_check(){
    var x = 0;
    // check if any text box filled in
    $('input[id*="-chtext"').each(function(){
      if($(this).val() != ""){
        x++;
      }
    });

    if(x >= 2) {
      return true;
    }

    return false;
  }

}(jQuery));
