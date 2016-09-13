<?php
/**
 * Implementation of hook_views_query_alter
 * @param type $view
 * @param type $query
 */

function atwork_qa_views_query_alter(&$view, &$query){
  if($view->name == 'question_and_answers'){

  }
}

