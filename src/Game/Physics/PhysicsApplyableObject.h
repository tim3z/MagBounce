
#ifndef PHYSICSAPPLYABLEOBJECT_H
#define PHYSICSAPPLYABLEOBJECT_H

#include "Physics/Vector2D.h"

/**
  * interface PhysicsApplyableObject
  * 
  */

class PhysicsApplyableObject {
private:
    
    Vector2D speed;
    
public:
    
    PhysicsApplyableObject();
    
    virtual ~PhysicsApplyableObject();
    
    /**
     * Return the momentum of this object
     * @return an Vector2D containing the movement
     */
    Vector2D getSpeed() const {
        return speed;
    }
    // why const at the end?? -> http://duramecho.com/ComputerInformation/WhyHowCppConst.html
    
    /**
     * Return the position of this Object
     * @return an Vector2D containing the position
     */
    virtual Vector2D getPosition() const = 0;
    
    /**
     * Set the current speed for this object
     * @param speed a vector represanting the speed
     */
    void setSpeed(const Vector2D &speed) {
        this->speed = speed;
    }
    
    /**
     * Set the current position of this object
     * @param position an Vector2D containing the position
     */
    virtual void setPosition(const Vector2D &position) = 0;
    
    /**
     * Return the Collision Radius for this object
     * @return the collision radius
     */
    virtual int getCollisionRadius() const = 0;
    
    virtual int getMagneticState() const = 0;
    virtual void setMagneticState(int magneticState) = 0;
    
};

#endif // PHYSICSAPPLYABLEOBJECT_H
