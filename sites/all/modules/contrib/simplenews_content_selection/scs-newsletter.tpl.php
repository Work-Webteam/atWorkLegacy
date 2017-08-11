<?php
/**
 * This template is used to assemble all nodes selected during newsletter
 * creation with Simplenews Content Selection.
 *
 * The following variables are available:
 *    - $toc Table of content, if it exists, as generated by the function
 *    theme_scs_toc() or your own.
 *    - $nodes Array of built selected nodes, ready to be outputed with the
 *    render() function.
 */
?>
<?php 

	// Function to encode images:
   	//function getDataURI($image, $mime = '') {
	//	return 'data: '.(function_exists('mime_content_type') ? mime_content_type($image) : $mime).';base64,'. base64_encode(file_get_contents($image));
	//}
	dpm($nodes);
	dpm($comment);
	dpm($notes);
	// Grab current date for webtrends
    $currentDate = "?nl=" . date("dmy");
    $atwork_base_url = $GLOBALS['base_url'];
 ?>
<?php //********************* Header section ********************* ?>

<table width="775" border="0" align="center" cellpadding="0" cellspacing="0" id="sn-newsletter-layout" style="background-color: #FFF;">
  <tr>
    <td style="background-color:#FFF;"><table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-newsletter-header">
        <tr>
          <td align="right" style="background-color:#004B8D; font-family: Calibri, sans-serif; font-size:11pt; color:#FFF; padding-right:15px; padding-top: 5px; padding-bottom:5px; "><?php  echo "[node:title]" ?></td>
        </tr>
        <tr>
          <td bgcolor="#FFFFFF" align="center" valign="middle" style="border: none;"><?php echo '<a href="' . $atwork_base_url . $currentDate . '"> <img src = "' . $atwork_base_url . '/sites/all/themes/atwork/images/atwork-logo-newsletter.png?nltest=testbanner" width="439" height="93" border="0" /> </a></td>'; ?>
        </tr>
        <?php //***************** feature section ***********************  ?>
        <?php


		// Grab all keys from $nodes var
		$nids = array_keys($nodes);

		/****************************   Check to see if this is an executive (single story) mailing. **********************/
		if (isset($nids[0]) && !isset($nids[1])):
			// Load render node for feature spot.
			$node_first = node_load($nids[0]);
			// dpm($node_first);

			// collect title and url alias of original node
			$atwork_newsletter_title = $node_first -> title;
			$atwork_newsletter_location = $node_first -> nid;

			//Build aliased URL with webtrends query tag
			$atwork_newsletter_aliased = drupal_get_path_alias('node/'.$atwork_newsletter_location) . $currentDate;
			//dpm($atwork_newsletter_aliased);

			// Collect title and url for output
			$output_atwork_newsletter_title = '<div id="feature_title"><h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; color:#004B8D; margin-top: 10px; margin-left: 10px; margin-right: 10px; line-height: 24px;"><a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased . '" >' . $atwork_newsletter_title . '</a></h2></div>';
			// collect teaser of news story for output.
			$atwork_newsletter_body = field_get_items('node',$node_first, 'body');


			// Grab image for render.
			$image = field_get_items('node', $node_first, 'field_image');
			$image_output = field_view_value('node', $node_first, 'field_image', $image[1], array(
  				'type' => 'image',
  				'settings' => array(
    			'image_style' => 'atwork_newsletter_feature_image',
    			'image_link' => 'content',
  				),
			));

			$image_output['#path']['path'] = $atwork_base_url . '/' . $atwork_newsletter_aliased;

			//$im = $image_output['#item']['uri'];

			//dpm($im);

			//$image_output2 = getDataURI($im);

			// Output tag line
			echo '<tr>';
          	echo '<td align="center" style="background-color:#ECECEC; font-family: Calibri, sans-serif; font-size:10pt; letter-spacing: 4px; padding-top: 5px; padding-bottom: 5px; border:none;">' . "&bull; EXECUTIVE UPDATE &bull;" . '</td>';
        	echo '</tr>';
      		echo '</table>';


			//Output image
			echo '<table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-newsletter-feature" style="background-color:#FFF;">';

			echo '<tr>';
			echo '<td>';
			echo '<div id="feature-image" name="featureimage" width="775" height="250" style="background-color:#FFF;">';
			echo render($image_output);
			//echo '<img src="'. $image_output2 .'" />';
			echo '</div>';
			echo '</td>';
			echo '</tr>';


			echo '<tr>';
			//Output title
			echo '<td>';
			echo '<table width="100%" border="0" cellpadding="0" cellspacing="0" id="sn-feature-title">';
			echo '<tr>';
			echo '<td width="348" height="110" valign="top">';
			echo '<div id="feature-title">';
			echo $output_atwork_newsletter_title;
			echo '</div>';
			echo '</td>';

			// Output teaser
			echo '<td width="55%" valign="top">';
			echo '<div id="feature-teaser">';
			echo '<table width="100%" border="0" cellspacing="0" cellpadding="0">';
			echo '<tr>';
			echo '<td height="110" valign="top">';
			echo '<p style="font-family: Calibri, sans-serif; font-size:11pt; color:#004B8D; margin-top: 10px; margin-right: 10px; line-height: 20px;">';
			echo $atwork_newsletter_body[0]['summary'];
			echo '</p>';
			echo '</div>';
			echo '</td>';
			echo '</tr>';
			echo '<tr>';
			echo '<td>';
			echo '<p style="margin-bottom: 10px;"><a style="font-family: Calibri, sans-serif; text-decoration: none; display: block; font-size: 10pt; line-height: 20px; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased . '"> Read more >> </a></p>';
			echo '</td>';
			echo '</tr>';
			echo '<tr>';
			echo '<td align="right">';
			echo '<div class="content-type">';
			echo '<p style="font-family: Calibri, sans-serif; font-size:10pt; margin-right:10px; margin-bottom: 10px; padding-top: 10px; padding-right: 10px; border-top: solid 1px #000;"> <a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . $currentDate . '"> News </a> </p>';
			echo '</div>';
			echo '</td>';
			echo '</tr>';
			echo '</div>';
			echo '</table>';
			echo '</table>';
			echo '<table width="775" border="0" align="center" cellpadding="0" cellspacing="0" >';

		/***************  Not an executive (single story) mailing, build full newsletter *****************************************/
		else:

			if(isset($nids[0])){
				// Load render node for feature spot.
				$node_first = node_load($nids[0]);
				// dpm($node_first);

				// collect title and url alias of original node
				$atwork_newsletter_title = $node_first -> title;
				$atwork_newsletter_location = $node_first -> nid;

				//Build aliased URL with webtrends query tag
				$atwork_newsletter_aliased = drupal_get_path_alias('node/'.$atwork_newsletter_location) . $currentDate;
				//dpm($atwork_newsletter_aliased);

				// Collect title and url for output
				$output_atwork_newsletter_title = '<div id="feature_title"><h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; color:#004B8D; margin-top: 10px; margin-left: 10px; margin-right: 10px; line-height: 24px;"><a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased . '" >' . $atwork_newsletter_title . '</a></h2></div>';
				// collect teaser of news story for output.
				$atwork_newsletter_body = field_get_items('node',$node_first, 'body');


				// Grab image for render.
				$image = field_get_items('node', $node_first, 'field_image');
				$image_output = field_view_value('node', $node_first, 'field_image', $image[1], array(
						'type' => 'image',
						'settings' => array(
					'image_style' => 'atwork_newsletter_feature_image',
					'image_link' => 'content',
						),
				));

				$image_output['#path']['path'] = $atwork_base_url . '/' . $atwork_newsletter_aliased;


				// Output tag line
				echo '<tr>';
          		echo '<td align="center" style="background-color:#ECECEC; font-family: Calibri, sans-serif; font-size:10pt; letter-spacing: 4px; padding-top: 5px; padding-bottom: 5px; border:none;">' . "&bull; A SELECTION OF WHAT'S MAKING NEWS RIGHT NOW &bull;" . '</td>';
        		echo '</tr>';
      			echo '</table>';


				//Output image
				echo '<table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-newsletter-feature">';

				echo '<tr>';
				echo '<td>';
				echo '<div id="feature-image" name="featureimage" width="775" height="250">';
				echo render($image_output);
				echo '</div>';
				echo '</td>';
				echo '</tr>';


				echo '<tr>';
				//Output title
				echo '<td>';
				echo '<table width="100%" border="0" cellpadding="0" cellspacing="0" id="sn-feature-title" style="background-color:#FFF;">';
				echo '<tr>';
				echo '<td width="348" height="110" valign="top">';
				echo '<div id="feature-title">';
				echo $output_atwork_newsletter_title;
				echo '</div>';
				echo '</td>';

				// Output teaser
				echo '<td width="55%" valign="top">';
				echo '<div id="feature-teaser">';
				echo '<table width="100%" border="0" cellspacing="0" cellpadding="0">';
				echo '<tr>';
				echo '<td height="110" valign="top">';
				echo '<p style="font-family: Calibri, sans-serif; font-size:11pt; color:#004B8D; margin-top: 10px; margin-right: 10px; line-height: 20px;">';
				echo $atwork_newsletter_body[0]['summary'];
				echo '</p>';
				echo '</div>';
				echo '</td>';
				echo '</tr>';
				echo '<tr>';
				echo '<td>';
				echo '<p style="margin-bottom: 10px;"><a style="font-family: Calibri, sans-serif; text-decoration: none; display: block; font-size: 10pt; line-height: 20px; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased . '"> Read more >> </a></p>';
				echo '</td>';
				echo '</tr>';
				echo '<tr>';
				echo '<td align="right">';
				echo '<div class="content-type">';
				echo '<p style="font-family: Calibri, sans-serif; font-size:10pt; margin-right:10px; margin-bottom: 10px; padding-top: 10px; padding-right: 10px; border-top: solid 1px #000;"> <a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . '/news' .$currentDate . '"> News </a> </p>';
				echo '</div>';
				echo '</td>';
				echo '</tr>';
			}
	?>
      </table>
      </div></td>
  </tr>
  <tr style="background-color:#ECECEC;">
    <td height="10" colspan="2" valign="top">&nbsp;</td>
  </tr>
