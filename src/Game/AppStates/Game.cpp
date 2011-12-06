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

Game::Game(App* app)
        : AppState(app), currentState(new Running(this)),
          currentLevel(new Level(800, 600)),
          physics(new Physics(currentLevel)) {
    currentLevel->addLevelObject(new RectangularLevelObject(0, 380, 640, 400));
    currentLevel->addLevelObject(new RectangularLevelObject(0, 0, 20, 380));
    currentLevel->addLevelObject(new RectangularLevelObject(620, 0, 640, 380));
    currentLevel->getPlayerObject()->setPosition(100.0f, 200.0f);
}

void Game::processInput(list<InputEvent *> events) {
    // TODO: stub
    currentState->reactOnInput(); // TODO: remove/edit signature
}

void Game::update(int dt) {
    physics->move(dt);

    cout << dt << "ms, x: " << currentLevel->getPlayerObject()->getPosition().getX() << " y: "
         << currentLevel->getPlayerObject()->getPosition().getY() << std::endl;
}

void Game::render() {
    Display* display = app->getDisplay();
    vector<Object*> levelObjects;
    currentLevel->getLevelObjects(&levelObjects);

    for (unsigned int i = 0; i < levelObjects.size(); i++) {
        display->render(levelObjects[i]->getRenderer()->getBitmap(), levelObjects[i]->getRenderingPosition());
    }

    display->update();
}

Game::~Game() {
    delete currentLevel;
    currentLevel = 0;
    delete physics;
    physics = 0;
}
