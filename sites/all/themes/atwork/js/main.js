/*
  make it safe to use console.log always
  http://www.jquery4u.com/snippets/safe-console-log/
*/
(function(a){function b(){}for(var c="assert,count,debug,dir,dirxml,error,exception,group,groupCollapsed,groupEnd,info,log,markTimeline,profile,profileEnd,time,timeEnd,trace,warn".split(","),d;!!(d=c.pop());){a[d]=a[d]||b;}})
(function(){try{console.log();return window.console;}catch(a){return (window.console={});}}());

/*
  add neat little glyphs and icons where they are needed
*/
jQ('.flag-action').on('click', function() {
  jQ(this).children('.icon-flag').css('color','red');
});

/*
  make placeholder text happen
*/
jQ('.region-pagetop #block-search-form .form-item  input').attr('placeholder', ' Search...');
jQ('#views-exposed-form-wiki-page input#edit-terms').attr('placeholder', ' Search Wikilumbia...');

/*
  print the page when the user clicks the print icon
*/
jQ('.icon-print').click(function() {
  window.print();
});

/*
  expand and collapse the transcripts for videos
*/
// Hide (collapse) the toggle containers on load
jQ('.toggle_container, .toggle_container_plain').hide();

jQ('h2.trigger, span.trigger').click(function(event) {
  event.preventDefault();
  jQ(this).next('.toggle_container').slideToggle('slow');
  jQ(this).parent().next('.toggle_container_plain').slideToggle('slow');
});

/*
  CSS fixes for IE with JS
*/
if (jQuery.browser.msie) {
  jQuery('.region-footer #footer-copyright li').last().css('border','none');
}

//--- FIRE + ATTACH jQUERY PLUGINS TO DOM ELEMENTS :) --- //
// This section is for small scripts that attach functionalities to DOM elements
// these invoke the functions and objects in the file "plugins.js"

/*
  fitvids.js
  https://github.com/davatron5000/FitVids.js/
*/
if (!jQuery.browser.msie) {
  // using fitVids.js on IE seems to break some comment feilds making them
  jQ('.content').fitVids();
}

/*
  Easy List Splitter
*/
jQ('ul#ecardList').easyListSplitter({
  colNumber: 3,
  direction: 'vertical'
});
jQ('#block-atwork_classifieds-categories ul').easyListSplitter({
  colNumber: 4,
  direction: 'vertical'
});
jQ('#block-views-wiki_categories-block ul').easyListSplitter({
  colNumber: 3,
  direction: 'vertical'
});

/*
  placeholder.js
*/
jQ(document).ready(function() {
  jQ('input, textarea').placeholder();
});

// --- END ATTACH jQUERIES --- //
