<?php

namespace salto_core\migration;


use stdClass;
use Wissensnetz\User\DrupalUser;

class MigrationService {

  private $edubreakAPI;

  private $userMapping = [];

  private $groupMapping = [];

  public function __construct($options) {
    $this->edubreakAPI = new EdubreakAPIClient($options);
  }

  public function migrate($domainId, $dryRun = TRUE, $domain_courses = []) {
    $migrationArray['groups'] = $this->getGroupsByDomainId($domainId, $domain_courses);
    $migrationArray['users'] = $this->getUsersAndMemberships($migrationArray['groups']);

    if ($dryRun) {
      return $migrationArray;
    }

    $this->migrateGroups($migrationArray['groups']);
    $this->migrateUsers($migrationArray['users']);
    $this->addUsersToGroup($migrationArray['users']);

    $migrationArray['group_content'] = $this->getGroupContent($migrationArray['groups']);

    $this->migrateGroupContent($migrationArray['group_content']);
  }

  private function getGroupsByDomainId($domainId, $domain_courses) {
    $ogList = $this->edubreakAPI->ogList();
    $filterd = array_filter($ogList, function ($og) use ($domainId, $domain_courses) {

      if(!empty($domain_courses)){
        if(!in_array($og['og_id'],$domain_courses)){
          return FALSE;
        }
      }

      return $og['domain_id'] == $domainId;
    });

    $groups = [];
    foreach ($filterd as $filter) {
      $gid = $filter['og_id'];
      $ebGroup = $this->edubreakAPI->getOg($gid);

      $groups[$filter['og_id']] = [
        'title' => $ebGroup['label'],
        'body' => $ebGroup['description'],
        'selective' => $ebGroup['membership_mode'],
        'type' => $ebGroup['type'],
      ];
    }
    return $groups;
  }

  private function getNewsByGroupId($ogList){
    $newsDetails = [];
    foreach ($ogList as $ebNid => $og) {
      $news = $this->edubreakAPI->getNews($ebNid);

      $og_id = $this->groupMapping[$ebNid];


      foreach($news['items'] as $item){
        $newsDetails[$og_id][$item['id']]['id'] = $item['id'];
        $newsDetails[$og_id][$item['id']]['og_id'] = $og_id;
        $newsDetails[$og_id][$item['id']]['author'] = $this->userMapping[$item['author']['id']];
        $newsDetails[$og_id][$item['id']]['title'] = $item['title'];
        $newsDetails[$og_id][$item['id']]['body'] = $item['body'];
        $newsDetails[$og_id][$item['id']]['created'] = $item['created'];
        $newsDetails[$og_id][$item['id']]['comments'] = [];
        $newsDetails[$og_id][$item['id']]['type'] = 'news';
        $newsDetails[$og_id][$item['id']]['attachments'] = $item['attachments'];
        $newsComments = $this->edubreakAPI->getNewsComments($item['id']);

        foreach($newsComments['items'] as $comment){
          $newsDetails[$og_id][$item['id']]['comments'][$comment['id']]['id'] = $comment['id'];
          $newsDetails[$og_id][$item['id']]['comments'][$comment['id']]['body'] = $comment['body'];
          $newsDetails[$og_id][$item['id']]['comments'][$comment['id']]['created'] = $comment['created'];
          $newsDetails[$og_id][$item['id']]['comments'][$comment['id']]['author'] = $this->userMapping[$comment['author']['id']];
        }
      }
    }
    return $newsDetails;
  }

  private function getBlogsByGroupId($ogList) {
    $blogDetails = [];
    foreach ($ogList as $ebNid => $og) {
      $content = $this->edubreakAPI->getBlog($ebNid);
      $og_id = $this->groupMapping[$ebNid];

      foreach($content['items'] as $item){
        $blogDetails[$og_id][$item['id']]['id'] = $item['id'];
        $blogDetails[$og_id][$item['id']]['og_id'] = $og_id;
        $blogDetails[$og_id][$item['id']]['author'] = $this->userMapping[$item['author']['id']];
        $blogDetails[$og_id][$item['id']]['title'] = $item['title'];
        $blogDetails[$og_id][$item['id']]['body'] = $item['body'];
        $blogDetails[$og_id][$item['id']]['created'] = $item['created'];
        $blogDetails[$og_id][$item['id']]['comments'] = [];
        $blogDetails[$og_id][$item['id']]['type'] = $item['type'];
        $blogDetails[$og_id][$item['id']]['attachments'] = $item['attachments'];

        $contentComments = $this->edubreakAPI->getContentComments($item['id']);

        foreach($contentComments['items'] as $comment){
          $blogDetails[$og_id][$item['id']]['comments'][$comment['id']]['id'] = $comment['id'];
          $blogDetails[$og_id][$item['id']]['comments'][$comment['id']]['body'] = $comment['body'];
          $blogDetails[$og_id][$item['id']]['comments'][$comment['id']]['created'] = $comment['created'];
          $blogDetails[$og_id][$item['id']]['comments'][$comment['id']]['author'] = $this->userMapping[$comment['author']['id']];
        }
      }
    }
    return $blogDetails;
  }

