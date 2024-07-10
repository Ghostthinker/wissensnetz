<?php

/**
 * @file
 * template.php
 */

use salto_core\service\SettingsService;
use Wissensnetz\Core\File\DrupalFile;
use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\Group\GroupDrupalNode;

/**
 * Implements hook_theme().
 */
function salto2014_theme($existing, $type, $theme, $path) {
  return [
    'node_form' => [
      'render element' => 'form',
      'template' => 'templates/forms/node-form',
    ],
    'file_entity_edit' => [
      'render element' => 'form',
      'template' => 'templates/forms/file-form',
    ],
    'onsite_notification_settings_form' => [
      'template' => 'templates/forms/notification-settings-form',
      'render element' => 'form',
    ],
    'toolbar' => [
      'template' => 'templates/md/toolbar',
      'render element' => 'elements',
    ],
    'accordion' => [
      'template' => 'templates/md/accordion',
      'render element' => 'elements',
    ],
    'file_attachment' => [
      'template' => 'templates/md/file-attachment',
      'render element' => 'elements',
    ],
    'modal_dialog_textarea' => [
      'template' => 'templates/md/modal-dialog-textarea',
      'render element' => 'elements',
      'variables' => ['modal' => NULL],
    ],
  ];
}

/**
 * @param $variables
 *
 * @return string
 */
function salto2014_checkboxes($variables) {
  $element = $variables['element'];
  $attributes = [];
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }

  if (!empty($element['#tooltips'])) {
    $element['#children'] = _salto2014_render_checkbox_with_tooltips($element);
    return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
  }

  else {
    return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
  }
}

/**
 * @param $element
 *
 * @return string
 */
function _salto2014_render_checkbox_with_tooltips($element) {
  $output = '';
  foreach ($element['#options'] as $key => $value) {
    $output .= '<span rel="tooltip" title="' . $element['#tooltips'][$key] . '">';
    $output .= render($element[$key]);
    $output .= '</span>';
  }
  return $output;
}


/**
 * Implements hook_preprocess_html().
 */
function salto2014_preprocess_html(&$variables) {
  global $conf;

  switch (theme_get_setting('bootstrap_navbar_position')) {
    case 'fixed-top':
      $variables['classes_array'][] = 'navbar-is-fixed-top';
      break;

    case 'fixed-bottom':
      $variables['classes_array'][] = 'navbar-is-fixed-bottom';
      break;

    case 'static-top':
      $variables['classes_array'][] = 'navbar-is-static-top';
      break;
  }

  $variables['attributes_array']['data-grid-color'] = 'red';
  $variables['attributes_array']['data-grid-framework'] = 'b3';
  $variables['attributes_array']['data-grid-opacity'] = '0.1';
  $variables['attributes_array']['data-grid-gutterwidth'] = '20px';

  // favicon handling
  if (!empty($conf['wn_blanko']['favicons_png'])) {
    $variables['wn_blanko'] = TRUE;

    $variables['favicons_png'] = [];
    $variables['favicons_png']['32x32'] = $conf['wn_blanko']['favicons_png']['32x32'] ?? NULL;
    $variables['favicons_png']['192x192'] = $conf['wn_blanko']['favicons_png']['192x192'] ?? NULL;
    $variables['favicons_png']['180x180'] = $conf['wn_blanko']['favicons_png']['180x180'] ?? NULL;
  }


  if (module_exists('salto_keycloak')) {
    if (salto_user_global_header_enabled() && salto_keycloak_get_access_token()) {
      $variables['classes_array'][] = 'has-global-header';
    }
  }
}

function salto2014_html_head_alter(&$head_elements) {
  global $conf;

  if (!module_exists('wn_blanko') || empty($conf['wn_blanko']['favicon'])) {
    return;
  }

  // Search the head elements for the Favicon
  foreach ($head_elements as $key => $element) {
    if (!empty($element['#attributes'])) {
      if (array_key_exists('href', $element['#attributes'])) {
        if (strpos($element['#attributes']['href'], 'salto2014/favicon.ico') > 0 || strpos($element['#attributes']['href'], 'misc/favicon.ico') > 0) {
          // Change the URL
          $head_elements[$key]['#attributes']['href'] = $conf['wn_blanko']['favicon'];
        }
      }
    }
  }
}

/**
 * Implementation of hook_preprocess_HOOK().
 */
function salto2014_preprocess_comment(&$variables) {

  $author = user_load($variables['comment']->uid);
  $variables['picture'] = theme('user_picture', [
    'account' => $author,
    'style' => 'user_60x60',
  ]);
  $variables['submitted'] = str_replace("Submitted by", "", $variables['submitted']);
}

/**
 *
 *
 * @param type $variables
 *
 * @return type
 */
function salto2014_image_style($variables) {
  global $user;

  $orig_path = $variables['path'];

  $output = '';

  $dimensions = [
    'width' => $variables['width'],
    'height' => $variables['height'],
  ];

  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];

  $variables['path'] = image_style_url($variables['style_name'], $variables['path']);
  $output .= theme('image', $variables);

  if ($user->uid > 0) {
    if ((strstr($variables['style_name'], 'user_') || strstr($variables['style_name'], 'activity_avatar')) && !strstr($orig_path, 'default://')) {
      $uid = $variables['alt'];
      if (is_numeric($uid) && $uid != USER_DELETED_UID) {
        $online_status = salto_user_get_online_status($uid);
        switch ($online_status) {
          case SALTO_USER_STATUS_ONLINE:
            $output .= '<div class="salto-user-online-status online" title="' . t('Online') . '"></div>';
            break;
          case SALTO_USER_STATUS_AWAY:
            $output .= '<div class="salto-user-online-status away" title="' . t('Away') . '"></div>';
            break;
          default:
            $output .= '<div class="salto-user-online-status offline" title="' . t('Offline') . '"></div>';
        }
      }
    }
  }

  return $output;
}

/**
 * Implements hook_preprocess_user_picture().
 *
 * @see template_preprocess_user_picture().
 */
function salto2014_preprocess_user_picture(&$variables) {

  $variables['user_picture'] = '';
  if (variable_get('user_pictures', 0)) {
    $account = $variables['account'];
    if (!empty($account->picture)) {
      if (is_numeric($account->picture)) {
        $account->picture = file_load($account->picture);
      }
      if (!empty($account->picture->uri)) {
        $filepath = $account->picture->uri;
      }
    }
    elseif (variable_get('user_picture_default', '')) {
      $filepath = variable_get('user_picture_default', '');
    }
    if (isset($filepath)) {
      $alt = t("@user's picture", ['@user' => format_username($account)]);

      if (module_exists('image') && file_valid_uri($filepath)) {

        $style = isset($variables['style']) ? $variables['style'] : $style = variable_get('user_picture_style', 'user_100x100');

        $variables['user_picture'] = theme('image_style', [
          'style_name' => $style,
          'path' => $filepath,
          'alt' => $alt,
          'title' => $alt,
          'classes_array' => [],
        ]);
      }
      else {
        $variables['user_picture'] = theme('image', [
          'path' => $filepath,
          'alt' => $alt,
          'title' => $alt,
          'classes_array' => [],
        ]);
      }
      if (!empty($account->uid) && user_access('access user profiles')) {
        $attributes = [
          'attributes' => ['title' => t('View user profile.')],
          'html' => TRUE,
        ];
        $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
      }
    }
  }
  else {
    $account = $variables['account'];
    $profile = profile2_load_by_user($account, 'main');
    $style = isset($variables['style']) ? $variables['style'] : $style = variable_get('user_picture_style', 'user_100x100');

    $user_pic = "";
    if (isset($profile->field_user_picture)) {
      $field_view = field_view_field('profile2', $profile, 'field_user_picture', ['settings' => ['image_style' => $style]]);
      $field_view['#label_display'] = 'hidden';
      $user_pic = drupal_render($field_view);
    }
    else {

      $field = field_info_field('field_user_picture');
      $default_image_fid = $field['settings']['default_image'];
      $image_file = file_load($default_image_fid);
      $image_uri = $image_file->uri;

      $variables = [
        'style_name' => $style,
        'path' => $image_uri,
        'classes_array' => [],
      ];
      $user_pic = theme('image_style', $variables);
    }

    if (!empty($account->uid) && user_access('access user profiles')) {
      $attributes = [
        'attributes' => ['title' => t('View user profile.')],
        'html' => TRUE,
      ];
      $user_pic = l($user_pic, "user/{$account->uid}", $attributes);
    }
    else {
      $field = field_info_field('field_user_picture');
      $default_image_fid = $field['settings']['default_image'];
      $image_file = file_load($default_image_fid);
      $image_uri = $image_file->uri;

      $variables = [
        'style_name' => $style,
        'path' => $image_uri,
        'classes_array' => [],
      ];
      $user_pic = theme('image_style', $variables);
    }
    $variables['user_picture'] = $user_pic;
  }
}

