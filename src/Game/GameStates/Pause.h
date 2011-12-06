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
    Pause(Game*);
    virtual ~Pause();

    void reactOnInput();
};

#endif // PAUSE_H
