#include "Graphics.h"

Graphics* Graphics::graphicsInstance = NULL;

Graphics* Graphics::getInstance() {
    if (graphicsInstance == NULL) {
        graphicsInstance = new Graphics();
    }
    
    return graphicsInstance;
}

Graphics::Graphics () {

    display = al_create_display(640, 480);
    if (!display) {
            fprintf(stderr, "failed to create display!\n");
    } else {
        //al_set_new_display_option(ALLEGRO_VSYNC, 2, ALLEGRO_SUGGEST);
        //al_set_new_display_flags(ALLEGRO_FULLSCREEN);
        al_set_target_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }
}

void Graphics::render(ALLEGRO_BITMAP* bitmap, Vector2D drawPosition) {
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(bitmap, drawPosition[0], drawPosition[1], 0);
}

void Graphics::flipDisplay() {
    al_flip_display();
}

Graphics::~Graphics () {
	al_destroy_display(display);
}