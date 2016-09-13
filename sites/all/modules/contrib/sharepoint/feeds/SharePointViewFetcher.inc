<?php

/**
 * @file
 * SharePoint View Fetcher Plugin for Feeds.
 */

/**
 * Fetcher Result Class for SharePoint Views.
 */
class SharePointViewFetcherResult extends FeedsFetcherResult {
  public $list;
  public $view;
  public $endpoint;

  /**
   * Constructor.
   */
  public function __construct($endpoint, $list, $view) {
    $this->list = $list;
    $this->view = $view;
    $this->endpoint = $endpoint;
    parent::__construct('');
  }

  /**
   * Overrides FeedsFetcherResult::getRaw();
   */
  public function getRaw() {
    module_load_include('inc', 'sharepoint');
    $client = sharepoint_get_client(sharepoint_endpoint_load($this->endpoint), 'lists');
    return sharepoint_get_splist_items($client, $this->list, $this->view);
  }
}

/**
 * Fetches data via HTTP.
 */
class SharePointViewFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    return new SharePointViewFetcherResult($this->config['endpoint'], $this->config['list'], $this->config['view']);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'list' => '',
      'endpoint' => '',
      'view' => FALSE,
      'num_records' => 0,
    );
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = _sharepoint_feeds_config_form($this);
    $form['num_records'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of records'),
      '#default_value' => $this->config['num_records'],
      '#size' => 30,
      '#maxlength' => 5,
      '#description' => t('The number of records to retrieve. Enter 0 for no limit'),
    );
    return $form;
  }
}
