/* 
 * File:   PhysicalProperties.h
 * Author: eagle
 *
 * Created on 27. Oktober 2011, 15:02
 */

#ifndef PHYSICALPROPERTIES_H
#define	PHYSICALPROPERTIES_H

#include "ForceBehaviour.h"
#include "TimeBehaviour.h"

class PhysicalProperties {
protected:
    
    ForceBehaviour* gravityBehaviour;
    ForceBehaviour* magnetismBehaviour;
    TimeBehaviour* timeBehaviour;
    
public:

    virtual ~PhysicalProperties();
    
    ForceBehaviour* getGravityBehaviour() {
        return gravityBehaviour;
    }
    ForceBehaviour* getMagnetismBehaviour() {
        return magnetismBehaviour;
    }
    TimeBehaviour* getTimeBehaviour() {
        return timeBehaviour;
    }
    
private:

};

#endif	/* PHYSICALPROPERTIES_H */

