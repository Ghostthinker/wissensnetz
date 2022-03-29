/**
 * @file

 *  Only stb code
 */
(function ($) {

  Drupal.behaviors.salto_knowledgebase_tabledrag = {
    attach: function (context, settings) {
      //remove drag handles of first depth category elements
      var tds = $('#taxonomy').once('salto_knowledgebase_tabledrag').find('tr>td:first-child').not(".tabledrag-hide");

      //remove draggable class - this will prevent swapping to root when the user drags a term to the topmost category
      $('#taxonomy').once('salto_knowledgebase_tabledrag_2').find('tr.draggable').first().removeClass('draggable');

      $.each(tds, function (key, value) {
        if ($(value).find('.indentation').length === 0) {
          $(value).find('.handle').first().remove();
        }
      });

    }
  };


  Drupal.tableDrag.prototype._validIndentInterval = Drupal.tableDrag.prototype.row.prototype.validIndentInterval;
  Drupal.tableDrag.prototype.row.prototype.validIndentInterval = function (prevRow, nextRow) {
    var minIndent;

    // Minimum indentation:
    var min = 1;

    var orig = Drupal.tableDrag.prototype._validIndentInterval(prevRow, nextRow);
    if (orig.min < 1) {
      min = 1;
    } else {
      min = orig.min;
    }

    if (orig.max < 1) {
      max = 1;
    } else {
      max = orig.max;
    }

    return {'min': min, 'max': max};

  };


})(jQuery);

