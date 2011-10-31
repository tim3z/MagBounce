/* 
 * File:   InputHandler.h
 * Author: jonathan
 *
 * Created on 31. Oktober 2011, 14:07
 */

#ifndef INPUTHANDLER_H
#define	INPUTHANDLER_H

#include "EventHandler.h"

class InputHandler {
public:
    InputHandler();
    InputHandler(EventHandler* eventHandler);
    virtual bool* getInput() = 0;
    InputHandler(const InputHandler& orig);
    virtual ~InputHandler();
protected:
    bool* keys;
    EventHandler* eventHandler;
};

#endif	/* INPUTHANDLER_H */

