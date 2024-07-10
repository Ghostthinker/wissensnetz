<?php

/**
 * @file
 * salto_knowledgebase.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function salto_knowledgebase_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_post-comment_body'.
  $field_instances['comment-comment_node_post-comment_body'] = array(
    'bundle' => 'comment_node_post',
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
    'ds_extras_field_template' => '',
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Kommentar',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'comment_with_link' => 0,
          'ds_code' => 0,
          'editor' => 0,
          'editor_comment' => 'editor_comment',
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
            'editor_comment' => array(
              'weight' => -9,
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
        'rows' => 7,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-group-field_default_access_post'.
  $field_instances['node-group-field_default_access_post'] = array(
    'bundle' => 'group',
    'default_value' => array(
      0 => array(
        'read' => 3,
        'edit' => 3,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'salto_knowledgebase',
        'settings' => array(),
        'type' => 'salto_collaboration_default',
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
    'field_name' => 'field_default_access_post',
    'label' => 'Beiträge',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'salto_knowledgebase',
      'settings' => array(),
      'type' => 'salto_collaboration_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-post-body'.
  $field_instances['node-post-body'] = array(
    'bundle' => 'post',
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
      'salto_diff' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 1,
          'more_text' => 'Weiterlesen',
          'summary_handler' => 'full',
          'trim_length' => 600,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Inhalt',
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
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-post-field_content_rating'.
  $field_instances['node-post-field_content_rating'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => 1,
          'style' => 'user',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/contrib/fivestar/widgets/outline/outline.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 3,
      ),
      'salto_diff' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_content_rating',
    'label' => 'Content Rating',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'allow_ownvote' => 1,
      'allow_revote' => 1,
      'stars' => 5,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(),
      'type' => 'exposed',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-post-field_kb_content_category'.
  $field_instances['node-post-field_kb_content_category'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Bitte ordnen Sie hier diesen Beitrag zu einer der Themenfelder zu. Dies erleichtert Ihnen die thematische Ausrichtung und verbessert die Auffindbarkeit Ihres Beitrags für andere Bildungsnetz-Mitglieder.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'salto_diff' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_kb_content_category',
    'label' => 'Themenfeld(er)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'term_reference_tree',
      'settings' => array(
        'cascading_selection' => 0,
        'filter_view' => '',
        'leaves_only' => 0,
        'max_depth' => '',
        'parent_term_id' => '',
        'select_parents' => 1,
        'start_minimized' => 1,
        'token_display' => '',
        'track_list' => 0,
      ),
      'type' => 'term_reference_tree',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-post-field_og_group'.
  $field_instances['node-post-field_og_group'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'salto_diff' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_og_group',
    'label' => 'Gruppe',
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
          'action' => 'disable',
          'action_on_edit' => 1,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => 1,
            'url' => 1,
          ),
          'skip_perm' => 'bypass node access',
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-post-field_post_attachment'.
  $field_instances['node-post-field_post_attachment'] = array(
    'bundle' => 'post',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'salto_diff' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_post_attachment',
    'label' => 'Anhang',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => '',
      'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov mp4 m4a m4v mpeg avi ogg oga ogv weba webp webm',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'bildungsnetz' => 0,
          'private' => 'private',
          'public' => 0,
          'webresource' => 0,
        ),
        'allowed_types' => array(
          'audio' => 'audio',
          'document' => 'document',
          'image' => 'image',
          'swf' => 0,
          'video' => 'video',
          'webresource' => 0,
        ),
        'browser_plugins' => array(
          'groups_files--media_browser_1' => 0,
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'salto_media_browser--media_browser_1' => 'salto_media_browser--media_browser_1',
          'salto_media_browser--media_browser_my_files' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-post-field_post_authors'.
  $field_instances['node-post-field_post_authors'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'salto_diff' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_post_authors',
    'label' => 'Autoren',
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
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
        'user_autocomplete' => 1,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-post-field_post_collaboration'.
  $field_instances['node-post-field_post_collaboration'] = array(
    'bundle' => 'post',
    'default_value' => array(
      0 => array(
        'read' => 1,
        'edit' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'salto_diff' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_post_collaboration',
    'label' => 'collaboration',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'salto_knowledgebase',
      'settings' => array(),
      'type' => 'salto_collaboration_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-post-field_post_tags'.
  $field_instances['node-post-field_post_tags'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Mit Hilfe von Schlagworten können Sie beim schnellen Finden und Einordnung dieses Beitrag helfen. Geben Sie einfach kurze Begriffe durch Kommata getrennt, wie zum Beispiel Lernen, Digitale Medien, Konzept an.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'salto_knowledgebase',
        'settings' => array(),
        'type' => 'salto_taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'salto_diff' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_post_tags',
    'label' => 'Schlagworte',
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

  // Exported field_instance: 'node-post-field_publishing_date'.
  $field_instances['node-post-field_publishing_date'] = array(
    'bundle' => 'post',
    'deleted' => 0,
    'description' => 'Während Dein Beitrag als Entwurf gespeichert oder die automatische Veröffentlichung geplant ist, können ihn nur Personen mit <strong>Änderungszugriff</strong> sehen und bearbeiten. Sobald der Veröffentlichungszeitpunkt erreicht ist, verfällt der Entwurfsmodus und alle Personen unter “Lesezugriff” können Deinen Beitrag sehen. Zu diesem Zeitpunkt werden sie auch abhängig von den personalisierten Benachrichtigungseinstellungen dazu benachrichtigt.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_publishing_date',
    'label' => 'Publishing date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 60,
        'input_format' => 'site-wide',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-0:+10',
      ),
      'type' => 'date_popup',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-post-field_publishing_options'.
  $field_instances['node-post-field_publishing_options'] = array(
    'bundle' => 'post',
    'default_value' => array(
      0 => array(
        'value' => 'immediate',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_publishing_options',
    'label' => 'Veröffentlichung planen',
    'required' => 0,
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

  // Exported field_instance: 'node-post-field_references'.
  $field_instances['node-post-field_references'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => 'Hier können Sie auf andere Beiträge verweisen.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'salto_diff' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_references',
    'label' => 'Referenzen',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
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
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
        'user_autocomplete' => 0,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-post-field_teaser_image'.
  $field_instances['node-post-field_teaser_image'] = array(
    'bundle' => 'post',
    'deleted' => 0,
    'description' => 'You can optionally set a preview image here. This is then used for a more visually appealing preview of this post on the homepage and overviews. <b>Please no lettering</b>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
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
    'field_name' => 'field_teaser_image',
    'label' => 'Vorschaubild',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'jpeg jpg png gif bmp tiff tif svg',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-post-og_vocabulary'.
  $field_instances['node-post-og_vocabulary'] = array(
    'bundle' => 'post',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => 'Bitte ordnen Sie hier diesen Beitrag zu einer der Beitragskategorien zu. Dies erleichtert Ihnen die thematische Ausrichtung und verbessert die Auffindbarkeit Ihres Beitrags für andere Bildungsnetz-Mitglieder.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'og_vocabulary',
    'label' => 'OG vocabulary',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
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
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og_vocab',
      'settings' => array(),
      'type' => 'og_vocab_complex',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-lehr_lern_material_kategorien-field_term_sync_post_ref'.
  $field_instances['taxonomy_term-lehr_lern_material_kategorien-field_term_sync_post_ref'] = array(
    'bundle' => 'lehr_lern_material_kategorien',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_term_sync_post_ref',
    'label' => 'Referenz auf Beiträge TF',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-wissensbasis_kategorien-field_taxonomy_author'.
  $field_instances['taxonomy_term-wissensbasis_kategorien-field_taxonomy_author'] = array(
    'bundle' => 'wissensbasis_kategorien',
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
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_taxonomy_author',
    'label' => 'Autor',
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
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-wissensbasis_kategorien-field_term_sync_material_ref'.
  $field_instances['taxonomy_term-wissensbasis_kategorien-field_term_sync_material_ref'] = array(
    'bundle' => 'wissensbasis_kategorien',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_term_sync_material_ref',
    'label' => 'Referenz auf Material TF',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Anhang');
  t('Autor');
  t('Autoren');
  t('Beiträge');
  t('Bitte ordnen Sie hier diesen Beitrag zu einer der Beitragskategorien zu. Dies erleichtert Ihnen die thematische Ausrichtung und verbessert die Auffindbarkeit Ihres Beitrags für andere Bildungsnetz-Mitglieder.');
  t('Bitte ordnen Sie hier diesen Beitrag zu einer der Themenfelder zu. Dies erleichtert Ihnen die thematische Ausrichtung und verbessert die Auffindbarkeit Ihres Beitrags für andere Bildungsnetz-Mitglieder.');
  t('Content Rating');
  t('Gruppe');
  t('Hier können Sie auf andere Beiträge verweisen.');
  t('Inhalt');
  t('Kommentar');
  t('Mit Hilfe von Schlagworten können Sie beim schnellen Finden und Einordnung dieses Beitrag helfen. Geben Sie einfach kurze Begriffe durch Kommata getrennt, wie zum Beispiel Lernen, Digitale Medien, Konzept an.');
  t('OG vocabulary');
  t('Publishing date');
  t('Referenz auf Beiträge TF');
  t('Referenz auf Material TF');
  t('Referenzen');
  t('Schlagworte');
  t('Themenfeld(er)');
  t('Veröffentlichung planen');
  t('Vorschaubild');
  t('Während Dein Beitrag als Entwurf gespeichert oder die automatische Veröffentlichung geplant ist, können ihn nur Personen mit <strong>Änderungszugriff</strong> sehen und bearbeiten. Sobald der Veröffentlichungszeitpunkt erreicht ist, verfällt der Entwurfsmodus und alle Personen unter “Lesezugriff” können Deinen Beitrag sehen. Zu diesem Zeitpunkt werden sie auch abhängig von den personalisierten Benachrichtigungseinstellungen dazu benachrichtigt.');
  t('You can optionally set a preview image here. This is then used for a more visually appealing preview of this post on the homepage and overviews. <b>Please no lettering</b>');
  t('collaboration');

  return $field_instances;
}
