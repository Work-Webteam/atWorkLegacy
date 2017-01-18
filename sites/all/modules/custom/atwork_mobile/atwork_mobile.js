(function ($) {
  function set_closed(){
    $("#atwork_menu").children().hide();
    $("#atwork_menu_item_tool_menu").children().hide();
    $("#atwork_menu_item_news_menu").children().hide();
    $("#atwork_menu_item_abps_menu").children().hide();
    //$("#atwork_menu_item_who_we_are_menu").children().hide();
    //$("#atwork_menu_item_corporate_strategies_menu").children().hide();
    //$("#atwork_menu_item_series_menu").children().hide();
    $("#atwork_menu_item_our_community_menu").children().hide();
    $("#atwork_menu_item_engagement_recognition_menu").children().hide();
    //$("#atwork_menu_item_corporate_programs_menu").children().hide();
    //$("#atwork_menu_item_learning_from_the_best_menu").children().hide();
    //$("#atwork_menu_item_resources_menu").children().hide();
    //$("#atwork_menu_item_tools_resources_menu").children().hide();
    //$("#atwork_menu_item_business_menu").children().hide();
    //$("#atwork_menu_item_human_resources_menu").children().hide();
  }

  //Helper function that changes + and - depending on whether a sub header is open or closed
  function menuIcons(e){

    var menuClicked = $(e).parent().parent().attr('id');
    if($(e).first('li').innerHeight() > 1){
      $("li#" + menuClicked + " > span > i").removeClass("fa fa-minus").addClass("fa fa-plus");
    } else {
      $("li#" + menuClicked + " > span > i").removeClass("fa fa-plus").addClass("fa fa-minus");
    }
  }

/**
 * Main function, various click handlers/event listener.
 *
 */
  $(document).ready(function(){
    set_closed();
    $('#full_menu').css('cursor', 'pointer');
    $("#full_menu").css("overflow-y", "auto");
    $('.atwork_menu_top_level').css('cursor', 'pointer');

    // overall menu click
    $("#full_menu").click(function(e){
      $("#atwork_menu").children().slideToggle();
      e.stopPropagation();
    });

    // News menu click
  $("#atwork_menu_item_tool").click(function(e){
      $("#atwork_menu_item_tool_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_tool_menu").children();
      menuIcons(element);
    });
    $("#atwork_menu_item_news").click(function(e){
      $("#atwork_menu_item_news_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_news_menu").children();
      menuIcons(element);
    });
    $("#atwork_menu_item_about_the_bc_public_service").click(function(e){
      $("#atwork_menu_item_abps_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_abps_menu").children();
      menuIcons(element);
    });

    /*$("#atwork_menu_item_who_we_are").click(function(e){
      $("#atwork_menu_item_who_we_are_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_who_we_are_menu").children();
      menuIcons(element);
    });*/

    /*$("#atwork_menu_item_corporate_strategies").click(function(e){
      $("#atwork_menu_item_corporate_strategies_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_corporate_strategies_menu").children();
      menuIcons(element);
    });*/

    /*$("#atwork_menu_item_series").click(function(e){
      $("#atwork_menu_item_series_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_series_menu").children();
      menuIcons(element);
    });*/

    $("#atwork_menu_item_our_community").click(function(e){
      $("#atwork_menu_item_our_community_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_our_community_menu").children();
      menuIcons(element);
    });

    $("#atwork_menu_item_engagement_recognition").click(function(e){
      $("#atwork_menu_item_engagement_recognition_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_engagement_recognition_menu").children();
      menuIcons(element);
    });
    /*$("#atwork_menu_item_corporate_programs").click(function(e){
      $("#atwork_menu_item_corporate_programs_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_corporate_programs_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_learning_from_the_best").click(function(e){
      $("#atwork_menu_item_learning_from_the_best_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_learning_from_the_best_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_resources").click(function(e){
      $("#atwork_menu_item_resources_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_resources_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_tools_resources").click(function(e){
      $("#atwork_menu_item_tools_resources_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_tools_resources_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_business").click(function(e){
      $("#atwork_menu_item_business_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_business_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_human_resources").click(function(e){
      $("#atwork_menu_item_human_resources_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_human_resources_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_technology").click(function(e){
      $("#atwork_menu_item_technology_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_technology_menu").children();
      menuIcons(element);
    });*/
    /*$("#atwork_menu_item_other").click(function(e){
      $("#atwork_menu_item_other_menu").children().slideToggle();
      e.stopPropagation();
      var element = $("#atwork_menu_item_other_menu").children();
      menuIcons(element);
    });*/
    $(".atwork_menu_nested").click(function(e){
      e.stopPropagation();
    });
  });
})(jQuery);
