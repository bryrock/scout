<?php
/**
 * @file
 * scout_pak.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function scout_pak_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: scout_tip
  $overrides["scout_tip.14.changed"] = 1396049745;
  $overrides["scout_tip.14.field_scout_tip_text|und|0|safe_value"] = 'A description is only for admin purposes, but it&#039;s also helpful if you have a lot of trail names that look similar.';
  $overrides["scout_tip.14.field_scout_tip_text|und|0|value"] = 'A description is only for admin purposes, but it\'s also helpful if you have a lot of trail names that look similar.';
  $overrides["scout_tip.14.title"] = 'Scout Trails - Description';
  $overrides["scout_tip.15.changed"] = 1396049761;
  $overrides["scout_tip.15.title"] = 'Scout Trails - Add Scout Tip';
  $overrides["scout_tip.16.changed"] = 1396050618;
  $overrides["scout_tip.16.field_scout_tip_text|und|0|safe_value"] = 'Your trails won&#039;t appear anywhere until you add them to Context.&lt;br /&gt;&lt;br /&gt;
  &lt;a href=&quot;/admin/structure/context/list/scout_trail_context/edit&quot;&gt;See how this is done&lt;/a&gt;.';
  $overrides["scout_tip.16.field_scout_tip_text|und|0|value"] = 'Your trails won\'t appear anywhere until you add them to Context.<br /><br />
  <a href="/admin/structure/context/list/scout_trail_context/edit">See how this is done</a>.';

 return $overrides;
}
