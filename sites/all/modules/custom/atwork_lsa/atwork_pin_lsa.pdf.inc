<?php
//https://daringfireball.net/projects/markdown/syntax
// Creating a markdown string that we can convert to pdf after
// We will need to do this on our local with Pandoc
// Lets put the image in as a base64 - that is available here: https://medium.com/markdown-monster-blog/getting-images-into-markdown-documents-and-weblog-posts-with-markdown-monster-9ec6f353d8ec
//  Base64 gets added at the end - so pay attention to where you add this in the process of the function calls (i.e. it needs to go very last) however, it will be referenced in every iteration.
$letter_text = <<< EOT

<!-- This should double as a page break as .md takes html -->
<div style="page-break-after: always;"></div>
EOT;
