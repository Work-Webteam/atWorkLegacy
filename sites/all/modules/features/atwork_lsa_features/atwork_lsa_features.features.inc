<?php
/**
 * @file
 * atwork_lsa_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function atwork_lsa_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function atwork_lsa_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function atwork_lsa_features_node_info() {
  $items = array(
    'lsa_application' => array(
      'name' => t('Long Service Awards Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('<p>Once you have entered all the required information and hit the &ldquo;SUBMIT&rdquo; button at the bottom of the screen, you will receive:</p>
		<ol>
			<li>A confirmation page displaying all of the information you&rsquo;ve entered. If something is incorrect, please contact the <a href="mailto:longserviceawards@gov.bc.ca?Long%20Service%20Awards">Long Service Awards</a> team.</li>
			<li>An automated confirmation email. </li>
		</ol>
<p><span style="color:red;" class="red-text">* If you do not receive these two items, your registration was not received. </span></p>
<p>Please review the <a href="/career/long-service-awards/award-catalogue" target="_blank">LSA Award Catalogue</a> prior to filling out the registration form.</p>'),
    ),
    'lsa_pin_application' => array(
      'name' => t('Service Pin Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
