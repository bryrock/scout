<?php
/**
 * @file
 * scout_trails.trails.admin.inc
 */

/************************************************************************************
 *
 * Scout Trails  (trail types below)
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

/*
  $form['trail']['trail_ref_stops'] = array(
    '#type' => 'entityreference',
    '#title' => t('Referenced Scout Stops'),
    '#description' => t('The Scout Stops on this trail.'),
    '#era_entity_type' => 'scout_stop',
    '#era_bundles' => array('public'),
    '#era_cardinality' => 1,
//    '#collapsible' => FALSE,
  );

*/
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

  // Save and go back.
  //field_attach_submit($type, $entity, $form, &$form_state, $options = array());
  field_attach_submit('scout_trail', $trail, $form, &$form_state);
  scout_trail_save($trail);

  // Redirect user back to list of task types.
  $redirect = entity_get_info('scout_trail');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  watchdog('scout_trail', 'Created scout trail %title.', array('%title' => $trail->title));
  drupal_set_message(t('%title has been created.', array('%title' => $trail->title)));
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
 * Submit handler for Scout Trails & Scout Stops.
 */

function scout_trails_form_submit($form, &$form_state) {
	$submit_click = $form_state['clicked_button']['#value'];
	dsm($submit_click,'Clicked');
	switch ($submit_click) {

		case	'Save Scout Tip':
		  dsm($form['scout_tip'], 'Scout Tip Values');
		  break;
		case	'Save Trail':
		  dsm($form['trail'], 'Trail Values');
	}
}

/************************************************************************************
 *
 * Scout Trail Types
 *
 ************************************************************************************
 */

/**
 * Submit handler for creating/editing scout_trail_type.
 */
function scout_trail_type_form_submit(&$form, &$form_state) {
  $trail_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  scout_trail_type_save($trail_type);

  // Redirect user back to list of task types.
  $form_state['redirect'] = 'admin/structure/scout/scout-trail-types/';
}

/**
 * Submit handler for deleting scout_trail_type.
 */
function scout_trail_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/scout/scout-trail-types/' . $form_state['scout_trail_type']->type . '/delete';
}

/**
 * Trail type delete form. scout_trails_trail_delete_form
 */
function scout_trail_type_form_delete_confirm($form, &$form_state, $trail_type) {
  $form_state['scout_trail_type'] = $trail_type;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['scout_trail_type_id'] = array('#type' => 'value', '#value' => entity_id('scout_trail_type' ,$trail_type));
  return confirm_form($form,
    t('Are you sure you want to delete scout trail type %title?', array('%title' => entity_label('scout_trail_type', $trail_type))),
    'scout_trail/' . entity_id('scout_trail_type' ,$trail_type),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Scout Trail type delete form submit handler.
 */
function scout_trail_type_form_delete_confirm_submit($form, &$form_state) {
  $trail_type = $form_state['scout_trail_type'];
  scout_trail_type_delete($trail_type);

  watchdog('scout_trail_type', '@type: deleted %title.', array('@type' => $trail_type->type, '%title' => $trail_type->label));
  drupal_set_message(t('@type %title has been deleted.', array('@type' => $trail_type->type, '%title' => $trail_type->label)));

  $form_state['redirect'] = 'admin/structure/scout/scout-trail-types/';
}

/**
 * Generates the scout trail type editing form.
 */
function scout_trail_type_form($form, &$form_state, $trail_type, $op = 'edit') {
  // insert module info
  $trail_type->module = 'scout_trails';

  //build default type name if this type is cloned
  if ($op == 'clone') {
    $trail_type->label .= ' (cloned)';
    $trail_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $trail_type->label,
    '#description' => t('The human-readable name of this trail type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($trail_type->type) ? $trail_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $trail_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'scout_trail_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this scout trail type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($trail_type->description) ? $trail_type->description : '',
    '#description' => t('Description about the scout trail type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save trail type'),
    '#weight' => 40,
  );

  if (!$trail_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete trail type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('scout_trail_type_form_submit_delete')
    );
  }
  return $form;
}
