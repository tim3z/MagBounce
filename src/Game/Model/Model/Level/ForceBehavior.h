#ifndef FORCEBEHAVIOR_H
#define FORCEBEHAVIOR_H

#include "Physics/Vector.h"

/**
 * interface ForceBehavior
 * 
 */

class ForceBehavior {
public:

    virtual ~ForceBehavior();

    /**
     * Calculate the acceleration represanted as an Vector for this force at the given position
     * @param position a Vector2D represanting the position
     * @return the calculated acceleration
     */
    virtual Vector2D getAccelerationAt(const Vector2D &position) = 0;
};

#endif // FORCEBEHAVIOR_H
