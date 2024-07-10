<?php

use Helper\Wissensnetz;

/**
 * Class FeedContentsCest
 * Alle Tests bezüglich Startseiten funktionalität
 *
 * @see aus https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.1aa149yk5ke
 *
 */
class FeedItemsCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {  }

  public function _after(AcceptanceTester $I) {}

  /**
   * @skip test incomplete
   *
   * 300.09 BenutzerIn - Inhalte - Aktuelles aus Trainer-im-Leistungssport.de einsehen
   *
   * @UserStory 300.09 https://trello.com/c/sq886zko/738-30009-benutzerin-inhalte-aktuelles-aus-trainer-im-leistungssportde-einsehen
   * @Task https://trello.com/c/ACugZlo1/1013-30009-benutzerin-inhalte-aktuelles-aus-trainer-im-leistungssportde-einsehen
   * @param \AcceptanceTester $I #
   * @return bool
   */
  public function FI_01_0_check_newsfeed(AcceptanceTester $I) {

    $I->wantTo('FC300.09 BenutzerIn - Inhalte - Aktuelles aus Trainer-im-Leistungssport.de einsehen');
    $I->expect('not configure on test system, return');

    $user = $I->haveUser();
    $trainer = $I->getUserByMail(USER_TRAINER_IM_LEISTUNGSSPORT_DE_MAIL);

    $I->completedSetup();

    $I->loginAsUser($user);


    $I->checkAK('FC300.09', 'AK 2: Die News werden über einen Feed mit Token von Trainer-im-Leistungssport.de abgerufen. Der Feed ist via https://www.trainer-im-leistungssport.de/aktuelles/alle/feed?token=Nn5HCFm5MWZDamrqmk verfügbar.');
    $I->amOnPage("/node/add/feed");

    $I->submitForm("#feed-node-form",[
      'title' => 'Feed-Test-FC300_09',
      'feeds[FeedsHTTPFetcher][source]' => 'https://www.trainer-im-leistungssport.de/aktuelles/alle/feed?token=Nn5HCFm5MWZDamrqmk',
    ]);
    $I->waitForText('Newsfeed Feed-Test-FC300_09 wurde erstellt.');

    $I->checkAK('FC300.09', 'AK 1: Auf der Startseite gibt es unten rechts unter "Literaturdatenbank des IAT" einen neuen Block "Aktuelles aus Trainer-im-Leistungssport.de"');
    $I->checkAK('FC300.09', '[new] AK 1.3: Der Block ist für alle Wissennetz-NutzerInnen sichtbar - unabhängig von den ausgewählten Themenfeldern (siehe AK 2.5). [27.03.2018 - Absprache: WFA + CD + JM]');

    $I->amOnPage("/");
    $I->see('Aktuelles aus Trainer-im-Leistungssport.de');
    $I->seeElement('.panel.panel-default.bip_side_box #block-tils');

    $I->checkAK('FC300.09', 'AK 1.1: Der Block zeigt Links zu den letzten 5 News aus Trainer-im-Leistungssport.de an (siehe AK 2.x).');
    $I->seeElement('#block-tils .views-row-1 a');
    $I->seeElement('#block-tils .views-row-2 a');
    $I->seeElement('#block-tils .views-row-3 a');
    $I->seeElement('#block-tils .views-row-4 a');
    $I->seeElement('#block-tils .views-row-5 a');
    //$I->checkAK('FC300.09', 'AK 1.2: Die Sortierung erfolgt chronologisch, neueste News zuerst.');

    //$I->checkAK('FC300.09', 'AK 2.1: Das Abholen erfolgt einmal pro Tag.');
    //$I->checkAK('FC300.09', 'AK 2.2: Um die Einbindung in das Wissensnetz möglichst einfach zu gestalten, den Lesezugriff auf + Kommentierung der Inhalte auch ohne Account im Trainer-im-Leistungssport.de zu erlauben werden die News als normale Beiträge unter einer bestimmten Kategorie im Gemeinschaftsbereich "Beiträge" abgelegt.');
    $posts = $I->getPostsFromUser($trainer);
    $nids = array_keys($posts);
    $I->checkAK('FC300.09', '[new] AK 2.6 Abgrenzung / Info: Neu erstellte Beiträge werden normal im Aktivitätenstrom angezeigt, wenn man das Themenfeld "Leistungssport" in seinem Profil aktiviert hat. [27.03.2018 - Absprache: WFA + CD + JM]');
    $I->see($posts[$nids[count($nids)-1]]->title, '.heartbeat-messages-wrapper');

    $I->checkAK('FC300.09', 'AK 2.3: Der Autor der News ist ein Systemnutzer "Trainer-im-Leistungssport.de".');
    $I->amOnPage("/node/" . $nids[0]);
    $I->seeElement('.node_author a', ['title' => $trainer->realname]);
    //$I->see($trainer->realname);
    $I->checkAK('FC300.09', 'AK 2.4: Bearbeitung der Beiträge ist nur durch den Systemnutzer möglich.');
    $I->dontSee('Bearbeiten');
    //$I->click('Bearbeiten');

    //$I->checkAK('FC300.09', '[mod] AK 2.5: Die Beiträge werden in dem Themenfeld "Leistungssport" und "Bildung" in jeweils der Unterkategorie "Trainer-im-Leistungssport.de" abgelegt. [04.05.2018 - 08:49 - JM]');

    $I->checkAK('FC300.09', 'AK 3: Die folgenden Inhalte werden übernommen.');
    //$I->checkAK('FC300.09', '[mod] AK 3.4: Fotos / Abbildungen / sonstige Anhänge (Verleiben auf externem Server) [02.05.2018 - 10:04 JM via CD]');
    $I->checkAK('FC300.09', '[mod] AK 3.5: Links werden auch übernommen (Alle erlaubte HTML Elemente aus dem Inhalt werden übernommen) [27.03.2018 - Absprache: WFA + CD + JM]');
    $I->seeElement('#node-' . $nids[0] . ' a');

    $I->checkAK('FC300.09', '[mod] AK 4: Unter jedem Beitrag steht der Satz "Mehr Informationen auf trainer-im-leistungssport.de" [02.05.2018 - 10:05 - JM via CD]');
    foreach ($posts as $nid => $post) {
      $I->amOnPage("/node/" . $nid);
      $I->see('Mehr Informationen auf trainer-im-leistungssport.de');
    }
  }
}
