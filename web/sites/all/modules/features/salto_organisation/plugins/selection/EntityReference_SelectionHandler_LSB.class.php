<?php

/**
 * A generic Entity handler.
 *
 * The generic base implementation has a variety of overrides to workaround
 * core's largely deficient entity handling.
 */
class EntityReference_SelectionHandler_LSB extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new EntityReference_SelectionHandler_LSB($field, $instance, $entity_type, $entity);
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $entity_info = entity_get_info($field['settings']['target_type']);

    // Merge-in default values.
    $field['settings']['handler_settings'] += array(
      'sort' => array(
        'type' => 'none',
      )
    );

    $form['sort']['type'] = array(
      '#type' => 'select',
      '#title' => t('Sort by'),
      '#options' => array(
        'none' => t("Don't sort"),
        'property' => t('A property of the base table of the entity'),
        'field' => t('A field attached to this entity'),
      ),
      '#ajax' => TRUE,
      '#limit_validation_errors' => array(),
      '#default_value' => $field['settings']['handler_settings']['sort']['type'],
    );

    $form['sort']['settings'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('entityreference-settings')),
      '#process' => array('_entityreference_form_process_merge_parent'),
    );

    if ($field['settings']['handler_settings']['sort']['type'] == 'property') {
      // Merge-in default values.
      $field['settings']['handler_settings']['sort'] += array(
        'property' => NULL,
      );

      $form['sort']['settings']['property'] = array(
        '#type' => 'select',
        '#title' => t('Sort property'),
        '#required' => TRUE,
        '#options' => drupal_map_assoc($entity_info['schema_fields_sql']['base table']),
        '#default_value' => $field['settings']['handler_settings']['sort']['property'],
      );
    }
    elseif ($field['settings']['handler_settings']['sort']['type'] == 'field') {
      // Merge-in default values.
      $field['settings']['handler_settings']['sort'] += array(
        'field' => NULL,
      );

      $fields = array();
      foreach (field_info_instances($field['settings']['target_type']) as $bundle_name => $bundle_instances) {
        foreach ($bundle_instances as $instance_name => $instance_info) {
          $field_info = field_info_field($instance_name);
          foreach ($field_info['columns'] as $column_name => $column_info) {
            $fields[$instance_name . ':' . $column_name] = t('@label (column @column)', array('@label' => $instance_info['label'], '@column' => $column_name));
          }
        }
      }

      $form['sort']['settings']['field'] = array(
        '#type' => 'select',
        '#title' => t('Sort field'),
        '#required' => TRUE,
        '#options' => $fields,
        '#default_value' => $field['settings']['handler_settings']['sort']['field'],
      );
    }

    if ($field['settings']['handler_settings']['sort']['type'] != 'none') {
      // Merge-in default values.
      $field['settings']['handler_settings']['sort'] += array(
        'direction' => 'ASC',
      );

      $form['sort']['settings']['direction'] = array(
        '#type' => 'select',
        '#title' => t('Sort direction'),
        '#required' => TRUE,
        '#options' => array(
          'ASC' => t('Ascending'),
          'DESC' => t('Descending'),
        ),
        '#default_value' => $field['settings']['handler_settings']['sort']['direction'],
      );
    }

    return $form;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $vals = array();

    //check context for new organisations from url
    $url_nid = !empty($_GET['field_organisation_parent'][0]) ? $_GET['field_organisation_parent'] : NULL;
    $root_organisation_nid = !empty($this->entity->field_organisation_parent) ? $this->entity->field_organisation_parent[LANGUAGE_NONE][0]['target_id'] : NULL;

/*
    //untergliederungen -  pool is only dv eas
    if (!empty($root_organisation_nid) || isset($url_nid)) {

      //url is fallback
      $id = $root_organisation_nid ? $root_organisation_nid : $url_nid;

      $vals = salto_licenses_get_earemotes_by_organisation(node_load($id));
    }
    else {
      //all earemotes!
      $vals = salto_licenses_get_earemotes();
    }
    */

    $vals = salto_organisation_get_lsb();

    return array('' => $vals);
  }
}
