(function ($) {

function atwork_premiere_add_nominee() {
  $('#webform-component-nominee-information--nominees-header table tbody').append('<tr><td><input type="text" name="nominee_name[]" /></td><td><input type="text" name="nominee_branch[]" /></td><td><input type="text" name="nominee_email[]" /></td><td><input type="text" name="nominee_phone[]" /></td></tr>');
	
}

$(document).ready(function(){

	atwork_premiere_add_nominee();
  atwork_premiere_add_nominee();
  atwork_premiere_add_nominee();
  
  $('#webform-component-nominee-information--nominees-header').append('<input type="button" value="Add a Nominee" class="atwork-premiere-add-nominee" /> ');
	
  $('.atwork-premiere-add-nominee').click(function() {
    atwork_premiere_add_nominee();
  });
  
  // store original values on document ready
  var value = $('input[name*="submitted[region]"]:checked').val();
  $('body').data('atwork_region', value);
  
  $('input[name*="submitted[region]"]').click(function() {
      var currentValue = $('input[name*="submitted[region]"]:checked').val();
      var originalValue = $('body').data('atwork_region');
      //alert(originalValue + '=' + currentValue);
      if (currentValue == originalValue && originalValue != 'NULL' && typeof(originalValue) !== 'undefined') {
        $(this).attr('checked', false);
        $('body').data('atwork_region', 'NULL');
      } else {
        $('body').data('atwork_region', currentValue);
      }
  });
  
  $('#edit-submitted-summary-statement').keydown(function() {
    var text = $(this).val();
    $('#edit-submitted-summary-word-count').val(text.split(' ').length);
  });
  $('#edit-submitted-summary-statement').click(function() {
    var text = $(this).val();
    $('#edit-submitted-summary-word-count').val(text.split(' ').length);
  });
  $('#edit-submitted-summary-statement').focus(function() {
    var text = $(this).val();
    $('#edit-submitted-summary-word-count').val(text.split(' ').length);
  });
  $('#edit-submitted-summary-statement').blur(function() {
    var text = $(this).val();
    $('#edit-submitted-summary-word-count').val(text.split(' ').length);
  });
  
  $('#edit-submitted-prem-award-q1, #edit-submitted-prem-award-q2, #edit-submitted-prem-award-q3, #edit-submitted-prem-award-q4, #edit-submitted-prem-award-q5, #edit-submitted-prem-award-q6, #edit-submitted-prem-award-q7, #edit-submitted-prem-award-q8, #edit-submitted-prem-award-q9').keydown(function() {
    var text = $('#edit-submitted-prem-award-q1').val() + '' + $('#edit-submitted-prem-award-q2').val() + '' + $('#edit-submitted-prem-award-q3').val() + '' + $('#edit-submitted-prem-award-q4').val() + '' + $('#edit-submitted-prem-award-q5').val() + '' + $('#edit-submitted-prem-award-q6').val() + '' + $('#edit-submitted-prem-award-q7').val() + '' + $('#edit-submitted-prem-award-q8').val() + '' + $('#edit-submitted-prem-award-q9').val();
    $('#edit-submitted-submission-word-count').val(text.split(' ').length);
  });
  $('#edit-submitted-prem-award-q1, #edit-submitted-prem-award-q2, #edit-submitted-prem-award-q3, #edit-submitted-prem-award-q4, #edit-submitted-prem-award-q5, #edit-submitted-prem-award-q6, #edit-submitted-prem-award-q7, #edit-submitted-prem-award-q8, #edit-submitted-prem-award-q9').click(function() {
    var text = $('#edit-submitted-prem-award-q1').val() + '' + $('#edit-submitted-prem-award-q2').val() + '' + $('#edit-submitted-prem-award-q3').val() + '' + $('#edit-submitted-prem-award-q4').val() + '' + $('#edit-submitted-prem-award-q5').val() + '' + $('#edit-submitted-prem-award-q6').val() + '' + $('#edit-submitted-prem-award-q7').val() + '' + $('#edit-submitted-prem-award-q8').val() + '' + $('#edit-submitted-prem-award-q9').val();
    $('#edit-submitted-submission-word-count').val(text.split(' ').length);
  });
  $('#edit-submitted-prem-award-q1, #edit-submitted-prem-award-q2, #edit-submitted-prem-award-q3, #edit-submitted-prem-award-q4, #edit-submitted-prem-award-q5, #edit-submitted-prem-award-q6, #edit-submitted-prem-award-q7, #edit-submitted-prem-award-q8, #edit-submitted-prem-award-q9').focus(function() {
    var text = $('#edit-submitted-prem-award-q1').val() + '' + $('#edit-submitted-prem-award-q2').val() + '' + $('#edit-submitted-prem-award-q3').val() + '' + $('#edit-submitted-prem-award-q4').val() + '' + $('#edit-submitted-prem-award-q5').val() + '' + $('#edit-submitted-prem-award-q6').val() + '' + $('#edit-submitted-prem-award-q7').val() + '' + $('#edit-submitted-prem-award-q8').val() + '' + $('#edit-submitted-prem-award-q9').val();
    $('#edit-submitted-submission-word-count').val(text.split(' ').length);
  });
  $('#edit-submitted-prem-award-q1, #edit-submitted-prem-award-q2, #edit-submitted-prem-award-q3, #edit-submitted-prem-award-q4, #edit-submitted-prem-award-q5, #edit-submitted-prem-award-q6, #edit-submitted-prem-award-q7, #edit-submitted-prem-award-q8, #edit-submitted-prem-award-q9').blur(function() {
    var text = $('#edit-submitted-prem-award-q1').val() + '' + $('#edit-submitted-prem-award-q2').val() + '' + $('#edit-submitted-prem-award-q3').val() + '' + $('#edit-submitted-prem-award-q4').val() + '' + $('#edit-submitted-prem-award-q5').val() + '' + $('#edit-submitted-prem-award-q6').val() + '' + $('#edit-submitted-prem-award-q7').val() + '' + $('#edit-submitted-prem-award-q8').val() + '' + $('#edit-submitted-prem-award-q9').val();
    $('#edit-submitted-submission-word-count').val(text.split(' ').length);
  });
  
  $("edit-submitted-application-type").prop("disabled", true);
  
});

})(jQuery);