
(function ($) {

  jQuery.fn.exampleProcessModalLink = function () {
    var $this = $(this[0]);
    $this.click(Drupal.CTools.Modal.clickAjaxLink);
    // Create a drupal ajax object
    var element_settings = {};
    if ($this.attr('href')) {
      element_settings.url = $this.attr('href');
      element_settings.event = 'click';
      element_settings.progress = {type: 'throbber'};
    }
    var base = $this.attr('href');
    Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
  };


  Drupal.behaviors.salto_help = {
    attach: function (context, settings) {

      //tooltips
      $('a.ctools-modal-salto-style.help-support').tooltip({'title': Drupal.t("Don't hesitate to send us a message if you do have any problems or ideas.")});
      $('a.ctools-modal-salto-style.help-overview').tooltip({'title': Drupal.t("Here you can find the help entries to almost any section of the Bildungsnetz")});
      $('a.ctools-modal-salto-style.help-faq').tooltip({'title': Drupal.t("Please have a look into the FAQ before adressing the support.")});
      $('a.ctools-modal-salto-style.help-screencasts').tooltip({'title': Drupal.t("Here you can watch different screencast videos.")});
      $('a.ctools-modal-salto-style.help-usage').tooltip({'title': Drupal.t("Get to know the difference usage scenarios and best practice examples of the Bildungsnetz")});

      //help ajax comments
      $('.views-field-comment-count').once('salto_help').on('click', function () {
        var self = $(this);
        var regresult = self.find('div').first().attr('class').split('-');
        var nid = regresult.pop();

        Drupal.salto_help.loadCommentsAjax(nid);

        return false;
      });


      $('.help_body .comment-form .form-submit').once('salto_help').on('mousedown', function () {
        var self = $(this);

        var regresult = self.closest('.panel-body').find('.views-field-comment-count div').first().attr('class').split('-');
        var nid = regresult.pop();

        var handler = function () {
          Drupal.salto_help.loadNumComments(nid);
          $(document).unbind("ajaxStop", handler);
        };
        $(document).bind("ajaxStop", handler);
      });
    }
  };

  Drupal.salto_help = Drupal.salto_help || {};

  Drupal.salto_help.loadCommentsAjax = function (nid) {
    //console.log(nid);

    $.ajax({
      url: Drupal.settings.basePath + "salto/help/js/comments/" + nid,
      type: 'GET',
      dataType: 'json'
    })
      .done(function (data) {
        //console.log(data);
        $('.salto-help-comments-wrapper-' + nid).html(data.output);

        Drupal.attachBehaviors();
      })
      .fail(function () {
        console.log("error");
      })
      .always(function () {
      });
  };

  Drupal.salto_help.loadNumComments = function (nid) {

    $.ajax({
      url: Drupal.settings.basePath + "salto/help/js/num_comments/" + nid,
      type: 'GET',
      dataType: 'json'
    })
      .done(function (data) {
        $('.salto-help-comments-wrapper-' + nid).closest('.panel-body').find('.views-field-comment-count a').html(data.output);
        Drupal.attachBehaviors();
      })
      .fail(function () {
        console.log("error");
      })
      .always(function () {
        console.log("complete");
      });
  };
})(jQuery);

