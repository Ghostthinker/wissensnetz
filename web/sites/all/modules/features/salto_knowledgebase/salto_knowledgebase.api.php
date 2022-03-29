<?php

/**
 * @file
 * Hooks provided by salto knowledgebase
 *
 */

/**
 * Alter the access options for salto_collaboration field
 *
 * @param  [type] $options [description]
 *
 * @return [type]          [description]
 */
function hook_salto_post_access_options_alter($op, &$options) {
  $additional_option_as_int = 0;
  $options[$additional_option_as_int] = t('default');
}


/**
 * A post has been created and saved to db. Grants have also been saved
 *
 * @param $node
 * @param $is_new
 *   indicates that the node is newly created, because at that moment the
 *   $node->is_new is not set any more
 */
function hook_knowledgebase_post_submitted($node, $is_new = FALSE) {
  drupal_set_message("default");
}
