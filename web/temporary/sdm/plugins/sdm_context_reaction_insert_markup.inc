<?php
/**
 * @file
 * sdm_context_reaction_insert_markup.inc
 */
class sdm_context_reaction_insert_markup extends context_reaction {

  /**
   * Allow admins to select sdm data to include when context is active.
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $entities = sdm_data_load_multiple(false, array(), true);
    $options = array();
    foreach($entities as $item) {
      $options[$item->sdm_data_id] = $item->name;
    }
    $form = array(
      'sdm_entities' => array(
        '#title' => t('Include Structured Data Markup'),
        '#description' => t('Select SDM entities to render when this context is active.'),
        '#type' => 'checkboxes',
        '#default_value' => isset($values['sdm_entities']) ? $values['sdm_entities'] : array(),
        '#options' => $options,
      ),
    );
    return $form;
  }

  function execute($ids)
  {
    $sdm_entities = sdm_data_load_multiple($ids, array(), TRUE);
    foreach ($sdm_entities as $sdm_data) {
      $content = "{\n";
      if (!empty($sdm_data->context)) {
        // If it starts with an alpha character, assume we need quotes.
        if (preg_match('/^[a-z]/i', $sdm_data->context)) {
          $content .= "\"@context\": \"{$sdm_data->context}\",\n";
        }
        else {
          $content .= "\"@context\": {$sdm_data->context},\n";
        }
      }
      if (!empty($sdm_data->id)) {
        $content .= "\"@id\": \"{$sdm_data->id}\",\n";
      }
      if (!empty($sdm_data->graph)) {
        $content .= "\"@graph\": {$sdm_data->graph},\n";
      }
      if (!empty($sdm_data->type)) {
        $content .= "\"@type\": \"{$sdm_data->type}\",\n";
      }
      if (!empty($sdm_data->reverse)) {
        $content .= "\"@reverse\": {$sdm_data->reverse},\n";
      }

      // Get field values.
      $wrapper = entity_metadata_wrapper('sdm_data', $sdm_data);
      $instances = field_info_instances('sdm_data', $sdm_data->sdm_data_type);
      $index = 0;
      foreach ($instances as $instance) {
        $label = $instance['label'];
        $value = $wrapper->{$instance['field_name']}->value();
        if (empty($value)) {
          continue;
        }
        $content .= "\"$label\": ";
        // Assume to add quotes if field is a textfield. Dont add quotes to textareas.
        $field = field_info_field($instance['field_name']);
        $is_textfield = ($field['type'] == 'text');
        if (!is_array($value)) {
          if ($is_textfield) {
            $content .= "\"$value\"";
          }
          else {
            $content .= "$value";
          }
        }
        else {
          $content .= "[\n";
          foreach ($value as $key => $item) {
            if ($is_textfield) {
              $content .= "\"$item\"";
            }
            else {
              $content .= "$item";
            }
            if ($key < count($value)-1) {
              $content .= ",\n";
            }
            else {
              $content .= "\n";
            }
          }
          $content .= "]";
        }
        if ($index < count($instances)-1) {
          $content .= ",\n";
          $index ++;
        }
        else {
          $content .= "\n";
        }
      }
      $content .= "}\n";

      // Can't use drupal_add_js as it only uses type=text/javascript.
      $tag = array(
        '#tag' => 'script',
        '#value' => $content,
        '#attributes' => array(
          'type' => 'application/ld+json',
        )
      );
      drupal_add_html_head($tag, "sdm-code-{$sdm_data->sdm_data_id}");
    }
  }
}