  private function getVideosByGroupId($ogList) {
    $videoDetails = [];
    foreach ($ogList as $ebNid => $og) {
      $videos = $this->edubreakAPI->getVideo($ebNid);

      $og_id = $this->groupMapping[$ebNid];

      foreach($videos['items'] as $item){

        $videoDetails[$og_id][$item['id']]['id'] = $item['id'];
        $videoDetails[$og_id][$item['id']]['og_id'] = $og_id;
        $videoDetails[$og_id][$item['id']]['author'] = $this->userMapping[$item['author']['id']] ?? USER_DELETED_UID;
        $videoDetails[$og_id][$item['id']]['title'] = $item['title'];
        $videoDetails[$og_id][$item['id']]['created'] = $item['created'];
        $videoDetails[$og_id][$item['id']]['views'] = $item['views'];
        $videoDetails[$og_id][$item['id']]['visibility'] = $item['visibility']['edubreak_access'];
        $videoDetails[$og_id][$item['id']]['streamingId'] = $item['streamingId'];
        $videoDetails[$og_id][$item['id']]['type'] = 'video';

        $videocomments_data = $this->edubreakAPI->getVideoComments($item['id']);

        $videocomments = [];
        $numComments = count($videocomments_data['data']);

        if (!empty($videocomments_data['data'])) {
          for ($i = 0; $i < $numComments; $i++) {

            if (!empty($videocomments_data['data'][$i]['commentId'])) {
              continue;
            }
            $userId = $this->userMapping[$videocomments_data['data'][$i]['user']['id']] ?? USER_DELETED_UID;
            $videocomments_data['data'][$i]['user']['id'] = $userId;
            $replies = [];
            foreach ($videocomments_data['data'][$i]['comments'] as &$comment) {
              $userIdReply = $this->userMapping[$comment['user']['id']];
              if (!empty($userIdReply)) {
                $comment['user']['id'] = $userIdReply;
                $replies[] = $comment;
              }
            }
            $videocomments_data['data'][$i]['comments'] = $replies;
            $videocomments[] = $videocomments_data['data'][$i];
          }
        }
        $videoDetails[$og_id][$item['id']]['videocomments'] = $videocomments;
      }
    }
    return $videoDetails;
  }

  private function getCmapsByGroupId($ogList) {
    $cmapDetails = [];
    foreach ($ogList as $ebNid => $og) {
      $content = $this->edubreakAPI->getCmap($ebNid);
      $og_id = $this->groupMapping[$ebNid];

      foreach($content['items'] as $item){

        if (empty($item['file'][0]['fid'])){
          watchdog('salto_files', "file %title has no fid and may be a web concept map, which can not be migrated for og_nid: %og_nid", ["%title" => $item['title'], "%og_nid" => $item['id']]);
          continue;
        }

        $cmapDetails[$og_id][$item['id']]['id'] = $item['id'];
        $cmapDetails[$og_id][$item['id']]['og_id'] = $og_id;
        $cmapDetails[$og_id][$item['id']]['author'] = $this->userMapping[$item['author']['id']] ?? USER_DELETED_UID;
        $cmapDetails[$og_id][$item['id']]['title'] = $item['title'];
        $cmapDetails[$og_id][$item['id']]['filename'] = $item['file'][0]['filename'];
        $cmapDetails[$og_id][$item['id']]['description'] = $item['description'];
        $cmapDetails[$og_id][$item['id']]['created'] = $item['created'];
        $cmapDetails[$og_id][$item['id']]['comments'] = [];
        $cmapDetails[$og_id][$item['id']]['type'] = $item['type'];
        $cmapDetails[$og_id][$item['id']]['item_url'] = $item['file'][0]['item_url'];
        $cmapDetails[$og_id][$item['id']]['tags'] = $item['tags'];

        $contentComments = $this->edubreakAPI->getContentComments($item['id']);

        $cmapDetails[$og_id][$item['id']]['entity_type'] = 'file';

        foreach($contentComments['items'] as $comment){
          $cmapDetails[$og_id][$item['id']]['comments'][$comment['id']]['id'] = $comment['id'];
          $cmapDetails[$og_id][$item['id']]['comments'][$comment['id']]['body'] = $comment['body'];
          $cmapDetails[$og_id][$item['id']]['comments'][$comment['id']]['created'] = $comment['created'];
          $cmapDetails[$og_id][$item['id']]['comments'][$comment['id']]['author'] = $this->userMapping[$comment['author']['id']];
        }
      }
    }

    return $cmapDetails;
  }

