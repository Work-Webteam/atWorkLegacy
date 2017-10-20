/************************************************************************
 * 	nav_toggle_v2.0														*
 *	written by Thayne Werdal											*
 *	Intended to enhance theme functionality								*
 *  jQuery for the persistent Navigation bar in the zen_atwork theme.	*
 *  26, January, 2015													*
 ***********************************************************************/



(function($) {
Drupal.behaviors.atwork_quicklinks = {
  attach: function (context, settings) {
 /*
	// Variable to track cookie state
	var $navOpen = '';

	// Check for cookie
	if($.cookie('navStatus')) {
		//console.log($.cookie('navStatus'));
		$navOpen = $.cookie('navStatus');
		// If user had previously closed the nav, toggle closed on page load
		if($navOpen == "closed") {
			$("#top-tools-panel", context).find(".ext").toggle();
		}

	} else {
		// Create a new cookie that lets us know nav is opened
		$.cookie('navStatus', 'opened', {expires: 30, path: '/'}); // Expires in thirty day, cookie accessible across site
	}

	// User clicks down carat, Navigation bar closes links section
	$("#quickfooter .fa.fa-caret-down").on("click", function(){
			$navOpen = "opened";
			// Refresh cookie state and value
			//$.cookie('navStatus', '' { path: '/'});
			$.cookie('navStatus', 'opened', {expires: 30, path: '/'});
			//console.log($.cookie('navStatus'));
			$("#top-tools-panel", context).find(".ext").slideDown("slow");
			//$("#top-tools-panel").slideDown;
	});

	// User clicks up carat, Navigation bar opens links section
	$("#quickfooter .fa.fa-caret-up").on("click", function(){
			$navOpen = "closed";
			// Refresh cookie state and value
			//$.cookie('navStatus', '' { path: '/'});
			$.cookie('navStatus', 'closed', {expires: 30, path: '/'});
  		//console.log($.cookie('navStatus'));
			$("#top-tools-panel", context).find(".ext").slideUp("slow");
			//$("#top-tools-panel").slideUp;
	});

	// Feedback on mouseclick for user
	$("#quickfooter .fa.fa-caret-down").mousedown(function() {
		$(this).css("background-color", "#D7D7D7");
	});
	$("#quickfooter .fa.fa-caret-down").mouseup(function() {
		$(this).css("background-color", "#008D7B");
	});

	// Feedback on mouseclick for user
	$("#top-tools-panel .fa.fa-caret-up").mousedown(function() {
		$(this).css("background-color", "#D7D7D7");
	});
	$("#top-tools-panel .fa.fa-caret-up").mouseup(function() {
		$(this).css("background-color", "#008D7B");
	});
	*/

	// User profile menu actions:
  	$("#header-user-name").mousedown(function(){
    	$("#header-user-dropdown").slideDown();
  	});
  	$("#header-user-dropdown").mouseleave(function(){
    	$("#header-user-dropdown").hide();
  	});

	$(window).scroll(function(){
		$(".region-navigation").css("top", Math.max(-2, 162 - $(window).scrollTop()));
		$("#block-tb-megamenu-menu-moderator-menu").css("top", Math.max(-2, 162 - $(window).scrollTop()));
		$("#block-tb-megamenu-menu-lsa-admin").css("top", Math.max(-2, 162 - $(window).scrollTop()));
		$(".view-top-tools").css("top", Math.max(30, 225 - $(window).scrollTop()));
	});

	if($(window).scrollTop() === -2){

		$(".region-navigation").css("top", 162);
		$("#block-tb-megamenu-menu-moderator-menu").css("top", 162);
		$("#block-tb-megamenu-menu-lsa-admin").css("top", 162);
		$(".view-top-tools").css("top", 225);
	} else if ($(window).scrollTop() < 162){
		var $navbarPos = 162 - $(window).scrollTop();
		$(".region-navigation").css("top", $navbarPos)
	} else {
		$(".region-navigation").css("top", -2)
	}
	// Short term code to give a title on hover to banner div
	//$('#header-box').prop('title', "First day of spring - March 20");
    //code ends
  }
};
})(jQuery);






