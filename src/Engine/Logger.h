/*
 * Logger.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <queue>
#include <string>

struct ALLEGRO_COND;
struct ALLEGRO_MUTEX;
struct ALLEGRO_THREAD;

using std::queue;
using std::string;

enum class LogPriority {
    PROFILING,
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    Logger();
    virtual ~Logger();

    void log(LogPriority priority, string&& text);

private:
    struct Message {
        LogPriority priority;
        string text;
    };

    ALLEGRO_COND* queueFull;
    ALLEGRO_MUTEX* queueMutex;
    ALLEGRO_THREAD* thread;
    queue<Message> messageQueue;

    /*
     * Member function pointers cannot be used like C function pointers, so these functions must be static.
     * In case the instance has to be accessed, it is passed as an argument.
     */
    static void* threadFunction(ALLEGRO_THREAD* thread, void* instance);

    /* uncopyable */
    Logger(const Logger&);
    const Logger& operator=(const Logger&);
};

#endif /* LOGGER_H_ */
