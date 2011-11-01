#include "GameStateRenderer.h"
#include "Graphics.h"
#include "Renderer.h"

GameStateRenderer::GameStateRenderer() {
    
}

void GameStateRenderer::renderObjects(std::vector<LevelObject*>* levelObjects) {
    
    Graphics* graphics = Graphics::getInstance();
    
    for (unsigned int i = 0; i < levelObjects->size(); i++) {
        graphics->render((*levelObjects)[i]->getRenderer()->getBitmap(), (*levelObjects)[i]->getRenderingPosition());
    }
    
    graphics->flipDisplay();
}

GameStateRenderer::~GameStateRenderer() {}