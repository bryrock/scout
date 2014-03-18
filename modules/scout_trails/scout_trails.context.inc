<?php
/**
 * @file
 * scout_trails.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function scout_trails_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_trail';
  $context->description = '';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news' => 'news',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '3',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  $export['news_trail'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_tip_create';
  $context->description = 'Shows how to create Scout Stops';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips/*/edit' => 'admin/content/scout-trails/scout-tips/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout-scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-15',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '1',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  t('Shows how to create Scout Stops');
  $export['scout_tip_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_tips_list';
  $context->description = '';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips' => 'admin/content/scout-trails/scout-tips',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-15',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '4',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  $export['scout_tips_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trail_context';
  $context->description = 'Shows how to add Scout Trails to a page';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/structure/context/list/scout_trail_context/edit' => 'admin/structure/context/list/scout_trail_context/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-15',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '7',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  t('Shows how to add Scout Trails to a page');
  $export['scout_trail_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trail_create';
  $context->description = 'Shows how to create Scout Trails';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/add/scout_trail' => 'admin/content/scout-trails/add/scout_trail',
        'admin/content/scout-trails/*/edit' => 'admin/content/scout-trails/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-15',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '6',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Trails');
  t('Shows how to create Scout Trails');
  $export['scout_trail_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trails_list';
  $context->description = 'Navigation Scout Trail Admin';
  $context->tag = 'Scout Trails';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails' => 'admin/content/scout-trails',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-15',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '5',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation Scout Trail Admin');
  t('Scout Trails');
  $export['scout_trails_list'] = $context;

  return $export;
}
