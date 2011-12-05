#include "Game.h"
#include <iostream>
#include <allegro5/allegro5.h>
#include "App.h"
#include "GameState.h"
#include "GameStates/Running.h"
#include "Graphics/Display.h"
#include "Graphics/Renderer.h"
#include "Model/Level.h"
#include "Model/PlayerObject.h"
#include "Model/RectangularLevelObject.h"
#include "Physics/Physics.h"

using std::cout;

// Constructors/Destructors
//  

Game::Game(App* app, EventHandler* eventHandler)
        : AppState(app, eventHandler), currentState(new Running(this, this->eventHandler)),
          exit(false), currentLevel(new Level(800, 600)),
          physics(new Physics(currentLevel)) {
    currentLevel->addLevelObject(new RectangularLevelObject(0, 380, 640, 400));
    currentLevel->addLevelObject(new RectangularLevelObject(0, 0, 20, 380));
    currentLevel->addLevelObject(new RectangularLevelObject(620, 0, 640, 380));
    currentLevel->getPlayerObject()->setPosition(100.0f, 200.0f);
}

void Game::execute() {
    int passed;
    double lastTime, currentTime;
    lastTime = al_get_time();

    while (!exit) {
        currentTime = al_get_time();
        passed = (currentTime - lastTime) * 1000; // milliseconds
        lastTime = currentTime;

        currentState->reactOnInput();

        physics->move(passed);

        cout << passed << "ms, x: " << currentLevel->getPlayerObject()->getPosition().getX() << " y: "
             << currentLevel->getPlayerObject()->getPosition().getY() << std::endl;

        vector<Object*> objects;
        currentLevel->getLevelObjects(&objects);
        this->renderObjects(&objects);
    }
}

void Game::renderObjects(vector<Object*>* levelObjects) {
    Display* display = app->getDisplay();

    for (unsigned int i = 0; i < levelObjects->size(); i++) {
        display->render((*levelObjects)[i]->getRenderer()->getBitmap(), (*levelObjects)[i]->getRenderingPosition());
    }

    display->update();
}

Game::~Game() {
    delete currentLevel;
    currentLevel = NULL;
    delete physics;
    physics = NULL;
}
