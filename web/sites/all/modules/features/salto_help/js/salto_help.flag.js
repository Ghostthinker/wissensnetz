/**
 * @file

 *  Only stb code
 */
(function ($) {


  Drupal.behaviors.salto_help_flagging = {
    attach: function (context, settings) {

      //flagging
      $('a.flag-action').once('salto_knowledgebase').click(function () {
        //ajax response
        salto_knowledgebase_attach_ajax_actions($(this));
        //immediately hide other possible flagging actions
        $(this).closest('.help-entry-useful-yes-and-no').html(Drupal.t('Thank you for your feedback! Saving...')).hide().fadeIn();

        return false;
      });

      $('a.unflag-action').once('salto_knowledgebase').click(function () {
        //immediately hide other possible flagging actions

        //ajax response
        salto_knowledgebase_attach_ajax_actions($(this));
        $(this).closest('.help-entry-useful-yes-and-no').html(Drupal.t('Resetting...')).hide().fadeIn();

        return false;
      });


      function salto_knowledgebase_attach_ajax_actions(self) {

        var container = self.closest('.help-entry-useful-container');

        var href = self.attr('href');
        var matches = href.match('/(\\d+)\\\?');
        var nid = matches[1];
        var matches_flag = href.match('flag/(.*flag)/(.+)/\\d+\\\?');
        var action = matches_flag[1];
        var flag = matches_flag[2];
        var url = '/salto/help/feedback/' + nid + '/' + flag + '/' + action;

        setTimeout(function () {
          $.ajax({
            type: "GET",
            url: url,
            success: function (response) {

              container.html(response.data);
              Drupal.attachBehaviors(response);


            }
          });
        }, 1000);

        return false;
      }

    }
  };

})(jQuery);

