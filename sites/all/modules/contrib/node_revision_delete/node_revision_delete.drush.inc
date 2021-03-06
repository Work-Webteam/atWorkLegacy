<?php

/**
 * @file
 * Drush commands related to the Node Revision Delete module.
 */

require_once dirname(__FILE__) . '/node_revision_delete.helpers.inc';

/**
 * Implements hook_drush_command().
 */
function node_revision_delete_drush_command() {
  $items['node-revision-delete'] = array(
    'description' => dt('Deletes old node revisions for a given content type.'),
    'arguments' => array(
      'type' => dt('Content type machine name.'),
      'minimum_revisions_to_keep' => dt('Minimum number of revisions to keep.'),
      'minimum_age_to_delete' => dt('Minimum age of revisions to be deleted.'),
      'when_to_delete' => dt('Minimum inactivity age to wait for delete a revision.'),
      'dry_run' => dt('Test run without deleting revisions but seeing the output results.'),
    ),
    'examples' => array(
      // @TODO: Add more examples.
      'drush nrd article 50' => dt('Keeps the latest 50 revisions of every article. Deletes the rest.'),
    ),
    'aliases' => array('nrd'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  $items['nrd-delete-cron-run'] = array(
    'description' => dt('Configures how many revisions delete per cron run.'),
    'arguments' => array(
      'quantity' => dt('Revisions quantity to delete per cron run.'),
    ),
    'aliases' => array('nrd-dcr'),
    'examples' => array(
      'nrd-delete-cron-run' => dt('Show how many revisions the module will delete per cron run.'),
      'nrd-delete-cron-run 50' => dt('Configure the module to delete 50 revisions per cron run.'),
    ),
  );
  $items['nrd-last-execute'] = array(
    'description' => dt('Get the last time that the node revision delete was made.'),
    'aliases' => array('nrd-le'),
    'examples' => array(
      'nrd-last-execute' => dt('Show the last time that the node revision delete was made.'),
    ),
  );

  // Getting all possible values.
  $values = array_keys(_node_revision_delete_word_to_time());
  $last_value = 'or ' . array_pop($values);
  $values[] = $last_value;

  $items['nrd-set-time'] = array(
    'description' => dt('Configures the frequency with which to delete revisions while cron is running.'),
    'aliases' => array('nrd-st'),
    'arguments' => array(
      'time' => dt('The time value (@values)', array('@values' => implode(', ', $values))),
    ),
    'examples' => array(
      'nrd-set-time' => dt('Show a list to select the frequency with which to delete revisions while cron is running.'),
      'nrd-set-time every_time' => dt('Configure the module to delete revisions every time the cron runs.'),
    ),
  );
  $items['nrd-get-time'] = array(
    'description' => dt('Shows the frequency with which to delete revisions while cron is running.'),
    'aliases' => array('nrd-gt'),
    'examples' => array(
      'nrd-get-time' => dt('Shows the actual frequency with which to delete revisions while cron is running.'),
    ),
  );
  $items['nrd-when-to-delete-time'] = array(
    'description' => dt('Configures the time options for the inactivity time that the revision must have to be deleted.'),
    'arguments' => array(
      'max_number' => dt('The maximum number for inactivity time configuration'),
      'time' => dt('The time value for inactivity time configuration (days, weeks or months)'),
    ),
    'aliases' => array('nrd-wtdt'),
    'examples' => array(
      'nrd-when-to-delete-time ' => dt('Shows the time configuration for the inactivity time.'),
      'nrd-when-to-delete-time 30 days' => dt('Set the maximum inactivity time to 30 days.'),
      'nrd-when-to-delete-time 6 weeks' => dt('Set the maximum inactivity time to 6 weeks.'),
    ),
  );
  $items['nrd-minimum-age-to-delete-time'] = array(
    'description' => dt('Configures time options to know the minimum age that the revision must have to be delete.'),
    'arguments' => array(
      'max_number' => dt('The maximum number for minimum age configuration'),
      'time' => dt('The time value for minimum age configuration (days, weeks or months)'),
    ),
    'aliases' => array('nrd-matdt'),
    'examples' => array(
      'nrd-minimum-age-to-delete-time ' => dt('Shows the time configuration for the minimum age of revisions.'),
      'nrd-minimum-age-to-delete-time 30 days' => dt('Set the maximum time for the minimum age to 30 days.'),
      'nrd-minimum-age-to-delete-time 6 weeks' => dt('Set the maximum time for the minimum age to 6 weeks.'),
    ),
  );
  $items['nrd-delete-prior-revisions'] = array(
    'description' => dt('Delete all revisions prior to a revision.'),
    'arguments' => array(
      'nid' => dt('The id of the node which revisions will be deleted.'),
      'vid' => dt('The revision id, all prior revisions to this revision will be deleted.'),
    ),
    'aliases' => array('nrd-dpr'),
    'examples' => array(
      'nrd-delete-prior-revisions 1 3' => dt('Delete all revisions prior to revision id 3 of node id 1.'),
    ),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function node_revision_delete_drush_help($section) {
  switch ($section) {
    case 'meta:node_revision_delete:title':
      return dt('Node Revision Delete commands');

    case 'meta:node_revision_delete:summary':
      return dt("Interacts with the Node Revision Delete module's functionalities.");

    case 'drush:node-revision-delete':
      return dt('Deletes old node revisions for a given content type.');

    case 'drush:nrd-delete-cron-run':
      return dt('Configures how many revisions delete per cron run.');

    case 'drush:nrd-last-execute':
      return dt('Get the last time that the node revision delete was made.');

    case 'drush:nrd-set-time':
      return dt('Configures the frequency with which to delete revisions while cron is running.');

    case 'drush:nrd-when-to-delete-time':
      return dt('Configures the time options for the inactivity time that the revision must have to be deleted.');

    case 'drush:nrd-minimum-age-to-delete-time':
      return dt('Configures time options to know the minimum age that the revision must have to be deleted.');

    case 'drush:nrd-delete-prior-revisions':
      return dt('Define which prior revisions to which revision of which node to delete.');
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_node_revision_delete_validate() {
  $args = func_get_args();
  // Make sure the content type exists.
  $content_types = node_type_get_names();
  $content_types_machine_name = array_keys($content_types);
  if (!in_array($args[0], $content_types_machine_name)) {
    return drush_set_error('NODE_REVISION_DELETE_WRONG_TYPE', dt('The content type "@type" does not exist. Available content types are @types', array(
      '@type' => $args[0],
      '@types' => implode(', ', $content_types_machine_name),
    )));
  }

  // Make sure the minimum number of revisions is a positive integer.
  if (!_node_revision_delete_is_integer_positive($args[1])) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('The minimum number of revisions to keep must be a positive integer.'));
  }

  // Make sure the minimum age of revisions to be deleted is a integer number.
  if (!ctype_digit($args[2])) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('You must enter digits for the minimum age of revisions to be deleted.'));
  }

  // Make sure the minimum inactivity age to wait for delete a revision is a
  // integer number.
  if (!ctype_digit($args[3])) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('You must enter digits for the minimum inactivity age to wait for delete a revision.'));
  }

  // Validating the dry-run param.
  if (!empty($args[4]) && !ctype_digit($args[4]) && !in_array($args[4], array(0, 1), TRUE)) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('The dry run parameter must be a boolean (0 or 1).'));
  }
}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 */
function drush_node_revision_delete() {
  $args = func_get_args();

  // Checking if we have candidate revisions to delete.
  $content_types = node_type_get_names();
  $candidates = count(_node_revision_delete_candidates($args[0], $args[1], $args[2], $args[3]));
  if (!$candidates) {
    $content_type = $content_types[$args[0]] . ' [' . $args[0] . ']';
    drush_log(dt('There are no revisions to delete for content type @content_type.', array('@content_type' => $content_type)), 'warning');
    return;
  }

  $dry_run = isset($args[4]) ? (bool) $args[4] : FALSE;
  // Set up the batch job.
  $batch = array(
    'operations' => array(
      array('node_revision_delete_batch_process',
        array(
          $args[0],
          $args[1],
          $args[2],
          $args[3],
          $dry_run,
        ),
      ),
    ),
    'title' => dt('Node Revision Delete batch job'),
    'init_message' => dt('Starting...'),
    'error_message' => dt('An error occurred'),
    'finished' => 'node_revision_delete_batch_finish',
    'file' => drupal_get_path('module', 'node_revision_delete') . '/node_revision_delete.batch.inc',
  );
  // Checking if this is a dry run.
  if ($dry_run) {
    drush_log(dt('This is a dry run. No revision will be deleted.'), 'warning');
  }
  // Start the batch job.
  batch_set($batch);
  drush_backend_batch_process();
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_node_revision_delete_nrd_delete_cron_run_validate() {
  $args = func_get_args();
  // If we don't have arguments we will return the config values.
  if (!count($args)) {
    return;
  }
  // Check for only one argument.
  if (count($args) > 1) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('This command use only one argument as quantity.'));
  }
  // Check for integer quantity.
  if (!ctype_digit($args[0])) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('You must specify digits for the quantity'));
  }
}

