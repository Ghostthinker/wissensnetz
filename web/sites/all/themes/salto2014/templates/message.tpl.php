<?php

/**
 * @file
 * Default theme implementation for message entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available,
 *   where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_message()
 * @see template_process()
 */
?>

<div class="<?php print $classes; ?> clearfix card"<?php print $attributes; ?>>
  <div class="row card-content" <?php if (!empty($tooltip)) {
    echo 'title="' . $tooltip . '"';
  } ?>>
    <div class="col-md-12">
      <?php print $user_picture; ?>
      <a class="message-link" href="<?php print $url ?>">
        <?php print $main_content ?>
      </a>
      <?php if (!empty($content_preview)) : ?>
        <div class="message-content-preview">
          <?php print($content_preview); ?>
        </div>
      <?php endif ?>
      <div class="message-links">
        <?php print($links); ?>
      </div>
    </div>
  </div>
</div>

