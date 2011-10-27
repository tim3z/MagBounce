
#ifndef FORCEBEHAVIOUR_H
#define FORCEBEHAVIOUR_H

#include <string>
#include "Vector2D.h"

/**
  * interface ForceBehaviour
  * 
  */

/******************************* Abstract Class ****************************
ForceBehaviour does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class ForceBehaviour {
public:
    
    virtual ~ForceBehaviour();

    /**
     * Calculate the acceleration represanted as an Vector for this force at the given position
     * @param position a Vector2D represanting the position
     * @return the acceleration as a Vector2D
     */
    virtual Vector2D* getAccelerationAt(Vector2D &position) = 0;    
};

#endif // FORCEBEHAVIOUR_H
