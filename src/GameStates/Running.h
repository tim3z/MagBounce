
#ifndef RUNNING_H
#define RUNNING_H
#include "GameState.h"

#include <string>

/**
  * class Running
  * 
  */

class Running : virtual public GameState {
    
public:

    /**
     * Empty Constructor
     */
    Running ();

    void reactOnInput();
    
    /**
     * Empty Destructor
     */
    virtual ~Running ();

};

#endif // RUNNING_H
