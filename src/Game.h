
#ifndef INGAME_H
#define INGAME_H
#include "State.h"
#include "Running.h"
#include "Pause.h"
#include "GameState.h"

#include <string>

/**
  * class InGame
  * 
  */

class Game : public State {
private:
    GameState *currentState;
    Running *running;
    Pause *pause;
    
public:
    
    /**
     * Empty Constructor
     */
    Game ();

    /**
     * Empty Destructor
     */
    virtual ~Game ();

};

#endif // INGAME_H
