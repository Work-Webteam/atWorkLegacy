date:     2016-09-05
module:   devel
file:     fatal-dd-2559061-12.patch
source:   https://www.drupal.org/node/2559061
issue:    the function dd() prevents the proper use of drush when combined with the presences of Composer and the module, devel.


date:    2017-01-26
module:  rules 
file:    rules-2406863-stampede-protection-89.patch
issue:   QF-15-semaphore-table-loop


date:   2017-06-01
module: Views
file:   views_plugin_display_attachment.inc
source: https://www.drupal.org/node/2481401
issue:  Notice: Undefined property: view::$exposed_input in views_plugin_display_attachment->attach_to()


date:   2017-06-01
module: Reply
file:   Reply module
source: https://www.drupal.org/node/2397007
issue:  Reply module was never updated to allow for new admin menu mapping automation, this was patched in.


date:   2017-06-05
module: Views
files:  views/modules/user/views_handler_field_user.inc
        views/modules/user/views_handler_field_user_language.inc
        views/modules/user/views_handler_field_user_name.inc
        views/tests/user/views_handler_field_user_name.test
Source: https://www.drupal.org/node/1609088
issue:  Error note in watchdog if a name was set to "filtered" in a view


date:   2017-06-12
module: ip2country
files:  ip2country.inc
source: https://www.drupal.org/node/2839722
issue:  Server not able to curl the file, so we need to access it directly instead.


date:   2017-06-12
module: autchace
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

date: 2018-01-09
module: Quiz (multichoice)
file: quiz_question.module, line 460
source: None - we did this ourselves
issue: search hook query had incorrect condition, which would break views search_term functionality elsewhere. Fixed this hook by changing n.type to node.type.