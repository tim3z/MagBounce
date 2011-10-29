#include "State.h"

State::State(App* app, StateRenderer* stateRenderer) {
    this->app = app;
    this->stateRenderer = stateRenderer;
}

State::State() {
    
}

State::~State() {}
