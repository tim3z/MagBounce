/* 
 * File:   EventHandler.h
 * Author: jonathan
 *
 * Created on 31. Oktober 2011, 16:14
 */

#ifndef EVENTHANDLER_H
#define	EVENTHANDLER_H

#include <allegro5/allegro5.h>
#include <allegro5/events.h>

class EventHandler {
public:
    EventHandler();
    EventHandler(ALLEGRO_DISPLAY* display);
    EventHandler(const EventHandler& orig);
    ALLEGRO_EVENT* getEvent();
    virtual ~EventHandler();
private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* eventQueue;
};

#endif	/* EVENTHANDLER_H */
