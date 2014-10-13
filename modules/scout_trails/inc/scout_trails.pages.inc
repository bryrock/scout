<?php
/**
 * @file
 * Helpers for Scout admin pages.
 *
 */

/**
 * Scout view callback.
 */
function scout_trail_view($scout_trail) {
  drupal_set_title(entity_label('scout_trail', $scout_trail));
  return entity_view('scout_trail', array(entity_id('scout_trail', $scout_trail) => $scout_trail), 'full');
}

/**
 * Page to select Scout Trail Type to add new scout trail.
 */
function scout_trail_add_page() {
  drupal_goto('admin/content/scout-trails/add/scout_trail');
}

/**
 * Page to select Scout Tip Type to add new scout tip.
 */
function scout_tip_admin_add_page() {
  drupal_goto('admin/content/scout-trails/scout-tips/add/scout_tip');
}
