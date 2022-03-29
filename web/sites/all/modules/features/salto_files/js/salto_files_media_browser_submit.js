(function($) {

    /**
     * Submits Mediabrowser Form selection form automatically
     */
    Drupal.behaviors.salto_files_wysiwyg = {
        attach: function(context, settings) {
     $(document).ready(function() {

        if($("#file_privacy_info", parent.window.document).length == 0) {
          $("#edit-body", parent.window.document).prepend('<div class="alert alert-block alert-info" id="file_privacy_info"><a class="close" data-dismiss="alert" href="#">×</a>' + Drupal.t('Please notice, that read and write access of files used in this post will automatically beeing set.') + '</div>');
        }
        // Grab values etc from the current parent form fields and alter media format form values (roll your own code here).
        // Find the submit button and click it - code from media.format_form.js
        var buttons = $(parent.window.document.body).find('#mediaStyleSelector').parent('.ui-dialog').find('.ui-dialog-buttonpane button');
        buttons[0].click();

      });
    }
  }
})(jQuery);
