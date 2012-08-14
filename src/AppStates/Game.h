#ifndef GAME_H
#define GAME_H

#include "AppState.h"
#include <vector>
#include "Math/Vector.h"

using namespace r2d;
using std::vector;
class GameState;
class Level;
class Physics;

/**
 * class Game
 * 
 */

class Game : public virtual AppState {
public:
    Game();
    virtual ~Game();

    AppState* handleEvent(ALLEGRO_EVENT* const event);
    void update(double dt);
    void render(Display& display) const;
    void getRenderLayers(vector<vector<RenderableObject*>*> &renderLayers);
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
