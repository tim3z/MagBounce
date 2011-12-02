#include "Running.h"
#include <iostream>
#include "Input/StateInputHandler/RunningInputHandler.h"

using std::cout;

Running::Running (Game* game, EventHandler* eventHandler) : GameState (game, eventHandler) {}

void Running::reactOnInput() {
//    RunningInputHandler* input = new RunningInputHandler(eventHandler);
//    input->getInput();
    cout << "It works!";
}

Running::~Running () {}
