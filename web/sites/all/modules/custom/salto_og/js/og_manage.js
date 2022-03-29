/**
 * @file
 */
(function ($) {

    Drupal.behaviors.salto_og = {
        attach: function (context, settings) {

            //manager action links on members
            $('.salto-og-action-links a').once('salto_group').click(function () {
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

                            container.html(response.actions);

                            //remove membership item
                            if (response.details == -1) {
                                container.closest('.views-row').hide();
                                return;
                            }

                            //set role
                            if (response.details) {
                                container.closest('.views-row').find('.groups-members-state').html(response.details);
                            }

                            Drupal.attachBehaviors(response);
                        }
                    });

                    return false;
                }
            });
        }
    };

})(jQuery);

