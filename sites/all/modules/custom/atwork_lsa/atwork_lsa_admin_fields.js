/**
 * JS function for LSA Gift choices
 * Library from: http://trentrichardson.com/Impromptu/
 * Drupal.jquery
 * Written by Thayne Werdal Feb 2016
 */

(function ($) {

  /**
   * Helper function that hides admin fields from non-admins
   */
  function hide_admin_fields(){
    /*** Hide admin options for now, eventually we may want to do this with php? ***/
    //Award year
    $('#edit-field-lsa-award-year').hide();
    $('#field-lsa-award-id-add-more-wrapper').hide();

    // Watch Engraving sent date
    $('#field-lsa-watch-engraving-sent-add-more-wrapper').hide();

    //Ministry ID
    $('#field-lsa-ministry-id-add-more-wrapper').hide();

    //Admin Settings
    $('.collapsible.collapsed.required-fields.group-lsa-administration.field-group-fieldset.form-wrapper.collapse-processed').hide();

    // Certificate
    $('#field-lsa-25year-certificatename-add-more-wrapper').hide();

    // Award Special Instructions
    $('#field-lsa-award-sp-instructions-add-more-wrapper').hide();
}

/**
 * Document ready controller,
 * Hides administrator fields from non admins - but still keeps them in Dom so we can manipulate them
 */
  $( document ).ready(function(){
    hide_admin_fields();
  });
}(jQuery));
