#ifndef APPSTATE_H
#define APPSTATE_H

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
    EventHandler* eventHandler;

public:

    AppState();
    AppState(App* app, EventHandler* eventHandler);

    virtual void execute() = 0;

    virtual ~AppState();
};

#endif // APPSTATE_H
