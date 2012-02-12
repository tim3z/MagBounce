/* 
 * File:   EventHandler.cpp
 * Author: jonathan
 * 
 * Created on 31. Oktober 2011, 16:14
 */

#include "EventHandler.h"
#include <allegro5/allegro5.h>
#include <allegro5/events.h>

EventHandler::EventHandler(ALLEGRO_EVENT_SOURCE* displayEventSource)
        : eventQueue(al_create_event_queue()) {
    if (al_install_keyboard()) {
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
    }
    al_register_event_source(eventQueue, displayEventSource);
}

ALLEGRO_EVENT* EventHandler::getEvent() {
    ALLEGRO_EVENT* event = nullptr;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.05);
    al_wait_for_event_until(this->eventQueue, event, &timeout);
    return event;
}

EventHandler::~EventHandler() {
}

