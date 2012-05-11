/* 
 * File:   MagnetismBehavior.h
 * Author: eagle
 *
 * Created on 29. Oktober 2011, 21:00
 */

#ifndef MAGNETISMBEHAVIOR_H
#define	MAGNETISMBEHAVIOR_H

#include <vector>
#include "Math/Vector.h"

using std::vector;
using namespace r2d;

class Object;

class MagnetismBehavior {
public:

    virtual ~MagnetismBehavior() {};

    /**
     * Calculate the acceleration represanted as an Vector for this force at the given position
     * @param position a Vector2D represanting the position
     * @param objects a vector containing all levelobjects to consider
     * @return the calculated acceleration
     */
    virtual Vector2D getAccelerationAt(const Vector2D &position, const std::vector<Object*> &objects) = 0;

};

#endif	/* MAGNETISMBEHAVIOR_H */

