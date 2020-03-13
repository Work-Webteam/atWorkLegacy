<?php
/**
 * @file
 * atwork_feature_events.box.inc
 */

/**
 * Implements hook_default_box().
 */
function atwork_feature_events_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'premiers_awards_navigation';
  $box->plugin_key = 'simple';
  $box->title = 'Premier\'s Awards';
  $box->description = 'Premier\'s Awards Navigation';
  $box->options = array(
    'body' => array(
      'value' => '<p style="TEXT-ALIGN: center"><img alt="" class="image-node_image" src="/sites/default/files/styles/node_image/public/bg/image/2015/1221/premiersawardsmainlogo.jpg" style="width: 220px; height: 159px; border-width: 0px; border-style: solid;" title="[node:title]"></p>

<ul style="margin-bottom: 0px">
	<li><a href="/career/premiers-awards/" title="About">Home</a></li>
	<li><a href="/premiers-award-2018-application">Premier\'s Award 2018&nbsp;Application</a></li>
	<li><a href="/career/premiers-awards/categories" title="Categories, Description and Criteria">Categories</a></li>
	<li><a href="/career/premiers-awards/nominations">Nominations</a></li>
	<li><a href="/career/premiers-awards/premiers-awards-adjudicators-and-judges">Adjudicators and Judges</a></li>
	<!-- <li><a  data-cke-saved-href="/career/premiers-awards/2016/webcasts/registration" href="/career/premiers-awards/2016/webcasts/registration">Webcast Registration</a></li> -->
	<li><a href="/career/premiers-awards/finalists">Finalists and Winners</a></li>
	<li><a href="/career/premiers-awards/ministry-contacts">Ministry Contacts</a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['premiers_awards_navigation'] = $box;

  return $export;
}
