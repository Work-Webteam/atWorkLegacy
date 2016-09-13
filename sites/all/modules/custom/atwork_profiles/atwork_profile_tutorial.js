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
        $.ajax({ url: base + '/tutorials/ajax/profile/tutorial=true' });
        $.prompt.close();
      }
},
tourStates = [
  {
    // General welcome message
    title: 'Welcome',
    html: 'This quickie tour is your starting point to update, edit and publish your profile on @Work.',
    buttons: { 'Take tour': 1, 'End tour': 0 },
    focus: 0,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  },
  // Gal info
  {
    title: 'Your information',
    html: 'The title and contact info displayed comes from the Global Address List (GAL) in Outlook.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.field.field-name-field-gal-title.field-type-text.field-label-hidden', x:380, y:-55, width: 400, arrow:'lm'},
    submit: tourSubmitFunc
  },
    // Edit tab
  {
    title: 'Getting started',
    html: 'Your employee profile takes only minutes to complete. Click the Edit tab to add a profile photo, describe your work history and list your skills and interests. You can publish or unpublish your extra <font color="red">(non-GAL)</font> profile information at any time.',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.tabs-primary.tabs.primary', x:50, y:-200, width: 400, arrow:'bl'},
    submit: tourSubmitFunc
  },
      //Skills & Interests
  {
    title: 'Skills and interests ',
    html: 'Adding your skills and interests to your profile lets you (and others) search for people with similar or sought after skills. </br> </br><strong>As an example:</strong> You could search for facilitation skills in Prince George.</br></br><strong>Tip:</strong> Add skills/interests that are short (a word or two, rather than sentences).',
    buttons: { Prev: -1, Next: 1, 'End Tour': 0 },
    focus: 1,
    position: { container: '.skills-profile-section', x:-75, y:-280, width: 400, arrow:'bc'},
    submit: tourSubmitFunc
  },
  // Closing message
  {
    title: 'End of your tour',
    html: 'To see this tour again, select the Edit tab above your profile image and look for the options under Tours.',
    buttons: { Prev: -1, 'End Tour': 0 },
    focus: 1,
    position: { container: '', x: 0, y: 0, width: 400 },
    submit: tourSubmitFunc
  }
];
$.prompt(tourStates);

  });

}(jQuery));
