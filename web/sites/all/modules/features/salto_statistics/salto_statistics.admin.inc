<?php

function salto_statistics_admin_settings($form, &$form_state) {
  $form['statistics'] = [
    '#type' => 'fieldset',
    '#title' => 'Time Settings',
  ];

  $form['statistics']['infos'] = [
    '#markup' => salto_statistics_admin_summary(),
    '#title' => t('Infos'),
  ];


  $form['statistics']['salto_statistics_statistics_daily_hour'] = [
    '#title' => t('Hour'),
    '#type' => 'textfield',
    '#description' => t('The hour when to save the daily statistics.'),
    '#default_value' => variable_get('salto_statistics_statistics_daily_hour', 22),
  ];


  $form = system_settings_form($form);

  return $form;
}

/**
 * A short summary when the last events occured
 *
 * @return [type] [description]
 */
function salto_statistics_admin_summary() {

  $last_run_time = variable_get('salto_statistics_statistics_daily_run_time', 0);
  $out[] = t("Last daily statistic saved: !daily", ['!daily' => $last_run_time > 0 ? format_date($last_run_time) : t('never')]);

  $last_statistics_nid = variable_get('salto_statistics_statistics_daily_last_nid', 0);
  if ($last_statistics_nid > 0) {
    $out[] = t("Last Statistic: !node", ["!node" => l(t('Show node'), 'node/' . $last_statistics_nid)]);
  }

  return implode("<br>", $out) . "<br>";
}
