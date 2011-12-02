/* 
 * File:   MagnetismBehaviour.h
 * Author: eagle
 *
 * Created on 29. Oktober 2011, 21:00
 */

#ifndef MAGNETISMBEHAVIOUR_H
#define	MAGNETISMBEHAVIOUR_H

#include "Physics/Vector2D.h"
#include "Model/Object.h"
#include <vector>

class MagnetismBehaviour {
public:

	virtual ~MagnetismBehaviour();

	/**
	 * Calculate the acceleration represanted as an Vector for this force at the given position
	 * @param position a Vector2D represanting the position
	 * @param objects a vector containing all levelobjects to consider
	 * @return the calculated acceleration
	 */
	virtual Vector2D getAccelerationAt(const Vector2D &position, const std::vector<Object*> &objects) = 0;

};

#endif	/* MAGNETISMBEHAVIOUR_H */

