
#ifndef APP_H
#define APP_H

#include <string>
#include "Graphics/Graphics.h"

class State;

/**
  * class App
  * 
  */

class App {
    class State;
    
private:
    Graphics *graphics;
    State *currentState;
    
    App(const App&);
    const App& operator=(const App&);

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