/**
 * Callback for the nrd-delete-cron-run command.
 */
function drush_node_revision_delete_nrd_delete_cron_run() {
  $args = func_get_args();
  // Getting or setting values?
  if (isset($args[0])) {
    // Saving the values in the config.
    variable_set('node_revision_delete_cron', $args[0]);

    $message = dt('The module was configurated to delete @revisions revisions per cron run.', array('@revisions' => $args[0]));
    drush_log($message, 'success');
  }
  else {
    // Getting the values from the config.
    $revisions = variable_get('node_revision_delete_cron');
    $message = dt('The revisions quantity to delete per cron run is: @revisions.', array('@revisions' => $revisions));
    drush_print($message);
  }
}

/**
 * Callback for the nrd-last_execute command.
 */
function drush_node_revision_delete_nrd_last_execute() {
  // Getting the value from the config.
  $last_execute = variable_get('node_revision_delete_last_execute');
  if (!empty($last_execute)) {
    $last_execute = format_date($last_execute);
    $message = dt('The last time when node revision delete was made was: @last_execute.', ['@last_execute' => $last_execute]);
  }
  else {
    $message = dt('The removal of revisions through the module node revision delete has never been executed on this site.');
  }
  drush_print($message);
}

/**
 * Callback for the nrd-set-time command.
 */
