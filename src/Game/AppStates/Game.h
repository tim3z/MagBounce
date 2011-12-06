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
public:
    Game(App* app);
    virtual ~Game();

    void processInput(list<InputEvent*> events);
    void update(int dt);
    void render();

private:
    GameState *currentState;
    Level* currentLevel;
    Physics* physics;

    Game(const Game&);
    const Game& operator=(const Game&);
};

#endif // GAME_H
