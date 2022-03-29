(function (jQuery) {


  Drupal.behaviors.salto_knowledgebase_attachment_default = {
    attach: function (context, settings) {
      var modal = jQuery('#modalContent');
      var parentDoc = null;
      if (modal !== null) {
        parentDoc = document;
      }

      setAttachmentTitle();
      if (salto_knowledgebase_inIframe() || window.frameElement !== null) {
        parentDoc = window.frameElement.ownerDocument;
      }

      if (parentDoc === null) {
        return;
      }

      jQuery(parentDoc).find("#edit-field-kb-content-category input:checked").each(function () {

        var val_post = jQuery(this).val();
        var val_file;

        //get match from sync_array
        if (Drupal.settings.themenfelder_snyc_array.hasOwnProperty("tid-" + val_post)) {
          val_file = Drupal.settings.themenfelder_snyc_array["tid-" + val_post];
        }

        var checkBoxFile = jQuery(".field-name-field-kb-kategorie input[value=" + val_file + "]");

        if (typeof checkBoxFile !== 'undefined' || checkBoxFile === null) {
          checkBoxFile.prop('checked', true);
        }
      });

    }
  };

  function setAttachmentTitle() {
    var modal = jQuery('#modalContent');
    jQuery(modal).ready(function () {
      //Save button, the title set in attachment
      jQuery(modal).find('button.form-submit').click(function () {
        var ref = jQuery(modal).find('#file-entity-edit').attr('action');
        //Title or ImageTitle
        var title = jQuery('#edit-field-file-title input').val() || jQuery('#edit-field-file-image-title-text input').val();
        jQuery(document).find('#edit-field-post-attachment .ctools-modal-media-file-edit.attachment_link').each(function () {
          var href = jQuery(this).attr('href');
          if (href.indexOf(ref) > -1) {
            jQuery(this).parent().parent().parent().find('[id*="file-attachment-title"]').val(title);
          }
        });
      });

      //Title on Attachment in ctools modal
      jQuery(document).find('#edit-field-post-attachment [id*="file-attachment-title"]').each(function () {
        var title = jQuery(this).val();
        var ref = jQuery(modal).find('#file-entity-edit').attr('action');
        var href = jQuery(this).parent().parent().find('.ctools-modal-media-file-edit.attachment_link').attr('href');
        if (typeof ref !== 'undefined' && ref.indexOf(href) > -1) {
          //Title
          jQuery('#edit-field-file-title input').val(title);
          //Image-Title
          jQuery('#edit-field-file-image-title-text input').val(title);
        }
      });
    });
  }

  /**
   check if js is executed in a iframe
   */
  function salto_knowledgebase_inIframe() {
    try {
      return window.self !== window.top;
    } catch (e) {
      return true;
    }
  }
}(jQuery));
