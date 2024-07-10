<?php

namespace Wissensnetz\User;

use Wissensnetz\User\Exception\DrupalUserDoubleMailException;
use Wissensnetz\User\Exception\DrupalUserNotExistsException;

class DrupalUser {

  protected $user;

  public function __construct($uid) {
    if ($uid instanceof \stdClass) {
      $this->user = $uid;
    }
    else {
      $this->user = user_load($uid, TRUE);
    }

    if (!property_exists($this->user, 'profile')) {
      $this->loadProfile();
    }

  }

  public static function byMail($mail) {
    $account = user_load_by_mail($mail);
    if (empty($account)) {
      return NULL;
    }
    return new DrupalUser($account->uid);
  }

  public static function make($uid) {
    return new DrupalUser($uid);
  }

  public static function byId($id) {

    if (is_numeric($id)) {
      return self::make($id);
    }

    return self::byGuid($id);

  }

  public static function byGuid($guid) {
    if (empty($guid)) {
      throw new DrupalUserNotExistsException();
    }

    if (module_exists('salto_keycloak')) {
      $records = db_select('edubreak_user', 'edubreak_user')
        ->fields('edubreak_user')
        ->condition('guid', $guid)
        ->execute()->fetchAll();
    }
    else {
      $records = db_select('users', 'users')
        ->fields('users', ['uid'])
        ->condition('uuid', $guid)
        ->execute()->fetchAll();
    }

    if (empty($records)) {
      throw new DrupalUserNotExistsException();
    }

    return new DrupalUser($records[0]->uid);
  }

  public function getFirstName() {
    return $this->user->profile->field_profile_name_first[LANGUAGE_NONE][0]['value'];
  }

  public function getLastName() {
    return $this->user->profile->field_profile_name_last[LANGUAGE_NONE][0]['value'];
  }

  public function getProfileMail() {
    return $this->user->profile->field_profile_contact_email[LANGUAGE_NONE][0]['value'];
  }

  public function getProfileImage() {
    return $this->user->profile->field_user_picture[LANGUAGE_NONE][0];
  }

  public function getProfileImageUrl() {
    return salto_user_get_user_picture($this->getUser());
  }

  public function updateProfile($profile) {
    $this->user->profile->field_profile_name_first[LANGUAGE_NONE][0]['value'] = $profile['firstName'] ?? $this->getFirstName();
    $this->user->profile->field_profile_name_last[LANGUAGE_NONE][0]['value'] = $profile['lastName'] ?? $this->getLastName();
    $this->user->profile->field_profile_contact_email[LANGUAGE_NONE][0]['value'] = $profile['profile']['email'] ?? $this->getProfileMail();
    profile2_save($this->user->profile);
  }

  public function getUid() {
    return $this->user->uid;
  }

  public function getUser() {
    return $this->user;
  }

  private function loadProfile() {
    $this->user->profile = profile2_load_by_user($this->getUid())['main'];

  }

  public function reload() {
    $this->user = user_load($this->getUid(), TRUE);
    $this->loadProfile();
  }

  public function getLoginMail() {
    return $this->user->mail;
  }

  private function allowedToChangeMail($mail) {
    $existingUser = DrupalUser::byMail($mail);

    if (empty($existingUser)) {
      return TRUE;
    }

    if ($existingUser->getUid() == $this->getUid()) {
      return TRUE;
    }

    return FALSE;

  }

  public function updateMail($mail) {
    $existingUser = DrupalUser::byMail($mail);

    if ($this->allowedToChangeMail($mail)) {
      $edit['mail'] = $mail ?? $this->getLoginMail();
      user_save($this->user, $edit);
      return;
    }

    $body = [
      'target_mail' => $mail,
      'remote_user' => [
        'uid' => $this->getUid(),
        'guid' => $this->getGuid(),
        'mail' => $this->getLoginMail(),
      ],
      'local_user' => [
        'uid' => $existingUser->getUid(),
        'guid' => $existingUser->getGuid(),
        'mail' => $existingUser->getLoginMail(),
      ],
    ];

    salto_debug_log_to_slack('Double mail problem found', print_r($body, TRUE));

    throw new DrupalUserDoubleMailException();
  }

  public function isAnonymous(): bool {
    return $this->user->uid == 0;
  }

  public static function current(): DrupalUser {
    global $user;
    return new DrupalUser($user);
  }

  public function getGuid() {

    if (module_exists('salto_keycloak')) {
      $query = db_select('edubreak_user', 'edubreak_user');
      $query->fields('edubreak_user', ['guid']);
      $query->condition('uid', $this->getUid());
      $result = $query->execute()->fetchAll();

      if (!empty($result)) {
        return $result[0]->guid;
      }

    }
    else {
      return $this->user->uuid;
    }

    return NULL;
  }


  public function hasAcceptedLegal() {
    $conditions = legal_get_conditions();
    $legal_account = legal_get_accept($this->getUid());
    return legal_version_check($this->getUid(), $conditions['version'], $conditions['revision'], $legal_account);
  }

  public function reloadUser() {
    $this->user = user_load($this->getUid(), TRUE);
  }

  public function getOgNids() {
    $og_groups = $this->user->field_user_groups[LANGUAGE_NONE];
    $og_nids = [];
    foreach ($og_groups as $group) {
      $og_nids[] = $group['target_id'];
    }
    return $og_nids;
  }

  public function getRealname() {
    return $this->getFirstName() . ' ' . $this->getLastName();
  }

  public function getRealnameLink() {
    return l($this->getRealname(), 'user/' . $this->getUid(), ['absolute' => TRUE,]);

  }

  public function isCommunityManager() {

    if (user_has_role(ROLE_GLOBAL_ADMIN_RID, $this->user)) {
      return TRUE;
    }

    return user_has_role(ROLE_GLOBAL_DOSB_RID, $this->user);
  }

  public function isOnlineMeetingManager() {

    if (user_has_role(ROLE_GLOBAL_ADMIN_RID, $this->user)) {
      return TRUE;
    }

    return user_has_role(ROLE_GLOBAL_ONLINETREFFEN_MANAGER, $this->user);
  }


  public function isActive() {
    return $this->user->status;
  }

  public function getUserUrl() {
    return url('user/' . $this->getUid(), ['absolute' => TRUE,]);
  }

  public function anomyize(){
    $this->user->profile->field_profile_name_first[LANGUAGE_NONE][0]['value'] = 'Anonymisierter';
    $this->user->profile->field_profile_name_last[LANGUAGE_NONE][0]['value'] = 'Benutzer:in';
    unset($this->user->profile->field_profile_interests[LANGUAGE_NONE][0]);
    unset($this->user->profile->field_profile_sports[LANGUAGE_NONE][0]);
    unset($this->user->profile->field_profile_competencies[LANGUAGE_NONE][0]);
    unset($this->user->profile->field_profile_categories[LANGUAGE_NONE][0]);
    unset($this->user->profile->field_profile_postal_address[LANGUAGE_NONE][0]);
    unset($this->user->profile->field_organisation_position[LANGUAGE_NONE][0]);
    $this->user->profile->field_profile_contact_mobile[LANGUAGE_NONE][0]['value'] = '';
    $this->user->profile->field_profile_contact_phone[LANGUAGE_NONE][0]['value'] = '';
    $this->user->profile->field_profile_about_me[LANGUAGE_NONE][0]['value'] = '';
    $this->user->profile->field_profile_contact_email[LANGUAGE_NONE][0]['value'] = '';
    profile2_save($this->user->profile);
    unset($this->user->field_user_organisations);
    $edit['field_user_organisations'] = [];
    user_save($this->user, $edit);

  }

}
