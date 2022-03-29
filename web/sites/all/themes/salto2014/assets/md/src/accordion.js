var AccordionImpl = function (obj) {
  var buttonClassName = obj ? obj.buttonClassName : 'accordion-button';
  var containerClassName = obj ? obj.containerClassName : 'accordion-container';

  buttonClassName = buttonClassName || 'accordion-button';
  containerClassName = containerClassName || 'accordion-container';

  // add a click listener on buttons for toggle accordions
  function addClickListener() {
    var acc = document.getElementsByClassName(buttonClassName);
    for (var k = 0; k < acc.length; k++) {
      acc[k].classList.add("has-listener");
      acc[k].addEventListener("click", function () {
        this.classList.toggle('active');
        resizeMaxHeight(this);
      });
    }
  }

    function resizeMaxHeight(el) {
      if (!el) { return; }
      var panel = el.nextElementSibling;
      panel.style.maxHeight = null;
      panel.style.overflow = null;
      if (el.classList.contains('active')) {
        panel.style.maxHeight = panel.scrollHeight + "px";
        panel.style.overflow = 'visible';
      }
    }

    function handleDesktop() {
      var acc = document.getElementsByClassName(containerClassName);
      var width = getBrowserWidth();
      for (var k = 0; k < acc.length; k++) {
        var button = acc[k].getElementsByClassName(buttonClassName)[0];
        if (width > 767) {
          acc[k].classList.add('desktop');
          if (!button) { continue; }
          button.classList.add('active');
        } else {
          acc[k].classList.remove('desktop');
        }
        resizeMaxHeight(button);
      }
    }

    // init mobile or desktop (open accordions, disable modals)
    document.addEventListener('DOMContentLoaded', function () {
      addClickListener();
      handleDesktop();
    });

    // listing resize
    window.addEventListener('resize', function () {
      handleDesktop();
    });

    // listing for attachment => add new file scale height
    var atts = document.querySelectorAll('.' + containerClassName + '.attachment');
    for (var att of atts) {
      if (att === null) { continue; }
      att.addEventListener('DOMNodeInserted', function (evt) {
        var button = this.getElementsByClassName(buttonClassName)[0];
        if (button === null) { return; }
        resizeMaxHeight(button);
      }, false);
    }

    // scalable comments
    var textAreaWrapperClassName = '.form-textarea-wrapper.resizable';
    addTextAreaListener();

    function addTextAreaListener() {
      var areas = document.querySelectorAll(textAreaWrapperClassName);
      for (var k = 0; k < areas.length; k++) {
        if (areas[k].classList.contains('has-listener')) {
          continue;
        }
        areas[k].classList.add("has-listener");
        areas[k].addEventListener("mouseover", function () {
          handleDesktop();
        });
      }
    }

    var actionButtonsWrapper = '.links.list-inline';
    var actionButtons = document.querySelectorAll(actionButtonsWrapper);
    for (var k = 0; k < actionButtons.length; k++) {
      actionButtons[k].classList.add("has-listener");
      var list = actionButtons[k].getElementsByTagName('a');
      for (var l = 0; l < list.length; l++) {
        list[l].addEventListener("click", function () {
          setTimeout(function () {
            addTextAreaListener();
            handleDesktop();
          }, 150);
        });
      }
    }

    // scalable taxonomy terms
    var treeClassName = '#edit-field-kb-content-category';//'.term-reference-tree-level';
    addTreeAttrListener();

    function addTreeAttrListener() {
      var areas = document.querySelectorAll(treeClassName);
      for (var k = 0; k < areas.length; k++) {
        if (areas[k].classList.contains('has-listener')) {
          continue;
        }
        areas[k].classList.add("has-listener");

        // accordion element = parent (button) needed for resize
        if (!areas[k].parentNode || !areas[k].parentNode.parentNode) { return; }
        var button = areas[k].parentNode.parentNode.getElementsByClassName(buttonClassName)[0];
        if (!button) { return; }

        // observer for listing style changes (display subtree)
        var observer = new MutationObserver(function(mutationsList, observer) {
          resizeMaxHeight(button);
        });
        observer.observe(areas[k], { attributes: true, childList: false, subtree: true });
      }
    }
};

// check exists Accordion, behind two instance are blocking
if (!window.Accordion) {
  var Accordion = new function () {
    new AccordionImpl({});
  };
}

function getBrowserWidth() {
  return window.innerWidth
    || document.documentElement.clientWidth
    || document.body.clientWidth;
}

function getBrowserHeight() {
  return  window.innerHeight
    || document.documentElement.clientHeight
    || document.body.clientHeight;
}
