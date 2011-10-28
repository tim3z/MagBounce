
#ifndef STATE_H
#define STATE_H

#include <string>
#include "Graphics/StateRenderer.h"

/**
  * interface State
  * 
  */

/******************************* Abstract Class ****************************
State does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class State {
protected:
    StateRenderer* stateRenderer;
    
public:
	virtual ~State();
};

#endif // STATE_H
