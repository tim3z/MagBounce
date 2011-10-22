
#ifndef STANDARDTIMEBEHAVIOUR_H
#define STANDARDTIMEBEHAVIOUR_H
#include "TimeBehaviour.h"

#include <string>

/**
  * class StandardTimeBehaviour
  * 
  */

class StandardTimeBehaviour : virtual public TimeBehaviour {
public:
    
    /**
    * Empty Constructor
    */
    StandardTimeBehaviour ();

    /**
     * Empty Destructor
     */
    virtual ~StandardTimeBehaviour ();
    
};

#endif // STANDARDTIMEBEHAVIOUR_H
