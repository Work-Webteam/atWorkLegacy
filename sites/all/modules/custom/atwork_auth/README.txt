Authenticates users with Siteminder Headers

Additional Features:
- Stores user's GUID to support changes in name, email and user-defined fields
- Supports saving updates on user access (username, email, displayname and ministry code)
with hooks to support additional fields
- Archives accounts containing "recycled" IDIRs with user-defined prefix
- Sync accounts with GAL during cron runs with detailed results
- Pulls latest GAL info when a user edit's their account
- disables users from changing GAL fields through Drupal
- Many settings to optimize resources

Install:
Install normally and setup configuration at admin/config/atwork/auth
Syncing requires the atwork_ldap module