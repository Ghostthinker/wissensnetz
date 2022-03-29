(function ($) {

  /*
   * snippet to allow you to bind events when dom elements are shown hidden with jQuery.
   */
  Drupal.behaviors.salto_organisation_overview = {
    attach: function (context, settings) {

      var val = $('#edit-field-organisation-obscure-und-0-value').val();

      $(".field_organisation_obscure_zs input[value=" + val + "]").prop("checked", true);


      $('.field_organisation_obscure_zs').once().each(function () {
        $(this).find("input:radio").change(function (e) {

          var new_val = $(this).val();
          var self = this;

          if (new_val === "1" && Drupal.settings.salto_obscure_initial_setting == 0) {

            if (Drupal.settings.salto_obscure_num_licenses > 0) {
              var message = Drupal.settings.salto_obscure_change_warn_message;

              bootbox.dialog({
                message: message,
                title: Drupal.t("Change the central storage of license data."),
                buttons: {
                  accept: {
                    label: Drupal.t("Confirm"),
                    className: "btn-danger",
                    callback: function () {
                      $('#edit-field-organisation-obscure-und-0-value').val(1);
                    }
                  },
                  cancel: {
                    label: Drupal.t("Cancel"),
                    className: "btn-cancel",
                    callback: function () {
                      $('#edit-field-organisation-obscure-und-0-value').val(0);
                      $('#edit-field-organisation-zs-1').prop("checked", true);
                    }
                  }
                }
              });
            } else {
              $('#edit-field-organisation-obscure-und-0-value').val(new_val);
            }
          } else {
            $('#edit-field-organisation-obscure-und-0-value').val(new_val);
          }
        })
      });
    }
  }
})(jQuery);
