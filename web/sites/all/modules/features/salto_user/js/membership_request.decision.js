(function ($) {
  var buttonsSelector = '.views-field-membership-request-button .btn-view-row';
  var modalId = 'modal_membership_requests';
  var buttonIdAccept = 'btn#mr-accept';
  var buttonIdDecline = 'btn#mr-decline';

  var modal;
  var alert;

  var MemberRequestModal = function (modalId, buttonsSelector) {
    var data = {};
    // Get the modal
    var modal = document.getElementById(modalId);

    function capitalizeFirstAllWords(str, separator = '.') {
      var pieces = str.split(separator);
      for (var i = 0; i < pieces.length; i++) {
        var j = pieces[i].charAt(0).toUpperCase();
        pieces[i] = j + pieces[i].substr(1);
      }
      return pieces;
    }

    function addClickListener() {
      var btn = document.querySelectorAll(buttonsSelector);
      for (var k = 0; k < btn.length; k++) {
        btn[k].addEventListener("click", function () {
          data.uid = this.dataset.uid;
          data.uuid = this.dataset.uuid;
          data.name = this.dataset.name;

          var sub = modal.querySelector('.modal-content p.subtitle');
          var h2 = modal.querySelector('.modal-content h2');
          modal.querySelector('.modal-content .btn-success').style.display = 'block';
          modal.querySelector('.modal-content .btn-decline').style.display = 'block';
          if (this.classList.contains('btn-success')) {
            h2.innerHTML = Drupal.t('Membership request accept');
            sub.innerHTML = Drupal.t('Accept the membership request of');
            modal.querySelector('.modal-content .btn-decline').style.display = 'none';
          } else {
            h2.innerHTML = Drupal.t('Membership request decline');
            sub.innerHTML = Drupal.t('Decline the membership request of');
            modal.querySelector('.modal-content .btn-success').style.display = 'none';
          }
          var idx = data.name.indexOf('_');
          var name = data.name.substring(0, idx);
          sub.innerHTML += ' ' + capitalizeFirstAllWords(name).join(' ');

          modal.style.display = "block";
        });
      }
    }

    var btnA = document.getElementById(buttonIdAccept);
    btnA.onclick = function () {
      data.message = modal.querySelector('.message textarea').value
      sendAccept(data);
    };

    var btnD = document.getElementById(buttonIdDecline);
    btnD.onclick = function () {
      data.message = modal.querySelector('.message textarea').value
      sendDecline(data);
    };

    // Get the <span> element that closes the modal
    var closeEl = modal.getElementsByClassName("close")[0];
    // When the user clicks on <span> (x), close the modal
    closeEl.onclick = function () {
      modal.style.display = 'none';
      alert.classList.remove('alert-warning');
      alert.style.display = 'none';
    }

    addClickListener();

    // When the user clicks anywhere outside of the modal, close it
    window.addEventListener("click", function (event) {
      if (event.target.id == modalId) {
        modal.style.display = 'none';
        alert.classList.remove('alert-warning');
        alert.style.display = 'none';
      }
    });
  };

  document.addEventListener('DOMContentLoaded', function () {
    modal = document.getElementById(modalId);
    alert = modal.querySelector('.alert');
    new MemberRequestModal(modalId, buttonsSelector);
  });

  function removeRow(uuid) {
    var el = document.querySelector(`.views-row[data-uuid="${uuid}"]`)
    if (el !== null) {
      el.remove();
    }
    modal.style.display = 'none';
  }

  function showError(error) {
    alert.classList.add('alert-warning');
    alert.innerText = error;
    alert.style.display = 'block';
  }

  function handleResponse(data) {
    if (data.status == 200) {
      removeRow(data.uuid);
    }
    if (data.error) {
      showError(data.error);
    }
  }

  function sendAccept(obj) {
    $.post('/membership/requests/' + obj.uuid + '/accept', obj, function (data) {
      data.uuid = obj.uuid;
      handleResponse(data);
    });
  }

  function sendDecline(obj) {
    $.post('/membership/requests/' + obj.uuid + '/decline', obj, function (data) {
      data.uuid = obj.uuid;
      handleResponse(data);
    });
  }
})(jQuery);