/**
 * @param array $variables [description]
 * @return [type]            [description]
 */
function salto2014_menu_link__user_menu(array $variables) {

  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#title'] == '_name_') {
    $fullname = salto_user_get_fullname();
    $html = '<li class="wrapper username">
              <h2>' . $fullname . '</h2>
             </li>';
    return $html . '<li class="divider"></li>';
  }

  if ($element['#title'] == '_seperator_') {
    return '<li class="divider"></li>';
  }

  if ($element['#href'] == 'notifications') {
    global $user;
    $sub_menu = '<ul class="dropdown-menu">
       <li >
         <span class="notifications-all pull-left-not">
          ' . l(t('All notifications'), 'notifications/all') . '
         </span>
          <span class="notifications-settings pull-right-not">' . l('<i class="icon-cog aria-hidden="true"></i>' . t('Settings'), 'notifications/settings', ['html' => TRUE]) . '
         </span>
       </li>
       <li class="divider"></li>
       <li class="notifications-content"><a href=""><i class="icon glyphicon glyphicon-refresh glyphicon-spin" aria-hidden="true"></i></a></li>
       <li class="divider"></li>
       <li class="notifications-actions">' . l(t('Mark all as read'), 'notifications/js/markasread/' . $user->uid, ['query' => ["token" => drupal_get_token()]]) . '</li>
    </ul>';

    $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
    $element['#localized_options']['attributes']['class'][] = 'notifications-dropdown-link';
    $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    $element['#attributes']['class'][] = 'dropdown';
    $element['#attributes']['class'][] = 'notifications-dropdown';

    $element['#title'] = '<span class="text">' . $element['#title'] . '</span>';
    $output = l($element['#title'], $element['#href'], $element['#localized_options'] + ['html' => TRUE]);

    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . '</li>';
  }

  if ($element['#below']) {

    // Prevent dropdown functions from being added to management menu as to not affect navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    else {
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

      if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
        $element['#attributes']['class'][] = 'dropdown-submenu';
      }
      else {
        $element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;
        $element['#title'] .= ' <span class="caret"></span>';
      }

      $element['#localized_options']['attributes']['data-target'] = '#';
    }
  }

  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']) || $element['#localized_options']['language']->language == $language_url->language)) {
    $element['#attributes']['class'][] = 'active';
  }

  $attributes['attributes']['class'] = '';
  $start = stripos($element['#href'], '/');
  if ($start > 0) {
    $class = substr($element['#href'], $start + 1);
    $class = str_replace('/', '-', $class);
    $attributes['attributes']['class'] = $class;
  }

  $user = salto_user_get_current();
  $hasMembershipRequestAccess = user_has_role(ROLE_GLOBAL_ADMIN_RID, $user) || user_has_role(ROLE_GLOBAL_GARDENER_RID, $user);
  if ($hasMembershipRequestAccess) {
    if (!$element['#below'] && stripos(implode(', ', $element['#attributes']['class']), 'last') !== FALSE) {
      $title = '<span class="text">' . t('Membership requests') . '</span>';
      $html = '<li class="leaf">' . l($title, 'user/membership-requests',
          $element['#localized_options'] + ['html' => TRUE] + $attributes) . '</li>';
      $html .= '<li class="divider"></li>';
      $element['#title'] = '<span class="text">' . $element['#title'] . '</span>';
      $output = l($element['#title'], $element['#href'],
        $element['#localized_options'] + ['html' => TRUE] + $attributes);
      return $html . '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
    }
  }

  $element['#title'] = '<span class="text">' . $element['#title'] . '</span>';
  $output = l($element['#title'], $element['#href'], $element['#localized_options'] + ['html' => TRUE] + $attributes);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function salto2014_menu_link__main_menu(array $variables) {
  $element = $variables['element'];
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $sub_menu = '';
  if ($element['#href'] === 'materials' || $element['#href'] === 'posts') {
    $tree = menu_tree_all_data('main-menu', $element['#original_link']);
    $menu = menu_tree_output($tree);
    $sub_menu = drupal_render($menu[$element['#original_link']['mlid']]['#below']);
    $element['#attributes']['class'][] = 'collapsed collapse';
    $element['#localized_options']['html'] = TRUE;
    $output = l($element['#title'], $element['#href'], $element['#localized_options'] + ['html' => TRUE]);
    $output = '<span class="wrapper flex-align-center">' . $output . '<span class="arrow"></span></span>';
    drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/collapse.js');
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function salto2014_menu_tree__menu_suche($variables) {
  $wrapper = $variables['#tree']['#theme_wrappers']['0'];
  $classes = implode(";", $wrapper);
  if (stripos($classes, 'menu_suche_2') !== FALSE) {
    return '<ul class="menu nav nav-pills nav-fill">' . $variables['tree'] . '</ul>';
  }
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

/**
 * Just for testing uses bootstrap itemlist
 *
 * @param  [type] $variables [description]
 *
 * @return [type]            [description]
 */
function salto2014_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    //find the active tab
    foreach ($variables['primary'] as $tab) {
      if ($tab['#active'] == TRUE) {
        break;
      }
    }
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Actions') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="list-group">';
    $variables['primary']['#suffix'] = '</ul></div>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Overrides theme_menu_local_task().
 */
function salto2014_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];
  $classes = [];
  $classes[] = 'list-group-item';

  if (!empty($variables['element']['#active'])) {
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', [
      '!local-task-title' => $link['title'],
      '!active' => $active,
    ]);

    $classes[] = 'active';
  }

  return '<li class="' . implode(' ', $classes) . '">' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/**
 * Overrides theme_menu_link().
 */
function salto2014_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#href'] == 'licenses') {
    if (!user_access("access license section")) {
      $element['#attributes']['class'][] = 'locked';
    }
  }

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
    if (in_array('menu_link__menu_knowledgebase_files_cats', $element['#theme']) ||
      in_array('menu_link__menu_knowledgebase', $element['#theme'])
    ) {
      $collapse = TRUE;

      $children = array_intersect_key($element['#below'], array_flip(element_children($element['#below'])));
      if (in_array('active-trail', $element['#attributes']['class'])) {
        $collapse = FALSE;
      }

      if ($collapse) {
        $element['#attributes']['class'][0] = 'collapsed';
      }
    }
  }

  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }

  $element['query'] = isset($element['#original_link']['query']) ? $element['#original_link']['query'] : NULL;
  $output = l($element['#title'], $element['#href'], $element['#localized_options'] + ['query' => $element['query']]);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function _salto2014_file($variables) {

  $element = $variables['element'];
  $element['#attributes']['type'] = 'file';
  element_set_attributes($element, ['id', 'name', 'size']);
  _form_set_class($element, ['form-file']);

  $input = '<input' . drupal_attributes($element['#attributes']) . ' />';
  return '<div class="file-upload"><img src="/sites/all/files/defaults/user.jpg">' . $input . '</div>';
}

/**
 * The only way I could archived to add a class to both node and file form :(
 *
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function salto2014_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'file_entity_edit' || !empty($form['#node_edit_form'])) {

    $form['#attributes']['class'] = ['content-form'];
  }
}

function salto2014_form_privatemsg_list_alter($form, &$form_state) {
  drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/action.read.js', ['scope' => 'footer']);
}

/**
 * Preprocessor for theme('article_node_form').
 */
function salto2014_preprocess_file_entity_edit(&$variables) {

  $variables['sidebar_content'] = '';
  $variables['sidebar_content'] .= '<div class="node-buttons">' . render($variables['form']['actions']) . '</div>';

  if (!empty($variables['form']['field_post_collaboration']) || !empty($variables['form']['field_post_authors'])) {
    $collaboration_wrapper = '<div class="collaboration-wrapper form-wrapper form-group">';
    $collaboration_wrapper .= '<label class="">' . t('Collaboration') . '</label>';

    if (!empty($variables['form']['field_post_collaboration']) && $variables['form']['field_post_collaboration']['#access']) {
      $collaboration_wrapper .= render($variables['form']['field_post_collaboration']);
    }

    if (!empty($variables['form']['field_post_authors']) && $variables['form']['field_post_authors']['#access']) {
      $collaboration_wrapper .= render($variables['form']['field_post_authors']);
    }

    $collaboration_wrapper .= '</div>';

    $variables['sidebar_content'] .= $collaboration_wrapper;

  }
  $variables['main_content'] = drupal_render_children($variables['form']);
}

