
#ifndef APP_H
#define APP_H

#include <string>
#include "Graphics/Graphics.h"
#include "AppStates/AppState.h"
#include "AppStates/Game.h"


/**
  * class App
  * 
  */

class App {
    
private:
    Game *game;
    AppState *currentState;
    
    App(const App&);
    const App& operator=(const App&);

public:
    
    /**
     * Empty Constructor
     */
    App ();
    
    void fire();

    /**
     * Empty Destructor
     */
    virtual ~App ();
    
};

#endif // APP_H
