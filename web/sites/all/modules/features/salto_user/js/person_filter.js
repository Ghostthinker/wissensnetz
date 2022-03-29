(function ($) {

  Drupal.behaviors.person_filter = {

    attach: function (context, settings) {
      $('#views-exposed-form-people-directory .views-exposed-widgets').once('person_filter').find('input').not(':input[type=hidden]').each(function () {
        var p = $(this).closest('.views-exposed-widget');
        var self = $(this);

        if (self.val().length > 0 && self.val() !== '- Alle -') {
          Drupal.salto_person_filter.init(self, p);
        }


      });
    }
  };

  Drupal.salto_person_filter = {
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
