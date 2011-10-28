
#ifndef INGAME_H
#define INGAME_H
#include "State.h"

#include <string>

/**
  * class InGame
  * 
  */

class Game : virtual public State {
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
