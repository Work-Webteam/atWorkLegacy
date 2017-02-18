<?php

class AtworkRateDefaultWidget extends AtworkRateWidget
{
  protected $wid;
  protected $layout;
  protected $css_file;
  protected $js_file;

  protected $desc_norating;
  protected $desc_notvoted;
  protected $desc_voted;
  protected $desc_justvoted;
  protected $desc_mouseover;

  protected $sprites;
  protected $highlight_voted;
  protected $highlight_mouseover;

  /**
   * Load the widget from database.
   *
   * Set up the buttons, tag, value type etc.
   */
  protected function load() {
    $widget = db_select('atwork_rate_widget', 'w')
      ->fields('w', array('wid', 'type', 'name', 'mode', 'sprites',
        'highlight_voted', 'highlight_mouseover', 'desc_norating',
        'desc_notvoted', 'desc_voted', 'desc_justvoted', 'desc_mouseover',
        'css_file', 'js_file'))
      ->condition('w.type', $this->type)
      ->execute()
      ->fetchObject();
      //dpm($widget);
    if ($widget) {
      $this->wid = $widget->wid;
      $this->value_type = $widget->mode;
      $this->css_file = $widget->css_file;
      $this->js_file = $widget->js_file;

      $this->desc_norating = $widget->desc_norating;
      $this->desc_notvoted = $widget->desc_notvoted;
      $this->desc_voted = $widget->desc_voted;
      $this->desc_justvoted = $widget->desc_justvoted;
      $this->desc_mouseover = $widget->desc_mouseover;

      $this->sprites = (bool) $widget->sprites;
      $this->highlight_voted = $widget->highlight_voted;
      $this->highlight_mouseover = $widget->highlight_mouseover;
      $this->loadButtons();
    }
  }

  /**
   * Load buttons from database.
   */
  protected function loadButtons() {
    $buttons = db_select('atwork_rate_widget_button', 'b')
      ->fields('b', array('num', 'label', 'value', 'width', 'height',
        'img_default', 'img_highlighted', 'img_default_voted',
        'img_highlighted_voted', 'img_disabled', 'img_disabled_voted'))
      ->condition('b.wid', $this->wid)
      ->orderBy('b.num', 'asc')
      ->execute()
      ->fetchAll();

    // Loop the result to find files to load.
    $fids = array();
    //dpm($buttons);
    foreach ($buttons as $button) {
      if (!$this->sprites) {
        $img = $button->img_default;
        if (is_numeric($img)) {
          $fids[] = $img;
        }
      }
    }
    if ($fids) {
      $fids = array_filter(array_unique($fids));
      $files = file_load_multiple($fids);
    }

    // Second loop to generate buttons.
    foreach ($buttons as $button) {
      $this->elements["button{$button->num}"] = new AtworkRateButton(
        $button->num,
        $button->label,
        $button->value,
        $this->getToken($button->num),
        FALSE,
        ''
      );
    }
  }

  /**
   * Initialize the widget.
   *
   * Load layout from database and generate default elements like vote count and description.
   */
  protected function init() {
    $this->layout = array();

    // Get numeric display mode as used in the elements table.
    $modes = array(
      'format_full' => 1,
      'format_compact' => 2,
      'format_full_disabled' => 4,
      'format_compact_disabled' => 8,
      'format_closed' => 16,
    );
    $mode = isset($modes[$this->mode]) ? $modes[$this->mode] : 0;
    $elements = db_select('atwork_rate_widget_element', 'e')
      ->fields('e', array('type', 'prefix', 'suffix', 'mode'))
      ->condition('e.wid', $this->wid)
      ->orderBy('e.weight', 'asc')
      ->execute()
      ->fetchAll();
    foreach ($elements as $element) {
      if ($element->mode & $mode) {
        $this->layout[] = $element;
      }
    }
    foreach ($this->elements as $element) {
      if ($element instanceof AtworkRateButton) {
        $highlight = FALSE;
        if ($this->rating == $element->getValue() && $this->highlight_voted & 1) {
          $highlight = TRUE;
        }
        if ($this->rating > $element->getValue() && $this->highlight_voted & 2) {
          $highlight = TRUE;
        }
        if ($this->rating < $element->getValue() && $this->highlight_voted & 4) {
          $highlight = TRUE;
        }
        if ($highlight) {
          $element->addClass('highlighted');
        }
      }
    }

    $this->elements['description'] = $this->getDescription();
  }

