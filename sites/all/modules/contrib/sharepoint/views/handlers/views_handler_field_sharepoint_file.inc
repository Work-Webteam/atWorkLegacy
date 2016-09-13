<?php
// $Id;

/**
 * @file
 *   Views field handler for Sharepoimt fields.
 */

/**
 * Views field handler for Sharepoint fields.
 *
 * The only thing we're doing here is making sure the field_alias
 * gets set properly, otherwise the parent render function is going to
 * fail.
 */
class views_handler_field_sharepoint_file extends views_handler_field {
  function query() {
    $this->field_alias = $this->real_field;
  }
  /**
   * Render the field.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  function render($values) {
    if (isset($values->filepath)) {
      $value = $values->filepath;
      return $this->render_link($this->sanitize_value($value), $values);
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);
  }
  
  function render_link($data, $values) {
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = $data;
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    return $text;
  }
}