function salto2014_form_element($variables) {
  $isCheckbox = $variables['element']['#type'] === 'checkbox';
  $isNotVBO = TRUE;
  if (!empty($variables['element']['#attributes']['class'])) {
    $classes = implode(";", $variables['element']['#attributes']['class']);
    $isNotVBO = stripos($classes, 'vbo') === FALSE;
  }
  if ($isCheckbox && $isNotVBO) {
    $variables['element']['#title_display'] = 'before';
    $variables['element']['#wrapper_attributes']['class'][] = 'checkbox-mark';
    $variables['element']['#label_attributes']['class'][] = 'container';
    $checkMark = '<span class="checkmark"></span>';

    if (stripos($variables['element']['#id'], 'field-taxonomy-post-tags') !== FALSE) {
      $variables['element']['#label_attributes']['class'][] = 'chip';
      $checkMark = '<span class="checkmark check"></span>';
    }

    $variables['element']['#children'] .= $checkMark;
  }
  return bootstrap_form_element($variables);
}

/**
 * Preprocessor for theme('article_node_form').
 */
function salto2014_preprocess_node_form(&$variables) {

  $drupalUser = \Wissensnetz\User\DrupalUser::current();

  $variables['form']['#attributes']['class'][] = 'content-form';
  $variables['sidebar_content'] = '';
  $variables['sidebar_content'] .= '<div class="node-buttons">' . render($variables['form']['actions']) . '</div>';

  if (!empty($variables['form']['salto_notification'])) {
    $variables['accordion']['access'] = TRUE;
    $variables['accordion']['title'] = t('Benachrichtigung');
    $variables['accordion']['content'] = render($variables['form']['salto_notification']);
    $variables['content']['side']['accordions'][] = theme('accordion', $variables);
  }

  if (!empty($variables['form']['field_post_collaboration']) && !empty($variables['form']['field_post_authors'])) {
    if ($variables['form']['field_post_collaboration']['#access'] && $variables['form']['field_post_authors']['#access']) {
      $variables['accordion']['access'] = TRUE;
      $variables['accordion']['label'] = TRUE;
      $variables['accordion']['title'] = t('Collaboration');
      $variables['accordion']['content'] = render($variables['form']['field_post_collaboration']);
      $variables['accordion']['content'] .= render($variables['form']['field_post_authors']);
      $variables['content']['side']['accordions'][] = theme('accordion', $variables);
    }
  }


  if($variables['form']['#form_id'] == 'post_node_form' && SettingsService::assignGroupsRetrospectivelyEnabled() && $drupalUser->isCommunityManager()){
    unset($variables['form']['field_og_group'][LANGUAGE_NONE][0]['default']['#options']);
    $groups = GroupDrupalNode::getNidAndTitleFromAllGroups();
    $variables['form']['field_og_group'][LANGUAGE_NONE][0]['default']['#options'] = ['_none' => t('- None -')] + $groups;
    drupal_add_js(drupal_get_path('module', 'salto_group') . "/js/salto_group.js");
  }

  if (!empty($variables['form']['field_og_group']) && empty($variables['form']['field_share_with'])) {
    $variables['accordion']['access'] = TRUE;
    $variables['accordion']['label'] = TRUE;
    $variables['accordion']['title'] = $variables['form']['field_og_group'][LANGUAGE_NONE][0]['#title'];
    $variables['accordion']['content'] = render($variables['form']['field_og_group']);
    $variables['content']['side']['accordions'][] = theme('accordion', $variables);
  }

  if (!empty($variables['form']['field_share_with']) && !empty($variables['form']['field_share_with'])) {
    if ($variables['form']['field_share_with']['#access'] && $variables['form']['field_share_with']['#access']) {

      $variables['form']['field_og_group']['#title'] = '';
      $variables['form']['field_og_group'][LANGUAGE_NONE][0]['#title'] = '';

      $variables['accordion']['access'] = TRUE;
      $variables['accordion']['label'] = TRUE;
      $variables['accordion']['title'] = t('Share with');
      $variables['accordion']['content'] = render($variables['form']['field_og_group']);
      $variables['accordion']['content'] .= render($variables['form']['field_share_with']);
      $variables['content']['side']['accordions'][] = theme('accordion', $variables);
    }
  }

  $main_bottom = '';

  $variables['accordions'] = '';
  $excludes = [
    'field_share_with',
    'field_og_group',
    'field_post_collaboration',
    'field_post_authors',
    'field_content_rating',
    'field_post_attachment',
  ];
  $includes = [
    'field_kb_content_category',
    'field_post_tags',
    'field_references',
    'field_org_lsb_inspection',
    'field_organisation_earemotes',
    'field_organisation_obscure',
    'field_org_dv_license_settings',
    'field_group_categories',
    'group_info',
    'group_join_mode',
    'group_default_access_options',
  ];

  if ($variables['form']['field_publishing_options']['#prefix'] !== '<div style="display:none">'){
    $includes[] =  'field_publishing_options';
  }

  $withLabel = ['group_info', 'group_default_access_options'];
  foreach ($variables['form'] as $key => $item) {
    if (in_array($key, $includes) === FALSE) {
      continue;
    }

    $elements = $variables['form'][$key];
    if (empty($elements) || (isset($elements['#access']) && !$elements['#access'])) {
      continue;
    }
    $isRequire = FALSE;
    if (!empty($elements['#attributes']['class'])) {
      $classes = implode(";", $elements['#attributes']['class']);
      $isRequire = stripos($classes, 'require') !== FALSE;
    }
    $required = $elements[LANGUAGE_NONE]['#required'] !== NULL ? $elements[LANGUAGE_NONE]['#required'] : $isRequire;

    $accordion = '<div class="accordion-container label-hide">';
    if (in_array($key, $withLabel) === TRUE) {
      $accordion = '<div class="accordion-container">';
    }
    $accordion .= '<button type="button" class="accordion-button">';
    $title = $elements[LANGUAGE_NONE]['#title'] !== NULL ? $elements[LANGUAGE_NONE]['#title'] : $elements['#title'];
    $accordion .= '<label class="control-label">' . render($title);
    $accordion .= $required ? '<span class="form-required" title="Diese Angabe wird benötigt.">*</span>' : '';
    $accordion .= '</label></button><div class="accordion-panel">';
    $accordion .= render($variables['form'][$key]);
    $accordion .= '</div></div>';

    $variables['accordions'] .= $accordion;
  }

  if ($variables['form']['body']) {
    $variables['accordion']['access'] = TRUE;
    $variables['accordion']['label'] = TRUE;
    $variables['accordion']['resize'] = TRUE;
    $variables['accordion']['title'] = $variables['form']['body'][LANGUAGE_NONE]['#title'];
    $variables['accordion']['content'] = drupal_render($variables['form']['body']);
    $variables['body'] = theme('accordion', $variables);
  }

  $variables['form']['field_teaser_image']['#access'] = FALSE;
  if ($variables['form']['field_teaser_image'] && SettingsService::postTeaserImageEnabled()) {
    $variables['form']['field_teaser_image']['#access'] = TRUE;
    $variables['accordion']['access'] = TRUE;
    $variables['accordion']['label'] = TRUE;
    $variables['accordion']['resize'] = TRUE;
    $variables['accordion']['title'] = t('Teaser image');
    $variables['form']['field_teaser_image'][LANGUAGE_NONE][0]['#description'] = t('You can set an optional preview image here. This is used for a visually appealing post preview on the start page and in the overviews. <b>Please do not use lettering!</b>');
    $variables['accordion']['content'] = drupal_render($variables['form']['field_teaser_image']);
    $variables['teaser_image'] = theme('accordion', $variables);
  }
  if ($variables['form']['field_post_attachment']) {
    $variables['accordion']['access'] = TRUE;
    $variables['accordion']['label'] = TRUE;
    $variables['accordion']['resize'] = TRUE;
    $variables['accordion']['title'] = t('Attachment');
    $variables['accordion']['content'] = drupal_render($variables['form']['field_post_attachment']);
    $variables['attachment'] = theme('accordion', $variables);
  }

  $variables['main_content'] = drupal_render_children($variables['form']);
  $variables['main_content'] .= $main_bottom;

  $toolbar = _salto2014_preprocess_node_form_toolbar($variables);
  $variables['content']['toolbar'] = theme('toolbar', $toolbar);

  $variables['floating_button']['is-submit'] = TRUE;
  $variables['floating_button']['links'] = [];
  $variables['floating_button']['links'][] = [
    'icon' => 'save',
    'title' => t('Save'),
  ];
  $variables['content']['floating_button'] = salto2014_floating_button($variables);

  drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/accordion.js', ['scope' => 'footer']);
  drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/chips.js', ['scope' => 'footer']);
}

