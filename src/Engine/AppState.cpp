#include "AppState.h"
#include "Graphics/StateRenderer.h"


AppState::AppState(App* app, StateRenderer* stateRenderer,
		EventHandler* eventHandler) :
		app(app), stateRenderer(stateRenderer), eventHandler(eventHandler) {
}

AppState::~AppState() {
}
