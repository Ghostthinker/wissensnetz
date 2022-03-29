/**
 * @file
 */
(function () {
  Drupal.behaviors.salto_help_screencast = {
    attach: function (context, settings) {
      document.querySelector('ul.nav.nav-tabs').style = 'display: none;';
      if (!settings.nodeId) {
        return;
      }
      var nodeId = settings.nodeId;
      var links = document.querySelectorAll('.views-field-comments-link a.ajax-comments-add-comment');
      for (var link of links) {
        if (link.getAttribute('href').indexOf(nodeId) > 0) {
          var parent = link.closest('div.panel-collapse.collapse');
          parent.classList.add('in');
        }
      }
      var video = document.querySelector('.panel-collapse.collapse.in video');
      if (video == null) {
        return;
      }
      video.play();
    }
  };
})();

