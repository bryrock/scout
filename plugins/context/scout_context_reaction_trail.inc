<?php

/**
 * Expose Scout Trail as a context reactions.
 */
class scout_context_reaction_trail extends context_reaction {

  /**
   * Options form.
   *
   * Populate options form with existing scout trails
   * for trail content selection in reaction.
   */
  function options_form($context) {

    //Find Scout trails and get their ids.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'scout_trail')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.
    $result = $query->execute();

    if (isset($result['scout_trail'])) {
      $trail_ids = array_keys($result['scout_trail']);
    }
    else {
	    drupal_set_message(t('You must create some Scout Trails before they can be used for Context.'), 'warning');
    }

    // Populate options list with available Scout trails
    $trail_option = array();
    foreach($trail_ids as $key =>$trail) {
      $trail_wrapper = entity_metadata_wrapper('scout_trail', $trail);
      $tips = count($trail_wrapper->field_scout_trail_tips);
      $trail_options[$key] = t($trail_wrapper->title->value() . ' (a Scout trail with ' . format_plural($tips, '1 Scout tip', '@count Scout tips') . ')');
    }

    $context_values = $this->fetch_from_context($context, 'values');

    return array(
      'trail_auto_start' => array(
        '#type' => 'checkbox',
        '#title' => t('Start scout trail automatically'),
        '#description' => t('Starts a Scout Trail on page load. If you disable this be sure to add a <em>Scout: Trailhead</em> block on this page.'),
        '#default_value' => isset($context_values['trail_auto_start']) ? $context_values['trail_auto_start'] : FALSE,
      ),
      'trail_play_once' => array(
        '#type' => 'checkbox',
        '#title' => t('Play trail only once'),
        '#description' => t('Check this to play the trail only once'),
        '#default_value' => isset($context_values['trail_play_once']) ? $context_values['trail_play_once'] : FALSE,
        '#states' => array(
          'visible' => array(
            ':input[type="checkbox"]#edit-reactions-plugins-scout-add-trail-auto-start' => array(
              'checked' => TRUE,
            )
          ),
        ),
      ),
      'trail_content' => array(
        '#title' => t('Scout Trails'),
        '#description' => t('Select a Scout Trail to appear when matching above conditions.'),
        '#type' => 'select',
        '#options' => $trail_options,
        '#default_value' => isset($context_values['trail_content']) ? $context_values['trail_content'] : NULL,
      ),
    );
  }

  /**
   * Options form submit handler.
   */

  function options_form_submit($values) {
    if(!isset($values['trail_play_once'])) $values['trail_play_once'] = FALSE;
    $values['trail_play_once'] = empty($values['trail_auto_start']) ? FALSE : $values['trail_play_once'];
    return $values;
  }

  /**
   * Execute.
   */
  function execute(&$vars = NULL) {
    $contexts = $this->get_contexts();

    // We need the Zurb Joyride library for any of this to work
    foreach ($contexts as $context) {
      if (!empty($context->reactions[$this->plugin])) {
        $library = libraries_load('joyride');
        $library_loaded = $library && !empty($library['loaded']);

        drupal_add_library('system', 'jquery.cookie');

        $js_name = 'jquery.joyride.js';
        $base_path = 'sites/all/libraries/joyride';

        if (!$library_loaded) {
          drupal_set_message(t('Can\'t load Joyride library. Please download !url jQuery plugin and extract it to @path, so @js can be found at @full_path.', array(
            '!url' => l(t('Zurb Joyride'), 'https://github.com/zurb/joyride'),
            '@path' => $base_path,
            '@js' => $js_name,
            '@full_path' => $base_path . '/' . $js_name,
          )), 'error');
          return FALSE;
        }
        drupal_add_js(drupal_get_path('module', 'scout') . '/inc/js/scout_trail_context.js');
        drupal_add_css(drupal_get_path('module', 'scout') . '/inc/css/scout-' . JOYRIDE_LIBRARY_VERSION . '.css');

        // Trail content consists of a scout_trail entity pointing to one or more scout_tip entities
        $trail_content = $context->reactions[$this->plugin]['trail_content'];
        if(empty($trail_content)) return FALSE;

        // Collect the scout_tips from the scout_trail and prepare,
        // to format trail content.
        $scout_trail_wrapper = entity_metadata_wrapper('scout_trail', $trail_content);
        $scout_tips = $scout_trail_wrapper->field_scout_trail_tips;
        $scout_tip_content = array();

        // Retrieve content from each attached scout tip
        foreach ($scout_tips as $key => $scout_tip) {
          $scout_tip_content[] = $scout_tip->value();
        }
        // Preprocess trail stops into (sanitized html) trail content for theming and Joyride library jquery
        $trail_content = scout_trails_markup_scout_trail($scout_tip_content);

        // Build the jquery settings with our completed content and context settings.
        $js_settings = array(
          'scoutContext' => array(
            'trail_content' => theme('scout_trail', array('trail_content' => $trail_content)),
            'auto_start' => (boolean)$context->reactions[$this->plugin]['trail_auto_start'],
            'play_once' => (boolean)$context->reactions[$this->plugin]['trail_play_once'],
          ),
        );

        drupal_add_js($js_settings, 'setting');
      }
    }
  }
}