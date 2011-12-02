#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "Model/Object.h"
#include "Physics/PhysicsApplyableObject.h"

/**
  * class PlayerObject
  * 
  */

class PlayerObject : public virtual PhysicsApplyableObject, public Object  {
public:
    
    /**
     * Empty Constructor
     */
    PlayerObject ();

    /**
     * Empty Destructor
     */
    virtual ~PlayerObject ();
    
    int getCollisionRadius() const;
    
    Vector2D getPosition() const {
        return Object::getPosition();
    }
    
    void setPosition(const Vector2D &position) {
        Object::setPosition(position);
    }
    void setPosition(float x, float y) {
        Object::setPosition(x, y);
    }
    
    void setMagneticState(int magneticState) {
        Object::setMagneticState(magneticState);
    }
    
    int getMagneticState() const {
        return Object::getMagneticState();
    }
    
    Vector2D getRenderingPosition() const;
    
};

#endif // PLAYEROBJECT_H
