(function (jQuery) {

  Drupal.behaviors.salto_knowledgebase_post_length = {
    attach: function (context, settings) {
      var body = jQuery('#edit-body');
      if (body === null) {
        return;
      }

      var countOpen = 3;
      var nextOpen = 3;

      function openAlert() {
        if (countOpen === nextOpen) {
          var msg = Drupal.t('Attention') + ': ';
          msg += Drupal.t('You has arrived the limit of body text content.');
          msg += Drupal.t('The content will trimmed on maximum char length!');
          bootbox.alert(msg);
          countOpen = 0;
        }
        countOpen++;
      }

      var maxLength = 50000;
      if (Drupal.settings.post_length_max) {
        maxLength = Drupal.settings.post_length_max;
      }

      var currentLength = 0;
      // summary
      var summaryLength = 0;
      body.on('keyup', function () {
        summaryLength = jQuery(this).find('#edit-body-und-0-summary').val().length;
        if (summaryLength >= maxLength / 3) {
          openAlert();
        }
      });

      if (typeof CKEDITOR === 'undefined') {
        return;
      }

      CKEDITOR.on('instanceReady', function (e) {
        if (e.editor.name === 'edit-body-und-0-value') {
          e.editor.on('key', function (es) {
            currentLength = e.editor.getData().length;
            if (currentLength >= maxLength) {
              openAlert();
            }
          });
        }
      });
    }
  }
}(jQuery));
