<?php

/**
 * @file
 * File containing admin settings for Restrict ROle Login by IP module
 */

/**
 * Page callback: Restrict Role Login by IP Admin settinsg form.
 *
 */
function restrict_role_login_by_ip_form($form, &$form_state) {

  $user_roles = user_roles(TRUE); // Get all roles except anonymous
  unset($user_roles[array_search(t('authenticated user'), $user_roles)]); // Remove default authenticated user role

  $form['restrict_role_login_by_ip_header'] = array(
    '#type' => 'textfield',
    '#title' => t('Header to check'),
    '#default_value' => variable_get('restrict_role_login_by_ip_header', 'REMOTE_ADDR'),
    '#description' => t('This is the HTTP request header that contains the client IP Address. It is sometimes re-written by reverse proxies and Content Distribution Networks. Default Value is  REMOTE_ADDR.'),
  );


  $form['restrict_role_login_by_ip_header_restriction'] = array(
    '#type' => 'textfield',
    '#title' => t('Allowed IP range'),
    '#description' => t('Enter IP Address Ranges in CIDR Notation seperated with semi-colons, <b><u>with no trailing semi-colon</u></b>.<br /> E.G. 10.20.30.0/24;192.168.199.1/32;1.0.0.0/8<br />For more information on CIDR notation click <a href="http://www.brassy.net/2007/mar/cidr_basic_subnetting">here</a>.'),
    '#default_value' => variable_get('restrict_role_login_by_ip_header_restriction', ''),
    '#maxlength' => 256,
  );

  $form['restrict_role_login_by_ip_header_roles'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc($user_roles),
    '#title' => t('What Roles do you want to restrict the login (to Whitelisted IPs)?'),
    '#default_value' => variable_get('restrict_role_login_by_ip_header_roles', array()),
  );

  return system_settings_form($form);
}
