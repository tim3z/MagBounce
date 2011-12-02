#include "App.h"
#include <allegro5/allegro.h>
#include "AppState.h"
#include "AppStates/Game.h"
#include "Graphics/GameStateRenderer.h"
#include "Graphics/Graphics.h"
#include "Input/EventHandler.h"

using std::cerr;

App::App() :
	eventHandler(new EventHandler(Graphics::getInstance()->getDisplay())),
	game(new Game(this, new GameStateRenderer(), eventHandler)),
	currentState(game),
	exit(false) {

}

void App::fire() {
    while (!exit) {
        currentState->execute();
    }
    al_destroy_display(Graphics::getInstance()->getDisplay());
}

App::~App() {
    delete currentState;
}

/*
 *
 */
int main(int argc, char** argv) {

    /*
     * Initialization routines (drivers, allegro etc.)
     */
    if (!al_init()) {
            cerr << "Failed to initialize allegro!\n";
            return -1;
    }

    App magBounceApp;

    magBounceApp.fire();

    return 0;
}
