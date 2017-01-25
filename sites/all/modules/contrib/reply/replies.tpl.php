<?php

/**
 * @file
 * Default theme implementation for replies.
 */
?>
<div class="replies-wrapper">
  <?php if (!empty($header)) : ?><div class="replies-header"><h3><?php print $header ?></h3></div><?php endif; ?>
  <?php if($replies){
    if(sizeof($replies) > 1){
      $reply_copy = $replies;
      // New array
      $sorted_array = array();
      $last_key = "";
      while(list($key, $value) = each($reply_copy)){
        if($value['#entity']->depth == 0){
          // Put this on the end
          array_push($sorted_array, $value['#entity']->id);
          $last_key = $key;
          continue;
        }
        $prev = $replies[$last_key];

        if($prev['#entity']->parent == $value['#entity']->parent){
          //Both have the same parent, need to know which goes first
          if($prev['#entity']->position < $value['#entity']->position){
            // this should be before prev one, so let's put it first
            // Get current position of item
            $position = in_array($prev['#entity']->id, $sorted_array);
            // Should be in our array already, but lets check
            if(isset($position) && $position!==FALSE){
              // Now put it in the new position
              $begin_array = array_slice($sorted_array, 0, $position);
              //dpm($sorted_array);
              // Push the new item on
              array_push($begin_array, $value['#entity']->id);
              // and add everything back on
              $end_array = array_slice($sorted_array, $position);
              // Now merge them back together
              $merged_array = array_merge($begin_array, $end_array);
              // And make this our new sorted array
              $sorted_array = $merged_array;
           } else {
            // Add it now
            array_push($sorted_array, $value['#entity']->id);
           }

          }
         $last_key = $key;
        } else {
          // Else this is new, so put it on the end
          array_push($sorted_array, $value['#entity']->id);
          $last_key = $key;

        }
      }
      // TODO - Create an array in the key order of sorted_array, then save as replies
      //dpm($sorted_array);
      //dpm($replies);
      }
    }  ?>
  <?php if ($replies = render($replies)): ?><div class="replies"><?php print $replies; ?></div><?php endif; ?>
  <?php if ($links): ?><div class="replies-links"><?php print render($links) ?></div><?php endif; ?>
  <?php if ($reply_form): ?><div class="replies-form"><?php print render($reply_form) ?></div><?php endif; ?>
</div>
