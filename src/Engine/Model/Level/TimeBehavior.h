#ifndef TIMEBEHAVIOR_H
#define TIMEBEHAVIOR_H

/**
 * interface TimeBehavior
 * 
 */

class TimeBehavior {
public:

    virtual ~TimeBehavior();

    /**
     * Returns a manipulated time value to calculate physics
     * @param time the real time
     * @return the time to calculate physics
     */
    virtual int manipulateTime(int time) = 0;

};

#endif // TIMEBEHAVIOR_H