</table>
</td>
</tr>
</table>
<?php //********************* Middle-Block Section **********************  ?>
<?php
  	// Collect info for middle row left if available
  	if(isset($nids[1])) {
  		//$second_node=$nodes[$nids[1]];
  		//echo render($second_node);

  		// Load render node for second news spot.
  		$node_second = node_load($nids[1]);

  		// Collect title and url alias for node.
  		$atwork_newsletter_title_left = $node_second -> title;
  		$atwork_newsletter_location = $node_second -> nid;
  		$atwork_newsletter_aliased_left = drupal_get_path_alias('node/' . $atwork_newsletter_location) . $currentDate;

  		$output_atwork_newsletter_title_left = '<h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; line-height: 24px; color:#004B8D; margin-top: 10px; margin-left: 10px; margin-right: 10px;"><a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased_left . '" >' . $atwork_newsletter_title_left . '</a></h2>';

		// Collect image from node
		$image = field_get_items('node', $node_second, 'field_image');
		$image_output_left = field_view_value('node', $node_second, 'field_image', $image[2], array(
				'type' => 'image',
				'settings' => array(
			'image_style' => 'atwork_newsletter_other_image',
			'image_link' => 'content',
				),
		));

		// Attach tag to image
		$image_output_left['#path']['path'] = $atwork_base_url . '/' . $atwork_newsletter_aliased_left;

		$atwork_newsletter_body_left = field_get_items('node',$node_second, 'body');
  	}

  ?>
