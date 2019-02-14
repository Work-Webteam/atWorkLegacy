<?php
$street = isset($label_address['street']) ? trim($label_address['street']) : "No street address provided.";
$city = isset($label_address['city']) ? trim($label_address['city']) : "No city provided.";
$postal = isset($label_address['postal']) ? trim($label_address['postal']) : "No postal code provided.";
$ministry = trim($ministry);

$letter_label = <<< EOT
{$supervisor_name}   
{$ministry}  
{$street}    
{$city}, B.C.
Canada
{$postal} 
EOT;
