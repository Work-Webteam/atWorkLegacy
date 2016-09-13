<!doctype html>
<!--[if IE 6]>
  <html class="lt-ie10 lt-ie9 lt-ie8 lt-ie7">
<![endif]-->
<!--[if IE 7]>
  <html class="lt-ie10 lt-ie9 lt-ie8">
<![endif]-->
<!--[if IE 8]>
  <html class="lt-ie10 lt-ie9">
<![endif]-->
<!--[if IE 9]>
  <html class="lt-ie10">
<![endif]-->
<!-- 

  IE10 no longer uses conditional comments
  http://stackoverflow.com/questions/9900311/how-do-i-target-only-internet-explorer-10-for-certain-situations-like-internet-e 
  
  Drupal adds class "js" to <html>

-->
<!--[if !IE]><!-->
<html class="not-ie">
<!--<![endif]-->

<head>

  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=8,chrome=1">
  <!-- no touchy line above.. -->

  <!-- BEGIN Drupal $head -->
    <?php print $head; ?>
  <!-- /END Drupal $head -->

  <!-- favicon.ico and apple-touch-icon.png placed in root directory -->

  <title><?php print $head_title; ?></title>

  <!--[if lt IE 9]>
    <script src="<?php print '/' . drupal_get_path('theme', 'atwork')  . '/js/ie/html5shiv-printshiv.js'; ?>"></script>
  <![endif]-->

  <!-- load the latest version of jQuery and always have it available in a specific var ("jQ") -->
  <script src="//ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
  <script>
    jQ = jQuery.noConflict(true);
  </script>

  <!-- BEGIN Drupal styles -->
  <?php print $styles;?>
  <!-- /END Drupal styles -->

  <!-- Font-Awesome http://fortawesome.github.io/Font-Awesome/ -->
  <link rel="stylesheet" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/font-awesome.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />

  <!--
    Responsive Stylesheets

    IE gets the first "basic" stylesheet (styles.css) AND all of the media query CSS stuff (via the conditional IE comments).
    Other browsers get this too (via !IE), but with the quick acid test of the media attribute "only all".
    This is a test for older browsers. In other words, a browser that doesn't support media queries doesn't those styles.

    Important to note:
      - IE will ignore the third set of link tags because of conditional comments.
      - High-tech, modern browsers will get sheet sets 1 and 3.
      - Low-tech browsers will get only the basic experience (stylesheet #1).

    From W3C: "The keyword ‘only’ can also be used to hide style sheets from older user agents. User agents must process media queries starting with ‘only’ as if the ‘only’ keyword was not present." - http://www.w3.org/TR/css3-mediaqueries/#media0
  -->

    <!-- 1. The basic stylesheet, all browers get this. -->
    <link rel="stylesheet" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/styles.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />

    <!-- 2. Special tweaks for Internet Explorer. Make sure IE gets the enhanced stylesheets too. -->
    <!--[if gt IE 6]>
      <link rel="stylesheet" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/320.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />
      <link rel="stylesheet" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/768.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />
      <link rel="stylesheet" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/990.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />
    <![endif]-->

    <!-- 3. Acid test for a modern browser with media query support. ( 'media=only all' ) - Low-Tech devices won't get these. -->
    <!--[if !IE]><!-->
      <link rel="stylesheet" media="only all and (min-width: 320px)" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/320.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />
      <link rel="stylesheet" media="only all and (min-width: 768px)" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/768.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />
      <link rel="stylesheet" media="only all and (min-width: 990px)" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/990.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />
    <!--<![endif]-->

  <!-- /Responsive Stylesheets -->

  <!-- Inline Responsive Styling. Why? In order to use Drupal's cachebusting variable. -->
  <style>
    
    
    
    @media only screen and (min-width: 990px) {
      #page {
        padding: 22px 0 0 0;
        background: url(<?php print '/' . drupal_get_path('theme', 'atwork') . '/images/logo.png'; if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>) no-repeat 0 48px;
      }
      .front #container {
        background: url(<?php print '/' . drupal_get_path('theme', 'atwork') . '/images/front_background.jpg'; if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>) no-repeat center top;
      }
      
      
      
      
      
      
      
    }
  </style>
  <!--[if gt IE 6]>
  <style>
    .front #container {
      background: url(<?php print '/' . drupal_get_path('theme', 'atwork') . '/images/front_background.jpg'; if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>) no-repeat center top;
    }
    #page {
      padding: 22px 0 0 0;
      background: url(<?php print '/' . drupal_get_path('theme', 'atwork') . '/images/logo.png'; if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>) no-repeat 0 48px;
    }
  </style>
  <![endif]-->

  <link rel="stylesheet" media="print" href="<?php print $GLOBALS['base_url']; ?>/sites/all/themes/atwork/css/print.css<?php if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>" />

  <script>
    /*
      patch for Windows 8 phone and IE10. Needs to stay here! http://trentwalton.com/2013/01/16/windows-phone-8-viewport-fix/
    */
    if (navigator.userAgent.match(/IEMobile\/10\.0/)) {
      var msViewportStyle = document.createElement("style");
      msViewportStyle.appendChild(
        document.createTextNode("@-ms-viewport{width:auto!important}")
      );
      document.getElementsByTagName("head")[0].appendChild(msViewportStyle);
    }
  </script>

  <!-- BEGIN Drupal $critps -->
    <?php print $scripts; ?>
  <!-- /END Drupal scripts -->

</head>

<body class="no-js <?php print $classes; ?>" <?php print $attributes;?>>
  <div id="container-wrapper">
    <div id="container">

      <script>
        // remove no-js class if we gots js
        jQ('body').removeClass('no-js');
      </script>

      <?php print $page_top; ?>
      <?php print $page; ?>
      <?php print $page_bottom; ?>

    </div><!-- /#container -->
  </div><!-- /#container-wrapper -->

  <script src="<?php print '/' . drupal_get_path('theme', 'atwork')  . '/js/plugins.js'; if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>"></script>
  <script src="<?php print '/' . drupal_get_path('theme', 'atwork')  . '/js/main.js'; if (variable_get('css_js_query_string', '')) { print('?v=' . variable_get('css_js_query_string', '')); } ?>"></script> 
  
  <?php
    if (_atwork_production_environment()) {
      include '/var/www/html/sites/all/themes/atwork/webtrends/sdc_include.html';
    }
	?>
  
  <!-- http://stackoverflow.com/questions/9809351/ie8-css-font-face-fonts-only-working-for-before-content-on-over-and-sometimes -->
  <!--[if lt IE 9]>
  <script>

    jQ(document).ready(function(){ 

      var head = document.getElementsByTagName('head')[0],
        style = document.createElement('style');
      style.type = 'text/css';
      style.styleSheet.cssText = ':before,:after{content:none !important;}'
      head.appendChild(style);

      setTimeout(function(){
        head.removeChild(style);
      }, 11);

    });

  </script>
  <![endif]-->

</body>

</html>