
#ifndef INGAME_H
#define INGAME_H
#include "State.h"

#include <string>

class GameState;
class Running;
class Pause;

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
