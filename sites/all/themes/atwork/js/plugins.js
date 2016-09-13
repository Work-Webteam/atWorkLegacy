// place any jQuery or other plugins in here, instead of separate, slower script files. :)

/* 
  get a script from external URL asynchronously
*/
// example usage: getScript('https://dl.dropbox.com/u/7573777/_assets/js/cornify_mod-jb.js', function () { doStuff(); });
function getScript(url, callback) {

  var head = document.documentElement,
    script = document.createElement('script');

  script.src = url;

  var done = false;

  script.onload = script.onreadystatechange = function () {

    if (!done && (!this.readyState || this.readState === "loaded" || this.readState === "complete")) {

      done = true;
      callback();

    }

  };

  head.insertBefore(script, head.firstChild);

  return undefined;

}

/*
  fitvids.js
  https://github.com/davatron5000/FitVids.js
  license - http://sam.zoy.org/wtfpl/
*/
(function( $ ){

  "use strict";

  $.fn.fitVids = function( options ) {
    var settings = {
      customSelector: null
    };

    var div = document.createElement('div'),
        ref = document.getElementsByTagName('base')[0] || document.getElementsByTagName('script')[0];

    div.className = 'fit-vids-style';
    div.innerHTML = '&shy;<style>         \
      .fluid-width-video-wrapper {        \
         width: 100%;                     \
         position: relative;              \
         padding: 0;                      \
      }                                   \
                                          \
      .fluid-width-video-wrapper iframe,  \
      .fluid-width-video-wrapper object,  \
      .fluid-width-video-wrapper embed {  \
         position: absolute;              \
         top: 0;                          \
         left: 0;                         \
         width: 100%;                     \
         height: 100%;                    \
      }                                   \
    </style>';

    ref.parentNode.insertBefore(div,ref);

    if ( options ) {
      $.extend( settings, options );
    }

    return this.each(function(){
      var selectors = [
        "iframe[src*='player.vimeo.com']",
        "iframe[src*='www.youtube.com']",
        "iframe[src*='www.youtube-nocookie.com']",
        "iframe[src*='www.kickstarter.com']",
        "object",
        "embed"
      ];

      if (settings.customSelector) {
        selectors.push(settings.customSelector);
      }

      var $allVideos = $(this).find(selectors.join(','));

      $allVideos.each(function(){
        var $this = $(this);
        if (this.tagName.toLowerCase() === 'embed' && $this.parent('object').length || $this.parent('.fluid-width-video-wrapper').length) { return; }
        var height = ( this.tagName.toLowerCase() === 'object' || ($this.attr('height') && !isNaN(parseInt($this.attr('height'), 10))) ) ? parseInt($this.attr('height'), 10) : $this.height(),
            width = !isNaN(parseInt($this.attr('width'), 10)) ? parseInt($this.attr('width'), 10) : $this.width(),
            aspectRatio = height / width;
        if(!$this.attr('id')){
          var videoID = 'fitvid' + Math.floor(Math.random()*999999);
          $this.attr('id', videoID);
        }
        $this.wrap('<div class="fluid-width-video-wrapper"></div>').parent('.fluid-width-video-wrapper').css('padding-top', (aspectRatio * 100)+"%");
        $this.removeAttr('height').removeAttr('width');
      });
    });
  };
})( jQ );

/* 
  Easy List Splitter
  http://www.madeincima.eu
*/
var j = 1;
 
