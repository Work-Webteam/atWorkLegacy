(function ($) {
  /**
   * Function to hide/show fields dependent on form selections
   * @type {{attach: Drupal.behaviors.atworkContactForm.attach}}
   */
  Drupal.behaviors.atworkContactForm = {
    attach: function (context, settings) {
      // Make sure we only do this once
      $('#edit-submitted-initiative-choices-1', context).once('atwork-processed', function (e){
        // Fieldsets to hide
        $('.where-you-work').hide();
        $('.priorities-identified').hide();
        $('.bcpsa-strategic-priority').hide();
        $('.ministry-specific-program').hide();
        // Click handlers.
        $('#edit-submitted-initiative-choices-1', context).click(function (e) {
          if($('#edit-submitted-initiative-choices-1').is(":checked")){
            $('.where-you-work').show();
          } else {
            $('.where-you-work').hide();
          }
        });
        $('#edit-submitted-initiative-choices-2', context).click(function (e) {
          if ($('#edit-submitted-initiative-choices-2').is(':checked')){
            $('.priorities-identified').show();
          } else {
            $('.priorities-identified').hide();
          }
        });
        $('#edit-submitted-initiative-choices-3', context).click(function (e) {
          if ($('#edit-submitted-initiative-choices-3').is(':checked')) {
            $('.bcpsa-strategic-priority').show();
          } else {
            $('.bcpsa-strategic-priority').hide();
          }
        });
        $('#edit-submitted-initiative-choices-4', context).click(function (e) {
          if ($('#edit-submitted-initiative-choices-4').is(':checked')) {
            $('.ministry-specific-program').show();
          } else {
            $('.ministry-specific-program').hide();
          }
        });
      });
    }
  };
})(jQuery);
