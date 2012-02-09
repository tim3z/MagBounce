#include "Display.h"
#include <iostream>
#include <allegro5/allegro5.h>

using std::cerr;

Display::Display()
        : display(al_create_display(640, 480)) {
    if (!display) {
        cerr << "Failed to create display.\n";
        // TODO: throw exception!
    } else {
        //al_set_new_display_option(ALLEGRO_VSYNC, 2, ALLEGRO_SUGGEST);
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
        al_set_target_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }
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
