<?php
/**
 * @file
 * sdm.admin.inc
 *
 * Replace sdm_data with the actual entity name.
 */

/**
 * Callback for the cancel link on sdm forms.
 */
function sdm_form_redirect($form, &$form_state) {
  $data = entity_get_info('sdm_data');
  $form_state['redirect'] = $data['admin ui']['path'];
}

function sdm_data_type_name_exists($name) {
  $query = "SELECT sdm_data_type from {sdm_data_type} sdm_type WHERE (sdm_data_type=:name);";
  $result = db_query($query, array(':name' => $name))->fetchField();
  return (!($result == FALSE));
}

/**
 * SDM delete form.
 */
function sdm_data_form_delete_confirm($form, &$form_state, $sdm_data) {
  $form_state['sdm_data'] = $sdm_data;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['sdm_data_id'] = array('#type' => 'value', '#value' => entity_id('sdm_data' , $sdm_data));
  return confirm_form($form,
    t('Are you sure you want to delete the structured data markup entity %title?', array('%title' => entity_label('sdm_data', $sdm_data))),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Group delete form submit handler.
 */
function sdm_data_form_delete_confirm_submit($form, &$form_state) {
  $sdm_data = $form_state['sdm_data'];
  sdm_data_delete($sdm_data);

  watchdog('sdm_data', '@sdm_data: deleted %title.', array('@sdm_data' => $sdm_data->sdm_data_id, '%title' => $sdm_data->label));
  drupal_set_message(t('@sdm_data %title has been deleted.', array('@sdm_data' => $sdm_data->sdm_data_id, '%title' => $sdm_data->label)));

  sdm_form_redirect($form, $form_state);
}

/**
 * Structured Data Markup Entity Form.
 */
function sdm_data_form($form, &$form_state, $sdm_data = NULL) {
  $form_state['sdm_data'] = $sdm_data;
  $form_state['entity_type'] = 'sdm_data';
  $form['name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Name'),
    '#description' => t('Administrative name for this SDM data entity'),
    '#default_value' => $sdm_data->name,
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Administrative description for this SDM data entity'),
    '#required' => FALSE,
    '#default_value' => $sdm_data->description,
  );

  $form['context'] = array(
    '#type' => 'textarea',
    '#required' => FALSE,
    '#title' => t('@Context'),
    '#description' => t('The @context json+ld node object, e.g: http://schema.org. This can be a full JSON object. See https://www.w3.org/TR/json-ld/#dfn-context-definition for more information about JSON context definitions.'),
    '#default_value' => (isset($sdm_data->context)) ? $sdm_data->context :
      ((empty($form_state['values']['context'])) ? 'http://schema.org' : $form_state['values']['context']),
  );

  $form['id'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('@ID'),
    '#description' => t('The @id json+ld node object. Use this to specify an externally accessible id for this SDM object. See https://www.w3.org/TR/json-ld/#node-identifiers'),
    '#default_value' => (isset($sdm_data->id)) ? $sdm_data->id :
      ((empty($form_state['values']['id'])) ? NULL : $form_state['values']['id']),
  );

  $form['graph'] = array(
    '#type' => 'textarea',
    '#required' => FALSE,
    '#title' => t('@Graph'),
    '#description' => t('The @graph json+ld node object. Type in the relevant JSON string. See https://www.w3.org/TR/json-ld/#named-graphs'),
    '#default_value' => (isset($sdm_data->graph)) ? $sdm_data->graph :
      ((empty($form_state['values']['graph'])) ? NULL : $form_state['values']['graph']),
  );

  $form['type'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('@Type'),
    '#description' => t('The @type json+ld node object. Supply one or more IRI or term names, comma separated. See https://www.w3.org/TR/json-ld/#specifying-the-type'),
    '#default_value' => (isset($sdm_data->type)) ? $sdm_data->type :
      ((empty($form_state['values']['type'])) ? NULL : $form_state['values']['type']),
  );

  $form['reverse'] = array(
    '#type' => 'textarea',
    '#required' => FALSE,
    '#title' => t('@Reverse'),
    '#description' => t('The @reverse json+ld node object. Type in the relevant JSON string. See https://www.w3.org/TR/json-ld/#node-objects and the section on reverse objects.'),
    '#default_value' => (isset($sdm_data->reverse)) ? $sdm_data->reverse :
      ((empty($form_state['values']['reverse'])) ? NULL : $form_state['values']['reverse']),
  );

  field_attach_form('sdm_data', $sdm_data, $form, $form_state);

  $form['actions'] = array(
    '#weight' => 1000,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save SDM Object'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('sdm_data_form_cancel'),
  );

  return $form;
}

/**
 * Structured Data Markup Entity submit handler.
 */
function sdm_data_form_submit($form, &$form_state) {
  $sdm_data = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and set the redirect url.
  $sdm_data->save();
  sdm_form_redirect($form, $form_state);
}

/**
 * Callback for the cancel link on Structured Data Markup Entity forms.
 */
function sdm_data_form_cancel() {
  $data = entity_get_info('sdm_data');
  drupal_goto($data['admin ui']['path']);
}

/**
 * Form to delete a Structured Data Markup Entity.
 */
function sdm_data_delete_form($form, &$form_state, $sdm_data) {
  $sdm_data_info = entity_get_info('sdm_data');
  $form_state['#sdm_data_id'] = $sdm_data->sdm_data_id;
  return confirm_form($form, t('Really delete SDM Data Object (cannot be undone)?'), $sdm_data_info['admin ui']['path'], null, t('Delete'), t('Cancel'));

}

/**
 * Submit callback for deleting a Structured Data Markup Entity.
 */
function sdm_data_delete_form_submit(&$form, &$form_state) {
  sdm_data_delete($form_state['#sdm_data_id']);
  sdm_form_redirect($form, $form_state);
}

/**
 * Structured Data Markup entity form.
 */
function sdm_data_type_form($form, &$form_state, $sdm_data_type = NULL) {
  $form['label'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Label'),
    '#default_value' => $sdm_data_type->label,
  );

  $form['sdm_data_type'] = array(
    '#type' => 'machine_name',
    '#required' => TRUE,
    '#title' => t('Type:'),
    '#default_value' => $sdm_data_type->sdm_data_type,
    '#maxlength' => 32,
    '#disabled' => !empty($sdm_data_type->sdm_data_type),
    '#machine_name' => array(
      'exists' => 'sdm_data_type_name_exists',
      'source' => array('label'),
    ),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#required' => FALSE,
    '#default_value' => $sdm_data_type->description,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save SDM Type'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('sdm_data_form_cancel'),
  );

  return $form;
}

/**
 * Structured Data Markup Entity Type submit handler.
 */
function sdm_data_type_form_submit(&$form, &$form_state) {
  $sdm_data_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and set the redirect url.
  $sdm_data_type->save();
  menu_rebuild();
  sdm_form_redirect($form, $form_state);
}
