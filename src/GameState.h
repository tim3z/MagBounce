#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include "Game.h"

/**
  * interface GameState
  * 
  */

class GameState {
private:
    Game *game;
    
public:
    
    GameState (Game *initGame);
    
    virtual ~GameState();
};

#endif // GAMESTATE_H
