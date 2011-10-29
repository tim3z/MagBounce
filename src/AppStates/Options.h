
#ifndef OPTIONS_H
#define OPTIONS_H
#include "AppState.h"

#include <string>

/**
  * class Options
  * 
  */

class Options : virtual public AppState {
public:
    
    /**
     * Empty Constructor
     */
    Options ();

    void execute();
    
    /**
     * Empty Destructor
     */
    virtual ~Options ();
  
};

#endif // OPTIONS_H
