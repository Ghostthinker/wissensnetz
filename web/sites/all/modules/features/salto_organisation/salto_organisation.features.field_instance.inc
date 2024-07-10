<?php

/**
 * @file
 * salto_organisation.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function salto_organisation_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_organisation-comment_body'.
  $field_instances['comment-comment_node_organisation-comment_body'] = array(
    'bundle' => 'comment_node_organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-organisation-body'.
  $field_instances['node-organisation-body'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Kurzbeschreibung des Verbandes',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-organisation-cer_settings'.
  $field_instances['node-organisation-cer_settings'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'cer_settings',
    'label' => 'Synchronize this Beitrag with...',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-organisation-cer_store_settings'.
  $field_instances['node-organisation-cer_store_settings'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'cer_store_settings',
    'label' => 'Remember these settings',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_api_enable_uuid'.
  $field_instances['node-organisation-field_org_api_enable_uuid'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_api_enable_uuid',
    'label' => 'Übermittlung von personenbezogenen Daten ist optional / UUID erforderlich',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_custom_license_mail'.
  $field_instances['node-organisation-field_org_custom_license_mail'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_custom_license_mail',
    'label' => 'Ergänzungstext beim Lizenzversand per E-Mail',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_dv_license_settings'.
  $field_instances['node-organisation-field_org_dv_license_settings'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 'none',
      ),
    ),
    'deleted' => 0,
    'description' => 'Ihr Dachverband kann standardmäßig auf anonymisierte Lizenzen Ihres Verbandes zugreifen. Zusätzliche Einsicht in
personenbezogene Daten und die Möglichkeit Ihre Lizenzen zu bearbeiten können Sie hier optional erteilen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_dv_license_settings',
    'label' => 'Zugriff auf Lizenzdaten durch Dachverband',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_lsb_inspection'.
  $field_instances['node-organisation-field_org_lsb_inspection'] = array(
    'bundle' => 'organisation',
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_lsb_inspection',
    'label' => 'Einsicht in personenbezogene Daten für folgende LSBs/LSVs freigeben',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'entityreference_duallistbox',
      'settings' => array(
        'pass_argument' => FALSE,
        'view' => '',
      ),
      'type' => 'entityreference_duallistbox_widget',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_plz'.
  $field_instances['node-organisation-field_org_plz'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_plz',
    'label' => 'PLZ',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ckeditor' => 'ckeditor',
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ckeditor' => array(
              'weight' => 0,
            ),
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 15,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_position'.
  $field_instances['node-organisation-field_org_position'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Bitte vermerken Sie hier die Position des/der Unterschriftbevollmächtigten (analog zu "Präsident des DOSB"). Die Angabe ist zwingend erforderlich damit die Position auf der Lizenz korrekt angezeigt wird.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_position',
    'label' => 'Position',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-organisation-field_org_president_name'.
  $field_instances['node-organisation-field_org_president_name'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Bitte vermerken Sie hier den Namen Ihrer/s Unterschriftbevollmächtigten für die Lizenzausstellung. Dieser wird dann entsprechend auf den Lizenzvordrucken angezeigt.
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_org_president_name',
    'label' => 'Name des/der Unterschriftbevollmächtigten',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-organisation-field_organisation_article_name'.
  $field_instances['node-organisation-field_organisation_article_name'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Bitte vermerken Sie hier den Verbandsnamen mit Artikel (der, die, das) für den Lizenzvordruck.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_article_name',
    'label' => 'Verbandname mit Artikel für den Lizenzdruck',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_bundesland'.
  $field_instances['node-organisation-field_organisation_bundesland'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Hier können Sie das Bundesland für diese Organisation festlegen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_bundesland',
    'label' => 'Bundesland',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_category'.
  $field_instances['node-organisation-field_organisation_category'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 'UG',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_category',
    'label' => 'Verbändegruppe',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-organisation-field_organisation_custom_labels'.
  $field_instances['node-organisation-field_organisation_custom_labels'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_custom_labels',
    'label' => 'Verbandseigene Zusatzfelder für Lizenzen (optional)',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_earemotes'.
  $field_instances['node-organisation-field_organisation_earemotes'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_earemotes',
    'label' => 'Ausbildungsgänge',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'entityreference_duallistbox',
      'settings' => array(
        'pass_argument' => FALSE,
        'view' => '',
      ),
      'type' => 'entityreference_duallistbox_widget',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_key'.
  $field_instances['node-organisation-field_organisation_key'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Das (eindeutige) Verbandskürzel der Organisation. Wird unter anderdem für die Lizenznummern dieser Organisation verwendet.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_key',
    'label' => 'Verbandskürzel',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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

  // Exported field_instance: 'node-organisation-field_organisation_logo'.
  $field_instances['node-organisation-field_organisation_logo'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Hier können Sie ein Logo Ihrer Organisation hochladen. Dies wird zur Erstellung der Lizenzen benötigt. Wir empfehlen daher ein Verbandslogo mit Text zu verwenden (falls vorhanden). Die Datei sollte eine Auflösung von 150-300 dpi haben und eine Größe von 1 MB nicht überschreiten, da die spätere Ladezeit der Lizenzen u. a. von der Dateigröße abhängig ist.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_logo',
    'label' => 'Logo',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'logos',
      'file_extensions' => 'jpeg jpg png gif',
      'max_filesize' => '20 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_obscure'.
  $field_instances['node-organisation-field_organisation_obscure'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_obscure',
    'label' => 'Zentrale Speicherung der Lizenzdaten',
    'required' => 0,
    'settings' => array(
      'max' => 1,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_parent'.
  $field_instances['node-organisation-field_organisation_parent'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => 'Hat diese Organisation eine Dachorganisation?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_parent',
    'label' => 'Dachorganisation',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => 0,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_remote_id'.
  $field_instances['node-organisation-field_organisation_remote_id'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organisation_remote_id',
    'label' => 'ListMS ID',
    'required' => FALSE,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_signature'.
  $field_instances['node-organisation-field_organisation_signature'] = array(
    'bundle' => 'organisation',
    'deleted' => 0,
    'description' => 'Hier können Sie die Unterschrift des/der Unterschriftbevollmächtigten für die Lizenzausstellung hochladen.Diese wird ausschließlich zur Erstellung von Lizenzen benötigt und ist nicht öffentlich einsehbar. Bitte achten Sie darauf, dass die Unterschrift freigestellt ist und das Bild mindestens eine Auflösung von 150 dpi hat. Um eine einheitliche Optik auf der Lizenz zu schaffen, ist bitte eine <strong>schwarze</strong> Unterschrift zu nutzen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_signature',
    'label' => 'Unterschrift des/der Unterschriftbevollmächtigten',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'signatures',
      'file_extensions' => 'jpeg jpg png gif',
      'max_filesize' => '25 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-organisation-field_organisation_sportkreis'.
  $field_instances['node-organisation-field_organisation_sportkreis'] = array(
    'bundle' => 'organisation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_organisation_sportkreis',
    'label' => 'Sportkreis',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-organisation-group_group'.
  $field_instances['node-organisation-group_group'] = array(
    'bundle' => 'organisation',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Determine if this is an OG group.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(
          'field_name' => FALSE,
        ),
        'type' => 'og_group_subscribe',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => 1,
    'entity_type' => 'node',
    'field_name' => 'group_group',
    'label' => 'Group',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_group_subscribe',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_group_subscribe',
      ),
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'og_hide' => TRUE,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'og_membership-organisation_membership-field_organisation_position'.
  $field_instances['og_membership-organisation_membership-field_organisation_position'] = array(
    'bundle' => 'organisation_membership',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Geben Sie hier Ihre Funktion in der Organisation ein. Falls Sie mehrere Funktionen angeben wollen, trennen Sie diese mit einem Komma. Ihre Haupttätikeit sollte dabei an erster Stelle stehen.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'membership_compact' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'og_membership',
    'field_name' => 'field_organisation_position',
    'label' => 'Funktion',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'salto_invite-organisation_invite-field_profile_contact_email'.
  $field_instances['salto_invite-organisation_invite-field_profile_contact_email'] = array(
    'bundle' => 'organisation_invite',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'entity_type' => 'salto_invite',
    'field_name' => 'field_profile_contact_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'salto_invite-organisation_invite-field_profile_name_first'.
  $field_instances['salto_invite-organisation_invite-field_profile_name_first'] = array(
    'bundle' => 'organisation_invite',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'entity_type' => 'salto_invite',
    'field_name' => 'field_profile_name_first',
    'label' => 'Vorname',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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

  // Exported field_instance:
  // 'salto_invite-organisation_invite-field_profile_name_last'.
  $field_instances['salto_invite-organisation_invite-field_profile_name_last'] = array(
    'bundle' => 'organisation_invite',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'entity_type' => 'salto_invite',
    'field_name' => 'field_profile_name_last',
    'label' => 'Nachname',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 'comment_with_link',
          'ds_code' => 'ds_code',
          'editor' => 'editor',
          'machine' => 'machine',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'comment_with_link' => array(
              'weight' => 0,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'editor' => array(
              'weight' => -10,
            ),
            'machine' => array(
              'weight' => -8,
            ),
            'php_code' => array(
              'weight' => -7,
            ),
            'plain_text' => array(
              'weight' => -9,
            ),
          ),
        ),
      ),
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'salto_invite-organisation_invite-field_salto_invite_groups'.
  $field_instances['salto_invite-organisation_invite-field_salto_invite_groups'] = array(
    'bundle' => 'organisation_invite',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'salto_invite',
    'field_name' => 'field_salto_invite_groups',
    'label' => 'Groups',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'salto_invite-organisation_invite-field_salto_invite_og_role'.
  $field_instances['salto_invite-organisation_invite-field_salto_invite_og_role'] = array(
    'bundle' => 'organisation_invite',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Rolle die bei der Anmeldung automatisch gesetzt wird.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'salto_invite',
    'field_name' => 'field_salto_invite_og_role',
    'label' => 'OG Rolle',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'salto_invite-organisation_invite-field_salto_invite_organisations'.
  $field_instances['salto_invite-organisation_invite-field_salto_invite_organisations'] = array(
    'bundle' => 'organisation_invite',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'salto_invite',
    'field_name' => 'field_salto_invite_organisations',
    'label' => 'Organisations',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 1,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Ausbildungsgänge');
  t('Bitte vermerken Sie hier den Namen Ihrer/s Unterschriftbevollmächtigten für die Lizenzausstellung. Dieser wird dann entsprechend auf den Lizenzvordrucken angezeigt.
');
  t('Bitte vermerken Sie hier den Verbandsnamen mit Artikel (der, die, das) für den Lizenzvordruck.');
  t('Bitte vermerken Sie hier die Position des/der Unterschriftbevollmächtigten (analog zu "Präsident des DOSB"). Die Angabe ist zwingend erforderlich damit die Position auf der Lizenz korrekt angezeigt wird.');
  t('Bundesland');
  t('Comment');
  t('Dachorganisation');
  t('Das (eindeutige) Verbandskürzel der Organisation. Wird unter anderdem für die Lizenznummern dieser Organisation verwendet.');
  t('Determine if this is an OG group.');
  t('Einsicht in personenbezogene Daten für folgende LSBs/LSVs freigeben');
  t('Email');
  t('Ergänzungstext beim Lizenzversand per E-Mail');
  t('Funktion');
  t('Geben Sie hier Ihre Funktion in der Organisation ein. Falls Sie mehrere Funktionen angeben wollen, trennen Sie diese mit einem Komma. Ihre Haupttätikeit sollte dabei an erster Stelle stehen.');
  t('Group');
  t('Groups');
  t('Hat diese Organisation eine Dachorganisation?');
  t('Hier können Sie das Bundesland für diese Organisation festlegen.');
  t('Hier können Sie die Unterschrift des/der Unterschriftbevollmächtigten für die Lizenzausstellung hochladen.Diese wird ausschließlich zur Erstellung von Lizenzen benötigt und ist nicht öffentlich einsehbar. Bitte achten Sie darauf, dass die Unterschrift freigestellt ist und das Bild mindestens eine Auflösung von 150 dpi hat. Um eine einheitliche Optik auf der Lizenz zu schaffen, ist bitte eine <strong>schwarze</strong> Unterschrift zu nutzen.');
  t('Hier können Sie ein Logo Ihrer Organisation hochladen. Dies wird zur Erstellung der Lizenzen benötigt. Wir empfehlen daher ein Verbandslogo mit Text zu verwenden (falls vorhanden). Die Datei sollte eine Auflösung von 150-300 dpi haben und eine Größe von 1 MB nicht überschreiten, da die spätere Ladezeit der Lizenzen u. a. von der Dateigröße abhängig ist.');
  t('Ihr Dachverband kann standardmäßig auf anonymisierte Lizenzen Ihres Verbandes zugreifen. Zusätzliche Einsicht in
personenbezogene Daten und die Möglichkeit Ihre Lizenzen zu bearbeiten können Sie hier optional erteilen.');
  t('Kurzbeschreibung des Verbandes');
  t('ListMS ID');
  t('Logo');
  t('Nachname');
  t('Name des/der Unterschriftbevollmächtigten');
  t('OG Rolle');
  t('Organisations');
  t('PLZ');
  t('Position');
  t('Remember these settings');
  t('Rolle die bei der Anmeldung automatisch gesetzt wird.');
  t('Sportkreis');
  t('Synchronize this Beitrag with...');
  t('Unterschrift des/der Unterschriftbevollmächtigten');
  t('Verbandname mit Artikel für den Lizenzdruck');
  t('Verbandseigene Zusatzfelder für Lizenzen (optional)');
  t('Verbandskürzel');
  t('Verbändegruppe');
  t('Vorname');
  t('Zentrale Speicherung der Lizenzdaten');
  t('Zugriff auf Lizenzdaten durch Dachverband');
  t('Übermittlung von personenbezogenen Daten ist optional / UUID erforderlich');

  return $field_instances;
}
