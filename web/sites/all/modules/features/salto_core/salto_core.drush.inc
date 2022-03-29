<?php

/**
 * Implementation of hook_drush_command().
 *
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function salto_core_drush_command() {
  $items = [];

  $items['salto_status'] = [
    'callback' => "salto_core_status_callback",
    'description' => "Show the salto-bn status",
    'arguments' => [],
    'options' => [
      'notify_error' => [
        'description' => dt('Send mail to support in case of an error'),
        'value' => 'optional',
      ],
    ],
    'aliases' => ['bnst'],
    'core' => [7],
  ];
  return $items;
}

function salto_core_status_callback() {

  $min_age = time() - 3600;

  $times = [];
  //$receiver = variable_get('support_mail', "support@bildungsnetz.dosb.de" );  //didn't work???

  $receiver = "support@ghostthinker.de";
  // $receiver = "stefan.hoerterer@gmail.com";


  $notify_error = drush_get_option('notify_error');
  $notify_admin = isset($notify_error) ? TRUE : FALSE;

  $var_checks = [
    'cron_last' => '-2 hours',
    'salto_statistics_statistics_daily_run_time' => "-1 day  -2 hours",
    'onsite_notification_mail_last_execution_daily' => "-1 day -3 hours ",
    'onsite_notification_mail_last_execution_weekly' => "-1 week -2 hours ",
  ];

  if (module_exists('dosb_license')) {
    $var_checks['cron_last_dosb_license'] = "-1 day -1 hour";
  }


  $rows = [];
  $error = FALSE;

  $headers = [
    'name',
    'last run',
    'should not be older than',
    'status',

  ];
  $rows[] = $headers;

  foreach ($var_checks as $var_name => $min_age_string) {

    $row = [];
    $var_name_cron_last_timestamp = variable_get($var_name, 0);
    $min_age = strtotime($min_age_string);


    $row[] = $var_name;
    $row[] = format_date($var_name_cron_last_timestamp, "short");
    $row[] = format_date($min_age, "short");


    if ($var_name_cron_last_timestamp < $min_age) {
      $row[] = "error - to old";
      $error = TRUE;

    }
    else {
      $row[] = "ok";

    }

    $rows[] = $row;
  }

  $conditions = ['class' => 'search_api_solr_service', 'enabled' => TRUE];
  foreach (search_api_server_load_multiple(FALSE, $conditions) as $server) {
    $row = [];
    $row[] = $server->machine_name . ' - ' . $server->name;
    $row[] = format_date(0, "short");
    $row[] = format_date(0, "short");

    $solr = $server->getSolrConnection();
    $isNotReachable = $solr == NULL || !$solr->ping();

    if ($isNotReachable) {
      $row[] = "error - The Solr server could not be reached";
      $error = TRUE;
    }
    else {
      $row[] = "ok";
    }

    $rows[] = $row;
  }

  drush_print_table($rows, TRUE);


  if ($error && $notify_admin) {
    drush_print("send mail to $receiver");

    //when did this script run the last time?
    $salto_core_cron_status_last_run = variable_get("salto_core_cron_status_last_run", NULL);

    $origin = variable_get("site_name", "SITENAME") . " - " . $_SERVER['SERVER_NAME'];

    if ($salto_core_cron_status_last_run > 0) {
      $subject = "Still cron Problems on $origin";
    }
    else {
      $subject = "New cron Problems on $origin";
    }

    if (!$salto_core_cron_status_last_run || $salto_core_cron_status_last_run < time() - 3600) {

      $params = [
        'subject' => $subject,
        'body' => theme('table', ["rows" => $rows]),
        'headers' => ['From' => 'noreply@edubreak.de'],
      ];

      drupal_mail("salto_core", "debug", $receiver, language_default(), $params);
      variable_del("salto_core_cron_status_last_run");
    }
    else {
      drush_print("Still error but not sending mail");
    }
    variable_set("salto_core_cron_status_last_run", time());

  }
  else {
    variable_set("salto_core_cron_status_last_run", time());
  }

}

/**
 * Check a cron var
 *
 * @param $variable_name
 * @param $min_age
 *
 * @return mixed
 */
function salto_core_check_cron_timestamp($variable_name, $min_age) {

  $cron_last_timestamp = variable_get($variable_name, NULL);

  $error = FALSE;

  if ($cron_last_timestamp < $min_age) {
    $message = "$variable_name: " . format_date($cron_last_timestamp, "small") . " - last run too old";
    drush_set_error($message);
  }
  else {
    $message = "$variable_name: " . format_date($cron_last_timestamp, "small") . " - ok";
    drush_print($message);
    $error = TRUE;


  }

  return [$message, $error];


}
