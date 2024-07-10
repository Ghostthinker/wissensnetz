<?php

namespace salto_group;

class GroupDeleteService
{

  private $group;


  public function __construct($group)
  {
    $this->group = $group;
  }

  public function deleteGroupContent(){
    $this->removeUsers();
    $this->deleteOnlineTreffen();
    $this->deletePosts();
    $this->deleteMaterials();
  }


  private function deleteOnlineTreffen(){
    $onlineTreffen = $this->getContentToDeleteFromGroup('online_meeting');
    foreach($onlineTreffen as $treffen){
      node_delete($treffen->entity_id);
    }
  }

  private function deletePosts(){
    $posts = $this->getContentToDeleteFromGroup('post');
    foreach($posts as $post){
      node_delete($post->entity_id);
    }
  }

  private function deleteMaterials(){
    $materials = $this->getContentToDeleteFromGroup('file');
    foreach($materials as $material){
      $file = file_load($material->entity_id);
      if($file){
        file_delete($file);
      }
    }
  }

  private function getContentToDeleteFromGroup($type){
    $group_nid = $this->group->nid;
    $query = db_select('field_data_field_post_collaboration', 'fpc')
      ->fields('fpc', ['entity_id', 'entity_id']);
    $query->leftJoin('og_membership','ogm','ogm.etid = fpc.entity_id');
    $query->condition('ogm.gid', $group_nid);


    $this->checkIfCollaborationNeeded($type,$query);

    if($type == 'file'){
      $query->condition('fpc.entity_type','file');
    }
    else{
      $query->condition('fpc.entity_type','node');
      $query->leftJoin('node','n','n.nid = fpc.entity_id');
      $query->condition('n.type',$type);
    }

    $result = $query->execute()->fetchAll();
    return $result;
  }

  private function removeUsers(){
    $group_nid = $this->group->nid;
    $users = salto_og_get_users_by_og($group_nid);
    foreach($users as $uid => $user){
      $user = user_load($uid);
      salto_og_user_cancel_access($group_nid,$uid,$user);
    }
  }

  private function checkIfCollaborationNeeded($type,&$query){
    if($type != 'online_meeting'){
      $query->condition('fpc.field_post_collaboration_read',SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP);
      $query->condition('fpc.field_post_collaboration_edit',SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP);
    }
  }

}
