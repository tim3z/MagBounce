#include <cstdio>
#include <allegro5/allegro.h>
#include "App.h"
#include "Graphics/GameStateRenderer.h"
#include "IO/EventHandler.h"

App::App() {
    eventHandler = new EventHandler(Graphics::getInstance()->getDisplay());
    GameStateRenderer* gameStateRenderer = new GameStateRenderer();
    game = new Game(this, gameStateRenderer, eventHandler);
    currentState = game;
    this->setExit(false);
}

void App::fire() {
    while (!exit) {
        currentState->execute();
    }
    al_destroy_display(Graphics::getInstance()->getDisplay());
}

App::~App() {
    delete currentState;
}
