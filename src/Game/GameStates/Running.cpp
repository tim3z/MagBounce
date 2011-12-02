#include "Running.h"
#include <stdio.h>
#include "../IO/StateInputHandler/RunningInputHandler.h"

Running::Running (Game* game, EventHandler* eventHandler) : GameState (game, eventHandler) {}

void Running::reactOnInput() {
//    RunningInputHandler* input = new RunningInputHandler(eventHandler);
//    input->getInput();
    printf("It works!");
}

Running::~Running () {}
