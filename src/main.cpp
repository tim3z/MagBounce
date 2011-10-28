/* 
 * File:   main.cpp
 * Author: jot
 * Main class with main method to initialize ALLEGRO and all displays (& drivers in the future)
 * Created on 22. Oktober 2011, 19:10
 */

#include <cstdio>
#include <allegro5/allegro.h>
#include "App.h"

/*
 * 
 */
int main(int argc, char** argv) {

    /*
     * Initialization routines (drivers, allegro etc.)
     */
    if (!al_init()) {
            fprintf(stderr, "failed to initialize allegro!\n");
            return -1;
    }

    App magBounceApp();

    return 0;
}
