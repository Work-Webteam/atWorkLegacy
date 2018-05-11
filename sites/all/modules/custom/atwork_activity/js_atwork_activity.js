function toggleCommentForm(nid) {
  //alert('.comment-form-' + nid);
  jQuery('.comment-form-' + nid).slideToggle();
  jQuery('html, body').animate({
    scrollTop: jQuery('.comment-form-' + nid).offset().top + 'px'
  }, 'fast');
}


(function ($) {
  Drupal.behaviors.atworkActivity = {
    attach: function () {
      $('.comment-form').hide();
      $(".toggle-com-button").before('<span class="comment-icon"></span>');
    }
  };

}(jQuery));
