#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

/**
  * interface GameState
  * 
  */

class GameState {
    class Game;
    
private:
    Game *game;
    
public:
    
    GameState ();
    GameState (Game *initGame);
    
    virtual ~GameState();
};

#endif // GAMESTATE_H
