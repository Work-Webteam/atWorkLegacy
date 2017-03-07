<?php
/**
 * @file
 * atwork_lsa_features.box.inc
 */

/**
 * Implements hook_default_box().
 */
function atwork_lsa_features_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'long_service_awards_navigation';
  $box->plugin_key = 'simple';
  $box->title = 'Long Service Awards';
  $box->description = 'Long Service Awards';
  $box->options = array(
    'body' => array(
      'value' => '<p style="text-align: center;"><img alt="" class="image-node_image" src="/sites/default/files/styles/node_image/public/bg/image/2016/0308/LongServiceAwards_2017_Feb21.png" style="width: 200px; height: 197px;" title="Long Service Awards"></p>

<ul>
	<li><a href="/career/long-service-awards" title="Home">Home</a></li>
	<li><a href="/career/long-service-awards/eligibility" title="Eligibility">Eligibility</a></li>
	<li><a href="/career/long-service-awards/eligibility/entities">Eligible Entities</a></li>
	<li><a href="/career/long-service-awards/award-catalogue">Award Catalogue</a></li>
	<li><a href="/career/long-service-awards/ceremonies" title="Ceremony Dates &amp; Recipients">Ceremonies</a></li>
	<li><a href="/career/long-service-awards/2016-recipients">Recipient List</a></li>
	<li><a href="/career/long-service-awards/volunteering">Volunteering</a></li>
	<li><a href="/career/long-service-awards/eligibility/policy">Policy</a></li>
	<li><a href="/career/long-service-awards/faq">FAQs</a></li>
	<li><a href="/career/long-service-awards/long_service_awards_contacts">Contacts</a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['long_service_awards_navigation'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'lsa_admin_links';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'LSA Admin Links';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="/administration/long-service-awards">Long Service Awards Administration</a></p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['lsa_admin_links'] = $box;

  return $export;
}
