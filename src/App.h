
#ifndef APP_H
#define APP_H

#include <string>
#include "Graphics/Graphics.h"
#include "State.h"

/**
  * class App
  * 
  */

class App {
    
private:
    Graphics *graphics;
    State *currentState;
    
public:
    
    /**
     * Empty Constructor
     */
    App ();

    /**
     * Empty Destructor
     */
    virtual ~App ();
    
};

#endif // APP_H
