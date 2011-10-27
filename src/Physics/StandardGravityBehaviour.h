
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

    void getAccelerationAt(Vector2D &position, Vector2D* acceleration);
};

#endif // STANDARDGRAVITYBEHAVIOUR_H
