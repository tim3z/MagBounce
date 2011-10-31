#include "AppState.h"

AppState::AppState(App* app, StateRenderer* stateRenderer, EventHandler* eventHandler) {
    this->app = app;
    this->stateRenderer = stateRenderer;
    this->eventHandler = eventHandler;
}

AppState::AppState() {
    
}

AppState::~AppState() {}
