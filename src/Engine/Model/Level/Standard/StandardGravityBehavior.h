#ifndef STANDARDGRAVITYBEHAVIOR_H
#define STANDARDGRAVITYBEHAVIOR_H

#include "../GravityBehavior.h"

/**
 * class StandardGravityBehavior
 * 
 */

class StandardGravityBehavior : public GravityBehavior {
public:

    /**
     * Empty Constructor
     */
    StandardGravityBehavior();

    /**
     * Empty Destructor
     */
    virtual ~StandardGravityBehavior();

    Vector2D getAccelerationAt();
};

#endif // STANDARDGRAVITYBEHAVIOR_H
