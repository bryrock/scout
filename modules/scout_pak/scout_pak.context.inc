<?php
/**
 * @file
 * scout_pak.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function scout_pak_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clone_of_scout_tip_create';
  $context->description = 'Shows how to create Scout Stops';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips/*/edit/startme' => 'admin/content/scout-trails/scout-tips/*/edit/startme',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '1',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  t('Shows how to create Scout Stops');
  $export['clone_of_scout_tip_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fast_track_scout_tip_create';
  $context->description = 'Shows how to create Scout Tips (autostart)';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips/1/edit/fast-track*' => 'admin/content/scout-trails/scout-tips/1/edit/fast-track*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '1',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  t('Shows how to create Scout Tips (autostart)');
  $export['fast_track_scout_tip_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fast_track_scout_trail_create';
  $context->description = 'Shows how to create Scout Trails (autostart)';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/add/scout_trail/fast-track' => 'admin/content/scout-trails/add/scout_trail/fast-track',
        'admin/content/scout-trails/6/edit/fast-track' => 'admin/content/scout-trails/6/edit/fast-track',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '6',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  t('Shows how to create Scout Trails (autostart)');
  $export['fast_track_scout_trail_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'first_time_scout';
  $context->description = 'After new install, this points administrator to help info';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/*' => 'admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 1,
      'trail_content' => '8',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('After new install, this points administrator to help info');
  t('Scout Trails');
  $export['first_time_scout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_help_page';
  $context->description = 'One stop scout trail on help page';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/help/scout' => 'admin/help/scout',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '9',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('One stop scout trail on help page');
  t('Scout Trails');
  $export['scout_help_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trails_help_page';
  $context->description = 'One stop scout trail on Scout Trails help page';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/help/scout_trails' => 'admin/help/scout_trails',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '10',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('One stop scout trail on Scout Trails help page');
  t('Scout Trails');
  $export['scout_trails_help_page'] = $context;

  return $export;
}
