#include <cstdio>
#include <allegro5/allegro.h>
#include "App.h"
#include "Graphics/GameStateRenderer.h"
#include "AppStates/AppStateExit.h"

App::App() {
    Graphics::getInstance();
    GameStateRenderer* gameStateRenderer = new GameStateRenderer();
    game = new Game(this, gameStateRenderer);
    currentState = game;
}

App::fire() {
    currentState->execute();
}

App::~App() {
    delete currentState;
}
