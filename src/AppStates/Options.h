#ifndef OPTIONS_H
#define OPTIONS_H
#include "AppState.h"
#include <vector>
#include "Math/Vector.h"

using namespace r2d;
using std::vector;

/**
 * class Options
 * 
 */
class Options : public virtual AppState {
public:
    Options();
    virtual ~Options();

    AppState* processInput(list<InputEvent*> events);
    void update(double dt);
    void render(Display& display);
    virtual Vector2D getCameraPosition();
    virtual vector<vector<RenderableObject*>*>* getRenderLayers();
};

#endif // OPTIONS_H
