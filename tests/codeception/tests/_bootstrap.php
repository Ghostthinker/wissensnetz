<?php

require("_support/extensions/Testprotokol.php");

error_reporting(E_ALL | E_STRICT);
#require_once('/home/steff/projects/bildungsnetz/tests/codeception/vendor/autoload.php');
ini_set("default_charset", 'utf-8');


if (!defined('DRUPAL_ROOT')) {
  // define('DRUPAL_ROOT', realpath("../../web"));
  // define('DRUPAL_ROOT', realpath(getcwd() . '/web/'));
  $current_path = getcwd();
  $path_exploded = explode("/", $current_path);
  if (end($path_exploded) == "codeception") {
    define('DRUPAL_ROOT', realpath("../../web"));
  }
  else {
    define('DRUPAL_ROOT', realpath(getcwd() . '/web/'));
  }
}

$old_pwd = getcwd();
chdir(DRUPAL_ROOT);

define('WN_TESTS_RUNNING', TRUE);

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

#chdir($old_pwd);
