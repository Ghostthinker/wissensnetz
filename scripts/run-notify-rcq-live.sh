#!/bin/bash

if [ ! -d "web" ]; then
  echo -e "\e[0;31m Theres no web dir! Are you sure you are on git root?"
  tput sgr0
  exit 2
fi
cd web

#start the queue for notifications
drush @live notify-rcq
