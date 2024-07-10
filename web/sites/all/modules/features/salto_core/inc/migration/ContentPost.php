<?php

namespace salto_core\migration;


use stdClass;

class ContentPost extends Content {

  public function create($content) {

    $user = $this->getContentAuthor($content['author']);

    $node = new StdClass();
    $node->type = 'post';
    $node->title = $content['title'];
    $node->status = 1;
    $node->language = LANGUAGE_NONE;
    $node->body[LANGUAGE_NONE][0]['value'] = $content['body'];
    $node->body[LANGUAGE_NONE][0]['safe_value'] = $content['body'];
    $node->body[LANGUAGE_NONE][0]['format'] = 'editor';
    $node->field_post_authors[LANGUAGE_NONE][0]['target_id'] = $user->uid ?? $user->getUid();
    $node->field_og_group[LANGUAGE_NONE][0]['target_id'] = $content['og_id'];
    $node->uid =  $user->uid ?? $user->getUid();
    $node->created = strtotime($content['created']);
    $node->comment = COMMENT_NODE_OPEN;
    $node->last_comment_uid = 0;

    switch ($content['type']){
      case 'blog':
        $category = taxonomy_get_term_by_name('Blogposts', 'group_category_' . $content['og_id']);
        reset($category);
        $term = current($category);
        $node->og_vocabulary[LANGUAGE_NONE][0]['target_id'] = $term->tid;
        break;
      case 'news':
        $category = taxonomy_get_term_by_name('News', 'group_category_' . $content['og_id']);
        reset($category);
        $term = current($category);
        $node->og_vocabulary[LANGUAGE_NONE][0]['target_id'] = $term->tid;
        break;
    }


    //Access is group
    $node->field_post_collaboration[LANGUAGE_NONE][0]['read'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP;
    $node->field_post_collaboration[LANGUAGE_NONE][0]['edit'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;



    node_save($node);

    //Attachments
    if (!empty($content['attachments'])) {
      $i=0;
      foreach ($content['attachments'] as $attachment) {

        $file = MigrationService::importAttachment($attachment['item_url'], $attachment['label']);
        $node->field_post_attachment[LANGUAGE_NONE][$i]['fid'] = $file->fid;
        $node->field_post_attachment[LANGUAGE_NONE][$i]['display'] = 1;
        $i++;
      }
    }

    node_save($node);
    return $node;
  }

}
