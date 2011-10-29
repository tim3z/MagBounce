
#ifndef STANDARDMAGNETISMBEHAVIOUR_H
#define STANDARDMAGNETISMBEHAVIOUR_H
#include "../MagnetismBehaviour.h"

#include <string>

/**
  * class StandardMagnetismBehaviour
  * 
  */

class StandardMagnetismBehaviour : virtual public MagnetismBehaviour {
  
public:

    /**
     * Empty Constructor
     */
    StandardMagnetismBehaviour ();

    /**
     * Empty Destructor
     */
    virtual ~StandardMagnetismBehaviour ();
    
    Vector2D getAccelerationAt(const Vector2D &position, const std::vector<LevelObject*> &objects);
};

#endif // STANDARDMAGNETISMBEHAVIOUR_H
