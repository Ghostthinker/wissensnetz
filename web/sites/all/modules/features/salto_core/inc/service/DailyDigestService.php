<?php

namespace salto_core\service;

use Wissensnetz\User\DrupalUser;

class DailyDigestService {

  /**
   * @var \Wissensnetz\User\DrupalUser
   */
  private $user;

  /**
   * @var \salto_core\service\PostService
   */
  private $newsService;

  /**
   * @var \salto_core\service\OnlineTreffenService
   */
  private $dialogService;

  public function __construct(DrupalUser $drupalUser) {
    $this->user = $drupalUser;
    $this->newsService = new PostService();
    $this->dialogService = new OnlineTreffenService();
    $this->mentionsService = new MentionsService();
  }

  public function getLatestActivitiesByUser() {

    $latestNews = $this->newsService->getLatestNewsByUser($this->user);
    $latestDialog = $this->dialogService->getLatestDialogByUser($this->user);
    $latestMentions = $this->mentionsService->getMentionsForUserportal($this->user, 5);

    $activitys = [
      'news' => [],
      'dialog' => [],
      'mainGroup' => []
    ];

    if (!empty($latestNews)) {
      $author = $latestNews->getAuthor();

      $activitys['news'] = [
        'title' => $latestNews->getTitle(),
        'created' => $latestNews->getCreatedDateISO(),
        'author' => $author->getRealname(),
        'url' => $latestNews->getUrlAbsolute()
      ];
    }

    if (!empty($latestDialog)) {
      $activitys['dialog'] = [
        'title' => $latestDialog->getTitle(),
        'created' => $latestDialog->getStartDateISO(),
        'url' => $latestDialog->getUrlAbsolute()
      ];
    }

    if($latestMentions  !== NULL){
      $activitys['mainGroup']['mentions'] = $latestMentions;
    }

    return $activitys;
  }

}
