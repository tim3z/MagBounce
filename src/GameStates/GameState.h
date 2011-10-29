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
    
protected:
    Game *game;
    
public:
    
    GameState();
    GameState(Game *initGame);
    
    virtual ~GameState();
    
    virtual void reactOnInput() = 0; //TODO bekommt boolean key array als parameter!
};

#endif // GAMESTATE_H
