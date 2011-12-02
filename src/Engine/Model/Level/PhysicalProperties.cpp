/* 
 * File:   PhysicalProperties.cpp
 * Author: eagle
 * 
 * Created on 27. Oktober 2011, 15:02
 */

#include "PhysicalProperties.h"
#include "MagnetismBehaviour.h"
#include "GravityBehaviour.h"
#include "TimeBehaviour.h"

PhysicalProperties::PhysicalProperties(GravityBehaviour* gravityBehaviour, MagnetismBehaviour* magnetismBehaviour,
        TimeBehaviour* timeBehaviour)
        : gravityBehaviour(gravityBehaviour), magnetismBehaviour(magnetismBehaviour), timeBehaviour(timeBehaviour) {

}

PhysicalProperties::~PhysicalProperties() {
    delete gravityBehaviour;
    delete magnetismBehaviour;
    delete timeBehaviour;
}

