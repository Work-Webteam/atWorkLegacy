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
        $.ajax({ url: base + '/tutorials/ajax/groups/tutorial=true' });
        $.prompt.close();
      }
},
tourStates = [
  {
    // General welcome message
    title: 'Welcome',
    html: 'Welcome to the new @Work groups page! We would love to give you a quick tour.',
    buttons: { Next: 1, 'End Tour': 0 },
    focus: 0,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  },
  // Group tabs
  {
    title: 'Groups page',
    html: 'Check out the 4 featured Groups, picked at random, displayed here...',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.views-row.views-row-2.views-row-even', x:0, y:-155, width: 400, arrow:'bc'},
    submit: tourSubmitFunc
  },

  // Group featured
  {
    title: 'Featured groups',
    html: 'or navigate quickly to the groups you\'ve joined by clicking the My Groups tab.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.views-row.views-row-2.views-row-even', x:0, y:-155, width: 400, arrow:'lb'},
    submit: tourSubmitFunc
  },

  // Create group button
  {
    title: 'Create a Group',
    html: 'Create your own group in 5 easy steps by clicking on this button. Use the search bar, below, to avoid duplicating another group.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.create-group', x: -350, y: 35, width: 400, arrow: 'tr' },
    submit: tourSubmitFunc
  },

    // Join button
  {
    title: 'Join a group',
    html: 'Join any group by clicking on the join link. Joining a group allows you to participate in that group and receive updates.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.views-row.views-row-2.views-row-even', x: -155, y:360, width: 400, arrow: 'tc'},
    submit: tourSubmitFunc
  },

    // Search
  {
    title: 'Group Search',
    html: 'Find groups on topics you\'re interested in by using the search bar.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '#edit-desc-1', x: -100, y:-172, width: 400, arrow: 'bc'},
    submit: tourSubmitFunc
  },


  // Closing message
  {
    title: 'Enjoy',
    html: 'Thanks for taking the quick tour - enjoy the site!',
    buttons: { Prev: -1, 'End Tour': 0 },
    focus: 1,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  }
];
$.prompt(tourStates);

  });

}(jQuery));
