<?php

/**
 * @file
 * Template file for generic images inserted via the Insert module.
 *
 * Available variables:
 * - $item: The complete item being inserted.
 * - $url: The URL to the image.
 * - $class: A set of classes assigned to this image (if any).
 * - $width: The width of the image.
 * - $height: The height of the image.
 *
 * Note that ALT and Title fields should not be filled in here, instead they
 * should use placeholders that will be updated through JavaScript when the
 * image is inserted.
 *
 * Available placeholders:
 * - __alt__: The ALT text, intended for use in the <img> tag.
 * - __title__: The Title text, intended for use in the <img> tag.
 * - __description__: A description of the image, sometimes used as a caption.
 * - __filename__: The file name.
 * - __[token]_or_filename__: Any of the above tokens if available, otherwise
 *   use the file's name. i.e. __title_or_filename__.
 */

$wiki = FALSE;
if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == 'edit') {
  if ($node = node_load(arg(1))) {
    if ($node->type == 'wiki') {
      $wiki = TRUE;
    }
  }
}
if (arg(0) == 'file' && arg(1) == 'ajax' && arg(2) == 'field_image') {
  $referer = str_replace($GLOBALS['base_url'] . '/', '', $_SERVER['HTTP_REFERER']);
  if (arg(0, $referer) == 'node' && arg(1, $referer) == 'add' && arg(2, $referer) == 'wiki') {
    $wiki = TRUE;
  }
  if (arg(0, $referer) == 'node' && is_numeric(arg(1, $referer)) && arg(2, $referer) == 'edit') {
    if ($node = node_load(arg(1, $referer))) {
      if ($node->type == 'wiki') {
        $wiki = TRUE;
      }
    }
  }
}
//dpm(arg(0) . '/' . arg(1) . '/' . arg(2));
?>
<?php if ($wiki): ?>
[[File:__filename__|left|200px|]]
<?php else: ?>
<img src="<?php print $url ?>" width="<?php print $width ?>" height="<?php print $height ?>" alt="__alt__" title="__title__" <?php print $class ? 'class="' . $class . '" ' : '' ?>/>
<?php endif; ?>
