#include "Display.h"
#include <iostream>
#include <stdexcept>
#include <allegro5/allegro5.h>
#include "DisplayConfig.h"

using std::cerr;
using std::runtime_error;

Display::Display(const DisplayConfig* const config)
        : display(nullptr) {
    if (config->fullscreen) al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    //al_set_new_display_option(ALLEGRO_VSYNC, 2, ALLEGRO_SUGGEST);

    if (!(display = al_create_display(config->width, config->height))) {
        throw runtime_error("Failed to initialize display.");
    }

    al_set_target_bitmap(al_get_backbuffer(display));
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

Display::~Display() {
    al_destroy_display(display);
}

void Display::render(ALLEGRO_BITMAP* bitmap, Vector2D screenPosition) {
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(bitmap, screenPosition.getX(), screenPosition.getY(), 0);
}

void Display::update() {
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

ALLEGRO_EVENT_SOURCE* const Display::getEventSource() const {
    return al_get_display_event_source(this->display);
}
