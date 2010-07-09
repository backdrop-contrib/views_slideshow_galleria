<?php
// $Id$

/**
 *  @file
 *  This will format a view to display several images in a Galleria style, for
 *  Views Slideshow: Galleria.
 *
 *  VERY IMPORTANT:
 *  The View MUST return a set of fields composed of Images only.
 *  Anything else WILL break the output.
 *
 * - $view: The view object.
 * - $options: Style options. See below.
 * - $rows: The output for the rows.
 * - $title: The title of this group of rows.  May be empty.
 * - $id: The unique counter for this view.
 * - $images: An array of images that have been stripped from $rows.
 */
?>

  <div id="views-slideshow-galleria-<?php print $id; ?>" class="views-slideshow-galleria">
    <?php if (!empty($title)) : ?>
      <h3><?php print $title; ?></h3>
    <?php endif; ?>

    <div id="views-slideshow-galleria-images-<?php print $id; ?>" class="views-slideshow-galleria-images galleria">
      <?php foreach ($images as $image): ?>
       <?php print $image ."\n"; ?>
      <?php endforeach; ?>
    </div>

  </div>

