<?php

/**
 * @file
 * Default theme implementation to display a flag link, and a message after the
 * action is carried out.
 *
 * Available variables:
 *
 * - $flag: The flag object itself. You will only need to use it when the
 *   following variables don't suffice.
 * - $flag_name_css: The flag name, with all "_" replaced with "-". For use in
 *   'class' attributes.
 * - $flag_classes: A space-separated list of CSS classes that should be applied
 *   to the link.
 *
 * - $action: The action the link is about to carry out, either "flag" or
 *   "unflag".
 * - $status: The status of the item; either "flagged" or "unflagged".
 *
 * - $link_href: The URL for the flag link.
 * - $link_text: The text to show for the link.
 * - $link_title: The title attribute for the link.
 *
 * - $message_text: The long message to show after a flag action has been
 *   carried out.
 * - $message_classes: A space-separated list of CSS classes that should be
 *   applied to
 *   the message.
 * - $after_flagging: This template is called for the link both before and after
 *   being
 *   flagged. If displaying to the user immediately after flagging, this value
 *   will be boolean TRUE. This is usually used in conjunction with immedate
 *   JavaScript-based toggling of flags.
 * - $needs_wrapping_element: Determines whether the flag displays a wrapping
 *   HTML DIV element.
 *
 * Template suggestions available, listed from the most specific template to
 * the least. Drupal will use the most specific template it finds:
 * - flag--name.tpl.php
 * - flag--link-type.tpl.php
 *
 * NOTE: This template spaces out the <span> tags for clarity only. When doing
 * some advanced theming you may have to remove all the whitespace.
 */

$tooltip_flagged_state = t('You are subscribed for this content. Click the icon on the right, to unsubscribe.');


/**
 * Special label for groups subscription flags
 */
if ($flag->entity_type == 'node') {

  $node = node_load($entity_id);
  if ($node->type == 'group') {
    if ($action == 'flag') {
      $link_title = t('Click here to subscribe for this group.');
    }
    else {
      $tooltip_flagged_state = t('You have subscribed this group. Click the icon on the right, to unsubscribe.');
      $link_title = t('Click here to unsubscribe from this group and its content.');
    }
  }
}


$request_uri = request_uri();

$node_context = FALSE;
if (arg(0) == 'node' && is_numeric(arg(1)) || arg(0) == 'file' && is_numeric(arg(1))) {
  $node_context = TRUE;
}
if (!$node_context) {
  $parsed_url = parse_url($request_uri);
  $query = drupal_get_query_array($parsed_url['query']);
  if (!empty($query['destination'])) {
    $query_array = explode('/', $query['destination']);
    if (count($query_array) == 2 && ($query_array[0] == 'node' || $query_array[0] == 'file') && is_numeric($query_array[1])) {
      $node_context = TRUE;
    }
  }
}

/////////////////////////////////////
//Prepare subscribe and Ignore widget
/////////////////////////////////////

/** @var bool $show_state_action_pane If true, the action link is divided into two different areas (state|action-icon) */
$show_state_action_pane = FALSE;

if ($node_context == FALSE) {
  $show_state_action_pane = FALSE;
}
else {

  //process Subscribe flag
  if ($flag->name == "notification_subscribe_node" || $flag->name == "notification_subscribe_material") {

    if ($status == 'flagged') {
      $show_state_action_pane = TRUE;
    }
    else {
      $show_state_action_pane = FALSE;
    }
  }

  //process Ignore flag
  if ($flag->name == "notification_ignore_post" || $flag->name == "notification_ignore_material") {

    if ($status == 'flagged') {
      $show_state_action_pane = FALSE;
      $link_text = t('Ignored');
    }
    else {
      $show_state_action_pane = TRUE;
      $link_text = t('Auto-Subscribed');
      $link_title = t('Click here to ignore this post.');
    }
  }
}

?>
<?php if ($needs_wrapping_element): ?>
<div class="flag-outer flag-outer-<?php print $flag_name_css; ?>">
  <?php endif; ?>
  <span class="<?php print $flag_wrapper_classes . ' ' . $flag->name; ?>">
    <?php if ($link_href): ?>
      <?php
      if (!$show_state_action_pane) : ?>
        <?php if ($link_text == t('Subscribed') && !$node_context) {
          $link_text = t("Cancel notification");
        } ?>

        <a href="<?php print $link_href; ?>" title="<?php print $link_title; ?>"
           class="<?php print $flag_classes ?>"
           rel="tooltip"><?php print $link_text; ?></a>
        <span class="flag-throbber">&nbsp;</span>
      <?php else: ?>
        <div class="action-link col-md-12">
          <div class="row">
            <div class="col-md-8 status flagged" rel="tooltip"
                 title="<?php echo $tooltip_flagged_state; ?>"><?php print $link_text; ?></div>
            <div class="col-md-4 action-unflag">
              <a href="<?php print $link_href; ?>"
                 title="<?php print $link_title; ?>" rel="tooltip"
                 class="<?php print $flag_classes ?>" rel="nofollow"> </a>
              <span class="flag-throbber"></span></div>
          </div>
        </div>
      <?php endif; ?>
    <?php else: ?>
      <span class="<?php print $flag_classes ?>"><?php print $link_text; ?></span>
    <?php endif; ?>
    <?php if ($after_flagging): ?>
      <span class="<?php print $message_classes; ?>">
        <?php print $message_text; ?>
    </span>
    <?php endif; ?>
    </span>
  <?php if ($needs_wrapping_element): ?>
</div>
<?php endif; ?>