(function( $ ) {
  jQ.fn.easyListSplitter = function(options) {
  
  var defaults = {      
    colNumber: 2, // Insert here the number of columns you want. Consider that the plugin will create the number of cols requested only if there are enough items in the list.
    direction: 'vertical'
  };
      
  this.each(function() {
    
    var obj = jQ(this);
    var settings = jQ.extend(defaults, options);
    var totalListElements = jQ(this).children('li').size();
    var baseColItems = Math.ceil(totalListElements / settings.colNumber);
    var listClass = jQ(this).attr('class');
    
    // -------- Create List Elements given colNumber ------------------------------------------------------------------------------
    
    for (i=1;i<=settings.colNumber;i++)
    { 
      if(i==1){
        jQ(this).addClass('listCol1').wrap('<div class="listContainer'+j+'"></div>');
      } else if(jQ(this).is('ul')){ // Check whether the list is ordered or unordered
        jQ(this).parents('.listContainer'+j).append('<ul class="listCol'+i+'"></ul>');
      } else{
        jQ(this).parents('.listContainer'+j).append('<ol class="listCol'+i+'"></ol>');
      }
        jQ('.listContainer'+j+' > ul,.listContainer'+j+' > ol').addClass(listClass);
    }
    
    var listItem = 0;
    var k = 1;
    var l = 0;  
    
    if(settings.direction == 'vertical'){ // -------- Append List Elements to the respective listCol  - Vertical -------------------------------
      
      jQ(this).children('li').each(function(){
        listItem = listItem+1;
        if (listItem > baseColItems*(settings.colNumber-1) ){
          jQ(this).parents('.listContainer'+j).find('.listCol'+settings.colNumber).append(this);
        } 
        else {
          if(listItem<=(baseColItems*k)){
            jQ(this).parents('.listContainer'+j).find('.listCol'+k).append(this);
          } 
          else{
            jQ(this).parents('.listContainer'+j).find('.listCol'+(k+1)).append(this);
            k = k+1;
          }
        }
      });
      
      jQ('.listContainer'+j).find('ol,ul').each(function(){
        if(jQ(this).children().size() == 0) {
        jQ(this).remove();
        }
      }); 
      
    } else{  // -------- Append List Elements to the respective listCol  - Horizontal ----------------------------------------------------------
      
      jQ(this).children('li').each(function(){
        l = l+1;

        if(l <= settings.colNumber){
          jQ(this).parents('.listContainer'+j).find('.listCol'+l).append(this);
          
        } else {
          l = 1;
          jQ(this).parents('.listContainer'+j).find('.listCol'+l).append(this);
        }       
      });
    }
    
    jQ('.listContainer'+j).find('ol:last,ul:last').addClass('last'); // Set class last on the last UL or OL 
    j = j+1;
    
  });
  };
})( jQ );

/*
  Placeholder.js
  https://github.com/mathiasbynens/jquery-placeholder
*/
/*! http://mths.be/placeholder v2.0.7 by @mathias */
(function(f,h,$){var a='placeholder' in h.createElement('input'),d='placeholder' in h.createElement('textarea'),i=$.fn,c=$.valHooks,k,j;if(a&&d){j=i.placeholder=function(){return this};j.input=j.textarea=true}else{j=i.placeholder=function(){var l=this;l.filter((a?'textarea':':input')+'[placeholder]').not('.placeholder').bind({'focus.placeholder':b,'blur.placeholder':e}).data('placeholder-enabled',true).trigger('blur.placeholder');return l};j.input=a;j.textarea=d;k={get:function(m){var l=$(m);return l.data('placeholder-enabled')&&l.hasClass('placeholder')?'':m.value},set:function(m,n){var l=$(m);if(!l.data('placeholder-enabled')){return m.value=n}if(n==''){m.value=n;if(m!=h.activeElement){e.call(m)}}else{if(l.hasClass('placeholder')){b.call(m,true,n)||(m.value=n)}else{m.value=n}}return l}};a||(c.input=k);d||(c.textarea=k);$(function(){$(h).delegate('form','submit.placeholder',function(){var l=$('.placeholder',this).each(b);setTimeout(function(){l.each(e)},10)})});$(f).bind('beforeunload.placeholder',function(){$('.placeholder').each(function(){this.value=''})})}function g(m){var l={},n=/^jQuery\d+$/;$.each(m.attributes,function(p,o){if(o.specified&&!n.test(o.name)){l[o.name]=o.value}});return l}function b(m,n){var l=this,o=$(l);if(l.value==o.attr('placeholder')&&o.hasClass('placeholder')){if(o.data('placeholder-password')){o=o.hide().next().show().attr('id',o.removeAttr('id').data('placeholder-id'));if(m===true){return o[0].value=n}o.focus()}else{l.value='';o.removeClass('placeholder');l==h.activeElement&&l.select()}}}function e(){var q,l=this,p=$(l),m=p,o=this.id;if(l.value==''){if(l.type=='password'){if(!p.data('placeholder-textinput')){try{q=p.clone().attr({type:'text'})}catch(n){q=$('<input>').attr($.extend(g(this),{type:'text'}))}q.removeAttr('name').data({'placeholder-password':true,'placeholder-id':o}).bind('focus.placeholder',b);p.data({'placeholder-textinput':q,'placeholder-id':o}).before(q)}p=p.removeAttr('id').hide().prev().attr('id',o).show()}p.addClass('placeholder');p[0].value=p.attr('placeholder')}else{p.removeClass('placeholder')}}}(this,document,jQ));

