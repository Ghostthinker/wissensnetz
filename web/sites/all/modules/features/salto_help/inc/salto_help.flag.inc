<?php
/*
 * Help entries flagging
 */

function salto_help_preprocess_node(&$variables) {

  if ($variables['type'] == 'help') {
    $node = $variables['node'];
    $variables['content']['flag_help_entry_useful_yes_and_no'] = [
      '#markup' => salto_help_render_flag_yes_and_no($node->nid),
      '#weight' => 10,
      '#access' => TRUE,
    ];
  }
}

/**
 * render complete yes and no entry feedback including the up and downvotes
 *
 * @param type $nid
 *
 * @return string
 */
function salto_help_render_flag_yes_and_no($nid) {

  $output = '';

  $flag_o_no = flag_get_flag('help_entry_useful_no');
  $flag_o_yes = flag_get_flag('help_entry_useful_yes');

  if (($flag_o_no && $flag_o_no->is_flagged($nid)) || ($flag_o_yes && $flag_o_yes->is_flagged($nid))) {
    //reset mode
    if ($flag_o_yes && $flag_o_yes->is_flagged($nid)) {
      $output .= $flag_o_yes->theme($flag_o_yes->is_flagged($nid) ? 'unflag' : 'flag', $nid, ['needs_wrapping_element' => TRUE]);
    }
    if ($flag_o_no && $flag_o_no->is_flagged($nid)) {
      $output .= $flag_o_no->theme($flag_o_no->is_flagged($nid) ? 'unflag' : 'flag', $nid, ['needs_wrapping_element' => TRUE]);
    }
    $output = '<div class="help-entry-useful-yes-and-no"><div class="help-flag-label"></div>' . $output . '</div>';
  }
  else {
    //initial mode - no option flagged yet
    $output .= $flag_o_yes->theme($flag_o_yes->is_flagged($nid) ? 'unflag' : 'flag', $nid, ['needs_wrapping_element' => TRUE]);
    $output .= $flag_o_no->theme($flag_o_no->is_flagged($nid) ? 'unflag' : 'flag', $nid, ['needs_wrapping_element' => TRUE]);

    $output = '<div class="help-entry-useful-yes-and-no"><div class="help-flag-label">' . t('Was this helpful to you?') . '</div>' . $output . '</div>';
  }


  $tmp_stats = salto_help_render_flag_count($nid);
  $output = ($tmp_stats !== '' ? $tmp_stats . ' | ' : '') . $output;

  $output = '<div class="help-entry-useful-container">' . $output . '</div>';

  return $output;
}

function salto_help_render_flag_count($nid) {

  $output = '';

  $flag_o_no = flag_get_flag('help_entry_useful_no');
  $flag_o_yes = flag_get_flag('help_entry_useful_yes');

  $no_count = $flag_o_no->get_count($nid);
  $yes_count = $flag_o_yes->get_count($nid);
  $sum_count = $no_count + $yes_count;

  $output .= '<div class="help-entry-useful-stats">';
  if ($sum_count > 0) {

    $output .= t('@yes/@sum people found this entry helpful', [
      '@yes' => $yes_count,
      '@sum' => $sum_count,
    ]);
  }
  else {
    return '';
  }
  $output .= '</div>';

  return $output;
}

