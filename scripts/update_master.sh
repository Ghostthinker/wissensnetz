#!/usr/bin/env bash
#
#this script is for upgrading the current head.
#
if [ ! -d "web" ]; then
  echo -e "\e[0;31m Theres no web dir! Are you sure you are on git root?"
  tput sgr0
  exit 2
fi
cd web

#set maintenance mode ON
#drush vset maintenance_mode 1

drush en captcha image_captcha salto_online_meeting mentions admin_api hidden_captcha social_video_service --yes

drush php-eval "variable_set('ajax_comments_reply_autoclose', 1);"
drush php-eval "variable_set('hidden_captcha_label', 'Captcha Math');"
#drush alter_db_multibyte
drush fra --yes

drush language-import de ../language/blanko --replace

drush updatedb --yes

drush cc opcache
drush cc all

#set maintenance mode OFF
#drush vset maintenance_mode 0


