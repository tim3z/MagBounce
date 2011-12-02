#include "GameStateRenderer.h"
#include "Graphics/Graphics.h"
#include "Graphics/Renderer.h"
#include "Model/Object.h"

GameStateRenderer::GameStateRenderer() {

}

void GameStateRenderer::renderObjects(std::vector<Object*>* levelObjects) {

    Graphics* graphics = Graphics::getInstance();

    for (unsigned int i = 0; i < levelObjects->size(); i++) {
        graphics->render((*levelObjects)[i]->getRenderer()->getBitmap(), (*levelObjects)[i]->getRenderingPosition());
    }

    graphics->flipDisplay();
}

GameStateRenderer::~GameStateRenderer() {
}
