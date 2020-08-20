/**
 * Search is buggy sometimes - trying to prevent unwanted behavior when user presses enter.
 */
(function ($) {
  Drupal.behaviors.atwork_search = {
    attach: function (context, settings) {
      $('#edit-search-block-form--2').keyup(function (event) {
        if (event.keyCode == '13') {
          event.preventDefault();
        }
      });
    }
  }
}(jQuery));
