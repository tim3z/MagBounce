#include "Options.h"

Options::Options()
        : AppState() {
}

Options::~Options() {
}

AppState* Options::processInput(list<InputEvent*> events) {
    // TODO: stub
    return this;
}

void Options::update(double dt) {
    // TODO: stub
}

void Options::render(Display& display) {
    // TODO: stub
}

void Options::getRenderLayers(vector<vector<RenderableObject*>*>* renderLayers) {
    //TODO: Fill renderable list
}

Vector2D Options::getCameraPosition() {
    return Vector2D();
}
