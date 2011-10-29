
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <string>
#include "../Vector2D.h"
#include "../../Model/Level.h"
#include "Collision.h"

/**
  * class CollisionHandler
  * 
  */

class CollisionHandler {
public:

    /**
    * Empty Constructor
    */
    CollisionHandler ();

    /**
    * Empty Destructor
    */
    virtual ~CollisionHandler (); 


    /**
     * Checks the given object assuming the given move for collisions with the given objects
     * 
     * @param object the moving object
     * @param move a vector containing the assumed move
     * @param objects the surrounding objects
     * @return an pointer to an collision object containing all information about the collision
     */
    static Collision* checkForCollision (const PhysicsApplyableObject &object, const Vector2D &move, const std::vector<LevelObject*> &objects);
};

#endif // COLLISIONHANDLER_H
