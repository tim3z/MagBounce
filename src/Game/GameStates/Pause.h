#ifndef PAUSE_H
#define PAUSE_H

#include "GameState.h"

/**
 * class Pause
 * 
 */

class EventHandler;

class Pause : public GameState {
public:

    /**
     * Empty Constructor
     */
    Pause();

    Pause(Game*, EventHandler* eventHandler);

    void reactOnInput();

    /**
     * Empty Destructor
     */
    virtual ~Pause();

};

#endif // PAUSE_H