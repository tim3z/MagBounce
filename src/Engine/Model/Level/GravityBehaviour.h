/* 
 * File:   GravityBehaviour.h
 * Author: eagle
 *
 * Created on 29. Oktober 2011, 20:55
 */

#ifndef GRAVITYBEHAVIOUR_H
#define	GRAVITYBEHAVIOUR_H

#include "Physics/Vector.h"

class GravityBehaviour {
public:

    virtual ~GravityBehaviour();

    /**
     * Calculate the acceleration represanted as an Vector
     * @return the calculated acceleration
     */
    virtual Vector2D getAccelerationAt() = 0;

};

#endif	/* GRAVITYBEHAVIOUR_H */

