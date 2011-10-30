#include "Renderer.h"

ALLEGRO_BITMAP* Renderer::getBitmap() {
    return bitmap;
}

Renderer::~Renderer() {
	// FIXME: ALLEGRO_BITMAP is not a C++ class! Does this really work?
    delete bitmap;
}
