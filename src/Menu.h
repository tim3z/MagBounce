
#ifndef MENU_H
#define MENU_H
#include "State.h"

#include <string>

/**
  * class Menu
  * 
  */

class Menu : virtual public State {
public:

    /**
     * Empty Constructor
     */
    Menu ();

    /**
     * Empty Destructor
     */
    virtual ~Menu ();
    
};

#endif // MENU_H
