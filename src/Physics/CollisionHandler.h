
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <string>
#include "PhysicsApplyableObject.h"
#include "Vector2D.h"
#include "../Model/Level.h"

/**
  * class CollisionHandler
  * 
  */

class CollisionHandler {
    
private: 

    Level level;
  
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
    * @return Vector2D
    * @param  object
    * @param  move
    */
    Vector2D checkForCollision (PhysicsApplyableObject object, Vector2D move);

    /**
    * Set the value of level
    * @param new_var the new value of level
    */
    void setLevel (Level new_var)   {
        level = new_var;
    }

    /**
    * Get the value of level
    * @return the value of level
    */
    Level getLevel ()   {
        return level;
    }

};

#endif // COLLISIONHANDLER_H
