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
		
		// Place title instructions on newsleter creation page.
		$('.page-node-add-simplenews #simplenews-node-form .form-item-title label').append('<p style="margin-top: 0; font-weight: normal;">Type or paste the newsletter title in the field above. The title you submit will appear as the subject line in the newsletter email<br>The typical title is: @Work Newsletter | (date)<br>	Example: @Work Newsletter | November 15, 2017</p>');

		
		// Place title instructions on newsleter creation page.
		$('.page-node-add-simplenews #simplenews-node-form #edit-body .form-item-body-und-0-value label').append('<p style="margin-top: 0; font-weight: normal;">Please review the newsletter below and ensure everything is as you\'d like. You may make edits at this point if needed. Once ready, click on the radio button beside "@Work Newsletter" under the heading "Newsletter category" below. Click on "Authoring Information" and remove your idir so that it defaults to EmployeeNews. Ensure under the "Publishing Option" that everything is unclicked. Then hit save. </p>');
		
		// Hide CKeditor instructions on newsletter confirmation page
		if($('#views-form-newsletter-creation-page').attr('action') === '/node/add/simplenews') {
			$('#views-form-newsletter-creation-page .text-format-wrapper .description').replaceWith('<br><br><br>');
		}
		
	});
})(jQuery);