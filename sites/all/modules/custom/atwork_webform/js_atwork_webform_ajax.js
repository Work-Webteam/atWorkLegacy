(function ($) {
  Drupal.behaviors.my_custom_module = {
    attach: function(context, settings) {

      // Only run if the link exists in the current page load or fragment refresh.
      $('#randomize:not(.atwork-processed)', context)
        .addClass('atwork-processed')
        .bind('click', function(){
          $.get('/random', null, feedDetails);
        return false;
        });
      // Need to be able to open and close list of users.
      $('#contestant-button:not(.atwork-processed)', context)
        .addClass('atwork-processed')
        .bind('click', function(){
          $('#voter_list').slideToggle("slow");
      });
      $('#voter_list').hide();
    }
  };
  
  var feedDetails = function(response){
    // Get back a random winner from all users who have voted
    $('<div id="winner_profile_image"></div>').insertBefore('#randomizer_block');
    var result = $.parseJSON(response);
    $('#winner_profile_image').html(result).hide();
    // And display for content team.
    $('#winner_profile_image').slideDown('slow');
    return false;
  };

  function openClose(){
  }



})(jQuery);
