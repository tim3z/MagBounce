
#ifndef TIMEBEHAVIOUR_H
#define TIMEBEHAVIOUR_H

#include <string>

/**
  * interface TimeBehaviour
  * 
  */

/******************************* Abstract Class ****************************
TimeBehaviour does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class TimeBehaviour {
public:
    
    virtual ~TimeBehaviour();
    
    /**
     * Returns a manipulated time value to calculate physics
     * @param time the real time
     * @return the time to calculate physics
     */
    virtual int manipulateTime(int time) = 0;
    
};

#endif // TIMEBEHAVIOUR_H
