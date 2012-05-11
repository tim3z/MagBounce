#include "Renderer.h"
#include <allegro5/allegro5.h>

Renderer::Renderer()
        : bitmap(nullptr) {
}

ALLEGRO_BITMAP* Renderer::getBitmap() {
    return bitmap;
}

Renderer::~Renderer() {
    al_destroy_bitmap(bitmap);
}