  /**
   * Generate HTML code for widget.
   *
   * @return string
   */
  public function __toString() {
    $output = '';

    // Add generic javascript.
    drupal_add_js(array(
      'atwork_rate' => array(
        'basePath' => url('atwork_rate/vote/js'),
        'destination' => drupal_get_destination(),
      ),
    ), array('type' => 'setting'));
    drupal_add_js(drupal_get_path('module', 'atwork_rate') . '/atwork_rate.js');

    // Add widget specific javascript and CSS.
    if ($this->js_file) {
      drupal_add_js($this->js_file);
    }
    if ($this->css_file) {
      drupal_add_css($this->css_file);
    }

    foreach ($this->layout as $element) {
      if (isset($this->elements[$element->type])) {
        $output .= $element->prefix;
        $output .= (string) $this->elements[$element->type];
        $output .= $element->suffix;
      }
    }

    $classes = array('atwork-rate-widget', "atwork-rate-widget-{$this->type}");
    $classes[] = $this->displayed == ATWORK_RATE_AVERAGE ? 'average-rating' : 'user-rating';
    $classes[] = $this->voted ? 'voted' : 'not-voted';

    if ($this->mode == 'format_full_disabled' || $this->mode == 'format_compact_disabled' || $this->mode == 'format_closed') {
      $classes[] = 'disabled';
    }
    else {
      $classes[] = 'enabled';
    }
    if ($this->mode == 'format_closed') {
      $classes[] = 'closed';
    }
    if ($this->mode == 'format_compact' || $this->mode == 'format_compact_disabled') {
      $classes[] = 'compact';
    }
    $attributes = array(
      'class' => $classes,
      'data-entity-type' => $this->entity_type,
      'data-entity-id' => $this->entity_id,
      'data-field' => $this->field_name,
      'data-mode' => $this->mode,
      'data-highlight-mouseover' => $this->highlight_mouseover,
      'data-desc-mouseover' => $this->desc_mouseover,
    );
    $output = "<div" . drupal_attributes($attributes) . ">$output</div>";
    return $output;
  }

  /**
   * Get description for this widget.
   *
   * @return string
   */
  protected function getDescription() {
    $user_vote = NULL;
    $total_vote = $this->count;
    $total_vote_without_user = $total_vote - 1;

    //dpm($this);
    foreach ($this->results as $result) {
      if ($result['function'] == 'user') {
        $user_vote = $this->getButtonLabelByValue($result['value']);
      }
    }
    // Hacked the messages to take more instances into account.
    // TODO: In the future, this should be added to the front end rate_ui module, and standardized here.
    // No one has voted
    if ($this->count == 0) {
      $description = $this->desc_norating;
    }
    // You have not voted, someone else has
    elseif (is_null($user_vote) ) {
      if($total_vote == 1 ){
        $description = "(" . $total_vote . ")";
      } else {
        $description = "(" . $total_vote . ")";
      }
    }
    // You just voted
    elseif ($this->just_voted) {
      if($total_vote_without_user == 1 ){
        $description = "You and " .  $total_vote_without_user . " other like this";
      } elseif($total_vote_without_user == 0) {
        $description = "You like this";
      } else {
        $description = "You and " .  $total_vote_without_user . " others like this";
      }
    }

    // You are the only one who has voted
    elseif ($user_vote && $this->count == 1){
      $description = "You like this";
    }
    // You have voted and so has someone else
    else {
      if($total_vote_without_user == 1 ){
        $description = "You and " . $total_vote_without_user . "other like this";
      } else {
        $description = "You and " . $total_vote_without_user . "others like this";
      }
    }

    $description = t($description, array(
      '@rating' => $this->rating,
      '@vote' => $user_vote,
    ));

    $description = "<span class=\"atwork-rate-description\">$description</span>";

    return $description;
  }
}
