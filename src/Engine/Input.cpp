/*
 * Input.cpp
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#include "Input.h"
#include <stdexcept>
#include <allegro5/allegro5.h>

using std::runtime_error;

InputThread::InputThread() : MainThread() {

}

InputThread::~InputThread() {
    this->stop();

}

void InputThread::main() {
    // TODO
}
