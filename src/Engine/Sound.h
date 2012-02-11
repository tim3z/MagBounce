/*
 * Sound.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef SOUNDTHREAD_H_
#define SOUNDTHREAD_H_

struct ALLEGRO_THREAD;

class SoundThread {
public:
    SoundThread();
    virtual ~SoundThread();

private:
    ALLEGRO_THREAD* thread;

    /*
     * Member function pointers cannot be used like C function pointers, so these functions must be static.
     * In case the instance has to be accessed, it is passed as an argument.
     */
    static void* threadFunction(ALLEGRO_THREAD* thread, void* instance);

    /* uncopyable */
    SoundThread(const SoundThread&);
    const SoundThread& operator=(const SoundThread&);
};

#endif /* SOUNDTHREAD_H_ */
