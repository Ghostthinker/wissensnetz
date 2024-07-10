<?php

include 'sites/default/settings.php';

if(empty($conf['opcache_token'])){
  header( 'HTTP/1.0 403 Forbidden');
  echo "failed";
  exit;
}

if($_GET['key'] == $conf['opcache_token']) {
  if(!opcache_reset()) {
    echo "failed";
  }else{
    echo "success";
  }
}
