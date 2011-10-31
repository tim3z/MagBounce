#include "GameState.h"

GameState::GameState(Game* game, EventHandler* eventHandler) {
    this->game = game;
    this->eventHandler = eventHandler;
}

GameState::GameState() {
    
}

GameState::~GameState() {

}
