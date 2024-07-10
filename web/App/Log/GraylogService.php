<?php


namespace Wissensnetz\Log;

use Gelf\Transport\TcpTransport;
use Gelf\Transport\UdpTransport;

class GraylogService {
  public function get_graylog_settings() {
    $settings = variable_get('salto_core_graylog_settings', []);

    $defaults = [
      'enabled' => FALSE,
      'host' => '10.0.0.2',
      'port' => 12202,
      'channel' => $conf['instance_key'] ?? uuid_generate() ?? 'wissensnetz.dev',
      'transport' => 'udp',
    ];

    return array_merge($defaults, $settings);
  }

  public function salto_log_graylog($message, $shortMessage, $logData, $severity, $category) {

    $settings = $this->get_graylog_settings();


    if (!$settings['enabled']) {
      return;
    }

    $host = $settings['host'];
    $port = $settings['port'];
    $channel = $settings['channel'];
    $transport = $settings['transport'];


    switch ($transport) {
      case 'tcp':
        $transport = new TcpTransport($host, $port);//, Gelf\Transport\UdpTransport::CHUNK_SIZE_LAN);
        break;
      case 'udp':
        $transport = new UdpTransport($host, $port, UdpTransport::CHUNK_SIZE_LAN);
        break;
    }

    // To mute all connection related exceptions, as it may be useful in logging, we can wrap the transport:
    //
    // $transport = new Gelf\Transport\IgnoreErrorTransportWrapper($transport);

    // While the UDP transport is itself a publisher, we wrap it in a real Publisher for convenience.
    // A publisher allows for message validation before transmission, and also supports sending
    // messages to multiple backends at once.
    $publisher = new \Gelf\Publisher();
    $publisher->addTransport($transport);

    switch ($severity) {
      case WATCHDOG_EMERGENCY:
        $level = \Psr\Log\LogLevel::EMERGENCY;
        break;
      case WATCHDOG_ALERT:
        $level = \Psr\Log\LogLevel::ALERT;
        break;
      case WATCHDOG_CRITICAL:
        $level = \Psr\Log\LogLevel::CRITICAL;
        break;
      case WATCHDOG_ERROR:
        $level = \Psr\Log\LogLevel::ERROR;
        break;
      case WATCHDOG_WARNING:
        $level = \Psr\Log\LogLevel::WARNING;
        break;
      case WATCHDOG_NOTICE:
        $level = \Psr\Log\LogLevel::NOTICE;
        break;
      case WATCHDOG_INFO:
        $level = \Psr\Log\LogLevel::INFO;
        break;
      case WATCHDOG_DEBUG:
        $level = \Psr\Log\LogLevel::DEBUG;
        break;
    }




    // Now we can create custom messages and publish them
    $messageItem = new \Gelf\Message();
    $messageItem->setShortMessage($shortMessage)
      ->setLevel($level)
      ->setFullMessage($message);

    $messageItem->setAdditional('channel', $channel);
    $messageItem->setAdditional('category', $category);
    foreach ($logData as $key => $val) {
      $messageItem->setAdditional($key, $val);
    }
    $publisher->publish($messageItem);

  }
}
