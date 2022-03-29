<?php

/**
 * @file
 * salto_group.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function salto_group_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'groups_group_description';
  $content->admin_title = 'Gruppe - Gruppenbeschreibung';
  $content->admin_description = '';
  $content->category = 'Gruppen';
  $content->settings = array(
    'admin_title' => 'Gruppe - Gruppenbeschreibung',
    'title' => 'Gruppenbeschreibung',
    'body' => '<?php
$og = og_context();
$group = node_load($og[\'gid\']);

//Text displayed if no body is set
$empty_text = \'<p>\'.t(\'This group does not have a description yet.\').\'</p>\';

$summary = "";
if(!empty($group->body[LANGUAGE_NONE][0][\'value\'])) {
   //shorten body, if it is not empty - empty body causes an error!
  $summary= text_summary($group->body[LANGUAGE_NONE][0][\'value\'], \'editor\', 150);
}else {
  //set default empty text if body is empty
  $summary = $empty_text;
}


$output .= $summary;

//check if body got shortened by comparing the lenth of the original body and summery.
//also prevent displaying the "more" link, if default empty text is set
if(drupal_strlen($summary ) !== drupal_strlen($group->body[LANGUAGE_NONE][0][\'value\']) && $summary !==$empty_text) {
  //text got shortened
  $output .= \'<a style="float:right" href="/node/\'.$group->nid.\'/info">Ausführliche Beschreibung &gt;</a>\';
}


echo $output;

?>',
    'format' => 'php_code',
    'substitute' => 0,
  );
  $export['groups_group_description'] = $content;

  return $export;
}
