#ifndef APPSTATE_H
#define APPSTATE_H

#include <list>
#include "Graphics/Display.h"

using std::list;
using namespace r2d;
class InputEvent;

/**
 * interface State
 * 
 */
class AppState {
public:
    AppState();
    virtual ~AppState();

    /**
     * Subclasses must implement input handling in this method.
     *
     * @param events List of InputEvents which have not yet been processed
     * @return Next application state
     *         (<code>this</code> if the state does not change, <code>nullptr</code> to exit the application)
     */
    virtual AppState* processInput(list<InputEvent *> events) = 0;
    virtual void update(double dt) = 0;
    virtual void render(Display& display) const = 0;

private:
    AppState(const AppState&);
    const AppState& operator=(const AppState&);
};

#endif // APPSTATE_H