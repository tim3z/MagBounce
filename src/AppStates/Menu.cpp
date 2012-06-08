#include "Menu.h"

Menu::Menu()
        : AppState() {
}

Menu::~Menu() {
}

AppState* Menu::processInput(list<InputEvent*> events) {
    // TODO: stub
    return this;
}

void Menu::update(double dt) {
    // TODO: stub
}

void Menu::render(Display& display) {
    // TODO: stub
}

vector<vector<RenderableObject*>*>* Menu::getRenderLayers() {
    return nullptr;
}

Vector2D Menu::getCameraPosition() {
    return Vector2D();
}