function drush_node_revision_delete_nrd_set_time($time = '') {
  // Check for correct argument.
  $options = _node_revision_delete_word_to_time();
  if (!in_array($time, array_keys($options))) {
    if (!empty($time)) {
      drush_log(dt('"@time_value" is not a valid time argument.', array('@time_value' => $time)), 'warning');
    }
    $time = drush_choice(_node_revision_delete_time_value(), dt('Choose the frequency with which to delete revisions while cron is running:'));
  }
  else {
    $time = $options[$time];
  }
  // Saving the values in the config.
  variable_set('node_revision_delete_time', $time);

  $time_value = _node_revision_delete_time_value($time);
  $message = dt('The frequency with which to delete revisions while cron is running was set to: @time.', array('@time' => $time_value));

  drush_log($message, 'success');
}

/**
 * Callback for the nrd-get-time command.
 */
function drush_node_revision_delete_nrd_get_time() {
  // Getting the values from the config.
  $time = variable_get('node_revision_delete_time');
  $time = _node_revision_delete_time_value($time);
  $message = dt('The frequency with which to delete revisions while cron is running is: @time.', array('@time' => $time));
  drush_print($message);
}

/**
 * Helper function to validate the maximum time.
 *
 * @param array $args
 *   An array with number and time.
 *
 * @return bool
 *   A boolean indicating the success of the validation.
 */
