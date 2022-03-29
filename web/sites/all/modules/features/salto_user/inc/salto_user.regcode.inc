<?php


/**
 * Send a regcode to a user
 *
 * @param  [type] $node
 * @param  [type] $mail
 */
function _salto_user_send_regcode($node, $mail) {
  global $language;

  // get the code
  $code = _salto_user_create_regcode_by_og($node);
  $message['subject'] = t("Registration Invitation");

  $link = url("user/register", [
      'absolute' => TRUE,
      'query' => [
        'code' => urlencode(_salto_user_encode_regurl($mail, $code->code)),
      ],
    ]
  );
  $message['body'] = t("Dear user, you've been invited to join the platform. Please follow the link to register !link", ['!link' => $link]);

  drupal_mail('salto_core', 'regcode_invite', $mail, $language, $message);
  drupal_set_message(t("An invitations has been sent to the e-mail-adress %email", ['%email' => $mail]));
}

/**
 * Creates a single usage regcode for a specific group
 *
 * @param  [type] $group
 *
 * @return [type]
 */
function _salto_user_create_regcode_by_og($node) {
  $regcode_og_term = _salto_organisation_get_regcode_tag($node);
  $code = new stdClass;
  $code->is_active = 1;
  $code->maxuses = 1;
  $code->code = regcode_generate(10, 'alphanum', 0);
  $terms = [$regcode_og_term->tid => $regcode_og_term->tid];

  if (!regcode_save($code, $terms, REGCODE_MODE_SKIP)) {
    watchdog('salto_user', 'No valid code for group @code was created', ['@group' => $group->label], WATCHDOG_ERROR);
  }
  return $code;
}


function _salto_user_encode_regurl($mail, $regcode, $invite_id) {

  $str = serialize([
    "mail" => $mail,
    'code' => $regcode,
    'invite_id' => $invite_id,
  ]);
  $encrypted = core_encrypt_openssl($str, SALTO_REGCODE_KEY, 'bf-cbc');
  return base64_encode($encrypted);
}

/**
 * Decode an regcode from url
 *
 * @param  [type] $hash
 *
 * @return [type]
 */
function _salto_user_decode_regurl($hash) {
  $str = core_decrypt_openssl(base64_decode($hash), SALTO_REGCODE_KEY, 'bf-cbc');
  return unserialize($str);
}
