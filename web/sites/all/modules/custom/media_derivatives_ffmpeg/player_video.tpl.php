<?php if ($status != "ok") : ?>
  <div style="max-width:480px">
    <?php print $thumbnail; ?>
  </div>
<?php else : ?>
  <?php if ($thumbnail_only) : ?>
    <?php print $thumbnail_link; ?>
  <?php else : ?>
    <video <?php print $video_attributes ?>data-setup="{}" preload="auto">
      <?php foreach ($sources as $mime => $src) : ?>
        <source src="<?php print $src ?>" type="<?php print $mime ?>">
      <?php endforeach ?>
    </video>
  <?php endif ?>
<?php endif ?>

