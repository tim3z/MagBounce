#include "App.h"
#include <list>
#include <stdexcept>
#include <allegro5/allegro.h>
#include "AppStates/Game.h"
#include "Graphics/Display.h"

using std::list;
using std::runtime_error;

App::App()
        : currentState(0), display(0) { // Don't initialize members before initializing allegro
    if (!al_init()) {
        throw new runtime_error("Failed to initialize allegro5.");
    }
    currentState = new Game();
    display = new Display();
}

App::~App() {
    delete currentState;
    delete display;
}

void App::run() {
    AppState* nextState = 0;

    double dt = 0.0;                  // dt which needs to be handled by the physics
    double lastTime = al_get_time();  // time the last game loop iteration started

    const double INTERVAL = 0.01;     // time interval used for updating the physics (in seconds)
    const double MAX_TIME = 0.25;     // max time simulated within one iteration of the game loop

    while (true) {
        double currentTime = al_get_time();
        dt += currentTime - lastTime;
        lastTime = currentTime;

        // restrict dt to avoid breaking physics and make sure the game doesn't get slower on every iteration
        if (dt > MAX_TIME) dt = MAX_TIME;

        if (dt >= INTERVAL) {
            /* PROCESS INPUT */
            list<InputEvent *> events; // TODO: actually get input events
            if (!(nextState = currentState->processInput(events))) break;

            /* UPDATE APPLICATION STATE */
            if (nextState == currentState) {
                // update physics in fixed steps (maximum: DT_MAX/DT_STEP_SIZE)
                while (dt >= INTERVAL) {
                    currentState->update(INTERVAL);
                    dt -= INTERVAL;
                }
            } else {
                delete currentState;
                currentState = nextState;
                dt = 0;
            }
        }

        /* RENDER */
        currentState->render(*display);
        // TODO: own thread (physics saves state, renderer accesses it), interpolate?
    }
}
