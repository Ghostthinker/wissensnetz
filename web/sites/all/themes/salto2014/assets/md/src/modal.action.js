
var ModalAction = function(modalId, buttonId) {
    // Get the modal
    var modal = document.getElementById(modalId);

    // Get the button that opens the modal
    var btn = document.getElementById(buttonId);

    // When the user clicks the button, open the modal
    btn.onclick = function() {
        modal.style.display = "block";
    };

    // Get the <span> element that closes the modal
    var closeEl = modal.getElementsByClassName("close")[0];
    // When the user clicks on <span> (x), close the modal
    closeEl.onclick = function() {
        modal.style.display = "none";
    }


    // When the user clicks anywhere outside of the modal, close it
    window.addEventListener("click", function (event) {
      if (event.target.id == modalId) {
        modal.style.display = "none";
      }
    });
};
