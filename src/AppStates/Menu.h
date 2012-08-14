#ifndef MENU_H
#define MENU_H
#include "AppState.h"
#include <vector>
#include "Math/Vector.h"

using namespace r2d;
using std::vector;

/**
 * class Menu
 * 
 */
class Menu : public virtual AppState {
public:
    Menu();
    virtual ~Menu();

    AppState* processInput(list<InputEvent*> events);
    void update(double dt);
    void render(Display& display);
    void getRenderLayers(vector<vector<RenderableObject*>*> &renderLayers);
    Vector2D getCameraPosition();
};

#endif // MENU_H
