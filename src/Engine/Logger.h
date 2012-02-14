/*
 * Logger.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "MainThread.h"
#include <queue>
#include <string>

using std::queue;
using std::string;

// Hide the fact that the Logger has an own thread. The thread auto-starts on creation.
class Logger : private MainThread {
public:
    Logger();
    Logger(const Logger&) = delete;
    const Logger& operator=(const Logger&) = delete;
    virtual ~Logger();

    enum class Priority : int8_t {
        VERBOSE,
        PROFILING,
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    void log(Priority priority, string&& text);

private:
    struct Message {
        Priority priority;
        string text;
    };

    ALLEGRO_COND* queueFull;
    ALLEGRO_MUTEX* queueMutex;
    queue<Message> messageQueue;

    void processMessage();
    void main();
};

#endif /* LOGGER_H_ */
