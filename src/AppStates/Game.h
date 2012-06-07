#ifndef GAME_H
#define GAME_H

#include "AppState.h"
#include "Math/Vector.h"
#include <vector>

using std::vector;
using namespace r2d;
class GameState;
class Level;
class Physics;

/**
 * class Game
 * 
 */

class Game : public AppState {
public:
    Game();
    virtual ~Game();

    AppState* handleEvent(ALLEGRO_EVENT* const event);
    void update(double dt);
    void render(Display& display) const;
    Vector2D getCameraPosition();

private:
    GameState *currentState;
    Level* currentLevel;
    ::Physics* physics;
    int positive;
    int negative;
    
    Vector2D oldCameraPosition;

    Game(const Game&);
    const Game& operator=(const Game&);
};

#endif // GAME_H
