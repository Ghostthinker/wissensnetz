<?php if ($backlink) : ?>
<div class="material-card-backlink">
  <a href="<?php print $backlink['target']; ?>">
    <div class="material-card-chip-backlink">
      <div class="button-image">
      </div><?php print $backlink['name']; ?>
    </div>
  </a>
</div>
<?php endif ?>

<div class="material-card-container">
  <?php foreach ($cards as $card): ?>
    <a href="<?php print $card['target']; ?>">
      <div class="material-card"
           style="background: url(<?php print $card['image']; ?>); background-size: cover;">
        <img class="material-card-icon" src="<?php print $icon ?>">
        <div class="material-card-chip">
          <div class="button-image-card"
               style="mask-image: url(<?php print $card['icon']; ?>);">
          </div> <?php print $card['label']; ?>
        </div>
      </div>
    </a>
  <?php endforeach; ?>
</div>


<style>
  .button-image {
    mask-size: 100%;
    mask-image: url(<?php print $icon; ?>);
    width: 1.5rem;
    height: 1.5rem;
    background: white;
    transform: rotate(180deg);
  }

  .button-image-card {
    mask-size: 100%;
    width: 1.25rem;
    height: 1.25rem;
    background: white;
  }


</style>
