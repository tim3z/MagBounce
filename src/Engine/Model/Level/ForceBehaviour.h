#ifndef FORCEBEHAVIOUR_H
#define FORCEBEHAVIOUR_H

#include "Physics/Vector.h"

/**
 * interface ForceBehaviour
 * 
 */

class ForceBehaviour {
public:

    virtual ~ForceBehaviour();

    /**
     * Calculate the acceleration represanted as an Vector for this force at the given position
     * @param position a Vector2D represanting the position
     * @return the calculated acceleration
     */
    virtual Vector2D getAccelerationAt(const Vector2D &position) = 0;
};

#endif // FORCEBEHAVIOUR_H
