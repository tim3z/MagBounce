#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

class Game;
class EventHandler;

/**
  * interface GameState
  * 
  */

class GameState {
    
protected:
    Game *game;
    EventHandler* eventHandler;
    
public:
    
    GameState();
    GameState(Game *game, EventHandler* eventHandler);
    
    virtual ~GameState();
    
    virtual void reactOnInput() = 0; //TODO bekommt boolean key array als parameter!
};

#endif // GAMESTATE_H
