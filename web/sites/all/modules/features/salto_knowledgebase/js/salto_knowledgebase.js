/**
 * @file

 *  Only stb code
 */
(function ($) {

  Drupal.behaviors.salto_knowledgebase = {
    attach: function (context, settings) {
      // CO-802
      // Check the first checkbox by default
      if (Drupal.settings.attachment_svp_preselect && $('input.attachment_preview:checked').length == 0) {
        $('input.attachment_preview:first').prop('checked', true);
      }

      // Handle checkbox click event
      $('input.attachment_preview').click(function(){
        // Uncheck all checkboxes except the one that was clicked
        $('input.attachment_preview').not(this).prop('checked', false);
      });

      if (location.hash == "#edit-comment-body") {
        setTimeout(() => {
          $('.comment-form textarea').once('salto_knowledgebase-focus').focus();
        }, 300)
      }

      $('.reaction-actions .comment-button').once('salto_knowledgebase-focus').click(() => {
        setTimeout(() => {
          $('.comment-form textarea').focus();
        }, 500)
      });

      $('.salto_rate_content_action').once('salto_knowledgebase').click(function(){
        var self = $(this);
        var star_icon = self.parent().find('i');
        var user_stars = self.closest('div.inside').find('.fivestar-static-item');
        var type = self.attr('data-type');
        var id = self.attr('data-id');
        var content_rating_wrapper = self.closest('div.inside').parent().find('.content_rating_display li');
        var user_rating_wrapper = self.closest('div.inside').parent().find('.content_rating_action li');

        if(user_rating_wrapper.length == 0) {
          user_rating_wrapper = $('.field-name-salto-files-rating-action > .field-items');
          content_rating_wrapper = self.closest('div.inside').parent().find('.field-name-files-rating-view .field-items');
        }

        if(Drupal.behaviors.salto_knowledgebase.vote_widget_state === 'init') {
          vote_widget = $(this).closest('.inside').find('.field-name-field-content-rating').first();
          Drupal.behaviors.salto_knowledgebase.vote_widget_state = 'done';
        }

        //files init state, static counter hiding protection
        if(user_stars.length > 1) {
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

        //hide link
        self.hide();

        $(vote_widget).find('a').once('salto_knowledgebase').click(function(){
          $('.tooltip').hide();
          $( document ).ajaxComplete(function(a, b, c) {
            if(typeof(c.data) != 'undefined') {
              if(c.data.indexOf('vote=') === 0) {
                $.ajax({
                  url: Drupal.settings.basePath + "knowledge/vote/js/getCurrentVotes/" + type + "/" + id,
                  type: 'GET',
                  dataType: 'json'
                })
                .done(function(data) {
                  vote_widget.detach();

                  $(content_rating_wrapper).html(data.average);
                  $(user_rating_wrapper).html(data.user);

                  Drupal.attachBehaviors(content_rating_wrapper);
                  Drupal.attachBehaviors(user_rating_wrapper);
                })
                .fail(function() {
                  console.log("error");
                })
                .always(function() {
                });
              }
            }
          });

          });

        return false;
      });

      $('gt-reactions-button').once("salto_knowledgebase").on('check', function () {
      });

      new Drupal.PostController();
    }

  };
  Drupal.PostController = function () {
    var self = this;

    $('.form-item-field-publishing-options-und:not("post-processed")').each(function(){

      $('.form-item-field-publishing-date-und-0-value-date .control-label').html('Datum');
      $('.form-item-field-publishing-date-und-0-value-time .control-label').html('Uhrzeit');
      $('.field-name-field-publishing-options').append($('.field-name-field-publishing-date'));

      $('input[name="field_publishing_options[und]').change(function() {
        self.toggle(this.value);
      });

      let val_init = $('input[name="field_publishing_options[und]').filter(":checked").val()
      self.toggle(val_init);

    }).addClass("post-processed")
  };
  Drupal.PostController.prototype.toggle = function(val) {

    if(val == 'cron') {
      $('#edit-field-publishing-date-und-0-value').show();
      $('.field-name-field-publishing-options').parent().css('max-height', 350);

    }else{
      $('#edit-field-publishing-date-und-0-value').hide();
    }

  }

  Drupal.behaviors.salto_knowledgebase.vote_widget_state = 'init' ;

 })(jQuery);

