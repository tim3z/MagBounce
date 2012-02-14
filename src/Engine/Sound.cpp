/*
 * Sound.cpp
 *
 *  Created on: 10.02.2012
 *      Author: moritz
 */

#include "Sound.h"
#include <stdexcept>
#include <allegro5/allegro5.h>

SoundThread::SoundThread() : MainThread() {

}

SoundThread::~SoundThread() {
    this->stop();

}

void SoundThread::main() {
    // TODO
}
