
#ifndef PAUSE_H
#define PAUSE_H
#include "GameState.h"

#include <string>

/**
  * class Pause
  * 
  */

class Pause : virtual public GameState {
public:
    
    /**
     * Empty Constructor
     */
    Pause ();

    /**
     * Empty Destructor
     */
    virtual ~Pause ();

};

#endif // PAUSE_H
