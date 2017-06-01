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