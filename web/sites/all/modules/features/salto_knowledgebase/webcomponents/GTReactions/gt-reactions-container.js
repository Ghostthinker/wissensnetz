class GtReactionsContainer extends HTMLElement {

  static get observedAttributes () { return ['type', 'lang']; }

  get buttonConfig() {
    return [
      {
        key: 'like',
        icon: 'like.svg',
        label: {
          de: 'Gefällt mir',
          en: 'like'
        }
      },
      {
        key: 'clapping',
        icon: 'clapping.svg',
        label: {
          de: 'Applaus',
          en: 'clapping'
        }
      },
      {
        key: 'support',
        icon: 'support.svg',
        label: {
          de: 'Unterstütze ich',
          en: 'I support'
        }
      },
      {
        key: 'wonderful',
        icon: 'heart.svg',
        label: {
          de: 'Wunderbar',
          en: 'Wonderful'
        }
      },
      {
        key: 'inspiring',
        icon: 'idea.svg',
        label: {
          de: 'Inspirierend',
          en: 'Inspiring'
        }
      },
      {
        key: 'thoughtful',
        icon: 'thinking.svg',
        label: {
          de: 'Nachdenklich',
          en: 'Thoughtful'
        }
      }
    ]
  }
  constructor () {
    super();

    this.attachShadow({ mode: 'open' });
    this.shadowRoot.appendChild(this.template.cloneNode(true));

    let root = this.shadowRoot;

    this.i18n =
    {
        'en': {
          'react': 'React',
          'like': 'Like',
        },
        'de': {
          'react': 'Reagieren',
          'like': 'Gefällt mir',
        }
    };

 }


   get template () {
    if (this.fragment) return this.fragment;

    const fragment = document.createDocumentFragment();

    let styles = document.createElement('style');
    styles.innerHTML = `/*compress*/:host {
      display: inline-flex;
      --share-button-background-color: transparent;
      --share-button-border: none;
      --share-copy-button-hover-color: #222222;
      --share-button-appearance: button;
      --share-button-border-radius: initial;
      --share-button-color: initial;
      --overlay-background-color: #333333;
      --overlay-background-border: 1px solid #555;
      --overlay-shadow: 0px 2px 5px #333;
    }
    .visible {
      display: block !important;
    }

}


    }
    /*endcompress*/`;

    const button = document.createElement('button');
    button.id = 'react-btn';
    button.innerHTML = '<slot><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24"><path fill="none" d="M0 0h24v24H0z"/><path d="M18 16c-.8 0-1.4.4-2 .8l-7-4v-1.5l7-4c.5.4 1.2.7 2 .7 1.7 0 3-1.3 3-3s-1.3-3-3-3-3 1.3-3 3v.7l-7 4C7.5 9.4 6.8 9 6 9c-1.7 0-3 1.3-3 3s1.3 3 3 3c.8 0 1.5-.3 2-.8l7.2 4.2v.6c0 1.6 1.2 3 2.8 3 1.6 0 3-1.4 3-3s-1.4-3-3-3z"/></svg></slot>';


    fragment.appendChild(styles);
    fragment.appendChild(button);


    this.fragment = fragment;
    return fragment;
  }

  connectedCallback () {
    let root = this.shadowRoot;

    // Sets the background color of the button because we are going to futz it.
    //const defaultButtonStyle = window.getComputedStyle(this.shareBtn);
    //const defaultStyle = window.getComputedStyle(this);
    //const initialBgColor = defaultStyle.getPropertyValue('--share-button-background-color');

    //this.style.setProperty('--share-button-background-color', initialBgColor || defaultButtonStyle.backgroundColor);
    //this.shareBtn.style.backgroundColor = 'var(--share-button-background-color)';

    // Handle click events on the main element.
    this.shadowRoot.addEventListener('click', e => {

      const target = e.target.nodeName;

      if(e.target.nodeName === 'IMG') {
        if(e.target.parentNode.nodeName === 'BUTTON') {
          this.onReactionClicked(e.target.parentNode);
        }else{
          this.onReactionClicked(e.target);
        }
      }


      this.toggleOverlay();

    }, true );

    // Dismiss the overlay on any keypress.
    this.addEventListener('keypress', e => this.toggleOverlay());

    /*
    // Dismiss the overlay on any interaction on the page
    document.documentElement.addEventListener('click', e => {
      if (e.target != root.host) {
        this.hide();
      }
    }, true);
*/

  }

  attributeChangedCallback (attr, oldValue, newValue) {
    // Only the watched attributes will get changed.
    if (oldValue != newValue) {
      this[attr] = newValue;
    }
  }

  get lang () {
    return this.getAttribute('lang');
  }
  set lang (val) {
    if (val) {
      this.updateLang(val);
      this.setAttribute('lang', val);
    } else {
      this.updateLang();
      this.removeAttribute('lang');
    }
  }

  get type () {
    return this.getAttribute('type');
  }

  set type (val) {
    if (val) {
      this.setAttribute('type', val);
    } else {
      this.removeAttribute('type');
    }
  }
  updateLang (lang) {}

  getLang () {
    return this.lang ? this.lang : 'en';
  }

  getString (msg) {
    var lang = this.getLang();
    return this.i18n[lang][msg];
  }

  hide () {
    this.overlay.classList.remove('visible');
  }

  show () {
    this.overlay.classList.add('visible');
  }

  toggleOverlay () {
    // User has clicked on the Share button
    this.overlay.classList.toggle('visible');
  }

  onReactionClicked(button) {

    const key = button.dataset.key;

    this.shadowRoot.dispatchEvent(new CustomEvent("react", {
      bubbles: false,
      composed: true,
      detail: {
        key: key
      }
    }));
  }
}

customElements.define('gt-reactions-button', GtReactionsButton);

export { GtReactionsButton };
