#ifndef APPSTATE_H
#define APPSTATE_H

class App;
class EventHandler;
class StateRenderer;

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

    AppState();
    AppState(App* app, StateRenderer* stateRenderer, EventHandler* eventHandler);

    virtual void execute() = 0;

    virtual ~AppState();
};

#endif // APPSTATE_H
