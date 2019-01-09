<?php
$street = isset($label_address['street']) ? $label_address['street'] : "No street address provided.";
$city = isset($label_address['city']) ? $label_address['city'] : "No city provided.";
$postal = isset($label_address['postal']) ? $label_address['postal'] : "No postal code provided.";

$letter_label = <<< EOT
  {$supervisor_name} 
  {$ministry}
  {$street} 
  {$city} 
  {$postal}
EOT;

