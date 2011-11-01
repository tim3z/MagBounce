/* 
 * File:   EventHandler.cpp
 * Author: jonathan
 * 
 * Created on 31. Oktober 2011, 16:14
 */

#include "EventHandler.h"

EventHandler::EventHandler() {}

EventHandler::EventHandler(ALLEGRO_DISPLAY* display) {
    this->display = display;
    eventQueue = al_create_event_queue();
    if (al_install_keyboard()) {
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
    }
    al_register_event_source(eventQueue, al_get_display_event_source(this->display));
}

ALLEGRO_EVENT* EventHandler::getEvent(){
    ALLEGRO_EVENT* event = 0;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.05);
    al_wait_for_event_until(this->eventQueue, event, &timeout);
    return event;
}

EventHandler::~EventHandler() {}

