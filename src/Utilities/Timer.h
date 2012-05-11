/*
 * Timer.h
 *
 *  Created on: 14.02.2012
 *      Author: moritz
 */

#ifndef TIMER_H_
#define TIMER_H_

struct ALLEGRO_EVENT_QUEUE;
struct ALLEGRO_TIMER;

/**
 * A timer producing ticks at a given interval.
 *
 * This class wraps the corresponding functions of Allegro5.
 */
class Timer {
public:
    /**
     * Creates a timer which produces ticks at a given interval.
     *
     * The granularity is at least in the order of milliseconds, sometimes even microseconds (see al_create_timer()).
     *
     * @param interval Seconds between two "ticks"
     * @throw std::runtime_error if a fatal error occurs during initialization
     */
    Timer(double interval);
    Timer(const Timer&) = delete;
    const Timer& operator=(const Timer&) = delete;
    virtual ~Timer();

    /**
     * Starts the timer.
     */
    void start();

    /**
     * Stops the timer and flushes the tick queue.
     */
    void stop();

    /**
     * Consume exactly one timer tick.
     *
     * If no tick has occurred since the last call to start() or consumeTick(), this function waits for the next tick.
     */
    void consumeTick();

    /**
     * Consume all accumulated timer ticks.
     *
     * If no tick has occurred since the last call to start() or consumeTick(), this function waits for the next tick.
     */
    void consumeTicks();

private:
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* timerEventQueue;
};

#endif /* TIMER_H_ */
