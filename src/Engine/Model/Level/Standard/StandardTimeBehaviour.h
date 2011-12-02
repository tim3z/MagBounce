#ifndef STANDARDTIMEBEHAVIOUR_H
#define STANDARDTIMEBEHAVIOUR_H

#include "../TimeBehaviour.h"

/**
 * class StandardTimeBehaviour
 * 
 */

class StandardTimeBehaviour : public TimeBehaviour {
public:

    StandardTimeBehaviour();
    virtual ~StandardTimeBehaviour();

    int manipulateTime(int time);
};

#endif // STANDARDTIMEBEHAVIOUR_H
