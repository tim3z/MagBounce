
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
    
    Pause (Game*);
    
    void reactOnInput();

    /**
     * Empty Destructor
     */
    virtual ~Pause ();

};

#endif // PAUSE_H
