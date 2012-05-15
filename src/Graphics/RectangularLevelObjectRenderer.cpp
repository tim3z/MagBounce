/* 
 * File:   RectangularLevelObjectRenderer.cpp
 * Author: eagle
 * 
 * Created on 29. Oktober 2011, 23:58
 */

#include "RectangularLevelObjectRenderer.h"
#include <allegro5/allegro5.h>

RectangularLevelObjectRenderer::RectangularLevelObjectRenderer(RectangularLevelObject& levelObject, float height, float width) : levelObject(levelObject) {
    //TODO: Bitmap loading routine
    bitmap = al_create_bitmap(height, width);
//     al_set_target_bitmap(bitmap);
//     al_clear_to_color(al_map_rgb(255, 0, 0));
}

RectangularLevelObjectRenderer::RectangularLevelObjectRenderer(const RectangularLevelObjectRenderer& orig) : levelObject(orig.levelObject) {
}

RectangularLevelObjectRenderer::~RectangularLevelObjectRenderer() {
}

ALLEGRO_BITMAP* RectangularLevelObjectRenderer::getBitmap()
{
    int magneticState = levelObject.getMagneticState();
    
    al_set_target_bitmap(bitmap);
    
    if (magneticState < 0) {
        al_clear_to_color(al_map_rgb(0, 0, 90));
    } else if (magneticState > 0) {
        al_clear_to_color(al_map_rgb(90, 0, 0));
    } else {
        al_clear_to_color(al_map_rgb(90, 90, 90));
    }
    
    return bitmap;
}

