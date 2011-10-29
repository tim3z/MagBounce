#include "StateRenderer.h"
#include "Graphics.h"
#include "Renderer.h"

StateRenderer::StateRenderer() {
    
}

void StateRenderer::renderObjects(std::vector<LevelObject>* levelObjects) {
    
    LevelObject currentLevelObject;
    Graphics* graphics = Graphics::getInstance();
    
    for (int i = 0; i < levelObjects->size(); i++) {
        currentLevelObject = levelObjects->at(i);
        graphics->render(currentLevelObject.getRenderer()->getBitmap(), currentLevelObject.getPosition());
    }
    
    graphics->flipDisplay();
    currentLevelObject.~LevelObject();
}

StateRenderer::~StateRenderer() {}