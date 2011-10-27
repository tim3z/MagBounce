
#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "LevelObject.h"
#include "../Physics/PhysicsApplyableObject.h"
#include <string>

/**
  * class PlayerObject
  * 
  */

class PlayerObject : public LevelObject, public PhysicsApplyableObject {
public:
    
    /**
     * Empty Constructor
     */
    PlayerObject ();

    /**
     * Empty Destructor
     */
    virtual ~PlayerObject ();
    
};

#endif // PLAYEROBJECT_H
