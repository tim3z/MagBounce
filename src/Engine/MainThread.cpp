/*
 * MainThread.cpp
 *
 *  Created on: 13.02.2012
 *      Author: moritz
 */

#include "MainThread.h"
#include <stdexcept>
#include <allegro5/allegro.h>

MainThread::MainThread() : thread(nullptr), threadCtrlMutex(nullptr), threadRestarted(nullptr), paused(false) {
    if (!(thread = al_create_thread(threadFunction, static_cast<void*>(this)))) {
        throw std::runtime_error("Failed to create new thread.");
    }

    if (!(threadCtrlMutex = al_create_mutex())) {
        al_destroy_thread(thread);
        throw std::runtime_error("Failed to create mutex.");
    }

    if (!(threadRestarted = al_create_cond())) {
        al_destroy_thread(thread);
        al_destroy_mutex(threadCtrlMutex);
        throw std::runtime_error("Failed to create condition variable.");
    }

    // The thread MUST NOT be started in the constructor, since subclasses have not been fully initialized yet.
}

MainThread::~MainThread() {
    al_destroy_thread(thread);
    al_destroy_cond(threadRestarted);
    al_destroy_mutex(threadCtrlMutex);
}


void MainThread::start() {
    al_start_thread(thread);
}

void MainThread::pause() { // TODO: is there a way to do this without using locks?
    al_lock_mutex(threadCtrlMutex);
    paused = true;
    al_unlock_mutex(threadCtrlMutex);
}

void MainThread::resume() {
    al_lock_mutex(threadCtrlMutex);
    paused = false;
    al_signal_cond(threadRestarted);
    al_unlock_mutex(threadCtrlMutex);
}

void MainThread::stop() {
    al_join_thread(thread, nullptr);
}


void* MainThread::threadFunction(ALLEGRO_THREAD* thread, void* instance) {
    auto self = static_cast<MainThread* const>(instance);

    self->init();

    while (!al_get_thread_should_stop(thread)) {
        al_lock_mutex(self->threadCtrlMutex);
        while (self->paused)
            al_wait_cond(self->threadRestarted, self->threadCtrlMutex);
        al_unlock_mutex(self->threadCtrlMutex);

        self->main();
    }

    self->cleanup();

    return nullptr;
}
