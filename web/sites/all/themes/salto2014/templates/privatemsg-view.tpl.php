<?php

drupal_add_css(drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.base.css');
drupal_add_css(drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.theme.css');
?>
<?php print $anchors; ?>
<div
  <?php if (!empty($message_classes)) { ?>class="card row <?php echo implode(' ', $message_classes); ?>" <?php } ?>
  id="privatemsg-mid-<?php print $mid; ?>">
  <div class="col-md-2">
    <?php print $author_picture; ?>
  </div>
  <div class="col-md-10">
    <?php if (isset($new)): ?>
      <span class="new privatemsg-message-new"><?php print $new ?></span>
    <?php endif ?>
    <div class="privatemsg-message-body">
      <?php print $message_body; ?>
    </div>
    <?php if (isset($message_actions)): ?>
      <?php print $message_actions ?>
    <?php endif ?>
    <div class="privatemsg-message-information">
      <span
        class="privatemsg-message-date"><?php print $message_timestamp; ?></span>
    </div>
  </div>
</div>
