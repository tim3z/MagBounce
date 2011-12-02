#include "Pause.h"

// Constructors/Destructors
//  

Pause::Pause (Game* game, EventHandler* eventHandler) : GameState(game, eventHandler) {}

void Pause::reactOnInput() {}

Pause::~Pause () {}
