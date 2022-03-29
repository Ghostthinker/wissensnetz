<div class="salto-search-result-container">
  <?php foreach ($search_cats as $key => $sc): ?>
    <div class="search-item">
      <a id="search-box-<?php echo $key; ?>"
         href="<?php echo $sc['url']; ?>"><span
          class="search-item-placeholder"></span>
        <strong class="search-item-text">in</strong>
        <strong class="search-item-cat"><?php echo $sc['label']; ?></strong>
      </a>
    </div>
  <?php endforeach; ?>
</div>
