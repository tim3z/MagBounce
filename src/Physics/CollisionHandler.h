
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <string>
#include "Vector2D.h"
#include "../Model/Level.h"

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
    * @return Vector2D
    * @param  object
    * @param  move
    */
    Vector2D checkForCollision (LevelObject object, Vector2D move);
};

#endif // COLLISIONHANDLER_H
