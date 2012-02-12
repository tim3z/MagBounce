/*
 * Sound.cpp
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#include "Sound.h"
#include <stdexcept>
#include <allegro5/allegro5.h>

using std::runtime_error;

SoundThread::SoundThread() : thread(nullptr) {
    if (!(thread = al_create_thread(threadFunction, static_cast<void*>(this)))) {
        throw new runtime_error("Failed to create sound thread.");
    }

    al_start_thread(thread);
}

SoundThread::~SoundThread() {
    al_destroy_thread(thread);
}

void* SoundThread::threadFunction(ALLEGRO_THREAD* thread, void* instance) {
    //SoundThread* self = static_cast<SoundThread*>(instance);

    while (!al_get_thread_should_stop(thread)) { // as long as al_join_thread is not called
        // TODO
    }

    return nullptr;
}
