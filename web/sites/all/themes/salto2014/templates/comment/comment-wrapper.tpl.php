<?php

/**
 * @file
 * Default theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 *
 * @ingroup themeable
 */
$sort = salto_knowledgebase_get_comment_sorting();

?>
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="comments-sorting">
    <?php if ($sort == SALTO_KNOWLEDGEBASE_SORT_COMMENTS_OLDER_FIRST): ?>
      <a
        href="?wn_comment_sorting=<?php echo SALTO_KNOWLEDGEBASE_SORT_COMMENTS_NEWER_FIRST ?>"><?php echo t('Sorted chronologically ascending'); ?></a>
      <span class="arrow-up"></span>
    <?php else: ?>
      <a
        href="?wn_comment_sorting=<?php echo SALTO_KNOWLEDGEBASE_SORT_COMMENTS_OLDER_FIRST ?>"><?php echo t('Sorted chronologically descending') ?></a>
      <span class="arrow-down"></span>
    <?php endif; ?>
    <?php if ($content['comments'] && $node->type != 'forum'): ?>
      <?php print render($title_prefix); ?>
      <h2 class="title"><?php print t('Comments'); ?></h2>
      <?php print render($title_suffix); ?>
    <?php endif; ?>
  </div>

  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
    <?php  print render($content['comment_form']); ?>
  <?php endif; ?>
</div>