function _salto2014_preprocess_node_form_toolbar(&$variables) {
  $title = $variables['form']['#node']->nid ? $variables['form']['#node']->title : drupal_get_title();
  $variables['toolbar']['title'] = $title;

  $variables['toolbar']['back'] = '#';
  $variables['toolbar']['back_onclick'] = 'javascript:window.history.back()';

  if ($variables['form']['#node']->nid) {
    $variables['toolbar']['action_links'][] = [
      'icon' => 'trash-alt',
      'target' => '/node/' . $variables['form']['#node']->nid . '/delete?destination=node/' . $variables['form']['#node']->nid . '/edit',
      'text' => t('Delete'),
      'title' => t('Delete'),
      'class' => 'btn btn-danger form-submit icon-before node-edit-protection-processed',
    ];
  }
  return $variables;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function salto2014_preprocess_onsite_notification_settings_form(&$variables) {

  unset($variables['form']['#theme']);

  menu_set_active_item('notifications/settings');

  $types = onsite_notification_get_notification_types();

  $form = &$variables['form'];

  $main_content = '';

  $main_content .= '<div class="row header">';
  $main_content .= '  <div class="col-md-6" ><b>' . t('Notification event') . '</b></div>';
  $main_content .= '  <div class="col-md-3"  rel="tooltip" title="' . t('Receive notifications for this event.') . '" ><b>' . t('Notification') . '</b></div>';
  $main_content .= '  <div class="col-md-3" rel="tooltip" title="' . t('Send a mail for this notification.') . '"><b>' . t('Email') . '</b></div>';

  $main_content .= '</div>';

  foreach ($types as $type) {
    if (isset($form[$type->name])) {
      unset($form[$type->name]['status']['#title']);
      unset($form[$type->name]['onsite']['#title']);
      unset($form[$type->name]['mail']['#title']);
      $main_content .= '<div class="row notification-settings-row">';
      $main_content .= '  <div class="col-md-6">' . t($form[$type->name]['#title']) . '</div>';
      $main_content .= '  <div class="col-md-3 status" >' . render($variables['form'][$type->name]['status']) . '</div>';
      $main_content .= '  <div class="col-md-3 mail" >' . render($variables['form'][$type->name]['mail']) . '</div>';

      $main_content .= '</div>';
      unset($form[$type->name]);
    }
  }

  $variables['sidebar_right'] = '';
  $variables['sidebar_right'] .= '<div class="pane-action-links">' . render($variables['form']['submit']) . '</div>';

  $variables['main_content'] = $main_content;
  $variables['secondary_content'] = drupal_render_children($variables['form']);

  $menu = menu_tree('onsite_notifications');

  $menuhtml = drupal_render($menu);
  $variables['sidebar_left'] = '<div class="menu-block-wrapper">' . $menuhtml . '</div>';

  $variables['modals']['toc']['html'] = '
    <div class="panel-panel col-md-3">
      <div class="inside">' . $variables['sidebar_left'] . '</div>
    </div>';
  salto_core_preprocess_salto_363($variables);
}

/**
 * Returns HTML for a group of media widgets.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the widgets.
 *
 * @ingroup themeable
 */
function salto2014_media_widget_multiple($variables) {
  $element = $variables['element'];

  $weight_class = $element['#id'] . '-weight';
  $table_id = $element['#id'] . '-table';

  $headers = [];
  $headers[] = t('File information');
  if ($element['#display_field']) {
    $headers[] = [
      'data' => t('Display'),
      'class' => ['checkbox'],
    ];
  }
  $headers[] = t('Weight');
  $headers[] = t('Operations');

  $widgets = [];
  foreach (element_children($element) as $key) {
    $widgets[] = &$element[$key];
  }
  usort($widgets, '_field_sort_items_value_helper');

  $rows = [];
  foreach ($widgets as $key => &$widget) {
    if ($widget['#file'] == FALSE) {
      $widget['#title'] = '';
      $widget['#description'] = $element['#file_upload_description'];
      continue;
    }

    $operations_elements = [];
    foreach (element_children($widget) as $sub_key) {
      if (isset($widget[$sub_key]['#type']) && $widget[$sub_key]['#type'] == 'submit') {
        hide($widget[$sub_key]);
        $operations_elements[] = &$widget[$sub_key];
      }
    }

    if ($element['#display_field']) {
      hide($widget['display']);
    }
    hide($widget['_weight']);

    $widget['#theme_wrappers'] = [];
    $information = drupal_render($widget);

    $operations = '';
    foreach ($operations_elements as $operation_element) {
      $operations .= render($operation_element);
    }
    $display = '';
    if ($element['#display_field']) {
      unset($widget['display']['#title']);
      $display = [
        'data' => render($widget['display']),
        'class' => ['checkbox'],
      ];
    }
    $widget['_weight']['#attributes']['class'] = [$weight_class];
    $weight = render($widget['_weight']);

    $row = [];
    $row[] = $information;
    if ($element['#display_field']) {
      $row[] = $display;
    }
    $row[] = $weight;
    $row[] = $operations;
    $rows[] = [
      'data' => $row,
      'class' => isset($widget['#attributes']['class']) ? array_merge($widget['#attributes']['class'], ['draggable']) : ['draggable'],
    ];
  }

  drupal_add_tabledrag($table_id, 'order', 'sibling', $weight_class);

  $output = empty($rows) ? '' : theme('table', [
    'header' => $headers,
    'rows' => $rows,
    'attributes' => ['id' => $table_id],
  ]);

  $element[0]['browse_button']['#title'] = t('Browse or upload files');
  $output .= drupal_render_children($element);

  return $output;
}

/**
 * Implementation of hook_preprocess_HOOK().
 */
function salto2014_preprocess_node(&$variables) {
  $node = $variables['node'];

  if ($variables['view_mode'] == 'full' || $variables['view_mode'] == 'teaser') {
    $variables['submit_date'] = $variables['date'];
  }

  if ($variables['view_mode'] == 'shared_post') {
    unset($variables['user_picture']);
    unset($variables['submitted']);

    $read_more = '<div class="node-readmore">' . l('Weiterlesen', 'node/' . $variables['nid']) . '</div>';

    $variables['content']['read_more'] = [
      '#markup' => $read_more,
      '#weight' => 99,
    ];
  }

  if (!empty($variables['field_post_collaboration'][LANGUAGE_NONE][0]['read'])) {

    $classes = ["title-access"];

    if ($variables['field_post_collaboration'][LANGUAGE_NONE][0]['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC) {

      $classes[] = "title-access-public";
      $tooltip = t('Public - Everybody can see it.');
    }

    if ($variables['field_post_collaboration'][LANGUAGE_NONE][0]['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL) {
      $classes[] = "title-access-all";
      $tooltip = t('All members - Only members of the site can see it.');
    }

    if ($variables['field_post_collaboration'][LANGUAGE_NONE][0]['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION) {
      $classes[] = "title-access-organisation";
      $tooltip = t('Organisation - ....');
    }

    if ($variables['field_post_collaboration'][LANGUAGE_NONE][0]['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS) {
      $classes[] = "title-access-author";
      $tooltip = t('Authors - ....');
    }

    if ($variables['field_post_collaboration'][LANGUAGE_NONE][0]['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP) {
      $classes[] = "title-access-group";
      $group = !empty($node->field_og_group[LANGUAGE_NONE][0]['target_id']) ? node_load($node->field_og_group[LANGUAGE_NONE][0]['target_id']) : NULL;
      $group_title = !empty($group) ? $group->title : '-';
      $tooltip = t("Group - only group members of group '!group_name' may see this node.",
        ['!group_name' => htmlspecialchars($group_title, ENT_QUOTES, 'UTF-8')]);
    }

    $variables['title_prefix'] = '<span class="' . implode(" ", $classes) . '" rel="tooltip" title="' . $tooltip . '"></span>';

  }

  unset($variables['content']['flag_notification_ignore_post']);
  unset($variables['content']['flag_notification_subscribe_node']);

  uasort($variables['content']['links'], 'element_sort');

  if (empty($variables['title'])) {
    $variables['title'] = drupal_get_title();
  }

  drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/accordion.js', ['scope' => 'footer']);

  if($variables['node']->type == 'post') {

    $variables['reactions_enabled'] = true;

    $RS = new ReactionService();
    $votes = $RS->getReactionsCount($variables['node']->nid, 'node');
    if(!empty($votes)) {
      $variables['reactionsSerialized'] = json_encode($votes);
    }else {
      $variables['reactionsSerialized'] = "";
    }

    $drupalNode = DrupalNode::make($node);
    $variables['preview_image'] = $drupalNode->getPreviewImageUrl();
    $variables['num_views'] = format_plural($drupalNode->getNumViews(), '1 read', '@count reads');
    $variables['num_comments'] = format_plural($drupalNode->getNumComments(), '1 comment', '@count comments');
    $variables['nid'] = $drupalNode->getNid();

  }
}


/**
 * Implementation of hook_preprocess_HOOK().
 */
function salto2014_preprocess_file_entity(&$variables) {

  $settings = SettingsService::getThemenfelderAsCard();
  $drupalFile = \Wissensnetz\Core\File\DrupalFile::make($variables['fid']);
  $drupalNode = $drupalFile->getCommentNode();
  $variables['material_cards'] = $settings['enabled'];

  $variables['icon'] = $drupalFile->getFileIcon();
  $variables['title'] = $drupalFile->getTitle();
  $variables['link'] = $drupalFile->getFileUrl();
  $variables['download_link'] = $drupalFile->isWebresource() ? $drupalFile->getExternalWebresourceUrl() : $drupalFile->getDownloadUrl();
  $variables['downloadIcon'] = $drupalFile->isWebresource() ? url('/sites/all/static_files/extern.svg', ['absolute' => TRUE]) : url('/sites/all/static_files/download.svg', ['absolute' => TRUE]);
  $previewImage = $drupalFile->getMediaDerivativeImage();
  $variables['preview_image'] = $previewImage;
  $variables['preview_image_class'] = 'preview-image';
  $variables['statistics'] = [
    'num_views' => $drupalFile->getNumViews() ?? 0,
    'num_comments' => $drupalNode->getNumComments() ?? 0,
  ];

  $variables['content']['submit_date'] = $variables['date'];

  $alter['max_length'] = 400;
  $alter['word_boundary'] = TRUE;
  $alter['ellipsis'] = TRUE;
  $alter['html'] = TRUE;

  $description = views_trim_text($alter, $variables['field_file_description'][0]['safe_value']);
  $variables['content']['description'] = $description;

  unset($variables['content']['flag_notification_ignore_material']);
  unset($variables['content']['flag_notification_subscribe_material']);

  $field_post_collaboration_ref = NULL;
  if (!empty($variables['field_post_collaboration'])) {
    if (!empty($variables['field_post_collaboration'][LANGUAGE_NONE][0])) {
      $field_post_collaboration_ref = &$variables['field_post_collaboration'][LANGUAGE_NONE][0];
    }
    else {
      if (!empty($variables['field_post_collaboration'][0])) {
        $field_post_collaboration_ref = &$variables['field_post_collaboration'][0];
      }
    }
  }

  $file = $variables['file'];
  $read = $field_post_collaboration_ref['read'];

  if ($read_write = salto_files_check_collaboration_override($file)) {
    $read = $read_write['read'];
  }
  if (!empty($field_post_collaboration_ref)) {

    $classes = ["title-access"];

    if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC) {

      $classes[] = "title-access-public";
      $tooltip = t('Public - Everybody can see this file.');
    }

    if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL) {
      $classes[] = "title-access-all";
      $tooltip = t('All members - Only members of the site can see the file.');
    }

    if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION) {
      $classes[] = "title-access-organisation";
      $tooltip = t('Organisation - only authors and members of their organisations may see this file.');
    }

    if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS) {
      $classes[] = "title-access-author";
      $tooltip = t('Authors - only authors may see this file.');
    }

    if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP) {
      $classes[] = "title-access-group";
      $tooltip = t('Group - only group members may see this file.');
    }

    $variables['content']['field_file_description']['#suffix'] = '<div style="clear:both; width:100%; float:left;"></div>';
    $variables['content']['field_file_description']['#prefix'] = '<span class="' . implode(" ", $classes) . '" rel="tooltip" title="' . $tooltip . '"></span>';
  }

  uasort($variables['content']['links'], 'element_sort');

  $allowed_types = [
    'document',
    'video',
    'audio',
    'image',
    'webresource',
  ];

  if(in_array($file->type, $allowed_types)) {

    $variables['reactions_enabled'] = true;

    $RS = new ReactionService();
    $votes = $RS->getReactionsCount($variables['file']->fid, 'file');
    if(!empty($votes)) {
      $variables['reactionsSerialized'] = json_encode($votes);
    }else {
      $variables['reactionsSerialized'] = "";
    }

    $variables['svs_enabled'] = FALSE;
    if(module_exists('social_video_service')){
      $svs_settings = social_video_service_get_settings();
      $variables['svs_enabled'] = $svs_settings['enabled'] && $file->type === 'video';
    }

  }

  $drupalFile = \Wissensnetz\Core\File\DrupalFile::make($file->fid);
  if(!$drupalFile->hasPublishedNodeReferences()){
    $variables['publishing_label'] =  '<span class="icon-hourglass-o" rel="tooltip" title="" data-original-title="' . t('Draft - Only persons with edit access') . '"></span>';
  }

}


/**
 * Implementation of hook_preprocess_HOOK().
 *
 * @param  [type] $variables [description]
 *
 * @return [type]            [description]
 */
function salto2014_preprocess_message(&$variables) {
  $message = $variables['elements']['#entity'];

  $account = user_load($variables['message']->uid);



  if ($message->type == "notification_licenses_marked_for_extension") {
    if ($message->uid == 0) {
      $style = 'user_30x30';
      $file_path = "public://dosb_logo.png";
      $user_picture = '<div class="user-picture">';
      $user_picture .= theme('image_style', [
        'style_name' => $style,
        'path' => $file_path,
      ]);
      $user_picture .= '</div>';
    }
  }
  else {
    $user_picture = theme('user_picture', [
      'account' => $account,
      'style' => 'user_30x30',
    ]);
  }
  $variables['user_picture'] = $user_picture;

  if (!empty($message->field_notification_tooltip)) {
    $variables['tooltip'] = t($message->field_notification_tooltip[LANGUAGE_NONE][0]['value']);
  }

  $variables['url'] = !empty($message->field_notification_link[LANGUAGE_NONE][0]['value']) ? url("redirect/message/" . $message->mid, ['absolute' => TRUE]) : '#'; // $message->field_notification_link[LANGUAGE_NONE][0]['value'] : '#';

  $variables['content']['links']['flag']['#theme'] = 'links';

  $variables['links'] = "";

  if (!empty($variables['content']['links']['flag'])) {
    $variables['links'] .= render($variables['content']['links']['flag']);
  }

  if (!empty($variables['content']['message_flags'])) {
    $variables['links'] .= render($variables['content']['message_flags']);
  }


  if (!empty($variables['content']['notification_content_preview'])) {
    $metadata = json_decode($variables['content']['notification_content_preview']['#object']->field_notification_metadata[LANGUAGE_NONE][0]['value']);
    $variables['content_preview'] = render($variables['content']['notification_content_preview']);
    if($metadata->audio_url){
      $variables['content_preview'] = '<span class="audio-comment-notification">' . $variables['content']['notification_content_preview'][0]['#markup']. ' <audio style="height: 3rem;" preload="auto" controls controlsList="nodownload">
                  <source src="'. $metadata->audio_url .'">
              </audio></span>';
    }
  }

  $flag = flag_get_flag('notification_mark_as_read');
  $variables['read'] = $flag->is_flagged($message->mid);

  if ($variables['read']) {
    $variables['classes_array'][] = 'message-read';
  }
  else {
    $variables['classes_array'][] = 'message-unread';
  }

  $variables['main_content'] = render($variables['content']);

  if (!isset($variables['single'])) {
    $variables['single'] = TRUE;
  }

  $preview_message_types = [
    MESSAGE_TYPE_NOTIFICATION_POST_CREATED,
  ];

  if (in_array($message->type, $preview_message_types)) {
    if (!empty($message->field_notification_node_ref)) {
      $node = node_load($message->field_notification_node_ref[LANGUAGE_NONE][0]['target_id']);
      $node_view = node_view($node, 'teaser');
      $variables['content_preview_mail'] =  drupal_render($node_view['body']);
      //$variables['content_preview'] = $variables['content_preview_mail'];
    }
  }

  if ($variables['view_mode'] == 'message_mail') {
    $variables['theme_hook_suggestions'][] = 'message__mail';
    $variables['theme_hook_suggestion'] = 'message__mail';
    $variables['single'] = FALSE;

    if (SettingsService::mailPreviewImagesEnabled()) {
      switch ($message->type) {
        case MESSAGE_TYPE_NOTIFICATION_POST_CREATED:
        case MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP:
        case MESSAGE_TYPE_NOTIFICATION_REVISION_CREATED:
        case MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED:
        case MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED:
        case MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT:
        case MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT_REPLY:
        case MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED:
          if (!empty($message->field_notification_metadata[LANGUAGE_NONE][0]['value'])) {
            //svs_video_comment
            $svs_comment_metadata = json_decode($message->field_notification_metadata[LANGUAGE_NONE][0]['value']);
            if (!empty($svs_comment_metadata->link_parameter->commentId)) {
              $commentId = $svs_comment_metadata->link_parameter->commentId;
              $image_preview = '<img src="' . onsite_notification_message_thumbnail_url('comment', $commentId) . '" style="max-width: 100%;" />';
              $variables['content_preview'] = $image_preview . $variables['content_preview'];
            }
          }
          else {
            $previewImageUrl = "";
            if (!empty($message->field_notification_file_ref[LANGUAGE_NONE][0]['target_id'])) {
              //material
              try {
                $drupalFile = new DrupalFile($message->field_notification_file_ref[LANGUAGE_NONE][0]['target_id']);
                $file = $drupalFile->getFile();

                $previewImageUrl = onsite_notification_message_thumbnail_url('file', $file->fid);
              } catch (Exception $e) {

              }
            }
            elseif (!empty($message->field_notification_node_ref)) {
              //node
              try {
                $drupalNode = DrupalNode::make($message->field_notification_node_ref[LANGUAGE_NONE][0]['target_id']);
                $previewImage = $drupalNode->getPreviewImage();

                if(!empty($previewImage)) {
                  $previewImageUrl = onsite_notification_message_thumbnail_url('file', $previewImage->getFid());
                }
              } catch (Exception $e) {
              }

            }

            $image_info = @getimagesize($previewImageUrl);
            if ($image_info !== FALSE) {
              $variables['content_preview'] = '<a href="' . $variables['url'] . '">';
              $variables['content_preview'] .= '<img src="' . $previewImageUrl . '" style="max-width: 100%; width: 100%;" />' . $variables['content_preview'];
              $variables['content_preview'] .= '</a>';
            }
          }
      }
    }

  }

}

/**
 * [salto2014_preprocess description]
 *
 * @param  [type] $variables [description]
 * @param  [type] $hook      [description]
 *
 * @return [type]            [description]
 */
function salto2014_preprocess(&$variables, $hook) {
  if ($hook == "entity" && !empty($variables['message'])) {
    salto2014_preprocess_message($variables);
  }
}

function salto2014_preprocess_heartbeat_activity(&$variables) {

  $activity = $variables['heartbeat_activity'];
  $heartbeatTemplateService = new \salto_core\service\HeartbeatTemplateService($activity);

    switch ($activity->message_id){
      case 'heartbeat_add_node':
        $heartbeatTemplateService->data_for_hearbeat_activity_add_node($variables);
        return;
      case 'heartbeat_add_comment':
        $heartbeatTemplateService->data_for_heartbeat_activity_add_comment($variables);
        return;
      case 'heartbeat_video_add':
      case 'heartbeat_video_update':
      case 'heartbeat_video_react':
      case 'heartbeat_videocomment_add':
      case 'heartbeat_videocomment_react':
      case 'heartbeat_videocomment_recomment':
        $heartbeatTemplateService->data_for_hearbeat_activity_video($variables);
        return;
    }


  $variables['heartbeat_message'] = $variables['content']['message']['#markup'];
  $variables['heartbeat_content'] = $variables['content']['heartbeat_content_preview'][0]['#markup'];

  $variables['content']['message']['#markup'] = mentions_filter_filter_mentions_process($variables['content']['message']['#markup'], NULL, NULL);
  $classes_to_check = ['heartbeat_add_comment', 'heartbeat_videocomment_add', 'heartbeat_videocomment_react', 'heartbeat_videocomment_recomment'];


  if (count(array_intersect($classes_to_check, $variables['classes_array'])) > 0) {
    $posStr = strpos($variables['content']['message']['#markup'], '<blockquote>');
    $quote = substr($variables['content']['message']['#markup'], $posStr);
    $fullLength = strlen($variables['content']['message']['#markup']);
    $variables['heartbeat_message'] = substr($variables['content']['message']['#markup'], 0, ($fullLength - strlen($quote)));
    $variables['heartbeat_content'] = $quote;

    $pattern = '/<audio\b[^>]*>/i';
    if (preg_match($pattern, $variables['heartbeat_activity']->variables['!comment'])) {
      $variables['heartbeat_content'] = '<blockquote>' . $variables['heartbeat_activity']->variables['!comment'] . '</blockquote>';
    }
  }

  if (in_array('heartbeat_add_comment', $variables['classes_array'])) {
    $posStr = strpos($variables['content']['message']['#markup'], '<blockquote>');
    $quote = substr($variables['content']['message']['#markup'], $posStr);
    $fullLength = strlen($variables['content']['message']['#markup']);
    $variables['heartbeat_message'] = substr($variables['content']['message']['#markup'], 0, ($fullLength - strlen($quote)));
    $variables['heartbeat_content'] = $quote;
  }

  if (in_array('heartbeat_add_node', $variables['classes_array'])) {
    $node = node_load($variables['content']['heartbeat_content_preview']['#object']->nid);
    $body = $node->body[LANGUAGE_NONE][0]['value'];
    $value = check_markup($body, 'editor');
    $value = strip_tags($value);

    $alter['max_length'] = 200;
    $alter['word_boundary'] = TRUE;
    $alter['ellipsis'] = TRUE;
    $alter['html'] = TRUE;

    $content = views_trim_text($alter, $value);

    $variables['heartbeat_content'] = $content . '<p> <a href="/node/' . $node->nid . '" rel="nofollow">'.l(t('Read more'), "node/$node->nid").'</a></p>';
  }
}

function salto2014_preprocess_toolbar(&$variables) {
  if (WN_TESTS_RUNNING === TRUE) {
    return;
  }
  $isHomePath = stripos(current_path(), 'home') !== FALSE;
  if ($isHomePath) {
    $variables['toolbar'] = [];
    $variables['toolbar']['title'] = 'Startseite';
    $variables['toolbar']['action_links'] = [];

    $hasAccess = user_access('manage people in any organisation');
    if ($hasAccess) {
      $variables['toolbar']['context_menu'][] = [
        'icon' => 'user-plus',
        'target' => url('organisation/invite'),
        'text' => 'Personen einladen',
      ];
    }
  }

  drupal_alter('preprocess_page_toolbar', $variables);
  if ($variables['toolbar']) {
    $variables['page']['toolbar'] = $variables['toolbar'];
  }
}

function _salto2014_modal_build(&$variables) {
  $modal = $variables['modal'];
  $id = 'modal_' . $modal['title'];
  $buttonId = 'btn#' . $modal['title'];
  $buttonClass = 'for-modal ' . $modal['class'];
  $output = '<div id="' . $id . '" class="modal-tb full">
      <!-- Modal content -->
      <div class="modal-content">
          <span class="close">&times;</span>
          <div class="wrapper">
              <h2>' . $modal['title'] . '</h2>
              ' . $modal['html'] . '
              <script>new ModalAction("' . $id . '", "' . $buttonId . '");</script>
          </div>
      </div>
  </div>';
  $icon = $modal['icon'] ? $modal['icon'] : 'th-list';
  $buttonContent = '<i class="fa fa-' . $icon . '"></i>';
  if ($modal['onlyButtonTitle']) {
    $buttonContent = $modal['title'];
  }
  $button = '<button type="button" class="' . $buttonClass . '" id="' . $buttonId . '">' . $buttonContent . '</button>';
  drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/modal.action.js');

  if ($modal['accordion']) {
    $acc = $modal['accordion'];
    $object = '{ containerClassName: "' . $acc['containerClassName'] . '", buttonClassName: "' . $acc['buttonClassName'] . '"}';
    $output .= '<script>new AccordionImpl(' . $object . ');</script>';
    drupal_add_js(drupal_get_path('theme', 'salto2014') . '/assets/md/src/accordion.js');
  }
  return ['output' => $output, 'button' => $button];
}

function salto2014_modal_toc(&$variables) {
  if (empty($variables['modals']['toc'])) {
    return '';
  }

  $variables['modal'] = $variables['modals']['toc'];
  $result = _salto2014_modal_build($variables);
  $variables['toolbar']['left'] = $result['button'];
  return $result['output'];
}

function salto2014_modal_filter(&$variables) {
  if (empty($variables['modals']['filter'])) {
    return '';
  }

  $variables['modal'] = $variables['modals']['filter'];
  $result = _salto2014_modal_build($variables);
  $variables['toolbar']['filter'] = $result['button'];
  return $result['output'];
}

function salto2014_preprocess_page_floating_button(&$variables) {
  if (stripos(current_path(), 'home') !== FALSE) {
    salto2014_preprocess_page_floating_button_defaults($variables);
  }

  drupal_alter('preprocess_page_floating_button', $variables);
  if ($variables['floating_button']) {
    $variables['floating_button']['content'] = salto2014_floating_button($variables);
  }

  if (!$variables['page']['content']['system_main']['#node_edit_form']) {
    return;
  }
  $variables['floating_button']['content'] = NULL;
}

function salto2014_preprocess_page_floating_button_defaults(&$variables) {
  $variables['floating_button']['links'][] = [
    'icon' => 'align-left',
    'target' => '/node/add/post',
    'title' => t('Create post'),
  ];
  $variables['floating_button']['links'][] = [
    'icon' => 'upload',
    'target' => '/file/add_anything',
    'title' => 'Datei hochladen',
  ];
}

function salto2014_floating_button(&$variables) {
  $links = $variables['floating_button']['links'];
  if (count($links) > 1) {
    $output = '<a href="#" class="float ease-out" id="menu-share"><i class="fa fa-plus mt-18"></i></a>';
    $output .= '<ul>';
    foreach ($links as $key => $link) {
      $icon = '<i class="fa fa-' . $link['icon'] . ' mt-18"></i>';
      $output .= '<li><a href="' . $link['target'] . '" class="tip" id="menu-' . $link['icon'] . '">' . $icon . '</a></li>';
    }
    $output .= '</ul>';
  }
  else {
    $link = $links[0];
    $icon = '<i class="fa fa-' . $link['icon'] . ' mt-18"></i>';
    $output = '<a href="' . $link['target'] . '" class="float" id="menu-' . $link['icon'] . '" title="' . $link['title'] . '">' . $icon . '</a>';
  }
  if ($variables['floating_button']['is-submit']) {
    $link = $links[0];
    $icon = '<i class="fa fa-' . $link['icon'] . ' mt-04"></i>';
    $output = '<button type="submit" id="edit-submit" name="op" value="Speichern" class="float btn btn-success form-submit icon-before">' . $icon . '</button>';
  }
  $variables['floating_button']['content'] = $output;#
  return $output;
}

function salto2014_html_card_small($variables, $isMobile = TRUE) {
  $left = $variables['title'];
  $right = $variables['content'];
  $content = '';
  foreach ($right as $text) {
    $content .= '<span>' . $text . '</span>';
  }
  $cc = '<div class="card-content row-direction">
            <span class="left">' . $left . '</span>
            <span class="right">' . $content . '</span>
        </div>';
  $mobileClass = $isMobile ? 'is-mobile' : '';
  $card = '<div class="card small ' . $mobileClass . '">' . $cc . '</div>';
  return $card;
}

function salto2014_breadcrumb($variables) {
  $breadcrumbs = $variables['breadcrumb'];

  if (current_path() != 'home') {
    $breadcrumb_title = drupal_get_title();
  }

  array_splice($breadcrumbs, count($breadcrumbs) - 1, 0, $breadcrumb_title);

  if (!empty($breadcrumbs)) {

    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $hide_single_breadcrumb = variable_get('path_breadcrumbs_hide_single_breadcrumb', 0);
    if ($hide_single_breadcrumb && count($breadcrumbs) == 1) {
      return FALSE;
    }

    if (is_array($breadcrumbs[count($breadcrumbs) - 1])) {
      array_pop($breadcrumbs);
    }

    $elem_tag = 'span';
    $elem_property = '';
    $root_property = '';
    $options = ['html' => TRUE];
    $snippet = variable_get('path_breadcrumbs_rich_snippets', PATH_BREADCRUMBS_RICH_SNIPPETS_DISABLED);
    if ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_RDFA) {
      $options['attributes'] = ['rel' => 'v:url', 'property' => 'v:title'];
      $options['absolute'] = TRUE;

      $elem_property = ' typeof="v:Breadcrumb"';
      $root_property = ' xmlns:v="http://rdf.data-vocabulary.org/#"';
    }
    elseif ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_MICRODATA) {
      $options['attributes'] = ['itemprop' => 'url'];
      $options['absolute'] = TRUE;

      $elem_property = ' itemscope itemtype="http://data-vocabulary.org/Breadcrumb"';
      $elem_tag = 'div';

      drupal_add_css(drupal_get_path('module', 'path_breadcrumbs') . '/css/path_breadcrumbs.css');
    }

    foreach ($breadcrumbs as $key => $breadcrumb) {

      $classes = ['inline'];
      $classes[] = $key % 2 ? 'even' : 'odd';
      if ($key == 0) {
        $classes[] = 'first';
      }
      if (count($breadcrumbs) == $key + 1) {
        $classes[] = 'last';
      }

      preg_match('/href="([^"]+?)"/', $breadcrumb, $matches);

      $href = '';
      if (!empty($matches[1])) {
        global $base_path;
        global $language;

        $base_string = rtrim($base_path, "/");

        if (!variable_get('clean_url', 0)) {
          $base_string .= '?q=';
        }

        $enabled_negotiation_types = variable_get("language_negotiation_language", []);
        if (!empty($enabled_negotiation_types['locale-url']) && !empty($language->prefix)) {
          $base_string .= '/' . $language->prefix;
        }

        if ($matches[1] == $base_string || $matches[1] == '' || $matches[1] == '/') {
          $href = '';
        }
        elseif (stripos($matches[1], "$base_string/") === 0) {
          $href = drupal_substr($matches[1], drupal_strlen("$base_string/"));
        }
        else {
          $href = stripos($matches[1], '/') === 0 ? drupal_substr($matches[1], 1) : $matches[1];
        }
        $href = empty($href) ? '<front>' : $href;
      }
      $title = trim(strip_tags($breadcrumb));

      if ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_MICRODATA) {
        $title = '<span itemprop="title">' . $title . '</span>';
      }

      if (preg_match('/<a\s.*?title="([^"]+)"[^>]*>/i', $breadcrumb, $attr_matches)) {
        $options['attributes']['title'] = $attr_matches[1];
      }
      else {
        unset($options['attributes']['title']);
      }

      $href = rawurldecode($href);
      $href = _path_breadcrumbs_clean_url($href, $options, 'none');
      $new_breadcrumb = !empty($href) ? l($title, $href, $options) : $title;
      $breadcrumbs[$key] = '<' . $elem_tag . ' class="' . implode(' ', $classes) . '"' . $elem_property . '>' . $new_breadcrumb . '</' . $elem_tag . '>';
    }

    $delimiter = variable_get('path_breadcrumbs_delimiter', '»');
    $delimiter = '<span class="delimiter">' . trim($delimiter) . '</span>';

    $classes = ['breadcrumb'];

    $prefix = '';
    $path_breadcrumbs_data = path_breadcrumbs_load_variant(current_path());
    if (user_access('administer path breadcrumbs') && $path_breadcrumbs_data && isset($path_breadcrumbs_data->variant)) {
      $contextual_links = [
        '#type' => 'contextual_links',
        '#contextual_links' => [
          'path_breadcrumbs' => [
            'admin/structure/path-breadcrumbs/edit',
            [$path_breadcrumbs_data->variant->machine_name],
          ],
        ],
      ];
      $prefix = drupal_render($contextual_links);
      $classes[] = 'contextual-links-region';
    }

    $output .= '<div class="' . implode(' ', $classes) . '"' . $root_property . '>' . $prefix . implode(" $delimiter ", $breadcrumbs) . '</div>';

    return $output;
  }
  return FALSE;
}

