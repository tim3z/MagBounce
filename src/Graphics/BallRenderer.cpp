#include "BallRenderer.h"
#include <allegro5/allegro5.h>

BallRenderer::BallRenderer(float radius) {
    int size = radius * 2;
    bitmap = al_create_bitmap(size, size);
    setColor(127, 127, 127);
}

void BallRenderer::setColor(int r, int g, int b) {
    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(r, g, b));
}