<?php
  // Collect info for middle row right if available
  	if(isset($nids[2])) {

		$node_third = node_load($nids[2]);

		// Collect title and url alias for node.
  		$atwork_newsletter_title_right = $node_third -> title;
  		$atwork_newsletter_location = $node_third -> nid;
  		$atwork_newsletter_aliased_right = drupal_get_path_alias('node/' . $atwork_newsletter_location) . $currentDate;

  		$output_atwork_newsletter_title_right = '<h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; line-height: 24px; color:#004B8D; margin-top: 10px; margin-left: 10px; margin-right: 10px;"><a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased_right . '" >' . $atwork_newsletter_title_right . '</a></h2>';

  		// collect image
		$image = field_get_items('node', $node_third, 'field_image');
		$image_output_right = field_view_value('node', $node_third, 'field_image', $image[2], array(
				'type' => 'image',
				'settings' => array(
			'image_style' => 'atwork_newsletter_other_image',
			'image_link' => 'content',
				),
		));

		// add webtrends tag to image
		$image_output_right['#path']['path'] = $atwork_base_url . '/' . $atwork_newsletter_aliased_right;

		// Grab teaser of news story for output
		$atwork_newsletter_body_right = field_get_items('node',$node_third, 'body');
  	}

	?>
<?php
  	// Output for middle row if we collected both stories
  	if($node_third && $node_second) {

		// beginning of middle-block.
		echo '<table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-middle-content">';

		echo '<tr valign="top">';
		echo '<td valign="top" style="background-color:#FFF;" width="382"><div id="sn-middle-left">';
		// middle-block left table.
		echo '<table width="100%" border="0" cellspacing="0" cellpadding="0">';
		//image output
		echo '<tr valign="top">';
		echo '<td valign="top">';
		echo '<div id="middle-left-image" width="372" style="background-color: #FFF">';
		echo render($image_output_left);
		echo '</div>';
		echo '</td>';
		echo '</tr>';
		// Title
		echo '<tr valign="top">';
		echo '<td valign="top" height="150">';
		echo '<div id="middle-left-content">';
		echo '<div id="middle-left-title" style="height: 50px;">';
		echo $output_atwork_newsletter_title_left;
		echo '</div>';
		// Teaser
		echo '<div id="middle-left-tease" style="height: 75px;">';
		echo '<p style="font-family: Calibri, sans-serif; font-size:11pt; color:#004B8D; margin-left: 10px; margin-right: 10px; line-height: 20px;">';
		echo $atwork_newsletter_body_left[0]['summary'];
		echo '</p>';
		echo '</div>';
		echo '</td>';
		echo '</tr>';
		echo '<tr>';
		echo '<td>';
		echo '<p style="font-family: Calibri, sans-serif; margin-left:10px; margin-bottom: 10px; font-size: 10pt;"><a style="text-decoration: none; color:#004B8D; " href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased_left . '" > Read more >> </a></p>';
		echo '</td>';
		echo '</tr>';
		// Content Type cell.
		echo '<tr>';
		echo '<td align="right" valign="top">';
		echo '<div class="content-type">';
		echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; margin-right:10px; margin-left: 10px; margin-bottom: 10px; padding-top: 10px; padding-right: 10px; padding-bottom: 10px; align: right; border-top: solid 1px #000;">';
		echo '<a style="text-decoration: none; color:#004B8D; " href="' . $atwork_base_url . '/news' . $currentDate . '"> News </a>';
		echo '</p>';
		echo '</div>';
		echo '</td>';
		echo '</tr>';
		// End of middle-block-left.
		echo '</table>';
		echo '</div>';
		echo '</td>';
		echo '<td width="11" style="background-color:#ECECEC;">&nbsp;</td>';


		// Beginning of middle-block-right
		echo '<td valign="top" style="background-color:#FFF;" width="382">';
		echo '<div id="sn-middle-right">';
		echo '<table width="100%" border="0" cellspacing="0" cellpadding="0">';
		//image output
		echo '<tr valign="top">';
		echo '<td valign="top">';
		echo '<div id="middle-right-image" width="372" height="200" id="middleleftimage2" style="background-color: #FFF">';
		echo render($image_output_right);
		echo '</div>';
		echo '</td>';
		echo '</tr>';
		// Title
		echo '<tr>';
		echo '<td valign="top" height="150">';
		echo '<div id="middle-right-content">';
		echo '<div id="middle-right-title" style="height: 50px;">';
		echo $output_atwork_newsletter_title_right;
		echo '</div>';
		// Teaser
		echo '<div id="middle-right-tease" style="height: 85px;">';
		echo '<p style="font-family: Calibri, sans-serif; font-size:11pt; color:#004B8D; margin-left: 10px; margin-right: 10px; line-height: 20px;">';
		echo $atwork_newsletter_body_right[0]['summary'];
		echo '</p>';
		echo '</div>';
		echo '</td>';
		echo '</tr>';
		echo '<tr>';
		echo '<td>';
		echo '<p style="font-family: Calibri, sans-serif; margin-left:10px; margin-bottom: 10px; font-size: 10pt;"><a style="text-decoration: none; color:#004B8D; " href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased_right . '" > Read more >> </a></p>';
		echo '</td>';
		echo '</tr>';
		// Content Type cell.
		echo '<tr>';
		echo '<td align="right" valign="top">';
		echo '<div class="content-type">';
		echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; margin-right:10px; margin-left: 10px; margin-bottom: 10px; padding-top: 10px; padding-right: 10px; padding-bottom: 10px; align=right;  border-top: solid 1px #000;">';
		echo '<a style="text-decoration: none; color:#004B8D; " href="' . $atwork_base_url . '/news' . $currentDate . '"> News </a>';
		echo '</p>';
		echo '</div>';
		echo '</td>';
		echo '</tr>';
		// end of middle-block-right.
		echo '</table>';
		echo '</div>';
		echo '</td>';

		// End of middle-block content type
		echo '</tr>';

  	}
 	?>
