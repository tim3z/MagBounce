
#ifndef STANDARDTIMEBEHAVIOUR_H
#define STANDARDTIMEBEHAVIOUR_H

#include <string>
#include "../TimeBehaviour.h"

/**
  * class StandardTimeBehaviour
  * 
  */

class StandardTimeBehaviour : virtual public TimeBehaviour {
public:
    
    StandardTimeBehaviour ();
    virtual ~StandardTimeBehaviour ();
    
    int manipulateTime(int time);
};

#endif // STANDARDTIMEBEHAVIOUR_H
