/* 
 * File:   PhysicalProperties.h
 * Author: eagle
 *
 * Created on 27. Oktober 2011, 15:02
 */

#ifndef PHYSICALPROPERTIES_H
#define	PHYSICALPROPERTIES_H

class GravityBehaviour;
class MagnetismBehaviour;
class TimeBehaviour;

class PhysicalProperties {
protected:
    GravityBehaviour* gravityBehaviour;
    MagnetismBehaviour* magnetismBehaviour;
    TimeBehaviour* timeBehaviour;

public:
    PhysicalProperties(GravityBehaviour* gravityBehaviour, MagnetismBehaviour* magnetismBehaviour,
            TimeBehaviour* timeBehaviour);

    virtual ~PhysicalProperties();

    GravityBehaviour* const getGravityBehaviour() {
        return gravityBehaviour;
    }
    MagnetismBehaviour* const getMagnetismBehaviour() {
        return magnetismBehaviour;
    }
    TimeBehaviour* const getTimeBehaviour() {
        return timeBehaviour;
    }

private:
    PhysicalProperties(const PhysicalProperties&);
    const PhysicalProperties& operator=(const PhysicalProperties&);
};

#endif	/* PHYSICALPROPERTIES_H */

