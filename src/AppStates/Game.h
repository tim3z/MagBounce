
#ifndef GAME_H
#define GAME_H
#include "AppState.h"
#include "../Graphics/GameStateRenderer.h"
#include "../GameStates/GameState.h"
#include "../GameStates/Running.h"
#include "../GameStates/Pause.h"
#include "../Physics/Physics.h"
#include "../Model/Level.h"

class GameState;
class Running;
class Pause;

/**
  * class Game
  * 
  */

class Game : virtual public AppState {
private:
    GameState *currentState;
    bool exit;
    
    Level* currentLevel;
    GameStateRenderer* gameStateRenderer;
    Physics* physics;
    
    
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
