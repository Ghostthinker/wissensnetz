<?php

namespace salto_core\migration;


use stdClass;

class ContentGroup extends Content {

  const JOIN_MODE_OPEN = 0;

  const JOIN_MODE_MODERATED = 1;

  const JOIN_MODE_CLOSED = 3;

  public function create($content) {
    $node = new \stdClass();
    $node->title = $content['title'];
    $node->type = 'group';
    $node->language = LANGUAGE_NONE;
    //$node->uid = $managerId;
    $node->field_group_categories[LANGUAGE_NONE][0]['tid'] = salto_knowledgebase_get_default_kb_category_tid();
    $node->body[LANGUAGE_NONE][0]['value'] = $content['body'];
    $node->field_group_join_mode[LANGUAGE_NONE][0]['value'] = $this->getGroupJoinMode($content['selective']);

    node_save($node);

    $gid = $node->nid;
    $vocabularies = salto_group_get_group_vocabularies($gid);
    $vocab_posts = $vocabularies["posts"];
    $vid = $vocab_posts->vid;

    $term = new stdClass();
    $term->vocabulary_machine_name = 'group_category_' . $gid;
    $term->name = 'Blogposts';
    $term->description = '';
    $term->vid = $vid;
    $term->format = 'editor';
    taxonomy_term_save($term);

    $term = new stdClass();
    $term->vocabulary_machine_name = 'group_category_' . $gid;
    $term->name = 'News';
    $term->description = '';
    $term->vid = $vid;
    $term->format = 'editor';
    taxonomy_term_save($term);

    return $gid;
  }

  private function getGroupJoinMode($mode) {
    if (self::JOIN_MODE_OPEN == $mode) {
      return -1;
    }
    if (self::JOIN_MODE_MODERATED == $mode) {
      return 2;
    }
    if (self::JOIN_MODE_CLOSED == $mode) {
      return 4;
    }
  }

}
