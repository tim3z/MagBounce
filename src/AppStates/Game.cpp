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
    currentLevel = new Level(800, 600);
    physics = new Physics(currentLevel);
    
    currentLevel->addLevelObject(new RectangularLevelObject(0,380, 640,400));
    currentLevel->addLevelObject(new RectangularLevelObject(0,0, 20,380));
    currentLevel->addLevelObject(new RectangularLevelObject(620,0, 640,380));
    currentLevel->getPlayerObject()->setPosition(100.0f, 50.0f);
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
        
        std::cout << passed << "ms, x: " << currentLevel->getPlayerObject()->getPosition()[0] << " y: " << currentLevel->getPlayerObject()->getPosition()[1] << std::endl;
        
        std::vector<LevelObject*> objects;
        currentLevel->getLevelObjects(&objects);
        gameStateRenderer->renderObjects(&objects);
    }
}

Game::~Game () {
    delete currentLevel;
    currentLevel = NULL;
    delete physics;
    physics = NULL;
}
