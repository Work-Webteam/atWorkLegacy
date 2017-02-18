<?php

/**
 * @file
 * Defines module hooks.
 */

/**
 * Define templates for rate widgets.
 *
 * @return array
 */
function hook_atwork_rate_widgets() {
  $templates = array();

  $templates['thumbs_up_down'] = new stdClass();
  $templates['thumbs_up_down']->title = t('Thumbs up / down');
  $templates['thumbs_up_down']->class = 'AtworkRateWidget';
  $templates['thumbs_up_down']->file = 'atwork_rate.widget.inc';

  $templates['fivestar'] = new stdClass();
  $templates['fivestar']->title = t('Fivestar');
  $templates['fivestar']->class = 'AtworkRateWidget';
  $templates['fivestar']->file = 'atwork_rate.widget.inc';

  return $templates;
}
