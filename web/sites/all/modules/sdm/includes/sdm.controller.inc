<?php
/**
* @file sdm.controller.inc
* Entity Controller.
*/

class SDMEntityController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'sdm_data_id' => '',
    );
    return parent::create($values);
  }
  public function save($entity) {
    parent::save($entity);
    return $this;
  }
  public function delete($ids) {
    $entities = entity_load('sdm_data', $ids);
    foreach($entities as $entity) {
      parent::delete(array($entity->sdm_data_id));
    }
  }
}

/**
 * UI controller.
 */
class SDMUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage Structured Data Markup Entities');
    $items[$this->path]['title'] = t('Structured Data Markup Entities');
    // Set the add path to use the list function.
    $items[$this->path . '/add']['page callback'] = 'sdm_data_type_table';
    $items[$this->path . '/add']['access callback'] = 'user_access';
    $items[$this->path . '/add']['access arguments'] = array('administer_sdm_data');
    // Pass add links through to a form factory.
    $types = sdm_data_types();
    foreach ($types as $type => $info) {
      $items[$this->path . '/add/' . $type] = array(
        'title' => 'Add ' . $type . '  - Structured Data Markup Entity',
        'page callback' => 'sdm_forms_wrapper',
        'page arguments' => array($type, NULL, 'add'),
        'access callback' => 'entity_access',
        'access arguments' => array('create', 'sdm_data', $type),
        'file' => 'includes/sdm.admin.inc',
        'file path' => drupal_get_path('module', 'sdm')
      );
    }
    // Pass manage (edit) calls through to the form factory.
    $items[$this->path . '/manage/%sdm_data']['page callback'] = 'sdm_forms_wrapper';
    $items[$this->path . '/manage/%sdm_data']['page arguments'] = array(NULL, 4, 'edit');
    $items[$this->path . '/manage/%sdm_data']['file path'] = drupal_get_path('module', 'sdm');
    $items[$this->path . '/manage/%sdm_data']['file'] = 'includes/sdm.admin.inc';
    return $items;
  }
}

/**
*  Entity class.
*/
class SDMEntity extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'sdm_data');
  }
  protected function defaultLabel() {
    return $this->name;
  }
  protected function defaultUri() {
    return array('path' => 'admin/structure/sdm/manage/' . $this->identifier());
  }
  // Return whether Structured Data Markup entity is active.
  public function isActive() {
    return $this->active;
  }
  // Activate the Structured Data Markup entity.
  public function activate() {
    $this->active = 1;
    $this->save();
  }

}

/**
*  Campaigns Type class.
*/
class SDMEntityType extends Entity {
  public $type;
  public $label;
  public $weight = 0;
  public $class = 'SDMEntityType';

  public function __construct($values = array()) {
    parent::__construct($values, 'sdm_data_type');
  }

  protected function defaultLabel() {
    return $this->label;
  }
  protected function defaultUri() {
    return array('path' => 'admin/structure/sdm/types/' . $this->identifier());
  }
}

/**
 * UI controller for Types.
 */
class SDMEntityTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage Structured Data Markup Entity Types');
    $items[$this->path]['title'] = t('Structured Data Markup Entity Types');
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    return $items;
  }
}

/**
*  Type Controller.
*/
class SDMEntityTypeController extends EntityAPIControllerExportable {
  public function create(array $values = array()) {
    $values += array(
      'sdm_data_type' => '',
      'label' => '',
      'description' => '',
      'class' => 'SDMEntityDefault',
    );
    return parent::create($values);
  }
}
