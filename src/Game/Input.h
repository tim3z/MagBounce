/*
 * Input.h
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#ifndef INPUTTHREAD_H_
#define INPUTTHREAD_H_

#include "MainThread.h"

class InputThread : public MainThread {
public:
    InputThread();
    virtual ~InputThread();

private:
    void main();
};

#endif /* INPUTTHREAD_H_ */
