
#ifndef INGAME_H
#define INGAME_H
#include "State.h"

#include <string>

/**
  * class InGame
  * 
  */

class InGame : virtual public State {
public:
    
    /**
     * Empty Constructor
     */
    InGame ();

    /**
     * Empty Destructor
     */
    virtual ~InGame ();

};

#endif // INGAME_H
