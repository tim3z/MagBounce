#ifndef GAME_H
#define GAME_H

#include "AppState.h"
#include <vector>

using std::vector;
class App;
class EventHandler;
class GameState;
class Level;
class Object;
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
    Physics* physics;

    void renderObjects(vector<Object*>*);

    Game(const Game&);
    const Game& operator=(const Game&);

public:
    /**
     * Empty Constructor
     */
    Game();

    Game(App* app, EventHandler* eventHandler);

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