function salto2014_preprocess_page(&$variables) {
  global $user, $use_minimal_theme, $conf;

  if ($use_minimal_theme == TRUE) {
    $variables['theme_hook_suggestions'][] = 'page__minimal';
  }

  if (module_exists('wn_blanko')) {
    $variables['wn_blanko'] = TRUE;
    $variables['wn_blanko_instance_key'] = $conf['wn_blanko']['instance_key'];
  }

  if ($variables['wn_blanko'] && !empty($conf['wn_blanko']['logo'])) {
    $variables['logo'] = $conf['wn_blanko']['logo'];
  }

  if ($user->uid == 0) {
    $variables['salto_sponsors'] = TRUE;
    return;
  }

  $elements = ['floating_button'];
  foreach ($elements as $element) {
    $function = __FUNCTION__ . '_' . $element;
    if (function_exists($function)) {
      $function($variables);
    }
  }

  if (stripos(current_path(), 'search') === FALSE) {
    $variables['page']['search'] = salto_search_render_search_form(FALSE);
    $isForm2 = stripos($variables['page']['search'], 'salto-search-search-form--2') > -1;
    if (!$isForm2) {
      $variables['page']['search'] = str_replace('salto-search-search-form', 'salto-search-search-form--2', $variables['page']['search']);
      $variables['page']['search'] = str_replace('edit-text', 'edit-text--2', $variables['page']['search']);
    }
  }

  $variables['page']['toolbar'] = theme('toolbar', $variables);
  if(salto_user_global_header_enabled() && salto_keycloak_get_access_token()){
    $menuService = new \Wissensnetz\Menu\MenuService();
    $tumSettings = salto_keycloak_tum_get_settings();
    $userportalSettings = salto_keycloak_get_userportal_settings();
    $tumApiService = new \Keycloak\TumApiService();
    $drupalUser = \Wissensnetz\User\DrupalUser::current();
    $groupNode = GroupDrupalNode::current();
    if(!empty($groupNode)){
      $tumApiService->updateContextHistory($groupNode, $drupalUser);
    }

    $variables['show_global_header'] = TRUE;
    $variables['global_header']['backendUrl'] = url('', array('absolute' => TRUE));
    $variables['global_header']['logoUrl'] = $variables['logo'];
    $variables['global_header']['tumUrl'] = $tumSettings['tum_url'];
    $variables['global_header']['ogTitle'] = $menuService->getContextSwitcherLabel();
    $variables['global_header']['localMenu'] = check_plain(json_encode($menuService->getLocalUserMenu()));
    $variables['global_header']['global_header_url'] = $userportalSettings['global_header_web_component_url'];
    ##unset($variables['logo']);

  }

  salto_2014_process_main_manu($variables);

}

