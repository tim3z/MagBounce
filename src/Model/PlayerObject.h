
#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "LevelObject.h"
#include "../Physics/PhysicsApplyableObject.h"
#include <string>

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
    
    float getCollisionRadius() const;
    
    Vector2D getPosition() const {
        return LevelObject::getPosition();
    }
    
    void setPosition(const Vector2D &position) {
        LevelObject::setPosition(position);
    }
    
};

#endif // PLAYEROBJECT_H
