/* 
 * File:   EventHandler.h
 * Author: jonathan
 *
 * Created on 31. Oktober 2011, 16:14
 */

#ifndef EVENTHANDLER_H
#define	EVENTHANDLER_H

struct ALLEGRO_DISPLAY; union ALLEGRO_EVENT; struct ALLEGRO_EVENT_QUEUE;

class EventHandler {
public:
    EventHandler();
    EventHandler(ALLEGRO_DISPLAY* display);
    ALLEGRO_EVENT* getEvent();
    virtual ~EventHandler();
private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* eventQueue;

    EventHandler(const EventHandler& orig);
    const EventHandler& operator=(const EventHandler&);
};

#endif	/* EVENTHANDLER_H */

