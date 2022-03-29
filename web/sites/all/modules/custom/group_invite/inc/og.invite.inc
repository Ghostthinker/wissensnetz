<?php

/**
 * @file
 * Main class  entities provided by Entity API.
 */
class OgInvite extends Entity {

  public $type;

  public $label;

  public $weight = 0;

  public function __construct($values = []) {
    parent::__construct($values, 'example_task_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

}

class OgInviteController extends EntityAPIControllerExportable {

  public function create(array $values = []) {
    $values += [
      'label' => '',
      'description' => '',
    ];
    return parent::create($values);
  }

  /**
   * Save Task Type.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    variable_set('menu_rebuild_needed', TRUE);
  }

}
