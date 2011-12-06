/*
 * main.cpp
 *
 *  Created on: 06.12.2011
 *      Author: moritz
 */

#include <iostream>
#include <allegro5/allegro.h>
#include "App.h"

using std::cerr;

/*
 *
 */
int main(int argc, char** argv) {

    /*
     * Initialization routines (drivers, allegro etc.)
     */
    if (!al_init()) {
        cerr << "Failed to initialize allegro!\n";
        return -1;
    }

    App magBounceApp;

    magBounceApp.fire();

    return 0;
}
