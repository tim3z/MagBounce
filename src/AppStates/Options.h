
#ifndef OPTIONS_H
#define OPTIONS_H
#include "AppState.h"

#include <string>

/**
  * class Options
  * 
  */

class EventHandler;

class Options : virtual public AppState {
public:
    
    /**
     * Empty Constructor
     */
    Options ();
    
    Options (App*, StateRenderer*, EventHandler* eventHandler);//TODO OptionsStateRenderer

    void execute();
    
    /**
     * Empty Destructor
     */
    virtual ~Options ();
  
};

#endif // OPTIONS_H
