<?php

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to override it. Available templates:
 *   simplenews-newsletter-body--[tid].tpl.php
 *   simplenews-newsletter-body--[view mode].tpl.php
 *   simplenews-newsletter-body--[tid]--[view mode].tpl.php
 * See README.txt for more details.
 *
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $title: Node title
 * - $language: Language code
 * - $view_mode: Active view mode
 * - $simplenews_theme: Contains the path to the configured mail theme.
 * - $simplenews_subscriber: The subscriber for which the newsletter is built.
 *   Note that depending on the used caching strategy, the generated body might
 *   be used for multiple subscribers. If you created personalized newsletters
 *   and can't use tokens for that, make sure to disable caching or write a
 *   custom caching strategy implemention.
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */
?>

<table bgcolor="#ECECEC" width="900" align="center">
	<tr>
		<td >

<?php 


if (arg(0) == 'node' && is_numeric(arg(1))) {
	//dpm($node);

	// Get the nid.
	$newsletter_nid = ($build['#node']->nid);

	// Load th node if you need to
	
	//$node = noad_load($nid);
	// $atwork_newsletter_location = $node -> nid; 

	$atwork_newsletter_aliased = drupal_get_path_alias('node/'.$newsletter_nid);
	echo '<p align="center"><a style="text-decoration:none;" href="https://gww.gov.bc.ca/' . $atwork_newsletter_aliased . '"> View in browser </a></p>';
	
}

// use the template from simplenews content selection
print render($build); 
	
?>
		</td>
	</tr>
</table>