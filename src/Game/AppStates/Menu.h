#ifndef MENU_H
#define MENU_H
#include "AppState.h"

/**
 * class Menu
 * 
 */

class Menu : public AppState {
public:

    /**
     * Empty Constructor
     */
    Menu();

    Menu(App*, EventHandler* eventHandler);

    void execute();

    /**
     * Empty Destructor
     */
    virtual ~Menu();

};

#endif // MENU_H
