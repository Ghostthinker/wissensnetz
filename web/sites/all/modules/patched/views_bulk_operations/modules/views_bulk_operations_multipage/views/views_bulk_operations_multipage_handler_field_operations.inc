<?php

/**
 * Extends the VBO-field handler to support multipage selection.
 */
class views_bulk_operations_multipage_handler_field_operations extends views_bulk_operations_handler_field_operations {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['vbo_settings']['contains']['multipage'] = array('default' => 0);
    $options['vbo_settings']['contains']['multipage_ignore_exposed_filters'] = array('default' => 0);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['vbo_settings']['multipage'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable multipage selections'),
      '#default_value' => $this->options['vbo_settings']['multipage'],
      '#description' => t('Allow the user to select items belonging to multiple pages.'),
    );

    $form['vbo_settings']['multipage_ignore_exposed_filters'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ignore exposed filters'),
      '#default_value' => $this->options['vbo_settings']['multipage_ignore_exposed_filters'],
      '#description' => t('Ignore exposed filters when performing selections spanning multiple pages. This will disable the "Select all items on all pages" functionality when any exposed filter is populated.'),
      '#states' => array(
        'visible' => array(
          ':input[name="options[vbo_settings][multipage]"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

}
