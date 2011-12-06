#ifndef APPSTATE_H
#define APPSTATE_H

#include <list>

using std::list;
class Display;
class InputEvent;

/**
 * interface State
 * 
 */
class AppState {
public:
    AppState();
    virtual ~AppState();

    virtual void processInput(list<InputEvent *> events) = 0;
    virtual void update(int dt) = 0;
    virtual void render(Display& display) = 0;

private:
    AppState(const AppState&);
    const AppState& operator=(const AppState&);
};

#endif // APPSTATE_H
