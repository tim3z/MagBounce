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
          physics(new Physics(currentLevel)), positive(0), negative(0) {
    currentLevel->addLevelObject(new RectangularLevelObject(0, 380, 640, 400));
    RectangularLevelObject* r = new RectangularLevelObject(0, 0, 20, 380);
    r->setMagneticState(-1);
    currentLevel->addLevelObject(r);
    currentLevel->addLevelObject(new RectangularLevelObject(620, 0, 640, 380));
    currentLevel->addLevelObject(new RectangularLevelObject(0, 0, 640, 30));
    currentLevel->getPlayerObject()->setPosition(100.0f, 200.0f);
    currentLevel->getPlayerObject()->setSpeed(Vector2D(-0.5f, 0.0f));
    oldCameraPosition = currentLevel->getPlayerObject()->getPosition();
}

AppState* Game::handleEvent(ALLEGRO_EVENT* const event) {
    if (event->type == ALLEGRO_EVENT_KEY_DOWN && event->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
	return nullptr;
    }
    
    if (event->type == ALLEGRO_EVENT_KEY_DOWN && event->keyboard.keycode == ALLEGRO_KEY_N) {
	negative = 1;
    }
    
    
    if (event->type == ALLEGRO_EVENT_KEY_UP && event->keyboard.keycode == ALLEGRO_KEY_N) {
	negative = 0;
    }
    
    if (event->type == ALLEGRO_EVENT_KEY_DOWN && event->keyboard.keycode == ALLEGRO_KEY_P) {
	positive = 1;
    }
    
    
    if (event->type == ALLEGRO_EVENT_KEY_UP && event->keyboard.keycode == ALLEGRO_KEY_P) {
	positive = 0;
    }
    
    if (negative == 0 && positive == 1) {
	currentLevel->getPlayerObject()->setMagneticState(1);
    } else if (negative == 1 && positive == 0) {
	currentLevel->getPlayerObject()->setMagneticState(-1);
    } else {
	currentLevel->getPlayerObject()->setMagneticState(0);
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

Vector2D Game::getCameraPosition() {
//    int width = 640;
//    int height = 480;
    Vector2D currentPosition = currentLevel->getPlayerObject()->getPosition();
    Vector2D move = currentPosition - oldCameraPosition;
    if (move.length() > 250) {
        currentPosition = oldCameraPosition + move.normalized() * (move.length()-250);
    }
    oldCameraPosition = currentPosition;
    return currentPosition;
}

vector<vector<RenderableObject&>*>* Game::getRenderLayers() {
    return nullptr;
}

Game::~Game() {
    delete currentLevel;
    delete physics;
}
