
#ifndef OPTIONS_H
#define OPTIONS_H
#include "State.h"

#include <string>

/**
  * class Options
  * 
  */

class Options : virtual public State {
public:
    
    /**
     * Empty Constructor
     */
    Options ();

    /**
     * Empty Destructor
     */
    virtual ~Options ();
  
};

#endif // OPTIONS_H
