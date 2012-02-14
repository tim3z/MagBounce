/*
 * Timer.cpp
 *
 *  Created on: 14.02.2012
 *      Author: moritz
 */

#include "Timer.h"
#include <stdexcept>
#include <allegro5/allegro.h>

Timer::Timer(double interval)
        : timer(nullptr), timerEventQueue(nullptr) {
    if (!(timer = al_create_timer(interval))) {
        throw std::runtime_error("Failed to create timer.");
    }

    if (!(timerEventQueue = al_create_event_queue())) {
        al_destroy_timer(timer);
        throw std::runtime_error("Failed to create timer.");
    }

    al_register_event_source(timerEventQueue, al_get_timer_event_source(timer));
}

Timer::~Timer() {
    al_destroy_timer(timer);
    al_destroy_event_queue(timerEventQueue);
}


void Timer::start() {
    al_start_timer(timer);
}

void Timer::stop() {
    al_stop_timer(timer);
    al_flush_event_queue(timerEventQueue);
}

void Timer::consumeTick() {
    al_wait_for_event(timerEventQueue, nullptr);
    al_drop_next_event(timerEventQueue);
}

void Timer::consumeTicks() {
    /* The race condition in the following (new tick could be generated between the function calls) is irrelevant,
     * since the user of this function obviously does not care about losing a single tick anyway. */
    al_wait_for_event(timerEventQueue, nullptr);
    al_flush_event_queue(timerEventQueue);
}
