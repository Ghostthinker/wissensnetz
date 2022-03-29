<?php
/**
 * @file
 * salto_share.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function salto_share_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'salto_share_post_action';
  $content->admin_title = 'salto_share_post_action';
  $content->admin_description = '';
  $content->category = 'Gruppen';
  $content->settings = array(
    'admin_title' => 'salto_share_post_action',
    'title' => '',
    'body' => '<a href="/node/add/shared-post?field_sharedpost_reference=%node:nid" title="<?php print t("You can share this post to one of your groups"); ?>" class="share share-action salto_knowledgebase-processed share-processed" rel="nofollow"><?php print t("Share"); ?></a>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $export['salto_share_post_action'] = $content;

  return $export;
}
