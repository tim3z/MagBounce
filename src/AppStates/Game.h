
#ifndef GAME_H
#define GAME_H
#include "AppState.h"
#include "../Graphics/GameStateRenderer.h"
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
    
    void execute();
    
    void setExit(bool flag) {
        exit = flag;
    }
    
    Game (App* app, GameStateRenderer* gameStateRenderer);

    /**
     * Empty Destructor
     */
    virtual ~Game ();

};

#endif // GAME_H