<table width="775" align="center" border="0" cellpadding="0" cellspacing="0">
  <tbody>
    <tr style="background-color:#ECECEC;">
      <td>&nbsp;</td>
    </tr>
  </tbody>
</table>
<?php  //************************ Take Note Section ************************** ?>
<table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-take-note" style="background-color: #ECECEC;">
  <tr>
    <td style="background-color:#A7A7A7;"><h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; color:#FFF; margin-top: 10px; margin-left: 10px; margin-right: 10px;"> Take Note </h2>
      <ul style="font-family: Calibri,sans-serif; font-size:11pt; color:#FFF; margin-top: 10px; margin-right: 10px; margin-bottom: 20px;">
        <li style="margin-left: 5px;">Item One <a style="color:#3200C5;" href="https://gww.gov.bc.ca"> Call to action </a></li>
        <li style="margin-left: 5px;">Item two <a style="color:#3200C5;" href="https://gww.gov.bc.ca"> Call to action </a></li>
        <li style="margin-left: 5px;">Item three <a style="color:#3200C5;" href="https://gww.gov.bc.ca"> Call to action </a></li>
      </ul></td>
  </tr>
  <tr>
    <td height="10" style="background-color:#ECECEC;">&nbsp;</td>
  </tr>
</table>
<?php // ************************  Did You Know? Section **************************** ?>
<table width="775" align="center" border="0" cellspacing="0" cellpadding="0" style="background-color: #ECECEC;">
  <tr>
    <td style="background-color:#A7A7A7;"><h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; color:#FFF; margin-top: 10px; margin-left: 10px; margin-right: 10px;"> Did You Know? </h2>
      <p style="font-family: Calibri,sans-serif; font-size:11pt; color:#FFF; margin-top: 10px; margin-bottom: 20px; margin-left: 10px; margin-right: 10px;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc volutpat eros et arcu blandit, a malesuada metus luctus. <?php echo '<a style="color:#3200C5;" href="' . $atwork_base_url ?> "> Call to action </a></p></td>
  </tr>
  <tr>
    <td height="10" style="background-color:#ECECEC;">&nbsp;</td>
  </tr>
