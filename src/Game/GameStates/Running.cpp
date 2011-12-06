#include "Running.h"
#include <iostream>
#include "Input/StateInputHandler/RunningInputHandler.h"

using std::cout;

Running::Running(Game* game)
        : GameState(game) {
}

void Running::reactOnInput() {
//    RunningInputHandler* input = new RunningInputHandler(eventHandler);
//    input->getInput();
    cout << "It works!";
}

Running::~Running() {
}
