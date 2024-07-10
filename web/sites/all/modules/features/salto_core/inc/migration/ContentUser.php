<?php

namespace salto_core\migration;


use stdClass;

class ContentUser extends Content {

  public function create($content) {


    $existingUser = user_load_by_mail($content['mail']);
    if($existingUser){
      return $existingUser->uid;
    }


    $account = new stdClass();
    $account->mail = $content['mail'];
    $account->name = $content['mail'];
    $account->is_new = TRUE;
    $account->status = 1;
    $account->roles[2] = 2;


    $edit['pass'] = $content['pass'];


    if ($content['language']) {
      $account->language = $content['language'];
    }

    $account = user_save($account, $edit);

    $image_data = file_get_contents($content['picture_url']);
    $picture_url_parsed = parse_url($content['picture_url']);
    $picture_url_info = pathinfo($picture_url_parsed['path']);
    $extension = $picture_url_info['extension'];
    $new_file_name = 'edubreak-user-image-g' . $account->uid;
    $temp_file = file_save_data($image_data, 'private://uploads/image/user' . $new_file_name . '.' . $extension, FILE_EXISTS_REPLACE);
    image_path_flush($temp_file->uri);
    $profile = profile_create(['type' => 'main', 'uid' => $account->uid]);
    // Add in the necessary custom fields and values.
    $profile->field_profile_name_first[LANGUAGE_NONE][0]['value'] = $content['firstname'];
    $profile->field_profile_name_last[LANGUAGE_NONE][0]['value'] = $content['lastname'];
    $profile->field_user_picture[LANGUAGE_NONE][0]['fid'] = $temp_file->fid;
    // Save the profile2 to the user account.
    profile2_save($profile);
    $account = user_load($account->uid, TRUE);
    $account->password = $edit['pass'];
    user_save($account);

    return $account->uid;
  }

  public function addUserToGroup($account, $group_nid, $group_manager) {
    og_group('node', $group_nid, [
      'entity_type' => 'user',
      'entity' => $account,
      'membership type' => 'group_membership',
      'state' => OG_STATE_ACTIVE,
    ]);

    if ($group_manager) {
      og_role_grant('node', $group_nid, $account->uid, salto_og_get_admin_rid($group_nid));
    }
  }

}
