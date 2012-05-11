/* 
 * File:   PhysicalProperties.h
 * Author: eagle
 *
 * Created on 27. Oktober 2011, 15:02
 */

#ifndef PHYSICALPROPERTIES_H
#define	PHYSICALPROPERTIES_H

class GravityBehavior;
class MagnetismBehavior;
class TimeBehavior;

class PhysicalProperties {
protected:
    GravityBehavior* gravityBehavior;
    MagnetismBehavior* magnetismBehavior;
    TimeBehavior* timeBehavior;

public:
    PhysicalProperties(GravityBehavior* gravityBehavior, MagnetismBehavior* magnetismBehavior,
            TimeBehavior* timeBehavior);

    virtual ~PhysicalProperties();

    GravityBehavior* const getGravityBehavior() {
        return gravityBehavior;
    }
    MagnetismBehavior* const getMagnetismBehavior() {
        return magnetismBehavior;
    }
    TimeBehavior* const getTimeBehavior() {
        return timeBehavior;
    }

private:
    PhysicalProperties(const PhysicalProperties&);
    const PhysicalProperties& operator=(const PhysicalProperties&);
};

#endif	/* PHYSICALPROPERTIES_H */

