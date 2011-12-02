#ifndef GAME_H
#define GAME_H

#include "AppState.h"

class App;
class EventHandler;
class GameState;
class GameStateRenderer;
class Level;
class Physics;

/**
 * class Game
 * 
 */

class Game : public AppState {
private:
    GameState *currentState;
    bool exit;

    Level* currentLevel;
    GameStateRenderer* gameStateRenderer;
    Physics* physics;

    Game(const Game&);
    const Game& operator=(const Game&);

public:
    /**
     * Empty Constructor
     */
    Game();

    Game(App* app, GameStateRenderer* gameStateRenderer, EventHandler* eventHandler);

    void execute();

    void setExit(bool flag) {
        exit = flag;
    }

    /**
     * Empty Destructor
     */
    virtual ~Game();
};

#endif // GAME_H
