#ifndef PHYSICS_H
#define PHYSICS_H

#include "Math/Vector.h"
#include "PhysicsAppliableObject.h"

class Level;
class PhysicsAppliableObject;

using namespace r2d;

/**
 * class Physics
 * 
 */

class Physics {
private:

    Level* currentLevel;

    Physics(const Physics&);
    const Physics& operator=(const Physics&);

public:

    Physics(Level* level);

    virtual ~Physics();

    /**
     * Calculate and execute movements for the current level and the passed time
     * @param time the time in ms for this frame
     */
    void move(double time);

private:

    /**
     * Calculates for the given Object and the given Time a moving Vector
     * @param Object the Object which might move
     * @param the duration of the move
     * @return Vector2D the calculated move
     */
    Vector2D calculateMoveFor(const PhysicsAppliableObject &object, double time);
    
    Vector2D getAccelerationFor(const PhysicsAppliableObject &object);

};

#endif // PHYSICS_H
