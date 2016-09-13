/**
 * JS function for tool tips
 * Library from: http://trentrichardson.com/Impromptu/
 */

(function ($) {

  $( document ).ready(function(){
    //$.prompt("Hello World!");

var tourSubmitFunc = function(e,v,m,f){
      if(v === -1){
        $.prompt.prevState();
        return false;
      }
      else if(v === 1){
        $.prompt.nextState();
        return false;
      }
      else if(v === 0){
        var base = window.location.protocol + "//" + window.location.host;
        $.ajax({ url: base + '/tutorials/ajax/tutorial=true' });
        $.prompt.close();
      }
},
tourStates = [
  {
    // General welcome message
    title: 'Welcome',
    html: 'Welcome to the new @Work, we are excited to show you some of our new functionality.',
    buttons: { Next: 1, 'End Tour': 0 },
    focus: 0,
    position: { container: '#views_slideshow_cycle_div_home_page_blocks_zen-block_5_0', x: 300, y: 0, width: 400 },
    submit: tourSubmitFunc
  },
  // Blue bar top
  {
    title: 'Blue Ribbon',
    html: 'This blue ribbon is your quick connection to other key government websites.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#block-atwork-profiles-header', x:0, y:45, width: 400, arrow:'tc'},
    submit: tourSubmitFunc
  },

  // User menu top
  {
    title: 'Your Menu',
    html: 'Here\'s where you\'ll find links to manage all your personal content and change your notification preferences.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#header-user-name', x: -150, y: 30, width: 400, arrow: 'tc' },
    submit: tourSubmitFunc
  },

    // Top Tools
  {
    title: 'Top Tools',
    html: 'This Top Tools menu appears on every page so that you can quickly access the websites and applications you use the most.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#top-tools-panel', x: -432, y:50, width: 400, arrow: 'rm'},
    submit: tourSubmitFunc
  },

    // Slider
  {
    title: 'Top News',
    html: 'Top News items featuring business relevant information appear in this carousel.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#views-slideshow-xtra-overlay--home-page-blocks-zen--attachment-4', x: 0, y:200, width: 400, arrow: 'tc'},
    submit: tourSubmitFunc
  },


  // Middle Blocks
  {
    title: "Curated Content",
    html: 'Curated content from across @Work is featured in this row.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: {container: '#block-views-home-page-blocks-zen-block-3', x: -45, y: -130, width: 400, arrow: 'bc'},
    submit: tourSubmitFunc
  },

  // Main activity feed
  {
    title: "Current Activity",
    html: 'Stay abreast of the @Work community\'s activities using these 4 tabs. My Activity and My Groups are personal to you.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#tabs', x: 225, y: -195, width: 400, arrow: 'bc' },
    submit: tourSubmitFunc
  },

  // Employee Photos
  {
    title: "Employee Contributed Photos",
    html: 'Share your photos with fellow employees in one of the @Work photo galleries or create your own. A handful of the best are featured here.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#block-views-gallery-reference-block-2', x: 0, y: -125, width: 400, arrow: 'bc'},
    submit: tourSubmitFunc
  },

  // Employees onsite
  {
    title: "Employees Online",
    html: "Check out how many fellow employees are on @Work right now",
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#users_online', x: -50, y: -145, width: 400, arrow: 'bc'},
    submit: tourSubmitFunc
  },

  // Closing message
  {
    title: 'Enjoy',
    html: 'Thanks for taking the quick tour - enjoy the site!',
    buttons: { 'End Tour': 0 },
    focus: 0,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  }
];
$.prompt(tourStates);

  });

}(jQuery));
