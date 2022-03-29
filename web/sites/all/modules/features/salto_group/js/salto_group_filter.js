(function ($) {

  Drupal.behaviors.salto_groups_filter = {
    attach: function (context, settings) {
      //exposed filter

      if ($('#edit-field-group-target-audience-role-value').length > 0) {
        $('#edit-field-group-target-audience-role-value').chosen();
      }

      $('.views-exposed-form .views-exposed-widgets').once('salto_group_filter').find('input').not(':input[type=hidden]').each(function () {
        var p = $(this).closest('.views-exposed-widget');
        var self = $(this);

        if (self.val().length > 0 && self.val() !== ' ') {
          Drupal.salto_group_filter.init(self, p);
        }

      });
    }
  };

  Drupal.salto_group_filter = {
    init: function (self, p) {
      p.append("<a class='reset-field' title='" + Drupal.t("Reset") + "'></a>");
      p.css('display', 'inline-block');

      p.find(".reset-field").click(function (e) {
        self.val("");
        $(this).hide();
        self.closest("form").submit();
      });
    }
  }

}(jQuery));
