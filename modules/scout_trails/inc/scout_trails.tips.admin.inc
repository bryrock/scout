<?php
/**
 * @file
 * scout_trails.tips.admin.inc
 */

/************************************************************************************
 *
 * Scout Tips Forms
 *
 ************************************************************************************
 */

function scout_tips_form_list($form, $form_state) {
	//dpm($form_state['values']['trailtip_edit'],'$form_state[values][trailtip_edit] - scout_tips_form_list()');
	return $form['trail']['trailtips']['hidden'];
}

/**
 * Callback for the cancel link on scout tip forms.
 */
function scout_tip_form_cancel() {
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;
}

/**
 * Scout Tip delete form.
 */
function scout_tip_delete_form($form, &$form_state, $scout_tip) {
  $form_state['scout_tip'] = $scout_tip;
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect . '/' .  $scout_tip->tip_id . '/edit';

  return confirm_form($form,
    t('Are you sure you want to delete the scout tip %title?', array('%title' => entity_label('scout_tip', $scout_tip))),
    $form_state['redirect'],
    t('This action cannot be undone.'),
    t('Confirm Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for scout_tip_delete_form
 */
function scout_tip_delete_form_submit($form, &$form_state) {
  $scout_tip = $form_state['scout_tip'];
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  scout_tip_delete($scout_tip);

  drupal_set_message(t('The scout tip %name has been deleted.', array('%name' => $scout_tip->title)));
  watchdog('scout_trails', 'Deleted scout tip %name.', array('%name' =>$scout_tip->title));
}

/**
 * Add new Scout Tip page callback.
 */
function scout_tip_form_add($type) {
  $tip_type = scout_tip_types($type);

  $scout_tip = entity_create('scout_tip', array('type' => $type));
  drupal_set_title(t('Create @name', array('@name' => entity_label('scout_tip_type', $tip_type))));
  $output = drupal_get_form('scout_trail_form', $scout_tip);

  return $output;
}

/**
 * The Scout Tip Form.
 */
function scout_tip_form($form, &$form_state, $scout_tip = NULL) {
  //dpm($scout_tip,'$scout_tip scout_tip_form ');
  global $user;

  $form['scout_tip'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scout - Create a Scout Tip'),
    '#description' => t('Scout tips consist of text content, page location and theming info.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['scout_tip']['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Scout Tip Label'),
    '#description' => t('Displays as title in a Scout Tip.'),
    '#default_value' => $scout_tip->title,
  );

  $form['scout_tip']['tag'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Tag'),
    '#description' => t('Optional tag for organizing / grouping tips in admin view.'),
    '#default_value' => $scout_tip->tag,
    '#autocomplete_path' => 'admin/content/scout-trails/scout-tips/ajax/tag',
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid,
  );

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit']['scout_tip'] = array(
    '#type' => 'submit',
    '#value' => t('Save Scout Tip'),
  );

  $form['actions']['cancel'] = array(
  '#type' => 'submit',
  '#value' => t('Cancel'),
  '#submit' => array('scout_tip_form_cancel'),
  );

  // Attach this Entity type's fields to the Form
  $form_state['scout_tip'] = $scout_tip;
  field_attach_form('scout_tip', $scout_tip, $form, $form_state);

  // Show Delete button if we edit group.
  $tip_id = entity_id('scout_tip', $scout_tip);
  if (!empty($tip_id) && scout_trails_access('edit', $scout_tip)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('scout_tip_form_submit_delete'),
    );
  }
//  dsm($form);
  return $form;
}

/**
 * Submit handler for creating/editing scout_tip.
 */
function scout_tip_form_submit(&$form, &$form_state) {
  $scout_tip = $form_state['scout_tip'];
  $scout_tip->title = $form_state['values']['title'];
  $scout_tip->tag = $form_state['values']['tag'];
  $scout_tip->changed = REQUEST_TIME;
  //dpm($scout_tip, '$scout_tip scout_tip_form_submit');

  // Determine if new tip or update
  $update = TRUE ? (isset($scout_tip->tip_id)) : FALSE;

  // Save and go back.
  field_attach_submit('scout_tip', $scout_tip, $form, $form_state);
  scout_tip_save($scout_tip);

  // Redirect user back to list of Scout Tips.
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  // Log and message
  If (!$update) {
	  watchdog('scout_tip', 'Created new scout tip "%title".', array('%title' => $scout_tip->title));
	  drupal_set_message(t('Scout Tip "%title" has been created.', array('%title' => $scout_tip->title)));
  }
  else {
    watchdog('scout_tip', 'Updated scout tip "%title" (%id).', array('%title' => $scout_tip->title,'%id' => $scout_tip->tip_id));
    drupal_set_message(t('Scout Tip "%title" (%id) has been updated.', array('%title' => $scout_tip->title,'%id' => $scout_tip->tip_id)));
  }
}

/**
 * Submit handler for deleting scout_tip.
 */

function scout_tip_form_submit_delete(&$form, &$form_state) {
  $scout_tip = $form_state['scout_tip']->tip_id;
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect . '/' . $scout_tip . '/delete';
}

/**
 * Page callback for views tag autocomplete
 */
function scout_tips_ui_autocomplete_tag($string = '') {
  $matches = array();
  $views = views_get_view_result('scout_tips','tags','all');
  foreach ($views as $key=>$value) {
    if (!empty($value->scout_tip_tag) && strpos($value->scout_tip_tag, $string) === 0) {
      $matches[$value->scout_tip_tag] = check_plain($value->scout_tip_tag);
      if (count($matches) >= 10) {
        break;
      }
    }
  }
  drupal_json_output($matches);
}
