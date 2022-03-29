#!/usr/bin/env bash
#Update the Drupal Core

if [ ! -d "web" ]; then
  echo -e "\e[0;31m Theres no web dir! Are you sure you are on git root?"
  tput sgr0
  exit 2
fi

cd web
drush up drupal --yes
git co .gitignore

# APPLY Taxonomy Vocabulary Listing Patch
echo "git apply --stat ../patched/2019-10-29-SN-GT-OG-VOCABULARY-PERMISSION-LISTING.patch"