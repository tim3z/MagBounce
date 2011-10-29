
#ifndef STATE_H
#define STATE_H

#include <string>
#include "../Graphics/StateRenderer.h"

class App;

/**
  * interface State
  * 
  */

class AppState {
protected:
    StateRenderer* stateRenderer;
    App* app;
    
public:
    
    AppState ();
    AppState (App* app, StateRenderer* stateRenderer);
    
    virtual void execute() = 0;
    
    virtual ~AppState();
};

#endif // STATE_H