</table>
<?php  //************************  Featured Blog  and Quote Section ********************** ?>
<?php
		if(isset($nids[3])) {
			//$fourth_node=$nodes[$nids[3]];
			//echo render($fourth_node);

			$node_fourth = node_load($nids[3]);
			// Collect title and url alias for node.
	  		$atwork_newsletter_title = $node_fourth -> title;
	  		$atwork_newsletter_location = $node_fourth -> nid;
	  		$atwork_newsletter_aliased = drupal_get_path_alias('node/' . $atwork_newsletter_location) . $currentDate;
	  		$output_atwork_newsletter_title = '<a style="text-decoration: none; color:#004B8D;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased . '" >' . $atwork_newsletter_title . '</a></h2>';

	  		// Collect author information for blog post
			$author_name_blog = $node_fourth -> name;
	  		$author_uid = $node_fourth -> uid;
	  		$blog_author_information = user_load($author_uid);
	  		$blog_author_name_full = $blog_author_information ->field_display_name['und'][0]['safe_value'];

			// Collect image for the blog entry;
			/**************
			* No image in this location any longer
			*$image = field_get_items('node', $node_fourth, 'field_image');
			*$image_output = field_view_value('node', $node_fourth, 'field_image', $image[0], array(
  			*	'type' => 'image',
  			*	'settings' => array(
    		*	'image_style' => 'node_full',
    		*	'image_link' => 'content',
  			*	),
			*));
			***********************/


			// Grab teaser of news story for output
			$atwork_newsletter_body = field_get_items('node',$node_fourth, 'body');

			// Beginning of atwork newsletter blog and comment info spots
			echo '<table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-blog-comment">';
			echo '<tr valign="top">';

			// Blog top content
			echo '<td width="383" valign="top" style="background-color:#FFF;"><table width="100%" border="0" cellpadding="0" cellspacing="0" id="sn-blog">';
			echo '<tr valign="top">';

			//echo render($image_output);
			echo '<td height="165" valign="top">';
			echo '<h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; line-height: 24px; color:#004B8D; margin-top: 10px; margin-left: 10px; margin-right: 10px;">';
			//title
			echo $output_atwork_newsletter_title;
			echo '</h2>';
			//teaser
			echo '<p style="font-family: Calibri,sans-serif; font-size:11pt; color:#004B8D; display:block; height:90px; margin-top: 10px; margin-left: 10px; margin-right: 10px; margin-bottom: 0; padding-bottom: 0; line-height: 20px;">';
			echo $atwork_newsletter_body[0]['summary'];
			echo '</p>';
			echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; color:#004B8D; margin-left: 10px;">';
			echo '<a style="text-decoration: none; font-size: 10pt;" href="' . $atwork_base_url . '/' . $atwork_newsletter_aliased . '" > Read more >> </a>';
			echo '</p>';
			echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; color:#004B8D; margin-left: 10px; margin-bottom: 5px;">';
			echo 'Posted by: ';
			echo $blog_author_name_full;
			echo '</p>';
			echo '</td>';
			echo '</tr>';

			// Blog content-type
			echo '<tr valign="top">';
			echo '<td align="right" valign="top">';
			echo '<div class="content-type">';
			echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; margin-right:10px; margin-left: 10px; margin-bottom: 10px; padding-top: 10px; padding-right: 10px; padding-bottom: 10px; border-top: solid 1px #000;">';
			echo '<a style="text-decoration: none;" href="' . $atwork_base_url . '/blogs' . $currentDate . '">Blogs</a>';
			echo '</p>';
			echo '</div>';
			echo '</td>';
			echo '</tr>';
			echo '</table>';
			echo '</td>';
			echo '<td width="10" valign="top" style="background-color:#ECECEC;">&nbsp;</td>';

			// Join the conversation top content
			echo '<td width="383" valign="top" style="background-color:#FFF;">';
			echo '<table width="100%" border="0" cellpadding="0" cellspacing="0" id="sn-comment">';
			echo '<tr valign="top">';
			echo '<td height="165" valign="top">';
			echo '<h2 style="font-family: Georgia, Times New Roman, Times, serif; font-size:22px; line-height: 24px; color:#004B8D; margin-top: 10px; margin-left: 10px; margin-right: 10px;">';
			echo '<a style="color:#004B8D; text-decoration:none;" href= "' . $atwork_base_url  . '/recent-comments' . $currentDate . '" > Join the Conversation </a>';
			echo '</h2>';
			echo '<p style="font-family: Calibri,sans-serif; font-size:11pt; color:#004B8D; display:block; height:90px; margin-top: 10px; margin-left: 10px; margin-right: 10px; margin-bottom: 0; padding: 0; line-height: 20px;">"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc volutpat eros et arcu blandit, a malesuada metus luctus. Aenean euismod volutpat enim vitae dignissim."</p>';
			echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; color:#004B8D; margin-left: 10px;">';
			echo '<a style="text-decoration: none; font-size: 10pt;" href="' . $atwork_base_url . '/recent-comments' . $currentDate . '" > Read more >> </a></p>';
			echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; color:#004B8D; margin-left: 10px; margin-bottom: 5px;">';
			echo 'Posted by: ';
			echo 'Author Name';
			echo '</p>';
			echo '</td>';
			echo '</tr>';

			// Join the conversation content-type
			echo '<tr valign="top">';
			echo '<td align="right" valign="top">';
			echo '<div class="content-type">';
			echo '<p style="font-family: Calibri,sans-serif; font-size:10pt; margin-right:10px; margin-left: 10px; margin-bottom: 10px; padding-top: 10px; padding-right: 10px; padding-bottom: 10px; border-top: solid 1px #000;">';
			echo '<a style="text-decoration: none;" href="' . $atwork_base_url . '/recent-comments' . $currentDate . '">Comments </a>';
			echo '</p>';
			echo '</div>';
			echo '</td>';

			// end of atwork newsletter blog and comment info spots
			echo '</tr>';
			echo '</table>';
			echo '</td>';
			echo '</tr>';
		}
	?>
