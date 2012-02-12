/*
 * Logger.cpp
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#include "Logger.h"
#include <iostream>
#include <stdexcept>
#include <allegro5/allegro5.h>

using std::clog;
using std::cout;
using std::endl;
using std::move;
using std::runtime_error;

Logger::Logger()
        : queueFull(nullptr), queueMutex(nullptr), thread(nullptr), messageQueue() {
    if (!(queueFull = al_create_cond())) {
        throw runtime_error("Failed to create condition variable.");
    }

    if (!(queueMutex = al_create_mutex())) {
        al_destroy_cond(queueFull);
        throw runtime_error("Failed to create condition variable.");
    }

    if (!(thread = al_create_thread(threadFunction, static_cast<void*>(this)))) {
        al_destroy_cond(queueFull);
        al_destroy_mutex(queueMutex);
        throw runtime_error("Failed to create logging thread.");
    }

    al_start_thread(thread);
}

Logger::~Logger() {
    al_destroy_thread(thread);
    al_destroy_mutex(queueMutex);
    al_destroy_cond(queueFull);
    // flush queue
    while (!messageQueue.empty()) {
        const Message& nextMessage = messageQueue.front();
        
        // TODO: see threadFunction
        if (nextMessage.priority >= LogPriority::WARNING)
            clog << nextMessage.text << endl;
        else
            cout << nextMessage.text << endl;

        messageQueue.pop;
    }
}

void Logger::log(LogPriority priority, string&& text) {
    al_lock_mutex(queueMutex);
    // every rvalue reference is a lvalue itself, that's why the move() is necessary
    // (see http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html)
    messageQueue.push({priority, move(text)});
    al_unlock_mutex(queueMutex);
    al_signal_cond(queueFull);
}

void* Logger::threadFunction(ALLEGRO_THREAD* thread, void* instance) {
    Logger* self = static_cast<Logger*>(instance);

    while (!al_get_thread_should_stop(thread)) { // as long as al_join_thread is not called
        al_lock_mutex(self->queueMutex);
        while (self->messageQueue.empty())
            al_wait_cond(self->queueFull, self->queueMutex);
        const Message& nextMessage = self->messageQueue.front();

        // TODO: only log to stdout if DEBUG flag is set, support logging errors to file in production environment
        //       log errors to different locations and stream depending on type, log asynchronously, etc.
        if (nextMessage.priority >= LogPriority::WARNING)
            clog << nextMessage.text << endl;
        else
            cout << nextMessage.text << endl;

        self->messageQueue.pop();
        al_unlock_mutex(self->queueMutex);
    }

    return nullptr;
}
