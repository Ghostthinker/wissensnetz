(function ($) {

  Drupal.behaviors.vboMultipage = {
    attach: function(context) {
      $('.vbo-views-form form', context).once('vbo-multipage', function () {
        var $form = $(this);
        if ($form.data('vboMultipageId')) {
          Drupal.vbo.multipage.initTableBehaviors($form);
          Drupal.vbo.multipage.initFormBehaviors($form);
          $('input.vbo-select', $form).each(function () {
            Drupal.vbo.multipage.initUpdateSelectionBehaviors(this);
          });
        }
      });
    }
  };

  Drupal.vbo = Drupal.vbo || {};
  Drupal.vbo.multipage = Drupal.vbo.multipage || {};

  /**
   * Initializes the table behaviors.
   */
  Drupal.vbo.multipage.initTableBehaviors = function ($form) {
    var vboMultipageId = $form.data('vboMultipageId');

    // Remove the "Select all rows" widget if needed.
    var selectAllMarkup = $('.vbo-table-select-all-markup', $form);
    if (!Drupal.settings.vbo.multipage[vboMultipageId].selectAllRowsEnabled) {
      selectAllMarkup.remove();
      $('.views-table-row-select-all', $form).remove();
    }

    // Attach event handlers to the "Select all ..." buttons.
    if (selectAllMarkup.length) {
      $('.vbo-table-select-all-pages', $form).click(function () {
        Drupal.vbo.multipage.tableSelectAllPages.call(this, $form);
        return false;
      });
      $('.vbo-table-select-this-page', $form).click(function () {
        Drupal.vbo.multipage.tableSelectThisPage.call(this, $form);
        return false;
      });
    }

    // Attach event handlers to the "Select all" checkbox.
    var $selectAll = $('.vbo-table-select-all', $form)
      .click(function () {
        Drupal.vbo.multipage.tableSelectAll.call(this, $form);
      });

    // Initialize the "Select all" widget status if needed.
    $form.data('selectAllRows', false);
    if (Drupal.settings.vbo && Drupal.settings.vbo.multipage && Drupal.settings.vbo.multipage[vboMultipageId].showSelectAllRows) {
      $selectAll.prop('checked', 'checked');
      $('.views-table-row-select-all', $form).show();
      Drupal.vbo.tableSelectAllPages($form);
      $form.data('selectAllRows', true);
    }
  };

  /**
   * Initialize the form behaviors.
   */
  Drupal.vbo.multipage.initFormBehaviors = function ($form) {
    // If we have pending selection requests we cannot submit the form, thus we
    // record whether the user tried to submit it to be able to automatically
    // submit it as soon as all requests complete.
    Drupal.vbo.multipage.setPendingSelectionCount($form, 0);
    $form.on('submit', function (event) {
      if (Drupal.vbo.multipage.getPendingSelectionCount($form) > 0) {
        event.preventDefault();
        $form
          .addClass('vbo-multipage-form-submitted')
          .addClass('form-disabled')
          .find('.form-submit')
          .attr('disabled', 'disabled');
      }
    });
  };

  /**
   * Returns the number of pending selection requests.
   */
  Drupal.vbo.multipage.getPendingSelectionCount = function ($form) {
    return $form.data('vbo-multipage-updating-selection');
  };

  /**
   * Sets the number of pending selection requests.
   */
  Drupal.vbo.multipage.setPendingSelectionCount = function ($form, count) {
    $form.data('vbo-multipage-updating-selection', count);
  };

  /**
   * Updates the number of pending selection requests.
   */
  Drupal.vbo.multipage.updatePendingSelectionCount = function ($form, delta) {
    var count = Drupal.vbo.multipage.getPendingSelectionCount($form);
    Drupal.vbo.multipage.setPendingSelectionCount($form, count += delta);
    return count;
  };

  /**
   * Handles clicks on the "Select all" checkbox.
   */
  Drupal.vbo.multipage.tableSelectAll = function ($form) {
    if (this.checked) {
      Drupal.vbo.multipage.tableSelectThisPage.call(this, $form);
    }
    else {
      // If the checkbox was unselected and the "Select all rows" button was
      // active, we clear the whole selection, otherwise we unselect only the
      // current items.
      var itemIds = {};
      if ($form.data('selectAllRows')) {
        itemIds = {'flush': 1};
      }
      else {
        $('.vbo-select:not(:disabled)', $form).each(function () {
          itemIds[$(this).val()] = 0;
        });
      }
      Drupal.vbo.multipage.updateSelection($form.data('vboMultipageId'), itemIds, $form);
      $form.data('selectAllRows', false);
    }
  };

  /**
   * Handles clicks on the "Select all rows in all pages" button.
   */
  Drupal.vbo.multipage.tableSelectAllPages = function ($form) {
    $form.data('selectAllRows', true);
    Drupal.vbo.multipage.updateSelection($form.data('vboMultipageId'), {'all_rows': 1}, $form);
  };

  /**
   * Handles clicks on the "Select all rows in this page" button.
   */
  Drupal.vbo.multipage.tableSelectThisPage = function ($form) {
    $form.data('selectAllRows', false);
    var itemIds = {'all_rows': 0};
    $(this)
      .closest('table')
      .find('.vbo-select:not(:disabled):checked')
      .each(function () {
        itemIds[$(this).val()] = 1;
      });
    Drupal.vbo.multipage.updateSelection($form.data('vboMultipageId'), itemIds, $form);
  };

  /**
   * Initializes the selection checkbox behaviors.
   */
  Drupal.vbo.multipage.initUpdateSelectionBehaviors = function (checkbox) {
    var $checkbox = $(checkbox),
      $form = $checkbox.closest('form');
    $checkbox.click(function () {
      var itemIds = {};
      itemIds[$checkbox.val()] = this.checked ? 1 : 0;
      Drupal.vbo.multipage.updateSelection($form.data('vboMultipageId'), itemIds, $form);
    });
  };

  /**
   * Updates selection data with the specified items.
   */
  Drupal.vbo.multipage.updateSelection = function (vboMultipageId, itemIds, $form) {
    // Mark this request as pending.
    Drupal.vbo.multipage.updatePendingSelectionCount($form, 1);

    var
      success = $.proxy(Drupal.vbo.multipage.onSelectionSuccess, $form),
      error = $.proxy(Drupal.vbo.multipage.onSelectionError, $form),
      data = {
        'vbo_multipage_id': vboMultipageId,
        'item_ids': itemIds,
        'token': Drupal.settings.vbo.multipage[vboMultipageId].token
      };

    // Invoke the JS front controller if available, otherwise fall back to a
    // regular AJAX call.
    if ($.fn.jsCallback) {
      $.fn.jsCallback('views_bulk_operations_multipage', 'selection_update', {
        data: data,
        success: success,
        error: error
      });
    }
    else {
      $.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + 'views-bulk-operations/multipage/selection-update',
        dataType: 'json',
        data: data,
        success: success,
        error: error
      });
    }
  };

  /**
   * Handles a successful selection.
   */
  Drupal.vbo.multipage.onSelectionSuccess = function () {
    // Mark the selection request as complete.
    var $form = $(this),
      count = Drupal.vbo.multipage.updatePendingSelectionCount($form, -1);
    // Automatically submit the VBO form if needed.
    if (count === 0 && $form.hasClass('vbo-multipage-form-submitted')) {
      $form.submit();
    }
  };

  /**
   * Handles an error while performing a selection.
   */
  Drupal.vbo.multipage.onSelectionError = function () {
    alert(Drupal.t('An error has occurred while performing the selection.'))
  };

})(jQuery);
