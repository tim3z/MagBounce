
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
     * This method calls all methods to calculate the movement and moves all LevelObjects.
     */
    void processMovement();
    
    /**
     * This Method uses the current StateRenderer to render all LevelObjects.
     */
    void render();

    /**
     * Empty Destructor
     */
    virtual ~Game ();

};

#endif // INGAME_H
