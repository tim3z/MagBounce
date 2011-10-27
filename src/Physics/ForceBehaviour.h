
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
     * @param acceleration a vector to write the result into
     */
    virtual void getAccelerationAt(Vector2D &position, Vector2D* acceleration) = 0;    
};

#endif // FORCEBEHAVIOUR_H
