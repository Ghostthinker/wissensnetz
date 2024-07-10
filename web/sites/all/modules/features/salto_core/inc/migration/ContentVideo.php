<?php

namespace salto_core\migration;


use stdClass;
use Wissensnetz\User\DrupalUser;

class ContentVideo extends Content {

  public function create($content) {

    $uniqueNonce = uuid_generate();

    $user = $this->getContentAuthor($content['author']);

    $file = new stdClass();
    $file->uid = $user->uid ?? $user->getUid();
    $file->filename = $content['title'];
    $file->uri = "prevoli://" .$uniqueNonce . '/'  . $content['streamingId'];
    $file->filemime = "video/extern";
    $file->timestamp = REQUEST_TIME;
    $file->created = $content['created'];
    $file->status = FILE_STATUS_PERMANENT;
    $file->field_og_group[LANGUAGE_NONE][0]['target_id'] = $content['og_id'];
    $file->field_post_collaboration[LANGUAGE_NONE][0]['read'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP;
    $file->field_post_collaboration[LANGUAGE_NONE][0]['edit'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;
    $file->field_file_originator[LANGUAGE_NONE][0]['value']['#default_value'] = $user->realname ?? $user->getFirstName() . ' ' . $user->getLastName();

    $file = file_save($file);
    $file->field_post_collaboration[LANGUAGE_NONE][0]['read'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP;
    $file->field_post_collaboration[LANGUAGE_NONE][0]['edit'] = SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;
    $file = file_save($file);
    module_invoke_all('migrate_imported_video', $file, $content);
  }

}
