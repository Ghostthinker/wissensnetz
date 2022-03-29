
document.addEventListener('DOMContentLoaded', function () {
  var checkbox = document.getElementById("edit-invite");
  if (checkbox === null) { return; }

  toggleOnCheck('invite-message-wrap');

  addListingInviteCheckboxMsg();

  function addListingInviteCheckboxMsg() {
    checkbox.addEventListener( 'change', function() {
      toggleOnCheck('invite-message-wrap');
    });
  }

  function toggleOnCheck($id) {
    var content = document.getElementById($id);
    if(checkbox.checked) {
      content.style.display = 'block'
    } else {
      content.style.display = 'none'
    }
  }
});



