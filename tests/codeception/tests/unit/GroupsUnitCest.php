<?php


class GroupsUnitCest {

  public function _before(UnitTester $I) {
  }

  public function _after(UnitTester $I) {
  }


  public function test_groups_delete(UnitTester $I) {

        $I->expect('when i delete a group, all contents within the group are removed');

      $GROUP_AUTHOR = $I->haveUser([
        'firstname' => 'Founder',
        'lastname' => 'tester',
        'mail' => 'jane.author@example.de'
      ]);

      $GROUP_MEMBER1 = $I->haveUser([
        'firstname' => 'Founder',
        'lastname' => 'tester',
        'mail' => 'jane.author@example.de'
      ]);

      $GROUP_MEMBER2 = $I->haveUser([
        'firstname' => 'Founder',
        'lastname' => 'tester',
        'mail' => 'jane.author@example.de'
      ]);

      $GROUP_MEMBER3 = $I->haveUser([
        'firstname' => 'Founder',
        'lastname' => 'tester',
        'mail' => 'jane.author@example.de'
      ]);

      $GROUP = $I->createGroup($GROUP_AUTHOR);
      $GROUP2 = $I->createGroup($GROUP_AUTHOR);

      $I->addMemberToGroup($GROUP_MEMBER1, $GROUP->nid);
      $I->addMemberToGroup($GROUP_MEMBER2, $GROUP->nid);
      $I->addMemberToGroup($GROUP_MEMBER3, $GROUP->nid);
      $I->addMemberToGroup($GROUP_MEMBER3, $GROUP2->nid);

      $ONLINE_MEETING = $I->haveOnlineMeeting([
        'user' => $GROUP_AUTHOR,
        'title' => 'online treffen',
        'group' => $GROUP,
        'startDate' => strtotime('now + 2 hours'),
        'endDate' => strtotime('now + 3 hours'),
        'meeting_status' => 1
      ]);

      $ONLINE_MEETING2 = $I->haveOnlineMeeting([
        'user' => $GROUP_AUTHOR,
        'title' => 'online treffen',
        'group' => $GROUP,
        'startDate' => strtotime('now + 2 hours'),
        'endDate' => strtotime('now + 3 hours'),
        'meeting_status' => 1
      ]);

      $ONLINE_MEETING3 = $I->haveOnlineMeeting([
        'user' => $GROUP_AUTHOR,
        'title' => 'online treffen',
        'group' => $GROUP2,
        'startDate' => strtotime('now + 2 hours'),
        'endDate' => strtotime('now + 3 hours'),
        'meeting_status' => 1
      ]);

      $POST_GROUP_ONLY = $I->havePost([
        'user' => $GROUP_AUTHOR,
        'title' => 'Wird gel??scht',
        'body' => "Test Inhalt 270_05",
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
        'groupAccess' => $GROUP->nid,
      ]);

      $POST_GROUP_ONLY_READ = $I->havePost([
        'user' => $GROUP_AUTHOR,
        'title' => 'Nur Read',
        'body' => "Test Inhalt 270_05",
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'groupAccess' => $GROUP->nid,
      ]);

      $POST_GROUP_ONLY_VIEW = $I->havePost([
        'user' => $GROUP_AUTHOR,
        'title' => 'Nur View',
        'body' => "Test Inhalt 270_05",
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
        'groupAccess' => $GROUP->nid,
      ]);

      $POST_GROUP_PUBLIC = $I->havePost([
        'user' => $GROUP_AUTHOR,
        'title' => 'Gruppe Public',
        'body' => "Test Inhalt 270_05",
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'groupAccess' => $GROUP->nid,
      ]);

      $POST_NO_GROUP = $I->havePost([
        'user' => $GROUP_AUTHOR,
        'title' => 'keine Gruppe',
        'body' => "Test Inhalt 270_05",
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      ]);

      $MATERIAL_GROUP_ONLY = $I->haveMaterial([
        'user' => $GROUP_AUTHOR,
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
      ]);

      $MATERIAL_ONLY_READ = $I->haveMaterial([
        'user' => $GROUP_AUTHOR,
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      ]);

      $MATERIAL_ONLY_VIEW = $I->haveMaterial([
        'user' => $GROUP_AUTHOR,
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
      ]);

      $MATERIAL_PUBLIC = $I->haveMaterial([
        'user' => $GROUP_AUTHOR,
        'group' => $GROUP,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      ]);

      $MATERIAL_NO_GROUP = $I->haveMaterial([
        'user' => $GROUP_AUTHOR,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      ]);



      $I->completedSetup();

      $usersInGroup = salto_og_get_users_by_og($GROUP->nid);
      $I->assertNotEmpty($usersInGroup);

      node_delete($GROUP->nid);


      $I->expect('that the online meeting nodes are deleted from the group');

      $I->checkAK('WN-103','AK 5: Online-Treffen werden alle gel??scht.');

      $ONLINE_MEETING = node_load($ONLINE_MEETING->nid,NULL,TRUE);
      $ONLINE_MEETING2 = node_load($ONLINE_MEETING2->nid,NULL,TRUE);
      $ONLINE_MEETING3 = node_load($ONLINE_MEETING3->nid,NULL,TRUE);
      $I->assertEmpty($ONLINE_MEETING);
      $I->assertEmpty($ONLINE_MEETING2);
      $I->assertNotEmpty($ONLINE_MEETING3);

      $I->expect('that all users will be removed from the group');

      $I->checkAK('WN-103','AK 6: Alle Gruppenmitgliedschaften werden einfach gel??scht und es ist keine Folgeaktivit??t notwendig!');

      $GROUP = node_load($GROUP->nid,NULL,TRUE);
      $usersInGroup = salto_og_get_users_by_og($GROUP->nid);
      $I->assertEmpty($usersInGroup);

      $I->expect('that only the POST_GROUP_ONLY will be deleted when deleting the group');


      $POST_GROUP_ONLY = node_load($POST_GROUP_ONLY->nid,NULL,TRUE);
      $POST_GROUP_ONLY_READ = node_load($POST_GROUP_ONLY_READ->nid,NULL,TRUE);
      $POST_GROUP_ONLY_VIEW = node_load($POST_GROUP_ONLY_VIEW->nid,NULL,TRUE);
      $POST_GROUP_PUBLIC = node_load($POST_GROUP_PUBLIC->nid,NULL,TRUE);
      $POST_NO_GROUP = node_load($POST_NO_GROUP->nid,NULL,TRUE);


      $MATERIAL_GROUP_ONLY = file_load($MATERIAL_GROUP_ONLY->fid);
      $MATERIAL_ONLY_READ = file_load($MATERIAL_ONLY_READ->fid);
      $MATERIAL_ONLY_VIEW = file_load($MATERIAL_ONLY_VIEW->fid);
      $MATERIAL_PUBLIC = file_load($MATERIAL_PUBLIC->fid);

      $I->checkAK('WN-103','AK 3: Beitr??ge und Dateien mit den folgenden Zugriffen werden gel??scht wenn beides zutrifft');

      $I->assertEmpty($POST_GROUP_ONLY);
      $I->assertNotEmpty($POST_GROUP_ONLY_READ);
      $I->assertNotEmpty($POST_GROUP_ONLY_VIEW);
      $I->assertNotEmpty($POST_GROUP_PUBLIC);

      $I->assertEmpty($MATERIAL_GROUP_ONLY);
      $I->assertNotEmpty($MATERIAL_ONLY_READ);
      $I->assertNotEmpty($MATERIAL_ONLY_VIEW);
      $I->assertNotEmpty($MATERIAL_PUBLIC);


      $I->expect('that POST_GROUP_ONLY_READ, $POST_GROUP_ONLY_VIEW and $POST_GROUP_PUBLIC will be moved to the community area');

      $I->checkAK('WN-103','AK 4: Beitr??ge und Dateien mit allen anderen Zugriffen bleiben vorhanden, jedoch dann ohne Gruppenzugeh??rigkeit (aber im Gemeinschaftsbereich einsortiert)');

     $I->assertEmpty($POST_GROUP_ONLY->field_og_group);
     $I->assertEmpty($POST_GROUP_ONLY_VIEW->field_og_group);
     $I->assertEmpty($POST_GROUP_PUBLIC->field_og_group);

      $I->assertEmpty($MATERIAL_ONLY_READ->field_og_group);
      $I->assertEmpty($MATERIAL_ONLY_VIEW->field_og_group);
      $I->assertEmpty($MATERIAL_PUBLIC->field_og_group);

  }
}