function salto_2014_process_main_manu(&$variables) {
  //hide onlinetreffen menu item if not enabled
  if(!salto_online_meeting_community_area_show_menu_item()){
    foreach($variables['primary_nav'] as &$item){
      if($item['#href'] == 'online-meetings/status'){
        $item['#attributes']['class'][] = 'hidden';
      }
    }

  }
}

/**
 * Overrides theme_pager().
 */
function salto2014_pager($variables) {
  $output = "";
  $items = [];
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];

  global $pager_page_array, $pager_total;

  $pager_middle = ceil($quantity / 2);
  $pager_current = $pager_page_array[$element] + 1;
  $pager_first = $pager_current - $pager_middle + 1;
  $pager_last = $pager_current + $quantity - $pager_middle;
  $pager_max = $pager_total[$element];

  $i = $pager_first;
  if ($pager_last > $pager_max) {
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  $li_first = theme('pager_first', [
    'text' => t('Erste Seite'),
    'element' => $element,
    'parameters' => $parameters,
  ]);
  $li_previous = theme('pager_previous', [
    'text' => t('<'),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ]);
  $li_next = theme('pager_next', [
    'text' => t('>'),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ]);
  $li_last = theme('pager_last', [
    'text' => t('Letzte Seite'),
    'element' => $element,
    'parameters' => $parameters,
  ]);
  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = [
        'class' => ['pager-first'],
        'data' => $li_first,
      ];
    }

    if ($li_previous) {
      $items[] = [
        'class' => ['prev'],
        'data' => $li_previous,
      ];
    }
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = [
          'class' => ['pager-ellipsis', 'disabled'],
          'data' => '<span>…</span>',
        ];
      }

      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = [
            // 'class' => array('pager-item'),
            'data' => theme('pager_previous', [
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            ]),
          ];
        }
        if ($i == $pager_current) {
          $items[] = [
            'class' => ['active'],
            'data' => l($i, '#', ['fragment' => '', 'external' => TRUE]),
          ];
        }
        if ($i > $pager_current) {
          $items[] = [
            'data' => theme('pager_next', [
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            ]),
          ];
        }
      }
      if ($i < $pager_max) {
        $items[] = [
          'class' => ['pager-ellipsis', 'disabled'],
          'data' => '<span>…</span>',
        ];
      }
    }
    if ($li_next) {
      $items[] = [
        'class' => ['next'],
        'data' => $li_next,
      ];
    }

    if ($li_last) {
      $items[] = [
        'class' => ['pager-last'],
        'data' => $li_last,
      ];
    }
    return '<div class="text-center">' . theme('item_list', [
        'items' => $items,
        'attributes' => ['class' => ['pagination']],
      ]) . '</div>';
  }
  return $output;
}


