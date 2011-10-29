
#ifndef STATE_H
#define STATE_H

#include <string>
#include "Graphics/StateRenderer.h"

class App;

/**
  * interface State
  * 
  */

class State {
protected:
    StateRenderer* stateRenderer;
    App* app;
    
public:
    
    State ();
    State (App* initApp);
    
    virtual ~State();
};

#endif // STATE_H
