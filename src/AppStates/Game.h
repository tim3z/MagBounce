
#ifndef GAME_H
#define GAME_H
#include "AppState.h"
#include <string>
#include "../Graphics/GameStateRenderer.h"
#include "../GameStates/GameState.h"
#include "../GameStates/Running.h"
#include "../GameStates/Pause.h"

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
    bool exit;
    
public:
    
    /**
     * Empty Constructor
     */
    Game ();
    
    Game (App* app, GameStateRenderer* gameStateRenderer);
    
    void execute();
    
    void setExit(bool flag) {
        exit = flag;
    }

    /**
     * Empty Destructor
     */
    virtual ~Game ();

};

#endif // GAME_H
