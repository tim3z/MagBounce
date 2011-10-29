#include "Game.h"
#include "../Graphics/Graphics.h"
#include <stdio.h>
#include <sys/time.h>

// Constructors/Destructors
//  

Game::Game(App* app, GameStateRenderer* gameStateRenderer) : AppState(app, gameStateRenderer) {
    this->setExit(false);
    Running* running = new Running(this);
    currentState = running;
    currentLevel = new Level();
    physics = new Physics(currentLevel);
}

Game::Game () {}

void Game::execute() {
    int passed;
    timeval lastTime, currentTime;
    gettimeofday(&lastTime, 0);
    while (!exit) {
        gettimeofday(&currentTime, 0);
        passed = (currentTime.tv_usec - lastTime.tv_usec) / 1000; // miliseconds
        lastTime = currentTime;
        
        currentState->reactOnInput();
        
        physics->move(passed);
        
        std::cout << passed << std::endl;
    }
}

Game::~Game () {
    delete currentLevel;
    currentLevel = NULL;
    delete physics;
    physics = NULL;
}
