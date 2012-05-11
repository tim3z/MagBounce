#include "App.h"
#include <list>
#include <stdexcept>
#include <allegro5/allegro.h>
#include "AppState.h"
#include "Config.h"
#include "Graphics/Display.h"
#include "Input.h"
#include "Sound.h"
#include "Utilities/Logger.h"
#include "Utilities/Timer.h"

using std::list;
using std::runtime_error;

// FIXME: pass Config by value to prevent errors
App::App(const Config* const config) // Don't initialize members before initializing allegro
        : currentState(nullptr), config(config), display(nullptr), logger(nullptr) {
    if (!al_init()) {
        throw runtime_error("Failed to initialize allegro5.");
    }

    logger = new Logger();

    try {
        display = new Display(&(config->displayConfig));
    } catch (...) {
        delete logger;
        throw;
    }
}

App::~App() {
    delete currentState;
    delete display;
    delete logger;
}

/**
 * Starts all threads and the main loop of the application.
 *
 * @param firstState AppState to load as the first state
 * @throw std::runtime_error if a fatal error occurs.
 */
void App::run(AppState* firstState) {
    AppState* nextState = nullptr;
    currentState = firstState;

    GraphicsThread graphicsThread(*this);
    InputThread inputThread;
    SoundThread soundThread;
    Timer physicsTimer(config->physicsInterval);

    double dt = 0.0;                  // dt which needs to be handled by the physics
    double lastTime = al_get_time();  // time the last game loop iteration started

    /* START OTHER THREADS */
    graphicsThread.start();
    inputThread.start();
    soundThread.start();
    physicsTimer.start();

    /* MAIN THREAD LOOP */
    while (true) {
        double currentTime = al_get_time();
        dt += currentTime - lastTime;
        lastTime = currentTime;

        // make sure we're not too fast
        physicsTimer.consumeTicks();

        // restrict dt to avoid breaking physics and make sure the game doesn't get slower on every iteration
        if (dt > config->maxSimulationTime) dt = config->maxSimulationTime;

        /* PROCESS INPUT */
        list<InputEvent *> events; // TODO: actually get input events
        if (!(nextState = currentState->processInput(events))) break;

        /* UPDATE APPLICATION STATE */
        if (nextState == currentState) {
            // update physics in fixed steps (maximum number of steps: maxSimulationTime/physicsInterval)
            while (dt >= config->physicsInterval) {
                currentState->update(config->physicsInterval);
                dt -= config->physicsInterval;
            }
        } else {
            graphicsThread.pause(); // the graphics thread accesses currentState, so it needs to be paused temporarily
            delete currentState;
            currentState = nextState;
            graphicsThread.resume();
            dt = 0;
        }
    }
}


App::GraphicsThread::GraphicsThread(const App& app)
        : MainThread(), app(app), timer(new Timer(1.0 / app.config->maxFPS)) {

}

App::GraphicsThread::~GraphicsThread() {
    this->stop();
    delete timer;
}

void App::GraphicsThread::init() {
    timer->start();
}

void App::GraphicsThread::main() {
    timer->consumeTicks();
    // FIXME: threadsicherheit!
    app.currentState->render(*(app.display));
    // TODO: interpolate?
}

void App::GraphicsThread::cleanup() {
    timer->stop();
}
