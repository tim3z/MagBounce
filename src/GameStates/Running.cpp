#include "Running.h"
#include <stdio.h>

// Constructors/Destructors
//  

Running::Running() {}

Running::Running (Game* game) : GameState (game) {}

void Running::reactOnInput() {
    printf("It works!");
}

Running::~Running () {}