function _drush_node_revision_delete_validate_maximum_time(array $args) {
  // If we don't have arguments we will return the config values.
  if (!count($args)) {
    return TRUE;
  }
  // Check for only 2 arguments.
  if (count($args) != 2) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('This command use two arguments.'));
  }
  // Check for integer number.
  if (!ctype_digit($args[0])) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('You must enter digits for the maximum number.'));
  }
  // Check for valid integer number.
  if ($args[0] < 1) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('You must enter a digit no more less than 1 for the maximum number.'));
  }
  // Check for time.
  if (!in_array($args[1], array('days', 'weeks', 'months'))) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('The accepted time arguments are: days, weeks or months.'));
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_node_revision_delete_nrd_when_to_delete_time_validate() {
  $args = func_get_args();
  _drush_node_revision_delete_validate_maximum_time($args);
}

/**
 * Callback for the nrd-when-to-delete-time command.
 */
function drush_node_revision_delete_nrd_when_to_delete_time() {
  $args = func_get_args();
  // Getting or setting values?
  if (isset($args[0])) {
    // Saving the values in the config.
    $node_revision_delete_when_to_delete_time['max_number'] = $args[0];
    $node_revision_delete_when_to_delete_time['time'] = $args[1];
    variable_set('node_revision_delete_when_to_delete_time', $node_revision_delete_when_to_delete_time);

    // We need to update the max_number in the existing content type
    // configuration if the new value is lower than the actual.
    _node_revision_delete_update_time_max_number_config('when_to_delete', $args[0]);

    // Is singular or plural?
    $time = _node_revision_delete_time_number_string($args[0], $args[1]);
    $message = dt('The maximum inactivity time was set to @max_number @time.', array('@max_number' => $args[0], '@time' => $time));
    drush_log($message, 'success');
  }
  else {
    // Getting the values from the config.
    $node_revision_delete_when_to_delete_time = variable_get('node_revision_delete_when_to_delete_time');
    $max_number = $node_revision_delete_when_to_delete_time['max_number'];
    $time = $node_revision_delete_when_to_delete_time['time'];

    // Is singular or plural?
    $time = _node_revision_delete_time_number_string($max_number, $time);
    $message = dt('The maximum time for "When to delete" configuration is: @max_number @time.', array('@max_number' => $max_number, '@time' => $time));
    drush_print($message);
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_node_revision_delete_nrd_minimum_age_to_delete_time_validate() {
  $args = func_get_args();
  _drush_node_revision_delete_validate_maximum_time($args);
}

/**
 * Callback for the nrd-minimum-age-to-delete-time command.
 */
function drush_node_revision_delete_nrd_minimum_age_to_delete_time() {
  $args = func_get_args();
  // Getting or setting values?
  if (isset($args[0])) {
    // Saving the values in the config.
    $node_revision_delete_minimum_age_to_delete_time['max_number'] = $args[0];
    $node_revision_delete_minimum_age_to_delete_time['time'] = $args[1];
    variable_set('node_revision_delete_minimum_age_to_delete_time', $node_revision_delete_minimum_age_to_delete_time);

    // We need to update the max_number in the existing content type
    // configuration if the new value is lower than the actual.
    _node_revision_delete_update_time_max_number_config('minimum_age_to_delete', $args[0]);

    // Is singular or plural?
    $time = _node_revision_delete_time_number_string($args[0], $args[1]);
    $message = dt('The maximum time for the minimum age was set to @max_number @time.', array('@max_number' => $args[0], '@time' => $time));
    drush_log($message, 'success');
  }
  else {
    // Getting the values from the config.
    $node_revision_delete_minimum_age_to_delete_time = variable_get('node_revision_delete_minimum_age_to_delete_time');
    $max_number = $node_revision_delete_minimum_age_to_delete_time['max_number'];
    $time = $node_revision_delete_minimum_age_to_delete_time['time'];

    // Is singular or plural?
    $time = _node_revision_delete_time_number_string($max_number, $time);
    $message = dt('The maximum time for the minimum age is: @max_number @time.', array('@max_number' => $max_number, '@time' => $time));
    drush_print($message);
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_node_revision_delete_nrd_delete_prior_revisions_validate() {
  $args = func_get_args();
  // Check for only 2 arguments.
  if (count($args) != 2) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('This command use two arguments.'));
  }
  // Check if the first argument is a valid node id.
  $node = node_load($args[0]);
  if (!$node) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('The first argument @nid is not a valid node id.', array('@nid' => $args[0])));
  }
  // Check if the second argument is a valid revision id.
  $revisions = node_revision_list($node);
  if (!isset($revisions[$args[1]])) {
    return drush_set_error('NODE_REVISION_DELETE_INVALID_ARGUMENT', dt('The second argument @vid is not a valid revision id or doesn\'t belong to the node id @nid.', array('@vid' => $args[1], '@nid' => $args[0])));
  }
  // Check if exists prior revisions.
  if (!count(_node_revision_delete_get_previous_revisions($args[0], $args[1]))) {
    drush_log(dt('There is no revision prior to revision @vid.', array('@vid' => $args[1])), 'warning');
    return FALSE;
  }
}

