#include "BallRenderer.h"

BallRenderer::BallRenderer(float radius) {
    int size = radius * 2;
    bitmap = al_create_bitmap(size, size);
    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(255, 0, 0));
}
