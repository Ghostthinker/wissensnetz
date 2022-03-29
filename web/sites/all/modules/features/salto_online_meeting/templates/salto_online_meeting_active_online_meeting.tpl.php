<br>
<div class="bip_side_box">
  <div class="panel-heading"><h3
      class="panel-title"><?php print t('Current Online meetings') ?> </h3>
  </div>
  <?php if (empty($online_meetings)) : ?>
    <div
      class="pane-content empty-text"> <?php print t('There are currently no online meetings in progress') ?></div>
  <?php else: ?>
    <?php foreach ($online_meetings as $online_meeting): ?>
      <br>
      <div class="online-meeting-border-form">
        <div class="online-meetings-items-icon-wrapper">
          <div class="icon-calendar online-meetings-items-icon"></div>
          <div class="online-meetings-item-status online"></div>
        </div>
        <div class="online-meeting-border-form-items">
          <label><?php print $online_meeting['title'] ?></label>
          <?php print $online_meeting['time'] ?>
          <br><br>
          <a class="btn btn-primary online-meeting-button-form"
             target="_blank"
             href="<?php print $online_meeting['url'] ?>"><?php print t('Join') ?></a>
        </div>
      </div>
    <?php endforeach ?>
  <?php endif ?>
</div>
