#include "BallRenderer.h"
#include <allegro5/allegro5.h>

BallRenderer::BallRenderer(PlayerObject& ball, float radius)
     : ball(ball) {
    int size = radius * 2;
    bitmap = al_create_bitmap(size, size);
}

ALLEGRO_BITMAP* BallRenderer::getBitmap() {
    int magneticState = ball.getMagneticState();
    
    al_set_target_bitmap(bitmap);
    
    if (magneticState < 0) {
        al_clear_to_color(al_map_rgb(0, 0, 127));
    } else if (magneticState > 0) {
        al_clear_to_color(al_map_rgb(127, 0, 0));
    } else {
        al_clear_to_color(al_map_rgb(127, 127, 127));
    }
    
    return bitmap;
}
