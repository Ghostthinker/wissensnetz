<?php if ($status != "ok") : ?>
  <div>
    <?php print $thumbnail; ?>
  </div>
<?php else : ?>
  <?php if ($thumbnail_only) : ?>
    <?php print $thumbnail_link; ?>
  <?php else : ?>
    <div <?php print $document_attributes ?> >
      <?php foreach ($sources as $mime => $src) : ?>
        <source src="<?php print $src ?>" type="<?php print $mime ?>">
      <?php endforeach ?>
    </div>
  <?php endif ?>
<?php endif ?>
