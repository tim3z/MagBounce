#include "Game.h"
#include "../Graphics/Graphics.h"

// Constructors/Destructors
//  

Game::Game(App* app, GameStateRenderer* gameStateRenderer) : AppState(app, gameStateRenderer) {
    this->setExit(false);
    Running* running = new Running(this);
    currentState = running;
}

Game::Game () {}

void Game::execute() {
    while (!exit) {
        currentState->reactOnInput();
    }
}

Game::~Game () {}
