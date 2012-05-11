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

using std::cerr;
using std::endl;

/*
 *
 */
int main(int argc, char** argv) {
    Config config = {{640, 480, false}, 200, 0.005, 0.25};

    try {
        { // make sure the destructor is called before the error message is written (→ log messages before error)
            App magBounceApp(&config);
            magBounceApp.run(new Game());
        }
        return EXIT_SUCCESS;
    } catch (const std::runtime_error& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}
