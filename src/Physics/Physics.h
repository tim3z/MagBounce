
#ifndef PHYSICS_H
#define PHYSICS_H

#include <string>
#include "Vector2D.h"
#include "PhysicsApplyableObject.h"
#include "../Model/Level.h"

/**
  * class Physics
  * 
  */

class Physics {
private:
    
    Level* currentLevel;
    
public:

    /**
     * Calculates for the given Object and the given Time a moving Vector
     * @param Object the Object which might move
     * @param the duration of the move
     * @return Vector2D the calculated move
     */
    Vector2D calculateMoveFor (PhysicsApplyableObject &Object, int time);

    virtual ~Physics();
};

#endif // PHYSICS_H
