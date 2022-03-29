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
drush vset maintenance_mode 1

drush en captcha image_captcha salto_online_meeting --yes

drush fra --yes

drush language-import de ../language/38 --replace

drush vset 'date_popup_timepicker' 'wvega'
drush updatedb --yes

drush cc all

#set maintenance mode OFF
drush vset maintenance_mode 0