<table width="775" align="center" border="0" cellpadding="0" cellspacing="0">
  <tbody>
    <tr style="background-color:#ECECEC;">
      <td>&nbsp;</td>
    </tr>
  </tbody>
</table>
<?php // ************************ Footer Section ************************** ?>
<?php endif; // All footers are the same  ?>
<table width="775" align="center" border="0" cellpadding="0" cellspacing="0" id="sn-footer" style="background-color: #ECECEC;">
  <tr bgcolor="#004B8D">
    <td width="387" height="140" valign="middle" style="border-right: solid 1px #FFF;"><table width="100%" border="0" align="center" cellpadding="0" cellspacing="0" >
        <tr >
          <td><p style="font-family: Calibri, sans-serif; font-size:11pt; color:#FFF; margin: 10px 10px; text-align: center;"><a href="mailto:employeenews@gov.bc.ca?Subject=@Work Newsletter"  style="color:#FFF;"><img alt="Contact us at employeenews@gov.bc.ca" title="Contact us at employeenews@gov.bc.ca" <?php echo 'src="' . $atwork_base_url ?>/sites/all/themes/atwork/images/email-us.png" style="width: 61px; height: 62px;"></a></p>
          <p style="font-family: Calibri, sans-serif; font-size:11pt; color:#FFF; margin: 10px 10px; text-align: center;"><a href="mailto:employeenews@gov.bc.ca?Subject=@Work%20Website" style="color:#FFFFFF";>EmployeeNews</a></p></td>
        </tr>
      </table></td>
    <td valign="middle" height="140"><table width="100%" border="0" cellspacing="0" cellpadding="0" >
        <tr>
          <td><p style="font-family: Calibri, sans-serif; font-size:11pt; color:#FFF; margin-top: 10px; margin-right: 25px; margin-bottom: 10px; margin-left: 25px;">You’re one of 26,000+ employees receiving the <?php echo '<a color="#FFF" href="' . $atwork_base_url . '/newsletters' . $currentDate . '"'; ?> style="color:#FFF;">@Work&nbspnewsletter</a> – a selection of noteworthy news from your corporate intranet. Visit <?php echo '<a color="#FFF" href="' . $atwork_base_url . '/' . $currentDate . '"'; ?> style="color:#FFF;">@Work</a> to stay informed and connect with your colleagues across the BC Public Service.</a> </p></td>
        </tr>
      </table></td>
  </tr>
</table>
</td>
</tr>
</table>
