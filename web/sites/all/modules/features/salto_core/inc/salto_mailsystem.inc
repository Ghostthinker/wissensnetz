<?php

/**
 * Modify the drupal mail system to send HTML emails.
 */
class SaltoMailSystem extends DefaultMailSystem {

  /**
   * Concatenate and wrap the e-mail body for plain-text mails.
   *
   * @param $message
   *   A message array, as described in hook_mail_alter().
   *
   * @return
   *   The formatted $message.
   */
  public function format(array $message) {

    if (empty($message['force_plain'])) {
      $message['body'] = implode("\n\n", $message['body']);
      $message['body'] = theme('htmlmail', ['message' => $message]);
      $message['body'] = make_urls_absolute($message['body']);
      $message['headers']['Content-Type'] = 'text/html; charset=UTF-8;';
    }
    else {
      $message['body'] = implode("\n\n", $message['body']);
      $message['body'] = drupal_wrap_mail(nl2br($message['body']));
    }

    $sitemail = variable_get('site_mail', '');

    if ($message['headers']['From'] == $sitemail) {
      $message['headers']['From'] = variable_get('site_name', 'Wissensnetz') . " <$sitemail>";
    }

    $engine = variable_get('mimemail_engine', 'mimemail');
    $engine_prepare_message = $engine . '_prepare_message';

    if (function_exists($engine_prepare_message)) {
      $message = $engine_prepare_message($message);
    }
    else {
      $message = mimemail_prepare_message($message);
    }

    return $message;
  }

}
