
#ifndef PHYSICS_H
#define PHYSICS_H

#include <boost/numeric/ublas/vector_expression.hpp>
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
    
    Physics(Level* level);

    virtual ~Physics();
    
    /**
     * Calculate and execute movements for the current level and the passed time
     * @param time the time in ms for this frame
     */
    void move(int time);
    
private:
    
    /**
     * Calculates for the given Object and the given Time a moving Vector
     * @param Object the Object which might move
     * @param the duration of the move
     * @return Vector2D the calculated move
     */
    Vector2D calculateMoveFor (const PhysicsApplyableObject &Object, int time);
    
    
};

#endif // PHYSICS_H
