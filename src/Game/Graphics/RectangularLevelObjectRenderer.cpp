/* 
 * File:   RectangularLevelObjectRenderer.cpp
 * Author: eagle
 * 
 * Created on 29. Oktober 2011, 23:58
 */

#include "RectangularLevelObjectRenderer.h"
#include <allegro5/allegro5.h>

RectangularLevelObjectRenderer::RectangularLevelObjectRenderer(float height, float width) {
    //TODO: Bitmap loading routine
    bitmap = al_create_bitmap(height, width);
    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(255, 0, 0));
}

RectangularLevelObjectRenderer::RectangularLevelObjectRenderer(const RectangularLevelObjectRenderer& orig) {
}

RectangularLevelObjectRenderer::~RectangularLevelObjectRenderer() {
}
