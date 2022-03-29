<?php if ($status != "ok") : ?>
  <div style="max-width:480px">
    <?php print $thumbnail; ?>
  </div>
<?php else : ?>
  <?php if ($thumbnail_only) : ?>
    <?php print $thumbnail_link; ?>
  <?php else : ?>
    <div <?php print $container_style ?> >
      <div><?php print $thumbnail; ?></div>
      <audio <?php print $audio_attributes ?> style="width: 100%">
        <?php foreach ($sources as $mime => $src) : ?>
          <source src="<?php print $src ?>" type="<?php print $mime ?>">
        <?php endforeach ?>
      </audio>
    </div>
  <?php endif ?>
<?php endif ?>