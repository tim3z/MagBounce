#ifndef STANDARDTIMEBEHAVIOR_H
#define STANDARDTIMEBEHAVIOR_H

#include "../TimeBehavior.h"

/**
 * class StandardTimeBehavior
 * 
 */

class StandardTimeBehavior : public TimeBehavior {
public:

    StandardTimeBehavior();
    virtual ~StandardTimeBehavior();

    double manipulateTime(double time);
};

#endif // STANDARDTIMEBEHAVIOR_H
