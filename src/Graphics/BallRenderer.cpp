#include "BallRenderer.h"

BallRenderer::BallRenderer(float radius) {
    bitmap = al_create_bitmap(radius, radius);
    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(255, 0, 0));
}
