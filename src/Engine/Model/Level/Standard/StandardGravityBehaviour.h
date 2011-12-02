#ifndef STANDARDGRAVITYBEHAVIOUR_H
#define STANDARDGRAVITYBEHAVIOUR_H

#include "../GravityBehaviour.h"

/**
 * class StandardGravityBehaviour
 * 
 */

class StandardGravityBehaviour : public GravityBehaviour {
public:

    /**
     * Empty Constructor
     */
    StandardGravityBehaviour();

    /**
     * Empty Destructor
     */
    virtual ~StandardGravityBehaviour();

    Vector2D getAccelerationAt();
};

#endif // STANDARDGRAVITYBEHAVIOUR_H
