/*
 * Input.cpp
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#include "Input.h"
#include <stdexcept>
#include <allegro5/allegro5.h>

using std::runtime_error;

InputThread::InputThread() : thread(0) {
    if (!(thread = al_create_thread(threadFunction, this))) {
        throw new runtime_error("Failed to create input thread.");
    }

    al_start_thread(thread);
}

InputThread::~InputThread() {
    al_destroy_thread(thread);
}

void* InputThread::threadFunction(ALLEGRO_THREAD* thread, void* instance) {
    //InputThread* self = reinterpret_cast<InputThread*>(instance);

    while (!al_get_thread_should_stop(thread)) { // as long as al_join_thread is not called
        // TODO
    }

    return 0;
}
