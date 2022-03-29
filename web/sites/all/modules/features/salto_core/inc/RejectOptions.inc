<?php

class RejectOptions {

  const REJECT_MIN_VERSION_NAME_CHROME = 'REJECT_MIN_VERSION_CHROME';

  const REJECT_MIN_VERSION_NAME_FIREFOX = 'REJECT_MIN_VERSION_FIREFOX';

  const REJECT_MIN_VERSION_NAME_OPERA = 'REJECT_MIN_VERSION_OPERA';

  const REJECT_MIN_VERSION_NAME_SAFARI = 'REJECT_MIN_VERSION_SAFARI';

  const REJECT_MIN_VERSION_NAME_EXPLORER = 'REJECT_MIN_VERSION_EXPLORER';

  const REJECT_MIN_VERSION_CHROME = 70;

  const REJECT_MIN_VERSION_FIREFOX = 62;

  const REJECT_MIN_VERSION_OPERA = 56;

  const REJECT_MIN_VERSION_SAFARI = 9;

  const REJECT_MIN_VERSION_EDGE = 14;

  const REJECT_MIN_VERSION_EXPLORER = 11;

  const REJECT_BROWSER_DISPLAY_NAME_CHROME = 'chrome';

  const REJECT_BROWSER_DISPLAY_NAME_OPERA = 'opera';

  const REJECT_BROWSER_DISPLAY_NAME_FIREFOX = 'firefox';

  const REJECT_BROWSER_DISPLAY_NAME_SAFARI = 'safari';

  const REJECT_BROWSER_DISPLAY_NAME_EDGE = 'mse';

  private $supportedBrowsers = [
    self::REJECT_BROWSER_DISPLAY_NAME_CHROME => [
      'version' => self::REJECT_MIN_VERSION_CHROME,
      'text' => 'Google Chrome',
      'url' => 'https://www.google.com/chrome/',
    ],
    self::REJECT_BROWSER_DISPLAY_NAME_FIREFOX => [
      'version' => self::REJECT_MIN_VERSION_FIREFOX,
      'text' => 'Mozilla Firefox',
      'url' => 'https://www.mozilla.com/firefox/',
    ],
    self::REJECT_BROWSER_DISPLAY_NAME_SAFARI => [
      'version' => self::REJECT_MIN_VERSION_SAFARI,
      'text' => 'Safari',
      'url' => 'https://www.apple.com/safari/download/',
      'allow' => '{ all: false, safari: true }',
    ],
    self::REJECT_BROWSER_DISPLAY_NAME_OPERA => [
      'version' => self::REJECT_MIN_VERSION_OPERA,
      'text' => 'Opera',
      'url' => 'https://www.opera.com/download/',
    ],
    self::REJECT_BROWSER_DISPLAY_NAME_EDGE => [
      'version' => self::REJECT_MIN_VERSION_EXPLORER,
      'text' => 'Microsoft Edge',
      'url' => 'https://www.microsoft.com/de-de/windows/microsoft-edge',
      'allow' => '{ all: false, ie: true, edge: true }',
    ],
  ];

  function showRejectedVersions() {
    return '{
      chrome: ' . self::REJECT_MIN_VERSION_CHROME . ',
      firefox: ' . self::REJECT_MIN_VERSION_FIREFOX . ',
      opera: ' . self::REJECT_MIN_VERSION_OPERA . ',
      safari: ' . self::REJECT_MIN_VERSION_SAFARI . ',
      ie: ' . self::REJECT_MIN_VERSION_EXPLORER . ',
      edge: ' . self::REJECT_MIN_VERSION_EDGE . ',
      unknown: true,
    }';
  }

  function buildSupportedBrowsers() {
    $json = '';
    foreach ($this->supportedBrowsers as $name => $browser) {
      $json .= $name . ': {';
      foreach ($browser as $key => $value) {
        if (stripos($key, 'allow') > -1) {
          $json .= $key . ': ' . $value . '';
        }
        else {
          $json .= $key . ': "' . $value . '",';
        }
      }
      $json .= '},';
    }
    return '{' . $json . '}';
  }

  function getBrowserDisplay() {
    $output = '';
    foreach ($this->supportedBrowsers as $key => $browser) {
      $output .= '"' . $key . '",';
    }
    return '[' . $output . ']';
  }

  function buildRejectString($devel = FALSE) {
    return '
     this.display = ' . $this->getBrowserDisplay() . ';
     this.reject = ' . $this->showRejectedVersions() . ';
     this.reject.all = ' . ($devel == TRUE ? 'true' : 'false') . ';
     this.browserInfo = ' . $this->buildSupportedBrowsers() . '';
  }

  function buildScript($devel = FALSE) {
    //skip reject on mobile browsers
    $script = 'beforeReject: function() {
      if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ) {
         //do not reject mobile browsers at the moment
         this.reject = {};
         this.reject.all = false;
      } else {' . $this->buildRejectString($devel) . '}
    }';
    return $script;
  }

}
