(function ($) {

  var salto_core_slider_autoscroll;
  var salto_core_slider_timer = 6000;

  Drupal.behaviors.salto_core_slider = {
    attach: function (context, settings) {

      //prevent attaching multiple behavior
      if (typeof (salto_core_slider_autoscroll) === 'undefined') {
        var self = this;

        salto_core_slider_timer = Drupal.settings.salto_core.salto_core_frontpage_slider_interval;

        salto_core_slider_autoscroll = window.setInterval(function () {
          self.next()
        }, salto_core_slider_timer);

        var slider = $(".view-home-tabs");

        // pause on hover
        slider.mouseover(function (e) {
          //stop slider
          salto_core_slider_autoscroll = clearInterval(salto_core_slider_autoscroll);
        });
        slider.mouseout(function (e) {
          //start slider
          clearInterval(salto_core_slider_autoscroll);
          salto_core_slider_autoscroll = window.setInterval(function () {
            self.next()
          }, salto_core_slider_timer);
        });
      }
    },

    next: function () {
      var active_li = $(".view-home-tabs .views-bootstrap-tab-plugin-style .nav-tabs  li.active");
      var tab_divs = $(".view-home-tabs .views-bootstrap-tab-plugin-style .tab-content .tab-pane");

      //first to last
      if (active_li.next().length > 0) {
        active_li.removeClass('active');
        active_li.next().addClass('active');

        //switch to next tab
        tab_divs.eq(active_li.index()).removeClass('active');
        tab_divs.eq(active_li.index() + 1).addClass('active');

      } else {
        //last to first
        active_li.removeClass('active');
        active_li.siblings().first().addClass('active');

        //switch to first tab
        tab_divs.eq(active_li.index()).removeClass('active');
        tab_divs.eq(0).addClass('active');

      }
    }
  }

})(jQuery);
