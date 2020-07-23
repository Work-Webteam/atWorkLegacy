date:     2016-09-05
module:   devel
file:     fatal-dd-2559061-12.patch
source:   https://www.drupal.org/node/2559061
issue:    the function dd() prevents the proper use of drush when combined with the presences of Composer and the module, devel.


date:   2017-06-01
module: Views
file:   views_plugin_display_attachment.inc
source: https://www.drupal.org/node/2481401
issue:  Notice: Undefined property: view::$exposed_input in views_plugin_display_attachment->attach_to()


date:   2017-06-05
module: Views
files:  views/modules/user/views_handler_field_user.inc
        views/modules/user/views_handler_field_user_language.inc
        views/modules/user/views_handler_field_user_name.inc
        views/tests/user/views_handler_field_user_name.test
Source: https://www.drupal.org/node/1609088
issue:  Error note in watchdog if a name was set to "filtered" in a view


date:   2017-06-12
module: authchace
files:  AuthcacheNodeHistorySetting.inc
source: None - we did this ourselves.
issue:  Fix for an error we were seeing in watchdog. Assignment seemed incorrect and code was not protected from failure.


date: 2017-10-16
module: WYSIWYG filter
files: wysiwyg_filter.inc
source: None - we did this ourselves
issue: Fix for an error where the module was attempting to attach an array to a string if the object was b or i.


date: 2017-11-27
module: views_bulk_operations
file: viws_bulk_operations.js
source: None - we did this ourselves
issue: Script breaking input select behaviour in VBO forms. The select anywhere on row was not toggling the create butoon enable/disable correctly. Removed line 68 entirely (this.checked = !checked;).

date: 2018-01-22
Module: Views autocomplete filters
file: views_autocomplete_filters.inc
source: https://www.drupal.org/project/views_autocomplete_filters/issues/2645124
issue: Unprotected code fix, at line 49

date: 2018-03-19
Module: AuthcacheNodeHistorySetting.inc
source: We created this fix
issue: Watchdog/php complaining about "Notice: Trying to get property of non-object in AuthcacheNodeHistorySetting->get() (line 50 of /var/www/html/sites/all/modules/contrib/authcache/modules/authcache_node_history/includes/AuthcacheNodeHistorySetting.inc).  We fixed this by altering the foreach so that it makes sure $history['nid']->timestamp exists (in addition to just checking $history['nid']).  We also assign timestamp to a variable of its own rather than straight to the array.


date: 2018-04-24
Module: Views
Source: https://www.drupal.org/project/views/issues/2481401
Issue: Views include is looking for an exposed filter that does not exist - this patch makes sure it also checks if the variable is set prior to running code.


date: 2019-09-18
Module: Advanced Forums
Source: https://www.drupal.org/project/advanced_forum/issues/3064321
Issue: Fixing error introduced by last module security patch.

date: 2020-04-06
Module: Views Data Export
Source: https://www.drupal.org/project/views_data_export/issues/2209853
Issue: Fixing error when exporting data on cluster.

date: 2020-07-23
Module: Core/Filter module
Source: https://www.drupal.org/project/drupal/issues/2016739
Issue: Fixes issue where any text@text is automatically converted to email address.
