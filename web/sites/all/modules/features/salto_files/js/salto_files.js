(function ($) {

  /**
   * Submits media-file attachment automatically
   */

  Drupal.behaviors.salto_files = {
    attach: function (context, settings) {
      //fix form-control problem
      $('input[type="text"]:not([class*="form-control"]), select:not([class*="form-control"]), textarea:not([class*="form-control"])').addClass('form-control');

      //create the logic for Lizenzstufen checkboxes
      $('#edit-field-file-lizenzstufe-und').find('input').once('salto-files-check-change').bind('change', function () {
        Drupal.salto_files.check_lizenzstufe_toggle($(this));
      });

      //fire data toggle on load. Hmm, no better way to do it??
      $('#edit-field-file-lizenzstufe-und').find('input').once('salto-files-check-init').each(function () {
        Drupal.salto_files.check_lizenzstufe_toggle($(this));
      });

      if ($('#edit-field-teaser-image-und-0-ajax-wrapper').length > 0) {
        resizeImage('#edit-field-teaser-image-und-0-ajax-wrapper');
      }

      if ($('#edit-field-term-image-und-0-ajax-wrapper').length > 0) {
        resizeImage('#edit-field-term-image-und-0-ajax-wrapper');
        resizeImage('#edit-field-term-icon-und-0-ajax-wrapper');
      }

      function resizeImage(id){
        const fileSpan = $(id + ' .file');
        const fileSizeSpan = $(id + ' .file-size');
        const imgElement = fileSpan.find('img');
        const aElement = fileSpan.find('a');

        if (aElement.length > 0) {
          imgElement.attr('src', aElement.attr('href')).css('max-width', '20rem');
          aElement.remove();
          fileSizeSpan.remove();
        }
      }

    }

  };

  Drupal.salto_files = {};

  Drupal.salto_files.check_lizenzstufe_toggle = function (elem) {

    var el_val = $(elem).val();
    var $self = $(elem);

    if (el_val == 0) {
      $(elem).closest("#edit-field-file-lizenzstufe-und").find("input").each(function () {
        var val = $(this).val();
        if (val != 0) {
          //toggle others
          if ($self.is(':checked')) {
            $(this).prop('disabled', true);
          } else {
            $(this).prop('disabled', false);
          }
        }
      });
    } else {
      var others_on = false;
      $(elem).closest("#edit-field-file-lizenzstufe-und").find("input").each(function () {
        //check all values except 0. if one is checked disable the others
        var val = $(this).val();
        if (val != 0) {
          if ($(this).is(':checked')) {
            others_on = true;
          }
        }
      });
      //at least one of the others is on -> disable value 0
      if (others_on) {
        $('#edit-field-file-lizenzstufe-und-0').prop('disabled', true);
      } else {
        $('#edit-field-file-lizenzstufe-und-0').prop('disabled', false);
      }
    }
  };

  Drupal.behaviors.salto_files_buttons = {
    attach: function (context, settings) {

      $('.file_action_buttons').each(function () {
        var parent = $(this).parents('.draggable').find('td:last-child');
        if (!$(parent).hasClass('insertLink')) {
          var buttons = $(this).clone(true);
          $(parent).prepend(buttons);
          $(parent).addClass('insertLink');
          //$(this).parent().remove( $(this) );
          $(buttons).removeClass('hide');
        }
      });

    }
  };

  Drupal.behaviors.salto_files_modal_close = {
    attach: function (context, settings) {

      //close button - deattach click event
      setTimeout(function () {
        $("#modalContent .ctools-close-modal").once("salto_files_off").off('click');

        $("#modalContent .ctools-close-modal").once("salto_files").click(function (e) {
          Drupal.CTools.Modal.dismiss();
        });

      }, 10);


    }
  };

})(jQuery);


(function ($) {
  if (typeof (Drupal.tableDrag) !== 'undefined') {
    Drupal.tableDrag.prototype.hideColumns();
  }

})(jQuery);
