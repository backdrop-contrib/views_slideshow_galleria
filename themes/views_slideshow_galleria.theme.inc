<?php
// $Id$

/**
 *  @file
 *  Theme & preprocess functions for the Views Slideshow: Galleria module.
 */

/**
 *  We'll grab only the first image from each row.
 */
function template_preprocess_views_slideshow_galleria(&$vars) {
  // Initialize our $images array.
  $vars['images'] = array();

  // Strip all images from the $rows created by the original view query.
  foreach($vars['rows'] as $id => $item) {
    preg_match('@(<\s*img\s+[^>]*>)@i', $item, $matches);
    if ($image = $matches[1]) {
      // We need to add a URL to 'longdesc', as required by the plugin.
      // If our image is in an anchor tag, use its URL.
      preg_match('@<\s*a\s+href\s*=\s*"\s*([^"]+)\s*"[^>]*>[^<]*'. preg_quote($image) .'[^<]*<\s*/a\s*>@i', $item, $urls);
      if (!($url = $urls[1])) {
        // Otherwise link to the original image.
        preg_match('@src\s*=\s*"([^"]+)"@i', $image, $urls);
        if (!($url = $urls[1])) {
          // If we get this far, there are probably more serious problems.
          // But for now, we'll go to the front page instead.
          $url = url('<front>');
        }
      }

      // Add the URL to the image's longdesc tag.
      $vars['rows'][$id] = preg_replace('@img\s+@i', 'img longdesc="'. $url .'" ', $vars['rows'][$id]);

      // Add the image to our image array to display.
      $vars['images'][$id] = $image;
    }
  }

  $options = $vars['options']['views_slideshow_galleria'];

  _views_slideshow_galleria_add_js($options, 'views-slideshow-galleria-images-'. $vars['id']);
}

function _views_slideshow_galleria_add_js($options, $id) {
  // Find the path to our plugin.
  $path = views_slideshow_galleria_path();

  // Add the required JS and CSS.
  drupal_add_js($path .'/galleria.js');

  $drupal_path = drupal_get_path('module', 'views_slideshow_galleria') . '/themes';
  drupal_add_js($drupal_path .'/js/views_slideshow_galleria.js');

  if ($options['advanced']['history']) {
    drupal_add_js($path .'/plugins/galleria.history.js');
  }

  $settings = array(
    'theme' => check_plain($options['theme']),
    'carousel' => $options['carousel'] ? TRUE : 0,
    'carousel_speed' => (integer)$options['carousel_speed'],
    'data_image_selector' => check_plain($options['advanced']['data_image_selector']),
    'data_source' => check_plain($options['advanced']['data_source']),
    'data_type' => check_plain($options['advanced']['data_type']),
    'debug' => $options['advanced']['debug'] ? TRUE : 0,
    'image_crop' => $options['image_crop'] ? TRUE : 0,
    'image_margin' => (integer)$options['image_margin'],
    'image_position' => check_plain($options['image_position']),
    'keep_source' => $options['advanced']['keep_source'] ? TRUE : 0,
    'popup_links' => $options['popup_links'] ? TRUE : 0,
    'queue' => $options['queue'] ? TRUE : 0,
    'show' => (integer)$options['show'],
    'thumb_crop' => $options['thumb_crop'] ? TRUE : 0,
    'thumb_margin' => (integer)$options['thumb_margin'],
    'transition' => check_plain($options['transition']),
    'transition_speed' => (integer)$options['transition_speed'],
  );

  // Set themeURL to the path to the JS theme file for the galleria.
  if ($options['custom_theme_options']['custom_theme'] && $options['custom_theme_options']['theme_path']) {
    $settings['theme'] = check_plain($options['custom_theme_options']['custom_theme']);
    $settings['themeURL'] = url($options['custom_theme_options']['theme_path']);
  }
  else if ($settings['theme'] && !$settings['custom_theme_options']['theme_path']) {
    $settings['themeURL'] = url($path ."/themes/{$settings['theme']}/galleria.{$settings['theme']}.js");
  }
  else if ($settings['custom_theme_options']['theme_path']) {
    // We'll allow a custom theme path to override the default.
    $settings['themeURL'] = url($options['custom_theme_options']['theme_path']);
  }
  else {
    // No theme specified; we assume they're using a Drupal theme for styling.
    $settings['themeURL'] = FALSE;
  }

  // Autoplay is FALSE or the number of MS.
  $settings['autoplay'] = ($options['autoplay'] && (integer)$options['autoplay_ms']) ? (integer)$options['autoplay_ms'] : 0;

  // Carousel_steps is 'auto' or an integer.
  $settings['carousel_steps'] = ($options['carousel_steps'] == 'auto') ? 'auto' : (integer)$options['carousel_steps'];

  if ($options['advanced']['data_config']) {
    $settings['data_config'] = check_plain($options['advanced']['data_config']);
  }
  if ($options['advanced']['extend']) {
    $settings['extend'] = check_plain($options['advanced']['extend']);
  }

  // Height is 'auto' or an integer.
  if (($options['height'] == 'auto') || !(integer)$options['height']) {
    $settings['height'] = 'auto';
  }
  else {
    $settings['height'] = (integer)$options['height'];
  }

  if ($options['max_scale_ratio'] && is_numeric($options['max_scale_ratio'])) {
    $settings['max_scale_ratio'] = (integer)$options['max_scale_ratio'];
  }

  if ($options['advanced']['on_image']) {
    $settings['on_image'] = $options['advanced']['on_image'];
  }

  $settings['preload'] = ($options['preload'] == 'auto') ? 'auto' : (integer)$options['preload'];

  $settings['thumb_quality'] = ($options['advanced']['thumb_quality'] == 'auto') ? 'auto' : (integer)$options['advanced']['thumb_quality'];

  $settings['thumbnails'] = ($options['thumbnails'] == 'empty') ? 'empty' : (integer)$options['thumbnails'];

  drupal_add_js(array('viewsSlideshowGalleria' => array($id => $settings)), 'setting');
}
