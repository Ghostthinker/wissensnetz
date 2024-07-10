<?php

/**
 * @file
 * salto_core.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function salto_core_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: editor.
  $profiles['editor'] = array(
    'format' => 'editor',
    'editor' => 'ckeditor',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'JustifyBlock' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Blockquote' => 1,
          'Format' => 1,
          'Table' => 1,
        ),
        'drupal_path' => array(
          'Link' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'theme' => 'advanced',
      'language' => 'de',
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'theme',
      'css_theme' => 'salto2014',
      'css_path' => '',
      'stylesSet' => '',
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'forcePasteAsPlainText' => 0,
      'pasteFromWordPromptCleanup' => 0,
      'pasteFromWordRemoveFontStyles' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => FALSE,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => '4.9.2.95e5d83',
    ),
    'name' => 'formateditor',
  );

  // Exported profile: editor_comment.
  $profiles['editor_comment'] = array(
    'format' => 'editor_comment',
    'editor' => 'ckeditor',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Link' => 1,
          'Unlink' => 1,
        ),
      ),
      'theme' => '',
      'language' => 'de',
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'theme',
      'css_theme' => 'salto2014',
      'css_path' => '',
      'stylesSet' => '',
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'forcePasteAsPlainText' => 0,
      'pasteFromWordPromptCleanup' => 0,
      'pasteFromWordRemoveFontStyles' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => FALSE,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => '4.9.2.95e5d83',
    ),
    'name' => 'formateditor_comment',
  );

  return $profiles;
}
