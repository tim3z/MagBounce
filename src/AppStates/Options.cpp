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

vector<vector<RenderableObject*>*>* Options::getRenderLayers() {
    return nullptr;
}

Vector2D Options::getCameraPosition() {
    return Vector2D();
}
