<?php

/**
 * @file
 * Example tpl file for theming a single model-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 *
 * Helper variables:
 * - $model: The Model object this status is derived from
 */
?>

<div class="model-status">
  <?php print '<strong>Model Sample Data:</strong> ' . $model_sample_data = ($model_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>
