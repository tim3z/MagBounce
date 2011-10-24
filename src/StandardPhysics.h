
#ifndef STANDARDPHYSICS_H
#define STANDARDPHYSICS_H
#include "Physics.h"

#include <string>

/**
  * class StandardPhysics
  * 
  */

class StandardPhysics : virtual public Physics {
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
