### Mobile responsive components for WN

Base: NPM + Fontawesome (Free) + Less
 
#### Build

Einfachhalber wird auf einzelne Less files gesetzt, da schon im WN eingesetzt wird.
So wird auch aus salto2014 die variables.less importiert!

- `npm run less` baut die css aus less Dateien => ***dist/output.css***
- `npm run build` baut die css aus less Dateien (mit tailwind) => ***dist/public.css***

Inwieweit tailwindCss und postcss relevant wird/ist mal schauen (autoprefixer?), mglw. fällts wieder raus! 

Anker ist quasi **less/modules.less**

#### Examples

im Verzeichnes /examples liegen html files als Demo

- accordion
- card
- checkbox
- floating button
- toolbox
