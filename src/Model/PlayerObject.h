
#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "LevelObject.h"
#include "../Physics/PhysicsApplyableObject.h"
#include "../Graphics/BallRenderer.h"

/**
  * class PlayerObject
  * 
  */

class PlayerObject : public virtual PhysicsApplyableObject, public LevelObject  {
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
        return LevelObject::getPosition();
    }
    
    void setPosition(const Vector2D &position) {
        LevelObject::setPosition(position);
    }
    void setPosition(float x, float y) {
        LevelObject::setPosition(x, y);
    }
    
    void setMagneticState(int magneticState) {
        LevelObject::setMagneticState(magneticState);
    }
    
    int getMagneticState() const {
        return LevelObject::getMagneticState();
    }
    
    Vector2D getRenderingPosition() const;
    
};

#endif // PLAYEROBJECT_H
