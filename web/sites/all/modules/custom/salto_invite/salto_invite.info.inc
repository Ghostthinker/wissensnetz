<?php

/**
 * @file
 * Provides Entity metadata integration.
 */

/**
 * Extend the defaults.
 */
class SaltoInviteMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    // Unset the uid property, as it is available via the user anyway.
    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The user for which to log the message."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'schema field' => 'uid',
      'required' => TRUE,
    );

    $properties['created'] = array(
      'type' => 'date',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The time the invite was sent.'),
    ) + $properties['created'];

    $properties['used'] = array(
      'type' => 'boolean',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The time the invite was sent.'),
    ) + $properties['used'];

    return $info;
  }
}
