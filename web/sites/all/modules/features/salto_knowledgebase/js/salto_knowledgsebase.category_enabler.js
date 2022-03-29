(function ($) {

  Drupal.behaviors.salto_licences_category_enabler = {
    attach: function (context, settings) {
      //each category field in group context (should oly be oane actually)
      $(".form-item-field-kb-content-category-und .category_switcher").once('salto_licences_category_enabler').each(function () {
        Drupal.salto_knowledgebase.set_category_widget(this);
      });
    }
  };

  Drupal.salto_knowledgebase = Drupal.salto_knowledgebase || {};

  /**
   * set the select widget for category select
   * @param elem
   */
  Drupal.salto_knowledgebase.set_category_widget = function (elem) {

    var cb = document.createElement("INPUT");
    cb.setAttribute("type", "checkbox");
    var span = document.createElement("SPAN");
    span.setAttribute("class", "checker");
    span.appendChild(cb);
    var label = document.createElement("SPAN");
    label.setAttribute("class", "checker_info");
    label.innerHTML = Drupal.t("Optional categorize");
    span.appendChild(label);
    $(elem).append(span);

    //initialize - check if a value is selected
    if ($('#edit-field-kb-content-category-und').val() !== '_none') {
      cb.checked = true;
    }
    var comprehensive_option = $('#edit-field-kb-content-category-und option[value="_none"]');

    //set the disabled according to the state of the select
    $('#edit-field-kb-content-category-und').prop('disabled', !cb.checked);

    //init description
    if (!cb.checked) {
      console.log('123');
      $('#edit-field-kb-content-category .help-block').css('display', 'none');
    }

    cb.addEventListener('change', function () {

      //toggle disabled state
      $('#edit-field-kb-content-category-und').prop('disabled', !cb.checked);
      $('#edit-field-kb-content-category .help-block').toggle();

      //set "none" als select option. This is actually not really needed
      if (!cb.checked) {
        comprehensive_option.attr('selected', true);
      } else {
      }
    });

  };
})(jQuery);

