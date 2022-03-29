
var Chips = new function () {
    var acc = document.getElementsByClassName('chip');

    for (var k = 0; k < acc.length; k++) {
      if (acc[k].classList.contains('has-listener')) { continue; }

      // init
      var cb = acc[k].getElementsByClassName('form-checkbox')[0];
      if (cb.checked) {
        acc[k].classList.toggle('checked');
      }

      // listener
      acc[k].classList.add('has-listener');
      cb.addEventListener('click', function (evt) {
        toggleParentClass(evt.target);
      });
    }

  function toggleParentClass(element) {
    var parent = element.closest('label.chip');
    parent.classList.toggle('checked');
  }
};
