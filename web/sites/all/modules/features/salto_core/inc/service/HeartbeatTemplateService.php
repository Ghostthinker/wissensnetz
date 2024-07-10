<?php

namespace salto_core\service;


use SocialVideoService\api\ApiService;
use SocialVideoService\SocialVideoService;
use Wissensnetz\Core\File\DrupalFile;
use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\User\DrupalUser;

class HeartbeatTemplateService {


  private $activity;

  public function __construct($activity) {
    $this->activity = $activity;
  }

  public function data_for_hearbeat_activity_add_node(&$variables){
    $variables['type'] = $this->activity->message_id;
    $variables['chip_info'] = $this->getChipInfo();
    $drupalNode = \Wissensnetz\Core\Node\DrupalNode::make($this->activity->nid);
    $variables['activity_heading'] = $this->thisPrepareMessage();

    $body = $drupalNode->getBody();
    $content = $this->trimText($body);
    $variables['activity_content'] = [
      'content' => $content,
      'preview_image' => $drupalNode->getPreviewImageUrl(),
      'num_views' => format_plural($drupalNode->getNumViews(), '1 read', '@count reads'),
      'num_comments' => format_plural($drupalNode->getNumComments(), '1 comment', '@count comments'),
      'nid' => $drupalNode->getNid()
    ];
  }

  public function data_for_heartbeat_activity_add_comment(&$variables){
    #heartbeat-activity-comment
    $variables['type'] = $this->activity->message_id;
    $variables['chip_info'] = $this->getChipInfo();
    $drupalNode = \Wissensnetz\Core\Node\DrupalNode::make($this->activity->nid);
    $variables['activity_heading'] = $this->thisPrepareMessage();
    $comment = comment_load($this->activity->cid);
    $content = $this->trimText($comment->comment_body[LANGUAGE_NONE][0]['value']);
    $variables['activity_content'] = [
      'content' => $content,
      'preview_image' => $drupalNode->getPreviewImageUrl(),
      'num_views' => format_plural($drupalNode->getNumViews(), '1 read', '@count reads'),
      'num_comments' => format_plural($drupalNode->getNumComments(), '1 comment', '@count comments'),
      'nid' => $drupalNode->getNid()
    ];
  }

  public function data_for_hearbeat_activity_video(&$variables){
    $drupalUser = DrupalUser::current();
    $variables['type'] = 'heartbeat_video';
    $drupalNode = DrupalNode::make($this->activity->nid);
    $file = DrupalFile::getFileFromCommentNode($drupalNode);
    $socialVideoService = new SocialVideoService();
    $context = [];

    if($this->activity->message_id === 'heartbeat_videocomment_recomment' || $this->activity->message_id === 'heartbeat_videocomment_react'){
      $string = $this->activity->variables['!timecode'];
      preg_match('/href="(.*?)"/', $string, $matches);
      $url = $matches[1];
      $query = parse_url($url, PHP_URL_QUERY);
      parse_str($query, $result);
      $context['commentId'] = $result['commentId'] ?? $this->activity->variables['!cid'];
      $context['recommentId'] = $result['commentId'] ? $this->activity->variables['!cid'] : '';
      $variables['icon'] = 'heartbeat-activity-type-video-comment';
    }

    if($this->activity->message_id === 'heartbeat_videocomment_add'){
      $context['commentId'] = $this->activity->variables['!cid'];
    }

    if($this->activity->variables['!timecode']){
      $variables['timecode'] = strip_tags($this->activity->variables['!timecode']);
    }

    if($context['commentId']){
      $variables['thumbnailUrl'] = $socialVideoService->getThumbnail($context['commentId']);
    }

    if(empty($variables['thumbnailUrl'])){
      $variables['thumbnailUrl'] = $socialVideoService->getVideoThumbnail($file->getUuid());
    }

    $variables['icon'] = $this->getIconClass();
    $variables['activity_content'] = $this->trimText($this->activity->variables['!comment']);
    $variables['video_url'] = $socialVideoService->getEmbedUrl($file->getFile(), $drupalUser->getUser(), $context);
    $variables['title'] = $drupalNode->getTitle();
    $variables['chip_info'] = $this->getChipInfo();
    $variables['activity_heading'] = [
      'node_title' => $drupalNode->getTitle(),
      'node_link' => $drupalNode->getUrlAbsolute()
    ];

    $variables['activity_heading'] = [
      'content' => $this->thisPrepareMessage()
    ];

  }

  private function getChipInfo(){
    $drupalUser = \Wissensnetz\User\DrupalUser::make($this->activity->uid);
    return [
      'user_url' => $drupalUser->getUserUrl(),
      'picture' => $drupalUser->getProfileImageUrl(),
      'name' => $drupalUser->getRealname(),
      'date' => $this->getDateText()
    ];

  }

  private function getDateText(){
    $timestamp = $this->activity->timestamp;
    $diff = $_SERVER['REQUEST_TIME'] - $timestamp;

    /*
    //use this to render a date optionally
    if($diff > 24*3600*7) {
      return format_date($timestamp, 'small');
    }
    */

    return t('@time ago', array('@time' => format_interval($diff, 1))) ;
  }

  private function trimText($text, $maxLength = 200){


    $pattern = '/<audio\b[^>]*>/i';
    if (preg_match($pattern, $text)) {
     return $text;
    }

    $value = check_markup($text, 'editor');
    $value = strip_tags($value);

    $alter['max_length'] = 200;
    $alter['word_boundary'] = TRUE;
    $alter['ellipsis'] = TRUE;
    $alter['html'] = TRUE;

    return views_trim_text($alter, $value);
  }

  private function thisPrepareMessage(){
    $string = ucfirst(str_replace($this->activity->variables['!username'] . ' ', '', $this->activity->message));
    $position = strpos($string, '<blockquote>');
    if(!$position){
      return $string;
    }
    return substr($string, 0, $position);
  }

  private function getIconClass(){
    switch ($this->activity->message_id){
      case 'heartbeat_video_update':
      case 'heartbeat_video_react':
      case 'heartbeat_video_add':
        return 'heartbeat-activity-type-video';
      case 'heartbeat_videocomment_add':
      case 'heartbeat_videocomment_react':
      case 'heartbeat_videocomment_recomment':
        return 'heartbeat-activity-type-video-comment';
    }

    return 'heartbeat-activity-type-video';
  }

}
