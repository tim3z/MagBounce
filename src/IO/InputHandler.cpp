/* 
 * File:   InputHandler.cpp
 * Author: jonathan
 * 
 * Created on 31. Oktober 2011, 14:07
 */

#include "InputHandler.h"

InputHandler::InputHandler() {}

InputHandler::InputHandler(EventHandler* eventHandler) {
    this->eventHandler = eventHandler;
}

InputHandler::InputHandler(const InputHandler& orig) {}

InputHandler::~InputHandler() {
    delete eventHandler;
}

