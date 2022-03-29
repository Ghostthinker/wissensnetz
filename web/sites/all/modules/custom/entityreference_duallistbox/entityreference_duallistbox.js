(function ($) {
  Drupal.behaviors.entityreference_duallistbox = {
    attach: function (context, settings) {
      Drupal.entityreference_duallistbox.init("id");
      $(".entityreference_duallistbox .form-type-checkbox").each(function () {
        Drupal.entityreference_duallistbox.update(this, false);
      });
    }
  };

  Drupal.entityreference_duallistbox = {

    init: function (id) {
      var _self = this;
      $(".entityreference_duallistbox .fulltext_filter:not('.processed')").keyup(function (e) {
        var query = $(this).val();

        var pool = $(this).closest('.pool-body');

        _self.all_items = pool.find('.form-type-checkbox');
        if (query.length < 1) {
          _self.all_items.css("display", "block");
          return;
        }

        var foundin = pool.find('.form-type-checkbox label:containsNC("' + query + '")').parent();
        _self.all_items.css("display", "none");
        foundin.css("display", "block");
      }).addClass('processed');

      $(".entityreference_duallistbox .form-type-checkbox .form-checkbox:not('.processed')").click(function (e) {
        Drupal.entityreference_duallistbox.update($(this).closest("div"), true);
      }).addClass('processed');
    },
    update: function (context, nop) {
      var selection = $(context).closest(".entityreference_duallistbox").find(".selected-items");
      var pool = $(context).closest(".entityreference_duallistbox").find(".pool-items");

      if ($(context).find("input.form-checkbox").attr("checked")) {

        $(context).appendTo(selection);
      } else {
        if (nop) {
          $(context).prependTo(pool);
        }
      }
    }
  }

})(jQuery);
