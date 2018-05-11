function hideProgress() {
  jQuery('.activity-feed-progress').hide();
}
function showProgress() {
  jQuery('.activity-feed-progress').show();
}
function refreshAllActivity(page) {
	if(!page) page = 0;

	jQuery.ajax({
		cache: false,
		url: Drupal.settings.basePath + '?q=atwork-activity/all-activity/tab_1',
		data: {page: page},
		dataType: 'text',
		error: function(request, status, error) {
			//alert(status);
		},
		success: function(data) {
			var html = data;

                        hideProgress();

			jQuery('#tabs-1').html(html);

			jQuery('#tabs-1 .pager-item a')
				.add('#tabs-1 .pager-first a')
				.add('#tabs-1 .pager-previous a')
				.add('#tabs-1 .pager-next a')
				.add('#tabs-1 .pager-last a')
					.click(function(el) {
                                                showProgress();
						let url = jQuery.url(el.currentTarget.getAttribute('href'));
						refreshAllActivity(url.param('page'));
						return (false);
					});
		}
	});
}

function refreshGroupActivity(page) {
	if(!page) page = 0;

	jQuery.ajax({
		cache: false,
		url: Drupal.settings.basePath + '?q=atwork-activity/group-activity/tab_0',
		data: {page: page},
		dataType: 'text',
		error: function(request, status, error) {
			//alert(status);
		},
		success: function(data) {
			let html = data;

                        hideProgress();

			jQuery('#tabs-2').html(html);

			jQuery('#tabs-2 .pager-item a')
				.add('#tabs-2 .pager-first a')
				.add('#tabs-2 .pager-previous a')
				.add('#tabs-2 .pager-next a')
				.add('#tabs-2 .pager-last a')
					.click(function(el) {
                                                showProgress();
						var url = jQuery.url(el.currentTarget.getAttribute('href'));
						refreshGroupActivity(url.param('page'));

						return (false);
					});
		}
	});
}

function refreshCommentActivity(page) {
	if(!page) page = 0;

	jQuery.ajax({
		cache: false,
		url: Drupal.settings.basePath + '?q=atwork-activity/comment-activity/tab_0',
		data: {page: page},
		dataType: 'text',
		error: function(request, status, error) {
			//alert(status);
		},
		success: function(data) {
			let html = data;

			hideProgress();

			jQuery('#tabs-4').html(html);

			jQuery('#tabs-4 .pager-item a')
				.add('#tabs-4 .pager-first a')
				.add('#tabs-4 .pager-previous a')
				.add('#tabs-4 .pager-next a')
				.add('#tabs-4 .pager-last a')
					.click(function(el, a, b, c) {
					  showProgress();
						let url = jQuery.url(el.currentTarget.getAttribute('href'));
						refreshCommentActivity(url.param('page'));

						return (false);
					});
		}
	});
}

function refreshMyActivity(page) {
	if(!page) page = 0;

	jQuery.ajax({
		cache: false,
		url: Drupal.settings.basePath + '?q=atwork-activity/my-activity/tab_0',
		data: {page: page},
		dataType: 'text',
		error: function(request, status, error) {
			//alert(status);
		},
		success: function(data) {
			var html = data;

                        hideProgress();

			jQuery('#tabs-3').html(html);

			jQuery('#tabs-3 .pager-item a')
				.add('#tabs-3 .pager-first a')
				.add('#tabs-3 .pager-previous a')
				.add('#tabs-3 .pager-next a')
				.add('#tabs-3 .pager-last a')
					.click(function(el) {
					  showProgress();
						var url = jQuery.url(el.currentTarget.getAttribute('href'));
						refreshMyActivity(url.param('page'));

						return (false);
					});
		}
	});
}

function initializeAllActivity() {
	jQuery(document).ready(function() {
		refreshAllActivity();
	});
}
      /// this is now handled by click-handlers - too much strain on queries otherwise

/*
function initializeGroupActivity() {
	jQuery(document).ready(function() {
		refreshGroupActivity();
	});
}
function initializeCommentActivity() {
	jQuery(document).ready(function() {
		refreshCommentActivity();
	});
}
function initializeMyActivity() {
	jQuery(document).ready(function() {
		refreshMyActivity();
	});
}
*/
