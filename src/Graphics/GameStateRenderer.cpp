#include "GameStateRenderer.h"
#include "Graphics.h"
#include "Renderer.h"

GameStateRenderer::GameStateRenderer() {
    
}

void GameStateRenderer::renderObjects(std::vector<LevelObject*>* levelObjects) {
    
    LevelObject* currentLevelObject = 0;
    Graphics* graphics = Graphics::getInstance();
    
    for (unsigned int i = 0; i < levelObjects->size(); i++) {
        currentLevelObject = levelObjects->at(i);
        graphics->render(currentLevelObject->getRenderer()->getBitmap(), currentLevelObject->getPosition());
    }
    
    graphics->flipDisplay();
    delete currentLevelObject;
}

GameStateRenderer::~GameStateRenderer() {}
