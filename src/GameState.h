#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

class Game;

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
