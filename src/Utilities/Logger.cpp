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

Logger::Logger()
        : MainThread(), queueFull(nullptr), queueMutex(nullptr), messageQueue() {
    if (!(queueFull = al_create_cond())) {
        throw std::runtime_error("Failed to create condition variable.");
    }

    if (!(queueMutex = al_create_mutex())) {
        al_destroy_cond(queueFull);
        throw std::runtime_error("Failed to create mutex.");
    }

    this->start();
}

Logger::~Logger() {
    this->stop(); // make sure the thread stops before mutex and cond are destroyed
    al_destroy_mutex(queueMutex);
    al_destroy_cond(queueFull);
    // flush queue
    while (!messageQueue.empty())
        processMessage();
}

void Logger::log(Priority priority, string&& text) {
    al_lock_mutex(queueMutex);
    // every rvalue reference is a lvalue itself, that's why the move() is necessary
    // (see http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html)
    messageQueue.push({priority, move(text)});
    al_unlock_mutex(queueMutex);
    al_signal_cond(queueFull);
}

void Logger::processMessage() {
    const Message& nextMessage = messageQueue.front();

    // TODO: only log to stdout if DEBUG flag is set, support logging errors to file in production environment
    //       log errors to different locations and stream depending on type, log asynchronously, etc.
    if (nextMessage.priority >= Priority::WARNING)
        clog << nextMessage.text << endl;
    else
        cout << nextMessage.text << endl;

    messageQueue.pop();
}

void Logger::main() {
    al_lock_mutex(queueMutex);
    while (messageQueue.empty())
        al_wait_cond(queueFull, queueMutex);

    processMessage();

    al_unlock_mutex(queueMutex);
}
