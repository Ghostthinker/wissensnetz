document.addEventListener('DOMContentLoaded', function (evt) {
  var containerSelectQuery = '#privatemsg-list-form .container-inline select.form-control';

  var selectorLabel = '.form-item.checkbox label';
  var elements = document.querySelectorAll('#privatemsg-list-form tr');
  //console.log(elements);
  for (var tr of elements) {
    if (tr.querySelector(selectorLabel) == null) { continue; }
    if (tr.classList.contains('privatemsg-unread')) {
      tr.querySelector(selectorLabel).addEventListener("click", setRead);
    } else {
      tr.querySelector(selectorLabel).addEventListener("click", setUnread);
    }

    var source = tr.getElementsByTagName('td');
    //console.log(source);
    tr.appendChild(source[0]);
  }

  function setRead() {
    var selector = containerSelectQuery + ' [value="mark as read"]';
    //console.log(selector);
    document.querySelector(selector).selected = true;
    triggerSubmit();
  }

  function setUnread() {
    var selector = containerSelectQuery + ' [value="mark as unread"]';
    //console.log(selector);
    document.querySelector(selector).selected = true;
    triggerSubmit();
  }
  function triggerSubmit() {
    setTimeout(function () {
      var selector = '#privatemsg-list-form .container-inline button.btn.btn-default.form-submit';
      document.querySelector(selector).click();
    }, 50);
  }
});
