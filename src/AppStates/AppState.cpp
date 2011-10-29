#include "AppState.h"

AppState::AppState(App* app, StateRenderer* stateRenderer) {
    this->app = app;
    this->stateRenderer = stateRenderer;
}

AppState::AppState() {
    
}

AppState::~AppState() {}