  private function getFilesByGroupId($ogList) {
    $filesDetails = [];
    foreach ($ogList as $ebNid => $og) {
      $filetree = $this->edubreakAPI->getFileTree($ebNid);

      $og_id = $this->groupMapping[$ebNid];

      $content = [];
      $this->convertFiletreeToMaterialContentRecursive($filetree, $og_id, $content);

      foreach($content['items'] as $item){

        $filesDetails[$og_id][$item['id']]['id'] = $item['id'];
        $filesDetails[$og_id][$item['id']]['og_id'] = $og_id;
        $filesDetails[$og_id][$item['id']]['author'] = $this->userMapping[$item['author']['id']] ?? USER_DELETED_UID;
        $filesDetails[$og_id][$item['id']]['title'] = $item['title'];
        $filesDetails[$og_id][$item['id']]['filename'] = $item['file'][0]['filename'];
        $filesDetails[$og_id][$item['id']]['description'] = $item['description'];
        $filesDetails[$og_id][$item['id']]['created'] = $item['created'];
        $filesDetails[$og_id][$item['id']]['comments'] = [];
        $filesDetails[$og_id][$item['id']]['type'] = $item['type'];
        $filesDetails[$og_id][$item['id']]['item_url'] = $item['file'][0]['item_url'];
        $filesDetails[$og_id][$item['id']]['entity_type'] = 'file';
        $filesDetails[$og_id][$item['id']]['folder_tid'] = $item['folder_tid'];

      }
    }

    return $filesDetails;
  }



  private function getUsersAndMemberships($ogList) {
    $userDetails = [];
    foreach ($ogList as $og_id => $item) {
      $memberships = $this->edubreakAPI->ogMembership($og_id);

      foreach ($memberships as $membership) {

        $uid = $membership['id'];
        if (empty($userDetails[$uid])) {
          $userDetails[$uid]['uid'] = $uid;
          $userDetails[$uid]['mail'] = $membership['mail'];
          $userDetails[$uid]['picture_url'] = $membership['picture_url'];
          $userDetails[$uid]['firstname'] = $membership['name']['firstname'];
          $userDetails[$uid]['lastname'] = $membership['name']['lastname'];
          $userDetails[$uid]['is_campus_manager'] = $membership['isCampusManager'];
          $userDetails[$uid]['type'] = 'user';
        }

        $isGroupManager = array_filter($membership['roles'], function ($role) {
          return $role['id'] == 3;
        });

        $userDetails[$uid]['groups'][$og_id]['group_manager'] = !empty($isGroupManager);
      }
    }
    return $userDetails;
  }

  private function migrateGroups($groups) {
    global $user;
    foreach ($groups as $ebNid => $group) {
      $nid = $this->migrateContent($group);
      $this->groupMapping[$ebNid] = $nid;
      //Remove the user who runs the script, because he created the group he will become automatic member
      og_ungroup('node', $nid, 'user', $user->uid);
    }
  }



  private function migrateUsers($users) {
    foreach ($users as $ebUid => $user) {
      $uid = $this->migrateContent($user);
      $this->userMapping[$ebUid] = $uid;
    }
  }

  private function migrateContent($content) {
    try {
      $contentWrapper = $this->getContentWrapper(($content['type']));
      return $contentWrapper->create($content);
    } catch (\Exception $e) {
      watchdog_exception('migration', $e);
      return NULL;
    }

  }

  private function addUsersToGroup($users) {
    $contentWrapper = $this->getContentWrapper('user');
    foreach ($users as $user) {
      $account = user_load($this->userMapping[$user['uid']]);
      foreach ($user['groups'] as $groupNid => $groupManager) {
        $contentWrapper->addUserToGroup($account, $this->groupMapping[$groupNid], $groupManager['group_manager'] );
      }
    }
  }

  private function getContentWrapper($type){
    return ContentFactory::getWrapper($type);
  }

