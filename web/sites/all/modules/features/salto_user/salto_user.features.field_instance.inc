<?php
/**
 * @file
 * salto_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function salto_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'profile2-main-field_profile_about_me'.
  $field_instances['profile2-main-field_profile_about_me'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'In diesem Feld haben Sie die Möglichkeiten, weitere Informationen zu Ihrer Person mit den anderen Nutzer(inne)n zu teilen. Zum Beispiel könnten Sie beschreiben, welche Aufgabenfelder Sie in Ihrem Verband genau bearbeiten oder zu welchem Thema Sie Austausch suchen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_about_me',
    'label' => 'Über meinen beruflichen Werdegang',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 0,
          'ds_code' => 0,
          'editor' => 'editor',
          'machine' => 0,
          'php_code' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
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
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_categories'.
  $field_instances['profile2-main-field_profile_categories'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Bitte geben Sie hier die Themenfelder an, in denen Sie arbeiten oder für die Sie sich interessieren. Alle Beiträge, Materialien und Gruppen auf dem Bildungsnetz sind einem oder mehreren Themenfeldern zugeordnet. Auf der Basis Ihrer Auswahl werden Ihnen Beiträge und Informationen auf dem Bildungsnetz angezeigt. Die Auswahl kann jederzeit bearbeitet werden.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_categories',
    'label' => 'Themenfeld(er)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_competencies'.
  $field_instances['profile2-main-field_profile_competencies'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Welche Arbeitsschwerpunkte besitzen Sie? Sie können mehrere Angaben zu Ihren beruflichen und privaten Kompetenzen machen und durch Komma trennen, z.B.: Kommunikation, Ehrgeiz,....',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_competencies',
    'label' => 'Arbeitsschwerpunkte',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_contact_email'.
  $field_instances['profile2-main-field_profile_contact_email'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Ihre primäre E-mail Adresse <b>Achtung, diese muss nicht mit Ihrer Login-Adresse übereinstimmen.</b> Diese könne Sie unter <b>Kontoeinstellungen</b> einstellen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_contact_email',
    'label' => 'E-mail',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_contact_mobile'.
  $field_instances['profile2-main-field_profile_contact_mobile'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Eine Nummer, mit der Sie auch unterwegs erreichbar sind.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_contact_mobile',
    'label' => 'Mobil',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_contact_phone'.
  $field_instances['profile2-main-field_profile_contact_phone'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Eine oder mehrere Festnetznummern.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_contact_phone',
    'label' => 'Telefon',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_interests'.
  $field_instances['profile2-main-field_profile_interests'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Welche Interessen haben Sie? Sie können mehrere Angaben zu Ihren beruflichen und privaten Interessen machen und durch Komma trennen, z.B.: Computer, E-Learning,...',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_interests',
    'label' => 'Interessen',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_name_first'.
  $field_instances['profile2-main-field_profile_name_first'] = array(
    'bundle' => 'main',
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
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_name_first',
    'label' => 'Vorname',
    'required' => 1,
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

  // Exported field_instance: 'profile2-main-field_profile_name_last'.
  $field_instances['profile2-main-field_profile_name_last'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_name_last',
    'label' => 'Nachname',
    'required' => 1,
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

  // Exported field_instance: 'profile2-main-field_profile_postal_address'.
  $field_instances['profile2-main-field_profile_postal_address'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Sie können optional Ihre geschäftliche Adresse hinterlegen und sie somit mit allen angemeldete Nutzer/innen, beispielsweise andere Bildungsverantwortliche, teilen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_postal_address',
    'label' => 'Adresse',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'DE' => 'DE',
        ),
        'default_country' => '',
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-country' => 'address-hide-country',
          'organisation' => 0,
          'name-oneline' => 0,
          'name-full' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'profile2-main-field_profile_sports'.
  $field_instances['profile2-main-field_profile_sports'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'In welchen Sportarten sind Sie aktiv? Sie können mehrere Angaben zu Ihren beruflichen und privaten Sportarten machen und durch Komma trennen, z.B.: Ski-Alpin, Fußball,....',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_profile_sports',
    'label' => 'Sportarten',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'profile2-main-field_user_picture'.
  $field_instances['profile2-main-field_user_picture'] = array(
    'bundle' => 'main',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'field_name' => 'field_user_picture',
    'label' => 'Profilbild',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'user_pictures',
      'file_extensions' => 'png gif jpg jpeg',
      'focus' => 1,
      'focus_lock_ratio' => 1,
      'focus_min_size' => '210x210',
      'focus_required' => 0,
      'max_filesize' => '',
      'max_resolution' => '2048x2048',
      'min_resolution' => '220x220',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'user_220x200',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'user-user-field_salto_newsletter'.
  $field_instances['user-user-field_salto_newsletter'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Wenn Sie keine Newsletter erhalten möchten, können Sie hier das Häkchen entfernen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_salto_newsletter',
    'label' => 'Newsletter',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'user-user-field_user_organisations'.
  $field_instances['user-user-field_user_organisations'] = array(
    'bundle' => 'user',
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
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_user_organisations',
    'label' => 'Organisations',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
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
      'user_register_form' => 0,
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
  t('Adresse');
  t('Arbeitsschwerpunkte');
  t('Bitte geben Sie hier die Themenfelder an, in denen Sie arbeiten oder für die Sie sich interessieren. Alle Beiträge, Materialien und Gruppen auf dem Bildungsnetz sind einem oder mehreren Themenfeldern zugeordnet. Auf der Basis Ihrer Auswahl werden Ihnen Beiträge und Informationen auf dem Bildungsnetz angezeigt. Die Auswahl kann jederzeit bearbeitet werden.');
  t('E-mail');
  t('Eine Nummer, mit der Sie auch unterwegs erreichbar sind.');
  t('Eine oder mehrere Festnetznummern.');
  t('Ihre primäre E-mail Adresse <b>Achtung, diese muss nicht mit Ihrer Login-Adresse übereinstimmen.</b> Diese könne Sie unter <b>Kontoeinstellungen</b> einstellen.');
  t('In diesem Feld haben Sie die Möglichkeiten, weitere Informationen zu Ihrer Person mit den anderen Nutzer(inne)n zu teilen. Zum Beispiel könnten Sie beschreiben, welche Aufgabenfelder Sie in Ihrem Verband genau bearbeiten oder zu welchem Thema Sie Austausch suchen.');
  t('In welchen Sportarten sind Sie aktiv? Sie können mehrere Angaben zu Ihren beruflichen und privaten Sportarten machen und durch Komma trennen, z.B.: Ski-Alpin, Fußball,....');
  t('Interessen');
  t('Mobil');
  t('Nachname');
  t('Newsletter');
  t('Organisations');
  t('Profilbild');
  t('Sie können optional Ihre geschäftliche Adresse hinterlegen und sie somit mit allen angemeldete Nutzer/innen, beispielsweise andere Bildungsverantwortliche, teilen.');
  t('Sportarten');
  t('Telefon');
  t('Themenfeld(er)');
  t('Vorname');
  t('Welche Arbeitsschwerpunkte besitzen Sie? Sie können mehrere Angaben zu Ihren beruflichen und privaten Kompetenzen machen und durch Komma trennen, z.B.: Kommunikation, Ehrgeiz,....');
  t('Welche Interessen haben Sie? Sie können mehrere Angaben zu Ihren beruflichen und privaten Interessen machen und durch Komma trennen, z.B.: Computer, E-Learning,...');
  t('Wenn Sie keine Newsletter erhalten möchten, können Sie hier das Häkchen entfernen.');
  t('Über meinen beruflichen Werdegang');

  return $field_instances;
}
