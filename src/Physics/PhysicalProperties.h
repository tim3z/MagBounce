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
    PhysicalProperties(GravityBehaviour* gravityBehaviour, MagnetismBehaviour* magnetismBehaviour, TimeBehaviour* timeBehaviour);

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
    PhysicalProperties(const PhysicalProperties&);
    const PhysicalProperties& operator=(const PhysicalProperties&);
};

#endif	/* PHYSICALPROPERTIES_H */

