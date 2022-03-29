<?php
/**
 * @file
 * views-aggregator-results-table.tpl.php
 *
 * Template to display views results after aggregation as a table.
 *
 * This template is based on the one in the Views module:
 * views/themes/views-view-table.tpl.php
 *
 * - $title : The title of this group of rows. May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $grouping_field_class: A class to apply to cells in the group aggregation
 *   column
 * - $totals_row_class: A class to apply to the column aggregation row
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * - $totals_row_position: whether to show the totals row at top, bottom or
 *   both
 * @ingroup views_templates
 */

?>
<table
  <?php if ($classes): ?>class="<?php print $classes; ?>"<?php endif ?><?php print $attributes; ?>>
  <?php if (!empty($title) || !empty($caption)) : ?>
    <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <thead>
  <?php if (!empty($header)) : ?>
    <!--<tr>
          <?php
    foreach ($header as $field => $label):
      $hclasses = isset($header_classes[$field]) ? $header_classes[$field] : '';
      if ($field === $grouping_field) {
        $hclasses .= " $grouping_field_class";
      }
      ?>
            <th <?php if (!empty($hclasses)): ?>class="<?php print $hclasses; ?>"<?php endif ?>>
              <?php print $label; ?>
            </th>
          <?php endforeach ?>
            </tr>-->
    <tr>
      <th rowspan="2"><?php print ($header['ea_name']); ?></th>
      <th colspan="4">Neu ausgestellte Lizenzen</th>
      <th colspan="4">Verlängerte Lizenzen</th>
      <th colspan="4">Gültige Lizenzen</th>
    </tr>
    <tr>
      <th
        title="männlich"><?php print (str_replace(" m ", " männlich ", $header['lid'])); ?></th>
      <th
        title="weiblich"><?php print (str_replace(" w ", " weiblich ", $header['lid_1'])); ?></th>
      <th
        title="unbekannt"><?php print (str_replace(" u ", " unbekannt ", $header['lid_2'])); ?></th>
      <th
        title="gesamt"><?php print (str_replace(" g ", " gesamt ", $header['lid_3'])); ?></th>
      <th
        title="männlich"><?php print (str_replace(" m ", " männlich ", $header['lid_4'])); ?></th>
      <th
        title="weiblich"><?php print (str_replace(" w ", " weiblich ", $header['lid_5'])); ?></th>
      <th
        title="unbekannt"><?php print (str_replace(" u ", " unbekannt ", $header['lid_6'])); ?></th>
      <th
        title="gesamt"><?php print (str_replace(" g ", " gesamt ", $header['lid_7'])); ?></th>
      <th
        title="männlich"><?php print (str_replace(" m ", " männlich ", $header['lid_8'])); ?></th>
      <th
        title="weiblich"><?php print (str_replace(" w ", " weiblich ", $header['lid_9'])); ?></th>
      <th
        title="unbekannt"><?php print (str_replace(" u ", " unbekannt ", $header['lid_10'])); ?></th>
      <th
        title="gesamt"><?php print (str_replace(" g ", " gesamt ", $header['lid_11'])); ?></th>
    </tr>
  <?php endif; ?>
  <?php if (($totals_row_position & 1) && !empty($totals)) : ?>
    <tr
      <?php if (!empty($totals_row_class)): ?>class="<?php print $totals_row_class; ?>"<?php endif ?>>
      <?php
      // Use order of the row fields to output the totals likewise.
      foreach (array_keys(reset($rows)) as $field):
        $hclasses = isset($header_classes[$field]) ? $header_classes[$field] : '';
        if ($field === $grouping_field) {
          $hclasses .= " $grouping_field_class";
        }
        ?>
        <th
          <?php if (!empty($hclasses)): ?>class="<?php print $hclasses; ?>"<?php endif ?>>
          <?php print isset($totals[$field]) ? $totals[$field] : ''; ?>
        </th>
      <?php endforeach ?>
    </tr>
  <?php endif; ?>
  </thead>
  <tbody>
  <?php foreach ($rows as $r => $row): ?>
    <tr
      <?php if (!empty($row_classes[$r])): ?>class="<?php print implode(' ', $row_classes[$r]); ?>"<?php endif ?>>
      <?php foreach ($row as $field => $content):
        $td_class = empty($field_classes[$field][$r]) ? '' : $field_classes[$field][$r];
        if ($field === $grouping_field) {
          $td_class .= " $grouping_field_class";
        }
        ?>
        <td
          <?php if (!empty($td_class)): ?>class="<?php print $td_class; ?>"<?php endif ?>
          <?php if (!empty($field_attributes[$field][$r])): ?><?php print drupal_attributes($field_attributes[$field][$r]); ?><?php endif ?>>
          <?php print $content; ?>
        </td>
      <?php endforeach ?>
    </tr>
  <?php endforeach ?>
  </tbody>
  <?php if (($totals_row_position & 2) && !empty($totals)) : ?>
    <tfoot>
    <tr
      <?php if (!empty($totals_row_class)): ?>class="<?php print $totals_row_class; ?>"<?php endif ?>>
      <?php
      // Use order of the row fields to output the totals likewise.
      foreach (array_keys(reset($rows)) as $field):
        $fclasses = isset($field_classes[$field]) ? reset($field_classes[$field]) : '';
        if ($field === $grouping_field) {
          $fclasses .= " $grouping_field_class";
        }
        ?>
        <th
          <?php if (!empty($fclasses)): ?>class="<?php print $fclasses; ?>"<?php endif ?>>
          <?php print isset($totals[$field]) ? $totals[$field] : ''; ?>
        </th>
      <?php endforeach ?>
    </tr>
    </tfoot>
  <?php endif ?>
</table>
