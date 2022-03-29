
var Toolbar = {
  listener: function(evt) {
    evt.preventDefault();
    Toolbar.goBack();
  },
  goBack: function() {
    window.history.go(-1);
  }
};

var backBtn = document.getElementById('goBackHistory');
if (backBtn !== null) {
  init();

  function init() {
    if (window.history.length < 3) { return; }
    backBtn.setAttribute('href', '#');
    backBtn.addEventListener('click', Toolbar.listener);
    backBtn.addEventListener('touchend', Toolbar.listener);
  }
}
