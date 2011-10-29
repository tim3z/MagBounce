#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

class Game;

/**
  * interface GameState
  * 
  */

class GameState {
    
protected:
    Game *game;
    
public:
    
    GameState();
    GameState(Game *game);
    
    virtual ~GameState();
    
    virtual void reactOnInput() = 0; //TODO bekommt boolean key array als parameter!
};

#endif // GAMESTATE_H
