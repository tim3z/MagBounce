#include "Game.h"
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "GameState.h"
#include "GameStates/Running.h"
#include "Graphics/GameStateRenderer.h"
#include "Model/Level.h"
#include "Model/PlayerObject.h"
#include "Model/RectangularLevelObject.h"
#include "Physics/Physics.h"

// Constructors/Destructors
//  

Game::Game(App* app, GameStateRenderer* gameStateRenderer,
		EventHandler* eventHandler) :
		AppState(app, gameStateRenderer, eventHandler),
		currentState(new Running(this, this->eventHandler)),
		exit(false), currentLevel(new Level(800, 600)),
		gameStateRenderer(gameStateRenderer),
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

		std::cout << passed << "ms, x: "
				<< currentLevel->getPlayerObject()->getPosition()[0] << " y: "
				<< currentLevel->getPlayerObject()->getPosition()[1]
				<< std::endl;

		std::vector<Object*> objects;
		currentLevel->getLevelObjects(&objects);
		gameStateRenderer->renderObjects(&objects);
	}
}

Game::~Game() {
	delete currentLevel;
	currentLevel = NULL;
	delete physics;
	physics = NULL;
}
