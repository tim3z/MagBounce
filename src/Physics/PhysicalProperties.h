/* 
 * File:   PhysicalProperties.h
 * Author: eagle
 *
 * Created on 27. Oktober 2011, 15:02
 */

#ifndef PHYSICALPROPERTIES_H
#define	PHYSICALPROPERTIES_H

#include "MagnetismBehaviour.h"
#include "GravityBehaviour.h"
#include "TimeBehaviour.h"

class PhysicalProperties {
protected:
    
    GravityBehaviour* gravityBehaviour;
    MagnetismBehaviour* magnetismBehaviour;
    TimeBehaviour* timeBehaviour;
    
public:

    virtual ~PhysicalProperties();
    
    GravityBehaviour* getGravityBehaviour() {
        return gravityBehaviour;
    }
    MagnetismBehaviour* getMagnetismBehaviour() {
        return magnetismBehaviour;
    }
    TimeBehaviour* getTimeBehaviour() {
        return timeBehaviour;
    }
    
private:

};

#endif	/* PHYSICALPROPERTIES_H */

