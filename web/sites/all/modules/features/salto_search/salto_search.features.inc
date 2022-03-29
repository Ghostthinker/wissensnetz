<?php
/**
 * @file
 * salto_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function salto_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function salto_search_default_search_api_autocomplete_search() {
  $items = array();
  $items['salto_search'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "salto_search",
    "name" : "Salto search autocomplete",
    "index_id" : "default_node_index",
    "suggester_id" : "server",
    "type" : "salto_search",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [ "body:summary", "body:value", "field_post_tags:name", "title" ] },
      "min_length" : "1",
      "results" : 1,
      "submit_button_selector" : "#edit-text",
      "autosubmit" : 1
    }
  }');
  $items['search_api_views_salto_search'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_salto_search",
    "name" : "Salto Search",
    "index_id" : "default_node_index",
    "suggester_id" : "",
    "type" : "search_api_views",
    "enabled" : "0",
    "options" : { "result count" : true, "fields" : [] }
  }');
  $items['search_api_views_salto_search_comment'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_salto_search_comment",
    "name" : "salto_search_comment",
    "index_id" : "comments",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [ "comment_body:value" ] },
      "min_length" : "1",
      "results" : 1,
      "custom" : { "display" : "panel_pane_1" },
      "submit_button_selector" : ":submit",
      "autosubmit" : 1
    }
  }');
  $items['search_api_views_salto_search_file'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_salto_search_file",
    "name" : "Salto Search File",
    "index_id" : "default_file_index",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [
          "field_file_description",
          "field_file_image_alt_text",
          "field_file_image_title_text",
          "field_file_originator",
          "field_kb_kategorie:name",
          "field_post_tags:name",
          "mime",
          "name"
        ]
      },
      "min_length" : "1",
      "results" : 1,
      "custom" : { "display" : "panel_salto_search_file" },
      "submit_button_selector" : ":submit",
      "autosubmit" : 1
    }
  }');
  $items['search_api_views_salto_search_node'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_salto_search_node",
    "name" : "Salto Search Node",
    "index_id" : "default_node_index",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [ "body:summary", "body:value", "field_post_tags:name", "title" ] },
      "min_length" : "1",
      "results" : 1,
      "custom" : { "display" : "panel_salto_search_node" },
      "submit_button_selector" : ":submit",
      "autosubmit" : 1
    }
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function salto_search_default_search_api_index() {
  $items = array();
  $items['comments'] = entity_import('search_api_index', '{
    "name" : "Default comment index",
    "machine_name" : "comments",
    "description" : null,
    "server" : "apache_solr",
    "item_type" : "comment",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "author:field_user_organisations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "comment_body:format" : { "type" : "string" },
        "comment_body:value" : { "type" : "text" },
        "parent" : { "type" : "integer", "entity_type" : "comment" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_comment_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "author" : true, "comment_body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "comment_body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "comment_body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "comment_body:value" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "comment_body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong class=\\u0022salto-search-needle\\u0022\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : { "comment_body:value" : true },
            "exceptions" : "texan=texa"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['default_file_index'] = entity_import('search_api_index', '{
    "name" : "Default file index",
    "machine_name" : "default_file_index",
    "description" : null,
    "server" : "apache_solr",
    "item_type" : "file",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "fid" : { "type" : "integer" },
        "field_file_description" : { "type" : "text", "boost" : "3.0" },
        "field_file_image_alt_text" : { "type" : "text" },
        "field_file_image_title_text" : { "type" : "text", "boost" : "5.0" },
        "field_file_originator" : { "type" : "text", "boost" : "5.0" },
        "field_kb_kategorie" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_kb_kategorie:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_og_group" : { "type" : "integer", "entity_type" : "node" },
        "field_post_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_post_tags:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "mime" : { "type" : "text" },
        "name" : { "type" : "text", "boost" : "3.0" },
        "owner" : { "type" : "integer", "entity_type" : "user" },
        "owner:field_user_organisations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "size" : { "type" : "integer" },
        "timestamp" : { "type" : "date" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "teaser" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "name" : true,
              "mime" : true,
              "field_file_description" : true,
              "field_file_originator" : true,
              "field_file_image_alt_text" : true,
              "field_file_image_title_text" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "name" : true,
              "mime" : true,
              "field_file_description" : true,
              "field_file_originator" : true,
              "field_file_image_alt_text" : true,
              "field_file_image_title_text" : true
            },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "name" : true,
              "mime" : true,
              "field_file_description" : true,
              "field_file_originator" : true,
              "field_file_image_alt_text" : true,
              "field_file_image_title_text" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "name" : true,
              "mime" : true,
              "field_file_image_alt_text" : true,
              "field_file_image_title_text" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong class=\\u0022salto-search-needle\\u0022\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "apache_solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-49", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "-48",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-47", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-46", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-43", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "-49",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "-48",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true, "body:summary" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "-47",
          "settings" : {
            "prefix" : "\\u003Cstrong class=\\u0022salto-search-needle\\u0022\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "-46",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text", "boost" : "0.5" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "field_organisation_earemotes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_post_authors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_post_authors:field_user_organisations" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_post_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_post_tags:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_taxonomy_post_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function salto_search_default_search_api_server() {
  $items = array();
  $items['database_server'] = entity_import('search_api_server', '{
    "name" : "Database Server",
    "machine_name" : "database_server",
    "description" : "Salto localhost db Server",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 1,
      "indexes" : []
    },
    "enabled" : "0"
  }');
  return $items;
}
