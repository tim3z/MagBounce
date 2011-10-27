
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
    
    void getAccelerationAt(Vector2D &position, Vector2D* acceleration);
};

#endif // STANDARDMAGNETISMBEHAVIOUR_H
