#include "App.h"
#include <iostream>
#include <list>
#include <allegro5/allegro.h>
#include "AppStates/Game.h"
#include "Graphics/Display.h"
#include "Input/EventHandler.h"
#include "Input/InputEvent.h"

using std::cerr; using std::list;

App::App()
        : display(new Display()), currentState(new Game()),
          exit(false) {
    // TODO: al_init and other initialization (if not yet done) here, throw exception on error
}

App::~App() {
    delete currentState;
    delete display;
}

void App::fire() {
    int dt;
    double lastTime, currentTime;
    lastTime = al_get_time();

    // game loop
    while (!exit) {
        currentTime = al_get_time();
        dt = (currentTime - lastTime) * 1000; // milliseconds
        lastTime = currentTime;

        processInput();
        update(dt);
        render();
    }
}

void App::processInput() {
    list<InputEvent *> events; // TODO: actually get input events
    currentState->processInput(events);
}

void App::update(int dt) {
    currentState->update(dt);
}

void App::render() {
    currentState->render(*display);
}
