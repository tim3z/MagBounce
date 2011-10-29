#include "Game.h"
#include <stdio.h>

// Constructors/Destructors
//  

Game::Game(App* app, GameStateRenderer* gameStateRenderer) : AppState(app, gameStateRenderer) {
    this->setExit(false);
}

Game::Game () {}

void Game::execute() {
    while (!exit) {
        printf("It works!");
    }
}

Game::~Game () {}
