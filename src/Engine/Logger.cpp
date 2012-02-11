/*
 * Logger.cpp
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#include "Logger.h"
#include <stdexcept>
#include <allegro5/allegro5.h>

using std::runtime_error;

Logger::Logger() : thread(0) {
    if (!(thread = al_create_thread(threadFunction, this))) {
        throw new runtime_error("Failed to create logging thread.");
    }

    al_start_thread(thread);
}

Logger::~Logger() {
    al_destroy_thread(thread);
}

void* Logger::threadFunction(ALLEGRO_THREAD* thread, void* instance) {
    //Logger* self = reinterpret_cast<Logger*>(instance);

    while (!al_get_thread_should_stop(thread)) { // as long as al_join_thread is not called
        // TODO
    }

    return 0;
}
