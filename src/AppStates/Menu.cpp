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

void Menu::getRenderLayers(vector<vector<RenderableObject*>*> &renderLayers) {
    //TODO: Fill renderable list
}

Vector2D Menu::getCameraPosition() {
    return Vector2D();
}

