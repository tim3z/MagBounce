/* 
 * File:   EventHandler.h
 * Author: jonathan
 *
 * Created on 31. Oktober 2011, 16:14
 */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

union ALLEGRO_EVENT;
struct ALLEGRO_EVENT_QUEUE;
struct ALLEGRO_EVENT_SOURCE;

class EventHandler {
public:
    EventHandler(ALLEGRO_EVENT_SOURCE* displayEventSource);
    ALLEGRO_EVENT* getEvent();
    virtual ~EventHandler();

private:
    ALLEGRO_EVENT_QUEUE* eventQueue;

    /* uncopyable */
    EventHandler(const EventHandler& orig);
    const EventHandler& operator=(const EventHandler&);
};

#endif	/* EVENTHANDLER_H */

