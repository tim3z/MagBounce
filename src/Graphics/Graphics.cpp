#include "Graphics.h"
#include "TestRenderer.h"

// Constructors/Destructors
//  

Graphics::Graphics () {

    display = al_create_display(640, 480);
    if (!display) {
            fprintf(stderr, "failed to create display!\n");
    } else {
        al_set_target_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }
}

void Graphics::render(ALLEGRO_BITMAP* bitmap) {
    al_flip_display();
    al_rest(10.0);
}

Graphics::~Graphics () {
	al_destroy_display(display);
}

