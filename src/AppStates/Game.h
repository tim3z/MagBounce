
#ifndef GAME_H
#define GAME_H
#include "AppState.h"
#include "../Graphics/GameStateRenderer.h"
#include <string>

class GameState;
class Running;
class Pause;

/**
  * class Game
  * 
  */

class Game : virtual public AppState {
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
    
    void execute();
    
    Game (App* app, GameStateRenderer* gameStateRenderer);

    /**
     * Empty Destructor
     */
    virtual ~Game ();

};

#endif // GAME_H
