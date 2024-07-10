<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"
  "http://www.w3.org/TR/REC-html40/loose.dtd">
<html>
<head>
  <style>

    #outer {
      background-color: #EBEAEB !important;
      display: block;
      text-align: center;
      padding: 1.25rem;
      color: #023047;
      font-family: "Open Sans", "Helvetica Neue", Helvetica, Arial, sans-serif;
      box-sizing: border-box;
      float: left;
    }


    .email-template-container {
      padding-top: 1rem;
      display: block;
      text-align: -webkit-center;
      align-items: center;
      margin: 1.5rem auto;
      max-width: 36rem;
    }

    .header-logo {
      max-width: 17rem;
      margin-bottom: 1.5rem;
    }

    .header-logo img {
      width: 100%;
    }

    .notification-content {
      word-break: break-word;
    }

    .email-main-content {
      border-top: 0.5rem solid <?php print $mail_primary_color ?>;
      max-width: 36rem;
      background: #FFF;
      box-shadow: 0px 4px 4px rgba(125, 125, 125, 0.25);
      text-align: left;
      flex-direction: column;
      box-sizing: border-box;
      padding: 2rem 1.25rem 2rem;

      margin-top: 1rem;
      width: 100%;
      display: block;
    }

    .notification-settings, .footer-logo {
      padding-left: 0.5rem;
      margin-bottom: 0.75rem;
    }

    .notification-settings {
      font-size: 0.875rem;
      text-decoration: none !important;
      float: left;
      color: grey !important;
    }

    .notification-message {
      font-size: 1.5rem;
      text-transform: uppercase;
      margin-bottom: 2rem;
    }

    .notification-message-type {
      color: <?php print $mail_primary_color ?> !important;
      font-weight: bold;
      font-size: 1rem;
    }

    .notification-content {
      line-height: 1.5rem;
    }

    .footer {
      margin-top: 1rem;
      width: 100%;
      display: block;
      padding: 0.5rem 0rem;
      padding-bottom: 2rem;
    }

    .footer-logo {
      max-width: 8rem;
      margin-right: 0.875rem;
      float: right;
    }

    .footer-logo img {
      width: 100%;
    }

    .ds-1col {
      color: <?php print $mail_primary_color ?>;
      font-weight: bold !important;
      font-size: 1rem;
    }

    .ds-1col > * {
      color: #023047;
      font-weight: normal;
      line-height: 1.5rem;
    }

    .mail-multiple-message-type {
      color: <?php print $mail_primary_color ?>;
      font-weight: bold;
      font-size: 1rem;
      margin-bottom: 1rem;
    }

    .mail-multiple-message-type a {
      text-decoration: none;
      color: inherit;
    }

    .multiple-mail-divider {
      border-bottom: 1px solid grey;
      margin-bottom: 2rem;
    }

  </style>
</head>
<body>
<div id="outer" style="width:100%; background-color: #f0f0f0; ">

  <div class="email-template-container">
    <div class="header-logo">
      <img src="<?php print $logo ?>">
    </div>
    <div class="email-main-content">
      <div class="notification-message">
        <?php print $title ?>
      </div>
      <div class="notification-content">
        <?php print $content ?>
      </div>
    </div>
    <div class="footer">
      <a href="/notifications/settings"
         class="notification-settings"><?php print t('Notification settings') ?></a>
      <div class="footer-logo">
        <img src="<?php print $eb_logo ?>" alt="">
      </div>
    </div>
  </div>
</div>
</body>
</html>
