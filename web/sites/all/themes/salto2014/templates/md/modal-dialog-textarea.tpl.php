<?php if (!empty($variables['modal'])): ?>
  <?php
  $modal = $variables['modal'];
  $id = $modal['id'];
  $buttonIdAccept = 'btn#mr-accept';
  $buttonIdDecline = 'btn#mr-decline';
  $buttonClass = 'btn big for-modal ' . $modal['class'];
  ?>
  <div id="<?php print $id; ?>" class="modal-tb">
    <div class="modal-content">
      <span class="close">&times;</span>
      <div class="wrapper">
        <h2><?php print $modal['title']; ?></h2>
        <section class="alert"></section>
        <p class="subtitle"></p>
        <div class="message">
          <label><?php print $modal['label']; ?></label>
          <textarea rows="7"></textarea>
        </div>
      </div>
      <div class="buttons">
        <button type="button" class="<?php print $buttonClass; ?> btn-success"
                id="<?php print $buttonIdAccept; ?>">
          <?php print t('Accept'); ?></button>
        <button type="button" class="<?php print $buttonClass; ?> btn-decline"
                id="<?php print $buttonIdDecline; ?>">
          <?php print t('Decline'); ?></button>
      </div>
    </div>
  </div>
<?php endif; ?>
