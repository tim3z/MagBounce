
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

    Vector2D getAccelerationAt(const Vector2D &position);
};

#endif // STANDARDGRAVITYBEHAVIOUR_H