  private function migrateGroupContent($groupContent) {
    global $user;
    foreach ($groupContent as $ebNid => $content) {

      foreach($content as $item){
        $entity = $this->migrateContent($item);
        if (!empty($item['comments'])){
          if (!empty($entity->fid)){
            $file_node = salto_files_get_comment_node($entity);
            $nid = $file_node->nid;
          }else{
            $nid = $entity->nid;
          }
          if (!empty($nid)){
            $this->migrateContentComments($item['comments'], $nid);
          }
        }
        $this->groupMapping[$ebNid] = $nid;
      }
    }
  }


  private function getGroupContent($groups) {
    $groupContent = [];

    $newsContent = $this->getNewsByGroupId($groups);
    foreach($newsContent as $og_id => $news ){
      foreach($news as $nid => $item){
        $groupContent[$og_id][$nid] = $item;
      }
    }

    $blogContent = $this->getBlogsByGroupId($groups);
    foreach($blogContent as $og_id => $blog ){
      foreach($blog as $nid => $item){
        $groupContent[$og_id][$nid] = $item;
      }
    }

    $videoContent = $this->getVideosByGroupId($groups);
    foreach($videoContent as $og_id => $video ){
      foreach($video as $nid => $item){
        $groupContent[$og_id][$nid] = $item;
      }
    }

    $cmapContent = $this->getCmapsByGroupId($groups);
    foreach($cmapContent as $og_id => $cmap ){
      foreach($cmap as $nid => $item){
        $groupContent[$og_id][$nid] = $item;
      }
    }

    $filesContent = $this->getFilesByGroupId($groups);
    foreach($filesContent as $og_id => $file ){
      foreach($file as $nid => $item){
        $groupContent[$og_id][$nid] = $item;
      }
    }


    return $groupContent;
  }


  public function migrateContentComments($comments, $nid){

    foreach($comments as $comment){

      try {
        $user = DrupalUser::make($comment['author']);
      } catch (\Exception $e) {
        $user = new stdClass();
        $user->uid = USER_DELETED_UID;
        $user->realname = variable_get('deleted-user', t('deleted user'));
      }

      $comment = (object) [
        'nid' => $nid,
        'pid' => 0,
        'uid' => $user->uid ?? $user->getUid(),
        'created' => strtotime($comment['created']),
        'language' => LANGUAGE_NONE,
        'is_anonymous' => 0,
        'status' => COMMENT_PUBLISHED,
        'subject' => '',
        'comment_body' => [
          LANGUAGE_NONE => [
            0 => [
              'value' => $comment['body'],
              'format' => 'plain_text',
            ],
          ],
        ],
      ];

      comment_submit($comment);

      comment_save($comment);

      comment_load($comment->cid);

    }
  }

  public static function importAttachment($remote_url, $new_file_name, $desitinationPath = 'private://') {
    $image_data = file_get_contents($remote_url);
    $picture_url_parsed = parse_url($remote_url);
    $picture_url_info = pathinfo($picture_url_parsed['path']);
    $extension = $picture_url_info['extension'];

    $file = file_save_data($image_data, $desitinationPath . $new_file_name . '.' . $extension, FILE_EXISTS_RENAME);
    image_path_flush($file->uri);
    return $file;
  }

  private function convertFiletreeToMaterialContentRecursive($filetree, $og_id, &$content, $parent_tid = NULL) {

    $vocabulary = 'group_category_materials_' . $og_id;

    $this->addFileToContent($filetree['files'], $content, $parent_tid);

    if (isset($filetree['folders'])) {
      foreach ($filetree['folders'] as $foldername => $folder) {
        $term = new stdClass();
        $term->name = $foldername;
        $term->vid = taxonomy_vocabulary_machine_name_load($vocabulary)->vid;
        $term->parent = $parent_tid;
        taxonomy_term_save($term);
        $this->convertFiletreeToMaterialContentRecursive($folder, $og_id,$content,  $term->tid);
      }
    }


  }

  private function addFileToContent($files, &$content, $term_id) {
    if (isset($files)) {
      foreach ($files as $file) {

        $content['items'][$file['fid']]['id'] = $file['fid'];
        $content['items'][$file['fid']]['author']['id'] = $file['uid'];
        $content['items'][$file['fid']]['title'] = $file['filename'];
        $content['items'][$file['fid']]['description'] = '';
        $content['items'][$file['fid']]['type'] = 'cmap';
        $content['items'][$file['fid']]['file'][0]['filename'] = $file['filename'];
        $content['items'][$file['fid']]['file'][0]['item_url'] = $file['fileUrl'];
        $content['items'][$file['fid']]['folder_tid'] = $term_id;
        $content['items'][$file['fid']]['created'] = $file['created'];
      }
    }
  }

}
