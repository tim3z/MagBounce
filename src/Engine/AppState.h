#ifndef APPSTATE_H
#define APPSTATE_H

#include <list>

using std::list;
class App;
class EventHandler;
class InputEvent;

/**
 * interface State
 * 
 */
class AppState {
public:
    AppState(App* app);
    virtual ~AppState();

    virtual void processInput(list<InputEvent *> events) = 0;
    virtual void update(int dt) = 0;
    virtual void render() = 0;

protected:
    App* app;

private:
    AppState(const AppState&);
    const AppState& operator=(const AppState&);
};

#endif // APPSTATE_H
