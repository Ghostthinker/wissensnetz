/**
 * @file
 */
(function ($) {

  Drupal.behaviors.salto_group = {
    attach: function (context, settings) {
      if ($('#edit-field-group-target-audience-role-und').length > 0) {
        $('#edit-field-group-target-audience-role-und').chosen();
      }


      //action links groups  .pane-groups-panel-groups-directory .action-links a
      //group action links
      $('.group-actions.action-links a').once('salto_group').click(function () {
        var self = $(this);
        var container = self.closest('.action-links');
        var href = self.attr('href');

        //check if this is an ajax action
        if (href.indexOf('groups/join/') > 0) {

          var url = href;
          var tml_html = container.find("> a").first().html();
          var html_spin = ' <i class="icon glyphicon glyphicon-refresh glyphicon-spin" aria-hidden="true"></i>';
          container.find(" > a").first().html(tml_html + html_spin);

          $.ajax({
            type: "GET",
            url: url,
            success: function (response) {
              container.html(response.data);
              Drupal.attachBehaviors(response);
            }
          });

          return false;
        }
      });

      if ($('#edit-field-post-collaboration-und-0-read option[value="3"]').text() === '') {
        $('#edit-field-post-collaboration-und-0-read option[value="3"]').remove();
        $('#edit-field-post-collaboration-und-0-edit option[value="3"]').remove();
      }

      $('#edit-field-og-group-und-0-default').change(function (){

        const selectedOption = $(this).val();
        const selectedText = $('option:selected', this).text();

        if ($('#edit-field-post-collaboration-und-0-read option[value="3"]').length > 0) {
          $('#edit-field-post-collaboration-und-0-read option[value="3"]').remove();
          $('#edit-field-post-collaboration-und-0-edit option[value="3"]').remove();
        }

        if(selectedOption === '_none'){
          return;
        }

        $('#edit-field-post-collaboration-und-0-read').append($('<option>', {
          value: '3',
          text: Drupal.t('Only group') + ' "' + selectedText + '"'
        })).val(3);

        $('#edit-field-post-collaboration-und-0-edit').append($('<option>', {
          value: '3',
          text: Drupal.t('Only group') + ' "' + selectedText + '"'
        })).val(3);


      });


      //manager action links on members
      $('.salto-og-action-links a').once('salto_group').click(function () {
        //ajax response
        var self = $(this);
        var container = self.closest('.member-actions');

        var href = self.attr('href');

        //remove is no ajax action
        if (href.length > 1 && href.indexOf('/remove') == -1) {

          var url = href;
          var tml_html = container.find("> div > a").first().html();
          var html_spin = ' <i class="icon glyphicon glyphicon-refresh glyphicon-spin" aria-hidden="true"></i>';
          container.find("> div > a").first().html(tml_html + html_spin);

          $.ajax({
            type: "GET",
            url: url,
            success: function (response) {
              location.reload();
            }
          });

          return false;
        }
      });
    }
  };

  Drupal.behaviors.salto_group_manage_categories = {
    attach: function (context, settings) {

      //set local storage variable to check if save has been triggered on iframe leave event
      sessionStorage.setItem("salto_group_structore_saving", 0);

      $("[name='group-structure-posts']").load(function () {
        $(this).height($(this).contents().find("body").height());

      });

      $("[name='group-structure-materials']").load(function () {
        $(this).height($(this).contents().find("body").height());

      });


      $(".salto-group-double-submit").click(function () {
        window.frames[0].postMessage("salto-submit", "*");
        window.frames[1].postMessage("salto-submit", "*");

        setTimeout(function () {
          window.parent.location.reload();
        }, 100)
      });


    }
  };

})(jQuery);

