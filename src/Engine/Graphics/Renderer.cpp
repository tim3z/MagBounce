#include "Renderer.h"

Renderer::Renderer() : bitmap(0) {

}

ALLEGRO_BITMAP* Renderer::getBitmap() {
    return bitmap;
}

Renderer::~Renderer() {
    al_destroy_bitmap(bitmap);
}
