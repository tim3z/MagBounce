#include "AppState.h"

AppState::AppState(App* app, EventHandler* eventHandler)
        : app(app), eventHandler(eventHandler) {
}

AppState::~AppState() {
}
