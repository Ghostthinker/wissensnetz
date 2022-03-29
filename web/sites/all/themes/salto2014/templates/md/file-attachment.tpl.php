<?php
$derivatives = $attachment['media_derivatives'];
$hasDerivatives = $derivatives['has_derivatives'] && file_exists($derivatives['derivatives_list']['document']->unmanaged_uri);
$hasFilesize = $attachment['filesize'] > 0;
$isImage = strpos($attachment['filemime'], 'image') !== FALSE && file_exists($attachment['url']);
?>
<div class="file-attachments">
  <div class="preview-image">
    <?php if ($hasDerivatives): ?>
      <img class="img-responsive"
           src="<?php $derivatives['derivatives_list']['document']->unmanaged_uri ?>"
           width="90" height="90" alt="derivatives-img">
    <?php elseif ($isImage): ?>
      <img class="img-responsive"
           src="<?php echo $attachment['url'] ?>"
           width="90" height="90" alt="thumbnail-img">
    <?php else:
      echo $attachment['icon']
      ?>
    <?php endif; ?>
  </div>
  <div class="info-section">
    <div class="file-title section-info">
      <?php echo $attachment['file_title'] ?>
    </div>
    <div class="file-user section-info section-info-small">
      <?php
      $output = t('Uploaded from');
      $output .= ' ' . $attachment['username'];
      echo $output
      ?>
    </div>
    <div class="file-date section-info section-info-small">
      <?php
      $output = t('at');
      $output .= ' ' . $attachment['date'];
      echo $output
      ?>
    </div>
  </div>
  <div class="file-download-section">
    <?php if ($hasFilesize): ?>
      <a href="<?php echo $attachment['download_url'] ?>"
         class="download-link"></a>
    <?php endif; ?>
  </div>
</div>
<hr>
