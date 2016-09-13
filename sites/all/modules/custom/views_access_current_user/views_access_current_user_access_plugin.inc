<?php

/** * Access plugin that provides property based access control. */ 
class views_access_current_user_access_plugin extends views_plugin_access {   
  function summary_title() { 
    return t('Current User'); 
  } // summary_title()   
  /* Determine if the current user has access or not. */ 
  function access($account) { 
    return views_access_current_user_access($account); 
  }   
  function get_access_callback() { 
    return array('views_access_current_user_access', array()); 
  }   
}