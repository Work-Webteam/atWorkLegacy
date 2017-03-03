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
      'help' => t('<p align="center" class="feature_box_yellow
"><strong>**IMPORTANT TO NOTE: If you do not receive these two items, you are not registered**</strong></p>
<p>Once you have entered all the required information and hit the &ldquo;save&rdquo; button at the bottom of the screen, you will receive:</p>
		<ol>
			<li>A confirmation page displaying all of the information you&rsquo;ve entered. Please check this page to ensure the information is accurate and then print a copy for your records. If something is incorrect, please contact the <a href="mailto:longserviceawards@gov.bc.ca?Long%20Service%20Awards">Long Service Awards program</a>.</li>
			<li>An automated confirmation email. </li>
		</ol>'),
    ),
    'lsa_pin_application' => array(
      'name' => t('Service Pin Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('<p>Once you have entered all of the required information and clicked the &ldquo;save&rdquo; button at the bottom of the screen, you will receive:</p>
		<ol>
			<li>A confirmation page displaying all of the information you’ve entered. Please check this page to ensure the information is accurate and then print a copy for your records. If something is incorrect, please contact <a href="mailto:Gillian.Kish@gov.bc.ca">Gillian Kish</a>.</li>
			<li>An automated email thanking you for your registration.</li>
		</ol>'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
