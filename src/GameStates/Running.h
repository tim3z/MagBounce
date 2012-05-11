#ifndef RUNNING_H
#define RUNNING_H
#include "GameState.h"

/**
 * class Running
 * 
 */

class Running : public GameState {

public:
    Running(Game*);
    virtual ~Running();

    void reactOnInput();
};

#endif // RUNNING_H
