class GtReactionsButton extends HTMLElement {

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
        icon: 'wonderful.svg',
        label: {
          de: 'Wunderbar',
          en: 'Wonderful'
        }
      },
      {
        key: 'inspiring',
        icon: 'inspiring.svg',
        label: {
          de: 'Inspirierend',
          en: 'Inspiring'
        }
      },
      {
        key: 'thoughtful',
        icon: 'thoughtful.svg',
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
    this.overlayTimer = null;
    this.overlayHidingFlag = false;

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



    this.reactBtn = root.getElementById('react-btn');
    this.overlay = root.getElementById('overlay');
    this.urlbar = root.getElementById('urlbar');
    this.url = root.getElementById('url');
    this.copy = root.getElementById('copy');
    this.message = root.getElementById('message');

    // translate
    //let i18nString = 'messageText';
    //this.message.textContent = this.message.textContent.replace('{{' + i18nString + '}}', this.getString(i18nString));
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
      --overlay-border-radius: 2em;
      --overlay-background-color: #fefefe;
      --overlay-background-border: none;
      --overlay-shadow: 0px 2px 5px #666;
    }
    .visible {
      display: block !important;
    }
    #share-btn {
      -webkit-appearance: var(--share-button-appearance);
      -moz-appearance: var(--share-button-appearance);
      appearance: var(--share-button-appearance);
      border: var(--share-button-border);
      border-radius: var(--share-button-border-radius);
      color: var(--share-button-color);
      width: 100%;
      height: inherit;
      display: flex;
      flex-direction: row;
      align-items: center;
      justify-content: center;
      flex-shrink: 1;
      text-transform: inherit;
      font: inherit;
      margin: 0;
      padding: 0;
      vertical-align: baseline;
    }
    #overlay {
      background-color: var(--overlay-background-color);
      border-radius: var(--overlay-border-radius);
      visibility: hidden;
      padding: 0.5em;
      margin: auto;
      margin-top: -5em;
      box-shadow: var(--overlay-shadow);
      position: absolute;
      display: flex;
      opacity:0;
      transition:visibility 0.1s linear, opacity 0.1s linear;
      border: var(--overlay-background-border);
    }
    #overlay.visible {
      display: inline-block !important;
      visibility: visible;
      opacity:1;
    }
    #services {
      padding-left: 0;
    }
    div.buttons {
      overflow-x: auto;
      display: flex;
      flex-direction: row;
    }
    slot[name=buttons]::slotted(*) {
      min-height: 1em;
      margin-top: 1em;
    }
    slot[name=clipboard]::slotted(*) {
      width: 100%;
      height: 100%;
    }
    slot[name=buttons]:empty {
      display: none;
    }
    #urlbar {
      display: flex;
      flex-direction: row;
      align-items: center;
    }
    #message {
      font-size: 1em;
      display: none;
      flex-basis: fit-content;
      align-items: center;
      padding-right: 0.5em;
    }

    #gt-reactions-container {
      display: flex;
      justify-content: space-around;
      align-content: space-between;
      align-items: center;
    }
    #gt-reactions-container > button {
      background:none;
      border:none;
      cursor:pointer;
      width:40px;
      height: 40px;
      cursor: pointer;
    }
    #react-btn {
      border: 0;
      background: transparent;
      width: 100%;
      cursor: pointer;
      text-align: left;
      padding: 0;
    }
    .bounce,
    .bounce-hover:hover {
      -webkit-animation: bounce 1s;
      animation: bounce 1s;
      -webkit-animation-iteration-count: 1;
      animation-iteration-count: 1;
    }
    @-webkit-keyframes bounce {
         0% {
           -webkit-transform: translateY(0);
           transform: translateY(0);
           transform: scale(1.2);
         }
         10% {
           -webkit-transform: translateY(-10px);
           transform: translateY(-10px);
           transform: scale(1.5);
          }
         }

       @keyframes bounce {
           0% {
           -webkit-transform: translateY(0);
           transform: translateY(0);
           transform: scale(1);
         }
         10% {
           -webkit-transform: translateY(-10px);
           transform: translateY(-10px);
           transform: scale(1.5);
         }
        }

    }
    /*endcompress*/`;


    const reactButton = document.createElement('button');
     reactButton.id = 'react-btn';
     reactButton.innerHTML = '<slot><svg xmlns="http://www.w3.org/2000/svg" width="24" height="24"><path fill="none" d="M0 0h24v24H0z"/><path d="M18 16c-.8 0-1.4.4-2 .8l-7-4v-1.5l7-4c.5.4 1.2.7 2 .7 1.7 0 3-1.3 3-3s-1.3-3-3-3-3 1.3-3 3v.7l-7 4C7.5 9.4 6.8 9 6 9c-1.7 0-3 1.3-3 3s1.3 3 3 3c.8 0 1.5-.3 2-.8l7.2 4.2v.6c0 1.6 1.2 3 2.8 3 1.6 0 3-1.4 3-3s-1.4-3-3-3z"/></svg></slot>';
     reactButton.setAttribute('aria-lable', 'React');

    const overlay = document.createElement('div');
    overlay.id = 'overlay';
    overlay.classList.add('bounce');
    overlay.innerHTML = `<!--compress-->
      <div id="gt-reactions-container">
      </div><!--endcompress-->`;

    const container = overlay.querySelector('#gt-reactions-container');



    this.buttonConfig.forEach(item => {

      const imageSrc =  new URL("svg/"+item.icon, import.meta.url);

      const button = document.createElement("button");
      //button.innerHTML = item.label[this.getLang()];
      const image = document.createElement("img");
      image.classList.add('bounce-hover', item.key);
      image.src = imageSrc.href

      button.appendChild(image);

      button.dataset.key = item.key;


      container.appendChild(button)
    });


    fragment.appendChild(styles);
    fragment.appendChild(reactButton);
    fragment.appendChild(overlay);

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


    // Dismiss the overlay on any interaction on the page
    document.documentElement.addEventListener('click', e => {
      if (e.target != root.host) {
        this.hide();
      }
    }, true);

    document.documentElement.addEventListener('mouseover', e => {
      if (e.target != root.host) {
        if(this.overlayHidingFlag !== true) {
          clearTimeout(this.overlayTimer);
          this.overlayHidingFlag = true;
          this.overlayTimer = setTimeout(() => {
            this.hide();
          }, 1500)
        }
      } else {
        clearTimeout(this.overlayTimer);
        this.overlayHidingFlag = false;
      }
    }, true);


    this.reactBtn.addEventListener('mouseover', e => {
      clearTimeout(this.overlayTimer);

      this.overlayHidingFlag = false;
      this.overlayTimer = setTimeout(() => {
        this.show();
      }, 300)
    });

    this.reactBtn.addEventListener('mouseout', e => {
      clearTimeout(this.overlayTimer);
    });

    this.shadowRoot.addEventListener('click', e => {
      clearTimeout(this.overlayTimer);

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
