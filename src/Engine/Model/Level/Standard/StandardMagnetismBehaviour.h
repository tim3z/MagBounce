#ifndef STANDARDMAGNETISMBEHAVIOUR_H
#define STANDARDMAGNETISMBEHAVIOUR_H
#include "../MagnetismBehaviour.h"

/**
 * class StandardMagnetismBehaviour
 * 
 */

class StandardMagnetismBehaviour : public MagnetismBehaviour {

public:

    /**
     * Empty Constructor
     */
    StandardMagnetismBehaviour();

    /**
     * Empty Destructor
     */
    virtual ~StandardMagnetismBehaviour();

    Vector2D getAccelerationAt(const Vector2D &position, const std::vector<Object*> &objects);
};

#endif // STANDARDMAGNETISMBEHAVIOUR_H
