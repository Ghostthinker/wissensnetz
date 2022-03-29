<?php if (empty($authors)): ?>
  Kein Ergebnis
<?php endif; ?>

<?php foreach ($authors as $author): ?>

  <div class="views-row">
    <div
      class="views-field views-field-field-user-picture"><?php print $author['picture'] ?></div>
    <div class="views-field-name">
      <?php print $author['realname'] ?><br/>
      (<?php print $author['author_editor']; ?>)
    </div>
  </div>

<?php endforeach ?>
