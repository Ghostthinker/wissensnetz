<?php

namespace salto_core\migration;


use stdClass;

class ContentMaterial extends Content {

  public function create($content) {

    $user = $this->getContentAuthor($content['author']);

    $destinationPath = 'private://uploads/document/group-' . $content['og_id'] . '/';
    if (!file_prepare_directory($destinationPath, FILE_CREATE_DIRECTORY)){
      throw new \Exception('Destination path is not writable');
    };

    $image_data = file_get_contents($content['item_url']);

    $picture_url_parsed = parse_url($content['item_url']);
    $picture_url_info = pathinfo($picture_url_parsed['path']);
    $file = file_save_data($image_data, $destinationPath . $picture_url_info['basename'], FILE_EXISTS_RENAME);
    image_path_flush($file->uri);

    if($file->type == 'image'){
      $file->field_file_image_title_text  [LANGUAGE_NONE][0]['value'] = $content['title'];
      $file->field_file_image_title_text  [LANGUAGE_NONE][0]['safe_value'] = $content['title'];
      $file->field_file_image_title_text  [LANGUAGE_NONE][0]['format'] = NULL;
    }else{
      $file->field_file_title [LANGUAGE_NONE][0]['value'] = $content['title'];
      $file->field_file_title [LANGUAGE_NONE][0]['safe_value'] = $content['title'];
      $file->field_file_title [LANGUAGE_NONE][0]['format'] = NULL;
    }

    $file->uid = $user->uid ?? $user->getUid();
    $file->field_file_description [LANGUAGE_NONE][0]['value'] = $content['description'];
    $file->field_file_description [LANGUAGE_NONE][0]['safe_value'] = $content['description'];
    $file->field_file_description [LANGUAGE_NONE][0]['format'] = NULL;
    $file->status = FILE_STATUS_PERMANENT;
    $file->field_og_group[LANGUAGE_NONE][0]['target_id'] = $content['og_id'];
    $file->field_post_collaboration[LANGUAGE_NONE][0]['read'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP;
    $file->field_post_collaboration[LANGUAGE_NONE][0]['edit'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;
    $file->field_file_originator[LANGUAGE_NONE][0]['value']['#default_value'] = $user->realname ?? $user->getFirstName() . ' ' . $user->getLastName();
    $file->field_file_license_type[LANGUAGE_NONE][0]['value'] = 'unlicensed';


    $file->created = $content['created'] ?  strtotime($content['created']) : strtotime('NOW');

    if (!empty($content['folder_tid'])){
      $file->og_vocabulary[LANGUAGE_NONE][] = ['target_id' => $content['folder_tid']];
    }

    if (!empty($content['tags'])) {
      $vocabulary = taxonomy_vocabulary_machine_name_load('post_tags');
      foreach ($content['tags'] as $tag) {
        $terms = taxonomy_get_term_by_name($tag['name'], $vocabulary->machine_name);

        if (empty(end($terms))) {
          $term = new stdClass();
          $term->name = $tag['name'];
          $term->vid = $vocabulary->vid;
          taxonomy_term_save($term);
        }
        else {
          $term = end($terms);
        }
        $file->field_post_tags[LANGUAGE_NONE][] = ['tid' => $term->tid];
      }
    }

    $file = file_save($file);

    return $file;

  }

}
