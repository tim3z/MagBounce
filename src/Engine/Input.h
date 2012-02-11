/*
 * Input.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef INPUTTHREAD_H_
#define INPUTTHREAD_H_

struct ALLEGRO_THREAD;

class InputThread {
public:
    InputThread();
    virtual ~InputThread();

private:
    ALLEGRO_THREAD* thread;

    /*
     * Member function pointers cannot be used like C function pointers, so these functions must be static.
     * In case the instance has to be accessed, it is passed as an argument.
     */
    static void* threadFunction(ALLEGRO_THREAD* thread, void* instance);

    /* uncopyable */
    InputThread(const InputThread&);
    const InputThread& operator=(const InputThread&);
};

#endif /* INPUTTHREAD_H_ */
