<?php
/**
 * @file
 * sdm_theme.inc
 */

/**
 * Returns HTML for a list of available SDM entity types.
 *
 * @param $variables
 *   An associative array containing:
 *   - content: An array of sdm entity types.
 *
 * @ingroup themeable
 */
function theme_sdm_data_type_list($variables) {
  $content = $variables['content'];

  if ($content) {
    $output = '<dl class="sdm-data-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    $output = '<p>' . t('You have not created any Structure Data Markup types yet. Go to the <a href="@create-sdm-type">Structured Data Markup type creation page</a> to add a new sdm type.', array('@create-sdm-type' => url('admin/structure/sdm/types/add'))) . '</p>';
  }
  return $output;
}
