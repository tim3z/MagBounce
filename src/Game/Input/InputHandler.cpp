/* 
 * File:   InputHandler.cpp
 * Author: jonathan
 * 
 * Created on 31. Oktober 2011, 14:07
 */

#include "InputHandler.h"
#include "EventHandler.h"

InputHandler::InputHandler(EventHandler* eventHandler)
        : eventHandler(eventHandler), keys(0) {
}

InputHandler::~InputHandler() {
    delete eventHandler;
}

