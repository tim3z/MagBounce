/* 
 * File:   PhysicalProperties.cpp
 * Author: eagle
 * 
 * Created on 27. Oktober 2011, 15:02
 */

#include "PhysicalProperties.h"
#include "MagnetismBehavior.h"
#include "GravityBehavior.h"
#include "TimeBehavior.h"

PhysicalProperties::PhysicalProperties(GravityBehavior* gravityBehavior, MagnetismBehavior* magnetismBehavior,
        TimeBehavior* timeBehavior)
        : gravityBehavior(gravityBehavior), magnetismBehavior(magnetismBehavior), timeBehavior(timeBehavior) {

}

PhysicalProperties::~PhysicalProperties() {
    delete gravityBehavior;
    delete magnetismBehavior;
    delete timeBehavior;
}

