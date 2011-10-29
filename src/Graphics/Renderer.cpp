#include "Renderer.h"
#include "Graphics.h"

Renderer::Renderer() {
    //TODO: Bitmap loading routine
    bitmap = al_create_bitmap(20, 20);
    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(255, 0, 255));
}

ALLEGRO_BITMAP* Renderer::getBitmap() {
    return bitmap;
}

Renderer::~Renderer() {
    delete bitmap;
}