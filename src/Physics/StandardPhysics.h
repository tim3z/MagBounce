
#ifndef STANDARDPHYSICS_H
#define STANDARDPHYSICS_H

#include <string>
#include "PhysicalProperties.h"
#include "StandardGravityBehaviour.h"
#include "StandardMagnetismBehaviour.h"
#include "StandardTimeBehaviour.h"

/**
  * class StandardPhysics
  * 
  */

class StandardPhysics : virtual public PhysicalProperties {
public:
    
    StandardPhysics ();
    virtual ~StandardPhysics ();

};

#endif // STANDARDPHYSICS_H
