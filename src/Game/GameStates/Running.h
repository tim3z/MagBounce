
#ifndef RUNNING_H
#define RUNNING_H
#include "GameState.h"

#include <string>

/**
  * class Running
  * 
  */

class EventHandler;

class Running : virtual public GameState {
    
public:

    /**
     * Empty Constructor
     */
    Running ();
    
    Running (Game*, EventHandler* eventHandler);

    void reactOnInput();
    
    /**
     * Empty Destructor
     */
    virtual ~Running ();

};

#endif // RUNNING_H
