<?php if ($accordion['access']): ?>
  <?php $classes = 'accordion-container ';
  $classes .= $accordion['is-mobile'] === TRUE ? 'is-mobile' : '';
  $classes .= $accordion['label'] !== TRUE ? 'label-hide' : '';
  $classes .= $accordion['resize'] === TRUE ? 'attachment' : '';
  $classes .= ' form-wrapper';
  ?>
  <div class="<?php print $classes; ?>">
    <button type="button" class="accordion-button">
      <?php print $accordion['title'] ?>
    </button>
    <div class="accordion-panel">
      <?php print $accordion['content'] ?>
    </div>
  </div>
<?php endif; ?>
