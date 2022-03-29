(function ($) {

  Drupal.behaviors.salto_knowledgebase = {
    attach: function (context, settings) {

      //click on rate content
      $('.salto_rate_content_action').once('salto_knowledgebase').click(function () {
        var self = $(this);
        var star_icon = self.parent().find('i');
        var user_stars = self.closest('div.inside').find('.fivestar-static-item');
        var type = self.attr('data-type');
        var id = self.attr('data-id');
        var content_rating_wrapper = self.closest('div.inside').parent().find('.content_rating_display li');
        var user_rating_wrapper = self.closest('div.inside').parent().find('.content_rating_action li');

        if (user_rating_wrapper.length == 0) {
          user_rating_wrapper = $('.field-name-salto-files-rating-action > .field-items');
          content_rating_wrapper = self.closest('div.inside').parent().find('.field-name-files-rating-view .field-items');
        }

        if (Drupal.behaviors.salto_knowledgebase.vote_widget_state === 'init') {
          vote_widget = $(this).closest('.inside').find('.field-name-field-content-rating').first();
          Drupal.behaviors.salto_knowledgebase.vote_widget_state = 'done';
        }

        //files init state, static counter hiding protection
        if (user_stars.length > 1) {
          user_stars.first().hide();
        }

        star_icon.hide();
        self.before(vote_widget);
        vote_widget.fadeIn().attr('style', 'display: inline-block;');
        vote_widget.attr('rel', 'tooltip');
        vote_widget.attr('title', Drupal.t('Click on one of the 5 stars to rate this content.'));

        Drupal.attachBehaviors(vote_widget.parent());

        //remove title tags for each of the stars
        $(vote_widget).find('a').once('salto_remove_title').removeAttr('title');

        self.hide();

        $(vote_widget).find('a').once('salto_knowledgebase').click(function () {

          $('.tooltip').hide();

          $(document).ajaxComplete(function (a, b, c) {
            if (typeof (c.data) != 'undefined') {
              if (c.data.indexOf('vote=') === 0) {
                $.ajax({
                  url: Drupal.settings.basePath + "knowledge/vote/js/getCurrentVotes/" + type + "/" + id,
                  type: 'GET',
                  dataType: 'json'
                })
                  .done(function (data) {
                    vote_widget.detach();

                    $(content_rating_wrapper).html(data.average);
                    $(user_rating_wrapper).html(data.user);

                    Drupal.attachBehaviors(content_rating_wrapper);
                    Drupal.attachBehaviors(user_rating_wrapper);
                  })
                  .fail(function () {
                    console.log("error");
                  })
                  .always(function () {
                  });
              }
            }
          });

        });

        return false;
      });
    }
  };

  Drupal.behaviors.salto_knowledgebase.vote_widget_state = 'init';

})(jQuery);

