<?php
/**
 * @file
 * atwork_user_following.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function atwork_user_following_taxonomy_default_vocabularies() {
  return array(
    'profile_interests' => array(
      'name' => 'Profile Interests',
      'machine_name' => 'profile_interests',
      'description' => 'Interests taxonomy for profiles',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'profile_skills' => array(
      'name' => 'Profile skills',
      'machine_name' => 'profile_skills',
      'description' => 'Skills taxonomy for profiles',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
