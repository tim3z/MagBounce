/*
 * Sound.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef SOUNDTHREAD_H_
#define SOUNDTHREAD_H_

#include "MainThread.h"

class SoundThread : public MainThread {
public:
    SoundThread();
    virtual ~SoundThread();

private:
    void main();
};

#endif /* SOUNDTHREAD_H_ */
