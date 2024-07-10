<?php

use Helper\Wissensnetz;

class PostFunctionalCest {

  public function _before(UnitTester $I) {

  }

  public function _after(UnitTester $I) {

  }


  public function testPostPublishingAccess(UnitTester $I) {

    $I->wantTo('check that the view access of publishing states are working correctly');

    $user_member = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'member',
    ]);

    $user_author = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'author',
    ]);

    $group = $I->createGroup($user_author);

    $post_immediate = $I->havePost([
      'Titel' => 'post_immediate',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE
    ]);

    $group_post_immedate = $I->havePost([
      'Titel' => 'group_post_immediate',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE
    ]);

    $post_draft = $I->havePost([
      'Titel' => 'post_draft',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_DRAFT
    ]);

    $group_post_draft = $I->havePost([
      'Titel' => 'group_post_draft',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_DRAFT
    ]);


    $I->completedSetup();

    $I->assertTRUE(node_access('view', $post_immediate, $user_author));
    $I->assertTRUE(node_access('view', $group_post_immedate, $user_author));
    $I->assertTRUE(node_access('view', $post_draft, $user_author));
    $I->assertTRUE(node_access('view', $group_post_draft, $user_author));

    $I->assertTRUE(node_access('view', $post_immediate, $user_member));
    $I->assertTRUE(node_access('view', $group_post_immedate, $user_member));
    $I->assertFALSE(node_access('view', $post_draft, $user_member));
    $I->assertFALSE(node_access('view', $group_post_draft, $user_member));

    $I->expect('publishing a post changes the view access.');

    $post_draft->field_publishing_options[LANGUAGE_NONE][0]['value'] = POST_PUBLISH_IMMEDIATE;
    node_save($post_draft);

    drupal_static_reset();
    $I->assertTRUE(node_access('view', $post_draft, $user_member));

  }

  public function testPostCommunityManagerAccess(UnitTester $I) {

    $I->wantTo('that the community manager have view access to all node from type post');



    $user_author = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'author',
    ]);

    $MANAGER = $I->haveUser([
      'firstname' => 'Inviter',
      'lastname' => microtime(true),
      'role_dosb' => TRUE,
    ]);

    $GROUP = $I->createGroup($user_author);

    $POST_ALL = $I->havePost([
      'Titel' => 'post_immediate',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE
    ]);

    $POST_AUTHORS = $I->havePost([
      'Titel' => 'group_post_immediate',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE
    ]);

    $POST_GROUP = $I->havePost([
      'Titel' => 'post_draft',
      'Inhalt' => "Test Inhalt B1_01",
      'group' => $GROUP->nid,
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
    ]);

    $POST_ORGANISATION = $I->havePost([
      'Titel' => 'group_post_draft',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
    ]);


    $I->completedSetup();

    $I->assertTRUE(node_access('view', $POST_ALL, $MANAGER));
    $I->assertTRUE(node_access('view', $POST_AUTHORS, $MANAGER));
    $I->assertTRUE(node_access('view', $POST_GROUP, $MANAGER));
    $I->assertTRUE(node_access('view', $POST_ORGANISATION, $MANAGER));

    $I->assertTRUE(node_access('update', $POST_ALL, $MANAGER));
    $I->assertTRUE(node_access('update', $POST_AUTHORS, $MANAGER));
    $I->assertTRUE(node_access('update', $POST_GROUP, $MANAGER));
    $I->assertTRUE(node_access('update', $POST_ORGANISATION, $MANAGER));

  }
}
