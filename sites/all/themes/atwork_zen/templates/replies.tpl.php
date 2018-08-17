<?php

/**
 * @file
 * Default theme implementation for replies.
 */
?>
<div class="replies-wrapper">
  <?php if (!empty($header)) : ?><div class="replies-header"><h3><?php print $header ?></h3></div><?php endif; ?>
  <?php

/**
 * Function to help parse the replies variable to change order.
 */

  if($replies){
    if(sizeof($replies) > 1){
      $reply_copy = $replies;
      // New array
      $sorted_array = array();
      $last_key = "";
      foreach($reply_copy as $key => $value) {
      //while(list($key, $value) = each($reply_copy)){
        if($value['#entity']->depth == 0){
          // Put this on the end
          array_push($sorted_array, $value['#entity']->id);
          $last_key = $key;
          continue;
        }
        $prev = $replies[$last_key];

        if(isset($value['#entity']->parent) && in_array($value['#entity']->parent, $sorted_array)){
          if($prev['#entity']->parent == $value['#entity']->parent){
            //Both have the same parent, need to know which goes first
            if($prev['#entity']->position < $value['#entity']->position){
              // this should be before prev one, so let's put it first
              // Get current position of item
              $position = array_search($prev['#entity']->id, $sorted_array);
              // Should be in our array already, but lets check
              if($position!==FALSE){
                // Now put it in the new position
                $begin_array = array_slice($sorted_array, 0, $position);
                // Push the new item on
                array_push($begin_array, $value['#entity']->id);
                // and add everything back on
                $end_array = array_slice($sorted_array, $position);
                // Now merge them back together
                $merged_array = array_merge($begin_array, $end_array);
                // And make this our new sorted array
                $sorted_array = $merged_array;
             // THis should come in order
              }
            } elseif($prev['#entity']->position > $value['#entity']->position) {
                // This should go directly after the previous entry
              $position = array_search($prev['#entity']->id, $sorted_array);
              // Should be in our array already, but lets check
              if($position!==FALSE){
                // Now put it in the new position
                $begin_array = array_slice($sorted_array, 0, $position+1);
                // and add entity_property_verify_data_type(data, type)hing back on
                $end_array = array_slice($sorted_array, $position+1);
                // Put item at beginning of the end array
                array_unshift($end_array, $value['#entity']->id);

                // Now merge them back together
                $merged_array = array_merge($begin_array, $end_array);
                // And make this our new sorted array
                $sorted_array = $merged_array;
              }
            }
          // THis has a parent, and should be slotted under them - no matching entities at this level yet
          } else {
            $position = array_search($value['#entity']->parent, $sorted_array);
            if($position !== FALSE){
                // Now put it in the new position, want to go after the parent, so we add one
                $begin_array = array_slice($sorted_array, 0, $position+1);
                // Push the new item on
                array_push($begin_array, $value['#entity']->id);
                // and add everything back on
                $end_array = array_slice($sorted_array, $position+1);
                // Now merge them back together
                $merged_array = array_merge($begin_array, $end_array);
                // And make this our new sorted array
                $sorted_array = $merged_array;
            }
          }
          // All else fails put it on the end so we don't lose it.
        }else {
          // Else this is new, so put it on the end
          array_push($sorted_array, $value['#entity']->id);

        }
        $last_key = $key;

      }
      // Check if we have a sorted array, and that it is the same size as the replies array
      if(!empty($sorted_array) && (count($sorted_array) == count($replies))){
        $updated_array = array();
        foreach($sorted_array as $reply_key){
          // Organize our new array
          $updated_array[$reply_key] = $reply_copy[$reply_key];
        }
        // Make sure we didn't miss anything.
        if(count($updated_array) == count($replies)){
          // Lets clear and refill the array
          unset($replies);
          $replies = $updated_array;
        }
      }
    }
  }
  ?>
  <?php if ($replies = render($replies)): ?><div class="replies"><?php print $replies; ?></div><?php endif; ?>
  <?php if ($links): ?><div class="replies-links"><?php print render($links) ?></div><?php endif; ?>
  <?php if ($reply_form): ?><div class="replies-form"><?php print render($reply_form) ?></div><?php endif; ?>
</div>
