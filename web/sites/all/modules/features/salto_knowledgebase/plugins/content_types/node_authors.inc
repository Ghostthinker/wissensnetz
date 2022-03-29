<?php

/**
 * @file
 * Plugin to handle the 'profile2' content type which allows individual profiles
 * to be embedded into a panel.
 */


/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'single' => TRUE,
  'title' => t('Node authors'),
  'description' => t('Action links'),
  'required context' => [
    new ctools_context_required(t('Node'), 'entity:node'),
  ],
  'category' => t('Salto'),
  'defaults' => ['image_style' => 'thumbnail', 'limit' => 5],
];

/**
 * Render the authors of a node
 */
function salto_knowledgebase_node_authors_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!isset($conf['image_style'])) {
    return;
  }

  $node = isset($context[0]->data->nid) ? clone($context[0]->data) : NULL;

  if (empty($node->nid)) {
    return;
  }

  //get node authors
  $authors = salto_knowledgebase_post_get_authors($node);

  //get node_revision authors
  $revision_authors = salto_knowledgebase_post_get_revision_authors($node->nid);


  $rendered_authors = [];
  $rendered_authors_revision = [];
  $style = $conf['image_style'];

  $limit = $conf['limit'] ? $conf['limit'] : 5;

  //normalize limit
  $limit = $limit > 0 ? $limit - 1 : NULL;

  $c = 0;

  //authors array empty -> user deleted
  if (empty($authors)) {
    $name = variable_get('deleted-user', t('deleted user'));
    $rendered_authors[] = [
      'data' => '<div title="' . $name . '">' . theme('user_picture', [
          'account' => ['uid' => USER_DELETED_UID],
          'style' => $style,
        ]) . '</div>',
      'class' => ['node_author'],
      'sortname' => $name,
    ];
  }

  foreach ($authors as $uid) {

    if (!is_null($limit) && $c++ > $limit) {
      $sum = count($authors);
      $rendered_authors[-1] = t('and @num more', ['@num' => $sum - count($rendered_authors)]);
      break;
    }
    $author = user_load($uid);

    $rendered_authors[$author->uid] = [
      'data' => l(theme('user_picture', [
        'account' => $author,
        'style' => $style,
      ]), 'user/' . $author->uid, [
        'html' => TRUE,
        'attributes' => ['title' => format_username($author)],
      ]),
      'class' => ['node_author'],
      'sortname' => $author->realname,
    ];
  }
  //sort by realname
  uasort($rendered_authors, '_salto_knowledgebase_sortByName');


  //revion authors
  $c = 0;

  foreach ($revision_authors as $uid) {

    if (!is_null($limit) && $c > $limit) {
      $sum = count($revision_authors);
      $rendered_authors_revision[-1] = t('and @num more', ['@num' => $sum - count($rendered_authors_revision)]);
      break;
    }

    $author = user_load($uid);

    //skiip authors already rendered in node authors
    if (empty($rendered_authors[$author->uid])) {
      $rendered_authors_revision[$author->uid] = [
        'data' => l(theme('user_picture', [
          'account' => $author,
          'style' => $style,
        ]), 'user/' . $author->uid, [
          'html' => TRUE,
          'attributes' => ['title' => format_username($author)],
        ]),
        'class' => ['node_author_revision'],
        'sortname' => $author->realname,
      ];
      $c++;
    }
  }

  //sort by realname
  uasort($rendered_authors_revision, '_salto_knowledgebase_sortByName');

  $block = new stdClass();
  $block->title = t('Authors and collaboration');

  $out = theme('item_list', [
    'items' => $rendered_authors,
    'attributes' => ["class" => 'node_authors'],
  ]);
  $out .= theme('item_list', [
    'items' => $rendered_authors_revision,
    'attributes' => ["class" => 'revision_authors'],
  ]);

  $block->content = $out;
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_knowledgebase_node_authors_content_type_admin_title($subtype, $conf, $context) {
  return t('Node authors');
}

function salto_knowledgebase_node_authors_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'salto_knowledgebase';
  $block->title = t("Authors of the node");
  $block->content = " ";
  return $block;
}

/**
 * The submit form stores the data in $conf.
 */
function salto_knowledgebase_node_authors_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * The form to add or edit a profile as content.
 */
function salto_knowledgebase_node_authors_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // Select type of profile to display.
  $form['image_style'] = [
    '#type' => 'select',
    '#title' => t('Image preset'),
    '#options' => image_style_options(),
    '#default_value' => $conf['image_style'],
  ];
  $form['limit'] = [
    '#type' => 'textfield',
    '#title' => t('Limit'),
    '#default_value' => $conf['limit'],
  ];
  return $form;
}


function _salto_knowledgebase_sortByName($a, $b) {
  return strcmp($a['sortname'], $b['sortname']);
}
