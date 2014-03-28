<?php
/**
 * @file
 * scout_trails.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scout_trails_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scout_trails_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_scout_tip().
 */
function scout_trails_default_scout_tip() {
  $items = array();
  $items['1'] = entity_import('scout_tip', '{
    "tip_id" : "1",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step One",
    "uid" : "5",
    "published" : "1",
    "created" : "1384728018",
    "changed" : "1384728018",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        { "value" : "description", "format" : null, "safe_value" : "description" }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add a title for the tip.",
          "format" : null,
          "safe_value" : "Add a title for the tip."
        }
      ]
    }
  }');
  $items['2'] = entity_import('scout_tip', '{
    "tip_id" : "2",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Two",
    "uid" : "5",
    "published" : "1",
    "created" : "1384742489",
    "changed" : "1384742489",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "field-name-field-scout-tip-text",
          "format" : null,
          "safe_value" : "field-name-field-scout-tip-text"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Then add the main text (that\\u0027s what this is).",
          "format" : null,
          "safe_value" : "Then add the main text (that\\u0026#039;s what this is)."
        }
      ]
    }
  }');
  $items['3'] = entity_import('scout_tip', '{
    "tip_id" : "3",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Three",
    "uid" : "5",
    "published" : "1",
    "created" : "1384743115",
    "changed" : "1384743115",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Don\\u0027t go in the basement!",
          "format" : null,
          "safe_value" : "Don\\u0026#039;t go in the basement!"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "field-name-field-scout-tip-button-text",
          "format" : null,
          "safe_value" : "field-name-field-scout-tip-button-text"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add the text for the \\u0022Next\\u0022 button.  It defaults to \\u0022Next\\u0022, but you can customize it!",
          "format" : null,
          "safe_value" : "Add the text for the \\u0026quot;Next\\u0026quot; button.  It defaults to \\u0026quot;Next\\u0026quot;, but you can customize it!"
        }
      ]
    }
  }');
  $items['4'] = entity_import('scout_tip', '{
    "tip_id" : "4",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Four",
    "uid" : "5",
    "published" : "1",
    "created" : "1384743571",
    "changed" : "1384743571",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        { "value" : "Do it Now!", "format" : null, "safe_value" : "Do it Now!" }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "selected", "format" : null, "safe_value" : "selected" } ] },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Decide how you will anchor the Scout Tip to a page.  You can do it by Data ID (#) or Class (.) selectors.\\r\\n\\r\\nOr you can make a tip Modal, anchored to the entire page.\\r\\n\\r\\nThis tip is anchored to a class for the tabs at the left.\\r\\n\\r\\nOpen the \\u0022Scout Tip Location Attribute\\u0022 to see your options.",
          "format" : null,
          "safe_value" : "Decide how you will anchor the Scout Tip to a page.  You can do it by Data ID (#) or Class (.) selectors.\\r\\n\\r\\nOr you can make a tip Modal, anchored to the entire page.\\r\\n\\r\\nThis tip is anchored to a class for the tabs at the left.\\r\\n\\r\\nOpen the \\u0026quot;Scout Tip Location Attribute\\u0026quot; to see your options."
        }
      ]
    }
  }');
  $items['5'] = entity_import('scout_tip', '{
    "tip_id" : "5",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Learn About Scout Trails",
    "uid" : "5",
    "published" : "1",
    "created" : "1384757611",
    "changed" : "1395967431",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "No thanks", "format" : null, "safe_value" : "No thanks" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Now you can also create Scout Tips right in Scout Trails!\\r\\n\\r\\n\\u003Ca href=\\u0022\\/admin\\/content\\/scout-trails\\/add\\/scout_trail\\u0022\\u003ESHOW ME!\\u003C\\/a\\u003E.",
          "format" : null,
          "safe_value" : "Now you can also create Scout Tips right in Scout Trails!\\r\\n\\r\\n\\u0026lt;a href=\\u0026quot;\\/admin\\/content\\/scout-trails\\/add\\/scout_trail\\u0026quot;\\u0026gt;SHOW ME!\\u0026lt;\\/a\\u0026gt;."
        }
      ]
    }
  }');
  $items['6'] = entity_import('scout_tip', '{
    "tip_id" : "6",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Blog Tip",
    "uid" : "5",
    "published" : "1",
    "created" : "1384758837",
    "changed" : "1384758837",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "menu-mlid-1533",
          "format" : null,
          "safe_value" : "menu-mlid-1533"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This is a blog, dumbass",
          "format" : null,
          "safe_value" : "This is a blog, dumbass"
        }
      ]
    }
  }');
  $items['7'] = entity_import('scout_tip', '{
    "tip_id" : "7",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Five",
    "uid" : "5",
    "published" : "1",
    "created" : "1384879746",
    "changed" : "1384879746",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Coolio", "format" : null, "safe_value" : "Coolio" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "selected", "format" : null, "safe_value" : "selected" } ] },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add (optional) custom classes for custom style changes \\/ additions to the Joyride style used by Scout Tips. ",
          "format" : null,
          "safe_value" : "Add (optional) custom classes for custom style changes \\/ additions to the Joyride style used by Scout Tips. "
        }
      ]
    }
  }');
  $items['8'] = entity_import('scout_tip', '{
    "tip_id" : "8",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Six",
    "uid" : "5",
    "published" : "1",
    "created" : "1384880744",
    "changed" : "1384880744",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "1", "format" : null, "safe_value" : "1" } ] },
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "block-scout-scout-trailhead",
          "format" : null,
          "safe_value" : "block-scout-scout-trailhead"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Scout trails are added to pages using Context.  They can be started automatically, with an option to play only once.  Or this block can be added (also in Context) to appear in an available region (user bar not present in Admin theme) and alert user that an optional tour is available.",
          "format" : null,
          "safe_value" : "Scout trails are added to pages using Context.  They can be started automatically, with an option to play only once.  Or this block can be added (also in Context) to appear in an available region (user bar not present in Admin theme) and alert user that an optional tour is available."
        }
      ]
    }
  }');
  $items['9'] = entity_import('scout_tip', '{
    "tip_id" : "9",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips Admin \\/ Creation",
    "uid" : "5",
    "published" : "1",
    "created" : "1384881275",
    "changed" : "1384881275",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "action-links",
          "format" : null,
          "safe_value" : "action-links"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This page shows the collection of created Scout Tips, regardless of whether or not they are being used in any Scout Trails.  New Scout Tips are created by clicking this link.",
          "format" : null,
          "safe_value" : "This page shows the collection of created Scout Tips, regardless of whether or not they are being used in any Scout Trails.  New Scout Tips are created by clicking this link."
        }
      ]
    }
  }');
  $items['10'] = entity_import('scout_tip', '{
    "tip_id" : "10",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips Editing",
    "uid" : "5",
    "published" : "1",
    "created" : "1384882178",
    "changed" : "1384882178",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Got it!", "format" : null, "safe_value" : "Got it!" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "even", "format" : null, "safe_value" : "even" } ] },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Clicking any scout tip link takes you to its edit form.",
          "format" : null,
          "safe_value" : "Clicking any scout tip link takes you to its edit form."
        }
      ]
    }
  }');
  $items['11'] = entity_import('scout_tip', '{
    "tip_id" : "11",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Admin \\/ Creation",
    "uid" : "5",
    "published" : "1",
    "created" : "1384882469",
    "changed" : "1384882469",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "action-links",
          "format" : null,
          "safe_value" : "action-links"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This page shows the collection of created Scout Trails and any Scout Tips they\\u0027re composed of.  New Scout Trails are created by clicking this link.",
          "format" : null,
          "safe_value" : "This page shows the collection of created Scout Trails and any Scout Tips they\\u0026#039;re composed of.  New Scout Trails are created by clicking this link."
        }
      ]
    }
  }');
  $items['12'] = entity_import('scout_tip', '{
    "tip_id" : "12",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Editing",
    "uid" : "5",
    "published" : "1",
    "created" : "1384883065",
    "changed" : "1384883065",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Thanks", "format" : null, "safe_value" : "Thanks" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "even", "format" : null, "safe_value" : "even" } ] },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Clicking any scout trail link (or any trail tip link) takes you to its edit form.",
          "format" : null,
          "safe_value" : "Clicking any scout trail link (or any trail tip link) takes you to its edit form."
        }
      ]
    }
  }');
  $items['13'] = entity_import('scout_tip', '{
    "tip_id" : "13",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Step One",
    "uid" : "5",
    "published" : "1",
    "created" : "1384883321",
    "changed" : "1384883321",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "form-item-title\\u0022",
          "format" : null,
          "safe_value" : "form-item-title\\u0026quot;"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Enter a title for you Scout Trail.",
          "format" : null,
          "safe_value" : "Enter a title for you Scout Trail."
        }
      ]
    }
  }');
  $items['14'] = entity_import('scout_tip', '{
    "tip_id" : "14",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Step Two",
    "uid" : "5",
    "published" : "1",
    "created" : "1384883428",
    "changed" : "1384883428",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Yada-yada", "format" : null, "safe_value" : "Yada-yada" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "form-item-description",
          "format" : null,
          "safe_value" : "form-item-description"
        }
      ]
    },
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "A description is also helpful.",
          "format" : null,
          "safe_value" : "A description is also helpful."
        }
      ]
    }
  }');
  $items['15'] = entity_import('scout_tip', '{
    "tip_id" : "15",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Step Three",
    "uid" : "5",
    "published" : "1",
    "created" : "1384883859",
    "changed" : "1395966878",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "See how to add new ones",
          "format" : null,
          "safe_value" : "See how to add new ones"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-field-scout-trail-tips-und-actions-ief-add-existing",
          "format" : null,
          "safe_value" : "edit-field-scout-trail-tips-und-actions-ief-add-existing"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add existing scout tips to your trail with auto complete.",
          "format" : null,
          "safe_value" : "Add existing scout tips to your trail with auto complete."
        }
      ]
    }
  }');
  $items['16'] = entity_import('scout_tip', '{
    "tip_id" : "16",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context",
    "uid" : "5",
    "published" : "1",
    "created" : "1384884812",
    "changed" : "1395968650",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "No thanks", "format" : null, "safe_value" : "No thanks" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Your trails won\\u0027t appear anywhere until you add them to Context.\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Ca href=\\u0022\\/admin\\/structure\\/context\\/list\\/scout_trail_context\\/edit\\/showme\\u0022\\u003ESee how this is done\\u003C\\/a\\u003E.",
          "format" : null,
          "safe_value" : "Your trails won\\u0026#039;t appear anywhere until you add them to Context.\\u0026lt;br \\/\\u0026gt;\\u0026lt;br \\/\\u0026gt;\\r\\n\\u0026lt;a href=\\u0026quot;\\/admin\\/structure\\/context\\/list\\/scout_trail_context\\/edit\\/showme\\u0026quot;\\u0026gt;See how this is done\\u0026lt;\\/a\\u0026gt;."
        }
      ]
    }
  }');
  $items['17'] = entity_import('scout_tip', '{
    "tip_id" : "17",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Add Condition",
    "uid" : "5",
    "published" : "1",
    "created" : "1384885609",
    "changed" : "1384885609",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-conditions-plugins-path-values",
          "format" : null,
          "safe_value" : "edit-conditions-plugins-path-values"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add the condition for the Scout Trail to appear.  In this case we\\u0027re using the path to the page we\\u0027re looking at now.",
          "format" : null,
          "safe_value" : "Add the condition for the Scout Trail to appear.  In this case we\\u0026#039;re using the path to the page we\\u0026#039;re looking at now."
        }
      ]
    }
  }');
  $items['18'] = entity_import('scout_tip', '{
    "tip_id" : "18",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Add Trailhead Block",
    "uid" : "5",
    "published" : "1",
    "created" : "1384886288",
    "changed" : "1384886288",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "right" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "scout-scout_trailhead",
          "format" : null,
          "safe_value" : "scout-scout_trailhead"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "If you don\\u0027t want the Scout Tour to begin automatically, then add the Trailhead block to an appropriate region.",
          "format" : null,
          "safe_value" : "If you don\\u0026#039;t want the Scout Tour to begin automatically, then add the Trailhead block to an appropriate region."
        }
      ]
    }
  }');
  $items['19'] = entity_import('scout_tip', '{
    "tip_id" : "19",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Select Scout Trail",
    "uid" : "5",
    "published" : "1",
    "created" : "1384886648",
    "changed" : "1384886648",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        { "value" : "Eazy peazy", "format" : null, "safe_value" : "Eazy peazy" }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "right" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-reactions-plugins-scout-trail-trail-content",
          "format" : null,
          "safe_value" : "edit-reactions-plugins-scout-trail-trail-content"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Select one of the available Scout Trails from the list.  The list will show the names of available trails and how many tips are on them.",
          "format" : null,
          "safe_value" : "Select one of the available Scout Trails from the list.  The list will show the names of available trails and how many tips are on them."
        }
      ]
    }
  }');
  $items['20'] = entity_import('scout_tip', '{
    "tip_id" : "20",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips Caveat",
    "uid" : "5",
    "published" : "1",
    "created" : "1384887705",
    "changed" : "1395980429",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Just Letting You Know",
          "format" : null,
          "safe_value" : "Just Letting You Know"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [],
    "field_scout_tip_selector_id" : [],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This demo has shown some Scout Tips that were attached to selectors that normally would be contained inside closed fieldsets on page load.  They only worked in this demo because I opened those fieldsets prior to proceeding to that tip.  In normal conditions, Scout Tips that are attached to selectors not available on page load will not know where to go, and will appear in the upper left corner of the screen. \\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\nAn alternative is to make those tips modal (like this tip), but then they are not a precise as those tips that point to the area they are addressing.",
          "format" : null,
          "safe_value" : "This demo has shown some Scout Tips that were attached to selectors that normally would be contained inside closed fieldsets on page load.  They only worked in this demo because I opened those fieldsets prior to proceeding to that tip.  In normal conditions, Scout Tips that are attached to selectors not available on page load will not know where to go, and will appear in the upper left corner of the screen. \\u0026lt;br \\/\\u0026gt;\\u0026lt;br \\/\\u0026gt;\\nAn alternative is to make those tips modal (like this tip), but then they are not a precise as those tips that point to the area they are addressing."
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_default_scout_tip_type().
 */
function scout_trails_default_scout_tip_type() {
  $items = array();
  $items['scout_tip'] = entity_import('scout_tip_type', '{
    "type" : "scout_tip",
    "label" : "Scout Tip",
    "weight" : 0,
    "description" : "The default Scout Tip type."
  }');
  return $items;
}

/**
 * Implements hook_default_scout_trail().
 */
function scout_trails_default_scout_trail() {
  $items = array();
  $items['1'] = entity_import('scout_trail', '{
    "trail_id" : "1",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Tips",
    "description" : "Shows how to create Scout Tips",
    "uid" : "5",
    "published" : "1",
    "created" : "1384728030",
    "changed" : "1395967014",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_trail_tips" : { "und" : [
        { "target_id" : "1" },
        { "target_id" : "2" },
        { "target_id" : "3" },
        { "target_id" : "4" },
        { "target_id" : "7" },
        { "target_id" : "8" },
        { "target_id" : "5" }
      ]
    }
  }');
  $items['4'] = entity_import('scout_trail', '{
    "trail_id" : "4",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Tip Admin - Creation",
    "description" : "Shows where to find Scout Tips",
    "uid" : "5",
    "published" : "1",
    "created" : "1384881575",
    "changed" : "1384881575",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "9" }, { "target_id" : "10" } ] }
  }');
  $items['5'] = entity_import('scout_trail', '{
    "trail_id" : "5",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails Admin - Creation",
    "description" : "Shows where to find Scout Trails \\u0026 Tips",
    "uid" : "5",
    "published" : "1",
    "created" : "1384882702",
    "changed" : "1384882702",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "11" }, { "target_id" : "12" } ] }
  }');
  $items['6'] = entity_import('scout_trail', '{
    "trail_id" : "6",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails",
    "description" : "Shows how to create Scout Trails",
    "uid" : "5",
    "published" : "1",
    "created" : "1384883144",
    "changed" : "1384883144",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_trail_tips" : { "und" : [
        { "target_id" : "13" },
        { "target_id" : "14" },
        { "target_id" : "15" },
        { "target_id" : "16" }
      ]
    }
  }');
  $items['7'] = entity_import('scout_trail', '{
    "trail_id" : "7",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails Context",
    "description" : "How to make Scout Trails appear",
    "uid" : "5",
    "published" : "1",
    "created" : "1384885694",
    "changed" : "1395980432",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_trails",
    "field_scout_trail_tips" : { "und" : [
        { "target_id" : "17" },
        { "target_id" : "18" },
        { "target_id" : "19" },
        { "target_id" : "20" }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_default_scout_trail_type().
 */
function scout_trails_default_scout_trail_type() {
  $items = array();
  $items['scout_trail'] = entity_import('scout_trail_type', '{
    "type" : "scout_trail",
    "label" : "Scout Trail",
    "weight" : 0,
    "description" : "The default Scout Trail type."
  }');
  return $items;
}
