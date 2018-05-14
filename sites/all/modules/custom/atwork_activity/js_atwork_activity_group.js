function hideProgress() {
  jQuery('.activity-feed-progress').hide();
}
function showProgress() {
  jQuery('.activity-feed-progress').show();
}
function refreshActivity(page) {
	if(!page) page = 0;
	jQuery.ajax({
		cache: false,
		url: Drupal.settings.basePath + '?q=atwork-activity/group/' + Drupal.settings.ogContext.gid,
		data: {page: page},
		dataType: 'text',
		error: function(request, status) {
			alert(status);
		},
		success: function(data) {
			var html = data;
			hideProgress();
			jQuery('#group-activity-ajax').html(html);
\			jQuery('#group-activity-ajax .pager-item a')
				.add('#group-activity-ajax .pager-first a')
				.add('#group-activity-ajax .pager-previous a')
				.add('#group-activity-ajax .pager-next a')
				.add('#group-activity-ajax .pager-last a')
					.click(function(el, a, b, c) {
					  showProgress();

						let url = jQuery.url(el.currentTarget.getAttribute('href'));
						refreshActivity(url.param('page'));

						return (false);
					});
		}
	});
}

function initializeActivity() {
	jQuery(document).ready(function() {
		refreshActivity();
	});
}
