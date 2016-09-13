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
        $.ajax({ url: base + '/tutorials/ajax/groups/tutorial=admin_true' });
        $.prompt.close();
      }
},
tourStates = [
  {
    // General welcome message
    title: 'Welcome',
    html: 'Welcome to your new @Work groups homepage! We would love to give you a quick tour.',
    buttons: { Next: 1, 'End Tour': 0 },
    focus: 0,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  },
  // Group nav
  {
    title: 'Navigation',
    html: 'This is your group navigation and is automatically generated based on the selections you made when you created the group. You can add items to this nav in the Settings menu.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#block-og-menu-og-single-menu-block', x:177, y:-55, width: 400, arrow:'lm'},
    submit: tourSubmitFunc
  },
    // Group Settings
  {
    title: 'Settings',
    html: 'The Settings menu is where you as a group administrator can find the tools to manage your group. This includes managing content, customizing the navigation and managing group membership.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#block-views-groups-details ul', x:-450, y:-75, width: 400, arrow:'rm'},
    submit: tourSubmitFunc
  },
  // Activity Feed
  {
    title: 'Activity Feed',
    html: 'This Activity Feed displays all the site activity happening in your group. It\'s a handy way of staying up to date on group activities.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#group-activity', x:-425, y:-75, width: 400, arrow:'rm'},
    submit: tourSubmitFunc
  },
    // Activity Feed
  {
    title: 'Group Content',
    html: 'You can add content to your group using these links or by clicking the blue Create buttons found on each content landing page.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#block-views-groups-details ul:last li', x:-440, y:0, width: 400, arrow:'rm'},
    submit: tourSubmitFunc
  },
  // Closing message
  {
    title: 'Enjoy',
    html: 'Thanks for taking the quick tour - we hope you enjoy building your group!',
    buttons: { Prev: -1, 'End Tour': 0 },
    focus: 1,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  }
];
$.prompt(tourStates);

  });

}(jQuery));
