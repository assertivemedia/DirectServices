<?php
/**
 * @file
 * google_social_profile_sdm.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function google_social_profile_sdm_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'sdm_data-google_social_profile-field_socia_profile_name'
  $field_instances['sdm_data-google_social_profile-field_social_profile_name'] = array(
    'bundle' => 'google_social_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a name for your Organization or Person, depending on what you put in the @type field.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'sdm_data',
    'field_name' => 'field_social_profile_name',
    'label' => 'name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'sdm_data-google_social_profile-field_social_profile_sameas'
  $field_instances['sdm_data-google_social_profile-field_social_profile_sameas'] = array(
    'bundle' => 'google_social_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide the <i>abosolute urls</i> to your social profile pages. E.G. http://www.facebook.com/my-profile-id.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'sdm_data',
    'field_name' => 'field_social_profile_sameas',
    'label' => 'sameAs',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'sdm_data-google_social_profile-field_social_profile_url'
  $field_instances['sdm_data-google_social_profile-field_social_profile_url'] = array(
    'bundle' => 'google_social_profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Supply the <i>absolute url</i> to your official website.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'sdm_data',
    'field_name' => 'field_social_profile_url',
    'label' => 'url',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a name for your Organization or Person, depending on what you put in the @type field.');
  t('Provide the <i>abosolute urls</i> to your social profile pages. E.G. http://www.facebook.com/my-profile-id.');
  t('Supply the <i>absolute url</i> to your official website.');
  t('name');
  t('sameAs');
  t('url');

  return $field_instances;
}
