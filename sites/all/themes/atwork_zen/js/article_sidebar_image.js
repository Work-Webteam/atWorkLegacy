jQuery(function () {
  jQuery(".node-type-article .region-sidebar-second .image-node_full").each(function () {
    if(jQuery(this).attr('title') === '[node:title]') {
    	jQuery(this).attr('title', jQuery("#page-title").text());
    } 
  });
});