/**
 * Callback for nrd-delete-prior-revisions command.
 */
function drush_node_revision_delete_nrd_delete_prior_revisions() {
  $args = func_get_args();

  if (drush_confirm(dt("Additionally, do you want to delete the revision @vid?", array('@vid' => $args[1])))) {
    node_revision_delete($args[1]);
    drush_print(dt('The revision @vid was sucessfully deleted.', array('@vid' => $args[1])));
  }

  // Get a list of revisions to delete.
  $revisions_before = array_keys(_node_revision_delete_get_previous_revisions($args[0], $args[1]));

  // Loop through the list of revisions, then delete them one by one.
  foreach ($revisions_before as $revision) {
    node_revision_delete($revision);
  }

  // Print out success message.
  $singular = 'One revision of node @nid was successfully deleted.';
  $plural = 'Successfully deleted @count revisions of node @nid.';
  $message = _node_revision_delete_drush_plural(count($revisions_before), $singular, $plural, array('@count' => count($revisions_before), '@nid' => $args[0]));
  drush_print($message);
}

/**
 * Formats a plural string containing a count of items.
 *
 * This function ensures that the string is pluralized correctly. Since dt() is
 * called by this function, make sure not to pass already-localized strings to
 * it.
 *
 * For example:
 * @code
 *   $output = _node_revision_delete_drush_plural($node->comment_count, '1 comment', '@count comments');
 * @endcode
 *
 * @param int $count
 *   The item count to display.
 * @param string $singular
 *   The string for the singular case. Make sure it is clear this is singular,
 *   to ease translation (e.g. use "1 new comment" instead of "1 new"). Do not
 *   use @count in the singular string.
 * @param string $plural
 *   The string for the plural case. Make sure it is clear this is plural, to
 *   ease translation. Use @count in place of the item count, as in
 *   "@count new comments".
 * @param array $args
 *   An associative array of replacements to make after translation. Instances
 *   of any key in this array are replaced with the corresponding value.
 *   Based on the first character of the key, the value is escaped and/or
 *   themed. See format_string(). Note that you do not need to include @count
 *   in this array; this replacement is done automatically for the plural case.
 * @param array $options
 *   An associative array of additional options. See dt() for allowed keys.
 *
 * @return string
 *   A translated string.
 *
 * @see dt()
 */
function _node_revision_delete_drush_plural($count, $singular, $plural, array $args = array(), array $options = array()) {
  $args['@count'] = $count;
  if ($count == 1) {
    return dt($singular, $args, $options);
  }

  // Get the plural index through the gettext formula.
  $index = (function_exists('locale_get_plural')) ? locale_get_plural($count, isset($options['langcode']) ? $options['langcode'] : NULL) : -1;
  // If the index cannot be computed, use the plural as a fallback (which
  // allows for most flexiblity with the replaceable @count value).
  if ($index < 0) {
    return dt($plural, $args, $options);
  }
  else {
    switch ($index) {
      case "0":
        return dt($singular, $args, $options);

      case "1":
        return dt($plural, $args, $options);

      default:
        unset($args['@count']);
        $args['@count[' . $index . ']'] = $count;
        return dt(strtr($plural, array('@count' => '@count[' . $index . ']')), $args, $options);
    }
  }
}
