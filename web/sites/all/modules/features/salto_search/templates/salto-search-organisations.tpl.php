<?php if (empty($organisations)): ?>
  Kein Ergebnis
<?php endif; ?>

<?php foreach ($organisations as $og): ?>

  <div class="views-row">
    <div class="views-field-name">
      <?php print $og['name'] ?>
    </div>
  </div>

<?php endforeach ?>
