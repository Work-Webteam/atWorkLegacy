(function ($) {
  Drupal.behaviors.prem_awards_form = {
    attach: function(context, settings) {
      console.log(settings);
      // Fixing case where user name returns blank and creates a 500 (employee news case)
      if((settings.atwork_prem_awards.user.length < 1) && uid == 0 ){
        setting.atwork_prem_awards.user = 'Employee News';
      }
      // Only run if the link exists in the current page load or fragment refresh.
      // TODO: Create a button or link with a specific ID
      $('#prem-awards-form:not(.atwork-prem-awards-processed)', context)
        .addClass('atwork-prem-awards-processed')
        .bind('click', function(){
          $.get('/p-awards/registration/' + settings.atwork_prem_awards.user + '/' + settings.atwork_prem_awards.uid, null, feedDetails);
          return false;
       });
    }
  };

  var feedDetails = function(response){
    var result = $.parseJSON(response);
    console.log(result);
    return false;
  };

  // Read a page's GET URL variables and return them as an associative array.
  function getUrlVars(){
    var vars = [], hash;
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
  }
})(jQuery);
