<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'single' => TRUE,
  'title' => t('Salto Tagcloud'),
  'description' => t('Salto Tagcloud'),
  'category' => t('Salto Widgets'),
  'defaults' => [
    'max_age' => variable_get('salto_tagcloud_max_age', [180]),
    'max_tags' => variable_get('salto_tagcloud_max_tags', [30]),
    'vids' => variable_get('salto_tagcloud_vids', [5]),
  ],
];

/**
 * Render
 */
function salto_tagcloud_salto_tagcloud_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!isset($conf['vids']) || !isset($conf['max_age']) || !isset($conf['max_tags'])) {
    return;
  }

  $block = new stdClass();
  $block->content = theme('salto_tagcloud', [
    'variables' => [
      'max_age' => $conf['max_age'],
      'max_tags' => $conf['max_tags'],
      'vids' => $conf['vids'],
    ],
  ]);
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_tagcloud_salto_tagcloud_content_type_admin_title($subtype, $conf, $context) {
  return t('Salto Tagcloud');
}

function salto_tagcloud_salto_tagcloud_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'salto_tagcloud';
  $block->title = t("Custom settings");

  $block->content = t("Show !max_tags tags of vid !vids and max ages !max_age", [
    '!max_tags' => $conf['max_tags'],
    '!vids' => $conf['vids'],
    '!max_age' => $conf['max_age'],
  ]);
  return $block;
}

/**
 * The submit form stores the data in $conf.
 */
function salto_tagcloud_salto_tagcloud_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * The form to add/edit a tagcloud
 */
function salto_tagcloud_salto_tagcloud_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['vids'] = [
    '#type' => 'textfield',
    '#title' => t('Vocabulary id(s)'),
    '#default_value' => $conf['vids'],
    '#description' => t('Vocabulary id(s) you would like to display - separated by commas (,).'),
  ];

  $form['max_tags'] = [
    '#type' => 'textfield',
    '#title' => t('Number of tags'),
    '#default_value' => $conf['max_tags'],
    '#description' => t('Number of tags that should be displayed.'),
  ];

  $form['max_age'] = [
    '#type' => 'textfield',
    '#title' => t('Max age of the content.'),
    '#default_value' => $conf['max_age'],
    '#description' => t('Max age (in days) of the content that should be investigated.'),
  ];

  return $form;
}

