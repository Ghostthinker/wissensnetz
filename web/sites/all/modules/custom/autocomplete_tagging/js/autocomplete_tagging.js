/**
 * @file

 *  Creates a tab by the scrollbar for help
 */
(function ($) {

  Drupal.behaviors.autocomplet_tagging = {
    attach: function (context, settings) {
      $('#privatemsg-new .form-item-recipient').once(function () {
        var taginput = $(this).find('input');

        var options = {}
        taginput.tokenInput("/user/autocomplete_tagging", options);
      });


      $('.autocomplete-tagging').once(function () {

        var form_group = $($(this).closest('.form-group.form-wrapper'));

        form_group.find('.form-autocomplete').append('<div class="tags" ></div><input class="autocomplete-token-input" />');

        var taginput = form_group.find('.autocomplete-token-input');
        var valueinput = $(this);

        if (valueinput == null) {
          return;
        }

        form_group.find('.input-group').hide();
        taginput.attr('placeholder', Drupal.t('Add another author..'));

        var uids = [];
        valueinput.val().replace(/\((.+?)\)/g, function ($0, $1) {
          uids.push($1)
        });

        //load users
        $.ajax({
          dataType: "json",
          url: '/user/autocomplete_tagging/preload',
          data: {uid: uids},
          success: function (data) {
            var options = {
              queryParam: '',
              prePopulate: data,
              preventDuplicates: true,
              theme: 'minimal',
              onAdd: function (item) {
                valueinput.val(valueinput.val() + ", " + item.name + " (" + item.id + ")");
                data.push(item);
              },
              onDelete: function (item) {
                var new_string_val = '';
                var new_data = [];
                $.each(data, function (key, val) {

                  if (val) {
                    if (val.id != item.id) {
                      new_string_val += ", " + val.name + " (" + val.id + ")";
                      new_data.push(val);
                    }
                  } else {
                  }
                });
                data = new_data;
                valueinput.val(new_string_val);
              },
              tokenFormatter: function (item) {
                return "<li>" + item.image + item.name + "</li>"
              },
              resultsFormatter: function (item) {
                return "<li>" + item.image + item.name + "</li>"
              },
              hintText: Drupal.t("Type in a name"),
              noResultsText: Drupal.t("No results"),
              searchingText: Drupal.t("Searching..."),
            };

            taginput.tokenInput("/user/autocomplete_tagging", options);
            $(".autocomplete-tagging .token-input-input-token-minimal input").attr('placeholder', Drupal.t('Add another author..'));
          }
        });


      });
    }
  };

})(jQuery);
