<?php
/**
 * Created by PhpStorm.
 * User: linnie
 * Date: 12.02.19
 * Time: 14:53
 */

/**
 * A simple testing mail system that logs mails on screen
 */
class OnScreenMailSystem extends TestMailSystem {

  public function _format(array $message) {
    return $message;
  }

  public function mail(array $message) {
    $onscreen_mail = parent::mail($message);
    drupal_set_message("<span class='onscreenmail'>" . json_encode($onscreen_mail) . "</span>");
    return TRUE;
  }

}

