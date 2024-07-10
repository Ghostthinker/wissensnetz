<?php

use Helper\Wissensnetz;

class OnlineMeetingFunctionalCest {

  public function _before(UnitTester $I) {
    variable_set('online_meeting_enabled', TRUE);
  }

  public function _after(UnitTester $I) {
    variable_set('online_meeting_enabled', FALSE);
  }


  public function testGetActiveDialogs(UnitTester $I) {

    $I->wantTo('check the get active online meetings function');

    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'statistic',
    ]);

    $og = $I->createOrganisation('LicenseStatisticOG', [
        'body' => 'dummy statistic og',
        'parent' => NULL,
        'language' => 'en',
      ]
    );
    $I->addMemberToOrganisation($user, $og, [SALTO_OG_ROLE_MANAGER_RID]);

    $group = $I->createGroup($user);

    //upcoming
    for ($i = 1; $i <= 3; $i++) {
      $I->haveOnlineMeeting([
        'user' => $user,
        'title' => 'past meeting' . $i,
        'group' => $group,
        'startDate' => strtotime('now - ' . ($i + 1) . ' hours'),
        'endDate' => strtotime('now - ' . $i . ' hour'),
        'meeting_status' => 1,
      ]);
    }
    //past event

    for ($i = 1; $i <= 3; $i++) {
      $I->haveOnlineMeeting([
        'user' => $user,
        'title' => 'upcoming meeting' . $i,
        'group' => $group,
        'startDate' => strtotime('now +' . $i . ' hours'),
        'endDate' => strtotime('now + ' . ($i + 1) . ' hours'),
      ]);
    }
    //recurring
    for ($i = 1; $i <= 3; $i++) {
      $I->haveOnlineMeeting([
        'user' => $user,
        'title' => 'recurring meeting' . $i,
        'group' => $group,
        'recurring_meeting' => 1,
      ]);
    }

    $I->haveOnlineMeeting([
      'user' => $user,
      'title' => 'recurring meeting5',
      'group' => $group,
      'recurring_meeting' => 1,
      'meeting_status' => 1,
    ]);

    $I->completedSetup();

    $I->assertCount(4, Wissensnetz::getActiveDialogs($group->nid));
  }

  public function testOnlineMeetingAccess(UnitTester $I) {

    $I->wantTo('check the access of the online meeting');


    $O1 = $I->createOrganisation('OnlineMeetingOrganisation_1', [
        'body' => 'O1',
        'parent' => NULL,
        'language' => 'en',
      ]
    );

    $G1_M1_MANAGER = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'manager',
    ]);

    $G1_M2_AUTOR = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting',
    ]);

    $G1_M3 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting_no_author',
    ]);

    $U4 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting_no_author',
    ]);

    $U5_O2 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting_no_author',
    ]);


    $G1 = $I->createGroup($G1_M1_MANAGER);

    $I->addMemberToOrganisation($G1_M2_AUTOR, $O1, [SALTO_OG_ROLE_MANAGER_RID]);
    $I->addMemberToOrganisation($U5_O2, $O1, [SALTO_OG_ROLE_FURTHER_MEMBER_RID]);

    $I->addMemberToGroup($G1_M1_MANAGER, $G1->nid);
    $I->addMemberToGroup($G1_M2_AUTOR, $G1->nid);
    $I->addMemberToGroup($G1_M3, $G1->nid);

    $OM_1 = $I->haveOnlineMeeting([
      'user' => $G1_M2_AUTOR,
      'title' => 'OM_1',
      'group' => $G1,
      'startDate' => strtotime('now + 2 hours'),
      'endDate' => strtotime('now + 3 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ]);

    $OM_2 = $I->haveOnlineMeeting([
      'user' => $G1_M2_AUTOR,
      'title' => 'OM_2',
      'group' => $G1,
      'startDate' => strtotime('now + 2 hours'),
      'endDate' => strtotime('now + 3 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION,
    ]);

    $OM_3 = $I->haveOnlineMeeting([
      'user' => $G1_M2_AUTOR,
      'title' => 'OM_3',
      'group' => $G1,
      'startDate' => strtotime('now + 2 hours'),
      'endDate' => strtotime('now + 3 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
    ]);

    $OM_4 = $I->haveOnlineMeeting([
      'user' => $G1_M2_AUTOR,
      'title' => 'OM_4',
      'group' => $G1,
      'startDate' => strtotime('now + 2 hours'),
      'endDate' => strtotime('now + 3 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
    ]);

    $I->completedSetup();

    //Alle WN Mitglieder
    $I->assertTRUE(node_access('view', $OM_1, $G1_M1_MANAGER));
    $I->assertTRUE(node_access('view', $OM_1, $G1_M2_AUTOR));
    $I->assertTRUE(node_access('view', $OM_1, $G1_M3));
    $I->assertTRUE(node_access('view', $OM_1, $U4));
    $I->assertTRUE(node_access('view', $OM_1, $U5_O2));

    //Nur Organisationen der Autoren
    $I->assertFALSE(node_access('view', $OM_2, $G1_M1_MANAGER));
    $I->assertTRUE(node_access('view', $OM_2, $G1_M2_AUTOR));
    $I->assertFALSE(node_access('view', $OM_2, $G1_M3));
    $I->assertFALSE(node_access('view', $OM_2, $U4));
    $I->assertTRUE(node_access('view', $OM_2, $U5_O2));

    //Nur Autoren und Gruppenmanager
    $I->assertTRUE(node_access('view', $OM_3, $G1_M1_MANAGER)); //Failed https://ghostthinker.atlassian.net/browse/WN-82
    $I->assertTRUE(node_access('view', $OM_3, $G1_M2_AUTOR));
    $I->assertFALSE(node_access('view', $OM_3, $G1_M3));
    $I->assertFALSE(node_access('view', $OM_3, $U4));
    $I->assertFALSE(node_access('view', $OM_3, $U5_O2));

    //Nur Gruppenmitglieder
    $I->assertTRUE(node_access('view', $OM_4, $G1_M1_MANAGER));
    $I->assertTRUE(node_access('view', $OM_4, $G1_M2_AUTOR));
    $I->assertTRUE(node_access('view', $OM_4, $G1_M3));
    $I->assertFALSE(node_access('view', $OM_4, $U4));
    $I->assertFALSE(node_access('view', $OM_4, $U5_O2));
  }

  public function testGetDialogsFromCommunityArea(UnitTester $I) {

    $I->wantTo('that i get the next pending dialog from the community area');

    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'statistic',
    ]);

    $drupalUser = \Wissensnetz\User\DrupalUser::make($user->uid);

    $group = $I->createGroup($user);

    $I->haveOnlineMeeting([
      'user' => $user,
      'title' => 'Online Treffen Gruppe Öffentlich',
      'group' => $group,
      'startDate' => strtotime('now + 5 hours'),
      'endDate' => strtotime('now + 6 hour'),
      'meeting_status' => 1,
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ]);

    $I->haveOnlineMeeting([
      'user' => $user,
      'title' => 'Online Treffen Gruppe Only Authors',
      'group' => $group,
      'startDate' => strtotime('now + 1 hours'),
      'endDate' => strtotime('now + 2 hour'),
      'meeting_status' => 1,
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
    ]);

    $I->haveOnlineMeeting([
      'user' => $user,
      'title' => 'Online Treffen Gruppe Only Group',
      'group' => $group,
      'startDate' => strtotime('now + 1 hours'),
      'endDate' => strtotime('now + 2 hour'),
      'meeting_status' => 1,
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
    ]);

    $I->haveOnlineMeeting([
      'user' => $user,
      'title' => 'Online Treffen Gemeinschaftsbereich öffentlich',
      'startDate' => strtotime('now + 6 hours'),
      'endDate' => strtotime('now + 7 hour'),
      'meeting_status' => 1,
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ]);

    $I->haveOnlineMeeting([
      'user' => $user,
      'title' => 'Online Treffen Gemeinschaftsbereich Privat',
      'startDate' => strtotime('now + 7 hours'),
      'endDate' => strtotime('now + 8 hour'),
      'meeting_status' => 1,
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
    ]);


    $I->assertCount(3, Wissensnetz::getActiveDialogs($group->nid));

    $onlineTreffenService = new \salto_core\service\OnlineTreffenService();
    $upcomingDialog = $onlineTreffenService->getLatestDialogByUser($drupalUser);
    $I->assertEquals('upcoming target', $upcomingDialog->getTitle());

  }


}
