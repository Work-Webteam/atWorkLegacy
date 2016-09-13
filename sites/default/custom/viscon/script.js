$(document).ready(function(){
// Executed once all the page elements are loaded

	// Convert the UL with all the tutorials into a sortable list:
	$("ul.sort").sortable({
		handle : '.tut',
		axis:'y',
		containment: 'document',
		opacity: 0.5,
		stop: function(event, ui) { 
	 // make each rnumber class reload on event stop to 1,2,3,4... using innerHTML		                 
			$('.rnumber').each(function(i){ 
            	this.innerHTML = i+1; });
			}
	});


	// Binding an action to the submitPoll button:
	$('#submitPoll').click(function(e){
	
		// We then turn the sortable into a comma-separated string
		// and assign it to the sortdata hidden form field:
		
		$('#sortdata').val($('ul.sort').sortable('toArray').join(','));
              var userinputids = new Array();
              var userinputs = new Array();
              $('.usercomments').each(function(i){
                                  userinputids[i] = this.id;
                                  userinputs[i] = $(this).val();
                            });
              $('#userinputids').val(userinputids.join('`,`'));
              $('#userinputs').val(userinputs.join('|||||'));
              if($('#othertitleinput').length){
                $('#othertitle').val($('#othertitleinput').val());
                $('#otherqid').val($('#othertitleinput').attr('name').replace("other",""));
              }
		
              // After this we submit the form:
		$('#sform').submit();

		// Preventing the default action triggered by clicking on the link
		e.preventDefault();
	});
	
});