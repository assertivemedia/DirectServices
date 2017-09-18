<?php
/**
 * @file
 * google_social_profile_sdm.features.inc
 */

/**
 * Implements hook_default_sdm_data_type().
 */
function google_social_profile_sdm_default_sdm_data_type() {
  $items = array();
  $items['google_social_profile'] = entity_import('sdm_data_type', '{
    "type" : null,
    "label" : "Google Social Profile",
    "weight" : 0,
    "class" : "SDMEntityType",
    "sdm_data_type" : "google_social_profile",
    "description" : "SDM Type for adding Google Social Profile JSON\\/LD objects to your site. See https:\\/\\/developers.google.com\\/structured-data\\/customize\\/social-profiles.",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
