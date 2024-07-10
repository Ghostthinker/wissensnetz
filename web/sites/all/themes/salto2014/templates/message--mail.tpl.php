<div class="mail-multiple-message-type">
  <a class="message-link" href="<?php print $url ?>">
    Es gibt Neuigkeiten. <?php print $main_content ?>
  </a>
</div>
<div class="multiple-mail-divider">
<?php if (!empty($content_preview)) : ?>
    <?php print($content_preview); ?>
<?php endif ?>
<?php if (!empty($content_preview_mail)) : ?>
  <div
    style="border: 1px solid #ccc; background: #f0f0f0; padding: 8px 10px;">
    <?php print($content_preview_mail); ?>
  </div>
<?php endif ?>
</div>

