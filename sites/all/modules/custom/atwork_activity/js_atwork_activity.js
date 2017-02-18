function toggleCommentForm(nid) {
  //alert('.comment-form-' + nid);
  jQuery('.comment-form-' + nid).slideToggle();
  jQuery('html, body').animate({
    scrollTop: jQuery('.comment-form-' + nid).offset().top + 'px'
  }, 'fast');
}


(function ($) {



  Drupal.behaviors.atworkActivity = {
    attach: function (context, settings) {
      $('.comment-form').hide();
    }
  };

}(jQuery));
