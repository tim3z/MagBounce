#include "App.h"
#include <list>
#include <stdexcept>
#include <allegro5/allegro.h>
#include "AppStates/Game.h"
#include "Graphics/Display.h"

using std::list;
using std::runtime_error;

App::App() // Don't initialize members before initializing allegro
        : currentState(0), display(0), graphicsThread(0), inputThread(0), loggingThread(0), soundThread(0) {
    if (!al_init()) {
        throw new runtime_error("Failed to initialize allegro5.");
    }

    // this is passed as an argument in case one thread needs to access the app instance
    if (!(graphicsThread = al_create_thread(graphicsThreadFunction, this))
            || !(inputThread = al_create_thread(inputThreadFunction, this))
            || !(loggingThread = al_create_thread(loggingThreadFunction, this))
            || !(soundThread = al_create_thread(soundThreadFunction, this))) {
        throw new runtime_error("Failed to create threads.");
    }

    currentState = new Game();
    display = new Display();
}

App::~App() {
    al_destroy_thread(graphicsThread);
    al_destroy_thread(inputThread);
    al_destroy_thread(loggingThread);
    al_destroy_thread(soundThread);

    delete currentState;
    delete display;
}

void App::run() {
    AppState* nextState = 0;

    double dt = 0.0;                  // dt which needs to be handled by the physics
    double lastTime = al_get_time();  // time the last game loop iteration started

    const double INTERVAL = 0.01;     // time interval simulated by the physics in one simulation step (in seconds)
    const double MAX_TIME = 0.25;     // max time simulated within one iteration of the game loop (in seconds)

    /* CREATE MAIN LOOP TIMER */
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* timerEventQueue;

    if (!(timer = al_create_timer(INTERVAL)) || !(timerEventQueue = al_create_event_queue())) {
        throw new runtime_error("Failed to create main loop timer.");
    }

    al_register_event_source(timerEventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    /* START ALL OTHER THREADS */
    al_start_thread(graphicsThread);
    al_start_thread(inputThread);
    al_start_thread(loggingThread);
    al_start_thread(soundThread);

    /* MAIN THREAD LOOP */
    while (true) {
        double currentTime = al_get_time();
        dt += currentTime - lastTime;
        lastTime = currentTime;

        // restrict dt to avoid breaking physics and make sure the game doesn't get slower on every iteration
        if (dt > MAX_TIME) dt = MAX_TIME;

        // wait if we're too fast
        if (dt < INTERVAL) al_wait_for_event(timerEventQueue, 0);
        al_flush_event_queue(timerEventQueue);

        /* PROCESS INPUT */
        list<InputEvent *> events; // TODO: actually get input events
        if (!(nextState = currentState->processInput(events))) break;

        /* UPDATE APPLICATION STATE */
        if (nextState == currentState) {
            // update physics in fixed steps (maximum number of steps: MAX_TIME/INTERVAL)
            while (dt >= INTERVAL) {
                currentState->update(INTERVAL);
                dt -= INTERVAL;
            }
        } else {
            // TODO: wait for threads to finish and lock them
            delete currentState;
            currentState = nextState;
            dt = 0;
        }
    }

    al_destroy_timer(timer);
    al_destroy_event_queue(timerEventQueue);
}

void* App::graphicsThreadFunction(ALLEGRO_THREAD* thread, void* arg) {
    App* self = reinterpret_cast<App*>(arg);

    const double FPS = 100;

    /* CREATE TIMER */
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* timerEventQueue;

    if (!(timer = al_create_timer(1.0 / FPS)) || !(timerEventQueue = al_create_event_queue())) {
        throw new runtime_error("Failed to create graphics loop timer.");
    }

    al_register_event_source(timerEventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while (true) {
        al_wait_for_event(timerEventQueue, 0);
        al_flush_event_queue(timerEventQueue);
        // FIXME: threadsicherheit!
        self->currentState->render(*(self->display));
        // TODO: interpolate?
    }

    al_destroy_timer(timer);
    al_destroy_event_queue(timerEventQueue);

    return 0;
}

void* App::inputThreadFunction(ALLEGRO_THREAD* thread, void* arg) {
    App* self = reinterpret_cast<App*>(arg);
    // TODO
    (void) self;
    (void) thread;
    return 0;
}

void* App::loggingThreadFunction(ALLEGRO_THREAD* thread, void* arg) {
    App* self = reinterpret_cast<App*>(arg);
    // TODO
    (void) self;
    (void) thread;
    return 0;
}

void* App::soundThreadFunction(ALLEGRO_THREAD* thread, void* arg) {
    App* self = reinterpret_cast<App*>(arg);
    // TODO
    (void) self;
    (void) thread;
    return 0;
}
