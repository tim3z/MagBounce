
#ifndef STANDARDMAGNETISMBEHAVIOUR_H
#define STANDARDMAGNETISMBEHAVIOUR_H
#include "ForceBehaviour.h"

#include <string>

/**
  * class StandardMagnetismBehaviour
  * 
  */

class StandardMagnetismBehaviour : virtual public ForceBehaviour {
  
public:

    /**
     * Empty Constructor
     */
    StandardMagnetismBehaviour ();

    /**
     * Empty Destructor
     */
    virtual ~StandardMagnetismBehaviour ();
};

#endif // STANDARDMAGNETISMBEHAVIOUR_H
