
#ifndef INGAME_H
#define INGAME_H
#include "State.h"
#include "Graphics/GameStateRenderer.h"
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
    GameStateRenderer* gameStateRenderer;
    GameState *currentState;
    Running *running;
    Pause *pause;
    
public:
    
    /**
     * Empty Constructor
     */
    Game ();
    
    Game (App* app, GameStateRenderer* gameStateRenderer);

    /**
     * Empty Destructor
     */
    virtual ~Game ();

};

#endif // INGAME_H
