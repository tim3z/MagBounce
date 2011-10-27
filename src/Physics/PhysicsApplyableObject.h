
#ifndef PHYSICSAPPLYABLEOBJECT_H
#define PHYSICSAPPLYABLEOBJECT_H

#include <string>
#include "Vector2D.h"

/**
  * interface PhysicsApplyableObject
  * 
  */

class PhysicsApplyableObject {
    
public:
    
    /**
     * Return the momentum of this object
     * @return an Vector2D containing the movement
     */
    virtual Vector2D getSpeed() const = 0;
    // why const at the end?? -> http://duramecho.com/ComputerInformation/WhyHowCppConst.html
    
    /**
     * Return the position of this Object
     * @return an Vector2D containing the position
     */
    virtual Vector2D getPosition() const = 0;
    
};

#endif // PHYSICSAPPLYABLEOBJECT_H
