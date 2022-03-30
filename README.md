# Wissensnetz

## Über dieses Projekt

Das Wissensnetz ist die Informations- und Austauschplattform für engagierte Personen aus den Bereichen Sport, Ehrenamt und Gemeinwohl. Jedes Mitglied kann seine Handlungsfelder in seinem Profil festlegen und das große Wissensnetz somit als ein personalisiertes Wissensmanagement-System nutzen. Sie können relevante Ansprechpartner/innen finden und sich mit ihnen zu ihren Themen austauschen. Dazu können Beiträge erstellt und kommentiert und eigene Gruppen gegründet werden. Außerdem können Dokumente und Informationen selbst eingestellt und aufgefunden werden.

## Im Wissensnetz können Sie …
 
* … sich mit Ihren Kolleginnen und Kollegen schnell und unkompliziert austauschen.
* … interessante Informationen und Materialien zu den Handlungsfeldern ihrer Praxis erhalten.
* … eigene Beiträge, Materialien, Fragen und Standpunkte einstellen und zur Diskussion stellen.
* … eigene Gruppen gründen und sich dort mit eigenen Zielgruppen und zu spezifischen Themen austauschen.
 

# Technische Hinweise 

## Vorbedingungen
Ideal ist ein server mit aktuellem ubuntu und folgenden diensten

* Apache 2.4
* PHP 7.4
* MySQL oder MariaDB
* Apache solr
* Docker

## Installation

setttings.php erstellen unter sites/default/settings.php

```php
<?php
$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => '***',
  'username' => '***',
  'password' => '***',
  'host' => 'localhost',
  'prefix' => '',
);

include('include.php');

#your custom drupal settings here
```
Alternativ kann als basis auch die settings.default.php verwedet werden.

Danach den initialen dump scripts/database.mysql eingespielt werden


datei ordner erstellen

```bash
mkdir files_private
midir web/sites/default/files
```


## Initialer Login

Für den initialen Login kannst du dich unter `/minda/secure`  anmelden

```
user: wissensnetz
password: W1ssensn€tz0pen!
```


