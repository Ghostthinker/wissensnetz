(function ($) {

  'use strict';

  Drupal.behaviors.mentionsTextcomplete = {
    attach: function () {
      var settings = Drupal.settings.mentions.textcomplete;
      var matchExp = new RegExp('\\B' + settings.prefix_regex + '(\\w*)$');
      $.each(settings.forms, function (index, form) {
        $('textarea[id^="' + form + '-value"]').textcomplete([
          {
            form: form,
            match: matchExp,
            search: function (term, callback) {
              var format_id = $('select[id^="' + this.form + '-format"]').val();
              if (!format_id){
                format_id = 'plain_text';
              }
              let formats = settings.formats.map(function(item, index, array) {
                return String(item);
              });
              if ($.inArray(format_id, formats) !== -1) {
                $.getJSON(Drupal.settings.basePath + 'mentions/autocomplete/' + format_id + '/' + term, function (resp) {
                  callback(resp);
                });
              }
              else {
                callback([]);
              }
            },
            replace: function (mention) {

              var match = mention.match('(?<=mention-user-regex">)(.*?)(?=\\<)');
              console.log(match[0]);

              return settings.prefix +  match[0] + settings.suffix + ' ';
            },
            index: 1
          }
        ]);
      });
    }
  };

})(jQuery);
