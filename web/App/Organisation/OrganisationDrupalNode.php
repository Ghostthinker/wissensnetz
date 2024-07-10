<?php

namespace Wissensnetz\Organisation;

use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\User\DrupalUser;

class OrganisationDrupalNode extends DrupalNode {

  public function addUserToOrganisation(DrupalUser $drupalUser, $role_id = NULL){
    $og_membership = og_membership_create('node', $this->getNid(), 'user', $drupalUser->getUid(), 'field_user_organisations', ['state' => 1]);
    $og_membership->save();
    if($role_id){
      og_role_grant('node', $this->getNid(), $drupalUser->getUid(), $role_id);
    }

    og_invalidate_cache();
  }

  public function removeUserFromOrganisation(DrupalUser $drupalUser){
    $og_membership = og_get_membership('node', $this->getNid(), 'user', $drupalUser->getUid());
    og_membership_delete($og_membership->id);
    og_invalidate_cache();
  }

  public function updateUserPosition(DrupalUser $drupalUser, $positions){
    $og_membership = og_get_membership('node', $this->getNid(), 'user', $drupalUser->getUid());
    $og_membership->field_organisation_position = $positions;
    $og_membership->save();
  }

}

