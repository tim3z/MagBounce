#include "App.h"
#include <list>
#include <stdexcept>
#include <allegro5/allegro.h>
#include "AppState.h"
#include "Config.h"
#include "Graphics/Display.h"
#include "Input.h"
#include "Sound.h"

using std::list;
using std::runtime_error;

// FIXME: pass Config by value to prevent errors
App::App(const Config* const config) // Don't initialize members before initializing allegro
        : currentState(nullptr), config(config), display(nullptr) {
    if (!al_init()) {
        throw runtime_error("Failed to initialize allegro5.");
    }

    display = new Display(&(config->displayConfig));
}

App::~App() {
    delete display;
    delete currentState;
}

/**
 * Starts all threads and the main loop of the application.
 *
 * @param firstState AppState to load as the first state
 * @throw runtime_error if a serious error has occurred.
 *                      After catching, the application has to be terminated (otherwise, there will be memory leaks).
 */
void App::run(AppState* firstState) {
    AppState* nextState = nullptr;
    currentState = firstState;

    // Threads with own main loop
    GraphicsThread graphicsThread(this);
    InputThread inputThread;
    SoundThread soundThread;

    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* timerEventQueue;
    double dt = 0.0;                  // dt which needs to be handled by the physics
    double lastTime = al_get_time();  // time the last game loop iteration started

    /* CREATE MAIN LOOP TIMER */
    if (!(timer = al_create_timer(config->physicsInterval)) || !(timerEventQueue = al_create_event_queue())) {
        throw runtime_error("Failed to create main loop timer.");
    }

    al_register_event_source(timerEventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    /* MAIN THREAD LOOP */
    while (true) {
        double currentTime = al_get_time();
        dt += currentTime - lastTime;
        lastTime = currentTime;

        // restrict dt to avoid breaking physics and make sure the game doesn't get slower on every iteration
        if (dt > config->maxSimulationTime) dt = config->maxSimulationTime;

        // wait if we're too fast
        if (dt < config->physicsInterval) al_wait_for_event(timerEventQueue, 0);
        al_flush_event_queue(timerEventQueue);

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
            // TODO: wait for threads accessing currentState to finish the current iteration and stop them temporarily
            delete currentState;
            currentState = nextState;
            dt = 0;
        }
    }

    al_destroy_timer(timer);
    al_destroy_event_queue(timerEventQueue);
}


App::GraphicsThread::GraphicsThread(const App* const app) : thread(nullptr) {
    if (!(thread = al_create_thread(threadFunction, static_cast<void*>(const_cast<App*>(app))))) {
        throw runtime_error("Failed to create graphics thread.");
    }

    al_start_thread(thread);
}

App::GraphicsThread::~GraphicsThread() {
    al_destroy_thread(thread);
}

void* App::GraphicsThread::threadFunction(ALLEGRO_THREAD* thread, void* appInstance) {
    const App* const app = static_cast<const App* const>(appInstance);

    /* CREATE TIMER */
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* timerEventQueue;

    if (!(timer = al_create_timer(1.0 / app->config->maxFPS)) || !(timerEventQueue = al_create_event_queue())) {
        throw runtime_error("Failed to create graphics loop timer.");
    }

    al_register_event_source(timerEventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while (!al_get_thread_should_stop(thread)) {
        al_wait_for_event(timerEventQueue, 0);
        al_flush_event_queue(timerEventQueue);
        // FIXME: threadsicherheit!
        app->currentState->render(*(app->display));
        // TODO: interpolate?
    }

    al_destroy_timer(timer);
    al_destroy_event_queue(timerEventQueue);

    return nullptr;
}