/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 * An invisible heading identifies the messages for assistive technology.
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html
 * for info.
 *
 * @param array $variables
 *   An associative array containing:
 *   - display: (optional) Set to 'status' or 'error' to display only messages
 *     of that type.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_status_messages()
 *
 * @ingroup theme_functions
 */
function salto2014_status_messages($variables) {

  $display = $variables['display'];
  $output = '';
  $status_heading = [
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  ];

  $status_class = [
    'status' => 'success',
    'error' => 'danger',
    'warning' => 'warning',
    'info' => 'info',
  ];

  $message_list = drupal_get_messages($display);

  if (module_exists('disable_messages') && variable_get('disable_messages_enable', '1')) {
    $message_list = disable_messages_apply_filters($message_list);
  }
  foreach ($message_list as $type => $messages) {
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';
    $output .= "<div class=\"alert alert-block$class messages $type\">\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">&times;</a>\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h4 class="element-invisible">' . filter_xss_admin($status_heading[$type]) . "</h4>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        if (!module_exists('devel')) {
          $output .= '  <li>' . filter_xss_admin($message) . "</li>\n";
        }
        else {
          $output .= ' <li>' . $message . "</li>\n";
        }
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= filter_xss_admin($messages[0]);
    }
    $output .= "</div>\n";
  }
  return $output;
}

