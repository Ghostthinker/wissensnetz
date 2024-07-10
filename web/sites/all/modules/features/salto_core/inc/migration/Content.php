<?php

namespace salto_core\migration;


use stdClass;
use Wissensnetz\User\DrupalUser;

abstract class Content {

  abstract public function create($content);

  public function getContentAuthor($author) {
    try {
      $user = DrupalUser::make($author);
    } catch (\Exception $e) {
      $user = new stdClass();
      $user->uid = USER_DELETED_UID;
      $user->realname = variable_get('deleted-user', t('deleted user'));
    }

    return $user;
  }

}
