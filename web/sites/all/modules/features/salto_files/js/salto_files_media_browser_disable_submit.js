(function ($) {

  /**
   * disables submit button on form submit to prevent multiple clicking
   */
  Drupal.behaviors.salto_files_wysiwyg = {
    attach: function (context, settings) {
      $(document).ready(function () {

        const form = $("#file-entity-add-upload-multiple");
        const submitButton = $("#edit-next", form);

        // Add an event listener to the form submission
        form.on("submit", function (event) {

          submitButton.prop("disabled", true);

        });

      });
    }
  }
})(jQuery);
