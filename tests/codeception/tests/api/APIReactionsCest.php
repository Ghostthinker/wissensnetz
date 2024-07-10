<?php

class APIReactionsCest {
    public function _before(ApiTester $I) {
      \Helper\Wissensnetz::clearFlood();
    }

    public function _after(ApiTester $I) {
      \Helper\Wissensnetz::clearFlood();

    }

  /**
   * @skip due api testing
   * @param \ApiTester $I
   *
   * @return void
   */
    public function testAccessDeniedCallbackNegative(ApiTester $I) {

        $microTime = microtime(true);

        $UserAuthor = $I->haveUser([
                'firstname' => 'author',
                'lastname' => $microTime,
        ]);
        $UserNoAccess = $I->haveUser([
                'firstname' => 'co author',
                'lastname' => $microTime,
        ]);

        $accept_type = 'json';
        $post_node = $I->havePost([
                'user' => $UserAuthor,
                'categorie' => THEMENFELD_GESUNDHEIT,
                'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
        ]);

        //$I->amHttpAuthenticated($UserNoAccess->name, $UserNoAccess->password);

        $nid = $post_node->nid;
        $I->sendPOST('api/reactions/node/' . $nid);
        $I->seeResponseCodeIs(403);
    }

    public function testAccessDeniedCallbackPositive(ApiTester $I) {
        $microTime = microtime(true);

        $UserAuthor = $I->haveUser([
                'firstname' => 'author',
                'lastname' => $microTime,
        ]);
        $UserNoAccess = $I->haveUser([
                'firstname' => 'co author',
                'lastname' => $microTime,
        ]);

        $accept_type = 'json';
        $post_node = $I->havePost([
                'user' => $UserAuthor,
                'categorie' => THEMENFELD_GESUNDHEIT,
                'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        ]);

        $I->amHttpAuthenticated($UserNoAccess->name, $UserNoAccess->password);

        $nid = $post_node->nid;
        $I->sendPOST('api/reactions/node/' . $nid);
        $I->seeResponseCodeIs(200);
    }

  /**
   * @skip due api testing
   * @param \ApiTester $I
   *
   * @return void
   */
  public function testAccessDeniedFileCallbackNegative(ApiTester $I) {
    $microTime = microtime(true);

    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);
    $UserNoAccess = $I->haveUser([
      'firstname' => 'co author',
      'lastname' => $microTime,
    ]);

    $accept_type = 'json';
    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => THEMENFELD_GESUNDHEIT_MATERIAL,
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
    ]);


    # $I->amHttpAuthenticated($UserNoAccess->name, $UserNoAccess->password);

    $fid = $MATERIAL->fid;
    $I->sendPOST('api/reactions/file/' . $fid);
    $I->seeResponseCodeIs(403);
  }

  public function testAccessDeniedFileCallbackPositive(ApiTester $I) {
    $microTime = microtime(true);

    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);
    $UserNoAccess = $I->haveUser([
      'firstname' => 'co author',
      'lastname' => $microTime,
    ]);

    $accept_type = 'json';
    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => THEMENFELD_GESUNDHEIT_MATERIAL,
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
    ]);



    $I->amHttpAuthenticated($UserNoAccess->name, $UserNoAccess->password);

    $fid = $MATERIAL->fid;
    $I->sendPOST('api/reactions/file/' . $fid);
    $I->seeResponseCodeIs(200);
  }

}
