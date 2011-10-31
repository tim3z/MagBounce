
#ifndef MENU_H
#define MENU_H
#include "AppState.h"

#include <string>

/**
  * class Menu
  * 
  */

class EventHandler;

class Menu : virtual public AppState {
public:

    /**
     * Empty Constructor
     */
    Menu ();
    
    Menu (App*, StateRenderer*, EventHandler* eventHandler); //TODO MenuStateRenderer
    
    void execute();

    /**
     * Empty Destructor
     */
    virtual ~Menu ();
    
};

#endif // MENU_H
