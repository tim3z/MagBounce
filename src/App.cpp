#include <cstdio>
#include <allegro5/allegro.h>
#include "App.h"
#include "Graphics/GameStateRenderer.h"

App::App() {
    Graphics::getInstance();
    GameStateRenderer* gameStateRenderer = new GameStateRenderer();
    game = new Game(this, gameStateRenderer);
    currentState = game;
    this->setExit(false);
}

void App::fire() {
    while (!exit) {
        currentState->execute();
    }
}

App::~App() {
    delete currentState;
}
