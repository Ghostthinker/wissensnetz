<?php

class OnlyIntegrationCleanupCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) { }


  /**
   * @skip only for blanco; no active
   *
   * get user ids by og and groups by users
   * @param UnitTester $I
   * @throws Exception
   */
  public function testCleanup(UnitTester $I) {
    return true;

    $I->expect('Test: function salto_debug_blank_cleanup($keepOgs, $keepTypes, $keepNids = [])');
    $keepOgs =[BlankCleanup::OG_LSB_NIEDERSACHSEN_ID, BlankCleanup::OG_GHOSTTHINKER_ID];
    $keepNids = [];
    $keepTypes = ['help','page','feed'];

    $blanco = \Helper\Bildungsnetz::getBlankCleanup();
    $repo = \Helper\Bildungsnetz::getNodeRepository();

    $ugs = [];
    foreach ($keepOgs as $ogNid) {
      $ugs = salto_organisation_get_untergliederungen($ogNid);
    }

    $keepOgs = array_unique(array_merge($keepOgs, $ugs));
    $keepUsers = $blanco->getAllUserIds($keepOgs);
    $keepGroups = $repo->getGroupIdsByUsers($keepUsers);
    $keepNodes = $repo->getNodeIdsByUsers($keepUsers);
    $keepNodeTypes = $repo->getNodeIdsByType(array_merge($keepTypes, ['organisation']));

    $I->expectTo('Delete nodes is ok, without ogs!!!');
    $nodes = array_unique(array_merge($keepNodeTypes, $keepNodes, $keepGroups, $keepNids));
    $I->assertTrue($blanco->deleteNodes($nodes, TRUE));
    $I->assertEquals(0, count($repo->getNodeIdsWithout($nodes)));

    $I->expectTo('Delete users is ok!!!');
    $keepUsers[] = 0;
    $I->assertTrue($blanco->executeCleanUserData($keepUsers));

    $I->expectTo('Delete organisations now!!!');
    cache_clear_all();
    $keepNodeTypes = $repo->getNodeIdsByType($keepTypes);
    $nodes = array_unique(array_merge($keepNodeTypes, $keepNodes, $keepGroups, $keepNids));
    $I->assertTrue($blanco->deleteNodes($nodes, TRUE));

    $I->expectTo('Truncate tables!!!');
    $I->assertTrue($blanco->truncateTables());

    $I->expect('Test: function salto_debug_blank_cleanup_node_types($types)');
    $types = [
      'ausbildungskonzept',
      'book',
      'earemote',
      'statistics-daily',
      'weiterbildungsmassnahme'
    ];

    $I->expectTo('Delete node types is ok!!!');
    $I->assertTrue($blanco->deleteNodesByTypes($types));

    salto_delete_content_types($types);

    $I->assertEquals(0, count($repo->getNodeIdsByType($types)));
  }

}
