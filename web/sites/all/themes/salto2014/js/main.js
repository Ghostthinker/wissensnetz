+function ($) {

  Drupal.behaviors.salto2014 = {
    attach: function (context, settings) {

      jQuery("[rel='tooltip']").tooltip({});
      jQuery('[data-toggle="popover"]').popover();

      //prevent forms from beeing submitted by pressing enter
      $('.node-form').find('input[type="text"]').keydown(function (event) {
        if (event.keyCode == 13) {
          event.preventDefault();
          return false;
        }
      });

      $('.userbar .navbar-user > ul > ul > li > a, .userbar .navbar-burger button').once('salto_theme').on('click', function (event) {
        if (event.target.classList.contains('help-dropdown-link')) {
          event.target.classList.toggle('open');
          if (!event.target.classList.contains('open')) {
            $('#modalContent').hide();
          } else {
            $('#modalContent').slideDown();
          }
        } else {
          var helpOpen = $('.userbar .navbar-user > ul > ul > li a.help-dropdown-link.open');
          if (helpOpen) {
            helpOpen.removeClass('open');
            $('#modalContent').hide();
          }
        }

        if (!event.target.classList.contains('action_account_dropdown')) {
          $('.userbar .navbar-user .action_account_dropdown').parent().removeClass('open');
        }

      });

      Drupal.salto_core.autoshorten(".heartbeat_add_comment blockquote", 65);
      $("[class^=autoshorten]:not(.processed)").each(function () {
        var name = $(this).attr('class');
        var maxlength = 200;
        if (name.lastIndexOf("-") > -1) {
          var i = name.lastIndexOf("-");
          var l = name.length - i;
          maxlength = name.substr(i + 1, l - 1);
        }
        maxlength = parseInt(maxlength);

       Drupal.salto_core.autoshorten(this, maxlength);
      }).addClass("processed");


      //iframe resize
      $("iframe.iframe-auto-resize:not(.iframe-auto-resize-processed)").each(function (e) {

        const options = {
          //maxHeight: 1000
        };
        $(this).iFrameResize(options);


      }).addClass("iframe-auto-resize-processed");

    }
  };


  $(document).ready(function () {

    var form = $(".content-form");
    var StickyContainers = [
      { selector: "header#navbar"},
      { selector: "footer"},
      { selector: ".userbar-desktop"},
    ];

    StickyContainers.forEach(function(item) {
      var stickyContainer = $(item.selector);
      if (form.length > 0 && stickyContainer.length > 0) {
        stickyContainer.css("position", "sticky");
      } else {
        stickyContainer.css("position", "static");
      }
    });

    jQuery("[rel='tooltip']").tooltip({});

    jQuery("img[data-org]").each(function (index, el) {
      var t = jQuery(this);
      var p = t.wrap('<a class="colorbox" href="' + t.attr("data-org") + '"> </a>');
      Drupal.attachBehaviors();
    });

    $('.menu-block-wrapper .expanded > a, .menu-block-wrapper .collapsed > a').append('<span class="arrow"></span>');
    $('.menu-block-wrapper li ul .expanded').not('.active, .active-trail').removeClass('expanded').addClass('collapsed');

    $('.menu-block-wrapper .arrow').bind('click', function (e) {

      e.preventDefault();
      if ($(this).parent().parent().hasClass('expanded')) {
        $(this).parent().parent().removeClass('expanded').addClass('collapsed').children('ul').css('display', 'block').slideUp('slow');
      } else {
        $(this).parent().parent().removeClass('collapsed').addClass('expanded').children('ul').css('display', 'none').slideDown('slow');
      }

      return false;

    });
  });


  function initUserPanes() {
    jQuery('.user-picture:not(".userpane-processed")').bind('hover', function () {
      var e = $(this);
      e.addClass('userpane-processed');
      e.unbind('hover');

      var link = e.parent();
      var url = link.attr("href");

      if (typeof url == 'undefined') {
        return;
      }

      //prevent link from redirect
      link.bind('click', function (ev) {
        ev.preventDefault();
      });

      $.getJSON(url + "/userpane", function (d) {
        e.popover({
          title: d.title,
          content: d.content,
          placement: 'top',
          trigger: 'hover',
          html: true,
          delay: 100
        }).popover('show');
      });
      e.addClass('popover_processed');
    });

  }
}(window.jQuery);
