/*
 * main.cpp
 *
 *  Created on: 06.12.2011
 *      Author: moritz
 */

#include <iostream>
#include <stdexcept>
#include <allegro5/allegro.h>
#include "App.h"
#include "AppStates/Game.h"
#include "Config.h"

using std::cerr; using std::endl; using std::runtime_error;

/*
 *
 */
int main(int argc, char** argv) {
    Config config = {{640, 480, false}, 100, 0.01, 0.25};

    try {
        App magBounceApp(&config);
        magBounceApp.run(new Game());
        return EXIT_SUCCESS;
    } catch (runtime_error& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}
