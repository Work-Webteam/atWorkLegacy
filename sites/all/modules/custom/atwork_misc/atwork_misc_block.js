(function ($) {
  function setupOlympicBlock(){
    $('#olympic_block_roll_up_down').css('cursor', 'pointer');
    $("#twitter-widget-0").css('min-height','');
    $(".twitter-timeline").contents().find("p").css("font-size","10pt");
    $(".twitter-timeline").contents().find("p").css("line-height","normal");
    $("#twitter-widget-0").height(170);
    $('#twitter-widget-0' ).attr( 'src', function ( i, val ) { return val; });
    $("#olympic_block_roll_up_down").text("+ View More");
    $("#olympic_placeholder_for_additional_content").hide();
    //$("#olympic_placeholder_for_additional_content2").hide();
  }

  function resizeOlympicBlock(){
    $("#twitter-widget-0").css('min-height','');
    if($("#twitter-widget-0").height() == 170){
      $("#twitter-widget-0").animate({height:'300px'}, {queue:false, duration:300});
      $("#twitter_feed_div").animate({height:'300px'}, {queue:false, duration:300});
      $("#olympic_medal_count_containers").animate({'marginTop' : "+=55px"});
      $("#olympic_gold_medal_count_container").animate({'marginTop' : "+=40px"});
      $("#olympic_silver_medal_count_container").animate({'marginTop' : "+=40px"});
      $("#olympic_bronze_medal_count_container").animate({'marginTop' : "+=40px"});


      $("#olympic_block_roll_up_down").text("- View Less");
      $("#olympic_placeholder_for_additional_content").slideDown(300);
      //$("#olympic_placeholder_for_additional_content2").slideDown(500);
    } else {
      $("#twitter-widget-0").animate({height:'170px'}, {queue:false, duration:300});
      $("#twitter_feed_div").animate({height:'170px'}, {queue:false, duration:300});
      $("#olympic_medal_count_containers").animate({'marginTop' : "-=55px"});
      $("#olympic_gold_medal_count_container").animate({'marginTop' : "-=40px"});
      $("#olympic_silver_medal_count_container").animate({'marginTop' : "-=40px"});
      $("#olympic_bronze_medal_count_container").animate({'marginTop' : "-=40px"});
      $("#olympic_block_roll_up_down").text("+ View More");
      $("#olympic_placeholder_for_additional_content").slideUp(300);
    }
  }

  function iframeLoadCheck(i){
    // Counter so that we don't run this infinity times if iframe doesn't load properly.
    if(i == 20){
      return;
    }
    //clearTimeout();
    //console.log("iframe check");
    // Have to set this as a var or we get a false positive from Firefox for some reason.
    var widgetCheck = $("#twitter-widget-0").height();
    if(widgetCheck === null || widgetCheck === 0){
      i ++;
      // Recursion until we have an element to resize, or if we try 20 times without success.
      setTimeout(function(){
        iframeLoadCheck(i);
      }, 200);
    } else {
      // Then we can set it
      setupOlympicBlock();
      return;    }
  }

/**
 * Main function, various click handlers/event listener.
 *
 */
  $(document).ready(function(){
    // Can't change iframe sizes until they laod, we will initially wait 200, then recurse to 200
    setTimeout(function(){
        iframeLoadCheck(0);
      }, 200);
    //setupOlympicBlock();
    // overall menu click
    $("#olympic_block_roll_up_down").click(function(){
      resizeOlympicBlock();
    });

  });
})(jQuery);
