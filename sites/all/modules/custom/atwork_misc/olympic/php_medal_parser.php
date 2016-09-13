<?php
// Need a package to grab site
include_once('simple_html_dom.php');
// Grab Canada medal count page
$html = file_get_html('https://www.rio2016.com/en/canada') or trigger_error("Could not connect to olympic site", E_USER_ERROR);

if(isset($html)){
  // Find the right table
  foreach($html->find('table') as $element){
    if($element->class == "page-info__medals-information"){
      //import all parts of table in plain text
      $medal_table = $element->plaintext;
    }
  }

  // Make string an array
  $medal_table_array = array_map('parse_value', explode(' ', $medal_table));


  // Remove all empty elements(there were a lot of spaces)
  foreach($medal_table_array as $key=>&$value){
    if($value == ""){
      unset($medal_table_array[$key]);
    }
  }

  // Reindex to expected array keys
  $medal_table_array = array_values($medal_table_array);
  //print_r($medal_table_array);
  $output = array(
    'gold' => $medal_table_array[0],
    'silver' => $medal_table_array[1],
    'bronze' => $medal_table_array[2],
    );

  // Save as a .csv we can use in our medal table
  $fh = fopen('/var/www/html/sites/all/modules/custom/atwork_misc/olympic/olympic.csv', "w");
  //;fputcsv($fh, array('gold', 'silver', 'bronze'));
  fputcsv($fh, $output);
fclose($fh);
} else {
  echo("No data downloaded, exiting script");
}
// Callback function that simply returns items to a new array
function parse_value($value){
  return($value);
}
?>
