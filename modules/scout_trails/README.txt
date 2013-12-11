This is the Read Me file for Scout Trails.

Scout is a Site Navigation aid. It can be used to assist new visitors to your site. It can also by used to help train content managers, guiding them through steps for creation and administration of site content.

Scout is a module/features package of the Zurb Joyride jQuery library for Drupal 7. The Zurb Joyride jQuery library is currently being implemented in Drupal 8 core as "Tours."

Scout brings Joyride functionality along with the Drupal 8 ease of tour creation to Drupal 7. Scout adds a custom Context reaction plug-in to Drupal 7, but works differently than the plugin provided by the Joyride module. Rather than providing a long text field for entering HTML, Scout's context reaction allows you to select a previously assembled Scout Trail (tour) from a simple pull-down list.

Scout Trails are collections of Scout Tips. Both are custom entities.

Scout Tips are created by filling out a form, in a familiar manner similar to adding Drupal content. HTML is optional, but not required.

Scout Trails are also created via a short form, used for assembling collections of Scout Tip entity references.

Once Scout Trails are created and saved, they are available for use by Context.

Scout Tips and Trails are exportable (using Features), so they can be created once and re-used on multiple sites of similar design.

---

Requires: Context, Chaos tools, Entity API, Entity Connect, Entity Reference, Features, Fieldgroup, Field, Field SQL storage, Inline Editing (will be ditched soon as this is a custom module), Options, List, Number, Scout (included), Libraries, Text, Views

Once installed, there is help information and a skinny tutorial at /admin/help/scout_trails.

<!-- TODO - Remove Inline Editing dependency. -->