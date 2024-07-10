(function ($) {

  /*
   * snippet to allow you to bind events when dom elements are shown hidden with jQuery.
   */

  Drupal.behaviors.salto_core = {
    attach: function (context, settings) {

      if (typeof (Drupal.tableDrag) !== 'undefined') {
        Drupal.tableDrag.prototype.hideColumns();
        $('.tabledrag-toggle-weight').text('');
      }

      //autoshorten comments in heartbeat
      $.each(['show', 'hide'], function (i, ev) {
        var el = $.fn[ev];
        $.fn[ev] = function () {
          this.trigger(ev);
          return el.apply(this, arguments);
        };
      });

      /**
       * open external links in a new window
       */
      $(document).ready(function ($) {
        $('a').once('salto_core').not('[href*="mailto:"]').each(function () {
          var a = new RegExp('/' + window.location.host + '/');
          var href = this.href;
          if (!a.test(href)) {
            $(this).attr('target', '_blank');
          }
        });
      });

      //open files in a new window
      $(function () {
        $('a').filter(function () {
          return this.href.match(/\.([0-9a-z]+)(?:[\?#]|$)/i);
        }).attr('target', '_blank');
      });
    }
  }


  Drupal.salto_core = Drupal.salto_core || {};

  Drupal.salto_core.autoshorten = function (selector, maxlength) {
    $(selector).readmore({
      heightMargin: 10,
      maxHeight: maxlength,
      moreLink: '<a href="#">' + Drupal.t('more') + ' ▾</a>',
      lessLink: '<a href="#">' + Drupal.t('less') + ' ▴</a>',
      wordBreak: true
    });
  }

  Drupal.salto_core.storeValue = function (key, value) {
    if (localStorage) {
      localStorage.setItem(key, value);
    } else {
      $.cookies.set(key, value);
    }
  }

  Drupal.salto_core.getStoredValue = function (key) {
    if (localStorage) {
      return localStorage.getItem(key);
    } else {
      return $.cookies.get(key);
    }
  }

  Drupal.salto_core.getUrlParameter = function getUrlParameter(sParam) {
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
      sURLVariables = sPageURL.split('&'),
      sParameterName,
      i;

    for (i = 0; i < sURLVariables.length; i++) {
      sParameterName = sURLVariables[i].split('=');

      if (sParameterName[0] === sParam) {
        return sParameterName[1] === undefined ? true : sParameterName[1];
      }
    }
  };

  /**
   * Format a date Object as dd.mm.YYYY
   * @param date
   * @returns {string}
   */
  Drupal.salto_core.formatSimpleDate = function (date) {

    var day = date.getDate();
    var month = date.getMonth() + 1;
    var year = date.getFullYear();

    var date_string = ('0' + day).slice(-2) + '.' + ('0' + month).slice(-2) + '.' + year;
    return date_string;

  }

  /**
   * Convert a german date d.m.y into a unix timestamp
   * @param date_string
   * @returns {number}
   */
  Drupal.salto_core.datestring_to_timestamp = function (date_string) {

    var ts = 0;
    try {
      var date_string_parts = date_string.split('.');
      ts = new Date(date_string_parts[2], date_string_parts[1] - 1, date_string_parts[0]).getTime();
    } catch (e) {
    }

    return ts;
  };

  Drupal.salto_core.showPlayerModal = function (url, title) {
    bootbox.dialog({
      message: "<div class=modal-titel>" + title + "</div><iframe allowfullscreen sandbox=\"allow-same-origin allow-scripts allow-popups allow-forms allow-modals allow-top-navigation-by-user-activation\" allow=\"fullscreen; clipboard-read; clipboard-write; microphone; camera\" style='width:100%; height: calc(100% - 1rem); border:none' src='" + url + "'></iframe>",
      className: "video-modal"
    });
  }


  /**
   * Get last day of the current quarter of date
   * @param date
   * @returns {*}
   */
  Drupal.salto_core.get_next_date_quarter = function (date) {


    var year = date.getFullYear();

    var q1 = new Date('March 31, ' + year);
    var q1_ts = q1.getTime();
    var q2 = new Date('June 30, ' + year);
    var q2_ts = q2.getTime();
    var q3 = new Date('September 30, ' + year);
    var q3_ts = q3.getTime();
    var q4 = new Date('December 31, ' + year);
    var q4_ts = q4.getTime();

    var date_ts = date.getTime();

    if (date_ts <= q1_ts) {
      return q1;
    }

    if (date_ts <= q2_ts) {
      return q2;
    }

    if (date_ts <= q3_ts) {
      return q3;
    }

    if (date_ts <= q4_ts) {
      return q4;
    }
    return null;
  }

  $.extend($.expr[':'], {
    'containsNC': function (elem, i, match, array) {
      return (elem.textContent || elem.innerText || '').toLowerCase().indexOf((match[3] || '').toLowerCase()) >= 0;
    }
  });

})(jQuery);
