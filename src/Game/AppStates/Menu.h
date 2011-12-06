#ifndef MENU_H
#define MENU_H
#include "AppState.h"

/**
 * class Menu
 * 
 */
class Menu : public AppState {
public:
    Menu();
    virtual ~Menu();

    void processInput(list<InputEvent*> events);
    void update(int dt);
    void render(Display& display);
};

#endif // MENU_H
