#include <cstdio>
#include <allegro5/allegro.h>
#include "App.h"

App::App() {
    currentState = new State();
  
    //Do currentState stuff such as moving objects and rendering.
//    while () {
//        currentState
//    }
}

App::~App() {
    currentState->~State();
}
