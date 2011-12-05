/* 
 * File:   GravityBehavior.h
 * Author: eagle
 *
 * Created on 29. Oktober 2011, 20:55
 */

#ifndef GRAVITYBEHAVIOR_H
#define	GRAVITYBEHAVIOR_H

#include "Physics/Vector.h"

class GravityBehavior {
public:

    virtual ~GravityBehavior();

    /**
     * Calculate the acceleration represanted as an Vector
     * @return the calculated acceleration
     */
    virtual Vector2D getAccelerationAt() = 0;

};

#endif	/* GRAVITYBEHAVIOR_H */

