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

  return $export;
}
