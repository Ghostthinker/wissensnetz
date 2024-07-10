// By default, Klaro will load the config from  a global "klaroConfig" variable.
// You can change this by specifying the "data-config" attribute on your
// script take, e.g. like this:
// <script src="klaro.js" data-config="myConfigVariableName" />
var klaroConfig = {
  // With the 0.7.0 release we introduce a 'version' paramter that will make
  // if easier for us to keep configuration files backwards-compatible in the future.
  version: 1,

  // You can customize the ID of the DIV element that Klaro will create
  // when starting up. If undefined, Klaro will use 'klaro'.
  elementID: 'klaro',

  // You can override CSS style variables here. For IE11, Klaro will
  // dynamically inject the variables into the CSS. If you still consider
  // supporting IE9-10 (which you probably shouldn't) you need to use Klaro
  // with an external stylesheet as the dynamic replacement won't work there.
  styling: {
    theme: ['dark', 'bottom', 'wide'],
  },

  // Setting this to true will keep Klaro from automatically loading itself
  // when the page is being loaded.
  noAutoLoad: false,

  // Setting this to true will render the descriptions of the consent
  // modal and consent notice are HTML. Use with care.
  htmlTexts: true,

  // Setting 'embedded' to true will render the Klaro modal and notice without
  // the modal background, allowing you to e.g. embed them into a specific element
  // of your website, such as your privacy notice.
  embedded: false,

  // You can group services by their purpose in the modal. This is advisable
  // if you have a large number of services. Users can then enable or disable
  // entire groups of services instead of having to enable or disable every service.
  groupByPurpose: true,

  // How Klaro should store the user's preferences. It can be either 'cookie'
  // (the default) or 'localStorage'.
  storageMethod: 'cookie',

  // You can customize the name of the cookie that Klaro uses for storing
  // user consent decisions. If undefined, Klaro will use 'klaro'.
  cookieName: 'klaro_wn',

  // You can also set a custom expiration time for the Klaro cookie.
  // By default, it will expire after 120 days.
  cookieExpiresAfterDays: 180,

  // You can change to cookie domain for the consent manager itself.
  // Use this if you want to get consent once for multiple matching domains.
  // If undefined, Klaro will use the current domain.
  //cookieDomain: '.github.com',

  // Defines the default state for services (true=enabled by default).
  default: false,

  // If "mustConsent" is set to true, Klaro will directly display the consent
  // manager modal and not allow the user to close it before having actively
  // consented or declines the use of third-party services.
  mustConsent: false,

  // Show "accept all" to accept all services instead of "ok" that only accepts
  // required and "default: true" services
  acceptAll: true,

  // replace "decline" with cookie manager modal
  hideDeclineAll: false,

  // hide "learnMore" link
  hideLearnMore: false,

  // show cookie notice as modal
  noticeAsModal: false,

  // You can also remove the 'Realized with Klaro!' text in the consent modal.
  // Please don't do this! We provide Klaro as a free open source tool.
  // Placing a link to our website helps us spread the word about it,
  // which ultimately enables us to make Klaro! better for everyone.
  // So please be fair and keep the link enabled. Thanks :)
  //disablePoweredBy: true,

  // you can specify an additional class (or classes) that will be added to the Klaro `div`
  //additionalClass: 'my-klaro',

  // You can define the UI language directly here. If undefined, Klaro will
  // use the value given in the global "lang" variable. If that does
  // not exist, it will use the value given in the "lang" attribute of your
  // HTML tag. If that also doesn't exist, it will use 'en'.
  //lang: 'en',

  // You can overwrite existing translations and add translations for your
  // service descriptions and purposes. See `src/translations/` for a full
  // list of translations that can be overwritten:
  // https://github.com/KIProtect/klaro/tree/master/src/translations

  // Example config that shows how to overwrite translations:
  // https://github.com/KIProtect/klaro/blob/master/src/configs/i18n.js
  translations: {
    // translationsed defined under the 'zz' language code act as default
    // translations.
    zz: {
      privacyPolicyUrl: '/datenschutz',
    },
    // If you erase the "consentModal" translations, Klaro will use the
    // bundled translations.
    de: {
      privacyPolicyUrl: '/datenschutzvereinbarung',
      privacyPolicy: {
        text: 'Für weitere Informationen zu den von uns verwendeten Cookies öffnen Sie die {privacyPolicy}.',
        name: 'Datenschutzhinweise',
      },
      consentModal: {
        title: '<div><strong>Wir verwenden Cookies.</strong></div>',
        description:
          'Auf unserer Website kommen verschiedene Cookies zum Einsatz: technische, funktionale und solche' +
          ' zu Analyse- und Werbezwecken.',
      },
      consentNotice: {
        description: '<div><strong>Wir verwenden Cookies.</strong></div>' +
          'Auf unserer Website kommen verschiedene Cookies zum Einsatz: technische, funktionale und solche' +
          ' zu Analyse- und Werbezwecken. Für weitere Informationen zu den von uns verwendeten Cookies öffnen Sie die {privacyPolicy}.',
        learnMore: 'Nein, anpassen',
      },
      acceptAll: 'Alle annehmen',
      decline: 'Nur notwendige Cookies annehmen',
      ok: 'Alle annehmen',
      facebook: {
        description: 'Werbung, Empfehlungen, Insights und Messungen',
      },
      matomo: {
        description: 'Sammeln von Besucherstatistiken (Dauer: 13 Monate)',
      },
      adsense: {
        description: 'Anzeigen von Werbeanzeigen (Beispiel)',
        title: 'Google AdSense Werbezeugs',
      },
      googleAnalytics: {
        description: 'Sammeln von Besucherstatistiken',
      },
      googleFonts: {
        description: 'Web-Schriftarten gehostet durch Google',
      },
      youtube: {
        description: 'Anzeigen von Werbeanzeigen und Performance (Dauer: 13 Monate)',
      },
      purposes: {
        analytics: 'Statistiken',
        security: 'Sicherheit',
        livechat: 'Live Chat',
        advertising: 'Werbung',
        styling: 'Styling',
        functional: 'Funktional (notwendig)',
        marketing: 'Marketing'
      },
    },
    en: {
      privacyPolicyUrl: '/en/datenschutz',
      privacyPolicy: {
        text: 'For more information about the cookies we use, open the {privacyPolicy}.',
        name: 'privacy policy',
      },
      consentModal: {
        title: '<div><strong>We use cookies.</strong></div>',
        description:
          'Various cookies are used on our website: technical, functional and those for analysis and advertising purposes. ',
      },
      consentNotice: {
        description: '<div><strong>We use cookies.</strong></div>' +
          'Various cookies are used on our website: technical, functional and those for analysis and advertising purposes. ' +
          'For more information about the cookies we use, open the {privacyPolicy}.',
        learnMore: 'No, modify',
      },
      acceptAll: 'Accept all',
      decline: 'Accept only necessary cookies',
      ok: 'Accept all',
      facebook: {
        description: 'Advertising, recommendations, insights and measurements',
      },
      matomo: {
        description: 'Collecting of visitor statistics',
      },
      adsense: {
        description: 'Displaying of advertisements (just an example)',
        title: 'Google Adsense Advertisement',
      },
      googleAnalytics: {
        description: 'Collecting of visitor statistics',
      },
      googleFonts: {
        description: 'Web fonts hosted on by Google',
      },
      youtube: {
        description: 'Displaying of advertisements and performance',
      },
      matomo: {
        description: 'Sammeln von Besucherstatistiken',
      },
      has_js: {
        description: 'Dauer: Bis Session-Ende',
      },
      purposes: {
        analytics: 'Analytics',
        security: 'Security',
        livechat: 'Livechat',
        advertising: 'Advertising',
        styling: 'Styling',
        functional: 'Functional (required)',
        marketing: 'Marketing'
      },
    },
  },

  // This is a list of third-party services that Klaro will manage for you.
  services: [
    {
      // Each app should have a unique (and short) name.
      name: 'matomo',

      // If "default" is set to true, the app will be enabled by default
      // Overwrites global "default" setting.
      // We recommend leaving this to "false" for apps that collect
      // personal information.
      default: true,

      // The title of you app as listed in the consent modal.
      title: 'Matomo/Piwik',

      // The purpose(s) of this app. Will be listed on the consent notice.
      // Do not forget to add translations for all purposes you list here.
      purposes: ['analytics'],

      // A list of regex expressions or strings giving the names of
      // cookies set by this app. If the user withdraws consent for a
      // given app, Klaro will then automatically delete all matching
      // cookies.
      cookies: [
        // you can also explicitly provide a path and a domain for
        // a given cookie. This is necessary if you have apps that
        // set cookies for a path that is not "/" or a domain that
        // is not the current domain. If you do not set these values
        // properly, the cookie can't be deleted by Klaro
        // (there is no way to access the path or domain of a cookie in JS)
        [/^_pk_.*$/, '/', '.dosb.de'], //for the production version
        [/^_pk_.*$/, '/', 'localhost'], //for the local version
        'piwik_ignore',
      ],
      // An optional callback function that will be called each time
      // the consent state for the service changes (true=consented). Passes
      // the `service` config as the second parameter as well.
       callback: function (consent, service) {
         var _paq = window._paq;
         // This is an example callback function.
         //console.log(
         //  'User consent for service ' + service.name + ': consent=' + consent
         //);

         // To be used in conjunction with Matomo 'requireCookieConsent' Feature, Matomo 3.14.0 or newer
         // For further Information see https://matomo.org/faq/new-to-piwik/how-can-i-still-track-a-visitor-without-cookies-even-if-they-decline-the-cookie-consent/
         if (consent == true) {
           if (!_paq) {
             _paq = window._paq = window._paq || [];
             _paq.push(['setIgnoreClasses', ["no-tracking", "colorbox"]]);
             /* tracker methods like "setCustomDimension" should be called before "trackPageView" */
             _paq.push(['trackPageView']);
             _paq.push(['enableLinkTracking']);
             (function () {
               var u = Drupal.settings.matomo.trackerUrl;
               _paq.push(['setTrackerUrl', u + 'matomo.php']);
               _paq.push(['setSiteId', Drupal.settings.matomo.trackSiteId]);
               var d = document, g = d.createElement('script'), s = d.getElementsByTagName('script')[0];
               g.type = 'text/javascript';
               g.defer = true;
               g.async = true;
               g.src = u + 'matomo.js';
               s.parentNode.insertBefore(g, s);
             })();

             _paq.push(['rememberCookieConsentGiven', 24*30*6]);
           }
         } else {
           if (window._paq) {
             _paq.push(['forgetCookieConsentGiven']);
           }
         }
       },
      // If "required" is set to true, Klaro will not allow this service to
      // be disabled by the user.
      required: false,

      // If "optOut" is set to true, Klaro will load this service even before
      // the user gave explicit consent.
      // We recommend always leaving this "false".
      optOut: false,

      // If "onlyOnce" is set to true, the service will only be executed
      // once regardless how often the user toggles it on and off.
      onlyOnce: true,
    },
    {
      name: 'youtube',
      contextualConsentOnly: true,
      purposes: ['marketing'],
      cookies: [
        [/^VISITOR_INFO1_LIVE(_.*)?/, '/', '.dosb.de'], //for the production version
        [/^YSC(_.*)?/, '/', '.dosb.de'], //for the production version
        [/^VISITOR_INFO1_LIVE(_.*)?/, '/', 'localhost'], //for the production version
        [/^YSC(_.*)?/, '/', 'localhost'], //for the production version
      ]
    },
    {
      name: 'has_js',
      default: true,
      title: 'JavaScript Cookie',
      purposes: ['functional'],
      cookies: ['has_js'],
      required: true,
    }
  ],
};
