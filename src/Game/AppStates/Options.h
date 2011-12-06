#ifndef OPTIONS_H
#define OPTIONS_H
#include "AppState.h"

/**
 * class Options
 * 
 */
class Options : public AppState {
public:
    Options(App*);
    virtual ~Options();

    void processInput(list<InputEvent*> events);
    void update(int dt);
    void render();
};

#endif // OPTIONS_H
