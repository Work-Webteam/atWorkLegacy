(function ($) {
	$(document).ready(function($) {
		
		// Hide table of contents
		$('.page-admin-content-newsletter-creation .form-item.form-item-scs-toc.form-type-checkbox').css('display', 'none');
		
		// Disable input on page 2
		if($('.page-admin-content-newsletter-creation .view-content').text().trim().substring(0,4) === 'Note') {
		    $('.page-admin-content-newsletter-creation #edit-cid').prop('readonly', 'true').css("background-color", "#e1e2dc");
		}
		
		// Hide 'input html format' drop-down
		$('.page-admin-content-newsletter-creation #edit-take-note-format').css('display', 'none');
		$('.page-admin-content-newsletter-creation #edit-did-you-know-format').css('display', 'none');
		
	});
})(jQuery);