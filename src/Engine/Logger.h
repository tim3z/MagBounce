/*
 * Logger.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef LOGGER_H_
#define LOGGER_H_

struct ALLEGRO_THREAD;

class Logger {
public:
    Logger();
    virtual ~Logger();

private:
    ALLEGRO_THREAD* thread;

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
