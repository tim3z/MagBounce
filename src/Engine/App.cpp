#include "App.h"
#include <iostream>
#include <allegro5/allegro.h>
#include "AppStates/Game.h"
#include "Graphics/Display.h"
#include "Input/EventHandler.h"

using std::cerr;

App::App()
        : display(new Display()), currentState(new Game(this, new EventHandler(display->getAllegroDisplay()))), exit(false) {

}

App::~App() {
    delete currentState;
    delete display;
}

void App::fire() {
    while (!exit) {
        currentState->execute();
    }
}

Display* const App::getDisplay() const {
    return display;
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
