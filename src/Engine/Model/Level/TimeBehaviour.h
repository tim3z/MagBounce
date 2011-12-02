
#ifndef TIMEBEHAVIOUR_H
#define TIMEBEHAVIOUR_H

/**
  * interface TimeBehaviour
  * 
  */

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
