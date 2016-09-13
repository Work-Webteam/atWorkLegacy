<?php

/**
 * @file
 * Themes the question report
 *
 * Available variables:
 * $form - FAPI array
 *
 * All questions are in form[x] where x is an integer.
 * Useful values:
 * $form[x]['question'] - the question as a FAPI array(usually a form field of type "markup")
 * $form[x]['score'] - the users score on the current question.(FAPI array usually of type "markup" or "textfield")
 * $form[x]['max_score'] - the max score for the current question.(FAPI array of type "value")
 * $form[x]['response'] - the users response, usually a FAPI array of type markup.
 * $form[x]['#is_correct'] - If the users response is correct(boolean)
 * $form[x]['#is_evaluated'] - If the users response has been evaluated(boolean)
 */
// $td_classes = array('quiz-report-odd-td', 'quiz-report-even-td');
// $td_class_i = 0;

if (arg(0) == 'node' && is_numeric(arg(1))) {
  $link = '';
  switch (arg(1)) {
    case 7647:
      $node = node_load(7660);
      $link = l($node->title, 'node/' . $node->nid);
      break;
    case 7591:
      $node = node_load(7590);
      $link = l($node->title, 'node/' . $node->nid);
      break;
    case 3608:
      $node = node_load(3631);
      $link = l($node->title, 'node/' . $node->nid);
      break;
    case 5683:
      $node = node_load(5721);
      $link = l($node->title, 'node/' . $node->nid);
      break;
    case 6415:
      $node = node_load(6427);
      $link = l($node->title, 'node/' . $node->nid);
      break;
    case 4005:
      $node = node_load(4008);
      $link = l($node->title, 'node/' . $node->nid);
      break;
    case 6960:
      $node = node_load(6961);
      $link = l($node->title, 'node/' . $node->nid);
      break;
  }
  if ($link) {
    print <<<EOT
<h2>Return to: $link</h2>
EOT;
  }
}

$p = drupal_get_path('module', 'quiz') .'/theme/';
$q_image = $p. 'question_bg.png';
?>

<h2><?php print t('Question Results');?></h2>

<dl class="quiz-report">

<?php
foreach ($form as $key => $sub_form):
  if (!is_numeric($key) || isset($sub_form['#no_report'])) continue;
  unset($form[$key]);
  $c_class = ($sub_form['#is_evaluated']) ? ($sub_form['#is_correct']) ? 'q-correct' : 'q-wrong' : 'q-waiting';
  $skipped = $sub_form['#is_skipped'] ? '<span class="quiz-report-skipped">'. t('(skipped)') .'</span>' : ''?>

	<dt>
	  <div class="quiz-report-score-container <?php print $c_class?>">
	  	<span>
	      <?php print t('Score')?>
		  <?php print drupal_render($sub_form['score'])?>
		  <?php print t('of') .' '. $sub_form['max_score']['#value']?>
		  <?php print '<br><em>'. $skipped .'</em>'?>
		</span>
      </div>

	  <p class="quiz-report-question"><strong><?php print t('Question')?>: </strong></p>
	  <?php print drupal_render($sub_form['question']);?>
	</dt>

    <dd>
	  <p><strong><?php print t('Response')?>: </strong></p>
      <?php print drupal_render($sub_form['response']); ?>
    </dd>

    <dd>
      <?php print drupal_render($sub_form['answer_feedback']); ?>
    </dd>

<?php endforeach; ?>
</dl>

<div style="float:right;"><?php print drupal_render_children($form);?></div>