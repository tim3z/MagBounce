#include "TestRenderer.h"
#include "Graphics.h"

TestRenderer::TestRenderer() {
    
    bitmap = al_create_bitmap(20, 20);
    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(255, 0, 255));
}

ALLEGRO_BITMAP* TestRenderer::getBitmap() {
    return bitmap;
}

TestRenderer::~TestRenderer() {
    
}