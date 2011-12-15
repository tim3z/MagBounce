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

using std::cerr; using std::endl; using std::runtime_error;

/*
 *
 */
int main(int argc, char** argv) {
    try {
        App magBounceApp;
        magBounceApp.run();
        return EXIT_SUCCESS;
    } catch (runtime_error& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}
