#include "Game.h"
#include <iostream>
#include <allegro5/allegro5.h>
#include "GameState.h"
#include "GameStates/Running.h"
#include "Graphics/Display.h"
#include "Graphics/Renderer.h"
#include "Model/Level.h"
#include "Model/PlayerObject.h"
#include "Model/RectangularLevelObject.h"
#include "Physics/Physics.h"

using std::cout;
using namespace r2d;

// Constructors/Destructors
//  

Game::Game()
        : AppState(), currentState(new Running(this)), currentLevel(new Level(800, 600)),
          physics(new Physics(currentLevel)) {
    currentLevel->addLevelObject(new RectangularLevelObject(0, 380, 640, 400));
    currentLevel->addLevelObject(new RectangularLevelObject(0, 0, 20, 380));
    currentLevel->addLevelObject(new RectangularLevelObject(620, 0, 640, 380));
    currentLevel->addLevelObject(new RectangularLevelObject(0, 0, 640, 30));
    currentLevel->getPlayerObject()->setPosition(100.0f, 200.0f);
    currentLevel->getPlayerObject()->setSpeed(Vector2D(-1.0f, 0.0f));
}

AppState* Game::handleEvent(ALLEGRO_EVENT* const event) {
    if (event->type == ALLEGRO_EVENT_KEY_DOWN && event->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
	return nullptr;
    }
    return this;
}

void Game::update(double dt) {
    physics->move(dt * 1000); // physics takes milliseconds ATM
}

void Game::render(Display& display) const {
    // FIXME: thread safe!
     vector<Object*> levelObjects;
     currentLevel->getLevelObjects(&levelObjects);
 
     for (unsigned int i = 0; i < levelObjects.size(); i++) {
         display.render(levelObjects[i]->getRenderer()->getBitmap(), levelObjects[i]->getRenderingPosition());
     }
 
     display.update();
}

Game::~Game() {
    delete currentLevel;
    delete physics;
}
