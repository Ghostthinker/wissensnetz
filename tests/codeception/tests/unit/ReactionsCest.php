<?php

use Helper\Wissensnetz;

class ReactionsCest {

    public function _before(UnitTester $I) {
    }

    public function _after(UnitTester $I) {
    }


    /**
     *
     */
    public function RC2207_ReactionsService(UnitTester $I) {
        $uid1 = time();
        $uid2 = $uid1 + 1;

        $entityid1 = time();
        $entityid2 = $entityid1 + 1;
        $entityid3 = $entityid2 + 1;


        $RS = new ReactionService();

        $RS->saveReaction("clap", $entityid1, "node", $uid1);
        $RS->saveReaction("smile", $entityid1, "node", $uid1);
        $RS->saveReaction("smile", $entityid1, "node", $uid2);
        $RS->saveReaction("clap", $entityid2, "node", $uid1);
        $RS->saveReaction("clap", $entityid3, "node", $uid1);

        $votesEntity1 = $RS->getReactionsByEntity($entityid1, "node");
        $votesUser = $RS->getReactionsByEntityAndUser($entityid1, "node", $uid1);

        $I->assertEquals(count($votesEntity1), 3);
        $I->assertEquals(count($votesUser), 2);
    }
}
