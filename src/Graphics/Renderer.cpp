#include "Renderer.h"

Renderer::Renderer() {

}

ALLEGRO_BITMAP* Renderer::getBitmap() {
    return bitmap;
}

Renderer::~Renderer() {
    al_destroy_bitmap(bitmap);
}
