<?php
/**
 * @file
 * scout_trails.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scout_trails_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'scout_tips';
  $view->description = '';
  $view->tag = 'Scout Trails';
  $view->base_table = 'scout_tip';
  $view->human_name = 'Scout Tips';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Scout Tips';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin scout tours';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'tip_id' => 'tip_id',
    'title' => 'title',
    'created' => 'created',
    'changed' => 'changed',
    'uid' => 'uid',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tip_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Exported Status
1 = Custom, 2 = Default, 3 = Overridden';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Notice:';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no available Scout Tips at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Scout Tip: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Scout Tip Type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Scout Tip: scout tip ID */
  $handler->display->display_options['fields']['tip_id']['id'] = 'tip_id';
  $handler->display->display_options['fields']['tip_id']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['tip_id']['field'] = 'tip_id';
  $handler->display->display_options['fields']['tip_id']['label'] = 'tip_id';
  $handler->display->display_options['fields']['tip_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tip_id']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[tip_id]/edit';
  $handler->display->display_options['fields']['tip_id']['separator'] = '';
  /* Field: Scout Tip: scout tip Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[tip_id]/edit';
  /* Field: Scout Tip: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Scout Tip: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Scout Tip: Scout (author) */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Scout';
  $handler->display->display_options['fields']['uid']['separator'] = '';
  /* Field: Scout Tip: Published */
  $handler->display->display_options['fields']['published']['id'] = 'published';
  $handler->display->display_options['fields']['published']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['published']['field'] = 'published';
  $handler->display->display_options['fields']['published']['label'] = 'Viewable';
  /* Field: Scout Tip: Export Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['separator'] = '';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/scout-trails/scout-tips';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Scout Tips';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['scout_tips'] = $view;

  $view = new view();
  $view->name = 'scout_trails';
  $view->description = '';
  $view->tag = 'Scout Trails';
  $view->base_table = 'scout_trail';
  $view->human_name = 'Scout Trails';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Scout Trails';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin scout tours';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'trail_id' => 'trail_id',
    'title' => 'title',
    'description' => 'description',
    'nothing' => 'nothing',
    'nothing_2' => 'nothing',
    'nothing_1' => 'nothing',
    'created' => 'created',
    'changed' => 'changed',
    'uid' => 'uid',
    'status' => 'status',
    'field_scout_trail_tips' => 'field_scout_trail_tips',
    'field_scout_trail_tips_1' => 'field_scout_trail_tips_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'trail_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => ' / ',
      'empty_column' => 0,
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scout_trail_tips' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scout_trail_tips_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="<?php print url(\'scout_trail/add\'); ?>>Add Task</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Notice:';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no available Scout Trails at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Referenced Scout Tips */
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['id'] = 'field_scout_trail_tips_target_id';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['table'] = 'field_data_field_scout_trail_tips';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['field'] = 'field_scout_trail_tips_target_id';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['ui_name'] = 'Referenced Scout Tips';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['label'] = 'Referenced Scout Tips';
  /* Field: Scout Trail: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Trail Type  ';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Scout Trail: Trail ID */
  $handler->display->display_options['fields']['trail_id']['id'] = 'trail_id';
  $handler->display->display_options['fields']['trail_id']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['trail_id']['field'] = 'trail_id';
  $handler->display->display_options['fields']['trail_id']['separator'] = '';
  /* Field: Scout Trail: Trail Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/edit';
  /* Field: Scout Trail: Trail Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Edit Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit Link';
  $handler->display->display_options['fields']['nothing']['label'] = 'Manage';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/edit';
  /* Field: Clone Link */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Clone Link';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Clone';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Clone';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/clone';
  /* Field: Delete Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/delete';
  /* Field: Scout Trail: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Scout Trail: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Scout Trail: Scout */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: Scout Trail: Export Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Scout Trail: Scout Tips */
  $handler->display->display_options['fields']['field_scout_trail_tips']['id'] = 'field_scout_trail_tips';
  $handler->display->display_options['fields']['field_scout_trail_tips']['table'] = 'field_data_field_scout_trail_tips';
  $handler->display->display_options['fields']['field_scout_trail_tips']['field'] = 'field_scout_trail_tips';
  $handler->display->display_options['fields']['field_scout_trail_tips']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['text'] = '[field_scout_trail_tips]-[field_scout_trail_tips-target_id]';
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[field_scout_trail_tips-target_id]/edit';
  $handler->display->display_options['fields']['field_scout_trail_tips']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scout_trail_tips']['empty'] = '(None)';
  $handler->display->display_options['fields']['field_scout_trail_tips']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_scout_trail_tips']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_scout_trail_tips']['delta_limit'] = '0';
  $handler->display->display_options['fields']['field_scout_trail_tips']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_scout_trail_tips']['multi_type'] = 'ol';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/scout-trails/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Scout Trails';
  $handler->display->display_options['menu']['description'] = 'Create scout trails for page navigation aids.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scout Trails';
  $handler->display->display_options['tab_options']['description'] = 'Manage scout trails';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['scout_trails'] = $view;

  return $export;
}
