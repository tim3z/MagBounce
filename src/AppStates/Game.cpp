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
        : AppState(), currentState(new Running(this)), currentLevel(new Level(640, 480)),
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
    cam_radius = currentLevel->getHeight() / 4;
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

Vector2D Game::getCameraPosition() {
    Vector2D move = currentLevel->getPlayerObject()->getPosition() - oldCameraPosition;
    if (move.length() > cam_radius) {
        oldCameraPosition += move.normalized() * (move.length()-cam_radius);
    }
    
    if (oldCameraPosition.getX() + 320 > currentLevel->getWidth()) {
        oldCameraPosition.setX(currentLevel->getWidth() - 320);
    }
    if (oldCameraPosition.getX() < 320) {
        oldCameraPosition.setX(320);
    }
    if (oldCameraPosition.getY() + 240 > currentLevel->getHeight()) {
        oldCameraPosition.setY(currentLevel->getHeight() - 240);
    }
    if (oldCameraPosition.getY() < 240) {
        oldCameraPosition.setY(240);
    }
    // TODO use Display size etc
    
    return oldCameraPosition;
}

void Game::getRenderLayers(vector<vector<RenderableObject*>*> &renderLayers) {
    vector<RenderableObject*>* levelObjects = new vector<RenderableObject*>();
    currentLevel->getLevelObjects((vector<Object*>*) levelObjects);
    renderLayers.push_back(levelObjects);
}

Game::~Game() {
    delete currentLevel;
    delete physics;
}
