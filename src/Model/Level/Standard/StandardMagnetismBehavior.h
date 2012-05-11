#ifndef STANDARDMAGNETISMBEHAVIOR_H
#define STANDARDMAGNETISMBEHAVIOR_H
#include "../MagnetismBehavior.h"

using namespace r2d;

/**
 * class StandardMagnetismBehavior
 * 
 */

class StandardMagnetismBehavior : public MagnetismBehavior {

public:

    /**
     * Empty Constructor
     */
    StandardMagnetismBehavior();

    /**
     * Empty Destructor
     */
    virtual ~StandardMagnetismBehavior();

    Vector2D getAccelerationAt(const Vector2D &position, const std::vector<Object*> &objects);
};

#endif // STANDARDMAGNETISMBEHAVIOR_H
