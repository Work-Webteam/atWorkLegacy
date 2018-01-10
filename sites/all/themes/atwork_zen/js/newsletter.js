jQuery(function () {
	
  jQuery(".node-type-simplenews .outlook-body div").each(function () {
    jQuery(this).css({"height": "102px"});
  });
  jQuery(".node-type-simplenews .outlook-blog-body .outlook-comment-body").each(function () {
	  jQuery(this).css({"margin-top": "10px", "padding-bottom": "25px"});
  });
  jQuery(".node-type-simplenews .outlook-body p").each(function () {
	  jQuery(this).css({"margin-top": "10px"});
  });
  jQuery(".node-type-simplenews .outlook-comment-blog-title h2").each(function () {
	  jQuery(this).css({"margin-bottom": "10px"});
  });
  jQuery(".node-type-simplenews .outlook-feature-title h2").each(function () {
	  jQuery(this).css({"margin-bottom": "10px"});
  });
  jQuery(".node-type-simplenews .article-image img").each(function () {
	  jQuery(this).css({"margin-left": "0"});
  });
  
  jQuery(".node-type-simplenews #comment-body")
    .css({"padding-left": "0"})
    .contents()
      .filter(function() {
        return this.nodeType === 3;
      })
      .wrap('<p style="margin: 0 0 0 15px;"></p>');
  
});
