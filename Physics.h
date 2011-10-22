
#ifndef PHYSICS_H
#define PHYSICS_H

#include <string>
#include "Vector2D.h"
#include "PhysicsApplyableObject.h"

/**
  * interface Physics
  * 
  */

/******************************* Abstract Class ****************************
Physics does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Physics {
public:

    /**
    * @return Vector2D
    * @param  Object
    */
    virtual Vector2D calculateMoveFor (PhysicsApplyableObject Object) = 0;


};

#endif // PHYSICS_H
