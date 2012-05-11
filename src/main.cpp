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
using namespace r2d;

/*
 *
 */
int main(int argc, char** argv) {
    Config config = {{640, 480, false}};
    std::cout << "Started\n";

    try {
	if (al_init()) {
	    /* In case this code is restructured later, it should be made sure that the App destructor is called
	     * before writing the error message. This way, all buffered log messages appear before the error message. */
	    App magBounceApp(&config);
            magBounceApp.start(new Game());
	} else {
	    throw std::runtime_error("Failed to initialize allegro5.");
	}
	return EXIT_SUCCESS;
    } catch (const std::runtime_error& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}