function salto2014_preprocess_privatemsg_recipients(&$variables) {
  global $user;
  $participants = $variables['thread']['participants'];
  foreach ($participants as $key => $participant) {
    if ($key == 'user_' . $user->uid) {
      unset($participants[$key]);
      break;
    }
  }
  $variables['participants'] = _privatemsg_format_participants($participants, NULL, TRUE);

  $originalId = $variables['thread']['thread_id'];
  $variables['toolbar']['title'] = drupal_get_title();
  $variables['toolbar']['action_links'][] = [
    'icon' => 'trash-alt',
    'target' => '/messages/delete/' . $originalId . '/' . $originalId,
    'text' => t('Delete'),
    'title' => t('Delete'),
  ];

  $variables['page']['toolbar'] = theme('toolbar', $variables);
}

function salto2014_preprocess_privatemsg_view(&$variables) {
  $variables['message_timestamp'] = format_date($variables['message']->timestamp);
}

function salto2014_preprocess_material_card(&$variables){

  drupal_add_css(drupal_get_path('module', 'salto_knowledgebase') . '/css/material_card.css');
  $settings = SettingsService::getThemenfelderAsCard();
  $taxonomyId = $variables['taxonomy_id'] != '' ? $variables['taxonomy_id'] : 0;
  $tree = taxonomy_get_tree($settings['taxonomy_id'], $taxonomyId, 1);
  $cards = [];
  foreach ($tree as $term) {
    $drupalTerm = \Wissensnetz\Taxonomy\DrupalTerm::make($term->tid);
    $cards[] = [
      'image' => $drupalTerm->getImageUrl() ?? url($settings['default_logo'], ['absolute' => TRUE]),
      'icon' => $drupalTerm->getIconUrl() ?? url($settings['default_icon'], ['absolute' => TRUE]),
      'label' => $drupalTerm->getName(),
      'target' => '/materials/' . $drupalTerm->getTid()
    ];
  }

  usort($cards, function($a, $b){ return strcmp(strtolower($a["label"]), strtolower($b["label"])); });

  $variables['cards'] = $cards;
  $variables['icon'] = '/sites/all/static_files/material-card-arrow.svg';

  if($taxonomyId){

    $backlink = [
      'name' => t('Materials'),
      'target' => '/materials'
    ];

    $parent = current(taxonomy_get_parents($taxonomyId));

    if(!empty($parent)){
      $drupalTerm = \Wissensnetz\Taxonomy\DrupalTerm::make($parent);
      $backlink = [
        'name' => $drupalTerm->getName(),
        'target' => '/materials/' . $drupalTerm->getTid()
      ];
    }


    $variables['backlink'] = $backlink;
  }

}
