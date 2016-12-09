

(function ($) {

  /*
  function hideProgress() {
    jQuery('.activity-feed-progress').hide();
  }
  function showProgress() {
    jQuery('.activity-feed-progress').show();
  }

  function refreshAllActivityClick(page) {
    if(!page) page = 0;
    console.log("click");
    jQuery.ajax({
      cache: false,
      url: Drupal.settings.basePath + '?q=atwork-activity/all-activity/tab_1',
      data: {page: page},
      dataType: 'text',
      error: function(request, status, error) {
        //alert(status);
      },
      success: function(data, status, request) {
        var html = data;
        console.log("clicked");
                          hideProgress();

        jQuery('#tabs-1').html(html);

        jQuery('#tabs-1 .pager-item a')
          .add('#tabs-1 .pager-first a')
          .add('#tabs-1 .pager-previous a')
          .add('#tabs-1 .pager-next a')
          .add('#tabs-1 .pager-last a')
            .click(function(el, a, b, c) {
                                                  showProgress();
              var url = jQuery.url(el.currentTarget.getAttribute('href'));
              console.log(url);
              refreshAllActivityClick(url.param('page'));

              return (false);
            });
      }
    });
  }

  /*

  function refreshGroupActivityClick(page) {
    if(!page) page = 0;

    jQuery.ajax({
      cache: false,
      url: Drupal.settings.basePath + '?q=atwork-activity/group-activity/tab_2',
      data: {page: page},
      dataType: 'text',
      error: function(request, status, error) {
        alert(status);
      },
      success: function(data, status, request) {
        var html = data;

                          hideProgress();

        jQuery('#tabs-2').html(html);

        jQuery('#tabs-2 .pager-item a')
          .add('#tabs-2 .pager-first a')
          .add('#tabs-2 .pager-previous a')
          .add('#tabs-2 .pager-next a')
          .add('#tabs-2 .pager-last a')
            .click(function(el, a, b, c) {
                                                  showProgress();
              var url = jQuery.url(el.currentTarget.getAttribute('href'));
              refreshGroupActivityClick(url.param('page'));

              return (false);
            });
      }
    });
  }

  function refreshCommentActivityClick(page) {
    if(!page) page = 0;

    jQuery.ajax({
      cache: false,
      url: Drupal.settings.basePath + '?q=atwork-activity/comment-activity/tab_4',
      data: {page: page},
      dataType: 'text',
      error: function(request, status, error) {
        alert(status);
      },
      success: function(data, status, request) {
        var html = data;

                          hideProgress();

        jQuery('#tabs-4').html(html);

        jQuery('#tabs-4 .pager-item a')
          .add('#tabs-4 .pager-first a')
          .add('#tabs-4 .pager-previous a')
          .add('#tabs-4 .pager-next a')
          .add('#tabs-4 .pager-last a')
            .click(function(el, a, b, c) {
                                                  showProgress();
              var url = jQuery.url(el.currentTarget.getAttribute('href'));
              refreshCommentActivityClick(url.param('page'));

              return (false);
            });
      }
    });
  }
  */
 /*
  function refreshMyActivityClick(page) {
    if(!page) page = 0;

    jQuery.ajax({
      cache: false,
      url: Drupal.settings.basePath + '?q=atwork-activity/my-activity/tab_3',
      data: {page: page},
      dataType: 'text',
      error: function(request, status, error) {
        alert(status);
      },
      success: function(data, status, request) {
        var html = data;

                          hideProgress();

        jQuery('#tabs-3').html(html);

        jQuery('#tabs-3 .pager-item a')
          .add('#tabs-3 .pager-first a')
          .add('#tabs-3 .pager-previous a')
          .add('#tabs-3 .pager-next a')
          .add('#tabs-3 .pager-last a')
            .click(function(el, a, b, c) {
                                                  showProgress();
              var url = jQuery.url(el.currentTarget.getAttribute('href'));
              refreshMyActivityClick(url.param('page'));

              return (false);
            });
      }
    });
  }

/**
 * Main function, various click handlers.
 *
 */
/*
  $(document).ready(function(){
    // Set click handlers to update feeds on click
    // This way we don't query the db unless we actually want the info
    $("#ui-id-1").mousedown(function(){
      refreshAllActivityClick();
    });
    /*
    $("#ui-id-4").mousedown(function(){
      refreshGroupActivityClick();
    });
    $("#ui-id-2").mousedown(function(){
      refreshCommentActivityClick();
    });

    $("#ui-id-3").mousedown(function(){
      refreshMyActivityClick();
    });

  });
  */

})(jQuery);
