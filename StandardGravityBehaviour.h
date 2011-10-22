
#ifndef STANDARDGRAVITYBEHAVIOUR_H
#define STANDARDGRAVITYBEHAVIOUR_H
#include "ForceBehaviour.h"

#include <string>

/**
  * class StandardGravityBehaviour
  * 
  */

class StandardGravityBehaviour : virtual public ForceBehaviour {
public:
    
    /**
     * Empty Constructor
     */
    StandardGravityBehaviour ();

    /**
     * Empty Destructor
     */
    virtual ~StandardGravityBehaviour ();
};

#endif // STANDARDGRAVITYBEHAVIOUR_H
