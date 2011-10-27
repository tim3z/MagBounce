
#ifndef STANDARDPHYSICS_H
#define STANDARDPHYSICS_H

#include <string>
#include "PhysicalPorperties.h"
#include "StandardGravityBehaviour.h"
#include "StandardMagnetismBehaviour.h"
#include "StandardTimeBehaviour.h"

/**
  * class StandardPhysics
  * 
  */

class StandardPhysics : virtual public PhysicalPorperties {
public:

    /**
     * Empty Constructor
     */
    StandardPhysics ();

    /**
     * Empty Destructor
     */
    virtual ~StandardPhysics ();

};

#endif // STANDARDPHYSICS_H
