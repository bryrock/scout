<?php
/**
 * @file
 * scout_trails.trails.admin.inc
 */

/************************************************************************************
 *
 * Scout Trails Forms
 *
 ************************************************************************************
 */

/**
 * Callback for the cancel link on trail forms.
 */
function scout_trail_form_cancel() {
  $redirect = entity_get_info('scout_trail');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;
}

/**
 * Scout Trail delete form.
 */
function scout_trail_delete_form($form, &$form_state, $trail) {
  $form_state['trail'] = $trail;
  $redirect = entity_get_info('scout_trail');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect . '/' .  $trail->trail_id . '/edit';

  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => entity_label('scout_trail', $trail))),
    $form_state['redirect'],
    t('This action cannot be undone.'),
    t('Confirm Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for scout_trail_delete_form
 */
function scout_trail_delete_form_submit($form, &$form_state) {
  $trail = $form_state['trail'];
  $redirect = entity_get_info('scout_trail');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  scout_trail_delete($trail);

  drupal_set_message(t('The scout trail %name has been deleted.', array('%name' => $trail->title)));
  watchdog('scout_trails', 'Deleted scout trail %name.', array('%name' =>$trail->title));
}

/**
 * Scout Trail Form.
 */
function scout_trail_form($form, &$form_state, $scout_trail = NULL) {

  global $user;

  $form['trail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Create a Scout Trail'),
    '#description' => t('Scout trails consist of a name and one or more scout tips.'),
    '#collapsible' => FALSE,
  );

  $form['trail']['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Trail Name'),
    '#default_value' => $scout_trail->title,
  );

  $form['trail']['description'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Trail Description'),
    '#default_value' => $scout_trail->description,
  );

  $form['trail']['tag'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Tag'),
    '#description' => t('Optional tag for organizing / grouping trails in admin view.'),
    '#default_value' => $scout_trail->tag,
    '#autocomplete_path' => 'admin/content/scout-trails/ajax/tag',
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid,
  );

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit']['trail'] = array(
    '#type' => 'submit',
    '#value' => t('Save Trail'),
  );

  $form['actions']['cancel'] = array(
  '#type' => 'submit',
  '#value' => t('Cancel'),
  '#submit' => array('scout_trail_form_cancel'),
  );

  // Attach this Entity type's fields to the Form
  $form_state['trail'] = $scout_trail;
  field_attach_form('scout_trail', $scout_trail, $form, $form_state);

  // Show Delete button if we edit group.
  $trail_id = entity_id('scout_trail', $scout_trail);
  if (!empty($trail_id) && scout_trails_access('edit', $scout_trail)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('scout_trail_form_submit_delete'),
    );
  }
//  dsm($form);
  return $form;
}

/**
 * Submit handler for creating/editing scout_trail.
 */
function scout_trail_form_submit(&$form, &$form_state) {
  $trail = $form_state['trail'];
  $trail->title = $form_state['values']['title'];
  $trail->description = $form_state['values']['description'];
  $trail->tag = $form_state['values']['tag'];
  $trail->changed = REQUEST_TIME;
//  dpm($trail, '$scout_trail scout_trail_form_submit');

  // Determine if new trail or update
  $update = TRUE ? (isset($trail->trail_id)) : FALSE;

  // Save and go back.
  field_attach_submit('scout_trail', $trail, $form, $form_state);
  scout_trail_save($trail);

  // Redirect user back to list of task types.
  $redirect = entity_get_info('scout_trail');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  // Log and message
  If (!$update) {
	  watchdog('scout_trail', 'Created new scout trail "%title".', array('%title' => $trail->title));
	  drupal_set_message(t('Scout Trail "%title" has been created.', array('%title' => $trail->title)));
  }
  else {
    watchdog('scout_trail', 'Updated scout trail "%title" (%id).', array('%title' => $trail->title,'%id' => $trail->trail_id));
    drupal_set_message(t('Scout Trail "%title" (%id) has been updated.', array('%title' => $trail->title,'%id' => $trail->trail_id)));
  }
}

/**
 * Submit handler for deleting scout_trail.
 */

function scout_trail_form_submit_delete(&$form, &$form_state) {
  $trail = $form_state['trail']->trail_id;
  $redirect = entity_get_info('scout_trail');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect . '/' . $trail . '/delete';
}

/**
 * Validate numeric fields.
 */
function scout_trails_numeric_validate($element, &$form_state, $form) {
  if (!is_numeric($element['#value'])) {
    form_error($element, t('Must be a numeric value'));
  }
}

/**
 * Validate selector requirement (must not be blank if stop is not modal).
 */
function scout_trails_selector_validate($element, &$form_state, $form) {
  if (!$form_state['values']['modal']) {
    if ($element['#value'] == '') {
      form_error($element, t('A class selector is required if this scout tip is not modal.'));
    }
  }
}

/**
 * Page callback for views tag autocomplete
 */
function scout_trails_ui_autocomplete_tag($string = '') {
  $matches = array();
  // get matches from default views:
  $views = views_get_view_result('scout_trails','tags','all');
  foreach ($views as $key=>$value) {
    if (!empty($value->scout_trail_tag) && strpos($value->scout_trail_tag, $string) === 0) {
      $matches[$value->scout_trail_tag] = check_plain($value->scout_trail_tag);
      if (count($matches) >= 10) {
        break;
      }
    }
  }
  drupal_json_output($matches);
}
