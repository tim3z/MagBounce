
#ifndef STATE_H
#define STATE_H

#include <string>
#include "Graphics/StateRenderer.h"

class App;
class EventHandler;

/**
  * interface State
  * 
  */

class AppState {
private:
	AppState(const AppState&);
	const AppState& operator=(const AppState&);

protected:
    App* app;
    StateRenderer* stateRenderer;
    EventHandler* eventHandler;
    
public:
    
    AppState ();
    AppState (App* app, StateRenderer* stateRenderer, EventHandler* eventHandler);
    
    virtual void execute() = 0;
    
    virtual ~AppState();
};

#endif // STATE_H
