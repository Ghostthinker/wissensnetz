/**
 * @file

 *  Only stb code
 */
(function ($) {

  Drupal.behaviors.salto_knowledgebase_reactions = {
    attach: function (context, settings) {

      $('.reaction-footer .reaction-summary, .comment .reaction-summary, .file .reaction-summary').once("salto_knowledgebase").each(function() {

        if($(this).html()) {
          const data = JSON.parse($(this).html());
          const type = $(this).data('entity-type');
          const id = $(this).data('entity-id');
          if (data) {
            Drupal.reactionController.updateReactions(type, id, data);
          }
        } else {
          //just show the flex container
          $(this).css({display:'flex'});
        }

      });

      $(document).ready(function() {
        $('.statistics').each(function() {
          var $reactionSummary = $(this).find('.reaction-summary');
          if ($reactionSummary.children().length === 0) {
            //$(this).find('span').css('margin-left', '-0.5rem');
          }
          else{
            $(this).find('span').css('margin-left', 'unset');
          }
        });
      });

      $('gt-reactions-button').once("salto_knowledgebase-react").on('react', function (e) {
        const type = $(this).data('entity-type');
        const id = $(this).data('entity-id');

        const reaction = e.originalEvent.detail.key;

        Drupal.reactionController.sendData(type, id, reaction);
      })
    }
  };


  class ReactionController {

    constructor() {

    }

    sendData(type, id, reaction) {
      let url = Drupal.settings.basePath + 'api/reactions/' + type + '/' + id;
      $.ajax({
        url: url,
        type: 'post',
        dataType: 'json',

        data: {'tag': reaction, 'id': id},
        success: (response) => {
          this.updateReactions(type, id, response)
        },
        error: function () {
        }
      });
    }

    updateReactions(type, nid, data) {

      let sum = 0;
      let itemsToRender = '';
      data.forEach(item => {

        const v = Drupal.settings.salto_reactions.find(i => i.key === item.tag);

        if (v) {
          sum += parseInt(item.count);
          itemsToRender += `<img src='${v.icon}' title="${item.count}">`;
        }

      });

      let newValue = '';

      if (sum > 0) {
        newValue = `${itemsToRender} ${sum} &nbsp;`;
      }


      $('.reaction-summary[data-entity-type="' + type + '"][data-entity-id="' + nid + '"]').html(newValue);
      $('.reaction-summary[data-entity-type="' + type + '"][data-entity-id="' + nid + '"]').css({display:'flex'});

      var $reactionSummary = $('.reaction-summary[data-entity-type="' + type + '"][data-entity-id="' + nid + '"]');
      if ($reactionSummary.children().length === 0) {
        //$('.reaction-summary[data-entity-type="' + type + '"][data-entity-id="' + nid + '"]').closest('.statistics').find('span').css('margin-left', '-0.5rem');
      }
      else{
        //$('.reaction-summary[data-entity-type="' + type + '"][data-entity-id="' + nid + '"]').closest('.statistics').find('span').css('margin-left', 'unset');
      }

    }
  }

  Drupal.reactionController = new ReactionController();

})(jQuery);
